/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsuner <hsuner@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 16:19:51 by hsuner            #+#    #+#             */
/*   Updated: 2023/12/07 17:42:13 by hsuner           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "so_long.h"
#include <fcntl.h>
#include <stdlib.h>

static inline void	compute(t_game *game)
{
	int	i;

	i = -1;
	while (game->map.line[++i])
		if (game->map.line[i] != '1' && game->map.line[i] != '0'
			&& game->map.line[i] != 'C' && game->map.line[i] != 'E'
			&& game->map.line[i] != 'P' && game->map.line[i] != '\n')
			return (ft_printf("%s\n", game->error.undefined), ft_exit(game));
	game->map.height = 0;
	game->map.area = ft_split(game->map.line, '\n');
	game->map.virtual_map = ft_split(game->map.line, '\n');
	if (!game->map.area || !game->map.virtual_map)
		return (ft_printf("%s\n", game->error.empty_map), ft_exit(game));
	i = -1;
	game->map.width = (int)ft_strlen(game->map.area[0]);
	while (game->map.line[++i])
	{
		if (game->map.line[i] == '\n')
		{
			game->map.height++;
			if (game->map.line[i] == '\n')
				if (i / game->map.height != game->map.width)
					return (ft_printf("%s", game->error.rect), ft_exit(game));
		}
	}
}

void	read_map(t_game *game, int fd)
{
	char	*str;
	char	*line;

	game->map.line = NULL;
	str = ft_strdup("");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		game->map.line = ft_strjoin(str, line);
		free(line);
		free(str);
		str = game->map.line;
	}
	if (!game->map.line)
		return (ft_printf("%s\n", game->error.empty_map), ft_exit(game));
	compute(game);
	close(fd);
}

static inline void	found_c_e_p(t_game *game)
{
	int	i;
	int	j;

	j = 0;
	while (game->map.area[j])
	{
		i = 0;
		while (game->map.area[j][i])
		{
			if (game->map.area[j][i] == 'C')
				game->map.collectible[0]++;
			if (game->map.area[j][i] == 'E')
				game->map.exit[0]++;
			if (game->map.area[j][i] == 'P')
			{
				game->map.player++;
				game->map.position[0] = j;
				game->map.position[1] = i;
			}
			i++;
		}
		j++;
	}
}

void	exists_c_e_p(t_game *game)
{
	game->map.collectible[0] = 0;
	game->map.exit[0] = 0;
	game->map.position[0] = 0;
	game->map.position[1] = 0;
	found_c_e_p(game);
	if (!game->map.collectible[0])
		return (ft_printf("%s\n", game->error.coin), ft_exit(game));
	if (game->map.exit[0] != 1)
		return (ft_printf("%s\n", game->error.exit), ft_exit(game));
	if (game->map.player != 1)
		return (ft_printf("%s\n", game->error.player), ft_exit(game));
}

void	wall_check(t_game *game)
{
	int	i;
	int	width;
	int	height;

	width = game->map.width;
	height = game->map.height;
	i = -1;
	while (game->map.area[0][++i])
		if (game->map.area[0][i] != '1' || game->map.area[height - 1][i] != '1')
			return (ft_printf("%s\n", game->error.wall), ft_exit(game));
	while (height--)
		if (game->map.area[height][0] != '1' || game->map.area[height][width
			- 1] != '1')
			return (ft_printf("%s\n", game->error.wall), ft_exit(game));
}
