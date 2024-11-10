/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afogonca <afogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 10:01:40 by afogonca          #+#    #+#             */
/*   Updated: 2024/11/05 10:02:20 by afogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
// Main

void	*ft_calloc(size_t nbytes, size_t size);
char	*ft_read(int fd, char *buffer);
char	*get_next_line(int fd);
// Utils
char	*ft_strchr(char *s, int c);
int		ft_strlen(const char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_getline(char *buffer);
char	*ft_bufferupdt(char *buffer);

#endif
