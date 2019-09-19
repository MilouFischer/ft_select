# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: efischer <efischer@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/03 09:30:54 by efischer          #+#    #+#              #
#    Updated: 2019/09/19 13:36:05 by efischer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_select

#=====================================HEAD======================================

IFLAGS += -I
INCLUDES += includes/
LIBINCLUDES += libft/includes/
HEAD += ft_select.h

#=====================================PATH======================================

PATHI = $(INCLUDES)
PATHO = objs/
PATHLIB = libft/

#====================================COMPILE====================================

CC = clang
CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -Werror
CFLAGS += -fsanitize=address,undefined -g3
#CFLAGS += -pedantic
#CFLAGS += -Wpadded
COMPILE = $(CC) -c

#=====================================SRCS======================================

SRCS += main.c
SRCS += ft_select.c 
SRCS += list_functions.c
SRCS += st_input.c
SRCS += st_print.c
SRCS += st_end.c
SRCS += move_cursor.c
SRCS += special_key.c
SRCS += termcap.c
SRCS += x_y_elem.c

#=====================================OBJS======================================

OBJS = $(patsubst %.c, $(PATHO)%.o, $(SRCS))

LIBFT = $(PATHLIB)libft.a

vpath %.c srcs/
vpath %.h $(PATHI)

all: $(NAME)

$(NAME): $(LIBFT) $(PATHO) $(OBJS)
	$(CC) $(CFLAGS) -lcurses $(OBJS) $(LIBFT) -o $@

$(OBJS): $(PATHO)%.o: %.c $(HEAD) Makefile
	$(COMPILE) $(CFLAGS) $< $(IFLAGS) $(INCLUDES) $(IFLAGS) $(LIBINCLUDES) -o $@

$(PATHO):
	mkdir $@

$(LIBFT): FORCE
	$(MAKE) -C $(PATHLIB)

clean:
	$(RM) $(OBJS)
	$(RM) -R $(PATHO)
	$(MAKE) clean -C $(PATHLIB)

fclean: clean
	$(RM) $(NAME)
	$(MAKE) fclean -C $(PATHLIB)

re: fclean all

FORCE:

.PHONY: all clean fclean re FORCE
