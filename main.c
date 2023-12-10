/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsuner <hsuner@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 16:46:15 by hsuner            #+#    #+#             */
/*   Updated: 2023/12/07 17:26:40 by hsuner           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "so_long.h"
#include <fcntl.h>

static inline void	init_error(t_error *error)
{
	error->coin = "There must be at least one <Coin>!";
	error->unreachable_coin = "Unreachable <Coin>!";
	error->exit = "Either the <Exit> is unavailable or there are multiple!";
	error->unreachable_exit = "Unreachable <Exit>!";
	error->player = "Either the <Player> is unavailable or there are multiple!";
	error->wall = "The map must be surrounded by <Walls>!";
	error->undefined = "Undefined element!";
	error->extension = "The extension must be <.ber>!";
	error->fd = "The <file> couldn't be opened!";
	error->empty_map = "The map is empty!";
	error->xpm = "<Xpm file> could not be read or found!";
	error->rect = "The map must be rectangular!";
}

static inline void	init_mlx(t_game *game)
{
	game->map.area = (void *)0;
	game->map.virtual_map = (void *)0;
	game->mlx.coin = (void *)0;
	game->mlx.exit = (void *)0;
	game->mlx.ground = (void *)0;
	game->mlx.player = (void *)0;
	game->mlx.wall = (void *)0;
	game->mlx.win = (void *)0;
	game->mlx.ptr = (void *)0;
}

int	main(int ac, char **av)
{
	int		fd;
	t_game	game;

	if (ac == 2)
	{
		init_mlx(&game);
		init_error(&game.error);
		is_ber(av[1], &game);
		fd = open(game.map.file_name, O_RDONLY);
		if (fd < 0)
			return (ft_printf("%s\n", game.error.fd), 0);
		read_map(&game, fd);
		exists_c_e_p(&game);
		wall_check(&game);
		is_game(&game);
		ft_mlx(&game);
	}
	return (0);
}
