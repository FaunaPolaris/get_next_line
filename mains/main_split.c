#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int	main(int argc, char **argv)
{
	int	i;
	char	**news;
	int	fd;
	char	buffer[BUFFER_SIZE];

	argc -= 1;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (0);
	i = read(fd, buffer, 50);
	news = split(buffer, count_lines(buffer));
	close (i);
	i = 0;
	while (i < count_lines(buffer))
	{
		printf("%d: %s\n", i, news[i]);
		i++;
	}
	free(news);
	return (1);
}
