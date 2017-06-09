/*
** init.c for tekadventure in /home/leandre/C_graphical_prog/tekadventure
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Tue Apr  4 15:51:50 2017 Léandre Blanchard
** Last update Sat May 27 19:29:04 2017 Léandre Blanchard
*/

#include "tekadventure.h"

t_textures		*generate_all_sprites(void)
{
  t_textures		*sprites;

  if ((sprites = malloc(sizeof(t_textures))) == NULL)
    return (NULL);
  if ((sprites->sprites = all_sprites(MAX_PERS)) == NULL)
    return (NULL);
  if ((sprites->weapons = weapon_sprites()) == NULL)
    return (NULL);
  if ((sprites->backgrounds = create_backgrounds()) == NULL)
    return (NULL);
  return (sprites);
}

t_info			*info_create(char *name, char skin, char weapon)
{
  t_info		*info;

  if ((info = malloc(sizeof(t_info))) == NULL)
    return (NULL);
  zeros(info->name, NAME_SIZE + 1);
  my_strcpy(info->name, name);
  info->pos.y = 0;
  info->pos.x = 108;
  info->skin = skin;
  info->weapon = weapon;
  info->attack = 0;
  info->dir = 4;
  info->area = 0;
  return (info);
}

void			re_fill_info(t_info *info, char *name, char skin, char weapon)
{
  zeros(info->name, NAME_SIZE + 1);
  my_strcpy(info->name, name);
  info->skin = skin;
  info->weapon = weapon;
}

t_player		*init_players(void)
{
  t_player		*players;
  int			i;

  i = 0;
  if ((players = malloc(sizeof(t_player) * MAX_PLAYERS)) == NULL)
    return (NULL);
  while (i != MAX_PLAYERS)
    {
      players[i].socket = sfTcpSocket_create();
      sfTcpSocket_setBlocking(players[i].socket, sfFalse);
      if ((players[i].info = info_create(EMPTY_NAME, -1, 0)) == NULL)
	return (NULL);
      i++;
    }
  return (players);
}
