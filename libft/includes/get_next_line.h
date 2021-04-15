/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apreymon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 16:55:12 by apreymon          #+#    #+#             */
/*   Updated: 2021/03/15 10:29:17 by apolliner        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFFER_SIZE 100
# include <unistd.h>

int				get_next_line(int fd, char **line);
int				create_line(char **stock, char **line, int ret);
int				check_ret(int ret, int fd, char **stock, char **line);
char			*ft_substr(char *s, unsigned int start, size_t len);
char			*ft_substr_const(const char *s, unsigned int start, size_t len);
char			*ft_substr_free(char *s, unsigned int start, size_t len);
char			*ft_strjoin(char *s1, char *s2);
char			*ft_strcpy(char *dest, char *src);
char			*ft_strdup(const char *s1);
char			*ft_strchr(const char *str, int c);
#endif
