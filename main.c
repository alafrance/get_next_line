#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stdlib.h"
#include "unistd.h"
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include "get_next_line.h"

int            main(int ac, char **av)
{
    int        fd;
    int        fd2;
    int     ret;
    char    *line;
    int     count = 0;

    line = NULL;
    if(ac != 3)
        return (-1);
    fd = open(av[1], O_RDONLY);
    fd2 = open(av[2], O_RDONLY);
    /*
    while ((ret = get_next_line(fd, &line)) > 0)
    {
        printf("%d - %s\n", ret, line);
        free(line);
        count++;
    }
    count++;
    printf("%d - %s\n", ret, line);
    printf("LIGNE LUE(S) : %d\n", count);
    free(line);
    count = 0;
    */
    while ((ret = get_next_line(fd2, &line)) > 0)
    {
        printf("%d -  %s\n", ret, line);
        free(line);
        count++;
    }
    count++;
    printf("LIGNE LUE(S) : %d\n", count);
    close(fd);
    close(fd2);
    fclose(stdout);
    getchar();
}