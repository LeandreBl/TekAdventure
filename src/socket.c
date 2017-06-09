/*
** socket.c for tekadventure in /home/leandre/C_graphical_prog/tekadventure
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Thu Apr 20 11:04:26 2017 Léandre Blanchard
** Last update Thu May 11 11:31:03 2017 Léandre Blanchard
*/

#include "tekadventure.h"

void		send_receive_host(t_player *players)
{
  while (players[0].info->skin >= 0)
    {
      receive_raw_host(players);
      send_raw(players);
      sfSleep(sfMilliseconds(5));
    }
}

void		send_receive_client(t_player *players)
{
  while (players[0].info->skin >= 0)
    {
      receive_raw_client(players);
      mono_send(players);
      sfSleep(sfMilliseconds(5));
    }
}

int              try_to_connect(sfIpAddress *addr, t_window *window,
				t_textures *sprites, t_player *players)
{
  int            a;

  a = 0;
  *addr = get_ip_input(window, sprites);
  if (my_strcmp(addr->address, "0.0.0.0") == 0)
    return (-1);
  save_ip(addr);
  while (sfTcpSocket_connect(players[0].socket, *addr, PORT,
			     sfSeconds(10)) != sfSocketDone && a < TIMEOUT)
    a++;
  if (a >= TIMEOUT)
    {
      my_printf(ERR_CONNECT, BOLDRED, RESET);
      return (try_to_connect(addr, window, sprites, players));
    }
  my_printf(SUCC_CONNECT, BOLDGREEN, RESET);
  return (0);
}

static void    	sockets_listener(sfTcpListener *listener, t_player *players)
{
  static int	i = 1;
  int		a;

  while (i < MAX_PLAYERS)
    {
      if (sfTcpListener_accept(listener, &players[i].socket) == sfSocketDone)
	{
	  a = first_inactive_socket(players) + 1;
	  sfTcpSocket_setBlocking(players[i].socket, sfFalse);
	  my_printf("%sPlayer n°%d connected%s\n", BOLDGREEN, a, RESET);
	  i++;
	}
      if (i > MAX_PLAYERS)
	i = first_inactive_socket(players);
    }
}

void		init_listener(t_player *players)
{
  sfTcpListener	*listener;

  listener = sfTcpListener_create();
  sfTcpListener_listen(listener, PORT);
  sockets_listener(listener, players);
  sfTcpListener_destroy(listener);
}
