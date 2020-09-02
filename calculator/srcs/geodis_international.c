#include "main.h"

static GtkWidget	*country;
static GtkWidget	*vol;
static GtkWidget	*weight;
static GtkWidget	*mode;
static GtkWidget	*display_area;
static GtkWidget	*display_price_ha;
static GtkWidget	*display_price;

static GtkWidget	*dep;

void		get_price_i()
{
	int			i;
	int			i_wei;
	int			i_area;
	int			i_tp;
	char		**cou;
	char		buffer_area[20];
	char		buffer_price_ha[40];
	char		buffer_price[80];
	double		price;
	double		i_vol;
	double		divisor[40] = { 0.30, 0.40, 0.45, 0.50, 0.51, 0.52, 0.53, 0.54, 0.55, 0.56, 0.57, 0.58, 0.59, 0.60, 0.61, 0.62, 0.63, 0.64, 0.65, 0.66, 0.67, 0.68, 0.69, 0.70, 0.71, 0.72, 0.73, 0.735, 0.740, 0.745, 0.750, 0.755, 0.760, 0.765, 0.770, 0.775, 0.780, 0.785, 0.790, 0.795 };

	i = 0;
	cou = malloc(sizeof(char*));
	cou[0] = calloc(13, 0);
	cou[0] = (char*)gtk_entry_get_text(GTK_ENTRY(country));
	while (cou[0][i])
	{
		cou[0][i] = toupper(cou[0][i]);
		i++;
	}
	i_area = calcZone(cou);
	i_vol = atof((char*)gtk_entry_get_text(GTK_ENTRY(vol)));
	i_wei = atoi((char*)gtk_entry_get_text(GTK_ENTRY(weight)));
	if (i_area == -1 || i_wei > 2500 || i_wei < 0 || i_vol < 0 || i_vol > 10.00)
	{
		snprintf(buffer_area, sizeof(buffer_area), "Erreur\nSaisie");
		gtk_label_set_text(GTK_LABEL(display_area), buffer_area);
		return ;
	}
	i_tp = calcPoids(i_wei, i_vol);
	price = calcTarif(i_tp, i_area);

	snprintf(buffer_area, sizeof(buffer_area), "Pays\n %.3s", cou[0]);
	gtk_label_set_text(GTK_LABEL(display_area), buffer_area);

	snprintf(buffer_price_ha, sizeof(buffer_price_ha), "Cout d'achat :\n    %.2lf €", price);
	gtk_label_set_text(GTK_LABEL(display_price_ha), buffer_price_ha);

	if (price < 500)
		price /= divisor[(int)(price / 12.5)];
	else
		price /= 0.8;
	snprintf(buffer_price, sizeof(buffer_price), "Prix de vente HT   : %.2lf €\nPrix de vente TTC : %.2lf €", price, (price * 1.2));
	gtk_label_set_text(GTK_LABEL(display_price), buffer_price);
}

GtkWidget	*geodis_international(GtkWidget *grid)
{
	GtkWidget	*calculate_button;

	gtk_grid_attach(GTK_GRID(grid), gtk_label_new("\n\nGeodis International"), 2, 6, 1, 1);

	country = gtk_entry_new();
	gtk_entry_set_max_length((GtkEntry*)country, 12);
	gtk_grid_attach(GTK_GRID(grid), gtk_label_new("\t\t\tDestination"), 0, 10, 1, 1);
	gtk_grid_attach(GTK_GRID(grid), country, 0, 10, 1, 1);

	vol = gtk_entry_new();
	gtk_entry_set_max_length((GtkEntry*)vol, 4);
	gtk_grid_attach(GTK_GRID(grid), gtk_label_new("\t\t\tVolume (m3)"), 1, 10, 1, 1);
	gtk_grid_attach(GTK_GRID(grid), vol, 1, 10, 1, 1);

	weight = gtk_entry_new();
	gtk_entry_set_max_length((GtkEntry*)weight, 4);
	gtk_grid_attach(GTK_GRID(grid), gtk_label_new("\t\t\tPoids (KG)"), 2, 10, 1, 1);
	gtk_grid_attach(GTK_GRID(grid), weight, 2, 10, 1, 1);


	calculate_button = gtk_button_new_with_label("Calculer");
	g_signal_connect(calculate_button, "clicked", G_CALLBACK(get_price_i), NULL);
	gtk_grid_attach(GTK_GRID(grid), calculate_button, 3, 10, 2, 1);

	display_area = gtk_label_new("Pays\n");
	gtk_grid_attach(GTK_GRID(grid), display_area, 5, 10, 1, 1);
	display_price_ha = gtk_label_new("Cout d'achat :\n    0.00 €");
	gtk_grid_attach(GTK_GRID(grid), display_price_ha, 6, 10, 1, 1);
	display_price = gtk_label_new("Prix de vente HT   : 0.00 €\nPrix de vente TTC : 0.00 €");
	gtk_grid_attach(GTK_GRID(grid), display_price, 7, 10, 1, 1);

	return (grid);
}
