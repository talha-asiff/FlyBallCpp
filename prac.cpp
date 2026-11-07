#include <iostream>
#include <raylib.h>
#include <cstdlib>
using namespace std;

int main()
{
    bool grabbed = false;
    InitWindow(500, 500, "Prac window");
    SetTargetFPS(60);
    int counterSeed = 0;
    int x = 250, y = 250;
    int oX = 500, oY = 340;
    int obsGen = 0;
    bool generating = false;
    bool moving = false;
    while(WindowShouldClose() == false){
        BeginDrawing();
        ClearBackground(BLUE);
        DrawRectangle(0, 460, 500, 50, GRAY);
        if(!moving && generating && (counterSeed == obsGen)){
            moving = true;
        }
        if(moving){
            DrawRectangle(oX, oY, 40, 200, BLACK);
            oX -= 10;
            if(oX <= 0){
                oX = 500;
                moving = false;
            }
        }
        DrawCircle(x,y, 15, RED);
        if(IsKeyDown(KEY_W) && !(y<0)){y-=10; grabbed = true;}
        if(IsKeyDown(KEY_S) && !(y>500)){y+=10; grabbed = true;}
        if(IsKeyDown(KEY_A) && !(x<0)){x-=10; grabbed = true;}
        if(IsKeyDown(KEY_D) && !(x>500)){x+=10; grabbed = true;}
        if(IsKeyReleased(KEY_W) || IsKeyReleased(KEY_S) || IsKeyReleased(KEY_A) || IsKeyReleased(KEY_D)){
            grabbed = false;
        }
        if(!grabbed && (y<=450 && y >= 0)){
            y+=10;
        }
        
        counterSeed++;
        if(counterSeed == 10){
            counterSeed = 0;
            obsGen = rand() % 10;
            generating = true;
        }
        EndDrawing();
    }
    CloseWindow();
    return 0;
}