#include "main.h"

int zone(int dep, int arr, int mode)
{
	int zoneMessagerie = 0;

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
	if (!mode)
		zoneMessagerie = (int)get_pos("table_zone_national.csv", arr, dep);
	else
		zoneMessagerie = (int)get_pos("table_zone_national_express.csv", arr, dep);
	return (zoneMessagerie);
}
