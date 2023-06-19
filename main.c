#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main(int argc, char **argv)
{
    int fd;
    char *line;

    argc += 1;
    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
    {
        perror("Failed to open the file");
        return 1;
    }
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line); // Remember to free the line allocated by get_next_line
    }
    line = get_next_line(fd);
    free(line);
    close(fd);
    return 0;
}

