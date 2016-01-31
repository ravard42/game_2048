#include "game_2048.h"

int			main(void)
{
	t_window	**win_tab;
	int		**tab_temoin;
	int			c;

	srand(time(NULL));
	
	initscr();
	noecho();
	cbreak();
	keypad(stdscr, TRUE);
	win_tab = load_window_tab();
	refresh();
	refresh_window_tab(win_tab);
	sleep(3);
	new_rand_box(win_tab);
	new_rand_box(win_tab);
	refresh();
	refresh_window_tab(win_tab);
	while (1)
	{
		tab_temoin = win_tab_dup(win_tab);
		c = getch();
		switch (c)
		{
			case KEY_UP:
				key_up_moove(win_tab);
				break;
			case KEY_DOWN:
				key_down_moove(win_tab);
				break;
			case KEY_LEFT:
				key_left_moove(win_tab);
				break;
			case KEY_RIGHT:
				key_right_moove(win_tab);
				break;
		}
		if (comparison(tab_temoin, win_tab))
			new_rand_box(win_tab);
		refresh();
		refresh_window_tab(win_tab);
	}
	refresh();
	sleep(4);
	endwin();
	return (0);
}
