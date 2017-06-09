/*
** save_ip.c for tekadventure in /home/leandre/C_graphical_prog/tekadventure
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Fri Apr 14 23:22:13 2017 Léandre Blanchard
** Last update Thu May 11 10:09:09 2017 Léandre Blanchard
*/

#include "tekadventure.h"

int			save_ip(sfIpAddress *addr)
{
  int                   fd;
  char                  useless[36];

  if ((fd = open("player.dat", O_RDWR)) == -1)
    {
      my_printf(ERR_SAVE, BOLDRED, RESET);
      return (-1);
    }
  read(fd, useless, 36);
  if ((write(fd, addr->address, 16)) == -1)
    my_printf(ERR_SAVE, BOLDRED, RESET);
  close(fd);
  return (0);
}

int			scan_save_ip(sfIpAddress *addr)
{
  int			fd;
  char			useless[36];

  if ((fd = open("player.dat", O_RDONLY)) == -1)
    return (-1);
  read(fd, useless, 36);
  read(fd, addr->address, 16);
  close(fd);
  return (0);
}
