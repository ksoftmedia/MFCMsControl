
// ComboBoxExDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "ComboBoxEx.h"
#include "ComboBoxExDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CComboBoxExDlg dialog



CComboBoxExDlg::CComboBoxExDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_COMBOBOXEX_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CComboBoxExDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBOBOXEX_ICO, comboBoxExICO);
	DDX_Control(pDX, IDC_COMBOBOXEX_PNG, comboBoxExPNG);
	DDX_Control(pDX, IDC_COMBOBOXEX_BMP, comboBoxExBMP);
}

BEGIN_MESSAGE_MAP(CComboBoxExDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_CBN_SELCHANGE(IDC_COMBOBOXEX_ICO, &CComboBoxExDlg::OnCbnSelchangeComboboxexIco)
	ON_CBN_SELCHANGE(IDC_COMBOBOXEX_PNG, &CComboBoxExDlg::OnCbnSelchangeComboboxexPng)
	ON_CBN_SELCHANGE(IDC_COMBOBOXEX_BMP, &CComboBoxExDlg::OnCbnSelchangeComboboxexBmp)
END_MESSAGE_MAP()


// CComboBoxExDlg message handlers

void CComboBoxExDlg::InitComboBoxExICO()
{
	imageListICO.Create(24, 24, ILC_COLOR32, 9, 2);
	imageListICO.Add(AfxGetApp()->LoadIcon(IDI_ICON_FACEBOOK));
	imageListICO.Add(AfxGetApp()->LoadIcon(IDI_ICON_INSTAGRAM));
	imageListICO.Add(AfxGetApp()->LoadIcon(IDI_ICON_LINE));
	imageListICO.Add(AfxGetApp()->LoadIcon(IDI_ICON_LINKEDIN));
	imageListICO.Add(AfxGetApp()->LoadIcon(IDI_ICON_PINTEREST));
	imageListICO.Add(AfxGetApp()->LoadIcon(IDI_ICON_SKYPE));
	imageListICO.Add(AfxGetApp()->LoadIcon(IDI_ICON_TWITTER));
	imageListICO.Add(AfxGetApp()->LoadIcon(IDI_ICON_VIBER));
	imageListICO.Add(AfxGetApp()->LoadIcon(IDI_ICON_YOUTUBE));
	comboBoxExICO.SetImageList(&imageListICO);
	comboBoxExICO.SetItemHeight(-1, 24);

	TCHAR *itemText[] = {_T("facebook"),
						 _T("instagram"),
						 _T("line"),
						 _T("linkedin"),
						 _T("pinterest"),
						 _T("skype"),
						 _T("twitter"),
						 _T("viber"),
						 _T("youtube")};

	int count = imageListICO.GetImageCount();
	for (int i = 0; i < count; i++)
	{
		COMBOBOXEXITEM cbei = { 0 };
		cbei.mask = CBEIF_IMAGE | CBEIF_SELECTEDIMAGE | CBEIF_TEXT;
		cbei.iItem = i;
		cbei.pszText = itemText[i];
		cbei.iImage = i;
		cbei.iSelectedImage = i;
		comboBoxExICO.InsertItem(&cbei);
	}

	comboBoxExICO.SetCurSel(0);
}

void CComboBoxExDlg::InitComboBoxExPNG()
{
	CPngImage png;
	png.Load(IDB_PNG);
	CBitmap bmp;
	bmp.Attach(png.Detach());
	imageListPNG.Create(24, 24, ILC_COLOR32 | ILC_MASK, 4, 4);
	imageListPNG.Add(&bmp, CLR_NONE);
	comboBoxExPNG.SetImageList(&imageListPNG);
	comboBoxExPNG.SetItemHeight(-1, 24);

	TCHAR* itemText[] = { _T("facebook"),
						 _T("instagram"),
						 _T("line"),
						 _T("linkedin"),
						 _T("pinterest"),
						 _T("skype"),
						 _T("twitter"),
						 _T("viber"),
						 _T("youtube") };

	int count = imageListPNG.GetImageCount();
	for (int i = 0; i < count; i++)
	{
		COMBOBOXEXITEM cbei = { 0 };
		cbei.mask = CBEIF_IMAGE | CBEIF_SELECTEDIMAGE | CBEIF_TEXT;
		cbei.iItem = i;
		cbei.pszText = itemText[i];
		cbei.iImage = i;
		cbei.iSelectedImage = i;
		comboBoxExPNG.InsertItem(&cbei);
	}

	comboBoxExPNG.SetCurSel(0);
}

void CComboBoxExDlg::InitComboBoxExBMP()
{
	CBitmap bmp;
	bmp.LoadBitmap(IDB_BITMAP);
	imageListBMP.Create(24, 24, ILC_COLOR32 | ILC_MASK, 4, 4);
	imageListBMP.Add(&bmp, CLR_NONE);
	comboBoxExBMP.SetImageList(&imageListBMP);
	comboBoxExBMP.SetItemHeight(-1, 24);

	TCHAR* itemText[] = { _T("facebook"),
						 _T("instagram"),
						 _T("line"),
						 _T("linkedin"),
						 _T("pinterest"),
						 _T("skype"),
						 _T("twitter"),
						 _T("viber"),
						 _T("youtube") };

	int count = imageListBMP.GetImageCount();
	for (int i = 0; i < count; i++)
	{
		COMBOBOXEXITEM cbei = { 0 };
		cbei.mask = CBEIF_IMAGE | CBEIF_SELECTEDIMAGE | CBEIF_TEXT;
		cbei.iItem = i;
		cbei.pszText = itemText[i];
		cbei.iImage = i;
		cbei.iSelectedImage = i;
		comboBoxExBMP.InsertItem(&cbei);
	}

	comboBoxExBMP.SetCurSel(0);
}

BOOL CComboBoxExDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	InitComboBoxExICO();
	InitComboBoxExPNG();
	InitComboBoxExBMP();

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CComboBoxExDlg::OnPaint()
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
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CComboBoxExDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CComboBoxExDlg::OnCbnSelchangeComboboxexIco()
{
	TRACE(_T("index = %d\n"), comboBoxExICO.GetCurSel());
}


void CComboBoxExDlg::OnCbnSelchangeComboboxexPng()
{
	TRACE(_T("index = %d\n"), comboBoxExPNG.GetCurSel());
}


void CComboBoxExDlg::OnCbnSelchangeComboboxexBmp()
{
	TRACE(_T("index = %d\n"), comboBoxExBMP.GetCurSel());
}
