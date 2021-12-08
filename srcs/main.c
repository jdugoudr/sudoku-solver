#include	<unistd.h>
#include 	<sys/types.h>
#include 	<sys/stat.h>
#include	<fcntl.h>
#include	"header.h"
#include	"print.h"
#include	"resolver.h"

/*
 * Main function
 * the parse is done here
 */

int	main(int argc, char **argv)
{
	int		fd;
	int		i;
	s_map	map[81];
	char	buf;
	int		k;

	i = 0;
	buf = 'f';
	if(argc != 2)
	{
		ft_putstr("Usage: ./exe path\nYou must give a path to a correct grid");
		return 0;
	}
	fd = open(argv[1], O_RDONLY); 
	if(fd == -1)
	{
		ft_putstr("sorry a problem to open the file. Maybe it doesn't exist\n" \
				"please retry later or with an another file\n");
		return 0;
	}
	while(i < 81)
	{
		if(read(fd, &buf, 1))
		{
			if((buf < '0') | (buf > '9'))
			{
				ft_putstr("erreur file is not valid\n");
				close(fd);
				return 0;
			}
			map[i].value = (buf - 48);
			map[i].nb_pos = 0;
			k = 0;
			while(k < 9)
			{
				map[i].tab[k] = 0;
				k += 1;
			}
		}
		else
		{
			ft_putstr("erreur reading on file\n");
			close(fd);
			return 0;
		}
		i += 1;
	}

	close(fd);
	ft_printMap(map);
	ft_putchar('\n');
	
	ft_resolve(map);
	
	ft_putstr("Solution :\n");
	ft_printMap(map);
	ft_putchar('\n');
	return 0;
}

void	ft_printMap(s_map map[81])
{
	int i;

	i = 0;
	while(i < 81)
	{
		if (map[i].value == 0)
			ft_putchar('.');
		else
			ft_putchar(map[i].value + 48);
		if((i%9) == 8)
			ft_putchar('\n');
		else
			ft_putchar(' ');
		i += 1;
		if (((i-1) % 9) < 8 && (i%3) == 0)
			ft_putstr("| ");
		if ((i % 27) == 0 && i < 81)
			ft_putstr("----------------------\n");

	}
}
