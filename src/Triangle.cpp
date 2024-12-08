#include "Triangle.h"
#include "Utilities.h"
#include <cmath>
#include "Board.h"
#include <algorithm>


void Triangle::initializeTriangle(const Vertex& ver1, const Vertex& ver2, const Vertex& ver3)
{
	if (isLegalTriangle(ver1, ver2, ver3))
	{
		m_verBaseLeft = ver1;
		m_verBaseRight = ver2;
		m_verUp = ver3;
		m_ABlength = distance(m_verBaseLeft, m_verBaseRight);
		m_BClength = distance(m_verBaseRight, m_verUp);
		m_CAlength = distance(m_verUp, m_verBaseLeft);
	}
}


Triangle::Triangle(Vertex v0, Vertex v1, Vertex v2) : // Default values
	m_verBaseLeft(20, 20), m_verBaseRight(30, 20), m_verUp(25, 20 + sqrt(75)),
	m_ABlength(distance(m_verBaseLeft, m_verBaseRight)),
	m_BClength(distance(m_verBaseRight, m_verUp)),
	m_CAlength(distance(m_verUp, m_verBaseLeft))
{
	initializeTriangle(v0, v1, v2);
}

Triangle::Triangle(const Vertex vertices[3]) :Triangle(vertices[0], vertices[1], vertices[2]) {}



void Triangle::draw(Board& board) const
{
	board.drawLine(m_verBaseLeft, m_verBaseRight);
	board.drawLine(m_verBaseRight, m_verUp);
	board.drawLine(m_verUp, m_verBaseLeft);
}


double Triangle::getLength(int index) const
{
	if (index < 0 || index>2)
		return -1; // Invalid input.

	switch (index)
	{
	case 0:
		return m_ABlength;
	case 1:
		return m_BClength;
	case 2:
		return m_CAlength;
	}

	return 0.0;
}

Vertex Triangle::getVertex(int index) const
{
	if (index < 0 || index>2)
		return Vertex(); // Invalid input.

	switch (index)
	{
	case 0:
		return m_verBaseLeft;
	case 1:
		return m_verBaseRight;
	case 2:
		return m_verUp;
	}

	return Vertex();
}

double Triangle::getPerimeter() const
{
	return m_ABlength + m_BClength + m_CAlength;
}

double Triangle::getArea() const
{
	double halfPerimeter = getPerimeter()/2;
	return sqrt(halfPerimeter * (halfPerimeter - m_ABlength) * (halfPerimeter - m_BClength) * (halfPerimeter - m_CAlength));
}

Vertex Triangle::getCenter() const
{
	Vertex center;

	center.m_col = (m_verBaseLeft.m_col + m_verBaseRight.m_col + m_verUp.m_col) / 3;
	center.m_row = (m_verBaseLeft.m_row + m_verBaseRight.m_row + m_verUp.m_row) / 3;

	return center;
}


Rectangle Triangle::getBoundingRectangle() const
{
	// The most extreme vertices.
	double colMax = max(max(m_verBaseLeft.m_col, m_verBaseRight.m_col), m_verUp.m_col);
	double colMin = min(min(m_verBaseLeft.m_col, m_verBaseRight.m_col), m_verUp.m_col);
	double rowMax = max(max(m_verBaseLeft.m_row, m_verBaseRight.m_row), m_verUp.m_row);
	double rowMin = min(min(m_verBaseLeft.m_row, m_verBaseRight.m_row), m_verUp.m_row);

	Vertex bottom{ colMin ,rowMin };	
	Vertex top{ colMax ,rowMax };

	return Rectangle(bottom, top);
}

bool Triangle::scale(double factor)
{
	if (factor <= 0)
		return false;

	Vertex center = getCenter();

	// The new distances from each vertex to the center

	Vertex verBaseLeftNew{
	center.m_col + (m_verBaseLeft.m_col - center.m_col) * factor,
	center.m_row + (m_verBaseLeft.m_row - center.m_row) * factor
	};

	Vertex verBaseRightNew{
		center.m_col + (m_verBaseRight.m_col - center.m_col) * factor,
	center.m_row + (m_verBaseRight.m_row - center.m_row) * factor
	};

	Vertex verUpNew{
		center.m_col + (m_verUp.m_col - center.m_col) * factor,
	center.m_row + (m_verUp.m_row - center.m_row) * factor
	};

	if (!isLegalTriangle(verBaseLeftNew, verBaseRightNew, verUpNew))
		return false;

	// Updating the vertices after checking that the domain is valid

	m_verBaseLeft = verBaseLeftNew;
	m_verBaseRight = verBaseRightNew;
	m_verUp = verUpNew;
	m_ABlength = distance(m_verBaseLeft, m_verBaseRight);
	m_BClength = distance(m_verBaseRight, m_verUp);
	m_CAlength = distance(m_verUp, m_verBaseLeft);

	return true;
}

