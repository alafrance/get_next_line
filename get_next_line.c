/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafranc <alafranc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 11:59:28 by alafranc          #+#    #+#             */
/*   Updated: 2020/11/27 14:17:21 by alafranc         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_strccpy(char *file, int c)
{
	char	*buf;
	int		i;
	int		j;
	int		r;

	j = 0;
	i = 0;
	while (file[i] && file[i] != '\n')
		i++;
	if (file[i] == '\n')
		i++;
	if (!(buf = malloc(sizeof(char) * (ft_strlen(file) - i + 1))))
		return (NULL);
	while (file[i])
		buf[j++] = file[i++];
	buf[j] = '\0';
	return (buf);
}

char	*ft_substr(char const *s, int end)
{
	char	*buf;
	size_t	size;
	size_t	i;

	i = 0;
	size = 0;
	if (s == NULL)
		return (NULL);
	while (i < end && s[i])
		i++;
	if (!(buf = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (s[i] && i < end)
	{
		buf[i] = s[i];
		i++;
	}
	buf[i] = '\0';
	return (buf);
}

char	*fill_filebuf(int fd, char *filebuf, int *b_read)
{
	char		buf[BUFFER_SIZE + 1];
	if (fd == 0 && filebuf == NULL)
		while ((*b_read = read(0, buf, BUFFER_SIZE)))
		{
			buf[*b_read] = '\0';
			filebuf = ft_strjoin(filebuf, buf);
		}
	else
		while (!ft_strchr(filebuf, '\n') && (*b_read = read(fd, buf, BUFFER_SIZE)))
		{
			buf[*b_read] = '\0';
			filebuf = ft_strjoin(filebuf, buf);
		}
	return (filebuf);
}

int		get_next_line(int fd, char **line)
{
	static int	b_read;
	static char	*filebuf;

	if (fd <= -1 || BUFFER_SIZE <= 0 || !line)
		return (-1);
	filebuf = fill_filebuf(fd, filebuf, &b_read);
	*line = ft_substr(filebuf, ft_strchr(filebuf, '\n'));
	filebuf = ft_strccpy(filebuf, '\n');
	printf("b_read: %d\n", b_read);
	if (filebuf == NULL || (filebuf[0] == '\0' && b_read != BUFFER_SIZE))
		return (0);
	else
		return (1);
}
