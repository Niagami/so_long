/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteste <jteste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 12:16:57 by jteste            #+#    #+#             */
/*   Updated: 2024/01/08 15:45:16 by jteste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_struct_init(t_main *mainstruct)
{
	mainstruct->count_line = 0;
	mainstruct->map_exit = 0;
	mainstruct->collectible = 0;
	mainstruct->start_pos = 0;
	return (0);
}

void	ft_save_player_pos(t_main *mainstruct, int i, int j)
{
	mainstruct->start_pos++;
	mainstruct->player_pos_y = i;
	mainstruct->player_pos_x = j;
}
