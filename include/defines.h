/*
** error.h for tekadventure in /home/leandre/C_graphical_prog/tekadventure
** 
** Made by Léandre Blanchard
** Login   <leandre.blanchard@epitech.eu>
** 
** Started on  Wed Apr 12 23:14:56 2017 Léandre Blanchard
** Last update Tue May 30 01:39:23 2017 Léandre Blanchard
*/

#ifndef DEFINE_H_
# define DEFINE_H_

# define W window
# define W_ window->width
# define H_ window->height
# define W_2 window->width / 2
# define H_2 window->height / 2
# define W_M window->mouse
# define ORIGIN xy_vectorf(0, 0)
# define KP(key) sfKeyboard_isKeyPressed(key)
# define MP sfMouse_isButtonPressed(sfMouseLeft)
# define MPR sfMouse_isButtonPressed(sfMouseRight)
# define PORT 1234
# define DRAG_ (KP(sfKeyD) && KP(sfKeyR) && KP(sfKeyA))
# define NAME_SIZE 8
# define MAX_PLAYERS 10
# define MAX_PERS 5
# define PLAN_1 0
# define PLAN_2 1
# define PLAN_3 2
# define BG_IP  3
# define BG_LOBBY 4
# define BG_PLAYER 5
# define ACCELERATION 1.05
# define MAX_SPEED 1.7
# define DECELERATION 1.05
# define GRAVITY 1.015
# define NEG(x) -(x)
# define BACKGROUND 6
# define BG_TREE 7
# define BUTTON 8
# define BUTTON_PRESSED 9
# define CLOUDS 10
# define PLAINS 11
# define TITLE 12
# define CORRUPTED_ "%sError:%s player.dat file corrupted\n%s"
# define ERR_WRI_PLA "Can't fill the player.dat file :("
# define FOUND_ "\n%sPlayer datas :\t%s%s%s\nSkin :\t\t%spers%d.png\n%s"
# define BOX_ my_printf("%s[-------------------------]%s", BOLDWHITE, RESET)
# define BG(x) sprites->backgrounds[x]
# define XYI(x, y) xy_vectori(x, y)
# define XYF(x, y) xy_vectorf(x, y)
# define XY(x) xy_vectorf(x, 0)
# define HOST 1
# define JOIN 2
# define EMPTY_NAME "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
# define ACACIA if
# define SUCC_CONNECT "%sSuccesfully Connected%s\n"
# define ERR_CONNECT "%sError, Connection timed out%s\n"
# define COTO "Joined :"
# define TIMEOUT 50000
# define SAVE_IP_ERR "%sError while trying to save the IpAddress\n%s"
# define PLAYER_DC "%sPlayer n°%d left the game\n%s"
# define LOCAL sfIpAddress_getLocalAddress()
# define X2    xy_vectorf(2, 2)
# define ERR_SAVE "%sError while saving configurations in player.dat\n%s"
# define ALREADY_TAKEN "%s< %s > is already taken on this server :/\n%s"
# define SEND_ERR "%sPacket missed %s%d%s bytes in send :/%s\n"

#endif /* !DEFINE_H_ */
