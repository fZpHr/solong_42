/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbelle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 10:28:09 by hbelle            #+#    #+#             */
/*   Updated: 2023/12/06 10:28:18 by hbelle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <unistd.h>
# include <stdlib.h>

char	*ft_itoa(int n);
size_t	ft_strlen(char *str);
char	*get_next_line(int fd);
char	*ft_strdup(char *buff);
int		ft_checkline(char *str);
char	*ft_strjoin(char *line, char *buff);

#endif
