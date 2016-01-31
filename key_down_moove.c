#include "game_2048.h"

static int	*merge(int *tab)
{
	if (tab[3] == tab[2] && tab[1] == tab[0])
	{
		tab[3] = 2 * tab[3];
		tab[2] = 2 *tab[1];
		tab[1] = 0;
		tab[0] = 0;
	}
	else if (tab[3] == tab[2])
	{
		tab[3] = 2 * tab[3];
		tab[2] = tab[1];
		tab[1] = tab[0];
		tab[0] = 0;
	}
	else if (tab[2] == tab[1])
	{
		tab[2] = 2 * tab[2];
		tab[1] = tab[0];
		tab[0] = 0;
	}
	else if (tab[1] == tab[0])
	{
		tab[1] = 2 * tab[1];
		tab[0] = 0;
	}
	return (tab);
}

void			key_down_moove(t_window **window_tab)
{
	int		*tab;
	int		j;
	int		k;
	int		i;

	tab = (int *)malloc(sizeof(int) * 4);
	j = 0;
	while (j < 4)
	{
		k = 3;
		i = 3;
		while (i >= 0)
		{
			if (window_tab[i][j].numb != 0)
			{
				tab[k] = window_tab[i][j].numb;
				k--;
			}
			i--;
		}
		while (k >= 0)
		{
			tab[k] = 0;
			k--;
		}
		tab = merge(tab);
		i = 3;
		while (i >= 0)
		{
			window_tab[i][j].numb = tab[i];
			i--;
		}
		j++;
	}
	refresh_window_tab(window_tab);
}
