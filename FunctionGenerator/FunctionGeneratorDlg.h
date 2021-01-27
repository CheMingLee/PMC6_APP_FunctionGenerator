// FunctionGeneratorDlg.h : 標頭檔
//

#pragma once
#include "afxwin.h"

// combo box LED define
#define CLOSELED					0
#define RED							1
#define YELLOW1						2 
#define YELLOW2						3
#define YELLOW3						4
#define ALLLED						5

// combo box Analog define
#define CLOSE_ANALOG				0
#define SINE_ANALOG					1
#define TRIANGE_ANALOG				2
#define SAWTOOTH_ANALOG				3

// CMD structure
typedef struct {
	unsigned int m_iChannel;
	int m_iflag;
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
typedef void (*importFuncDev)();
typedef unsigned int (*importFuncSetLED)(unsigned int);
typedef unsigned int (*importFuncGetLED)();
typedef void (*importFuncSetPWM)(unsigned short, CMD_PWM, int);
typedef void (*importFuncSetAnanlog)(unsigned short, CMD_ANALOG, int);
typedef float (*importFuncGetParamsfloat)(unsigned short, int);
typedef int (*importFuncGetParamsint)(unsigned short, int);

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
	importFuncDev InitialDev, CloseDev;
	importFuncSetLED SetLED;
	importFuncGetLED GetLED;
	importFuncSetPWM SetPWM;
	importFuncSetAnanlog SetAnalog;
	importFuncGetParamsfloat GetParam_float;
	importFuncGetParamsint GetParam_int;
	CComboBox m_cbLedStatus, m_cbFuncType_1, m_cbFuncType_2;
	CString m_strLedStatus;
	CMD_PWM m_CmdDataPWM;
	CMD_ANALOG m_CmdDataAnal;
	unsigned int m_uiSetLED;
	int m_iPWM_flag[32];
	float m_fPWM_Freq[32], m_fPWM_Duty[32], m_fPWM_Delay[32];
	int m_iFuncType[2];
	float m_fAnal_Freq[2], m_fAnal_Amp[2], m_fAnal_Ratio[2], m_fAnal_Delay[2];
	BOOL IsWow64();
	void DllLoader();
	void GetLEDstatus();
	void GetParamsInit();
	void SetPWMflag();
	void SetDigitalParams(unsigned short usCmd, int iCH);
	void SetAnalParams(unsigned short usCmd, int iCH);
	void SetRatioEdit(int iCbCurSel, int iCH);
	afx_msg void OnDestroy();
	afx_msg void OnBnClickedButtonSetLED();
	afx_msg void OnBnClickedButtonSetOutputEx();
	afx_msg void OnBnClickedButtonSetOutput();
	afx_msg void OnBnClickedButtonSetOutAnalog1();
	afx_msg void OnBnClickedButtonSetOutAnalog2();
	afx_msg void OnCbnSelchangeComboFunctionType1();
	afx_msg void OnCbnSelchangeComboFunctionType2();
	CButton m_ckCH1;
	CButton m_ckCH2;
	CButton m_ckCH3;
	CButton m_ckCH4;
	CButton m_ckCH5;
	CButton m_ckCH6;
	CButton m_ckCH7;
	CButton m_ckCH8;
	CButton m_ckCH9;
	CButton m_ckCH10;
	CButton m_ckCH11;
	CButton m_ckCH12;
	CButton m_ckCH13;
	CButton m_ckCH14;
	CButton m_ckCH15;
	CButton m_ckCH16;
	CButton m_ckCH17;
	CButton m_ckCH18;
	CButton m_ckCH19;
	CButton m_ckCH20;
	CButton m_ckCH21;
	CButton m_ckCH22;
	CButton m_ckCH23;
	CButton m_ckCH24;
	CButton m_ckCH25;
	CButton m_ckCH26;
	CButton m_ckCH27;
	CButton m_ckCH28;
	CButton m_ckCH29;
	CButton m_ckCH30;
	CButton m_ckCH31;
	CButton m_ckCH32;
};
