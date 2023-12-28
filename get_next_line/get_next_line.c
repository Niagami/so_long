/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niagami <niagami@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 11:51:43 by jteste            #+#    #+#             */
/*   Updated: 2023/11/30 20:47:48 by niagami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
/*This function brows the stock until a '\n'
or a '\0' is found and copy the remaining
portion of stock in a new string wich become
the new stock*/
char	*ft_clear_stock(char *stock)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (stock[i] != '\0' && stock[i] != '\n')
		i++;
	if (!stock[i])
	{
		free(stock);
		return (NULL);
	}
	str = malloc(sizeof(char) * (ft_strlen(stock) - i + 1));
	if (str == NULL)
		return (NULL);
	i++;
	while (stock[i] != '\0')
		str[j++] = stock[i++];
	str[j] = '\0';
	free(stock);
	return (str);
}
/*This function calculate the size of the line,
malloc it and copy the stock into the malloc
string until a '\0' or a '\n' is found
then add a '\n' if there is one in
stock*/

char	*ft_get_line(char *stock)
{
	int		index;
	char	*str;

	index = 0;
	if (stock[index] == '\0')
		return (NULL);
	while (stock[index] != '\0' && stock[index] != '\n')
		index++;
	str = malloc((index + 2) * sizeof(char));
	if (!str)
		return (NULL);
	index = 0;
	while (stock[index] != '\0' && stock[index] != '\n')
	{
		str[index] = stock[index];
		index ++;
	}
	if (stock[index] == '\n')
	{
		str[index] = '\n';
		index++;
	}
	str[index] = '\0';
	return (str);
}
/*This function read from the file descriptor 
and concatenate the buffer from read 
at the end of the stock until a '\n' is found 
in stock or until read returns zero*/

char	*ft_read_and_copy(int fd, char *stock)
{
	char	*buffer;
	int		read_size;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buffer == NULL)
		return (NULL);
	read_size = 1;
	while (!(ft_strchr(stock, '\n')) && read_size != 0)
	{
		read_size = read(fd, buffer, BUFFER_SIZE);
		if (read_size == -1)
		{
			free(buffer);
			free(stock);
			return (NULL);
		}
		buffer[read_size] = '\0';
		stock = ft_strjoin(stock, buffer);
	}
	free(buffer);
	return (stock);
}

char	*get_next_line(int fd)
{
	static char	*stock = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stock = ft_read_and_copy(fd, stock);
	if (!stock)
		return (NULL);
	line = ft_get_line(stock);
	stock = ft_clear_stock(stock);
	return (line);
}
