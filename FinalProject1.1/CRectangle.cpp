#include "pch.h"
#include "CRectangle.h"
IMPLEMENT_SERIAL(CRectangle, CObject, 1)
void CRectangle::Draw(CDC* dc)const
{
	CPen pen(PS_SOLID, 6, fg);
	CBrush brush(bg);
	dc->SelectObject(&pen);
	dc->SelectObject(&brush);
	dc->Rectangle(getP1().x, getP1().y, getP2().x, getP2().y);
	
}
