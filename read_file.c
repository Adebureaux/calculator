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

double	get_fix_var(FILE *fd, char* buf)
{
	double	ret;
	int	i;

	buf = malloc(1000);
	fgets(buf, 1000, fd);
	i = 0;
	while (buf[i] && buf[i] != '\n')
	{
		if (isdigit(buf[i]))
		{
			ret = atof(&buf[i]);
			break ;
		}
		i++;
	}
	free(buf);
	return (ret);
}

void	get_var(t_var *var)
{
	FILE		*fd;
	char		*buf;
	int			i;
	int			j;

	fd = fopen("ressources/table_variables.csv", "r");
	if (!fd)
		return ;
	buf = malloc(1000);
	fgets(buf, 1000, fd);
	i = 0;
	j = 0;
	while (buf[i] && buf[i] != '\n')
	{
		if (isdigit(buf[i]))
		{
			var->divisor[j] = 1 - atof(&buf[i]) / 100;
			while (buf[i] && buf[i] != ';')
				i++;
			j++;
		}
		else
			i++;
	}
	free(buf);
	var->tgo = get_fix_var(fd, buf) / 100 + 1;
	var->base_national = get_fix_var(fd, buf);
	var->base_national_express = get_fix_var(fd, buf);
	var->base_international = get_fix_var(fd, buf);
	fclose(fd);
}
