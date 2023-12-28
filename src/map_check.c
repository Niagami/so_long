/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteste <jteste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 12:43:27 by jteste            #+#    #+#             */
/*   Updated: 2023/12/28 13:59:07 by jteste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_open_map(void)
{
	int		fd;
	int		count_line;
	char	*line;

	count_line = 0;
	line = NULL;
	fd = open("maps/test.ber", O_RDONLY);
	while ((line != NULL) || (count_line == 0))
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		count_line++;
		printf("%d\n", count_line);
		free(line);
	}
	close(fd);
	return (0);
}
