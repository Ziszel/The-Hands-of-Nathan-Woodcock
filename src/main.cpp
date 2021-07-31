#include "parallax.hpp"
#include "player.hpp"
#include "Utility/calMath.hpp"
#include "serialisation.hpp"
#include <raylib-cpp.hpp>
#include <array>

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

	// Create game objects
	Scrollable midGround = Scrollable(midGroundTex, raylib::Vector2(0.0f, 0.0f), 1, 2.0f);

	Scrollable backGround = Scrollable(backGroundTex, raylib::Vector2(0.0f, 0.0f), 0, 8.0f);
	Player *player = new Player(playerTex, raylib::Vector2(screenWidth / 2, screenHeight / 2));

	std::array<Scrollable, 2> scrollables = {backGround, midGround};

	// Camera
	Camera2D camera = {0};
	camera.target = (raylib::Vector2){player->position.x + 20, player->position.y + 20};
	camera.offset = (raylib::Vector2){screenWidth / 2, screenHeight / 2};
	camera.rotation = 0.0f;
	camera.zoom = 1.0f;

	SetWindowPosition(800, 800);
	// Main game loop
	while (!w.ShouldClose()) // Detect window close button or ESC key
	{
		// Update
		deltaTime = GetFrameTime();

		if (IsKeyDown('A') && player->speed.x > -player->maxSpeed)
		{
			player->speed.x += -player->acceleration * deltaTime;
		}
		else if (IsKeyDown('D') && player->speed.x < player->maxSpeed)
		{
			player->speed.x += player->acceleration * deltaTime;
		}
		else if (player->inAir == false)
		{
			player->speed.x *= player->friction;
		}

		if (IsKeyPressed('W') && player->inAir == false)
		{
			// move player up.
			player->speed.y -= 500.0f * deltaTime;
			// We are now in the air
			player->inAir = true;
		}
		if (player->position.y < player->groundHeight && player->inAir == true)
		{
			// player must now be in the air, stop them jumping again,
			// and slowly bring them down.
			player->speed.y += player->gravity * deltaTime;
		}
		// this controls if the player is on the floor, replace with tiled
		// logic once implemented
		if (player->position.y > 240)
		{
			player->inAir = false;
			player->speed.y = 0;
			player->position.y = 240;
		}

		if (IsKeyPressed('J'))
		{
			if (player->health > 0)
			{
				player->health--;
			}
		}

		if (IsKeyPressed('S'))
		{
			SaveGameState(*player, scrollables);
		}
		else if (IsKeyPressed('L'))
		{
			LoadGameState(*player, scrollables);
		}

		std::cout << player->position.y << std::endl;
		std::cout << player->inAir << std::endl;
		player->position.x += player->speed.x;
		player->position.y += player->speed.y;
		updateScrollables(scrollables, *player);

		// update the camera
		if (player->speed.x != player->maxSpeed || player->speed.x != -player->maxSpeed)
		{
			camera.target = (raylib::Vector2){player->position.x + 20 + player->speed.x * 7, player->position.y + 20};
		}
		else
		{
			camera.target = (raylib::Vector2){player->position.x + 20 + player->maxSpeed, player->position.y + 20};
		}

		// Draw
		BeginDrawing();
		ClearBackground(LIGHTGRAY);

		// everything drawn within this mode is relational to the camera and not the screen
		BeginMode2D(camera);

		// Draw background layers
		for (auto &s : scrollables)
		{
			DrawTextureEx(s.texture, s.position, 0.0f, 2.0f, WHITE);
		}

		// Draw Player
		DrawTextureEx(player->texture, player->position, 0.0f, 2.0f, WHITE);

		EndMode2D();
		// Draw UI (for now just player health)
		int healthRecWidth = 25;
		int healthRecHeight = 25;
		int padding = 10;
		for (int i = player->health; i >= 0; i--)
		{
			int posX = screenWidth - (healthRecWidth + padding) * i;
			int posY = 25;

			DrawRectangle(posX, posY, healthRecWidth, healthRecHeight, RED);
		}
		EndDrawing();
	}

	// clean up the program
	delete player;
	return 0;
}