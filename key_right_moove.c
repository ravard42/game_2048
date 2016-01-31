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

void			key_right_moove(t_window **window_tab)
{
	int		*tab;
	int		i;
	int		k;
	int		j;

	tab = (int *)malloc(sizeof(int) * 4);
	i = 0;
	while (i < 4)
	{
		k = 3;
		j = 3;
		while (j >= 0)
		{
			if (window_tab[i][j].numb != 0)
			{
				tab[k] = window_tab[i][j].numb;
				k--;
			}
			j--;
		}
		while (k >= 0)
		{
			tab[k] = 0;
			k--;
		}
		tab = merge(tab);
		j = 3;
		while (j >= 0)
		{
			window_tab[i][j].numb = tab[j];
			j--;
		}
		i++;
	}
	refresh_window_tab(window_tab);
}
