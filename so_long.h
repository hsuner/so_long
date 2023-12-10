/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsuner <hsuner@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 16:47:51 by hsuner            #+#    #+#             */
/*   Updated: 2023/11/30 20:32:42 by hsuner           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define PIXEL 64
# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2

typedef struct s_error
{
	char	*coin;
	char	*unreachable_coin;
	char	*exit;
	char	*unreachable_exit;
	char	*player;
	char	*wall;
	char	*undefined;
	char	*extension;
	char	*fd;
	char	*empty_map;
	char	*xpm;
	char	*rect;
}			t_error;

typedef struct s_map
{
	char	**area;
	char	**virtual_map;
	char	*file_name;
	char	*line;
	int		width;
	int		height;
	int		position[2];
	int		collectible[2];
	int		exit[2];
	int		player;
}			t_map;

typedef struct s_mlx
{
	void	*ptr;
	void	*win;
	void	*player;
	void	*exit;
	void	*ground;
	void	*coin;
	void	*wall;
	int		step;
}			t_mlx;

typedef struct s_game
{
	t_error	error;
	t_map	map;
	t_mlx	mlx;
}			t_game;

// check
int			is_ber(char *str, t_game *game);
void		read_map(t_game *game, int fd);
void		ft_exit(t_game *game);
void		exists_c_e_p(t_game *game);
void		wall_check(t_game *game);
void		is_game(t_game *game);
// mlx
void		ft_mlx(t_game *game);
int			put_xml(t_game *game);
int			keyboard(int keycode, t_game *game);

#endif