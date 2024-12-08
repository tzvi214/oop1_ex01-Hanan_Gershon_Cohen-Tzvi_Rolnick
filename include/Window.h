#pragma once
#include "Vertex.h"
#include "Board.h"
#include "Rectangle.h"

class Window
{
public:
	Window(const Rectangle& rectangle, const Vertex& point);
	Window(const Vertex& topRight, double width, double height, const Vertex& point);
	Vertex getBottomLeft() const;
	Vertex getTopRight() const;
	Vertex getPoint() const;


	Rectangle getBoundingRectangle() const;
	double getPerimeter() const;
	double getArea()const;
	Vertex getCenter() const;


	bool scale(double factor);
	void draw(Board& board)const;

private:
	Rectangle m_rectangle;
	Vertex m_point;
};
