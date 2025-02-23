#pragma once
#include "stdafx.h"
#include "gui.h"
class PowerUp
{
	private:
		//SFML Variables
		sf::Sprite powerUp;
		sf::Texture texture;
		sf::Event event;
		sf::Vector2f velocity;
		sf::IntRect currentFrame;

		sf::Clock dropClock;
		
		//Variables
		int randDropClockInt;	//random drops
		int dropClockInt;		//random drops based on clock
		int randX;				//random power up

		//Functions
		void initVariables();
		void initTexture();
		void initSprite();

	public:
		//Contructor/Destructor
		PowerUp();
		virtual ~PowerUp();

		//Variables
		int randPowerUpInt;		//random power up
		bool powerUpDrop;		//if power up has been used

		//Functions
		int randClockInt();
		int randPowerUp();
		int randXint();

		const sf::Vector2f getPosition() const;
		const sf::FloatRect windowBounds() const;
		void positionSet(const float x, const float y);

		void updatePowerUpPhysics();
		void update();
		void render(sf::RenderTarget& rTarget);
};

