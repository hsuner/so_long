/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsuner <hsuner@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 17:10:45 by hsuner            #+#    #+#             */
/*   Updated: 2023/12/05 20:43:33 by hsuner           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx/mlx.h"
#include "libft/libft.h"
#include "so_long.h"
#include <stdlib.h>

void	ft_exit(t_game *game)
{
	if (game->map.area)
		free_malloc(game->map.area, 0);
	if (game->map.virtual_map)
		free_malloc(game->map.virtual_map, 0);
	if (game->mlx.coin)
		mlx_destroy_image(game->mlx.ptr, game->mlx.coin);
	if (game->mlx.exit)
		mlx_destroy_image(game->mlx.ptr, game->mlx.exit);
	if (game->mlx.ground)
		mlx_destroy_image(game->mlx.ptr, game->mlx.ground);
	if (game->mlx.player)
		mlx_destroy_image(game->mlx.ptr, game->mlx.player);
	if (game->mlx.wall)
		mlx_destroy_image(game->mlx.ptr, game->mlx.wall);
	if (game->mlx.win)
		mlx_destroy_window(game->mlx.ptr, game->mlx.win);
	exit(1);
}

int	is_ber(char *str, t_game *game)
{
	int	len;

	len = ft_strlen(str);
	if (str[len - 1] != 'r' || str[len - 2] != 'e' || str[len - 3] != 'b'
		|| str[len - 4] != '.')
		return (ft_printf("%s\n", game->error.extension), 0);
	return (game->map.file_name = ft_strdup(str), 1);
}
