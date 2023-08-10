#include "pch.h"
#include "Line.h"
IMPLEMENT_SERIAL(Line, CObject, 1)
void Line::Draw(CDC* dc) const
{
	CPen pen(PS_SOLID, 4, fg);
	dc->SelectObject(&pen);
	dc->MoveTo(getP1().x, getP1().y);
	dc->LineTo(getP2().x, getP2().y);
}
