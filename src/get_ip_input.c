/*
** loop_ip_name.c for tekadventure in /home/leandre/C_graphical_prog/tekadventure
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Fri Apr  7 15:05:48 2017 Léandre Blanchard
** Last update Fri Apr 21 17:57:40 2017 Léandre Blanchard
*/

#include "tekadventure.h"

static void	put_background(t_window *window, t_sprite *background)
{
  static int	b;

  put_sprite(window, background, xy_vectorf(-b / 20, 0));
  put_sprite(window, background, xy_vectorf(1280 - b / 20, 0));
  b = (b + 1) % (1280 * 20);
}

static void	put_ip_string(t_window *window,
			      sfIpAddress *ip, t_sprite *background)
{
  put_background(window, background);
  put_word("Enter Host Ip :", xy_vectorf(W_2 - 200, H_2), window, sfBlack);
  put_word(ip->address, xy_vectorf(W_2, H_2), window, sfBlack);
}

static void	add_key_to_str(sfIpAddress *ip, int *pos, int *key)
{
  if (KP(sfKeyLShift) || KP(sfKeyRShift))
    {
      if (key_released(*key) && *pos < 16)
	{
	  ip->address[*pos] = *key - 26 + 48;
	  *pos += 1;
	}
      if (key_released(sfKeySemiColon) || key_released(sfKeySpace))
	{
	  ip->address[*pos] = '.';
	  *pos += 1;
	}
    }
  if (key_released(sfKeyBack) && *pos > 0)
    {
      *pos -= 1;
      ip->address[*pos] = 0;
    }
  *pos = (*pos < 0) ? 0 : *pos;
}

static int	loop_ip(t_window *window, sfIpAddress *ip, t_sprite *background)
{
  int		i;
  int		k;

  k = my_strlen(ip->address);
  i = 25;
  while (i < 36 && sfRenderWindow_isOpen(window->window))
    {
      window_clear(window);
      close_win(window);
      add_key_to_str(ip, &k, &i);
      put_ip_string(window, ip, background);
      i++;
      if (i == 36)
	i = 25;
      if (key_released(sfKeyReturn) && my_strlen(ip->address) > 6)
	return (0);
      window_refresh(window);
    }
  return (-1);
}

sfIpAddress	get_ip_input(t_window *window, t_textures *sprites)
{
  sfIpAddress	addr;

  zeros(addr.address, 16);
  scan_save_ip(&addr);
  if ((loop_ip(window, &addr, BG(BG_IP))) == -1)
    my_strcpy(addr.address, "0.0.0.0");
  return (addr);
}
