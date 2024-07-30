#include "../include/cub3d.h"

int main()
{
	//Allocation for main structure
	t_window *ups;
	ups = malloc(sizeof(t_window) * 1);
	if (!ups)
	{
		free(ups);
		printf("Failed to allocate any memory\n");
	}
	//Managing the window
	manage_window(ups);
	// Parsing the map
}