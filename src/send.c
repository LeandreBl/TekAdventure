/*
** send.c for tekadventure in /home/leandre/C_graphical_prog/tekadventure
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Thu May 11 10:02:30 2017 Léandre Blanchard
** Last update Mon May 22 17:48:55 2017 Léandre Blanchard
*/

#include "tekadventure.h"

int		mono_send(t_player *players)
{
  size_t        size;

  if (sfTcpSocket_sendPartial(players[0].socket, players[0].info,
			      sizeof(t_info), &size)
      == sfSocketDisconnected)
    {
      players[1].info->skin = -1;
      my_printf("%sHost disconnected\n%s", BOLDRED, RESET);
    }
  if (size != sizeof(t_info))
    my_printf(SEND_ERR, BOLDWHITE, BOLDCYAN, sizeof(t_info) - size,
	      BOLDWHITE, RESET);
  return (0);
}

int		send_raw(t_player *players)
{
  int           i;
  int           j;
  size_t        size;

  i = 0;
  while (i < MAX_PLAYERS)
    {
      j = 0;
      while (j < MAX_PLAYERS)
	{
	  if ((i != j || i == 0 || j == 0) && my_strlen(players[j].info->name) != 0
	       && players[i].info->skin > 0)
	    {
	      sfTcpSocket_sendPartial(players[i].socket,
				      players[j].info, sizeof(t_info), &size);
	    }
	  j++;
	}
      i++;
    }
  return (0);
}
