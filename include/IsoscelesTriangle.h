#pragma once
#include "Vertex.h"
#include "Utilities.h"
#include "Triangle.h"

class IsoscelesTriangle 
{
public:
	IsoscelesTriangle(const Vertex vertices[3]);
	IsoscelesTriangle(const Vertex& left, const Vertex& right, double height);
	Vertex getVertex(int index) const;
	double getLength(int index) const;
	double getHeight() const;
	void draw(Board& board) const;
	Rectangle getBoundingRectangle() const;
	double getPerimeter() const;
	double getArea() const;
	Vertex getCenter() const;
	bool scale(double factor);

private:
	void initializeIsoscelesTriangle(const Vertex&, const Vertex&, const Vertex&);

	Triangle m_Triangle;

};