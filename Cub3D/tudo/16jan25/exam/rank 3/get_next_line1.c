#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#ifndef BUFFER_SIZE_H
# define BUFFER_SIZE 43
#endif

char	*str_dup(char *str)
{
	int		i;
	int		len;
	char	*text;

	i = 0;
	while (str[len++])
		;
	text = malloc(sizeof(char) * len + 1);
	if (!text)
		return (NULL);
	while (str[i])
	{
		text[i] = str[i];
		i++;
	}
	text[i] = '\0';
	return (text);
}

char	*get_next_line(int fd)
{
	static	char	chr[BUFFER_SIZE];
	char	str[7000000];
	static	int	b_size;
	static	int	b_pos;
	int	i;

	i = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (1)
	{
		if (b_pos >= b_size)
		{
			b_size = read(fd, chr, BUFFER_SIZE);
			b_pos = 0;
			if (b_size <= 0)
				break ;
		}
		str[i++] = chr[b_pos++];
		if (str[i - 1 ] == '\n')
			break;
	}
	str[i] = '\0';
	if (i == 0)
		return (NULL);
	return (str_dup(str));
}

int	main()
{
	char	*str;
	int	fd;
	
	fd = open("teste.txt", O_RDONLY);
	if (fd < 0)
		return (0);
	str = get_next_line(fd);
	printf("%s", str);
	return (0);
}
