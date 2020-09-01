#ifndef MAIN_H
# define MAIN_H
# include <gtk/gtk.h>
# include <stdlib.h>
# include <stdio.h>

GtkWidget	*geodis_national(GtkWidget *window);
int			zone(int dep, int arr, int mode);
double		tarif(int zoneMessagerie, int poids, int mode, int corse);
#endif
