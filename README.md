<h1 align="center">so_long</h1>

<p align="center">
  <img src="https://img.shields.io/badge/C-00599C?style=flat&logo=c&logoColor=white" alt="C"/>
</p>

<p align="center"><strong>A small 2D game built pixel by pixel on MiniLibX, backed by a general-purpose allocator Alex designed and wrote himself, well beyond what the subject asked for.</strong></p>

---

## 📌 Overview

so_long is 42's first real program instead of an algorithm exercise: a 2D game where a character walks a grid, collects items and reaches an exit, drawn through MiniLibX, a windowing library thin enough to only hand back a raw framebuffer.
There is no `draw_sprite`, no scene graph, nothing between the student and the pixels: every map is parsed and validated before the window opens, and every frame is composited by hand into an image buffer.
The subject itself only asks for the standard 42-wide rule, no leaks, checked once when the program exits.
Alex went further than that and built a full allocator on top of it: pointers are grouped by which free function they need, and any fatal error can walk every group and free it in one call, a reusable piece of infrastructure most first-year students don't attempt, and something he still points to as an early sign of where his interests were heading.

## 🎯 Objectives

- Parse a custom `.ber` map format into a validated grid: rectangular, walled on every border, exactly one player start and one exit, at least one collectible
- Reject an unsolvable map before opening a window, by walking the grid from the player's start and checking the exit and every collectible are reachable
- Render everything as raw pixel copies into an off-screen buffer, no MiniLibX drawing primitive beyond `mlx_put_image_to_window`
- Track every move and print the running count to the terminal
- Go past the subject's "don't leak" requirement with a self-designed garbage collector: every long-lived allocation grouped by how it needs to be freed, so a full playthrough, and any error path through it, never leaks
- Bonus: pixel-by-pixel movement instead of tile jumps, a lockable scrolling camera, and an on-screen HUD replacing the terminal counter

## 📋 Constraints

What the subject imposes:

- Program takes one argument, a map file ending in `.ber`
- The map alphabet is exactly five characters: `0` empty, `1` wall, `C` collectible, `E` exit, `P` player start
- Exactly one `P` and one `E`, at least one `C`; a duplicate or a missing one is an error
- The map must be rectangular and fully walled on its border
- A valid path must exist from `P` to `E` passing through every `C`
- Movement with `W`/`A`/`S`/`D` (arrow keys are an accepted alternative), never into a wall, with the running move count printed to the shell on every move
- A 2D view, top-down or side-on; the game does not need to run in real time
- `ESC` or the window's close button must quit cleanly
- Rendering must go through MiniLibX's images
- Any malformed map exits with `Error\n` followed by an explicit message
- The rules common to every 42 project also apply: strict Norm compliance including bonus files, no crash beyond documented undefined behavior, no leaks, and a Makefile with `NAME`, `all`, `clean`, `fclean`, `re` (plus `bonus` if a bonus part is submitted)

## 🧠 How it works

### Parsing

`ft_parsing_main` runs a fixed pipeline: check the file extension, open it, read every line into a `char **` map, check the content line by line (border walls, exactly one `P` and one `E`, at least one `C`, nothing else), then check the path.
Any failure exits immediately with a message naming the specific rule that broke, from "not rectangular" to "not solvable".

### Solvability

`ft_parsing_check_map_path` copies the map, then walks it recursively from the player's start tile, marking every cell it visits as a wall so it never revisits it.
It counts how many exits and collectibles that walk actually reaches; the map is only accepted if the walk finds exactly one exit and every collectible on the map.
This runs before the window opens, so an unsolvable map never gets as far as MiniLibX.

### The allocator

This is the part of the project that isn't in the subject: a small garbage collector, `garbage.h`, that Alex designed and built as a personal bonus challenge, at a point where writing a generalized allocator in C was still a big step up from the exercises around it.
Every pointer that has to outlive the function that allocated it is registered into a group, one group per free function it needs (a plain `free`, a MiniLibX image destroy, a window destroy...).
A single `ft_garbage_group_free` call on any fatal error walks every group and frees it, so an error mid-game can never leak the textures or frames already loaded.
The rest of the codebase, parsing, rendering, gameplay, all funnel their allocations through it rather than tracking frees by hand.

### Rendering

Textures are loaded once into `t_data` buffers and blended into a per-frame image with `ft_tools_img_blend`.
The game keeps a small list of these frames so moving the player only touches the tiles that changed instead of redrawing the whole map.

### Movement and camera (bonus)

The mandatory build moves the player one tile per keypress and prints the move count to the terminal on every tile crossed.
The bonus build (`make bonus`, compiled with `-D MOUV_ON_TERM=0`) moves the player continuously in `CHUNK_SIZE`-sized steps and drops that terminal print, since the same count is already drawn on screen; it adds a scrollable camera that can be locked back onto the player, toggled and re-centered from the keyboard.

## 🛠️ Tech Stack

<p>
  <img src="https://img.shields.io/badge/C-00599C?style=flat&logo=c&logoColor=white" alt="C"/>
</p>

## 🚀 Getting Started

MiniLibX is not vendored in this repo; pull it and pin it to the commit this project was built against, since the current tip changed its internal types and will not compile against these headers.

```bash
git clone https://github.com/acardona123/42_so_long.git
cd 42_so_long
git clone https://github.com/42Paris/minilibx-linux.git includes/mlx
git -C includes/mlx checkout 7dc53a411a7d4ae286c60c6229bd1e395b0efb82
make -C includes/mlx
make
```

Use `make bonus` instead for continuous movement and the scrolling camera.

## 📖 Usage

```bash
./so_long maps/valid/map_valid_20x20.ber
```

**Controls:** `w`/`a`/`s`/`d` move the player. In the bonus build the arrow keys move the player too while the camera is locked to it, or pan the camera when unlocked; `c` toggles that lock, `Home` recenters the camera on the player, `-`/`=` change its speed.

## 🧪 Tests

`maps/valid/` holds four maps of increasing size; `maps/unvalid/` holds thirteen maps, one per rejection rule (not rectangular, not closed, forbidden character, missing/duplicate `P` or `E`, no collectible, unsolvable, wrong extension). `tests/` has standalone probes for the parser, the garbage collector and the image helpers, built separately from the game. Validated against [42_tester_so_long_parsing](https://github.com/acardona123/42_tester_so_long_parsing), which runs the same map corpus as a script.

## 📁 Structure

```
srcs/
├── 0_garbage_collector/   allocator: grouped pointers, one free function per group
├── 1_init_pre_parsing/
├── 2_parsing/             map read, content checks, solvability walk
├── 3_init_post_parsing/   texture loading, background, key hooks
├── 4_gameplay/             player and camera movement, display, exit unlock
├── 5_end/                 close and free everything
├── 6_tools/               pixel/image helpers shared across the above
├── 7_libft/               local libft subset
└── 8_gnl/                 get_next_line, used to read the map file
includes/                  headers and the compiled .xpm textures the game loads
maps/                      valid and unvalid map corpus
textures/                  source art (PNG/XCF) the .xpm textures were built from
tests/                     standalone probes, not part of the game binary
```

## 📚 Resources

- [42Paris/minilibx-linux](https://github.com/42Paris/minilibx-linux)

---

<p align="center"><sub>🏫 Project from the <strong>42</strong> common core, School 42 Paris.</sub></p>
