#include "Menu.h"



void Menu::initMenuFont()						//initialise font
{
	if (!this->Font.loadFromFile("Fonts/Bebas-Regular.ttf"))
	{
		std::cerr << "No font file found!" << std::endl;
	}
}

void Menu::initBackground()						//initialise background
{
	if (!this->backgroundTexture.loadFromFile("Textures/background_Menu.png"))
	{
		std::cerr << "No font file found!" << std::endl;
	}
	this->backgroundSprite.setTexture(this->backgroundTexture);
	this->backgroundSprite.setScale(0.5f, 0.5f);

}

void Menu::initVariable()						//initalise varibales
{
	this->startGame = false;
}

void Menu::initMenuText()						//initialise menu text
{
	this->titleText.setFont(this->Font);
	this->titleText.setFillColor(sf::Color::Yellow);
	this->titleText.setString("ROCKET DODGER");
	this->titleText.setPosition(150, 30);
	this->titleText.setCharacterSize(60);

	this->menuText[1].setFont(this->Font);
	this->menuText[1].setFillColor(sf::Color::Red);
	this->menuText[1].setString("Start");
	this->menuText[1].setPosition(280, 150);
	this->menuText[1].setCharacterSize(30);

	this->menuText[2].setFont(this->Font);
	this->menuText[2].setFillColor(sf::Color::White);
	this->menuText[2].setString("Options");
	this->menuText[2].setPosition(280, 250);
	this->menuText[2].setCharacterSize(30);

	this->menuText[3].setFont(this->Font);
	this->menuText[3].setFillColor(sf::Color::White);
	this->menuText[3].setString("Exit");
	this->menuText[3].setPosition(280, 350);
	this->menuText[3].setCharacterSize(30);

	this->selectedItemIndex = 1;
}

Menu::Menu()				//constuctor
{
	this->initBackground();
	this->initVariable();
	this->initMenuFont();
	this->initMenuText();
}

Menu::~Menu()				//deconsuctor
{
}

int Menu::getPressedItem()		//action on selected item
{
	return selectedItemIndex;
}

void Menu::moveUp()		//moves selection up
{
	if (selectedItemIndex - 1 >= 0)
	{
		menuText[this->selectedItemIndex].setFillColor(sf::Color::White);
		this->selectedItemIndex--;
		menuText[this->selectedItemIndex].setFillColor(sf::Color::Red);
	}
}

void Menu::moveDown()		//moves selection down
{
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
	{
		menuText[this->selectedItemIndex].setFillColor(sf::Color::White);
		this->selectedItemIndex++;
		menuText[this->selectedItemIndex].setFillColor(sf::Color::Red);
	}
}

void Menu::update()		//update
{
	this->moveUp();
	this->moveDown();
}

void Menu::render(sf::RenderTarget & rTarget)		//render target
{
	rTarget.draw(backgroundSprite);
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		rTarget.draw(menuText[i]);
	}
	rTarget.draw(titleText);
}

