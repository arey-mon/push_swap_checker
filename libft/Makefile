# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apreymon <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/09 10:20:51 by apreymon          #+#    #+#              #
#    Updated: 2021/04/21 13:55:43 by apolliner        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC	= gcc
CFLAGS	= -Wall -Wextra -Werror

NAME	= libft.a

FILES	=	ft_memset \
		ft_atoi \
		ft_bzero \
		ft_calloc \
		ft_memalloc \
		ft_memcpy \
		ft_memccpy \
		ft_memmove \
		ft_memchr \
		ft_memcmp \
		ft_strlen \
		ft_isalpha \
		ft_isdigit \
		ft_isalnum \
		ft_isascii \
		ft_isprint \
		ft_iswhitespace \
		ft_toupper \
		ft_tolower \
		ft_strchr \
		ft_strclen \
		ft_strrchr \
		ft_strncmp \
		ft_strcmp \
		ft_strcpy \
		ft_strlcpy \
		ft_strlcat \
		ft_strnstr \
		ft_strdup \
		ft_strndup \
		ft_substr \
		ft_strjoin \
		ft_strtrim \
		ft_split \
		ft_itoa \
		ft_strmapi \
		ft_strnew \
		ft_putchar_fd \
		ft_putstr_fd \
		ft_putendl_fd \
		ft_putnbr_fd \
		ft_lstnew_bonus \
		ft_lstadd_front_bonus \
		ft_lstsize_bonus \
		ft_lstlast_bonus \
		ft_lstadd_back_bonus \
		ft_lstdelone_bonus \
		ft_lstclear_bonus \
		ft_lstiter_bonus \
		ft_lstmap_bonus \
		get_next_line

SRCS = $(addsuffix .c, $(FILES))

OBJS = $(addsuffix .o, $(FILES))
OBJDIR = objs/

all: $(NAME)

$(NAME) : $(addprefix $(OBJDIR), $(OBJS))
	@ar -rcs $(NAME) $(addprefix $(OBJDIR), $(OBJS))

$(OBJDIR)%.o: %.c
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all
