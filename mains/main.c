#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(int argc, char **argv)
{
	char	*result;
	int	fd;

	if (argc != 2)
		return (0);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return(0);
	result = get_next_line(fd);
	printf("buffer size: %d\n", (BUFFER_SIZE));	
	printf("result: %s\n", result);
	close(fd);
	free (result);
	return (1);
}
