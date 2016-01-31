#ifndef GAME_2048_H
# define GAME_2048_H

#include <ncurses.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

typedef struct				s_window
{
	WINDOW					*win;
	int						numb;
}							t_window;

int						new_numb(void);
t_window					**load_window_tab();
void			new_rand_box(t_window **win_tab);
void			refresh_window_tab(t_window **win_tab);

int		**win_tab_dup(t_window **tab);
int	comparison(int **tab_temoin, t_window **tab);


void				key_up_moove(t_window **window_tab);
void			key_down_moove(t_window **window_tab);
void			key_left_moove(t_window **window_tab);
void			key_right_moove(t_window **window_tab);

#endif
