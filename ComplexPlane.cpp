#include "ComplexPlane.h"
#include <cmath>
#include <string>
#include <sstream>

//using namespace sf;

//Constructor
ComplexPlane::ComplexPlane(float aspectRatio) {
    m_aspectRatio = aspectRatio;
    this->m_view.setSize(BASE_WIDTH, -BASE_HEIGHT * m_aspectRatio);
    this->m_view.setCenter(0.0, 0.0);
    this->m_zoomCount = 0;
}

//Zoom In
void ComplexPlane::zoomIn()
{
	m_zoomCount++;
	double x, y;

	x = BASE_WIDTH * pow(BASE_ZOOM, m_zoomCount);
	y = BASE_HEIGHT * m_aspectRatio * pow(BASE_ZOOM, m_zoomCount);

	//*****setSize in m_view to the new size****  TODO*
    this->m_view.setSize(x, y);

}

//Zoom Out
void ComplexPlane::zoomOut()
{
	m_zoomCount--;
	double x, y;

	x = BASE_WIDTH * pow(BASE_ZOOM, m_zoomCount);
	y = BASE_HEIGHT * m_aspectRatio * pow(BASE_ZOOM, m_zoomCount);

	//***setSize in m_view to the new size*** TODO*
    this->m_view.setSize(x, y);
}

//Set Center
void ComplexPlane::setCenter(Vector2f coord)
{
    this->m_view.setCenter(coord);
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
void ComplexPlane::loadText(Text& text) {
    stringstream st;
    st << "Center:(" << this->m_view.getCenter().x << "," << this->m_view.getCenter().y << ")" << endl;
    st << "Cursor:(" << this->m_mouseLocation.x << "," << this->m_mouseLocation.y << ")" << endl;
    st << "Left-click to Zoom in" << endl;
    st << "Left-click to Zoom out" << endl;
    text.setString(st.str());
}

//Count iterations
size_t ComplexPlane::countIterations(Vector2f coord) const
{

}

//Iterations to RGB
void ComplexPlane::iterationsToRGB(size_t count, uint8_t& r, uint8_t& g, uint8_t& b) const
{

}
