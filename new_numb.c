#include "game_2048.h"

int		new_numb(void)
{
	int	k;

	while (1)
	{
		k = rand()%3 + 2;
		switch (k)
		{
			case 2 :
				return (k);
			case 4 :
				return (k);
			case 3 :
				break;
		}
	}
}
