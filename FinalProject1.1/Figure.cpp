#include "stdafx.h"
#include "pch.h"

#include "Figure.h"

IMPLEMENT_SERIAL(Figure, CObject, 1)
void Figure::Serialize(CArchive& ar)
{
	CObject::Serialize(ar);
	if (ar.IsStoring())
	{
		ar << P1;
		ar << P2;
		ar << fg;
		ar << bg;
	}
	else // Loading
	{
		ar >> P1;
		ar >> P2;
		ar >> fg;
		ar >> bg;
	}
}


CPoint Figure::lastPoint()
{
	CPoint point(0.0);
	return point;
}

bool Figure::isInside(const CPoint& P) const
{
	return (P1.x <= P.x && P.x <= P2.x || P1.x >= P.x && P.x >= P2.x) &&
		(P1.y <= P.y && P.y <= P2.y || P1.y >= P.y && P.y >= P2.y);
}
//void Figure::Shift(int dx, int dy)//drag 
//{
//	P1 = P1 + CPoint(dx, dy);
//	P2 = P2 + CPoint(dx, dy);
//}