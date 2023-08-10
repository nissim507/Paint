#pragma once
#include "Figure.h"
class CEllipse :public Figure
{
	DECLARE_SERIAL(CEllipse)   
public:
	CEllipse() :Figure(){}
	CEllipse(CPoint p1, CPoint p2, COLORREF Brush, COLORREF Pen) :Figure(p1, p2) { id = 4; bg = Brush; fg = Pen; }
	void Draw(CDC* dc) const;
};


