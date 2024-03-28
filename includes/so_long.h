/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysbai-jo <ysbai-jo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 10:17:41 by ysbai-jo          #+#    #+#             */
/*   Updated: 2024/03/26 20:38:35 by ysbai-jo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/*>>>>>>>>>>Includes<<<<<<<<<<*/

# include "ft_printf.h"
# include "get_next_line.h"
# include <mlx.h>
# include <stdbool.h>

/*>>>>>>>>>> Map Definition <<<<<<<<<<*/
# define WALL '1'
# define FLOOR '0'
# define EXIT 'E'
# define COLLEC 'C'
# define PLAYER 'P'
# define ENEMY 'X'

/*>>>>>colors<<<<<*/
# define RED "\x1b[31m"
# define YELLOW "\x1b[33m"
# define BOLDYELLOW "\033[1m\033[33m"
# define BOLDRED "\033[1m\033[31m"
# define END "\x1b[0m"
# define WIN_PURPLE 0xFF00FF
# define BOLD_WHITE 0xFFFFFF
# define RED_WIN 0xFF0000
# define SKY_BLUE "\033[0;94m"
# define BRIGHT_BLUE "\033[0;94m"
# define BRIGHT_YELLOW "\033[0;93m"

/*some keys and values*/
# define CONST 50
# define ANIMATION_SPEED 10100
# define CLOSE_WIN 17
# define UP 119
# define DOWN 115
# define RIGHT 100
# define LEFT 97
# define ESC 65307
# define CLEAR "\033[K"
# define RETURN "\r"

/*>>>>>structs<<<<<*/
typedef struct s_player
{
	int			x;
	int			y;
	size_t		mv_count;
	int			animation;
}				t_player;

typedef struct s_map
{
	char		**map;
	int			col;
	int			row;
	int			collec;
	int			fd;
	bool		**vmap;
}				t_map;

typedef struct s_position
{
	int			x;
	int			y;
}				t_position;

typedef struct s_data
{
	int			curr_x;
	int			curr_y;
	int			new_x;
	int			new_y;
}				t_data;

typedef struct s_img
{
	void		*wall;
	void		*floor;
	void		*collec;
	void		*exit_open;
	void		*exit_close;
	void		*p0;
	void		*p1;
	void		*p2;
	void		*p3;
	void		*p4;
	void		*enemy;
}				t_img;

typedef struct s_engine
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_player	player;
	t_map		map;
	t_position	*stack;
	t_data		index;
	t_img		img;
}				t_game;

/*Error handling functions*/
void			fd_error(char *path);
void			err_wall(t_game *engine);
void			err_rectangle(t_game *engine);
void			err_player(t_game *engine, int player, char *str);
void			err_malloc(char *str);
void			err_malloc_v2(char *str, t_game *engine);
void			err_exit(t_game *engine, int e, char *str);
void			err_collec(t_game *engine);
void			err_characters(t_game *engine, char c);
void			err_path2exit(t_game *engine);
void			err_path2collec(t_game *engine, int c, char *str);

/*check functions*/
void			check_walls(t_game *engine);
void			check_rectangle(t_game *engine);
void			check_pce(t_game *engine);
void			check_characters(t_game *engine);
void			check_arg(int ac, char *path);
void			check_file_ext(void *path);
void			check_path2exit(t_game *engine);
void			check_path2collec(t_game *engine);

/*building map functions*/
void			build_map(char *path, t_game *engine);
void			build_mlx_win(t_game *engine);
void			build_mlx_images(t_game engine);

/*quit game and free functions*/
void			free_vmap(t_game *engine);
void			shutdown_game(t_game *engine);
void			shutdown_game_win(t_game *engine, char *str);

/*External Functions*/
size_t			ft_nstrlen(const char *str);
char			*ft_strchr(const char *str, int c);
int				ft_strcmp(char *s1, char *s2);
char			*ft_strrchr(const char *str, int c);
char			*ft_itoa(int n);

/*mlx functions*/
int				handle_input(int key, t_game *engine);
int				handle_loop_input(t_game *engine);

#endif