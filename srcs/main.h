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

double		get_pos(char *file, int x, int y);
GtkWidget	*national(GtkWidget *grid);
int			national_area(int dep, int arr, int mode);
double		national_price(int area, int weight, int mode, int corse);
GtkWidget	*international(GtkWidget *grid);
int			international_area(char **country);
int			international_weigth_range(int real_weight);
double		international_price(int range_weight, int area);
#endif
