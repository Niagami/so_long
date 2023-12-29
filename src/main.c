/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteste <jteste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 12:39:50 by jteste            #+#    #+#             */
/*   Updated: 2023/12/29 14:39:28 by jteste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	t_main	mainstruct;

	ft_struct_init(&mainstruct);
	ft_open_map(&mainstruct);
	ft_check_map(&mainstruct);
	return (0);
}
