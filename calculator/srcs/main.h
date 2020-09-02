#ifndef MAIN_H
# define MAIN_H
# include <gtk/gtk.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <ctype.h>
# include <math.h>

GtkWidget	*geodis_national(GtkWidget *grid);
GtkWidget	*geodis_international(GtkWidget *grid);
int			zone(int dep, int arr, int mode);
double		tarif(int zoneMessagerie, int poids, int mode, int corse);
int			calcPoids(int poids, double volume);
int			calcZone(char **pays);
double  calcTarif(int poidsTranche, int zone);
#endif
