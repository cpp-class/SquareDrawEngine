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

void sd_45deg_line(int x, int y, int sq_size, int sq_space, int length, Color color)
{
	int cnt {0};

	const int step {sq_size + sq_space};

	while (cnt != length)
	{
	    DrawRectangle(x, y, sq_size, sq_size, color);

	    x += step;
	    y += step;
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

void sd_cross(int x, int y, int sq_size, int sq_space, int length, Color color)
{
	int cnt {0};

	const int step {sq_size + sq_space};

	int x2 {x + step * (length-1)};

	while (cnt != length)
	{
	    DrawRectangle(x , y, sq_size, sq_size, color);
	    DrawRectangle(x2, y, sq_size, sq_size, color);

	    x += step;
	    x2 -= step;

	    y += step;
		cnt = cnt + 1;
	}
}


void sd_payramid(int x, int y, int sq_size, int sq_space, int height, Color color)
{
	int cnt {0};
	int len {1};
	int step {sq_size + sq_space};

	while (cnt != height)
	{
		sd_horizontal_line(x, y, sq_size, sq_space, len, color);

		y += step;
		len += 2;
		x -= step;

		cnt += 1;
	}
}

void sd_diamond(int x, int y, int sq_size, int sq_space, int height, Color color)
{
	int cnt {1};

	int num_sides {height/2};

	int step {sq_size + sq_space};

	sd_vertical_line(x, y, sq_size, sq_space, height, color);

	while (cnt<=num_sides)
	{
		height -= 2;
		sd_vertical_line(x - cnt*step, y + cnt*step, sq_size, sq_space, height, color);
		sd_vertical_line(x + cnt*step, y + cnt*step, sq_size, sq_space, height, color);

		cnt = cnt + 1;
	}

}

void sd_chess_board(int x, int y, int sq_size, int sq_space, int width, int height, Color color1, Color color2)
{
	int cnt {0};
	int step {sq_size + sq_space};
	int d_space { sq_space*2 + sq_size};

	int c1_start {0};
	int c2_start {1};

	int c2_height {height/2};
	int c1_height {height - c2_height};

	while (cnt<width)
	{
		sd_vertical_line(x, y + (step*c1_start) , sq_size, d_space, c1_height, color1);
		sd_vertical_line(x, y + (step*c2_start) , sq_size, d_space, c2_height, color2);

		int temp;

		temp = c1_start;
		c1_start = c2_start;
		c2_start = temp;

		temp = c1_height;
		c1_height = c2_height;
		c2_height = temp;

		x += step;

		cnt += 1;
	}
}

