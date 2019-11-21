# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ayajrhou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/17 02:23:21 by ayajrhou          #+#    #+#              #
#    Updated: 2019/10/22 18:21:25 by ayajrhou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

G = gcc -Wall -Wextra -Werror
SRC = *.c
O = $(SRC:.c=.o)
NAME = libftprintf.a

all: $(NAME)

$(NAME): 
	$(G) -c $(SRC)
	ar rc $(NAME) $(O)
	ranlib $(NAME)
	cp $(NAME) testpf/
	@echo $(NAME) is created

bonus: 
	$(G) -c $(BNS)
	ar rs $(NAME) $(OB)

clean: 
	rm -f $(O) $(OB)

fclean: clean
	rm -f $(NAME)

re: fclean all
