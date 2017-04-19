NAME = libftprintf.a

OUTPUT = printf_test

FLAGS = -fsanitize=address

SRCS = ft_printf.c strtool.c \
	   tabtool.c field.c \
	   parseur.c ft_itoabase.c\
	   precision.c takeconversion.c \
	   printd.c printc.c \
	   prints.c printo.c \
	   printp.c printu.c \
	   printx.c tool.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@echo
	@echo 'Make -> $(NAME) created'
	@echo
	@ar rc $(NAME) $(OBJS)

clean:
	@echo 'Clean -> *.o deleted'
	@echo
	@rm -rf $(OBJS)

fclean: clean
	@echo 'Fclean -> '$(NAME)' deleted'
	@echo
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
