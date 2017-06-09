/*
** create_backgrounds.c for tekadventure in /home/leandre/C_graphical_prog/tekadventure
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Wed Apr 19 11:15:15 2017 Léandre Blanchard
** Last update Tue May 30 00:50:46 2017 Léandre Blanchard
*/

#include "tekadventure.h"

static int     		check_null(t_sprite **backgrounds)
{
  int			i;

  i = 0;
  while (i != 16)
    if (backgrounds[i++] == NULL)
      return (-1);
  return (0);
}

static void		ingame_sprites(t_sprite **backgrounds)
{
  backgrounds[0] = create_sprite("sprites/soil.png");
  backgrounds[1] = create_sprite("sprites/space.png");
  backgrounds[2] = create_sprite("sprites/dyson.png");
  backgrounds[12] = create_sprite("sprites/title.png");
  backgrounds[13] = create_sprite("sprites/iron_block.png");
  backgrounds[14] = create_sprite("sprites/gate.png");
  backgrounds[15] = create_sprite("sprites/stone.png");
  backgrounds[16] = create_sprite("sprites/PlanetAqua.png");
  backgrounds[17] = create_sprite("sprites/PlanetRock.png");
  backgrounds[18] = create_sprite("sprites/PlanetShinny.png");
  backgrounds[19] = create_sprite("sprites/PlanetSunny.png");
  backgrounds[20] = create_sprite("sprites/PlanetWhite.png");
}

t_sprite		**create_backgrounds(void)
{
  t_sprite		**backgrounds;

  if ((backgrounds = create_sprites(22)) == NULL)
    return (NULL);
  backgrounds[3] = create_sprite("sprites/background_ip.png");
  backgrounds[4] = create_sprite("sprites/background_lobby.png");
  backgrounds[5] = create_sprite("sprites/spaceship.png");
  backgrounds[6] = create_sprite("sprites/background.png");
  backgrounds[7] = create_sprite("sprites/background_tree.png");
  backgrounds[8] = create_sprite("sprites/button.png");
  backgrounds[9] = create_sprite("sprites/button_pressed.png");
  backgrounds[10] = create_sprite("sprites/clouds.png");
  backgrounds[11] = create_sprite("sprites/plains.png");
  ingame_sprites(backgrounds);
  backgrounds[21] = NULL;
  if (check_null(backgrounds) == -1)
    return (NULL);
  return (backgrounds);
}
