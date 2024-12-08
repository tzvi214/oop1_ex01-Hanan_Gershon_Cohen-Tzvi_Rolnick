#pragma once
#include <Vertex.h>
#include <macros.h>
#include <Board.h>

class Rectangle
{
public:
    Rectangle(const Vertex& bottomLeft, const Vertex& topRight);
    Rectangle(const Vertex vertices[2]);
    Rectangle(double x, double y, double width, double height);
    Rectangle(const Vertex& topRight, double width, double height);

    Vertex getBottomLeft() const;
    Vertex getTopRight() const;
    double getWidth() const;
    double getHeight() const;
    void draw(Board& board) const;
    Rectangle getBoundingRectangle() const;
    double getPerimeter() const;
    double getArea() const;
    Vertex getCenter() const;
    bool scale(double fator);

private:
    bool isLegal(const Vertex& bottomLeft, const Vertex& topRight) const;

    Vertex m_bottomLeft, m_topRight;
    double m_width, m_height;
};
