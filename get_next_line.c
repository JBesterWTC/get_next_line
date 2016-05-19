#include "libft.h"
#include "get_next_line.h"

int	ft_read_into_store(int const fd, char **store)
{
	static char	buff[BUFF_SIZE+1] = '\n';
	int		read_bytes;
	char		*nstr;

	read_bytes = read(fd, buff, BUFF_SIZE);
	if (read_bytes > 0)
	{
		buff[read_bytes] = 0;
		nstr = ft_strjoin(*store, buff);
		if (!nstr)
			return(-1);
		free(*store);
		*store = nstr;
	}
	return (read_bytes);
}

int	get_next_line(int const fd, char **line)
{
	static char	*store;
	char		*endl_index;
	int		result;

	if ((stock = (char *)ft_memalloc(sizeof(char))) == NULL)
		return (-1);
	endl_index = ft_strchr(stock, '\n');
	while (endl_index == NULL)
	{
		result = read_into_store(fd, &store);
		if (result = 0)
		{
			if ((endl_index = ft_strchr(stock, '\0')) == stock)
				return (0);
		}
		else if (result < 0)
			return (0);
		else
			endl_index = ft_strchr(stock, '\n');
	}
	*line = ft_strsub(stock, 0, endl_index - stock);
	if (!*line)
		return (-1);
	endl_index =ft_strdup(endl_index + 1);
	free(stock);
	stock = endl_index;
	return (1);
}
