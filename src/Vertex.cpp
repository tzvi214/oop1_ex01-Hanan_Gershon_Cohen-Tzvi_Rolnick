#include "Vertex.h"
#include "macros.h"

#include <iostream>

bool Vertex::isHigherThan(const Vertex& other) const
{
    return m_row >= other.m_row;
}

bool Vertex::isToTheRightOf(const Vertex& other) const
{
    return m_col >= other.m_col;
}

bool Vertex::isValid() const
{
    return m_col >= 0 && m_col <= MAX_COL && m_row >= 0 && m_row <= MAX_ROW;
}

bool Vertex::isParallelXAxis(const Vertex& other) const
{
    // must be if this function are current.
    return m_row - other.m_row < 0.1; //  m_row == other.m_row
}

std::istream& operator>>(std::istream& istr, Vertex& v)
{
    return istr >> v.m_col >> v.m_row;
}

std::ostream& operator<<(std::ostream& ostr, const Vertex& v)
{
    return ostr << "(" << v.m_col << ", " << v.m_row << ")";
}


bool Vertex::isLegalWindo(const Vertex& bottomLeft, const Vertex& topRight) const
{

    return (m_col >= bottomLeft.m_col && m_row >= bottomLeft.m_row
        && m_col <= topRight.m_col && m_row <= topRight.m_row);
}