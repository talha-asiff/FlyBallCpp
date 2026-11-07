#include <iostream>
#include <raylib.h>
using namespace std;

int main()
{
    bool grabbed = false;
    InitWindow(500, 500, "Prac window");
    SetTargetFPS(60);
    
    int x = 250, y = 250;
    while(WindowShouldClose() == false){
        BeginDrawing();
        ClearBackground(BLUE);
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
        
        
        EndDrawing();
    }
    CloseWindow();
    return 0;
}