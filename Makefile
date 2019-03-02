CC=gcc
CFLAGS=-Wall -Werror -Wextra
NAME=exe
SRCS_DIR= srcs/
OBJS_DIR= objs/
SRCS=main.c \
	 print.c \
	 check.c \
	 resolver.c
OBJS:= $(addprefix $(OBJS_DIR),$(SRCS:.c=.o))
SRCS:= $(addprefix $(SRCS_DIR),$(SRCS))
RM=rm -rf

all: $(NAME)

$(OBJS_DIR):
	mkdir $@

$(NAME): $(OBJS_DIR) $(OBJS)
	@$(CC) $(CFLAGS) -o $@ $(OBJS)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	@echo $@
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
