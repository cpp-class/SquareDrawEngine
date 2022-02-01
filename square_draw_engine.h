#ifndef SQUARE_DRAW_ENGINE_H_
#define SQUARE_DRAW_ENGINE_H_

#include "raylib.h"

void sd_horizontal_line(int x, int y, int size, int space, int num_sq, Color color);

void sd_vertical_line(int x, int y, int size, int space, int num_sq, Color color);

void sd_rectangle(int x, int y, int sq_size, int sq_space, int width, int height, Color color);

void sd_frame(int x, int y, int sq_size, int sq_space, int width, int height, Color color);

void sd_payramid(int x, int y, int sq_size, int sq_space, int height, Color color);
#endif /* SQUARE_DRAW_ENGINE_H_ */
