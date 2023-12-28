/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_and_copy_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteste <jteste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 12:43:27 by jteste            #+#    #+#             */
/*   Updated: 2023/12/28 15:50:07 by jteste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_open_map(t_main *mainstruct)
{
	int		fd;
	char	*line;

	mainstruct->count_line = 0;
	line = NULL;
	fd = open("maps/test.ber", O_RDONLY);
	if (fd == -1)
		return (1);
	while ((line != NULL) || (mainstruct->count_line == 0))
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		mainstruct->count_line++;
		free(line);
	}
	close(fd);
	ft_copy_map(mainstruct);
	return (0);
}

int	ft_copy_map(t_main *mainstruct)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	line = NULL;
	fd = open("maps/test.ber", O_RDONLY);
	mainstruct->map = malloc((mainstruct->count_line + 1) * sizeof(char *));
	if (!mainstruct->map)
		return (1);
	mainstruct->map[mainstruct->count_line] = NULL;
	mainstruct->count_line = 0;
	while ((line != NULL) || (mainstruct->count_line == 0))
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		mainstruct->map[i] = ft_strdup(line);
		i++;
		free(line);
	}
	close(fd);
	return (0);
}
