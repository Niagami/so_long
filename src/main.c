/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteste <jteste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 12:39:50 by jteste            #+#    #+#             */
/*   Updated: 2024/01/16 22:06:17 by jteste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_main	mainstruct;

	if (argc != 2)
	{
		ft_error_message("Wrong number of arguments");
		return (1);
	}
	mainstruct.mapname = ft_strdup(argv[1]);
	ft_struct_init(&mainstruct);
	ft_open_map(&mainstruct);
	ft_check_map(&mainstruct);
	mainstruct.mlx_ptr = mlx_init((ft_strlen(mainstruct.map[0]) - 1) * 64, mainstruct.count_line * 64, "so_long",false);
	if (mainstruct.mlx_ptr == NULL)
		return (1);
	ft_load_image(&mainstruct);
	ft_texture_to_image(&mainstruct);
	ft_display_image(&mainstruct);
	mlx_key_hook(mainstruct.mlx_ptr, &my_keyhook, &mainstruct);
	mlx_loop(mainstruct.mlx_ptr);
	free(mainstruct.mlx_ptr);
	return (0);
}
