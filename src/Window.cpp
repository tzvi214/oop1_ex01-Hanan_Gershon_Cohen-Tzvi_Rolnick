#include "Window.h"
#include "Rectangle.h"
#include "macros.h"
#include <iostream>
using namespace std;

Window::Window(const Rectangle& rectangle, const Vertex& point)
	:m_rectangle(Rectangle(m_rectangle.getBottomLeft(), m_rectangle.getTopRight())),
	m_point(25, 15)
{
	if (point.isLegalWindo(rectangle.getBottomLeft(), rectangle.getTopRight()))
	{
		m_rectangle = rectangle; // using with the defult copy c-tor.
		m_point = point;
	}
}

Window::Window(const Vertex& topRight, double width, double height, const Vertex& point)
	:Window(Rectangle(Vertex(topRight.m_col - width, topRight.m_row - height), topRight)
		, point){}

Vertex Window::getBottomLeft() const
{
	return Vertex(m_rectangle.getBottomLeft());
}

Vertex Window::getTopRight() const
{
	return Vertex(m_rectangle.getTopRight());
}

Vertex Window::getPoint() const
{
	return m_point;
}

Rectangle Window::getBoundingRectangle() const
{
	return m_rectangle.getBoundingRectangle();
}

double Window::getPerimeter() const
{
	return m_rectangle.getPerimeter() * 2;
}

double Window::getArea() const
{
	return m_rectangle.getArea();
}

Vertex Window::getCenter() const
{
	return m_point;
}

bool Window::scale(double factor)
{
	return m_rectangle.scale(factor);
}

void Window::draw(Board& board) const
{
	// Creating 4 rectangles, divided by the "Point".
	Rectangle left_down(m_rectangle.getBottomLeft(), m_point),
	right_down(Vertex(m_point.m_col, m_rectangle.getBottomLeft().m_row), Vertex(m_rectangle.getTopRight().m_col, m_point.m_row)),//(p,bl),(tr,p)
	left_up(Vertex(m_rectangle.getBottomLeft().m_col, m_point.m_row), Vertex(m_point.m_col, m_rectangle.getTopRight().m_row)),//(bl,p),(p,tr)
	right_up(m_point, m_rectangle.getTopRight());

	left_down.draw(board);
	right_down.draw(board);
	left_up.draw(board);
	right_up.draw(board);

}

