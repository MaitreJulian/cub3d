CC		= cc
CFLAGS	= -Wall -Wextra -Werror

NAME    = libft.a
INCS    = includes
PRINTF	= printf
GNL		= get_next_line

SRCS    =	ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
			ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c \
			ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c \
			ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c \
			ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c \
			ft_strlen.c ft_strmapi.c ft_strcmp.c ft_strncmp.c ft_strnstr.c ft_strrchr.c \
			ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c ft_isspace.c ft_strnchr.c

GNL_SRCS	=	$(GNL)/get_next_line.c $(GNL)/get_next_line_utils.c

PRINTF_SRCS	= $(PRINTF)/ft_print_address.c $(PRINTF)/ft_print_char.c $(PRINTF)/ft_print_hexa.c \
			 $(PRINTF)/ft_print_int.c $(PRINTF)/ft_print_string.c $(PRINTF)/ft_printf.c \
			  $(PRINTF)/ft_strlen.c

SRC_BONUS	=	ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
				ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
				ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

OBJ			= $(SRCS:.c=.o) $(GNL_SRCS:.c=.o) $(PRINTF_SRCS:.c=.o)
OBJ_BONUS 	= $(SRC_BONUS:.c=.o)

.c.o:
	@$(CC) $(CFLAGS) -I ./ -c $< -o $(<:.c=.o) -I $(INCS)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)

all: $(NAME)

bonus: $(OBJ) $(OBJ_BONUS)
	@ar rc $(NAME) $(OBJ) $(OBJ_BONUS)

clean:
	@rm -f $(OBJ) $(OBJ_BONUS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY:	all clean fclean re bonus