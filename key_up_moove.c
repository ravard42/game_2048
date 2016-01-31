#include "game_2048.h"

static int	*merge(int *tab)
{
	if (tab[0] == tab[1] && tab[2] == tab[3])
	{
		tab[0] = 2 * tab[0];
		tab[1] = 2 *tab[2];
		tab[2] = 0;
		tab[3] = 0;
	}
	else if (tab[0] == tab[1])
	{
		tab[0] = 2 * tab[0];
		tab[1] = tab[2];
		tab[2] = tab[3];
		tab[3] = 0;
	}
	else if (tab[1] == tab[2])
	{
		tab[1] = 2 * tab[1];
		tab[2] = tab[3];
		tab[3] = 0;
	}
	else if (tab[2] == tab[3])
	{
		tab[2] = 2 * tab[2];
		tab[3] = 0;
	}
	return (tab);
}

void			key_up_moove(t_window **window_tab)
{
	int		*tab;
	int		j;
	int		k;
	int		i;

	tab = (int *)malloc(sizeof(int) * 4);
	j = 0;
	while (j < 4)
	{
		k = 0;
		i = 0;
		while (i < 4)
		{
			if (window_tab[i][j].numb != 0)
			{
				tab[k] = window_tab[i][j].numb;
				k++;
			}
			i++;
		}
		while (k < 4)
		{
			tab[k] = 0;
			k++;
		}
		tab = merge(tab);
		i = 0;
		while (i < 4)
		{
			window_tab[i][j].numb = tab[i];
			i++;
		}
		j++;
	}
	refresh_window_tab(window_tab);
}
