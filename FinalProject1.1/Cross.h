#pragma once
#include "Line.h"
class Cross :public Line
{
    DECLARE_SERIAL(Cross)
public:
    Cross() :Line() {}
    Cross(CPoint p1, CPoint p2, COLORREF Pen) :Line(p1, p2, Pen) { id = 3; }
    void Draw(CDC* dc)const;
};

