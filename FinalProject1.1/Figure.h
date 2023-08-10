#include "stdafx.h"
#pragma once

using namespace std;
class Figure : public CObject {
	DECLARE_SERIAL(Figure)  
protected:
	int id;
	CPoint P1;
	CPoint P2;
	COLORREF fg, bg;
public:
	Figure() {  }
	Figure(CPoint p1, CPoint p2) :P1(p1), P2(p2) { }
	virtual void Serialize(CArchive& ar);
	virtual void Draw(CDC* dc) const {}
	int getID()const { return id; }
	CPoint getP1() const
	{
		return P1;
	}
	CPoint getP2() const
	{
		return P2;
	}
	void setx1(int x) 
	{
		P1.x = x;
	}
	void setx2(int x)
	{
		P2.x = x;
	}
	void sety1(int y)
	{
		P1.y = y;
	}
	void sety2(int y)
	{
		P2.y = y;
	}
	COLORREF getBg()const { return bg; }
	COLORREF getFg()const { return fg; }
	virtual CPoint lastPoint();
	virtual void build(CPoint currentPoint) {}
	void setBrush(COLORREF nB) { bg = nB; }
	void setPen(COLORREF nP) { fg = nP; }
	virtual void Redefine(CPoint p1, CPoint p2) { P1 = p1; P2 = p2; }
	virtual bool isInside(const CPoint& P) const;
	/*virtual void Shift(int dx, int dy);*/
};
