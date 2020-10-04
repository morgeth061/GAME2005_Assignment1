#pragma once
#ifndef __PLAYER__
#define __PLAYER__

#include "PlayerAnimationState.h"
#include "Sprite.h"

class Player final : public Sprite
{
public:
	Player();
	~Player();

	// Life Cycle Methods
	virtual void draw() override;
	virtual void update() override;
	virtual void clean() override;

	// setters
	void setAnimationState(PlayerAnimationState new_state);

	void setIsMoving(bool moving);

	void reset();

private:
	void m_buildAnimations();

	PlayerAnimationState m_currentAnimationState;

	int angleDegrees;
	float initVelocity;

	int frameCount = 1;
	bool isMoving = false;
};

#endif /* defined (__PLAYER__) */