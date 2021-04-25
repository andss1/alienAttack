#include "Enemy.h"
#include "AnimSpriteComponent.h"
#include "Game.h"

Enemy::Enemy(Game* game)
	:Actor(game)
	, mLeftSpeed(5.0f)
	, mDownSpeed(0.0f)
{
	// Create an animated sprite component for the Ship using images of the project
	AnimSpriteComponent* asc = new AnimSpriteComponent(this);
	std::vector<SDL_Texture*> anims = {
		game->GetTexture("Assets/Enemy01.png"),
		game->GetTexture("Assets/Enemy02.png"),
		game->GetTexture("Assets/Enemy03.png"),
		game->GetTexture("Assets/Enemy04.png"),
		game->GetTexture("Assets/Enemy05.png"),
		game->GetTexture("Assets/Enemy06.png"),
	};

	//set the textures to the Ship vector of animated sprites
	asc->SetAnimTextures(anims);
}

//update the Enemy position
void Enemy::UpdateActor(float deltaTime)
{
	Actor::UpdateActor(deltaTime);
	// Update position based on speeds and delta time
	Vector2 pos = GetPosition();
	pos.x = pos.x- mLeftSpeed;

	SetPosition(pos);
}