# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arafeeq <arafeeq@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/24 15:43:03 by arafeeq           #+#    #+#              #
#    Updated: 2022/11/09 15:53:37 by arafeeq          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS =	push_swap parse parse_utils split list_fts \
		list_utils small_sort big_sort push_swap_moves \
		rotate_moves chunk_and_sort

OBJDIR = objects

OBJS = $(addprefix $(OBJDIR)/, $(addsuffix .o, $(SRCS)))

HEADER = push_swap.h

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g

$(OBJDIR)/%.o : %.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all