#include "main.h"

double	tarif(int zoneMessagerie, int poids, int mode, int corse)
{
	int			tranchePoids;
	double		prixBase;

	zoneMessagerie--;
	if (poids >= 0 && poids <= 4)
		tranchePoids = 0;
	else if (poids >= 5 && poids <= 9)
		tranchePoids = 1;
	else if (poids >= 10 && poids <= 14)
		tranchePoids = 2;
	else if (poids >= 15 && poids <= 19)
		tranchePoids = 3;
	else if (poids >= 20 && poids <= 29)
		tranchePoids = 4;
	else if (poids >= 30 && poids <= 39)
		tranchePoids = 5;
	else if (poids >= 40 && poids <= 49)
		tranchePoids = 6;
	else if (poids >= 50 && poids <= 59)
		tranchePoids = 7;
	else if (poids >= 60 && poids <= 69)
		tranchePoids = 8;
	else if (poids >= 70 && poids <= 79)
		tranchePoids = 9;
	else if (poids >= 80 && poids <= 89)
		tranchePoids = 10;
	else if (poids >= 90 && poids <= 99)
		tranchePoids = 11;
	if (!mode)
	{
		if (poids >= 100 && poids <= 199)
			tranchePoids = 12;
		else if (poids >= 200 && poids <= 299)
			tranchePoids = 13;
		else if (poids >= 300 && poids <= 499)
			tranchePoids = 14;
		else if (poids >= 500 && poids <= 1000)
			tranchePoids = 15;
	}
	else
	{
		if (poids >= 100 && poids <= 1000)
			tranchePoids = 12;
	}
	if (!corse)
	{
		if (!mode)
			prixBase = get_pos("ressources/table_messagerie.csv", zoneMessagerie, tranchePoids);
		else
			prixBase = get_pos("ressources/table_messagerie_express.csv", zoneMessagerie, tranchePoids);
	}
	else
	{
		if (!mode)
			prixBase = get_pos("ressources/table_messagerie_corse.csv", zoneMessagerie, tranchePoids);
		else
			prixBase = get_pos("ressources/table_messagerie_express_corse.csv", zoneMessagerie, tranchePoids);
	}
	return poids > 100 ? (prixBase * (double)(poids / 100.00)) : (prixBase);
}
