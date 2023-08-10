//authors : 
//adir mintz 316579549
//nisim cohen 308152537


// FinalProject1.1Dlg.cpp : implementation file 


#include "pch.h"
#include "framework.h"
#include "FinalProject1.1.h"
#include "FinalProject1.1Dlg.h"
#include "afxdialogex.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CFinalProject11Dlg dialog



CFinalProject11Dlg::CFinalProject11Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_FINALPROJECT11_DIALOG, pParent)
	, Drag(FALSE)
{
	curColorBrush = RGB(0,0,0);
	curColorPen = RGB(0, 0, 0);
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

CFinalProject11Dlg::~CFinalProject11Dlg()
{
	figs.RemoveAll();
	temp.RemoveAll();
}

void CFinalProject11Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_MFCCOLORBUTTON3, m_Color1);
	DDX_Control(pDX, IDC_MFCCOLORBUTTON1, m_Color2);
	DDX_Check(pDX, IDC_CHECK1, Drag);
}

BEGIN_MESSAGE_MAP(CFinalProject11Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_RADIO1, &CFinalProject11Dlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &CFinalProject11Dlg::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_RADIO3, &CFinalProject11Dlg::OnBnClickedRadio3)
	ON_BN_CLICKED(IDC_RADIO4, &CFinalProject11Dlg::OnBnClickedRadio4)
	
ON_WM_MOUSEMOVE()
ON_WM_LBUTTONDOWN()
ON_WM_LBUTTONUP()

ON_BN_CLICKED(IDC_BUTTON1, &CFinalProject11Dlg::OnBnClickedButton1)
ON_BN_CLICKED(IDC_BUTTON2, &CFinalProject11Dlg::OnBnClickedButton2)
ON_BN_CLICKED(IDC_BUTTON3, &CFinalProject11Dlg::OnBnClickedButton3)
ON_BN_CLICKED(IDC_BUTTON4, &CFinalProject11Dlg::OnBnClickedButton4)
ON_WM_CTLCOLOR()

ON_BN_CLICKED(IDC_MFCCOLORBUTTON3, &CFinalProject11Dlg::OnBnClickedMfccolorbutton3)
ON_BN_CLICKED(IDC_MFCCOLORBUTTON1, &CFinalProject11Dlg::OnBnClickedMfccolorbutton1)
ON_BN_CLICKED(IDC_CHECK1, &CFinalProject11Dlg::OnBnClickedCheck1)
ON_BN_CLICKED(IDC_BUTTON5, &CFinalProject11Dlg::OnBnClickedButton5)

ON_BN_CLICKED(IDC_RADIO5, &CFinalProject11Dlg::OnBnClickedRadio5)
ON_BN_CLICKED(IDC_BUTTON6, &CFinalProject11Dlg::OnBnClickedButton6)
END_MESSAGE_MAP()


// CFinalProject11Dlg message handlers

BOOL CFinalProject11Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);// Set small icon
	
	CBitmap bmpSave;
	bmpSave.LoadBitmap(IDB_BITMAP1);//save icon button
	CButton* pButtonSave = (CButton*)GetDlgItem(IDC_BUTTON1);
	pButtonSave->ModifyStyle(0, BS_BITMAP);
	pButtonSave->SetBitmap(bmpSave);

	CBitmap bmpLoad;
	bmpLoad.LoadBitmap(IDB_BITMAP2);//load icon button
	CButton* pButtonLoad = (CButton*)GetDlgItem(IDC_BUTTON2);
	pButtonLoad->ModifyStyle(0, BS_BITMAP);
	pButtonLoad->SetBitmap(bmpLoad);

	CBitmap bmpRedo;
	bmpRedo.LoadBitmap(IDB_BITMAP4);//redo icon button
	CButton* pButtonRedo = (CButton*)GetDlgItem(IDC_BUTTON3);
	pButtonRedo->ModifyStyle(0, BS_BITMAP);
	pButtonRedo->SetBitmap(bmpRedo);

	CBitmap bmpUndo;
	bmpUndo.LoadBitmap(IDB_BITMAP3);//undo icon button
	CButton* pButtonUndo = (CButton*)GetDlgItem(IDC_BUTTON4);
	pButtonUndo->ModifyStyle(0, BS_BITMAP);
	pButtonUndo->SetBitmap(bmpUndo);

	CBitmap bmpRandom;
	bmpRandom.LoadBitmap(IDB_BITMAP5);//random icon button
	CButton* pButtonRandom = (CButton*)GetDlgItem(IDC_BUTTON5);
	pButtonRandom->ModifyStyle(0, BS_BITMAP);
	pButtonRandom->SetBitmap(bmpRandom);

	CBitmap bmpNew;
	bmpNew.LoadBitmap(IDB_BITMAP6);//new icon button
	CButton* pButtonNew = (CButton*)GetDlgItem(IDC_BUTTON6);
	pButtonNew->ModifyStyle(0, BS_BITMAP);
	pButtonNew->SetBitmap(bmpNew);

	// TODO: Add extra initialization here
	CheckRadioButton(IDC_RADIO1, IDC_RADIO4, IDC_RADIO1);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CFinalProject11Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CFinalProject11Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
		
	}
	else
	{
		CPaintDC dc(this); // device context for painting
		for (int i = 0; i < figs.GetSize(); i++)
		{
			figs[i]->Draw(&dc);
		}

			CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CFinalProject11Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}




void CFinalProject11Dlg::OnBnClickedRadio1()//rectangle
{
	// TODO: Add your control notification handler code here
	futureFigureKind = 1;
}


void CFinalProject11Dlg::OnBnClickedRadio2()//line
{
	// TODO: Add your control notification handler code here
	futureFigureKind = 2;
}



void CFinalProject11Dlg::OnBnClickedRadio3()//cross
{
	// TODO: Add your control notification handler code here
	futureFigureKind = 3;
}


void CFinalProject11Dlg::OnBnClickedRadio4()//ellipse
{
	// TODO: Add your control notification handler code here
	futureFigureKind = 4;
}

void CFinalProject11Dlg::OnBnClickedRadio5()//pen
{
	// TODO: Add your control notification handler code here
	futureFigureKind = 5;
}




//2
void CFinalProject11Dlg::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	if (isPressed&&refill==false )
	{
		if (futureFigureKind == 5)
		{
			CClientDC dc(this);
			figs[figs.GetSize() - 1]->build(point);
			figs[figs.GetSize() - 1]->Draw(&dc);
		}
		else {


			CClientDC dc(this);
			dc.SetROP2(R2_NOTXORPEN);
			figs[figs.GetSize() - 1]->Draw(&dc);
			end = point;
			figs[figs.GetSize() - 1]->Redefine(start, end);
			figs[figs.GetSize() - 1]->Draw(&dc);
		}
		
	}
	
	CDialogEx::OnMouseMove(nFlags, point);
}


void CFinalProject11Dlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	start = point;
	isPressed = true;
	if (refill == false) {
		switch (futureFigureKind)
		{
		case 1:
			figs.Add(new CRectangle(start, start, curColorBrush, curColorPen));
			break;
		case 2:
			figs.Add(new Line(start, start, curColorPen));
			break;
		case 3:
			figs.Add(new Cross(start, start, curColorPen));
			break;
		case 4:
			figs.Add(new CEllipse(start, start, curColorBrush, curColorPen));
			break;
		case 5:
			figs.Add(new Pen(start, start, curColorPen));
			break;
		}
	}
	else if(!figs.IsEmpty())
	{
		ShapePressed = true;
		for (int i = figs.GetSize() - 1; i >= 0; i--)
		{
			if (figs[i]->isInside(point))
			{
				CPoint P1 = figs[i]->getP1();
				CPoint P2 = figs[i]->getP2();
				P1.x -= 1;
				P2.x += 1;
				P1.y -= 1;
				P2.y += 1;
				switch (figs[i]->getID())
				{
				case 1:
					figs.RemoveAt(i);
					figs.Add(new CRectangle(P1,P2, curColorBrush, curColorPen));
					break;
				case 2:
					figs.RemoveAt(i);
					figs.Add(new Line(P1, P2, curColorPen));
					break;
				case 3:
					figs.RemoveAt(i);
					figs.Add(new Cross(P1, P2, curColorPen));
					break;
				case 4:
					figs.RemoveAt(i);
					figs.Add(new CEllipse(P1, P2, curColorBrush, curColorPen));
					break;
				}
				 P1 = figs[figs.GetSize()-1]->getP1();
				 P2 = figs[figs.GetSize() - 1]->getP2();
				RECT r;
				r.left = (P1.x < P2.x) ? P1.x : P2.x;
				r.top = (P1.y < P2.y) ? P1.y : P2.y;
				r.right = (P1.x > P2.x) ? P1.x : P2.x;
				r.bottom = (P1.y > P2.y) ? P1.y : P2.y;
				InvalidateRect(&r);
				index = i;
				break;
			}
			
			
		}
	
	}
	
	CDialogEx::OnLButtonDown(nFlags, point);
}


void CFinalProject11Dlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	
	// TODO: Add your message handler code here and/or call default
	if (isPressed&&refill==FALSE)
	{
		end = point;
		isPressed = false;
		figs[figs.GetSize() - 1]->Redefine(start, end);
		
		RECT r;
		r.left = (start.x < end.x) ? start.x : end.x;
		r.top = (start.y < end.y) ? start.y : end.y;
		r.right = (start.x > end.x) ? start.x : end.x;
		r.bottom = (start.y > end.y) ? start.y : end.y;
		InvalidateRect(&r);
	}
	else if (isPressed && refill && ShapePressed)
	{
		ShapePressed = false;
		isPressed = false;
		CPoint P1 = figs[index]->getP1();
		CPoint P2 = figs[index]->getP2();
		RECT r;
		r.left = (P1.x < P2.x) ? P1.x : P2.x;
		r.top = (P1.y < P2.y) ? P1.y : P2.y;
		r.right = (P1.x > P2.x) ? P1.x : P2.x;
		r.bottom = (P1.y > P2.y) ? P1.y : P2.y;
		InvalidateRect(&r);
	}

	
	CDialogEx::OnLButtonUp(nFlags, point);
}


void CFinalProject11Dlg::OnBnClickedButton1()//save
{
	// TODO: Add your control notification handler code here
		
				 // FALSE to SAVE
	CFileDialog dlg(FALSE, _T(".fs"), NULL, 0, _T("Figures (*.figs)|*.figs|All Files (*.*)|*.*||"));
	CString filename;
	if (dlg.DoModal() == IDOK)
	{
		filename = dlg.GetPathName(); // return full path and filename
		CFile file(filename, CFile::modeCreate | CFile::modeWrite);
		CArchive ar(&file, CArchive::store);
		figs.Serialize(ar);
		ar.Close();
		file.Close();
	}
	
}


void CFinalProject11Dlg::OnBnClickedButton2()//load
{
	// TODO: Add your control notification handler code here
		
				 // TRUE to LOAD
	CFileDialog dlg(TRUE, _T(".figs"), NULL, 0, _T("Figures (*.figs)|*.figs|All Files (*.*)|*.*||"));
	CString filename;
	if (dlg.DoModal() == IDOK)
	{
		filename = dlg.GetPathName(); // return full path and filename
		CFile file(filename, CFile::modeRead);
		CArchive ar(&file, CArchive::load);
		figs.Serialize(ar);
		ar.Close();
		file.Close();
		Invalidate();
	}
	
}


void CFinalProject11Dlg::OnBnClickedButton3()//UNDO
{
	// TODO: Add your control notification handler code here
	if (figs.GetSize() != 0)
	{
		temp.Add(figs[figs.GetSize() - 1]);
		figs.RemoveAt(figs.GetSize() - 1);
		Invalidate();
	}
}

void CFinalProject11Dlg::OnBnClickedButton4()//REDO
{
	// TODO: Add your control notification handler code here
	if (temp.GetSize() != 0)
	{
		figs.InsertAt(figs.GetSize(), temp.GetAt(temp.GetSize() - 1));
		temp.RemoveAt(temp.GetSize() - 1);
		Invalidate();
	}
}


void CFinalProject11Dlg::OnBnClickedMfccolorbutton3()//brush color
{
	// TODO: Add your control notification handler code here
	curColorBrush = m_Color1.GetColor();
}


void CFinalProject11Dlg::OnBnClickedMfccolorbutton1()//pen color
{
	// TODO: Add your control notification handler code here
	curColorPen = m_Color2.GetColor();
}


void CFinalProject11Dlg::OnBnClickedCheck1()//refill
{
	// TODO: Add your control notification handler code here
	if (Drag) { refill = false; }
	else refill  = true;
}


void CFinalProject11Dlg::OnBnClickedButton5()//Random
{
	// TODO: Add your control notification handler code here
	srand(time(NULL));
	int id;
	int i = 0;
	int x, x1, y, y1, width, green, blue, red;
	x = rand() % 800 + 50;
	y = rand() % 470 + 80;
	x1 = rand() % 800 + 50;
	y1 = rand() % 420 + 86;
	id = rand() % 4 + 1;
	red = rand() % 254 + 1;
	green = rand() % 254 + 1;
	blue = rand() % 254 + 1;
	CPoint P1(x, y);
	CPoint P2(x1, y1);
	switch (id)
	{
	case 1:
		figs.Add(new CRectangle(P1, P2, RGB(blue, red, green), RGB(red, green, blue)));
		break;
	case 2:
		figs.Add(new Line(P1, P2, RGB(blue, red, green)));
		break;
	case 3:
		figs.Add(new Cross(P1, P2, RGB(blue, red, green)));
		break;
	case 4:
		figs.Add(new CEllipse(P1, P2, RGB(blue, red, green), RGB(red, green, blue)));
		break;
	}

	RECT r;
	r.left = (P1.x < P2.x) ? P1.x : P2.x;
	r.top = (P1.y < P2.y) ? P1.y : P2.y;
	r.right = (P1.x > P2.x) ? P1.x : P2.x;
	r.bottom = (P1.y > P2.y) ? P1.y : P2.y;
	InvalidateRect(&r);
	
}






void CFinalProject11Dlg::OnBnClickedButton6()//clear all
{
	// TODO: Add your control notification handler code here
	const int result = MessageBox((LPCWSTR)L"are you sure u want to clear all?", (LPCWSTR)L"Clear All", MB_YESNO);

	switch (result)
	{
	case IDYES:
		figs.RemoveAll();
		temp.RemoveAll();
		Invalidate();
		break;
	case IDNO:
		// Do nothing
		break;

	}
}
