#include "game_2048.h"

void		new_rand_box(t_window **window_tab)
{
		int		i;
		int		numb;
		int		j;
		int		k;
		t_window	**tab;

		i = 0;
		numb = 0;
		while (i < 4)
		{
			j = 0;
			while (j < 4)
			{
				if (window_tab[i][j].numb == 0)
					numb++;
				j++;
			}
			i++;
		}
		tab = (t_window **)malloc(sizeof(t_window *) * numb);
		i = 0;
		k = 0;
		while (i < 4)
		{
			j = 0;
			while (j < 4)
			{
				if (window_tab[i][j].numb == 0)
				{
					tab[k] = &window_tab[i][j];
					k++;
				}
				j++;
			}
			i++;
		}
		k = rand()%numb;
		(*tab[k]).numb = new_numb();
}
