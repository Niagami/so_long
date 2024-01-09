/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteste <jteste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 12:39:50 by jteste            #+#    #+#             */
/*   Updated: 2024/01/09 15:47:00 by jteste           ###   ########.fr       */
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
	else
	{
		mainstruct.mapname = ft_strdup(argv[1]);
		ft_struct_init(&mainstruct);
		ft_open_map(&mainstruct);
		ft_check_map(&mainstruct);
		return (0);
	}
}
