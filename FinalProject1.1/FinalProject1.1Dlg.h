
// FinalProject1.1Dlg.h : header file
//

#pragma once
#include "Figure.h"
#include "Line.h"
#include "Cross.h"
#include "CRectangle.h"
#include "CEllipse.h"
#include "Pen.h"

// CFinalProject11Dlg dialog
class CFinalProject11Dlg : public CDialogEx
{
private:
	CMFCColorButton m_Color1,m_Color2; //Color Taking from the button
	COLORREF curColorBrush, curColorPen;
// Construction
public:
	CFinalProject11Dlg(CWnd* pParent = nullptr);	// standard constructor
	virtual  ~CFinalProject11Dlg();//destructor
// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_FINALPROJECT11_DIALOG };
#endif
	CPoint start, end,TLX;
	int futureFigureKind = 1; //Rectangle 
	int index = 0;
	bool isPressed = false;//is mouse pressed
	bool cursorPressed=false; //check if the button for moving is pressed
	CTypedPtrArray< CObArray, Figure*> figs;//template arr of figures
	CTypedPtrArray< CObArray, Figure*> temp;
	bool ShapePressed=false; // checking if i'm still on shape
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:

	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();
	afx_msg void OnBnClickedRadio3();
	afx_msg void OnBnClickedRadio4();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedMfccolorbutton3();
	afx_msg void OnBnClickedMfccolorbutton1();
	afx_msg void OnBnClickedCheck1();
	BOOL Drag;
	BOOL refill;
	afx_msg void OnBnClickedButton5();
	
	afx_msg void OnBnClickedRadio5();
	afx_msg void OnBnClickedButton6();
};
