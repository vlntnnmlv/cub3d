# cub3d

Graphical project implementing ray-casting. Currently can be build only on MacOS systems.

```
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define ERROR 1
#define SUCCESS 0

typedef enum	e_side
{
	BUY = 0,
	SELL
}				t_side;

typedef struct	s_application
{
	size_t	id;
	t_side	side;
	size_t	q;
	double	p;
}				t_application;

typedef struct	s_trade
{
	size_t	id;
	t_side	side;
}				t_trade;

int main(int ac, char **av)
{
	if (ac != 2)
	{
		printf("usage: %s input-file\n", av[0]);
		return ERROR;
	}
	FILE 	*fp;
	char 	*line = NULL;
	size_t	len = 0;
	size_t 	read;

	fp = fopen(av[1], "r");
	if (!fp)
	{
		printf("input file error");
		return ERROR;
	}

	t_application *applications = malloc(0);

	char	cur_type;
	int 	cur_id;
	char	cur_side;
	int 	cur_q;
	double	cur_p;
	char 	*tmp;

	while ((read = getline(&line, &len, fp)) != -1)
	{
		printf("%s", line);
		sscanf(line, "%c,%d,%c,%s,%d,%lf", &cur_type, &cur_id, &cur_side, tmp, &cur_q, &cur_p);
		printf("%c,%d,%c,%d,%f\n", cur_type, cur_id, cur_side, cur_q, cur_p);
	}
}
```
