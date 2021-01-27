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
	int m_iChannel;
	int m_iflag;
	float m_fFreq;
	float m_fDuty;
	float m_fDelay;
}CMD_PWM;

typedef struct {
	int m_iChannel;
	int m_iFunction;
	float m_fFreq;
	float m_fAmp;
	float m_fRatio;
	float m_fDelay;
}CMD_ANALOG;

// DLL function signature
typedef void (*FuncDev)();
typedef unsigned int (*FuncSetLED)(unsigned int);
typedef void (*FuncSetPWM)(CMD_PWM, int);
typedef void (*FuncSetAnanlog)(CMD_ANALOG, int);
typedef void (*FuncStart)();
typedef unsigned int (*FuncGetLED)();
typedef void (*FuncGetPWM)(CMD_PWM *, int);
typedef void (*FuncGetAnalog)(CMD_ANALOG *, int);
typedef void (*FuncGetRunTime)(double *);

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
	FuncDev InitialDev, CloseDev;
	FuncSetLED SetLED;
	FuncSetPWM SetPWM;
	FuncSetAnanlog SetAnalog;
	FuncStart SetStart, SetStop;
	FuncGetLED GetLED;
	FuncGetPWM GetParamPWM;
	FuncGetAnalog GetParamAnalog;
	FuncGetRunTime GetRunTime;
	CComboBox m_cbLedStatus, m_cbFuncType_1, m_cbFuncType_2;
	CString m_strLedStatus, m_strRunTime;
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
	void SetDigitalParams(int iCH);
	void SetAnalParams(int iCH);
	void SetRatioEdit(int iCbCurSel, int iCH);
	afx_msg void OnDestroy();
	afx_msg void OnBnClickedButtonSetLED();
	afx_msg void OnBnClickedButtonStart();
	afx_msg void OnBnClickedButtonStop();
	afx_msg void OnBnClickedButtonSetPWM();
	afx_msg void OnBnClickedButtonSetOutAnalog();
	afx_msg void OnBnClickedButtonGetruntime();
	afx_msg void OnCbnSelchangeComboFunctionType1();
	afx_msg void OnCbnSelchangeComboFunctionType2();
	CButton m_ckCH1, m_ckCH2, m_ckCH3, m_ckCH4, m_ckCH5, m_ckCH6, m_ckCH7, m_ckCH8, m_ckCH9, m_ckCH10;
	CButton m_ckCH11, m_ckCH12, m_ckCH13, m_ckCH14, m_ckCH15, m_ckCH16, m_ckCH17, m_ckCH18, m_ckCH19, m_ckCH20;
	CButton m_ckCH21, m_ckCH22, m_ckCH23, m_ckCH24, m_ckCH25, m_ckCH26, m_ckCH27, m_ckCH28, m_ckCH29, m_ckCH30, m_ckCH31, m_ckCH32;
};
