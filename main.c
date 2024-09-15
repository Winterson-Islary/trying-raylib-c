#include <stdio.h>
#include "raylib.h"

int main()
{
	const int screenWidth = 800;
	const int screenHeight = 450;
	const int length = 550;
	const int height = 300;
	const int section = 6;
	InitWindow(screenWidth, screenHeight, "Test Window");
	Rectangle containerRec = {0.0f, 0.0f, (float)length / section, (float)height};
	int currentFrame = 0;
	int framesCounter = 0;
	int framesSpeed = 2;
	int counter = 1;
	char buffer[sizeof(int)];

	SetTargetFPS(60);

	while (!WindowShouldClose())
	{
		framesCounter++;
		if (framesCounter >= (60 / framesSpeed))
		{
			framesCounter = 0;
			counter++;
			currentFrame++;

			if (currentFrame > 5)
			{
				currentFrame = 0;
				counter = 1;
			}
			containerRec.x = (float)currentFrame * containerRec.width;
		}
		sprintf(buffer, "%d", counter);
		BeginDrawing();
		ClearBackground(RAYWHITE);
		DrawRectangleLines(15, 40, length, height, LIME);
		DrawRectangleLines(15 + (int)containerRec.x, 40 + (int)containerRec.y, (int)containerRec.width, (int)containerRec.height, RED);
		DrawText(buffer, (int)containerRec.width / 2 + (int)containerRec.x, (int)containerRec.height / 2 + (int)containerRec.y, 30, LIME);
		DrawText("TESTING", 190, 200, 20, LIGHTGRAY);
		EndDrawing();
	}
	CloseWindow();

	return 0;
}