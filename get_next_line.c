/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcuadrad <pcuadrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 14:12:09 by pcuadrad          #+#    #+#             */
/*   Updated: 2019/11/20 14:45:27 by pcuadrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	get_line(char **s, char **line)
{
	int		len;
	char	*tmp;

	len = 0;
	while ((*s)[len] != '\n' && (*s)[len] != '\0')
		len++;
	if ((*s)[len] == '\n')
	{
		*line = ft_substr(*s, 0, len);
		tmp = ft_strdup(&((*s)[len + 1]));
		free(*s);
		*s = tmp;
	}
	else
	{
		*line = ft_substr(*s, 0, len);
		free(*s);
		*s = NULL;
		return (0);
	}
	return (1);
}

static int	checkline(char **s, char **line, int fd_read)
{
	if (fd_read < 0)
		return (-1);
	else if ((fd_read == 0 && *s == NULL) || *s[0] == '\0')
	{
		*line = ft_strdup("");
		return (0);
	}
	else
		return (get_line(s, line));
}

int			get_next_line(int fd, char **line)
{
	int			fd_read;
	static char *s;
	char		buff[BUFFER_SIZE + 1];
	char		*tmp;

	if (fd < 0 || !line || !BUFFER_SIZE)
		return (-1);
	while ((fd_read = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[fd_read] = '\0';
		if (s == NULL)
			s = ft_strdup(buff);
		else
		{
			tmp = ft_strjoin(s, buff);
			free(s);
			s = tmp;
		}
		if (ft_strchr(s, '\n'))
			break ;
	}
	return (checkline(&s, line, fd_read));
}
