/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: showard <showard@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/25 14:28:07 by showard       #+#    #+#                 */
/*   Updated: 2024/11/29 18:37:21 by showard       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif
# if BUFFER_SIZE <= 0
#  error BUFFER_SIZE needs to be bigger than 0. Try again nerd.
# endif
# include <stddef.h>

char		*get_next_line(int fd);
size_t		ft_strlen_gnl(const char *s);
char		*ft_strdup_gnl(const char *s);
char		*ft_strjoin_gnl(char const *s1, char const *s2);
char		*ft_substr_gnl(char const *s, unsigned int start, size_t len);
char		*ft_strchr_gnl(const char *s, int c);
void		clean_lines(char *remainder, char **full_line, char **r_line);
void		complete_line(char *buffer, char **full_line, int fd);
char		*ft_strcpy_gnl(char *dest, const char *src);

#endif