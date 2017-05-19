#include <stdio.h>
#include <3ds.h>
#include <sf2d.h>
#include <sfil.h>
//#include <hbkb.h>

#include "images.h"



int main(int argc, char **argv)
{
	int x = 80;
	int y = 133;
	//Initialize the sf2d lib
	sf2d_init();
	//Set the background color
	sf2d_set_clear_color(RGBA8(0xFF, 0xFF, 0xFF, 0xFF));
	consoleInit(GFX_TOP, NULL);
	printf("Loading texture(s)...");
	sf2d_texture *bg_image = sf2d_create_texture_mem_RGBA8(bg.pixel_data, bg.width, bg.height, TEXFMT_RGBA8, SF2D_PLACE_RAM);
	sf2d_texture *tex_image = sf2d_create_texture_mem_RGBA8(mouse.pixel_data, mouse.width, mouse.height, TEXFMT_RGBA8, SF2D_PLACE_RAM);
	printf("Starting...");

	// Main loop
	while (aptMainLoop())
	{
		//Scan all the inputs. This should be done once for each frame
		hidScanInput();

		

		//Determines is key is being held
		u32 kPressed = hidKeysHeld();
		u32 kDown = hidKeysDown();
		u32 kUp = hidKeysUp();

		sf2d_start_frame(GFX_TOP, GFX_LEFT);
		sf2d_draw_texture(bg_image, 0, 0);
		sf2d_draw_texture(tex_image, y, x);
		sf2d_end_frame();

		/*sf2d_start_frame(GFX_BOTTOM);
		sf2d_draw_texture(bg_image, 0, 0);
		sf2d_end_frame();*/
		
		//If they are holding a D-pad key, change the mouse position accordingly
		if (kPressed & KEY_DOWN)
			x = x + 1;
		if (kPressed & KEY_UP)
			x = x - 1;
		if (kPressed & KEY_LEFT)
			y = y - 1;
		if (kPressed & KEY_RIGHT)
			y = y + 1;
		if (y > 266)
			y = 266;
		if (y < 0)
			y = 0;
		if (x > 159)
			x = 159;
		if (x < 0)
			x = 0;

		/*if (kDown & KEY_SELECT) {
			HBKB_CallKeyboard();
		}
		if (kUp & KEY_SELECT) {
			HBKB_Clean();
		}*/

		//hidKeysDown returns information about which buttons have been just pressed (and they weren't in the previous frame)
		//hidKeysHeld returns information about which buttons are currently pressed (regardless if they were pressed or not pressed in the previous frame)
		//hidKeysUp returns information about which buttons are not pressed but were pressed in the previous frame


		if (kDown & KEY_START) break; // break in order to return to hbmenu
		
		//Swap the buffers
		sf2d_swapbuffers();
	}
	sf2d_free_texture(bg_image);
	sf2d_free_texture(tex_image);
	sf2d_fini();
	return 0;
}