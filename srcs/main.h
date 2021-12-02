#ifndef MAIN_H
# define MAIN_H
# define _WIN32_WINNT 0x0500
# include <gtk/gtk.h>
# include <stdlib.h>
# include <windows.h>
# include <string.h>
# include <stdio.h>
# include <ctype.h>
# include <math.h>

double		get_base_from_file(char *file, int area, int weight);

GtkWidget	*national(GtkWidget *grid);
int			zone(int dep, int arr, int mode);
double		tarif(int zoneMessagerie, int poids, int mode, int corse);
double		calcTarif(int poidsTranche, int zone);

GtkWidget	*international(GtkWidget *grid);
int			international_weigth_range(int real_weight);
int			international_area(char **country);
double		international_price(int range_weight, int area);
#endif
