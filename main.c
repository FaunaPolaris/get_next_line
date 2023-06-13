#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int	main(int argc, char **argv)
{
	int	fd;
	int	i;
	char	*output;

	argc += 1;
	fd = open (argv[1], O_RDONLY);
	i = 0;
	while (i < 10)
	{
		output = get_next_line(fd);
		printf("%d: %s\n", i, output);
		i++;
		free(output);
	}
}
