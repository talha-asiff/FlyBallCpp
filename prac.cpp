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
    bool lost = false;
    while(WindowShouldClose() == false){
        BeginDrawing();
        if(!lost){
        ClearBackground(BLUE);
        // if((x <= oX) && (x >= oX+39) && (y >= oY) && (y <= oY+200)){
        //     lost = true;
        // }
        Rectangle obsRect = { (float)oX, (float)oY, 40, 200 };
        Vector2 playerPos = { (float)x, (float)y };

        if (CheckCollisionCircleRec(playerPos, 15.0f, obsRect)) {
            lost = true;
        }
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
        DrawRectangle(0, 460, 500, 50, GRAY);
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
        } else {
            ClearBackground(RED);
            DrawText("GAME OVER", 190, 230, 25, YELLOW);
            DrawText("PRESS R TO RESTART", 140, 270, 20, WHITE);
            if(IsKeyDown(KEY_R)){
                lost = false;
                counterSeed = 0;
                x = 250, y = 250;
                oX = 500, oY = 340;
                obsGen = 0;
                generating = false;
                moving = false;
                lost = false;
            }
        }
        EndDrawing();
    }
    CloseWindow();
    return 0;
}