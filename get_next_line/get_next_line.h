/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteste <jteste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 11:51:45 by jteste            #+#    #+#             */
/*   Updated: 2023/12/28 13:10:03 by jteste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

char	*get_next_line(int fd);
char	*ft_get_line(char *stock);
char	*ft_read_and_copy(int fd, char *str);
char	*ft_clear_stock(char *stock);
char	*ft_strchr(const char *str, int tofind);
char	*ft_strjoins(char *stock, char *buffer);
size_t	ft_strlen(const char *str);

#endif