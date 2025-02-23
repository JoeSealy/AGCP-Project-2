#pragma once
#include "stdafx.h"
class GUI
{
private:
	//SFML Variables
	sf::Text timerText;
	sf::Text livesText;
	sf::Text PowerUpText;
	sf::Text endGameTextScore;
	sf::Text platText;

	sf::Font Font;

	sf::Clock clock;
	sf::Clock powerClock;

	std::string countUpStr;
	std::string scoreUpStr;
	std::string livesStr;
	std::string platStr;



	//Variables
	int scoreUp;		//adds score over time
	float backgroundSpeed;		//background Speed
	float powerTime;		//Duration of power up

	//Functions
	void initVariables();
	void initFont();
	void initClock();
	void initScore();
	void initLives();
	void initEndGame();
	void initpowerUp();
	void initPlat();


public:
	//constructor/decontrcutor
	GUI();
	virtual ~GUI();

	//SFML Variables
	sf::Text scoreText;
	sf::Text endGameText;
	

	//Variables
	bool invincibility;		//check invincibility
	bool addLivesBool;		//add lives 
	bool addScoreBool;		//adds to score
	bool slowedRocketBool;	//slows rockets
	bool platMessage;

	float countUp;			//time

	int backgroundPos;
	int lives;				//amount lives
	int score;				// adds to score
	int plat;

	//Functions
	float clockUpdate();

	int scoreUpdate();		
	int livesUpdate();
	int platUpdate();
	void powerUpdate();

	void toClockString();
	void toScoreString();
	void toLivesString();
	void toPlatString();



	
	void update();
	void render(sf::RenderTarget& rTarget);

};

