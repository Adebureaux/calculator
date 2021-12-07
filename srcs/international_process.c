#include "main.h"

static double	multiplier;

int		international_area(char **country)
{
	int			i;
	int			area;
	const char	*country_zone[34] = { "ALL", "AND", "AUT", "BEL", "BOS", "BUL", "CRO", "DAN", "ESP", "EST", "FIN", "HON", "IRL", "ITA", "KOS", "LET", "LIE", "LIT", "LUX", "MAC", "MON", "NOR", "PAY", "POL", "POR", "REP", "ROU", "ANG", "ECO" "SER", "SLO", "SUE", "SUI", 0 };

	i = 0;
	area = -1;
	while (country_zone[i])
	{
		if (strncmp(country[0], country_zone[i], 3) == 0)
			area = i;
		i++;
	}
	return (area);
}

int		international_weigth_range(int real_weight)
{
	int	range_weight;

	range_weight = 0;
	if (real_weight > 100)
		multiplier =  real_weight / 100.00;
	else
		multiplier = 1;
	if (real_weight >= 0 && real_weight <= 9)
		range_weight = 0;
	else if (real_weight > 9 && real_weight <= 19)
		range_weight = 1;
	else if (real_weight > 19 && real_weight <= 29)
		range_weight = 2;
	else if (real_weight > 29 && real_weight <= 39)
		range_weight = 3;
	else if (real_weight > 39 && real_weight <= 49)
		range_weight = 4;
	else if (real_weight > 49 && real_weight <= 59)
		range_weight = 5;
	else if (real_weight > 59 && real_weight <= 69)
		range_weight = 6;
	else if (real_weight > 69 && real_weight <= 79)
		range_weight = 7;
	else if (real_weight > 79 && real_weight <= 89)
		range_weight = 8;
	else if (real_weight > 89 && real_weight <= 99)
		range_weight = 9;
	else if (real_weight > 99 && real_weight <= 199)
		range_weight = 10;
	else if (real_weight > 199 && real_weight <= 299)
		range_weight = 11;
	else if (real_weight > 299 && real_weight <= 399)
		range_weight = 12;
	else if (real_weight > 399 && real_weight <= 499)
		range_weight = 13;
	else if (real_weight > 499 && real_weight <= 999)
		range_weight = 14;
	else if (real_weight > 999 && real_weight <= 1999)
		range_weight = 15;
	else if (real_weight > 1999)
		range_weight = 16;
	else
		return (-1);
	return (range_weight);
}

double	international_price(int range_weight, int area)
{
	double	base;

	base = get_pos("ressources/table_international.csv", area, range_weight);
	return ((base * multiplier * 1.13) + 3.99);
}
