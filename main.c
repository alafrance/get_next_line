#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
int test_gnl()
{
    int fd;
    int gnl;
    char filename[100];
    int i;
    int number;
    char *line;

    i = 0;
    number = 0;
    line = 0;
    printf("Tell me the filename: ");
    scanf("%s", filename);
    printf("And the numbers of call's gnl: ");
    scanf("%d", &number);
    if (number < 0)
        return (0);
    fd = open(filename, O_RDONLY);
    printf("\n");
    while (i < number)
    {
        gnl = printf("%d, line: %s\n", get_next_line(fd, &line), line);
        i++;
    }
    printf("\n");
    close(fd);
    return (1);
}

int main(void)
{
    int     fd;
    int     continued;
    char    answer[4];
    char    *line;

    line = NULL;
    continued = 1;
    while(continued == 1)
    {
        if(!(test_gnl()))
            printf("Errorrrr");
        printf("Do you want continue ? y/n:");
        scanf("%s", answer);
        if (strcmp(answer, "y") == 0 || strcmp(answer, "yes") == 0)
            continued = 1;
        else
            continued = 0;
    }
    // getchar(); // For leaks
    return (0);
}