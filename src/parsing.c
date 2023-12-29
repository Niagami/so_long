/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteste <jteste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 15:25:12 by jteste            #+#    #+#             */
/*   Updated: 2023/12/29 11:56:10 by jteste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_checkmap(t_main *mainstruct)
{
	printf("signe ok : %d\n", ft_checksign(mainstruct));
	printf("rectangle ok : %d\n", ft_checksize(mainstruct));
	return (0);
}

int	ft_checksize(t_main *mainstruct)
{
	int		i;
	size_t	first_line_lenght;
	size_t	next_line_lenght;

	i = 0;
	first_line_lenght = ft_strlen(mainstruct->map[i]) - 1;
	while (mainstruct->map[i] != NULL)
	{
		if (ft_strchr(mainstruct->map[i], '\n'))
			next_line_lenght = ft_strlen(mainstruct->map[i]) - 1;
		else
			next_line_lenght = ft_strlen(mainstruct->map[i]);
		if (next_line_lenght != first_line_lenght)
			return (1);
		i++;
	}
	return (0);
}

int	ft_checksign(t_main *mainstruct)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (mainstruct->map[i] != NULL)
	{
		j = 0;
		while (mainstruct->map[i][j] != '\0')
		{
			if ((mainstruct->map[i][j] != '0')
			&& (mainstruct->map[i][j] != '1')
			&& (mainstruct->map[i][j] != 'C')
			&& (mainstruct->map[i][j] != 'P')
			&& (mainstruct->map[i][j] != 'E')
			&& (mainstruct->map[i][j] != '\n'))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
