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

    int cur_draw {0};

    InitWindow(screen_width, screen_height, "Draw Engine with Squares!");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {

    	if (IsKeyPressed(KEY_SPACE))
    	{
    		cur_draw++;
    		if (cur_draw>4) {
    			cur_draw = 0;
    		}
    	}


        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            if (cur_draw == 0)
            {
            	sd_vertical_line(400, 100, 25, 5, 10, VIOLET);

                put_text("sd_vertical_line(400, 100, 25, 5, 10, VIOLET)", 30, screen_width, 25, BLACK);
            }

            if (cur_draw == 1)
            {
            	sd_horizontal_line(100, 200, 30, 4, 10, GREEN);

                put_text("sd_horizontal_line(100, 200, 30, 4, 10, GREEN)", 30, screen_width, 25, BLACK);
            }

            if (cur_draw == 2)
            {
                sd_rectangle(50, 100, 10, 1, 30, 18, RED);

                put_text("sd_rectangle (50, 50, 10, 1, 30, 18, RED)", 30, screen_width, 25, BLACK);
            }

            if (cur_draw == 3)
            {
                sd_frame(50, 100, 20, 5, 15, 4, BLUE);

                put_text("sd_frame (50, 100, 20, 5, 15, 4, BLUE)", 30, screen_width, 25, BLACK);
            }

            if (cur_draw == 4)
            {
                sd_payramid(300, 100, 20, 5, 10, GREEN);

                put_text("sd_payramid(300, 100, 20, 5, 10, GREEN)", 30, screen_width, 25, BLACK);
            }

            DrawText("Press space ...", 50 , screen_height - 60, 40, LIGHTGRAY);

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
