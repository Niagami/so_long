/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jteste <jteste@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 14:15:38 by jteste            #+#    #+#             */
/*   Updated: 2024/01/24 14:24:33 by jteste           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	my_close_hook(void *param)
{
	t_main	*smain;

	smain = param;
	ft_free_all(smain, "Game closed", 0);
}
