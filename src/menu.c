/*
** join_host.c for tekadventure in /home/leandre/C_graphical_prog/tekadventure
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Wed Apr  5 14:37:00 2017 Léandre Blanchard
** Last update Wed May 24 16:44:15 2017 Léandre Blanchard
*/

#include "tekadventure.h"

static void	button(t_win *window, t_textures *sprites, t_info *info,
		       int *ch)
{
  put_sprite_resize(window, BG(BUTTON), XYF(W_2 + 100, H_2), XYF(2, 2));
  put_sprite_resize(window, BG(BUTTON), XYF(W_2 - 300, H_2), XYF(2, 2));
  put_sprite(window, BG(BUTTON), XYF(10, 10));
  pos_mouse(window);
  if (!(is_in_rect(window, XYF(W_2 + 100, H_2), XYF(200, 60))))
    {
      put_sprite_resize(window, BG(BUTTON_PRESSED), XYF(W_2 + 100, H_2), X2);
      if (MP)
	*ch = JOIN;
    }
  if (!(is_in_rect(window, XYF(W_2 - 300, H_2), XYF(200, 60))))
    {
      if (MP)
	*ch = HOST;
      put_sprite_resize(window, BG(BUTTON_PRESSED), XYF(W_2 - 300, H_2), X2);
    }
  if (!(is_in_rect(window, XYF(10, 10), XYF(100, 30))))
    {
      if (MP)
	lobby(window, info, sprites);
      put_sprite(window, BG(BUTTON_PRESSED), XYF(10, 10));
    }
  put_word("HOST", XYF(W_2 - 240, H_2 + 10), window, sfWhite);
  put_word("JOIN", XYF(W_2 + 165, H_2 + 10), window, sfWhite);
  put_word("new", XYF(34, 6), window, sfWhite);
}

static void	my_character(t_win *window, t_info *info, t_textures *sprites)
{
  static int	a;

  put_sprite(window, sprites->backgrounds[BACKGROUND], XY(-a / 10));
  put_sprite(window, sprites->backgrounds[BACKGROUND], XY(1280 - a / 10));
  if (info->skin != 4)
    put_sprite(window, sprites->sprites[(int)info->skin][(a / 100) % 8],
	       XYF(W_2 - 50, H_ - 200));
  put_sprite(window, BG(TITLE), XYF((1280 - 685) / 2, 50));
  a = (a + 1) % (1280 * 10);
}

int		host_join(t_win *window, t_info *info, t_textures *sprites)
{
  int		ch;

  ch = 0;
  while (sfRenderWindow_isOpen(window->window) && ch == 0)
    {
      window_clear(window);
      close_win(window);
      my_character(window, info, sprites);
      button(window, sprites, info, &ch);
      pos_mouse(window);
      window_refresh(window);
    }
  return (ch);
}
