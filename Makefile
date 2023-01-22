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

SRC 			=	$(addprefix $(SRC_DIR), $(addsuffix .c, \
					transparency \
					))
TESTS			=	$(addprefix $(TESTS_DIR)test_, $(addsuffix .c, \
					decouverte \
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