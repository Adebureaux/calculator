#ifndef MAIN_H
# define MAIN_H
# define _WIN32_WINNT 0x0500
# include <gtk/gtk.h>
# include <stdlib.h>
//# include <windows.h>
# include <string.h>
# include <stdio.h>
# include <ctype.h>
# include <math.h>

GtkWidget	*geodis_national(GtkWidget *grid);
GtkWidget	*geodis_international(GtkWidget *grid);
int			zone(int dep, int arr, int mode);
double		tarif(int zoneMessagerie, int poids, int mode, int corse);
double		read_file(char *file, int area, int weight);
double		calcTarif(int poidsTranche, int zone);
int			calcPoids(int poidsReel);
int			calcZone(char **pays);
void		get_wei(void);
#endif
