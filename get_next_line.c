#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	char		buf[BUFFER_SIZE + 1];
	static int	b_read;
	static char	*file;

	if (fd <= -1 || BUFFER_SIZE <= 0 || !line)
		return (-1);
	if (fd == 0 && file == NULL)
		while ((b_read = read(0, buf, BUFFER_SIZE)))
		{
			buf[b_read] = '\0';
			file = ft_strjoin(file, buf);
		}
	else
		while (!is_newline(file) && (b_read = read(fd, buf, BUFFER_SIZE)))
		{
			buf[b_read] = '\0';
			file = ft_strjoin(file, buf);
		}
	*line = malloc_line(file, b_read);
	file = move_to_next_line(file);
	if (b_read != BUFFER_SIZE)
		return (0);
	else
		return (1);
}

char	*malloc_line(char *file, int b_read)
{
	char	*buf;
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (file == NULL || (file[0] == '\0' && b_read != BUFFER_SIZE))
		return (NULL);
	while (file[i] && file[i] != '\n')
		i++;
	if (!(buf = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (file[i] && file[i] != '\n')
		buf[j++] = file[i++];
	buf[j] = '\0';
	return (buf);
}

char	*move_to_next_line(char *file)
{
	if (file == NULL)
		return (NULL);
	while (*file)
	{
		if (*file == '\n')
			return (file + 1);
		file++;
	}
	return (NULL);
}

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
int main(int ac, char **av) {
	int fd;
	char *line;

	line = "ZAVAOUQUOI";
	(void)ac;
	(void)av;
	fd = open("test.txt", O_RDONLY);
	/*
	close(fd);
	fd = open("t.txt", O_RDONLY);
	printf("get next line: %d\n", get_next_line(fd, &line));
	 */
	printf("line: %s\n", line);
}