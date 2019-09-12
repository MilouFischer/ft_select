# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: efischer <efischer@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/03 09:30:54 by efischer          #+#    #+#              #
#    Updated: 2019/09/12 17:42:59 by efischer         ###   ########.fr        #
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
#CFLAGS += -pedantic
#CFLAGS += -Wpadded
COMPILE = $(CC) -c

#=====================================SRCS======================================

SRCS += ft_select.c 
SRCS += list_functions.c
SRCS += init.c
SRCS += termcap.c

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
