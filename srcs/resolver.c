/*
 * This the file where the magic appear
 */

#include "resolver.h"

/*
 * Here we check for each empty cases on the map
 * the number of possibilty we have
 */
int	ft_possibilty(s_map map[81])
{
	int	i;
	int k;
	int still_pos;

	still_pos = 0;
	k = 1;
	i = 0;
	while(i < 81)
	{
		if(map[i].value == 0)
		{
			map[i].nb_pos = 0;
			while(k <= 9)
			{
				if(!ft_check(map, i, k))
				{
					map[i].tab[map[i].nb_pos] = k;
					map[i].nb_pos += 1;
					still_pos += 1;
				}
				k += 1;
			}
		}
		k = 1;
		i += 1;
	}
	return still_pos;
}

/*
 * We looking for the case with
 * the less possibilty
 */
int	ft_less(s_map map[81])
{
	int i;
	int ii;
	int less;

	less = 10;
	ii = 0;
	i = 0;
	while(i < 81)
	{
		if(map[i].nb_pos < less && map[i].value == 0)
		{
			ii = i;
			less = map[ii].nb_pos;
		}
		i += 1;
	}
	return ii;
}

/*
 * Here is the backtracking
 * We put on the box with the less possibilties
 * and we call back the same method
 * if we can't resolve the sudoku we come back
 * to last choice and try a new possibility
 */
int ft_resolve(s_map map[81])
{
	int i;
	int k;

	k = 0;
	i = 0;
	if(ft_possibilty(map) == 0)
		return ft_end(map);

	else 
	{
		i = ft_less(map);
		while(k < map[i].nb_pos)
		{
			map[i].value = map[i].tab[k];
			if(!ft_resolve(map))
				return 0;
			k += 1;
		}
		map[i].value = 0;
		map[i].nb_pos = 0;
		return 1;
	}
}

/*
 * If we have no more possibilty on the
 * all map, we check if the map is finished.
 * If it's not we have to try an other number
 */
int	ft_end(s_map map[81])
{
	int i = 0;

	while(i < 81)
	{
		if(map[i].value == 0)
			return 1;
		i += 1;
	}
	return 0;
}
