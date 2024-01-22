/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_and_copy_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteste <jteste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 12:43:27 by jteste            #+#    #+#             */
/*   Updated: 2024/01/22 15:37:35 by jteste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_open_map(t_main *mainstruct)
{
	int		fd;
	char	*line;

	line = NULL;
	fd = open(mainstruct->mapname, O_RDONLY);
	if (read(fd, 0, 0) < 0 || fd == -1)
		ft_free_all(mainstruct, "Read error", 1);
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

void	ft_copy_map(t_main *mainstruct)
{
	int		fd;
	char	*line;

	mainstruct->index = 0;
	line = NULL;
	fd = open(mainstruct->mapname, O_RDONLY);
	mainstruct->map = ft_calloc((mainstruct->count_line + 1), sizeof(char *));
	if (!mainstruct->map)
		ft_free_all(mainstruct, "Malloc error", 1);
	mainstruct->map[mainstruct->count_line+1] = NULL;
	mainstruct->count_line = 0;
	while ((line != NULL) || (mainstruct->count_line == 0))
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		mainstruct->map[mainstruct->index] = line;
		mainstruct->count_line++;
		mainstruct->index++;
		free(line);
	}
	close(fd);
}
