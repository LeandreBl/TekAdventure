/*
** scoller.h for scroller in /home/leandre/Rushs/scroller
**
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
**
** Started on  Fri Mar 31 13:51:04 2017 Léandre Blanchard
** Last update Tue May 30 01:05:29 2017 Léandre Blanchard
*/

#ifndef SCROLLER_H_
# define SCROLLER_H_

# include "my.h"
# include "colors.h"
# include "my_csfml.h"
# include "defines.h"

typedef struct		s_info
{
  char			dir;
  sfVector2f		pos;
  char			name[NAME_SIZE + 1];
  char			skin;
  char			weapon;
  char			attack;
  int			area;
}			t_info;

typedef struct		s_player
{
  sfTcpSocket		*socket;
  t_info		*info;
}			t_player;

typedef struct		s_textures
{
  t_sprite		***sprites;
  t_sprite		**backgrounds;
  t_sprite		***weapons;
}			t_textures;

typedef struct		s_minimap
{
  int			width;
  int			height;
  int			color;
}			t_minimap;

typedef struct		s_portal
{
  sfVector2i		entry;
  sfVector2i		exit;
  struct s_room		*to;
}			t_portal;

typedef struct		s_room
{
  char			**room;
  char			**dup;
  char			*name;
  struct s_portal	**portals;
  struct s_room		*next;
}			t_room;

typedef struct		s_map
{
  int			len;
  struct s_room		*first;
}			t_map;

typedef struct		s_terrain
{
  char			**map;
  sfUint8		*pmap;
  sfTexture		*tmap;
  t_map			world;
  t_room		*cur;
}			t_terrain;

void		display_planets(t_window *window, t_textures *sprites,
				t_info *info);

sfVector2i	convert_mouse(t_window *window, t_info *info);

void		regul_speed(float *speed);

sfVector2i	convert_pos(sfVector2f pos);

void		move_spaceship(t_window *window, t_textures *sprites,
			       t_info *info);

int		bloc_to_display(char c);

void		display_back(t_window *window, sfVector2f pos,
			     t_textures *sprites, t_terrain *terrain);

void		auto_jump(t_window *window, t_info *info,
			  t_terrain *terrain, sfVector2i mouse);

float		clic_to_move(t_window *window, t_info *info);

int		assign_room(t_room *cur, int i, char *name);

int		get_name(char *name);

void		free_graph(t_map *map);

void		free_terrain(t_terrain *terrain);

char		*get_map_name(char *line);

int		get_maps(char **tab, t_map *map);

int		get_portals(char **tab, t_map *map);

int		link_portals(char **tab, t_map *map, int i);

sfVector2i	drag_mouse(t_window *window, sfVector2i *pos);

void		replace_pos(t_info *info, sfVector2f *prev,
			    t_terrain *terrain);

int		is_block(char **tab, sfVector2f posf);

int		special_sprite(t_sprite **sprites, const char *pathname);

int		warp(t_window *window, t_info *info, t_terrain *terrain);

float		dist(sfVector2i from, sfVector2i to);

sfVector2i	swaper(sfVector2f pos);

sfMusic		**create_musics(void);

t_terrain	*generate_terrain(const char *pathname);

float		moves(t_window *window,
		      t_info *info, t_terrain *terrain);

void		jump(t_window *window, t_info *info, t_terrain *terrain);

int		ingame(t_window *window, t_textures *sprites, t_player *players);

void		display_ingame(t_window *window, t_player *players,
			       t_textures *textures, t_terrain *terrain);

int		player_bug(t_player *players);

void		display_ally(t_window *window, t_textures *sprites,
			     t_player *player);

int		nickname_already_taken(t_player *players, char *name);

void		display_players_datas(t_player *players);

int		save_ip(sfIpAddress *addr);

void		display_background_lobby(t_window *window, t_textures *sprites);

void		display_players_lobby(t_window *window,
				      t_textures *sprites,
				      t_player *players);

void		send_receive_host(t_player *players);

void		send_receive_client(t_player *players);

int		mono_send(t_player* players);

int		send_raw(t_player *players);

int		receive_raw_host(t_player *players);

int		receive_raw_client(t_player *players);

void		send_raw_client(t_player *players);

void		init_listener(t_player *players);

void		free_textures(t_textures *sprites);

t_sprite        **create_backgrounds(void);

void		re_fill_info(t_info *info, char *name, char skin, char weapon);

t_player	*init_players(void);

t_textures	*generate_all_sprites(void);

void		free_players(t_player *players);

t_player	*create_players(void);

int		recup_map(char **tab, t_map *map);

int		get_lobby_keys(int *a);

void		free_all_sprites(t_sprite ***sprites);

int		lobby(t_window *window, t_info *info, t_textures *sprites);

void		fill_host_join_sprites(t_sprite **sprites);

t_sprite	***weapon_sprites(void);

void		fill_game_bg(t_sprite **bg);

int		relocate_players(t_player *players);

int		scan_save_ip(sfIpAddress *addr);

int		number_of_players(t_player *players);

void		display_me(t_window *window, t_player *players,
			   t_textures *textures, t_terrain *terrain);

void		display_ally(t_window *window, t_textures *sprites,
			     t_player *players);

t_sprite	***all_sprites(int nb);

sfIpAddress	get_ip_input(t_window *window, t_textures *sprites);

int		host_join(t_win *window, t_info *info, t_textures *sprites);

int		host(t_window *window, t_textures *sprites, t_player *players);

int		join(t_window *window, t_textures *sprites, t_player *players);

int		try_to_connect(sfIpAddress *addr, t_window *window,
			       t_textures *sprites, t_player *players);

sfIpAddress	sfGetIpLocalAdress();

int		first_inactive_socket(t_player *players);

int		fill_sockets_with_name(t_player *players, t_info *info);

t_sprite	**create_sprites(int nb);

int		fill_sprites(t_sprite **sprites, const char *pathname);

#endif /* !SCROLLER_H_ */
