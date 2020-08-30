#include <raylib.h> // Code ported from Lua, no OOP. 
int main() {
	const int WindowWidth = 1280;
	const int WindowHeight = 720;
	InitWindow(WindowWidth, WindowHeight, "PONG"); // Window init with title "PONG".
	SetTargetFPS(60);
	// Set all game variables.
	// Player paddle vars.
	int plPosX = 10;
	int plPosY = GetScreenHeight() / 2 - 75;
	int plSizX = 10;
	int plSizY = 150;
	// Enemy paddle vars.
	int enPosX = 1260;
	int enPosY = GetScreenHeight() / 2 - 75;
	int enSizX = 10;
	int enSizY = 150;
	// Ball vars.
	int baPosX = 22;
	int baPosY = GetScreenHeight() / 2 - 4;
	int baSizX = 8;
	int baSizY = 8;
	double baVelX = 2.5f;
	double baVelY = GetRandomValue(-2.5f, 2.5f);
	// Main game loop.
	while (!WindowShouldClose()) {
		// Player paddle movement.
		if ((IsKeyDown(KEY_UP)) && (plPosY > 5)) plPosY -= 2.5f;
		else if ((IsKeyDown(KEY_DOWN)) && (plPosY + 150 < 715)) plPosY += 2.5f;
		// Enemy paddle movement.
		if (baPosX > WindowWidth / 2) {
			if (enPosY + enSizY / 2 - 5 > baPosY) enPosY -= 2.5f;
			else if (enPosY + enSizY / 2 + 5 < baPosY) enPosY += 2.5f; }
		// Enemy paddle limiter.
		if (enPosY < 5) enPosY = 5;
		if (enPosY + 150 > 715) enPosY = 715 - enSizY;
		// Ball movement.
		baPosX += baVelX;
		baPosY += baVelY;
		// Paddle - Ball collision.
		if ((baPosX <= plPosX + 12) && (baPosY >= plPosY) && (baPosY <= plPosY + plSizY)) baVelX = -baVelX + 0.5f;
		if ((baPosX >= enPosX - 12) && (baPosY >= enPosY) && (baPosY <= enPosY + enSizY)) {
 			baVelX = -baVelX;
			double rnd1 = GetRandomValue(-2.5f, 2.5f);
			baVelY = rnd1; }
		// Edge - Ball collsion.
		if (baPosY < 5) baVelY = -baVelY;
		if (baPosY + 8 > 715) baVelY = -baVelY;
		// Game over.
		if (baPosX < 10) CloseWindow();
		if (baPosX > 1270) CloseWindow();
		// Draw to screen.
		BeginDrawing();
		ClearBackground(BLACK);
		// Player paddle
		DrawRectangle(plPosX, plPosY, plSizX, plSizY, RAYWHITE);
		// Enemy paddle.
		DrawRectangle(enPosX, enPosY, enSizX, enSizY, RAYWHITE);
		// Ball.
		DrawRectangle(baPosX, baPosY, baSizX, baSizY, RAYWHITE);
		EndDrawing();
	}
}
