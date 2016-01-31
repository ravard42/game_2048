#include "game_2048.h"

int	comparison(int **tab_temoin, t_window **tab)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (tab_temoin[i][j] != tab[i][j].numb)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
