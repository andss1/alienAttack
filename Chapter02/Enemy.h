#pragma once
#pragma once
#include "Actor.h"
class Enemy : public Actor
{
	//as Ship will be controlled, it needs proper methods for it
public:
	Enemy(class Game* game);
	void UpdateActor(float deltaTime) override;
	float mLeftSpeed;
private:
	float mDownSpeed;
};