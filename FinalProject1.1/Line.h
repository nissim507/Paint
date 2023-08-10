#pragma once
#include "Figure.h"
class Line :public Figure
{
    DECLARE_SERIAL(Line)
public:
    Line():Figure(){}
    Line(CPoint p1, CPoint p2, COLORREF Pen) :Figure(p1, p2) { id = 2; fg = Pen; }
    void Draw(CDC* dc)const;
};

