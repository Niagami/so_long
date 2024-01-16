/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteste <jteste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 13:08:54 by jteste            #+#    #+#             */
/*   Updated: 2024/01/16 13:24:07 by jteste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_save_exit_pos(t_main *mainstruct)
{
	int	j;

	mainstruct->index = 0;
	mainstruct->exit = malloc(sizeof(t_exit));
	if (mainstruct->exit == NULL)
		ft_error_message("Malloc error");
	while (mainstruct->map[mainstruct->index] != NULL)
	{
		j = 0;
		while (mainstruct->map[mainstruct->index][j] != '\0')
		{
			if (mainstruct->map[mainstruct->index][j] == 'E')
			{
				mainstruct->exit[0].x = j;
				mainstruct->exit[0].y = mainstruct->index;
			}
			j++;
		}
		mainstruct->index++;
	}
}
