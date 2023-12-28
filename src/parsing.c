/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteste <jteste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 15:25:12 by jteste            #+#    #+#             */
/*   Updated: 2023/12/28 17:08:10 by jteste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_checkmap(t_main *mainstruct)
{
	ft_checksize(mainstruct);
	return (0);
}

int	ft_checksize(t_main *mainstruct)
{
	int		i;
	size_t	linelenght;

	i = 0;
	linelenght = ft_strlen(mainstruct->map[i]);
	printf("premiere ligne %zu\n", linelenght);
	while (mainstruct->map[i] != NULL)
	{
		printf("ligne suivante %zu\n", ft_strlen(mainstruct->map[i]));
		if (ft_strlen(mainstruct->map[i]) != linelenght)
			return (1);
		i++;
	}
	return (0);
}
