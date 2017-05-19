#include <stdio.h>
#include <3ds.h>
#include <sf2d.h>
#include <sfil.h>

extern const struct {
	unsigned int width;
	unsigned int height;
	unsigned int bytes_per_pixel;
	unsigned char pixel_data[];
} mouse;

extern const struct{
	unsigned int width;
	unsigned int height;
	unsigned int bytes_per_pixel;
	unsigned char pixel_data[];
} bg;