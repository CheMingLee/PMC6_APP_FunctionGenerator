// FunctionGeneratorDlg.h : ���Y��
//

#pragma once

// DLL function signature
typedef void (*importFunctionDev)();
typedef void (*importFunctionSet)(unsigned int);

// CFunctionGeneratorDlg ��ܤ��
class CFunctionGeneratorDlg : public CDialog
{
// �غc
public:
	CFunctionGeneratorDlg(CWnd* pParent = NULL);	// �зǫغc�禡

// ��ܤ�����
	enum { IDD = IDD_FUNCTIONGENERATOR_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �䴩


// �{���X��@
protected:
	HICON m_hIcon;

	// ���ͪ��T�������禡
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	HINSTANCE m_hinstLib;
	importFunctionDev InitialDev, CloseDev;
	importFunctionSet SetLED;
	unsigned int m_uiSetLED;
	BOOL IsWow64();
	void DllLoader();
	afx_msg void OnBnClickedButtonStart();
	afx_msg void OnDestroy();
};
