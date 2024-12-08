#pragma once
#include "Rectangle.h"
#include "Vertex.h"
#include "Board.h"

class Triangle
{
public:
	Triangle(const Vertex vertices[3]);
	Triangle(Vertex v0, Vertex v1, Vertex v2);
	double getLength(int index) const;
	Vertex getVertex(int index) const;

	void draw(Board& board) const;
	Rectangle getBoundingRectangle() const;
	double getPerimeter() const;
	double getArea() const;
	Vertex getCenter() const;
	bool scale(double factor);

private:
	void initializeTriangle(const Vertex&, const Vertex&, const Vertex&);

	Vertex m_verBaseLeft, m_verBaseRight, m_verUp;
	double m_ABlength, m_BClength, m_CAlength;

};
