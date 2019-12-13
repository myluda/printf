# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ayajrhou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/17 02:23:21 by ayajrhou          #+#    #+#              #
#    Updated: 2019/12/09 22:41:00 by ayajrhou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

G = gcc -Wall -Wextra -Werror
SRC = ft_hexa.c ft_isalpha.c ft_itoa.c ft_partition1.c ft_partition2.c ft_partition3.c ft_strchr.c ft_partition4.c	ft_partition5.c ft_porintof.c ft_printf.c ft_putchar.c ft_putstr_c.c ft_putstr_r.c ft_putstr.c ft_strcpyy.c ft_strdup.c ft_strjoin.c ft_strlen.c ft_tolower.c ft_toupper.c ft_utoa.c ft_youkhart.c ft_atoi.c ft_hexa_p.c ft_hexa_upper.c
O = $(SRC:.c=.o)
NAME = libftprintf.a
OB = $(BNS:.c=.o) 

all: $(NAME)

$(NAME): 
	$(G) -c $(SRC)
	ar rc $(NAME) $(O)
	ranlib $(NAME)
	@echo $(NAME) is created

bonus: 
	$(G) -c $(BNS)
	ar rs $(NAME) $(OB)

clean: 
	rm -f $(O) $(OB)

fclean: clean
	rm -f $(NAME)

re: fclean all
