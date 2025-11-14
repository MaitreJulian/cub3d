# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jvenkata <jvenkata@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/03 11:33:48 by jowoundi          #+#    #+#              #
#    Updated: 2025/11/13 14:16:47 by jvenkata         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3 #-fsanitize=address

# Colors
GREEN   = \033[32m
YELLOW	= \033[33m
NC      = \033[0m

# Libft
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
MINILIBX = ./minilibx-linux/libmlx.a
INCLUDES = -I ./header -I $(LIBFT_DIR)

# Dirs
SRC_DIR = src
OBJ_DIR = obj

# Source files (relative to SRC_DIR)
SRCS =	main.c \
		error.c \
		gnl/get_next_line_utils.c gnl/get_next_line.c \
		init_map.c \
		extract_map.c \
		init_textures.c \
		utils.c

# Expand with SRC_DIR prefix
SRCS := $(addprefix $(SRC_DIR)/, $(SRCS))

# Objects in OBJ_DIR
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Progress bar
TOTAL_FILES := $(words $(SRCS))
CURRENT_FILE := 0
define progress_bar
	@$(eval CURRENT_FILE=$(shell echo $$(($(CURRENT_FILE) + 1))))
	@printf "\r$(YELLOW)Compiling cub3d... [%-$(TOTAL_FILES)s] %d/%d $(NC)" \
	$$(for i in $$(seq 1 $(CURRENT_FILE)); do printf "#"; done) $(CURRENT_FILE) $(TOTAL_FILES)
	@if [ $(CURRENT_FILE) -eq $(TOTAL_FILES)  ]; then echo ""; fi
endef

# Compilation rule
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c header/cub3d.h
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	$(call progress_bar)
	                                            
# Main rules
all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@printf "$(GREEN)Linking objects to create executable...$(NC)\n"
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MINILIBX) -o $(NAME)
	@printf "$(GREEN)Executable $(NAME) created!$(NC)\n"

$(LIBFT):
	@make -C $(LIBFT_DIR) --silent

clean:
	@rm -rf $(OBJ_DIR)
	@make -C $(LIBFT_DIR) clean --silent

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean --silent

re: fclean all

.PHONY: all clean fclean re
