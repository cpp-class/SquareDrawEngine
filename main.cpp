#include "raylib.h"
#include "square_draw_engine.h"

void put_text(const char* text, int y, int screen_width, int font_size, Color color)
{
    int tsize = MeasureText(text, font_size);
    int x = (screen_width - tsize)/2;

    DrawText(text, x, y, font_size, color);
}

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screen_width = 800;
    const int screen_height = 600;

    int cur_draw {1};
    int total_draw {9};

    InitWindow(screen_width, screen_height, "Draw Engine with Squares!");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {

    	if (IsKeyPressed(KEY_SPACE))
    	{
    		cur_draw++;
    		if (cur_draw>total_draw) {
    			cur_draw = 1;
    		}
    	}


        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            if (cur_draw == 1)
            {
            	sd_vertical_line(400, 100, 25, 5, 10, VIOLET);

                put_text("sd_vertical_line ( 400, 100, 25, 5, 10, VIOLET)", 30, screen_width, 25, BLACK);
            }

            if (cur_draw == 2)
            {
            	sd_horizontal_line(100, 200, 30, 4, 10, GREEN);

                put_text("sd_horizontal_line ( 100, 200, 30, 4, 10, GREEN)", 30, screen_width, 25, BLACK);
            }

            if (cur_draw == 3)
            {
                sd_rectangle(50, 100, 10, 1, 30, 18, RED);

                put_text("sd_rectangle ( 50, 50, 10, 1, 30, 18, RED)", 30, screen_width, 25, BLACK);
            }

            if (cur_draw == 4)
            {
                sd_frame(50, 100, 20, 5, 15, 4, BLUE);

                put_text("sd_frame ( 50, 100, 20, 5, 15, 4, BLUE)", 30, screen_width, 25, BLACK);
            }

            if (cur_draw == 5)
            {
            	sd_45deg_line(100, 100, 20, 2, 15, LIME);

                put_text("sd_45deg_line ( 100, 100, 20, 2, 15, LIME )", 30, screen_width, 25, BLACK);
            }

            if (cur_draw == 6)
            {
                sd_payramid(300, 100, 20, 5, 10, GREEN);

                put_text("sd_payramid ( 300, 100, 20, 5, 10, GREEN )", 30, screen_width, 25, BLACK);
            }

            if (cur_draw == 7)
            {
            	sd_cross(300, 100, 20, 2, 8, LIME);
                put_text("sd_cross ( 300, 100, 20, 2, 8, LIME )", 30, screen_width, 25, BLACK);

            	sd_cross(300, 350, 20, 2, 7, LIME);
                put_text("sd_cross ( 300, 300, 20, 2, 7, LIME )", 300, screen_width, 25, BLACK);

            }

            if (cur_draw == 8)
            {
                sd_diamond(300, 100, 20, 5, 7, BLUE);
                put_text("sd_diamond ( 300, 100, 20, 5, 7, BLUE )", 30, screen_width, 25, BLACK);

                sd_diamond(400, 400, 20, 5, 4, RED);
                put_text("sd_diamond ( 400, 300, 20, 5, 4, RED )", 350, screen_width, 25, BLACK);


            }

            if (cur_draw == 9)
            {
                sd_chess_board(100, 80, 30, 3, 10, 5, RED, BLUE);
                put_text("sd_chess_board ( 100, 80, 30, 3, 10, 5, RED, BLUE )", 30, screen_width, 25, BLACK);

                sd_chess_board(100, 350, 30, 3, 6, 4, GREEN, VIOLET);
                put_text("sd_chess_board ( 100, 300, 30, 3, 6, 4, GREEN, VIOLET )", 300, screen_width, 25, BLACK);

            }

            DrawText(TextFormat("[%d/%d] Press space ...", cur_draw, total_draw), 50 , screen_height - 60, 40, LIGHTGRAY);

            //DrawFPS(10, 10);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
