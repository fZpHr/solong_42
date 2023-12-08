#include "get_next_line.h"

char	*ft_loop(int bytes, char *buff, int fd)
{
	char	*line;

	line = ft_strdup(buff);
	if (!line)
		return (NULL);
	while (bytes && ft_checkline(line) == 0)
	{
		bytes = read(fd, buff, BUFFER_SIZE);
		if (bytes < 0)
		{
			free(line);
			return (NULL);
		}
		buff[bytes] = '\0';
		line = ft_strjoin(line, buff);
		if (line == NULL)
			return (NULL);
	}
	return (line);
}

void	ft_nextline(char *str)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (str[i] != '\n' && str[i] != 0)
		i++;
	if (str[i] == '\n')
		i++;
	j = 0;
	while (str[i + j])
	{
		str[j] = str[i + j];
		j++;
	}
	str[j] = 0;
}

char	*get_next_line(int fd)
{
	static char		buff[BUFFER_SIZE + 1] = "\0";
	char			*line;
	int				bytes;

	bytes = 1;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	line = ft_loop(bytes, buff, fd);
	ft_nextline(buff);
	if (!line || line[0] == '\0')
	{
		free(line);
		return (NULL);
	}
	return (line);
}
/*
#include <stdio.h>
#include <fcntl.h>
int	main()
{
	int	fdi;
	int	fdo;
	int	fdp;
	char	*line;
	int	i;
	
	fdi = open("42_no_nl", O_RDONLY);
	fdo = open("43_no_nl", O_RDONLY);
	fdp = open("big_line_no_nl", O_RDONLY);
	i = 1;
	while (i < 5)
	{
		line = get_next_line(fdi);
		printf("Ligne1 : %d\n%s\n", i, line);
		free(line);
		line = get_next_line(fdo);
		printf("Ligne2 : %d\n%s\n", i, line);
		free(line);
		line = get_next_line(fdp);
		printf("Ligne3 : %d\n%s\n", i, line);
		free(line);
		i++;
	}
	close(fdi);
	close(fdo);
	close(fdp);
	return (0);
}*/
