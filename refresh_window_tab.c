#include "game_2048.h"

void			refresh_window_tab(t_window **window_tab)
{
	int				i;
	int				j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			wclear(window_tab[i][j].win);
			box(window_tab[i][j].win, 0, 0);
			if (window_tab[i][j].numb != 0)
				mvwprintw(window_tab[i][j].win, 1, 5, "%d", window_tab[i][j].numb);
			wrefresh(window_tab[i][j].win);
			j++;
		}
		i++;
	}
}
