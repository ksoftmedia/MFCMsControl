
// ComboBoxExDlg.h : header file
//

#pragma once


// CComboBoxExDlg dialog
class CComboBoxExDlg : public CDialogEx
{
// Construction
public:
	CComboBoxExDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_COMBOBOXEX_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation

private:
	void InitComboBoxExICO();
	void InitComboBoxExPNG();
	void InitComboBoxExBMP();
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CComboBoxEx comboBoxExICO;
	CImageList imageListICO;
	CComboBoxEx comboBoxExPNG;
	CImageList imageListPNG;
	CComboBoxEx comboBoxExBMP;
	CImageList imageListBMP;
	afx_msg void OnCbnSelchangeComboboxexIco();
	afx_msg void OnCbnSelchangeComboboxexPng();
	afx_msg void OnCbnSelchangeComboboxexBmp();
};
