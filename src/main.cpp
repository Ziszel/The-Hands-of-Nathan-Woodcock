#include "parallax.hpp"
#include "player.hpp"
#include "Utility/calMath.hpp"
#include "serialisation.hpp"
#include "option.hpp"
#include "menu.hpp"
#include "ui.hpp"
#include <raylib-cpp.hpp>
#include <array>
#include <vector>

int main()
{

	// Initialization
	int screenWidth = 640;
	int screenHeight = 480;
	float fps = 60.0f;
	float deltaTime = 0.0f;

	raylib::Color textColor(LIGHTGRAY);
	raylib::Window w(screenWidth, screenHeight, "The Hands of Nathan Woodcock");

	SetTargetFPS(fps);

	// Load Resources
	Texture2D playerTex = LoadTexture("resources/player.png");
	Texture2D midGroundTex = LoadTexture("resources/midground.png");
	Texture2D backGroundTex = LoadTexture("resources/background.png");
	Texture2D menuTex = LoadTexture("resources/windowsxpbg.png");

	// Create test menu objects
	int drawTest = 0;
	Option cont = Option("continue");
	Option settings = Option("settings");
	Option exit = Option("exit");
	std::vector<Option> pauseOptions;
	pauseOptions.push_back(exit);
	pauseOptions.push_back(settings);
	pauseOptions.push_back(cont);
	Menu pauseMenu = Menu(menuTex, raylib::Vector2((float)screenWidth * 0.5 - 30, 25), "PAUSE", pauseOptions);

	// Create game objects
	Scrollable midGround = Scrollable(midGroundTex, std::pair<float, float>(0.0f, 0.0f), 1, 2.0f);

	Scrollable backGround = Scrollable(backGroundTex, std::pair<float, float>(0.0f, 0.0f), 0, 8.0f);
	Player *player = new Player(playerTex, std::pair<float, float>(screenWidth / 2, screenHeight / 2));
	UI ui = UI();

	std::array<Scrollable, 2> scrollables = {backGround, midGround};

	// Camera
	Camera2D camera = {0};
	camera.target = (raylib::Vector2){player->position.first + 20, player->position.second + 20};
	camera.offset = (raylib::Vector2){screenWidth / 2, screenHeight / 2};
	camera.rotation = 0.0f;
	camera.zoom = 1.0f;

	SetWindowPosition(600, 400);
	// Main game loop
	while (!w.ShouldClose()) // Detect window close button or ESC key
	{
		if (drawTest == 1)
		{
		}
		else
		{

			// Update
			deltaTime = GetFrameTime();

			if (IsKeyPressed('S'))
			{
				SaveGameState(*player, scrollables);
			}
			else if (IsKeyPressed('L'))
			{
				LoadGameState(*player, scrollables);
			}

			player->Update(deltaTime);
			updateScrollables(scrollables, *player);

			// update the camera
			camera.target = (raylib::Vector2){player->position.first + player->width + player->speed.first * 7, player->position.second + player->height};
		}

		// Draw
		BeginDrawing();
		ClearBackground(LIGHTGRAY);

		if (drawTest == 1)
		{
			pauseMenu.Draw(screenWidth, screenHeight);
		}
		else
		{

			// everything drawn within this mode is relational to the camera and not the screen
			BeginMode2D(camera);

			// Draw background layers
			for (auto &s : scrollables)
			{
				raylib::Vector2 sPos = {s.position.first, s.position.second};
				DrawTextureEx(s.texture, sPos, 0.0f, 2.0f, WHITE);
			}

			// Draw Player
			player->Draw();

			EndMode2D();
			// Draw UI (for now just player health)
			ui.Draw(player, screenWidth);
			
		}
		EndDrawing();
	}

	// clean up the program
	delete player;
	return 0;
}