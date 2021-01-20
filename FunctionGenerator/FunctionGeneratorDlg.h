// FunctionGeneratorDlg.h : 標頭檔
//

#pragma once
#include "afxwin.h"

// combo box define
#define CLOSELED			0
#define RED					1
#define YELLOW1				2 
#define YELLOW2				3
#define YELLOW3				4
#define ALLLED				5
#define CLOSE_ANALOG		0
#define SINE_ANALOG			1
#define TRIANGE_ANALOG		2
#define SAWTOOTH_ANALOG		3

// CMD structure
typedef struct {
	unsigned int m_iChannel;
	float m_fFreq;
	float m_fDuty;
	float m_fDelay;
}CMD_PWM;

typedef struct {
	int m_iFunction;
	float m_fFreq;
	float m_fAmp;
	float m_fRatio;
	float m_fDelay;
}CMD_ANALOG;

// DLL function signature
typedef void (*importFunctionDev)();
typedef void (*importFunctionSetPWM)(CMD_PWM);
typedef void (*importFunctionSetAnanlog)(CMD_ANALOG);
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
	importFunctionSetPWM SetPWM_JF8, SetPWM_JF7;
	importFunctionSetAnanlog SetAnalog_1, SetAnalog_2;
	CComboBox m_cbLedStatus, m_cbFuncType_1, m_cbFuncType_2;
	CString m_strLedStatus;
	unsigned int m_uiSetLED;
	float m_fJF7_Freq[16], m_fJF7_Duty[16], m_fJF7_Delay[16];
	float m_fJF8_Freq[16], m_fJF8_Duty[16], m_fJF8_Delay[16];
	float m_fAnal_Freq[2], m_fAnal_Amp[2], m_fAnal_Ratio[2], m_fAnal_Delay[2];
	BOOL IsWow64();
	void DllLoader();
	float* SetDigitalParams(float fFreq, float fDuty, float fDelay);
	float* SetAnalParams(float fFreq, float fAmp, float fRatio, float fDelay);
	void SetAnalog(int iChannel);
	void SetRatioEdit(int iCbCurSel, int iCH);
	afx_msg void OnDestroy();
	afx_msg void OnBnClickedButtonSetLED();
	afx_msg void OnBnClickedButtonSetOutputEx();
	afx_msg void OnBnClickedButtonSetOutput();
	afx_msg void OnBnClickedButtonSetOutAnalog1();
	afx_msg void OnBnClickedButtonSetOutAnalog2();
	afx_msg void OnCbnSelchangeComboFunctionType1();
	afx_msg void OnCbnSelchangeComboFunctionType2();
};
