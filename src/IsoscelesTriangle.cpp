#include "IsoscelesTriangle.h"
#pragma once

void IsoscelesTriangle::initializeIsoscelesTriangle(const Vertex& ver1, const Vertex& ver2, const Vertex& ver3)
{
	double BClength = (distance(ver2, ver3));
	double CAlength(distance(ver3, ver1));

	if (!doubleEqual(BClength, CAlength))
	{
		m_Triangle = { Vertex(20, 20), Vertex(30, 20), Vertex(25, 20 + sqrt(75)) };
	}
}

IsoscelesTriangle::IsoscelesTriangle(const Vertex vertices[3]) 
	:m_Triangle(Triangle(vertices[0], vertices[1], vertices[2]))
{ 
	initializeIsoscelesTriangle(
		m_Triangle.getVertex(0), 
		m_Triangle.getVertex(1),
		m_Triangle.getVertex(2));
}

IsoscelesTriangle::IsoscelesTriangle(const Vertex& left, const Vertex& right, double height)
	:m_Triangle(Triangle(left, right, Vertex{ (left.m_col + right.m_col)/2 ,left.m_row+height }))
{
}

Vertex IsoscelesTriangle::getVertex(int index) const
{
	return m_Triangle.getVertex(index);
}

double IsoscelesTriangle::getLength(int index) const
{
	return m_Triangle.getLength(index);
}

double IsoscelesTriangle::getHeight() const
{
	double row = m_Triangle.getVertex(2).m_row;
	double rowOther = m_Triangle.getVertex(0).m_row;
	return abs(row - rowOther);
}

void IsoscelesTriangle::draw(Board& board) const
{
	m_Triangle.draw(board);
}

Rectangle IsoscelesTriangle::getBoundingRectangle() const
{
	return m_Triangle.getBoundingRectangle();
}

double IsoscelesTriangle::getPerimeter() const
{
	return m_Triangle.getPerimeter();
}

double IsoscelesTriangle::getArea() const
{
	return m_Triangle.getArea();
}

Vertex IsoscelesTriangle::getCenter() const
{
	return m_Triangle.getCenter();
}

bool IsoscelesTriangle::scale(double factor)
{
	return m_Triangle.scale(factor);
}


