#include <iostream>
#include "ComplexPlane.h"

int main()
{
  // Get the desktop resolution
	const unsigned int width = VideoMode::getDesktopMode().width;
	const unsigned int height = VideoMode::getDesktopMode().height;


	// Calculate the aspect ratio of the monitor
	float aspectRatio = static_cast<float>(height) / static_cast<float>(width);

	// Construct the window
	RenderWindow window(VideoMode(width, height), "Mandelbrot Set");


	// Construct an object of type ComplexPlane
	ComplexPlane plane(16.0f / 9.0f);

	// Create a Font Object
	Font font;
	if (!font.loadFromFile("Orbitron.ttf"))
	{
		cout << "Font failed to load" << endl;
	}

	// Create a Text Object
	Text text;
	text.setFont(font);
	text.setCharacterSize(24);
	text.setFillColor(Color::White);
	text.setPosition(10, 10);
	
	// Construct Vertex Array



}
