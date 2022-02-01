#include "square_draw_engine.h"

void sd_horizontal_line(int x, int y, int size, int space, int num_sq, Color color)
{

	int cnt {0};

	while (cnt != num_sq)
	{
	    DrawRectangle(x, y, size, size, color);

	    x += size + space;
		cnt = cnt + 1;
	}

}

void sd_vertical_line(int x, int y, int size, int space, int num_sq, Color color)
{
	int cnt {0};

	while (cnt != num_sq)
	{
	    DrawRectangle(x, y, size, size, color);

	    y += size + space;
		cnt = cnt + 1;
	}
}

void sd_rectangle(int x, int y, int sq_size, int sq_space, int width, int height, Color color)
{
	int cnt {0};

	while (cnt != height) {
		sd_horizontal_line(x, y , sq_size, sq_space, width, color);
		y = y + sq_size + sq_space;
		cnt = cnt + 1;
	}
}

void sd_frame(int x, int y, int sq_size, int sq_space, int width, int height, Color color)
{
	int step {sq_size + sq_space};

	sd_horizontal_line(x, y, sq_size, sq_space, width, color);
	sd_horizontal_line(x, y + (height-1)*step, sq_size, sq_space, width, color);

	sd_vertical_line(x, y, sq_size, sq_space, height, color);
	sd_vertical_line(x + (width-1)*step, y, sq_size, sq_space, height, color);
}


void sd_payramid(int x, int y, int sq_size, int sq_space, int height, Color color)
{

}

