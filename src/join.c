/*
** join.c for tekadventure in /home/leandre/C_graphical_prog/tekadventure
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Wed Apr  5 16:02:45 2017 Léandre Blanchard
** Last update Mon May 22 17:57:15 2017 Léandre Blanchard
*/

#include "tekadventure.h"

static void		display(t_window *window, t_textures *sprites,
				t_player *players, sfIpAddress *addr)
{
  display_background_lobby(window, sprites);
  put_word("Connected :", XYF(W_ - 220, H_ - 150), W, sfWhite);
  put_word(addr->address, XYF(W_ - 220, H_ - 100), W, sfWhite);
  display_players_lobby(window, sprites, players);
}

int			join(t_window *window, t_textures *sprites, t_player *players)
{
  sfIpAddress		addr;
  sfThread		*send_receive;

  if ((try_to_connect(&addr, window, sprites, players)) != 0)
    return (-1);
  if (my_strcmp(addr.address, "0.0.0.0") != 0)
    save_ip(&addr);
  send_receive = sfThread_create((void *)send_receive_client, (void *)players);
  sfThread_launch(send_receive);
  while (sfRenderWindow_isOpen(window->window)
	 && players[1].info->attack != 2
	 && players[0].info->skin >= 0)
    {
      window_clear(window);
      display(window, sprites, players, &addr);
      close_win(window);
      window_refresh(window);
    }
  if (players[1].info->attack == 2)
    ingame(window, sprites, players);
  if (players[0].info->skin < 0)
    my_printf("%sHOST disconnected%s\n", BOLDRED, RESET);
  free_thread(send_receive);
  return (0);
}
