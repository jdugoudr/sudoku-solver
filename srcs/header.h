/************************/
/* fichier : header.h   */
/* create date : .      */
/*						*/
/************************/

#ifndef H_HEADER_H
	#define H_HEADER_H
	#include <stdio.h>
	typedef struct s_map s_map;
	struct s_map{
		int value;
		int nb_pos;
		int tab[9];
	};
	void	ft_printMap(s_map map[81]);
	//char	*ft_pathToFile(char *name, char final_path[50]);
#endif
