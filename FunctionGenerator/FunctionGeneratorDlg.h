// FunctionGeneratorDlg.h : 標頭檔
//

#pragma once
#include "afxwin.h"

// combo box define
#define CLOSELED 0
#define RED 1
#define YELLOW1 2 
#define YELLOW2 3
#define YELLOW3 4
#define ALLLED 5

// DLL function signature
typedef void (*importFunctionDev)();
typedef unsigned int (*importFunctionSet)(unsigned int);

// CFunctionGeneratorDlg 對話方塊
class CFunctionGeneratorDlg : public CDialog
{
// 建構
public:
	CFunctionGeneratorDlg(CWnd* pParent = NULL);	// 標準建構函式

// 對話方塊資料
	enum { IDD = IDD_FUNCTIONGENERATOR_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支援


// 程式碼實作
protected:
	HICON m_hIcon;

	// 產生的訊息對應函式
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	HINSTANCE m_hinstLib;
	importFunctionDev InitialDev, CloseDev;
	importFunctionSet SetLED;
	CComboBox m_cbLedStatus;
	CString m_strLedStatus;
	unsigned int m_uiSetLED;
	BOOL IsWow64();
	void DllLoader();
	afx_msg void OnBnClickedButtonSetLED();
	afx_msg void OnDestroy();
};
