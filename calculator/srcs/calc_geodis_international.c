#include "main.h"

static double	multiplier;

int		calcPoids(int poidsReel)
{
	int		tranchePoids;

	tranchePoids = 0;
	if (poidsReel > 100)
		multiplier =  poidsReel / 100;
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
	{ "ALL", "AND", "AUT", "BEL", "BOS", "BUL", "CRO", "DAN", "ESP", "EST", "FIN", "HON", "IRL", "ITA", "KOS", "LET", "LIE", "LIT", "LUX", "MAC", "MON", "NOR", "PAY", "POL", "POR", "REP", "ROU", "ANG", "ECO", "SER", "SLO", "SUE", "SUI", 0 };

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
	const double	tablePrix[33][17] =
	{
		{ 46.61, 50.10, 53.57, 57.05, 60.52, 63.99, 67.48, 70.95, 74.42, 81.68, 81.68, 70.79, 63.80, 58.53, 58.16, 50.94, 44.10 },
		{ 38.96, 49.80, 61.35, 71.49, 81.01, 85.56, 100.84, 110.24, 120.58, 133.68, 123.38, 111.24, 103.73, 99.68, 94.33, 81.78, 77.96 },
		{ 64.06, 75.67, 87.27, 98.86, 110.46, 122.04, 133.64, 145.23, 156.84, 168.45, 152.91, 129.45, 118.81, 112.50, 101.10, 84.20, 80.00 },
		{ 34.42, 38.91, 43.41, 47.91, 52.41, 56.90, 61.41, 65.91, 70.42, 74.89, 64.32, 54.07, 45.88, 40.08, 37.87, 32.57, 27.70 },
		{ 134.72, 136.24, 138.90, 141.09, 143.04, 179.50, 180.61, 181.69, 182.78, 183.75, 193.78, 162.42, 146.52, 136.00, 117.37, 105.88, 105.82 },
		{ 138.52, 141.57, 144.32, 147.64, 151.21, 168.95, 171.89, 174.78, 177.71, 180.66, 173.92, 146.94, 129.20, 118.83, 99.59, 88.01, 87.97 },
		{ 112.27, 113.54, 115.74, 117.55, 119.18, 149.60, 150.51, 151.41, 152.31, 153.13, 161.47, 135.33, 122.10, 113.33, 97.82, 88.23, 88.18 },
		{ 73.37, 79.12, 84.36, 88.07, 92.98, 106.85, 111.15, 115.29, 119.27, 123.05, 111.00, 105.37, 90.65, 85.52, 77.99, 68.72, 66.53 },
		{ 61.93, 70.03, 83.60, 96.32, 107.99, 119.07, 129.65, 139.71, 149.36, 158.68, 152.96, 138.34, 127.78, 120.20, 110.88, 98.22, 93.22 },
		{ 139.05, 144.67, 149.63, 158.90, 163.71, 172.66, 176.94, 181.10, 185.05, 188.85, 180.99, 153.14, 138.94, 128.98, 110.08, 92.12, 86.50 },
		{ 97.94, 103.56, 108.65, 111.23, 116.03, 120.69, 125.08, 129.34, 133.43, 137.31, 150.74, 125.74, 111.40, 102.34, 91.52, 77.87, 75.36 },
		{ 91.71, 92.54, 94.11, 95.40, 96.55, 120.13, 120.74, 121.32, 121.92, 122.45, 130.30, 109.42, 98.83, 91.79, 79.37, 71.33, 71.29 },
		{ 95.89, 104.54, 113.19, 121.87, 130.55, 139.23, 147.94, 156.65, 165.36, 174.07, 157.54, 136.53, 119.47, 107.51, 104.82, 90.16, 76.64 },
		{ 48.37, 53.13, 57.89, 62.64, 67.39, 72.15, 76.90, 81.66, 86.41, 89.61, 90.51, 79.22, 70.01, 63.61, 62.62, 54.35, 46.64 },
		{ 306.20, 309.28, 314.90, 319.46, 323.59, 404.56, 406.80, 408.98, 411.18, 413.15, 437.80, 367.38, 331.65, 307.96, 266.09, 239.60, 239.43 },
		{ 120.28, 126.37, 131.74, 141.43, 146.61, 151.55, 156.31, 160.87, 165.23, 169.43, 155.10, 124.69, 110.93, 101.87, 90.61, 82.00, 79.73 },
		{ 64.64, 71.95, 79.26, 86.59, 93.88, 101.20, 108.51, 115.84, 123.14, 130.46, 112.25, 100.21, 90.31, 83.73, 84.09, 72.31, 61.46 },
		{ 106.89, 113.28, 118.95, 127.26, 132.78, 150.48, 155.26, 159.85, 164.25, 168.45, 152.03, 123.41, 110.04, 101.05, 88.02, 77.81, 74.83 },
		{ 36.73, 41.53, 46.33, 51.13, 55.93, 60.74, 65.54, 70.36, 75.15, 79.93, 69.34, 58.84, 50.44, 44.48, 42.45, 36.84, 31.63 },
		{ 291.09, 294.58, 298.96, 303.09, 307.10, 317.31, 321.06, 324.75, 328.50, 332.20, 339.64, 295.63, 264.14, 246.63, 215.64, 198.19, 190.19 },
		{ 334.74, 338.76, 343.81, 348.54, 353.16, 364.94, 369.20, 373.45, 377.75, 382.03, 390.59, 339.99, 303.75, 283.61, 247.99, 227.90, 218.71 },
		{ 76.07, 81.48, 112.55, 143.56, 146.99, 150.30, 153.43, 156.47, 182.01, 184.32, 199.99, 175.93, 160.96, 151.63, 134.05, 125.38, 126.29 },
		{ 38.27, 42.83, 47.42, 52.00, 56.53, 61.12, 65.68, 70.25, 74.82, 79.39, 75.31, 62.00, 52.51, 45.75, 43.16, 37.79, 32.69 },
		{ 54.96, 62.68, 69.61, 74.89, 81.47, 95.66, 101.53, 107.15, 112.53, 117.71, 120.79, 103.38, 96.93, 90.25, 83.79, 77.81, 76.15 },
		{ 51.48, 58.77, 66.05, 73.34, 80.62, 87.92, 95.20, 102.49, 109.79, 117.07, 113.88, 98.70, 86.37, 77.73, 75.79, 65.18, 55.39 },
		{ 75.59, 78.79, 82.72, 85.12, 87.53, 94.84, 102.08, 104.63, 110.18, 118.13, 109.03, 102.58, 97.38, 91.26, 88.30, 85.79, 81.53 },
		{ 213.60, 215.93, 218.86, 221.60, 224.30, 229.34, 231.81, 234.27, 236.78, 239.24, 239.21, 205.42, 182.04, 169.05, 146.47, 134.04, 128.62 },
		{ 73.57, 83.84, 94.09, 104.38, 114.62, 124.89, 135.14, 145.41, 155.67, 165.94, 148.11, 129.63, 114.55, 104.08, 97.64, 88.75, 76.13 },
		{ 148.22, 149.86, 152.78, 155.17, 157.34, 197.45, 198.68, 199.85, 201.05, 202.12, 213.16, 178.65, 161.16, 149.60, 129.12, 116.47, 116.41 },
		{ 84.51, 88.48, 93.48, 96.33, 99.14, 113.55, 116.08, 118.65, 121.23, 130.03, 130.89, 114.78, 104.37, 97.30, 88.55, 83.96, 80.69 },
		{ 70.97, 76.63, 93.89, 96.58, 101.17, 135.85, 139.42, 163.99, 166.87, 169.59, 168.50, 137.17, 119.77, 112.28, 100.79, 89.61, 86.57 },
		{ 71.52, 79.61, 87.71, 95.81, 103.89, 111.99, 120.09, 128.19, 136.28, 144.37, 124.23, 110.89, 99.96, 92.66, 93.04, 80.01, 68.01 }
	};

	prixBase = ((tablePrix[zone][poidsTranche] * multiplier) * 1.13) + 3.99;
	return (prixBase);
}
