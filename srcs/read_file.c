#include "main.h"

double	get_pos(char *file, int x, int y)
{
	FILE	*fd;
	char	*val;
	char	c;
	double	ret;
	int		count;
	int		i;

	fd = fopen(file, "r");
	if (!fd)
		return (0);
	count = 0;
	i = 0;
	c = '\0';
	val = malloc(10);
	while (count < x)
	{
		if (isalpha(c = fgetc(fd)))
		{
			while (!isdigit(c))
				c = fgetc(fd);
		}
		if (c == EOF)
			break ;
		if (c == '\n')
			count++;
	}
	count = 0;
	while (count < y)
	{
		if (isalpha(c = fgetc(fd)))
		{
			while (!isdigit(c))
				c = fgetc(fd);
		}
		if (c == EOF)
			break ;
		if (c == ';')
			count++;
	}
	while ((c = fgetc(fd)) != ';' && c != '\n')
	{
		if (isalpha(c))
		{
			while (!isdigit(c))
				c = fgetc(fd);
		}
		if (c == EOF)
			break ;
		if (isdigit(c) || c == '.')
		{
			val[i] = c;
			i++;
		}
	}
	val[i] = '\0';
	ret = atof(val);
	fclose(fd);
	free(val);
	return (ret);
}
