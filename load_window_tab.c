#include "game_2048.h"

t_window		**load_window_tab()
{
	t_window		**window_tab;
	int				i;
	int				j;

	window_tab = (t_window **)malloc(sizeof(t_window *) * 4);
	i = 0;
	while (i < 4)
	{
		window_tab[i] = (t_window *)malloc(sizeof(t_window) * 4);
		i++;
	}
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			window_tab[i][j].win = newwin(3, 11, LINES / 2 - 8 + 3*i, COLS / 2 - 22 + 11*j);
			box(window_tab[i][j].win, 0, 0);
			window_tab[i][j].numb = 0;
			if (window_tab[i][j].numb != 0)
				mvwprintw(window_tab[i][j].win, 1, 5, "%d", window_tab[i][j].numb);
			wrefresh(window_tab[i][j].win);
			j++;
		}
		i++;
	}
	curs_set(0);
	return (window_tab);

}
