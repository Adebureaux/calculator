#include "main.h"

static double	multiplier;

int		calcPoids(int poidsReel)
{
	int		tranchePoids;

	tranchePoids = 0;
	if (poidsReel > 100)
		multiplier =  poidsReel / 100.00;
	else
		multiplier = 1;
	if (poidsReel >= 0 && poidsReel <= 9)
		tranchePoids = 0;
	else if (poidsReel > 9 && poidsReel <= 19)
		tranchePoids = 1;
	else if (poidsReel > 19 && poidsReel <= 29)
		tranchePoids = 2;
	else if (poidsReel > 29 && poidsReel <= 39)
		tranchePoids = 3;
	else if (poidsReel > 39 && poidsReel <= 49)
		tranchePoids = 4;
	else if (poidsReel > 49 && poidsReel <= 59)
		tranchePoids = 5;
	else if (poidsReel > 59 && poidsReel <= 69)
		tranchePoids = 6;
	else if (poidsReel > 69 && poidsReel <= 79)
		tranchePoids = 7;
	else if (poidsReel > 79 && poidsReel <= 89)
		tranchePoids = 8;
	else if (poidsReel > 89 && poidsReel <= 99)
		tranchePoids = 9;
	else if (poidsReel > 99 && poidsReel <= 199)
		tranchePoids = 10;
	else if (poidsReel > 199 && poidsReel <= 299)
		tranchePoids = 11;
	else if (poidsReel > 299 && poidsReel <= 399)
		tranchePoids = 12;
	else if (poidsReel > 399 && poidsReel <= 499)
		tranchePoids = 13;
	else if (poidsReel > 499 && poidsReel <= 999)
		tranchePoids = 14;
	else if (poidsReel > 999 && poidsReel <= 1999)
		tranchePoids = 15;
	else if (poidsReel > 1999)
		tranchePoids = 16;
	else
		return (-1);
	return (tranchePoids);
}

int		calcZone(char **pays)
{
	int			i;
	int			zone;
	const char	*zonePays[34] =
	{ "ALL", "AND", "AUT", "BEL", "BOS", "BUL", "CRO", "DAN", "ESP", "EST", "FIN", "HON", "IRL", "ITA", "KOS", "LET", "LIE", "LIT", "LUX", "MAC", "MON", "NOR", "PAY", "POL", "POR", "REP", "ROU", "ANG", "SER", "SLO", "SUE", "SUI", 0 };

	i = 0;
	zone = -1;
	while (zonePays[i])
	{
		if (strncmp(pays[0], zonePays[i], 3) == 0)
			zone = i;
		i++;
	}
	return zone;
}

double	calcTarif(int poidsTranche, int zone)
{
	double			prixBase;
	prixBase = read_file("ressources/table_international.csv", zone, poidsTranche);
	return ((prixBase * multiplier * 1.13) + 3.99);
}
