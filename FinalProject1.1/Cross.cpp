#include "pch.h"
#include "Cross.h"
IMPLEMENT_SERIAL(Cross, CObject, 1)
void Cross::Draw(CDC* dc)const
{
	CPen pen(PS_SOLID, 4, fg);
	dc->SelectObject(&pen);
	dc->MoveTo(getP1().x, getP1().y);
	dc->LineTo(getP2().x, getP2().y);
	dc->MoveTo(getP2().x, getP1().y);
	dc->LineTo(getP1().x, getP2().y);
}
