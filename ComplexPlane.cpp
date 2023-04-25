#include "ComplexPlane.h"
#include <cmath>
#include <string>
#include <sstream>
#include <complex>

//Constructor
ComplexPlane::ComplexPlane(float aspectRatio) 
{
	// Store the aspectRatio into m_aspectRatio
    m_aspectRatio = aspectRatio;

	// setSize of the m_view variable to BASE_WIDTH, -BASE_HEIGHT * m_aspectRatio
	// Negative size for the height will invert the vertical axis
    this->m_view.setSize(BASE_WIDTH, -BASE_HEIGHT * m_aspectRatio);

	// setCenter of the m_view variable to 0.0, 0.0
    this->m_view.setCenter(0.0, 0.0);

	// Set m_zoomCount to 0
    this->m_zoomCount = 0;
}

//Zoom In
void ComplexPlane::zoomIn()
{
	// Increment m_zoomCount
	m_zoomCount++;
	// Set a local variable for the x size to BASE_WIDTH * (BASE_ZOOM to the m_ZoomCount power)
	float xSize = BASE_WIDTH * pow(BASE_ZOOM, m_zoomCount);

	// Set a local variable for the y size to BASE_HEIGHT * m_aspectRatio * (BASE_ZOOM to the m_ZoomCount power)
	float ySize = BASE_HEIGHT * m_aspectRatio * pow(BASE_ZOOM, m_zoomCount);

	// setSize in m_view to the new size
	this->m_view.setSize(xSize, ySize);
}

//Zoom Out
void ComplexPlane::zoomOut()
{
	// decrement m_zoomCount
	m_zoomCount--;

	// Set a local variable for the x size to BASE_WIDTH* (BASE_ZOOM to the m_ZoomCount power)
	float xSize = BASE_WIDTH * pow(BASE_ZOOM, m_zoomCount);

	// Set a local variable for the y size to BASE_HEIGHT * m_aspectRatio * (BASE_ZOOM to the m_ZoomCount power)
	float ySize = BASE_HEIGHT * m_aspectRatio * pow(BASE_ZOOM, m_zoomCount);
	
	// setSize in m_view to the new size
    this->m_view.setSize(xSize, ySize);
}

//Set Center
void ComplexPlane::setCenter(Vector2f coord)
{
	// setCenter for m_view to the given coordinate
    this->m_view.setCenter(coord);
}

//Get view
View ComplexPlane::getView()
{
	return m_view;
}

//Set Mouse Location
void ComplexPlane::setMouseLocation(Vector2f coord)
{
	// Store the given value in the m_mouseLocation variable
	m_mouseLocation = coord;
}

//Load Text
void ComplexPlane::loadText(Text& text) 
{
	// Use a stringstream and the corresponding member variables
	// to create the following output:
	// Mandelbrot Set
	// Center: (0,0)
	// Cursor: (-1.05313, 0.828125)
	// Left-click to Zoom in
	// Right-click to Zoom out

	// Create a stringstream to store the text
    stringstream st;

	// Add the Title line
	st << "Mandelbrot Set\n";

	// Center
    st << "Center:(" << this->m_view.getCenter().x << "," << this->m_view.getCenter().y << ")" << endl;
	// Cursor
    st << "Cursor:(" << this->m_mouseLocation.x << "," << this->m_mouseLocation.y << ")" << endl;
	// Zoom Instructions
    st << "Left-click to Zoom in" << endl;
    st << "Left-click to Zoom out" << endl;
	// Set the text string of the Text object to the stringstream contents
    text.setString(st.str());
}

//Count the number of iterations of the set for the given coordinate
size_t ComplexPlane::countIterations(Vector2f coord) const
{
	// Convert the pixel coordinate to a complex number
	complex<float> c(coord.x / m_view.getSize().x * m_view.getSize().x - m_view.getSize().x / 2 + m_view.getCenter().x, 
					 coord.y / m_view.getSize().y * m_view.getSize().y - m_view.getSize().y / 2 + m_view.getCenter().y);

	// Initialize the iteration count and complex number z to 0
	size_t count = 0;
	complex<float> z(0, 0);

	// Iterate until the max number of iterations is reached or z escapes the circle of radius 2
	while (count < MAX_ITER && abs(z) < 2.0)
	{
		z = z * z + c;
		count++;
	}

	return count;
}

//Iterations to RGB
void ComplexPlane::iterationsToRGB(size_t count, Uint8& r, Uint8& g, Uint8& b) const
{
	if (count == MAX_ITER)
	{
		r = 0;
		g = 0;
		b = 0;
		return;
	}
	else
	{
        //***TODO**
        if (count < 10) {
            r = 234;
            g = 51;
            b = 247;
        } else if (count < 20) {
            r = 111;
            g = 240;
            b = 227;
        } else if (count < 30) {
            r = 51;
            g = 117;
            b = 144;
        } else if (count < 40) {
            r = 94;
            g = 204;
            b = 61;
        } else if (count < 50) {
            r = 255;
            g = 255;
            b = 84;
        } else {
//            r = 215;
//            g = 91;
//            b = 84;
            r = 215;
            g = 91;
            b = 84;
        }
    }

}
