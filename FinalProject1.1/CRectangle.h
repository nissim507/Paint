#pragma once
#include "Line.h"
class CRectangle :
    public Line
{
    DECLARE_SERIAL(CRectangle)
public:
    CRectangle() :Line() {}
    CRectangle(CPoint p1, CPoint p2, COLORREF Brush, COLORREF Pen) :Line(p1, p2, Pen) { id = 1; bg = Brush; }
    void Draw(CDC* dc) const;

};

