/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apreymon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 16:52:52 by apreymon          #+#    #+#             */
/*   Updated: 2021/04/13 13:11:02 by apolliner        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>
# include "get_next_line.h"

# define BUFFER_SIZE 100
# define BUFF_SIZE 32		/// ADD FOR GNL

typedef struct		s_list
{
	void				*content;
	struct s_list		*next;
	size_t			content_size; ////  ADD FOR GNL
}					t_list;

int					ft_atoi(const char *str);
void				ft_bzero(void *s, size_t n);
void				*ft_calloc(size_t count, size_t size);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_islower(int c);
int					ft_isprint(int c);
int					ft_isupper(int c);
int					ft_iswhitespace(char a);
char				*ft_itoa(int n);
void				*ft_memalloc(size_t size);
void				*ft_memccpy(void *dst, const void *src,
		int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memcpy_int(void *dst, const void *src, int n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memset(void *b, int c, size_t len);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr_fd(char *s, int fd);
char				**ft_split(char const *s, char c);
char				*ft_strchr(const char *s, int c);
int					ft_strchr_int(const char *str, int c);
int					ft_strchr_iint(const int *arr, int c);
int					ft_stronechar(const char *str, int c);
char				*ft_strdup(const char *s1);
char				*ft_strjoin(char *s1, char *s2);
char				*ft_strjoin_free_dest(char *s1, char *s2);
char				*ft_strjoin_free_src(char *s1, char *s2);
char				*ft_strjoin_free(char *s1, char *s2);
size_t				ft_strlcat(char *dest, const char *src, size_t size);
size_t				ft_strlcpy(char *dest, const char *src,
							size_t size);
size_t				ft_strlen(const char *str);
size_t				ft_strclen(const char *str, char c);
char				*ft_strmapi(char const *s, char (*f)
		(unsigned int, char));
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strndup(const char *src, size_t len);
char				*ft_strnstr(const char *haystack, const char *needle,
		size_t len);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strrchr(const char *s, int c);
char				*ft_strcpy(char *dest, char *src);
char				*ft_strncpy(char *dest, char const *src,
		unsigned int n);
char				*ft_strnew(size_t size);
char				*ft_strtrim(char const *s1, char const *set);
char				*ft_substr_const(char const *s, unsigned int start,
		size_t len);
char				*ft_substr_free(char *s, unsigned int start,
		size_t len);
int					ft_tolower(int c);
int					ft_toupper(int c);
void				ft_lstadd_back(t_list **alst, t_list *new);
void				ft_lstadd_front(t_list **alst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstdelone(t_list *lst, void (*del)(void*));
void				ft_lstclear(t_list **lst, void (*del)(void*));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
		void (*del)(void *));
t_list				*ft_lstnew(void *content);
t_list				*ft_lstnew_size(void const *content, size_t content_size);
int					get_next_line(int fd, char **line);
int					get_next_line2(int fd, char **line);

#endif
