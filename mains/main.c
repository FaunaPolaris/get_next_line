#include "get_next_line.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	char	*result;
	int	fd;

	if (argc != 2)
		return ;
	fd = open(argv[1]);
	result = (get_next_line(fd));
	printf("buffer size: BUFFER_SIZE\nresult: %s\n", result);
	close(fd);
	free (result);
	return (1)
}
