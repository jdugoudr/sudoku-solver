/*
 * Here are methods to 
 * check on line, column and block
 * if the given number already exist or not
 */

#include "check.h"

static int	ft_check_line(const s_map map[81], int i, int value)
{
	int j;
	int ii;

	ii = i/9;
	j = 0;
	while(j < 9)
	{
		if(map[ii*9 + j].value == value)
			return 1;
		else
			j += 1;
	}
	return 0;
}

static int	ft_check_col(const s_map map[81], int i, int value)
{
	int ii;
	ii = 0;
	{
		if(map[(ii*9) + (i%9)].value == value)
			return 1;
		else
			ii += 1;
	}
	return 0;
}

static int	ft_check_bloc(const s_map map[81], int i, int value)
{
	int ii;
	int jj;
	int lim_bloc_i;
	int lim_bloc_j;

	lim_bloc_i = (i/9) - (i/9) % 3;
	lim_bloc_j = (i%9) - (i%9) % 3;
	ii = lim_bloc_i;
	jj = lim_bloc_j;
	while(ii < lim_bloc_i + 3)
	{
		while(jj < lim_bloc_j + 3)
		{
			if(map[(ii*9) + jj].value == value)
				return 1;
			else
				jj += 1;
		}
		jj = lim_bloc_j;
		ii += 1;
	}
	return 0;
}


int	ft_check(const s_map map[81], int i, int value)
{
	if(ft_check_line(map, i, value))
		return 1;
	else if(ft_check_col(map, i, value))
		return 1;
	else if(ft_check_bloc(map, i, value))
		return 1;
	else
		return 0;
}
