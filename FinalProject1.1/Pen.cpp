#include "pch.h"
#include "Pen.h"
#include <vector>

IMPLEMENT_SERIAL(Pen, CObject, 1)

Pen::Pen(CPoint p1, CPoint p2, COLORREF pen) :Line(p1, p2, pen)
{
	id = 5;
	ArrOfPoints.push_back(p1);
}

void Pen::Draw(CDC* dc) const
{
	CPen pen(PS_SOLID, 4, fg);
	for (int i = 1; i < ArrOfPoints.size(); ++i)
	{
		dc->SelectObject(pen);
		dc->MoveTo(ArrOfPoints[i - 1]);
		dc->LineTo(ArrOfPoints[i]);
	}
}
CPoint Pen::lastPoint()
{
	return ArrOfPoints[ArrOfPoints.size() - 1];
}
void Pen::build(CPoint currentPoint)
{
	ArrOfPoints.push_back(currentPoint);
}
void Pen::Serialize(CArchive& ar)
{
	CObject::Serialize(ar);
	if (ar.IsStoring())
	{
		ar << ArrOfPoints.size();
		int size = ArrOfPoints.size();
		ar << getBg();
		ar << getFg();
		for (int i = 0; i < size; i++)
		{
			ar << lastPoint();
			ArrOfPoints.pop_back();
		}
	}
	else // Loading
	{
		int sizeArr;
		ar >> sizeArr;
		COLORREF bg, fg;
		ar >> bg;
		ar >> fg;
		setBrush(bg);
		setPen(fg);
		CPoint p1;
		for (int i = 0; i < sizeArr; i++)
		{
			ar >> p1;
			buildfirst(p1);
		}
	}
}
void Pen::buildfirst(CPoint currentPoint)
{
	ArrOfPoints.insert(ArrOfPoints.begin(), currentPoint);
}