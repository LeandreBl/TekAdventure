/*
** host.c for tekadventure in /home/leandre/C_graphical_prog/tekadventure
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Wed Apr  5 16:00:57 2017 Léandre Blanchard
** Last update Mon May 29 14:01:47 2017 Léandre Blanchard
*/

#include "tekadventure.h"

static void	       	display_button(t_window *window, t_textures *sprites,
				       t_player *players)
{
  put_sprite_resize(window, BG(BUTTON),
		    XYF(W_2 - 100, H_ - H_2 / 3), XYF(2, 2));
  if (!is_in_rect(window, XYF(W_2 - 100, H_ - H_ / 3 + 120), XYF(200, 60)))
    {
      put_sprite_resize(window, BG(BUTTON_PRESSED),
			XYF(W_2 - 100, H_ - H_2 / 3), XYF(2, 2));
      if (MP)
	players[0].info->attack = 2;
    }
  put_word("Start", XYF(W_2 - 38, H_ - H_2 / 3 + 10), window, sfWhite);
  put_word("Your ip :", XYF(W_ - 210, H_ - 150), W, sfWhite);
  put_word(LOCAL.address, XYF(W_ - 210, H_ - 100), W, sfWhite);
}

void			display_players_lobby(t_window *window,
					      t_textures *sprites,
					      t_player *players)
{
  static int		a;
  int			i;
  t_info		*info;

  i = 0;
  while (i < MAX_PLAYERS)
    {
      info = players[i].info;
      if (info->skin >= 0 && info->skin <= MAX_PERS)
	{
	  put_sprite(window, sprites->sprites[(int)info->skin][16],
		     XYF(i * 150, H_2));
	  put_word(players[i].info->name, XYF(i * 150, H_2 - 50), W, sfBlack);
	}
      i++;
    }
  a++;
}

void			display_background_lobby(t_window *window, t_textures *sprites)
{
  static int		a;

  put_sprite(window, BG(CLOUDS), XY((-a) / 10));
  put_sprite(window, BG(CLOUDS), XY(1280 - a / 10));
  put_sprite(window, BG(PLAINS), ORIGIN);
  put_sprite(window, BG(BG_LOBBY), ORIGIN);
  a = (a + 1) % (1280 * 10);
}

int			host(t_window *window, t_textures *sprites, t_player *players)
{
  sfThread		*listener;
  sfThread		*send_receive;

  listener = sfThread_create((void *)init_listener, (void *)players);
  send_receive = sfThread_create((void *)send_receive_host, (void *)players);
  sfThread_launch(listener);
  sfThread_launch(send_receive);
  while (sfRenderWindow_isOpen(window->window)
	 && players[0].info->attack == 0)
    {
      window_clear(window);
      close_win(window);
      display_background_lobby(window, sprites);
      display_players_lobby(window, sprites, players);
      display_button(window, sprites, players);
      window_refresh(window);
    }
  if (players[0].info->attack == 2)
    ingame(window, sprites, players);
  players[0].info->attack = -1;
  free_thread(send_receive);
  free_thread(listener);
  return (0);
}
