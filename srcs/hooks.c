/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <kdhrif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 10:56:02 by kdhrif            #+#    #+#             */
/*   Updated: 2022/12/30 15:21:56 by kdhrif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	key_hook(int keycode, t_mlx *vars)
{
	if (keycode == 65307)
		fdf_exit(vars);
	return (0);
}

void	all_hooks(t_mlx *mlx)
{
	mlx_hook(mlx->win, DESTROYNOTIFY, 0, fdf_exit, mlx);
	mlx_key_hook(mlx->win, key_hook, mlx);
}
