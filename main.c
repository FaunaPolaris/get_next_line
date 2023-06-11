#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int	main(int argc, char **argv)
{
	int	fd;
	int	i;

	argc += 1;
	fd = open (argv[1], O_RDONLY);
	while (i < 10)
	{
		printf("%d: %s\n", i, get_next_line(fd));
		i++;
	}
}
