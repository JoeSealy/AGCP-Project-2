#include "Platform.h"


void Platform::initGUI()
{
	this->gui = new GUI();
}

void Platform::initVariables()
{
	this->clockNumber = 1;
	this->easy = false;
	this->medium = false;
	this->hard = false;
}

void Platform::initTexture()
{
	if (!this->texture.loadFromFile("Textures/platform_InGame.jpg"))
	{
		std::cout << "ERROR Platform file is not available";
	}
}

void Platform::initSprite()
{
	srand(time(NULL));

	this->platformStart.setTexture(this->texture);
	this->currentStart = sf::IntRect(30, 0, 700, 30);
	this->platformStart.setTextureRect(this->currentStart);
	this->platformStart.setPosition(0, 200);


	this->platformShort.setTexture(this->texture);
	this->currentShort = sf::IntRect(45, 215, 180, 25);
	this->platformShort.setTextureRect(this->currentShort);
	this->platformShort.setScale(0.7f, 1.f);

	for (int i = 0; i < 6; i++) {
		this->platformShort.setPosition(this->randX(), -50.f);
		this->platform_List.push_back(platformShort);
	}

	this->platformMedium.setTexture(this->texture);
	this->currentMedium = sf::IntRect(45, 215, 180, 25);
	this->platformMedium.setTextureRect(this->currentMedium);
	this->platformMedium.setScale(1.3f, 1.f);

	for (int i = 0; i < 6; i++) {
		this->platformMedium.setPosition(this->randX(), -50.f);
		this->platform_List.push_back(platformMedium);
	}

	this->platformLong.setTexture(this->texture);
	this->currentLong = sf::IntRect(30, 362, 520, 38);
	this->platformLong.setTextureRect(this->currentLong);
	this->platformLong.setScale(0.7, 1);

	for (int i = 0; i < 6; i++) {
		this->platformLong.setPosition(this->randX(), -50.f);
		this->platform_List.push_back(platformLong);
	}
}

//public

Platform::Platform()
{
	this->initSprite();
	this->initVariables();
	this->initTexture();
	this->initGUI();
}

Platform::~Platform()
{
	delete this->gui;
}

int Platform::randX()
{
	randXint = std::rand() % 400;
	return randXint;
}

const sf::Vector2f Platform::getPosition() const
{
	return this->platform_List[platformNumber].getPosition();
}

const sf::FloatRect Platform::windowBounds() const
{
	for (int i = 0; i < platform_List.size(); i++) 
	{
		return this->platform_List[i].getGlobalBounds();
	}
}

void Platform::positionSet(const float x, const float y)
{
		this->randX();
		return this->platform_List[platformNumber].setPosition(this->randX() , y);
}

void Platform::updatePlatformPhysics()
{
	this->gui->clockUpdate();

	(this->velocity.y) = 1 + (this->gui->clockUpdate() / 100);

	if (this->velocity.y > 3)
	{
		this->velocity.y = 3;
	}

	if (this->gui->clockUpdate() > 2.f)
	{
		this->easy = true;
	}

	if (this->gui->clockUpdate() > 30.f)
	{
		if (this->gui->clockUpdate() > 36.f) {
			this->platform_List[12].setPosition(0, -50);
			this->platform_List[13].setPosition(0, -50);
			this->platform_List[14].setPosition(0, -50);
		}

		this->easy = false;
		this->medium = true;
	}

	if (this->gui->clockUpdate() > 60.f)
	{

		if (this->gui->clockUpdate() > 66.f) {
			this->platform_List[6].setPosition(0, -50);
			this->platform_List[7].setPosition(0, -50);
			this->platform_List[8].setPosition(0, -50);
			this->platform_List[9].setPosition(0, -50);
		}

		this->medium = false;
		this->hard = true;
	}


	if (easy)
	{
		if (this->gui->clockUpdate() > 2.f) {
			this->platform_List[12].move(this->velocity);
		}

		if (this->gui->clockUpdate() > 5.f) {
			this->platform_List[13].move(this->velocity);
		}

		if (this->gui->clockUpdate() > 8.f) {
			this->platform_List[14].move(this->velocity);
		}

	}

	if (medium)
	{
		if (this->gui->clockUpdate() > 32.f) {
			this->platform_List[6].move(this->velocity);
		}

		if (this->gui->clockUpdate() > 34.f) {
			this->platform_List[7].move(this->velocity);
		}

		if (this->gui->clockUpdate() > 36.f) {
			this->platform_List[8].move(this->velocity);
		}

		if (this->gui->clockUpdate() > 38.f) {
			this->platform_List[9].move(this->velocity);
		}

	}

	if (hard)
	{
		if (this->gui->clockUpdate() > 60.f) {
			this->platform_List[0].move(this->velocity);
		}

		if (this->gui->clockUpdate() > 62.f) {
			this->platform_List[1].move(this->velocity);
		}

		if (this->gui->clockUpdate() > 65.f) {
			this->platform_List[2].move(this->velocity);
		}

		if (this->gui->clockUpdate() > 67.f) {
			this->platform_List[3].move(this->velocity);
		}

		if (this->gui->clockUpdate() > 70.f) {
			this->platform_List[4].move(this->velocity);
		}

		if (this->gui->clockUpdate() > 72.f) {
			this->platform_List[5].move(this->velocity);
		}

	}
	
	
}

void Platform::update()
{
	this->updatePlatformPhysics();
}

void Platform::render(sf::RenderTarget & rTarget)
{

	for (int i = 0; i < platform_List.size(); i++) {
		rTarget.draw(this->platform_List[i]);
	}
}
