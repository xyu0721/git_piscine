# コンパイラとフラグ
CC = cc
CFLAGS = -Wall -Wextra -Werror

# ライブラリ名
NAME = libft.a

# ディレクトリ
SRC_DIR = srcs
INC_DIR = includes

# ソースファイルとオブジェクトファイル
SRCS = $(SRC_DIR)/ft_putchar.c \
       $(SRC_DIR)/ft_swap.c \
       $(SRC_DIR)/ft_putstr.c \
       $(SRC_DIR)/ft_strlen.c \
       $(SRC_DIR)/ft_strcmp.c

OBJS = $(SRCS:.c=.o)

# ルール
all: $(NAME)

$(NAME): $(OBJS)
	@echo "Creating $(NAME)..."
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "$(NAME) has been successfully created."

%.o: %.c
	@echo "Compiling $<..."
	@$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

clean:
	@echo "Removing object files..."
	@rm -f $(OBJS)

fclean: clean
	@echo "Removing $(NAME)..."
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
