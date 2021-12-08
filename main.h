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

typedef struct s_var
{
		double	divisor[41];
		double	tgo;
		double	base_national;
		double	base_national_express;
		double	base_international;
}			t_var;

double		get_pos(char *file, int x, int y);
void		get_var(t_var *var);

GtkWidget	*national(GtkWidget *grid, t_var *var);
int			national_area(int dep, int arr, int mode);
int			national_weigth_range(int weight, int mode);
double		national_price(int area, int weight, int mode, int corse, t_var *var);

GtkWidget	*international(GtkWidget *grid, t_var *var);
int			international_area(char **country);
int			international_weigth_range(int real_weight);
double		international_price(int range_weight, int area, t_var *var);
#endif
