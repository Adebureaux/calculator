#include "main.h"

int	main(int argc, char **argv)
{
	GtkWidget	*window;
	GtkWidget	*grid;

	//HWND hWnd = GetConsoleWindow();
	//ShowWindow(hWnd, SW_HIDE);

	gtk_init(&argc, &argv);
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title (GTK_WINDOW (window), "CALCULATEUR DE PRIX");
	gtk_window_set_default_size (GTK_WINDOW (window), 1200, 300);
	gtk_window_set_position(GTK_WINDOW (window), GTK_WIN_POS_CENTER);
	g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

	grid = gtk_grid_new();
	gtk_grid_set_column_spacing((GtkGrid*)grid, 10);
	gtk_grid_set_row_spacing((GtkGrid*)grid, 20);
	gtk_container_add(GTK_CONTAINER(window), grid);
	grid = geodis_national(grid);
	grid = geodis_international(grid);
	gtk_widget_show_all(window);
	gtk_main();
	return (0);
}
