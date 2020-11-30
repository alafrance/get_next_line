/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafranc <alafranc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 23:59:34 by alafranc          #+#    #+#             */
/*   Updated: 2020/11/30 19:11:16 by alafranc         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int		get_next_line(int fd, char **line);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *s);
char	*ft_strdup(char *src);
void	*ft_strccpy(char *file, int c);
int		ft_strchr(char *file, int c);
char	*ft_substr_line(char *s);
char	*ft_remove_first_line(char *file);
#endif
