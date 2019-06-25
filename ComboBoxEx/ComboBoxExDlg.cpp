
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
	DDX_Control(pDX, IDC_COMBOBOXEX, comboBoxEx);
}

BEGIN_MESSAGE_MAP(CComboBoxExDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_CBN_SELCHANGE(IDC_COMBOBOXEX, &CComboBoxExDlg::OnCbnSelchangeComboboxex)
END_MESSAGE_MAP()


// CComboBoxExDlg message handlers

void CComboBoxExDlg::InitComboBoxEx()
{
	imageList.Create(20, 23, ILC_COLOR32, 9, 2);
	imageList.Add(AfxGetApp()->LoadIcon(IDI_ICON_FACEBOOK));
	imageList.Add(AfxGetApp()->LoadIcon(IDI_ICON_INSTAGRAM));
	imageList.Add(AfxGetApp()->LoadIcon(IDI_ICON_LINE));
	imageList.Add(AfxGetApp()->LoadIcon(IDI_ICON_LINKEDIN));
	imageList.Add(AfxGetApp()->LoadIcon(IDI_ICON_PINTEREST));
	imageList.Add(AfxGetApp()->LoadIcon(IDI_ICON_SKYPE));
	imageList.Add(AfxGetApp()->LoadIcon(IDI_ICON_TWITTER));
	imageList.Add(AfxGetApp()->LoadIcon(IDI_ICON_VIBER));
	imageList.Add(AfxGetApp()->LoadIcon(IDI_ICON_YOUTUBE));
	comboBoxEx.SetImageList(&imageList);

	TCHAR *itemText[] = {_T("facebook"),
						 _T("instagram"),
						 _T("line"),
						 _T("linkedin"),
						 _T("pinterest"),
						 _T("skype"),
						 _T("twitter"),
						 _T("viber"),
						 _T("youtube")};

	for (size_t i = 0; i < imageList.GetImageCount(); i++)
	{
		COMBOBOXEXITEM cbei = { 0 };
		cbei.mask = CBEIF_IMAGE | CBEIF_SELECTEDIMAGE | CBEIF_TEXT;
		cbei.iItem = i;
		cbei.pszText = itemText[i];
		cbei.iImage = i;
		cbei.iSelectedImage = i;
		comboBoxEx.InsertItem(&cbei);
	}

	comboBoxEx.SetCurSel(0);
	comboBoxEx.SetItemHeight(-1, 20);
}

BOOL CComboBoxExDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	InitComboBoxEx();

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



void CComboBoxExDlg::OnCbnSelchangeComboboxex()
{
	TRACE(_T("index = %d\n"), comboBoxEx.GetCurSel());
}
