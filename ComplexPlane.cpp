#include "ComplexPlane.h"
#include <cmath>

//Constructor
ComplexPlane::ComplexPlane(float aspectRatio)
{
	m_aspectRatio = aspectRatio;


}

//Zoom In
void ComplexPlane::zoomIn()
{
	m_zoomCount++;
	double x, y;

	x = BASE_WIDTH * pow(BASE_ZOOM, m_zoomCount);
	y = BASE_HEIGHT * m_aspectRatio * pow(BASE_ZOOM, m_zoomCount);

	//*****setSize in m_view to the new size****  TODO*
	

}

//Zoom Out
void ComplexPlane::zoomOut()
{
	m_zoomCount--;
	double x, y;

	x = BASE_WIDTH * pow(BASE_ZOOM, m_zoomCount);
	y = BASE_HEIGHT * m_aspectRatio * pow(BASE_ZOOM, m_zoomCount);

	//***setSize in m_view to the new size*** TODO*

}

//Set Center
void ComplexPlane::setCenter(Vector2f coord)
{

}

//Get view
View ComplexPlane::getView()
{

}

//Set Mouse Location
void ComplexPlane::setMouseLocation(Vector2f coord)
{
	m_mouseLocation = coord;
}

//Load Text
void ComplexPlane::loadText(Text& text)
{

}

//Count iterations
size_t ComplexPlane::countIterations(Vector2f coord)
{

}

//Iterations to RGB
void ComplexPlane::iterationsToRGB(size_t count, uint8_t& r, uint8_t& g, uint8_t& b)
{

}
