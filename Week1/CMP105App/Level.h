#pragma once

#include <SFML/Graphics.hpp>
#include <string.h>
#include <iostream>

/*

This code defines the shape variables

@author:Paul Robertson
Date created: 15/01/2020
@modifiedBy: FMGD
Last day Modified: 16/01/2020
*/


class Level{
public:
	Level(sf::RenderWindow* hwnd);
	~Level();

	void handleInput();
	void update();
	void render();

private:
	void beginDraw();
	void endDraw();
	sf::RenderWindow* window;

	sf::RectangleShape inner_rect;
	sf::RectangleShape middle_rect;
	sf::RectangleShape external_rect;

	sf::RectangleShape corner_rect;

	sf::CircleShape circle;

	sf::Font font;
	sf::Text text;


};