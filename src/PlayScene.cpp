#include "PlayScene.h"
#include "Game.h"
#include "EventManager.h"
#include "TextureManager.h"

PlayScene::PlayScene()
{
	PlayScene::start();
}

PlayScene::~PlayScene()
= default;

void PlayScene::draw()
{
	TextureManager::Instance()->draw("background", 0, 0);
	TextureManager::Instance()->draw("floor", 0, 725);
	drawDisplayList();
}

void PlayScene::update()
{
	updateDisplayList();
}

void PlayScene::clean()
{
	removeAllChildren();
}

void PlayScene::handleEvents()
{
	EventManager::Instance().update();

	// handle player movement with GameController
	/* if (SDL_NumJoysticks() > 0)
	{
		if (EventManager::Instance().getGameController(0) != nullptr)
		{
			const auto deadZone = 10000;
			if (EventManager::Instance().getGameController(0)->LEFT_STICK_X > deadZone)
			{
				m_pPlayer->setAnimationState(PLAYER_RUN_RIGHT);
				m_playerFacingRight = true;
			}
			else if (EventManager::Instance().getGameController(0)->LEFT_STICK_X < -deadZone)
			{
				m_pPlayer->setAnimationState(PLAYER_RUN_LEFT);
				m_playerFacingRight = false;
			}
			else
			{
				if (m_playerFacingRight)
				{
					m_pPlayer->setAnimationState(PLAYER_IDLE_RIGHT);
				}
				else
				{
					m_pPlayer->setAnimationState(PLAYER_IDLE_LEFT);
				}
			}
		}
	}


	// handle player movement if no Game Controllers found
	if (SDL_NumJoysticks() < 1)
	{
		if (EventManager::Instance().isKeyDown(SDL_SCANCODE_A))
		{
			m_pPlayer->setAnimationState(PLAYER_RUN_LEFT);
			m_playerFacingRight = false;
		}
		else if (EventManager::Instance().isKeyDown(SDL_SCANCODE_D))
		{
			m_pPlayer->setAnimationState(PLAYER_RUN_RIGHT);
			m_playerFacingRight = true;
		}
		else
		{
			if (m_playerFacingRight)
			{
				m_pPlayer->setAnimationState(PLAYER_IDLE_RIGHT);
			}
			else
			{
				m_pPlayer->setAnimationState(PLAYER_IDLE_LEFT);
			}
		}
	}
	 */

	if (EventManager::Instance().isKeyDown(SDL_SCANCODE_ESCAPE))
	{
		TheGame::Instance()->quit();
	}

	if (EventManager::Instance().isKeyDown(SDL_SCANCODE_1))
	{
		TheGame::Instance()->changeSceneState(START_SCENE);
	}

	if (EventManager::Instance().isKeyDown(SDL_SCANCODE_2))
	{
		TheGame::Instance()->changeSceneState(END_SCENE);
	}
}

void PlayScene::start()
{
	// Plane Sprite
	//m_pPlaneSprite = new Plane();
	//addChild(m_pPlaneSprite);

	TextureManager::Instance()->load("../Assets/Textures/background.jpg", "background");
	TextureManager::Instance()->load("../Assets/Textures/floor.png", "floor");

	
	// Player Sprite
	m_pPlayer = new Player();
	addChild(m_pPlayer);
	m_playerFacingRight = true;

	// Back Button
	m_pPlayButton = new Button("../Assets/textures/startButton.png", "playButton", PLAY_BUTTON);
	m_pPlayButton->getTransform()->position = glm::vec2(400.0f, 762.5f);
	
	m_pPlayButton->addEventListener(CLICK, [&]()->void
	{
		m_pPlayButton->setActive(false);
		m_pPlayer->reset();
		m_pPlayer->setIsMoving(true);
		//TheGame::Instance()->changeSceneState(START_SCENE);
	});

	m_pPlayButton->addEventListener(MOUSE_OVER, [&]()->void
	{
		m_pPlayButton->setAlpha(128);
	});

	m_pPlayButton->addEventListener(MOUSE_OUT, [&]()->void
	{
		m_pPlayButton->setAlpha(255);
	});

	addChild(m_pPlayButton);
}
