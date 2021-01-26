// FunctionGeneratorDlg.h : ���Y��
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
typedef void (*importFuncDev)();
typedef unsigned int (*importFuncSetLED)(unsigned int);
typedef void (*importFuncSetPWM)(CMD_PWM, int);
typedef void (*importFuncSetAnanlog)(CMD_ANALOG, int);
typedef unsigned int (*importFuncGetLED)();
typedef float (*importFuncGetParams)(int);

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
	importFuncDev InitialDev, CloseDev;
	importFuncSetLED SetLED;
	importFuncSetPWM SetPWM;
	importFuncSetAnanlog SetAnalog;
	importFuncGetLED GetLED;
	importFuncGetParams GetDigital_Freq;
	CComboBox m_cbLedStatus, m_cbFuncType_1, m_cbFuncType_2;
	CString m_strLedStatus;
	CMD_PWM m_CmdDataPWM;
	CMD_ANALOG m_CmdDataAnal;
	unsigned int m_uiSetLED;
	float m_fPWM_Freq[32], m_fPWM_Duty[32], m_fPWM_Delay[32];
	int m_iFuncType[2];
	float m_fAnal_Freq[2], m_fAnal_Amp[2], m_fAnal_Ratio[2], m_fAnal_Delay[2];
	BOOL IsWow64();
	void DllLoader();
	void GetLEDstatus();
	void GetDigitalFreqInit();
	void SetDigitalParams(int iCH);
	void SetAnalParams(int iCH);
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
