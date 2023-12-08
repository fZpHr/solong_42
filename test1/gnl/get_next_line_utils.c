#include "get_next_line.h"

int	ft_end_ofthe_line(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n' && str[i] != 0)
		i++;
	if (str[i] == '\n')
		i++;
	return (i);
}

size_t	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_checkline(char *str)
{
	size_t	i;

	i = 0;
	if (ft_strlen(str) == 0)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strdup(char *s)
{
	char	*dest;
	int		l;
	int		i;

	i = 0;
	l = ft_end_ofthe_line(s);
	dest = malloc(sizeof(char) * (l + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (i < l)
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ptr;
	int		i;
	int		j;
	int		l;

	i = 0;
	j = 0;
	l = ft_end_ofthe_line(s2);
	ptr = malloc(sizeof(char) * (ft_strlen(s1) + l + 1));
	if (!ptr)
		return (free(s1), NULL);
	while (s1 && s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	while (s2 && j < l)
	{
		ptr[i + j] = s2[j];
		j++;
	}
	ptr[i + j] = '\0';
	free(s1);
	return (ptr);
}
