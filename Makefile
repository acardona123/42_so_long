NAME			=	so_long

CC				=	cc
C_FLAGS			=	-Wall -Wextra -Werror
C_FLAGS_DEBUG	=	-g

INCLUDES_DIR	=	includes/
SRC_DIR			=	srcs/
OBJ_DIR			=	obj/
TESTS_DIR		=	tests/
LIB_PERSO		=	
LIBS			=	-L$(INCLUDES_DIR)mlx -lmlx -lXext -lX11 -lm $(LIB_PERSO)
DEPS			=	$(INCLUDES_DIR)so_long.h Makefile
INCLUDES_H		=	-I./$(INCLUDES_DIR) -I./$(INCLUDES_DIR)mlx

SRC_0_GARBABE		=	$(addprefix 0_garbage_collector/, \
					garbage_collector_0free_ftn \
					garbage_collector_0init \
					garbage_collector_build0_groups \
					garbage_collector_build1_units \
					garbage_collector_my_malloc \
					)
SRC_1_INIT_PRE	=	$(addprefix 1_init_pre_parsing/, \
					init_pre_0main \
					)
SRC_2_PARSING		=	$(addprefix 2_parsing/, \
					parsing_0main \
					parsing_file_to_map \
					parsing_map_check_content \
					parsing_map_check_path \
					)
SRC_3_INIT_POST	=	$(addprefix 3_init_post_parsing/, \
					init_post_0main \
					init_post_textures \
					init_post_hooks \
					)
SRC_8_END			=	$(addprefix 8_end/, \
					end_close \
					)
SRC_9_TOOLS		=	$(addprefix 9_tools/, \
					tools_error_exit \
					tools_find_map_elem \
					tools_transparency \
					)
SRC_10_LIBFT	=	$(addprefix 10_libft/, \
					ft_lstadd_back \
					ft_lstclear \
					ft_lstnew \
					ft_lstsize \
					ft_strjoin \
					ft_strlcpy \
					ft_strlen \
					)
SRC_11_GNL		=	$(addprefix 11_gnl/, \
					get_next_line \
					get_next_line_utils \
					)
SRC 			=	$(addprefix $(SRC_DIR), $(addsuffix .c, \
					$(SRC_0_GARBABE) \
					$(SRC_1_INIT_PRE) \
					$(SRC_2_PARSING) \
					$(SRC_3_INIT_POST) \
					$(SRC_8_END) \
					$(SRC_9_TOOLS) \
					$(SRC_10_LIBFT) \
					$(SRC_11_GNL) \
					))
TESTS			=	$(addprefix $(TESTS_DIR), $(addsuffix .c, \
					test_garbage_collector \
					))
OBJ				=	$(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRC) $(TESTS))

all : $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(DEPS)
	@if [ ! -d "$(OBJ_DIR)" ]; then mkdir $(OBJ_DIR); fi
	@if [ ! -d "$(dir $@)" ]; then mkdir $(dir $@); fi
	$(CC) $(C_FLAGS) $(C_FLAGS_DEBUG) $(INCLUDES_H) -c $< -o $@

$(NAME) : $(OBJ) $(DEPS)
	$(CC) $(C_FLAGS) $(C_FLAGS_DEBUG) $(INCLUDES_H) $(OBJ) $(LIBS) -o $(NAME)

bonus :
	@echo "Bonus pas encore faits."

clean :
	rm -rf $(OBJ_DIR)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re bonus