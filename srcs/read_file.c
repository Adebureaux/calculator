#include "main.h"

double	get_base_from_file(char *file, int area, int weight)
{
	FILE	*fd;
	int		count;
	int		i;
	char	c;
	char	*val;
	double	ret;

	fd = fopen(file, "r");
	if (!fd)
		return (0);
	count = 0;
	i = 0;
	c = '\0';
	val = malloc(10);
	while (count < area)
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
	while (count < weight)
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
