#include "Level.h"
/*

This code initialise the shape variables (size, color, position...)
and render the shape (tells the programing to output the shape to the screen)

@author:Paul Robertson
Date created: 15/01/2020
@modifiedBy: FMGD
Last Day Modified: 16/01/2020
*/
Level::Level(sf::RenderWindow* hwnd) //Constructor
{
	window = hwnd; //Store reference to window object
	sf::Vector2u pos = window->getSize();
	const int rect_width = 50;
	const int rect_height = 50;
	sf::Vector2f rect4_size = corner_rect.getSize();

	const int circle_radius = circle.getRadius();

	sf::String message = "Hello World";
	int num_chars = message.getSize();
	float text_width = 0;
	int character_size = 24; //In pixels

	// initialise game objects
	//Rectangules
	//The most External triangle
	external_rect.setSize(sf::Vector2f(rect_width * 3, rect_height * 3));
	external_rect.setPosition(125, 125);
	external_rect.setFillColor(sf::Color::Red);

	//Middel triangle
	middle_rect.setSize(sf::Vector2f(rect_width * 2, rect_height * 2));
	middle_rect.setPosition(((external_rect.getSize().x - middle_rect.getSize().x) / 2) + external_rect.getPosition().x , ((external_rect.getSize().y - middle_rect.getSize().y) / 2 ) + external_rect.getPosition().x);
	middle_rect.setFillColor(sf::Color::Green);

	//Inside triangle
	inner_rect.setSize(sf::Vector2f(rect_width, rect_height));
	inner_rect.setOrigin(inner_rect.getSize().x / 2, inner_rect.getSize().y / 2); //Set origin in the middle of the rectangle
	inner_rect.setPosition(((middle_rect.getSize().x - inner_rect.getSize().x) / 2) + middle_rect.getPosition().x + inner_rect.getSize().x / 2, ((middle_rect.getSize().y - inner_rect.getSize().y) / 2) + middle_rect.getPosition().x + inner_rect.getSize().y /2);
	inner_rect.setFillColor(sf::Color::Blue);
	inner_rect.rotate(45);

	//Corner Triangle
	corner_rect.setSize(sf::Vector2f(150, 150));
	corner_rect.setPosition(pos.x - rect4_size.x, pos.y - rect4_size.y);
	corner_rect.setFillColor(sf::Color::Green);

	//Circle
	circle.setRadius(50);
	circle.setPosition(pos.x / 2 - circle_radius, pos.y / 2 - circle_radius);
	circle.setFillColor(sf::Color::Blue);
	circle.setOutlineColor(sf::Color::Red);
	circle.setOutlineThickness(2.f);

	//Text
	if (!font.loadFromFile("font/arial.ttf"))
	{
		std::cout << "Error loading font \n";
	}
	text.setFont(font);
	text.setString(message);
	text_width = text.getLocalBounds().width; //It has to be after declarate charcaterSize
	text.setCharacterSize(character_size);
	text.setFillColor(sf::Color::Red);
	text.setStyle(sf::Text::Bold | sf::Text::Underlined);

	//Get the width of the text on pixels (Local bounding rectangle of the entity)
	text_width = text.getLocalBounds().width; //It has to be after define charcaterSize, style...
	text.setOrigin(text_width/2, 0); //Set the origen in the middle point of the text
	text.setPosition(pos.x / 2, 0);
	
}

Level::~Level()
{
}

// handle user input
void Level::handleInput()
{

}

// Update game objects
void Level::update()
{
	sf::Vector2u pos = window->getSize();
    sf::Vector2f rect4_size = corner_rect.getSize();
	const int circle_radius = circle.getRadius();

	text.setPosition(pos.x / 2 , 0);
	circle.setPosition(pos.x / 2 - circle_radius, pos.y / 2 - circle_radius);
	corner_rect.setPosition(pos.x - rect4_size.x, pos.y - rect4_size.y);

}

// Render level
void Level::render()
{
	beginDraw(); //Blank frame buffer ready for drawing

	window->draw(external_rect);
	window->draw(middle_rect);
	window->draw(inner_rect);

	window->draw(circle);
	window->draw(text);

	window->draw(corner_rect);

	endDraw(); //Send frame buffer to screen
}

void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}