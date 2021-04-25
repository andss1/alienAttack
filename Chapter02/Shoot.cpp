#include "Shoot.h"
#include "AnimSpriteComponent.h"
#include "Game.h"

Shoot::Shoot(Game* game)
	:Actor(game)
	, mRightSpeed(0.0f)
	, mDownSpeed(0.0f)
{
	// Create an animated sprite component for the Ship using images of the project
	AnimSpriteComponent* asc = new AnimSpriteComponent(this);
	std::vector<SDL_Texture*> anims = {
		game->GetTexture("Assets/Laser.png"),
	};

	//set the textures to the Ship vector of animated sprites
	asc->SetAnimTextures(anims);
}

//update the Enemy position
void Shoot::UpdateActor(float deltaTime)
{
	Actor::UpdateActor(deltaTime);
	// Update position based on speeds and delta time
	Vector2 pos = GetPosition();
	pos.x = pos.x + 15;

	SetPosition(pos);
}