/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putstr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: showard <showard@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/08 18:10:23 by showard       #+#    #+#                 */
/*   Updated: 2024/10/24 15:59:09 by showard       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putstr_fd(char *s, int fd, ssize_t *fcheck)
{
	size_t	len;

	len = ft_strlen(s);
	ft_write(fd, s, len, fcheck);
}
