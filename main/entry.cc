/*******************************************************************************************
*
*   raylib [core] example - 2d camera mouse zoom
*
*   Example originally created with raylib 4.2, last time updated with raylib 4.2
*
*   Example licensed under an unmodified zlib/libpng license, which is an OSI-certified,
*   BSD-like license that allows static linking with closed source software
*
*   Copyright (c) 2022 Jeffery Myers (@JeffM2501)
*
********************************************************************************************/

#include "raylib.h"
#include "emscripten.h"

#include "rlgl.h"
#include "raymath.h"

#include <stdio.h>

extern "C" {

void set_size(int wid, int hei) {
 SetWindowSize(wid, hei);    
}

}

void GetCanvasSize(int &width, int &height)
{
    width = (int)EM_ASM_DOUBLE ({
        return Module.canvas.parentElement.getBoundingClientRect().width ;
    } , NULL ) ;

    height = (int)EM_ASM_DOUBLE ({
        return Module.canvas.parentElement.getBoundingClientRect().height ;
    } , NULL ) ; 
}



//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------

int main(int argc, char** argv) 
{
    char buf [240];


    // Initialization
    //--------------------------------------------------------------------------------------
    int screenWidth;
    int screenHeight;

    GetCanvasSize(screenWidth, screenHeight);

    char* ptr = buf;

    for(int i = 0; i < argc; i++)
    {
        ptr += sprintf (ptr, "Arg: %d is %s\n", i, argv[i]);
    }

    //sprintf (buf, "Size is: %d x %d", screenWidth, screenHeight);

    InitWindow(screenWidth, screenHeight, "raylib [core] example - 2d camera mouse zoom");

    Camera2D camera = { {0} };
    camera.zoom = 1.0f;

    SetTargetFPS(60);                   // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())        // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // Translate based on mouse right click
        if (IsMouseButtonDown(MOUSE_BUTTON_RIGHT))
        {
            Vector2 delta = GetMouseDelta();
            delta = Vector2Scale(delta, -1.0f/camera.zoom);

            camera.target = Vector2Add(camera.target, delta);
        }

        // Zoom based on mouse wheel
        float wheel = GetMouseWheelMove();
        if (wheel != 0)
        {
            // Get the world point that is under the mouse
            Vector2 mouseWorldPos = GetScreenToWorld2D(GetMousePosition(), camera);
            
            // Set the offset to where the mouse is
            camera.offset = GetMousePosition();

            // Set the target to match, so that the camera maps the world space point 
            // under the cursor to the screen space point under the cursor at any zoom
            camera.target = mouseWorldPos;

            // Zoom increment
            const float zoomIncrement = 0.125f;

            camera.zoom += (wheel*zoomIncrement);
            if (camera.zoom < zoomIncrement) camera.zoom = zoomIncrement;
        }

        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
            ClearBackground(BLACK);

            BeginMode2D(camera);

                // Draw the 3d grid, rotated 90 degrees and centered around 0,0 
                // just so we have something in the XY plane
                rlPushMatrix();
                    rlTranslatef(0, 25*50, 0);
                    rlRotatef(90, 1, 0, 0);
                   // DrawGrid(100, 50);
                rlPopMatrix();

                // Draw a reference circle
               // DrawCircle(100, 100, 50, YELLOW);
                
            EndMode2D();

            DrawText(buf, 40, 10, 20, WHITE);
        
        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------
    return 0;
}