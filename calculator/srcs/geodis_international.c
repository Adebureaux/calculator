#include "main.h"

static GtkWidget	*window;
static GtkWidget	*grid;
static GtkWidget	*dim1[10];
static GtkWidget	*dim2[10];
static GtkWidget	*dim3[10];
static GtkWidget	*wei[10];

static int			i_col;
static int			totalwei;
static int			tp;

static GtkWidget	*country;
static GtkWidget	*col;
static GtkWidget	*display_area;
static GtkWidget	*display_price_ha;
static GtkWidget	*display_price;

void		get_wei_i(void)
{
	double		d_dim1[10];
	double		d_dim2[10];
	double		d_dim3[10];
	int			i_wei[10];
	double		vol;
	int			i;

	i = 0;
	totalwei = 0;
	while (i < i_col)
	{
		d_dim1[i] = atoi((char*)gtk_entry_get_text(GTK_ENTRY(dim1[i])));
		d_dim2[i] = atoi((char*)gtk_entry_get_text(GTK_ENTRY(dim2[i])));
		d_dim3[i] = atoi((char*)gtk_entry_get_text(GTK_ENTRY(dim3[i])));
		i_wei[i] = atoi((char*)gtk_entry_get_text(GTK_ENTRY(wei[i])));
		vol = (((d_dim1[i]/100.00)*(d_dim2[i]/100.00)*(d_dim3[i]/100.00))*166.00);
		totalwei += i_wei[i] < vol ? vol : i_wei[i];
		i++;
	}
	if (totalwei > 2000)
	{
		gtk_window_close(GTK_WINDOW(window));
		totalwei = -1;
		get_wei();
	}
	tp = calcPoids(totalwei);
	gtk_window_close(GTK_WINDOW(window));
}

void		get_wei(void)
{
	GtkWidget	*validate_button;
	int			i;
	char		label[10];

	gtk_init(NULL, NULL);
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window), "CALCUL DU VOLUME");
	gtk_window_set_default_size(GTK_WINDOW(window), 900, 300);
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
	g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

	grid = gtk_grid_new();
	gtk_grid_set_column_spacing((GtkGrid*)grid, 10);
	gtk_grid_set_row_spacing((GtkGrid*)grid, 20);
	gtk_container_add(GTK_CONTAINER(window), grid);

	gtk_grid_attach(GTK_GRID(grid), gtk_label_new("\t"), 0, 0, 1, 1);

	i = 0;
	while (i < i_col)
	{
		sprintf(label, "Colis %d", i + 1);
		gtk_grid_attach(GTK_GRID(grid), gtk_label_new(label), 1, ((i + 1) * 5), 1, 1);
		dim1[i] = gtk_entry_new();
		dim2[i] = gtk_entry_new();
		dim3[i] = gtk_entry_new();
		wei[i] = gtk_entry_new();

		gtk_entry_set_max_length(GTK_ENTRY(dim1[i]), 3);
		gtk_grid_attach(GTK_GRID(grid), gtk_label_new("\t\tLongueur"), 2, ((i + 1) * 5), 1, 1);
		gtk_grid_attach(GTK_GRID(grid), dim1[i], 2, ((i + 1) * 5), 1, 1);

		gtk_entry_set_max_length(GTK_ENTRY(dim2[i]), 3);
		gtk_grid_attach(GTK_GRID(grid), gtk_label_new("\t\tLargeur"), 3, ((i + 1) * 5), 1, 1);
		gtk_grid_attach(GTK_GRID(grid), dim2[i], 3, ((i + 1) * 5), 1, 1);

		gtk_entry_set_max_length(GTK_ENTRY(dim3[i]), 3);
		gtk_grid_attach(GTK_GRID(grid), gtk_label_new("\t\tHauteur"), 4, ((i + 1) * 5), 1, 1);
		gtk_grid_attach(GTK_GRID(grid), dim3[i], 4, ((i + 1) * 5), 1, 1);

		gtk_entry_set_max_length(GTK_ENTRY(wei[i]), 4);
		gtk_grid_attach(GTK_GRID(grid), gtk_label_new("\t\t\tPoids"), 5, ((i + 1) * 5), 1, 1);
		gtk_grid_attach(GTK_GRID(grid), wei[i], 5, ((i + 1) * 5), 1, 1);
		i++;
	}

	validate_button = gtk_button_new_with_label("Valider");
	gtk_grid_attach(GTK_GRID(grid), validate_button, 3, ((i_col + 1) * 5), 2, 1);
	g_signal_connect(validate_button, "clicked", G_CALLBACK(get_wei_i), NULL);

	gtk_grid_attach(GTK_GRID(grid), gtk_label_new("\t"), 0, ((i_col + 2) * 5), 1, 1);

	gtk_widget_show_all(window);
	gtk_main();
}

void		get_price_i(void)
{
	int			i;
	int			i_area;
	char		**cou;
	char		buffer_area[20];
	char		buffer_price_ha[40];
	char		buffer_price[80];
	double		price;
	double		divisor[40] = { 0.30, 0.40, 0.45, 0.50, 0.51, 0.52, 0.53, 0.54, 0.55, 0.56, 0.57, 0.58, 0.59, 0.60, 0.61, 0.62, 0.63, 0.64, 0.65, 0.66, 0.67, 0.68, 0.69, 0.70, 0.71, 0.72, 0.73, 0.735, 0.740, 0.745, 0.750, 0.755, 0.760, 0.765, 0.770, 0.775, 0.780, 0.785, 0.790, 0.795 };

	i = 0;
	cou = malloc(sizeof(char*));
	cou[0] = calloc(20, 0);
	cou[0] = (char*)gtk_entry_get_text(GTK_ENTRY(country));
	while (cou[0][i])
	{
		cou[0][i] = toupper(cou[0][i]);
		i++;
	}
	i_area = calcZone(cou);
	i_col = atoi((char*)gtk_entry_get_text(GTK_ENTRY(col)));
	price = 0;
	if (i_area == -1 || i_col < 1 || i_col > 10)
	{
		snprintf(buffer_area, sizeof(buffer_area), "Erreur\nSaisie");
		snprintf(buffer_price_ha, sizeof(buffer_price_ha), "Cout d'achat :\n    %.2lf €", price);
		snprintf(buffer_price, sizeof(buffer_price), "Prix de vente HT   : %.2lf €\nPrix de vente TTC : %.2lf €", price, (price * 1.2));
		gtk_label_set_text(GTK_LABEL(display_area), buffer_area);
		gtk_label_set_text(GTK_LABEL(display_price_ha), buffer_price_ha);
		gtk_label_set_text(GTK_LABEL(display_price), buffer_price);
		return ;
	}
	get_wei();
	if (tp == -1)
	{
		snprintf(buffer_area, sizeof(buffer_area), "Erreur\nSaisie");
		snprintf(buffer_price_ha, sizeof(buffer_price_ha), "Cout d'achat :\n    %.2lf €", price);
		snprintf(buffer_price, sizeof(buffer_price), "Prix de vente HT   : %.2lf €\nPrix de vente TTC : %.2lf €", price, (price * 1.2));
		gtk_label_set_text(GTK_LABEL(display_area), buffer_area);
		gtk_label_set_text(GTK_LABEL(display_price_ha), buffer_price_ha);
		gtk_label_set_text(GTK_LABEL(display_price), buffer_price);
		return ;
	}
	price = calcTarif(tp, i_area);

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

	gtk_grid_attach(GTK_GRID(grid), gtk_label_new("\n\nGeodis International"), 3, 6, 1, 1);

	gtk_grid_attach(GTK_GRID(grid), gtk_label_new("\t"), 0, 10, 1, 1);

	country = gtk_entry_new();
	gtk_entry_set_max_length(GTK_ENTRY(country), 19);
	gtk_grid_attach(GTK_GRID(grid), gtk_label_new("\t\t\t\t\t\t\t\tPays de destination"), 1, 10, 2, 1);
	gtk_grid_attach(GTK_GRID(grid), country, 1, 10, 2, 1);

	col = gtk_entry_new();
	gtk_entry_set_max_length(GTK_ENTRY(col), 2);
	gtk_grid_attach(GTK_GRID(grid), gtk_label_new("\t\tNombre de colis"), 3, 10, 1, 1);
	gtk_grid_attach(GTK_GRID(grid), col, 3, 10, 1, 1);

	calculate_button = gtk_button_new_with_label("Calculer");
	g_signal_connect(calculate_button, "clicked", G_CALLBACK(get_price_i), NULL);
	gtk_grid_attach(GTK_GRID(grid), calculate_button, 4, 10, 2, 1);

	display_area = gtk_label_new("Pays\n");
	gtk_grid_attach(GTK_GRID(grid), display_area, 6, 10, 1, 1);

	display_price_ha = gtk_label_new("Cout d'achat :\n    0.00 €");
	gtk_grid_attach(GTK_GRID(grid), display_price_ha, 7, 10, 1, 1);
	display_price = gtk_label_new("Prix de vente HT   : 0.00 €\nPrix de vente TTC : 0.00 €");
	gtk_grid_attach(GTK_GRID(grid), display_price, 8, 10, 1, 1);

	return (grid);
}
