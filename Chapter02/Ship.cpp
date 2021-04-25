// ----------------------------------------------------------------
// From Game Programming in C++ by Sanjay Madhav
// Copyright (C) 2017 Sanjay Madhav. All rights reserved.
// 
// Released under the BSD License
// See LICENSE in root directory for full details.
// ----------------------------------------------------------------

#include "Ship.h"
#include "Shoot.h"
#include "AnimSpriteComponent.h"
#include "Game.h"

Ship::Ship(Game* game)
	:Actor(game)
	,mRightSpeed(0.0f)
	,mDownSpeed(0.0f)
	,press_space(false)
	,disparou(false)
{
	// Create an animated sprite component for the Ship using images of the project
	AnimSpriteComponent* asc = new AnimSpriteComponent(this);
	std::vector<SDL_Texture*> anims = {
		game->GetTexture("Assets/Ship01.png"),
		game->GetTexture("Assets/Ship02.png"),
		game->GetTexture("Assets/Ship03.png"),
		game->GetTexture("Assets/Ship04.png"),
	};

	//set the textures to the Ship vector of animated sprites
	asc->SetAnimTextures(anims);
}

//update the Ship following modifications made by the ProcessKeyboard
void Ship::UpdateActor(float deltaTime)
{
	Actor::UpdateActor(deltaTime);
	// Update position based on speeds and delta time
	Vector2 pos = GetPosition();
	pos.x += mRightSpeed * deltaTime;
	pos.y += mDownSpeed * deltaTime;
	// Restrict position to left half of screen
	if (pos.x < 25.0f)
	{
		pos.x = 25.0f;
	}
	else if (pos.x > 500.0f)
	{
		pos.x = 500.0f;
	}
	if (pos.y < 25.0f)
	{
		pos.y = 25.0f;
	}
	else if (pos.y > 743.0f)
	{
		pos.y = 743.0f;
	}
	SetPosition(pos);
}

//Get inputs by Keyboard
//this method will change the speed of the Ship
//Remember that the speed is given by some amount of pixels drawn in a given delta time
void Ship::ProcessKeyboard(const uint8_t* state)
{
	disparou = false;
	mRightSpeed = 0.0f;
	mDownSpeed = 0.0f;
	// right/left
	if (state[SDL_SCANCODE_D])
	{
		mRightSpeed += 250.0f;
	}
	if (state[SDL_SCANCODE_A])
	{
		mRightSpeed -= 250.0f;
	}
	// up/down
	if (state[SDL_SCANCODE_S])
	{
		mDownSpeed += 300.0f;
	}
	if (state[SDL_SCANCODE_W])
	{
		mDownSpeed -= 300.0f;
	}
	if (state[SDL_SCANCODE_SPACE])
	{
		//Garante que player não atire diversas vezes como o ESPAÇO pressionado
		if (press_space == false) 
		{
			press_space = true;
			disparou = true;
		}
	}
	if (!state[SDL_SCANCODE_SPACE]) {
		disparou = false;
		press_space = false;
	}
}

