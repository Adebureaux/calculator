#include "main.h"

double	read_file(char *file, int area, int weight)
{
	FILE	*fd;
	int		count;
	int		i;
	double	ret;
	char	c;
	char	*val;

	fd = fopen(file, "r");
	if (!fd)
		return (0);
	count = 0;
	i = 0;
	c = '\0';
	val = malloc(10);
	printf("\narea before %d\n", area);
	printf("weight before %d\n", weight);
	while (count < area)
	{
		c = fgetc(fd);
		if (c == '\n')
			count++;
	}
	printf("area after %d\n", count);
	count = 0;
	while (count < weight)
	{
		c = fgetc(fd);
		if (c == ';')
			count++;
	}
	printf("\nweight after %d\n", count);
	while ((c = fgetc(fd)) != ';')
	{
		if (c == EOF)
			break ;
		val[i] = c;
		i++;
	}
	val[i] = '\0';
	if ((ret = atof(val)) == 0)
		ret = 11.81;
	fclose(fd);
	free(val);
	return (ret);
}
