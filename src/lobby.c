/*
** lobby.c for tekadventure in /home/leandre/C_graphical_prog/tekadventure
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Wed Apr 12 14:26:56 2017 Léandre Blanchard
** Last update Mon May 29 13:59:59 2017 Léandre Blanchard
*/

#include "tekadventure.h"

static int	create_file(t_info *info, int a)
{
  int		fd;

  info->skin = a;
  if ((fd = open("player.dat", O_RDWR | O_CREAT, 0666)) == -1)
    return (-1);
  if ((write(fd, info, sizeof(t_info))) == -1)
    {
      close(fd);
      my_printf("%s%s%s\n", BOLDRED, ERR_WRI_PLA, RESET);
      return (-1);
    }
  close(fd);
  return (0);
}

static int	put_background(t_info *info, t_window *window, t_sprite *lobby)
{
  static int	a;

  put_sprite(window, lobby, XY(-a / 10));
  put_sprite(window, lobby, XY(1280 - a / 10));
  put_word("Nickname :", xy_vectorf(W_2, H_2 - 50), window, sfBlack);
  put_word(info->name, xy_vectorf(W_2, H_2), window, sfBlack);
  window_refresh(window);
  a = (a + 1) % (1280 * 10);
  return (0);
}

static int	get_username(t_window *window, t_info *info, t_sprite *lobby)
{
  int		i;
  int		k;

  k = 0;
  i = 25;
  zeros(info->name, NAME_SIZE + 1);
  while (i < 36 && sfRenderWindow_isOpen(window->window))
    {
      window_clear(window);
      close_win(window);
      if (key_released(i) && k < NAME_SIZE)
	info->name[k++] = (KP(sfKeyRShift)) ? i + 'A' : i + 'a';
      if (key_released(sfKeyBack) && k > 0)
	info->name[--k] = 0;
      k = (k < 0) ? 0 : k;
      if (i == sfKeyZ)
	i = sfKeyA - 1;
      i++;
      if (key_released(sfKeyReturn) && my_strlen(info->name) > 0)
	return (0);
      put_background(info, window, lobby);
    }
  return (-1);
}

static int	display(t_window *window, t_sprite *lobby,
			t_sprite *sprite, t_info *info)
{
  static int	b;

  put_sprite(window, lobby, xy_vectorf(-b / 10, 0));
  put_sprite(window, lobby, xy_vectorf(1200 -b / 10, 0));
  put_word("Select your skin :\nUsing arrow keys",
	   xy_vectorf(W_2, H_2 - 150), window, sfBlack);
  put_word(info->name, xy_vectorf(W_2 + 30, H_2 + 70), window, sfBlack);
  put_sprite_resize(window, sprite,
		    xy_vectorf(W_2, H_2 + 100), xy_vectorf(2, 2));
  b++;
  return (0);
}

int		lobby(t_window *window, t_info *info, t_textures *sprites)
{
  int		a;
  int		b;
  t_sprite	*lobby;

  lobby = sprites->backgrounds[BG_TREE];
  a = 0;
  b = 0;
  if ((get_username(window, info, lobby)) == -1)
    return (-1);
  while (sfRenderWindow_isOpen(window->window))
    {
      window_clear(window);
      get_lobby_keys(&a);
      if (key_released(sfKeyReturn))
	return (create_file(info, a));
      info->skin = a;
      display(window, lobby, sprites->sprites[a][(b / 100) % 8], info);
      window_refresh(window);
      b++;
      close_win(window);
    }
  return (0);
}
