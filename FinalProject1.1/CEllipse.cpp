#include "pch.h"
#include "CEllipse.h"
IMPLEMENT_SERIAL(CEllipse, CObject, 1)
void CEllipse::Draw(CDC* dc) const
{
	CPen pen(PS_SOLID, 4, fg);
	CBrush brush(bg);
	dc->SelectObject(&pen);
	dc->SelectObject(&brush);
	dc->Ellipse(getP1().x, getP1().y, getP2().x, getP2().y);
}
