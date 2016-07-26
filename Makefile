# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: baalbane <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/23 17:37:08 by baalbane          #+#    #+#              #
#    Updated: 2016/07/26 19:09:05 by baalbane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = ft_printf.a

CFLAGS = -Wall -Wextra -Werror -Include/

SRCS =	ft_printf.c


OBJS = $(SRCS:.c=.o)

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
		ar rc $(NAME) $(OBJS)
		ranlib $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
