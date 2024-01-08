/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteste <jteste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 13:11:00 by jteste            #+#    #+#             */
/*   Updated: 2024/01/08 13:53:16 by jteste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_format(t_main *mainstruct)
{
	size_t	i;

	i = ft_strlen(mainstruct->mapname);
	if ((mainstruct->mapname[i - 1] == 'r')
		&& (mainstruct->mapname[i - 2] == 'e')
		&& (mainstruct->mapname[i - 3] == 'b')
		&& (mainstruct->mapname[i - 4] == '.'))
		return (true);
	else
		return (false);
}
