#include "main.h"

int		national_area(int dep, int arr, int mode)
{
	dep--;
	if (dep > 20)
		dep--;
	else if (dep == 19)
		dep = 12;
	arr--;
	if (arr > 20)
		arr--;
	else if (arr == 19)
		arr = 12;
	return (!mode ? (int)get_pos("ressources/table_zone_national.csv", arr, dep) : (int)get_pos("ressources/table_zone_national_express.csv", arr, dep));
}

int		national_weigth_range(int weight, int mode)
{
		int			weight_range;

		if (weight >= 0 && weight <= 4)
			weight_range = 0;
		else if (weight >= 5 && weight <= 9)
			weight_range = 1;
		else if (weight >= 10 && weight <= 14)
			weight_range = 2;
		else if (weight >= 15 && weight <= 19)
			weight_range = 3;
		else if (weight >= 20 && weight <= 29)
			weight_range = 4;
		else if (weight >= 30 && weight <= 39)
			weight_range = 5;
		else if (weight >= 40 && weight <= 49)
			weight_range = 6;
		else if (weight >= 50 && weight <= 59)
			weight_range = 7;
		else if (weight >= 60 && weight <= 69)
			weight_range = 8;
		else if (weight >= 70 && weight <= 79)
			weight_range = 9;
		else if (weight >= 80 && weight <= 89)
			weight_range = 10;
		else if (weight >= 90 && weight <= 99)
			weight_range = 11;
		if (!mode)
		{
			if (weight >= 100 && weight <= 199)
				weight_range = 12;
			else if (weight >= 200 && weight <= 299)
				weight_range = 13;
			else if (weight >= 300 && weight <= 499)
				weight_range = 14;
			else if (weight >= 500 && weight <= 1000)
				weight_range = 15;
		}
		else
		{
			if (weight >= 100 && weight <= 1000)
				weight_range = 12;
		}
		return (weight_range);
}

double	national_price(int area, int weight, int mode, int corse)
{
	int		weight_range;
	double	base_price;
	double	price;

	area--;
	weight_range = national_weigth_range(weight, mode);
	if (!corse)
	{
		if (!mode)
			base_price = get_pos("ressources/table_messagerie.csv", area, weight_range);
		else
			base_price = get_pos("ressources/table_messagerie_express.csv", area, weight_range);
	}
	else
	{
		if (!mode)
			base_price = get_pos("ressources/table_messagerie_corse.csv", area, weight_range);
		else
			base_price = get_pos("ressources/table_messagerie_express_corse.csv", area, weight_range);
	}
	price = mode ? (base_price * 1.13) + 11.99 : (base_price * 1.13) + 3.99;
	return (weight > 100 ? (price * (double)(weight / 100.00)) : (price));
}
