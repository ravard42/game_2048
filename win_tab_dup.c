#include "game_2048.h"

int		**win_tab_dup(t_window **tab)
{
	int	**dup;
	int	i;
	int	j;

	dup = (int **)malloc(sizeof(int *) * 4);
	i = 0;
	while (i < 4)
	{
		dup[i] = (int *)malloc(sizeof(int));
		i++;
	}
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			dup[i][j] = tab[i][j].numb;
			j++;
		}
		i++;
	}
	return (dup);
}
