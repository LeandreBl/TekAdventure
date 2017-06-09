/*
** receive_send.c for tekadventure in /home/leandre/C_graphical_prog/tekadventure
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Fri Apr  7 16:49:56 2017 Léandre Blanchard
** Last update Tue May 23 13:19:39 2017 Léandre Blanchard
*/

#include "tekadventure.h"

static int	update_info(t_info *info, t_info temp)
{
  zeros(info->name, NAME_SIZE + 1);
  my_strcpy(info->name, temp.name);
  info->skin = temp.skin;
  info->weapon = temp.weapon;
  info->dir = temp.dir;
  info->pos = temp.pos;
  info->attack = temp.attack;
  info->area = temp.area;
  return (0);
}

int		receive_raw_host(t_player *players)
{
  size_t	size;
  int		i;
  t_info	temp;

  i = 1;
  while (i < MAX_PLAYERS)
    {
      if ((sfTcpSocket_receive(players[i].socket,
			       &temp, sizeof(t_info),
			       &size)) == sfSocketDisconnected)
	{
	  my_printf(PLAYER_DC, BOLDBLUE, i + 1, RESET);
	  zeros(players[i].info->name, NAME_SIZE + 1);
	  players[i].info->skin = -1;
	  sfTcpSocket_destroy(players[i].socket);
	  players[i].socket = sfTcpSocket_create();
	}
      if (size == sizeof(t_info))
	update_info(players[i].info, temp);
      i++;
    }
  return (0);
}

int		receive_raw_client(t_player *players)
{
  static int	next = 1;
  int		i;
  size_t	size;
  t_info	temp;

  i = 0;
  if (players[0].info->skin < 0)
    return (-1);
  if ((sfTcpSocket_receive(players[0].socket, &temp, sizeof(t_info),
			   &size)) == sfSocketDisconnected)
    players[0].info->skin = -1;
  if (size != sizeof(t_info))
    return (-1);
  while (i < MAX_PLAYERS && players[i].info->skin >= 0)
    {
      if (i > 0)
	if (my_strcmp(temp.name, players[i].info->name) == 0
	    && my_strcmp(temp.name, players[0].info->name) != 0)
	  return (update_info(players[i].info, temp));
      i++;
    }
  if (next < MAX_PLAYERS)
    update_info(players[next++].info, temp);
  return (0);
}
