/*
** creator.c for creator in /home/leandre/C_graphical_prog/tekadventure
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Sat May 27 19:13:48 2017 Léandre Blanchard
** Last update Sat May 27 19:25:18 2017 Léandre Blanchard
*/

#include "my.h"

static void	print_line(int width, char c)
{
  int		i;

  i = 0;
  write(1, "o", 1);
  while (i < width)
    {
      write(1, &c, 1);
      i++;
    }
  write(1, "o", 1);
  write(1, "\n", 1);
}

int		main(int ac, char **av)
{
  int		width;
  int		height;
  int		i;

  if (ac != 3)
    write(1, "usage : ./creator <width> <height>\n", 36);
  width = my_getnbr(av[1]);
  height = my_getnbr(av[2]);
  i = 0;
  print_line(width, 'o');
  while (i < height)
    {
      print_line(width, ' ');
      i++;
    }
  print_line(width, 'o');
  return (0);
}
