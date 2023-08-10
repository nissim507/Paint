#pragma once
#include "Line.h"
#include <vector>
class Pen :public Line
{
	DECLARE_SERIAL(Pen)
public:
	
	Pen() :Line() {}
	Pen(CPoint p1, CPoint p2, COLORREF pen);
	void Draw(CDC* dc)const;
	CPoint lastPoint();
	void build(CPoint currentPoint);
	void buildfirst(CPoint currentPoint);
	void Serialize(CArchive& ar);
private:
	vector <CPoint> ArrOfPoints;
};

