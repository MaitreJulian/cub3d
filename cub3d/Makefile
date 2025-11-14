NAME	= cub3D

CC		= cc
FLAG	= -Wall -Wextra -Werror -g

PARSING_DIR		= parsing
LIBFT_DIR		= libft
MINILIBX_DIR	= minilibx-linux
DIR_O	= file_o

SRC		= main.c init.c draw.c free_and_error.c ft_mlx.c \
		  $(PARSING_DIR)/error.c $(PARSING_DIR)/extract_map.c \
		  $(PARSING_DIR)/init_map.c $(PARSING_DIR)/init_textures.c \
		  $(PARSING_DIR)/key_hook.c $(PARSING_DIR)/utils.c $(PARSING_DIR)/mainju.c \
		  $(PARSING_DIR)/check_map.c

LIBFT_A		= ${LIBFT_DIR}/libft.a
MINILIBX_A	= $(MINILIBX_DIR)/libmlx_Linux.a

GREEN	= \033[1;92m
RED		= \033[1;31m
BLUE	= \033[0;90m

OBJ		= $(patsubst %.cpp,$(DIR_O)/%.o,$(SRC))

all: $(NAME)

$(DIR_O):
	@mkdir -p $(DIR_O)
	
$(DIR_O)/%.o: %.cpp | $(DIR_O)
	@echo "Compilation de $< vers $@"
	@$(CC) $(FLAG) -c $< -o $@

$(LIBFT_A):
	@$(MAKE) -C $(LIBFT_DIR)

$(MINILIBX_A):
	@$(MAKE) -C $(MINILIBX_DIR)

$(NAME): $(OBJ) $(LIBFT_A) $(MINILIBX_A)
	@$(CC) $(FLAG) $(OBJ) $(LIBFT_A) $(MINILIBX_A) -lX11 -lXext -lm -o $(NAME) && echo -e "$(GREEN)COMPILATION SUCCEED"\
	"\n⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿⠿⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n"\
	"⣿⣿⣿⣿⣿⣿⣿⠛⢩⣴⣶⣶⣶⣌⠙⠫⠛⢋⣭⣤⣤⣤⣤⡙⣿⣿⣿⣿⣿⣿\n"\
	"⣿⣿⣿⣿⣿⡟⢡⣾⣿⠿⣛⣛⣛⣛⣛⡳⠆⢻⣿⣿⣿⠿⠿⠷⡌⠻⣿⣿⣿⣿\n"\
	"⣿⣿⣿⣿⠏⣰⣿⣿⣴⣿⣿⣿⡿⠟⠛⠛⠒⠄⢶⣶⣶⣾⡿⠶⠒⠲⠌⢻⣿⣿\n"\
	"⣿⣿⠏⣡⢨⣝⡻⠿⣿⢛⣩⡵⠞⡫⠭⠭⣭⠭⠤⠈⠭⠒⣒⠩⠭⠭⣍⠒⠈⠛\n"\
	"⡿⢁⣾⣿⣸⣿⣿⣷⣬⡉⠁⠄⠁$(BLUE)⠄⠄⠄⠄⠄⠄⠄$(GREEN)⣶$(BLUE)⠄⠄⠄⠄⠄⠄⠄⠄$(GREEN)⢀\n"\
	"⢡⣾⣿⣿⣿⣿⣿⣿⣿⣧⡀$(BLUE)⠄⠄⠄⠄⠄⠄⠄$(GREEN)⢀⣠⣿⣦⣤⣀⣀⣀⣀⠄⣤⣾\n"\
	"⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣶⣶⡶⢇⣰⣿⣿⣟⠿⠿⠿⠿⠟⠁⣾⣿⣿\n"\
	"⣿⣿⣿⣿⣿⣿⣿⡟⢛⡛⠿⠿⣿⣧⣶⣶⣿⣿⣿⣿⣿⣷⣼⣿⣿⣿⣧⠸⣿⣿\n"\
	"⠘⢿⣿⣿⣿⣿⣿⡇⢿⡿⠿⠦⣤⣈⣙⡛⠿⠿⠿⣿⣿⣿⣿⠿⠿⠟⠛⡀⢻⣿\n"\
	"$(BLUE)⠄⠄$(GREEN)⠉⠻⢿⣿⣿⣷⣬⣙⠳⠶⢶⣤⣍⣙⡛⠓⠒⠶⠶⠶⠶⠖⢒⣛⣛⠁⣾⣿\n"\
	"$(BLUE)⠄⠄⠄⠄⠄$(GREEN)⠈⠛⠛⠿⠿⣿⣷⣤⣤⣈⣉⣛⣛⣛⡛⠛⠛⠿⠿⠿⠟⢋⣼⣿⣿\n"\
	"$(BLUE)⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄$(GREEN)⠈⠉⠉⣻⣿⣿⣿⣿⡿⠿⠛⠃$(BLUE)⠄$(GREEN)⠙⠛⠿⢿⣿\n"\
	"$(BLUE)⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄$(GREEN)⢬⣭⣭⡶⠖⣢⣦⣀$(BLUE)⠄⠄⠄⠄$(GREEN)⢀⣤⣾⣿\n"\
	"$(BLUE)⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄$(GREEN)⢰⣶⣶⣶⣾⣿⣿⣿⣿⣷⡄$(BLUE)⠄$(GREEN)⢠⣾⣿⣿⣿\033[0m"

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	@${MAKE} -C ${MINILIBX_DIR} clean
	@rm -rf $(DIR_O) && echo -e "$(GREEN)FILE .O DELETED\033[0m"

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@rm -f $(NAME) && echo -e "$(GREEN)EXEC DELETED\033[0m"

re: fclean all

.PHONY: all clean fclean re