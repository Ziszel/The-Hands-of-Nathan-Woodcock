#include "parallax.hpp"
#include "player.hpp"
#include "Utility/calMath.hpp"
#include "serialisation.hpp"
#include <raylib-cpp.hpp>
#include <array>
#include <iostream>

using namespace playerNs;

int main()
{

	// Initialization
	int screenWidth = 640;
	int screenHeight = 480;
	float fps = 60.0f;
	float deltaTime = 0.0f;

	raylib::Color textColor(LIGHTGRAY);
	raylib::Window w(screenWidth, screenHeight, "C++ Parallax Scrolling Test");

	SetTargetFPS(fps);

	// Load Resources
	Texture2D playerTex = LoadTexture("resources/player.png");
	Texture2D nearGroundTex = LoadTexture("resources/midground.png");
	Texture2D backGroundTex = LoadTexture("resources/background.png");

	// Create game objects
	Scrollable nearGround = Scrollable(nearGroundTex, raylib::Vector2(0.0f, 0.0f), 1, 2.0f);
	//Scrollable midGround = Scrollable();
	Scrollable backGround = Scrollable(backGroundTex, raylib::Vector2(0.0f, 0.0f), 0, 8.0f);
	Player *player = new Player(playerTex, raylib::Vector2(screenWidth / 2, screenHeight / 2));

	std::array<Scrollable, 2> scrollables = {backGround, nearGround};

	// Camera
	Camera2D camera = {0};
	camera.target = (raylib::Vector2){player->position.x + 20, player->position.y + 20};
	camera.offset = (raylib::Vector2)(screenWidth / 2, screenHeight / 2);
	camera.rotation = 0.0f;
	camera.zoom = 1.0f;

	// Attempt to load the game

	SetWindowPosition(800, 800);
	// Main game loop
	while (!w.ShouldClose()) // Detect window close button or ESC key
	{
		// Update
		deltaTime = GetFrameTime();

		if (IsKeyDown('A'))
		{
			player->speed.x += -2.0f * deltaTime;
		}
		else if (IsKeyDown('D'))
		{
			player->speed.x += 2.0f * deltaTime;
		}
		else
		{
			player->speed.x *= player->friction;
		}

		if (IsKeyPressed('S'))
		{
			SaveGameState(*player);
		}

		player->position.x += player->speed.x;
		updateScrollables(scrollables, *player);

		// update the camera
		camera.target = (raylib::Vector2){ player->position.x + 20, player->position.y + 20};

		// Draw
		BeginDrawing();
			ClearBackground(LIGHTGRAY);

			BeginMode2D(camera);

			// Draw background layers
			for (auto &s : scrollables)
			{
				DrawTextureEx(s.texture, s.position, 0.0f, 2.0f, WHITE);
			}

			// Draw Player
			DrawTextureEx(player->texture, player->position, 0.0f, 2.0f, WHITE);
		EndDrawing();
	}

	// clean up the program
	delete player;
	return 0;
}