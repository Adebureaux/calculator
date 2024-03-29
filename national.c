#include "main.h"

static GtkWidget	*dep;
static GtkWidget	*arr;
static GtkWidget	*weight;
static GtkWidget	*display_area;
static GtkWidget	*display_price_ha;
static GtkWidget	*display_price;
static GtkWidget	*express_button;
static t_var		*g_var;

void		get_price(void)
{
	int			i_dep;
	int			i_arr;
	int			i_wei;
	int			i_area;
	gboolean	corse;
	gboolean	express;
	char		buffer_area[20];
	char		buffer_price_ha[40];
	char		buffer_price[80];
	double		price;

	i_dep = atoi((char*)gtk_entry_get_text(GTK_ENTRY(dep)));
	i_arr = atoi((char*)gtk_entry_get_text(GTK_ENTRY(arr)));
	i_wei = atoi((char*)gtk_entry_get_text(GTK_ENTRY(weight)));
	express = gtk_toggle_button_get_active((GtkToggleButton*)express_button);
	price = 0;
	if (i_dep < 1 || i_dep > 95 || i_arr < 1 || i_arr > 95 || i_wei < 0)
	{
		snprintf(buffer_area, sizeof(buffer_area), "Erreur\nSaisie");
		snprintf(buffer_price_ha, sizeof(buffer_price_ha), "Cout d'achat :\n    %.2lf €", price);
		snprintf(buffer_price, sizeof(buffer_price), "Prix de vente HT   : %.2lf €\nPrix de vente TTC : %.2lf €", price, (price * 1.2));
		gtk_label_set_text(GTK_LABEL(display_area), buffer_area);
		gtk_label_set_text(GTK_LABEL(display_price_ha), buffer_price_ha);
		gtk_label_set_text(GTK_LABEL(display_price), buffer_price);
		return ;
	}

	i_area = national_area(i_dep, i_arr, express);
	snprintf(buffer_area, sizeof(buffer_area), "Zone\n    %d", i_area);
	gtk_label_set_text(GTK_LABEL(display_area), buffer_area);

	corse = i_dep == 20 || i_arr == 20 ? 1 : 0;
	price = national_price(i_area, i_wei, express, corse, g_var);
	snprintf(buffer_price_ha, sizeof(buffer_price_ha), "Cout d'achat :\n    %.2lf €", price);
	gtk_label_set_text(GTK_LABEL(display_price_ha), buffer_price_ha);

	if (price < 500)
		price /= g_var->divisor[(int)(price / 12.5)];
	else
		price /= g_var->divisor[40];
	snprintf(buffer_price, sizeof(buffer_price), "Prix de vente HT   : %.2lf €\nPrix de vente TTC : %.2lf €", price, (price * 1.2));
	gtk_label_set_text(GTK_LABEL(display_price), buffer_price);
}

GtkWidget	*national(GtkWidget *grid, t_var *var)
{
	GtkWidget	*calculate_button;

	g_var = var;
	gtk_grid_attach(GTK_GRID(grid), gtk_label_new("\n\nGeodis National"), 3, 0, 1, 1);

	dep = gtk_entry_new();
	gtk_entry_set_max_length(GTK_ENTRY(dep), 2);
	gtk_grid_attach(GTK_GRID(grid), gtk_label_new("\tCode postal de depart"), 1, 5, 1, 1);
	gtk_grid_attach(GTK_GRID(grid), dep, 1, 5, 1, 1);

	gtk_grid_attach(GTK_GRID(grid), gtk_label_new("\t"), 0, 5, 1, 1);

	arr = gtk_entry_new();
	gtk_entry_set_max_length(GTK_ENTRY(arr), 2);
	gtk_grid_attach(GTK_GRID(grid), gtk_label_new("\tCode postal d'arrivée"), 2, 5, 1, 1);
	gtk_grid_attach(GTK_GRID(grid), arr, 2, 5, 1, 1);

	weight = gtk_entry_new();
	gtk_entry_set_max_length(GTK_ENTRY(weight), 3);
	gtk_grid_attach(GTK_GRID(grid), gtk_label_new("\t\t\tPoids (KG)"), 3, 5, 1, 1);
	gtk_grid_attach(GTK_GRID(grid), weight, 3, 5, 1, 1);

	express_button = gtk_toggle_button_new_with_label("EXP");
	gtk_grid_attach(GTK_GRID(grid), express_button, 4, 5, 1, 1);

	calculate_button = gtk_button_new_with_label("Calculer");
	g_signal_connect(calculate_button, "clicked", G_CALLBACK(get_price), NULL);
	gtk_grid_attach(GTK_GRID(grid), calculate_button, 5, 5, 1, 1);

	display_area = gtk_label_new("Zone\n");
	gtk_grid_attach(GTK_GRID(grid), display_area, 6, 5, 1, 1);
	display_price_ha = gtk_label_new("Cout d'achat :\n    0.00 €");
	gtk_grid_attach(GTK_GRID(grid), display_price_ha, 7, 5, 1, 1);
	display_price = gtk_label_new("Prix de vente HT   : 0.00 €\nPrix de vente TTC : 0.00 €");
	gtk_grid_attach(GTK_GRID(grid), display_price, 8, 5, 1, 1);

	return (grid);
}
