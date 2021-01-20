// FunctionGeneratorDlg.cpp : 實作檔
//

#include "stdafx.h"
#include "FunctionGenerator.h"
#include "FunctionGeneratorDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

typedef BOOL (WINAPI *LPFN_ISWOW64PROCESS) (HANDLE, PBOOL);
LPFN_ISWOW64PROCESS fnIsWow64Process;

// 對 App About 使用 CAboutDlg 對話方塊

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// 對話方塊資料
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支援

// 程式碼實作
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()

// CFunctionGeneratorDlg 對話方塊

CFunctionGeneratorDlg::CFunctionGeneratorDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CFunctionGeneratorDlg::IDD, pParent)

{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CFunctionGeneratorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_JF8_CH1_FREQ, m_fJF8_Freq[0]);
	DDX_Text(pDX, IDC_EDIT_JF8_CH2_FREQ, m_fJF8_Freq[1]);
	DDX_Text(pDX, IDC_EDIT_JF8_CH3_FREQ, m_fJF8_Freq[2]);
	DDX_Text(pDX, IDC_EDIT_JF8_CH4_FREQ, m_fJF8_Freq[3]);
	DDX_Text(pDX, IDC_EDIT_JF8_CH5_FREQ, m_fJF8_Freq[4]);
	DDX_Text(pDX, IDC_EDIT_JF8_CH6_FREQ, m_fJF8_Freq[5]);
	DDX_Text(pDX, IDC_EDIT_JF8_CH7_FREQ, m_fJF8_Freq[6]);
	DDX_Text(pDX, IDC_EDIT_JF8_CH8_FREQ, m_fJF8_Freq[7]);
	DDX_Text(pDX, IDC_EDIT_JF8_CH9_FREQ, m_fJF8_Freq[8]);
	DDX_Text(pDX, IDC_EDIT_JF8_CH10_FREQ, m_fJF8_Freq[9]);
	DDX_Text(pDX, IDC_EDIT_JF8_CH11_FREQ, m_fJF8_Freq[10]);
	DDX_Text(pDX, IDC_EDIT_JF8_CH12_FREQ, m_fJF8_Freq[11]);
	DDX_Text(pDX, IDC_EDIT_JF8_CH13_FREQ, m_fJF8_Freq[12]);
	DDX_Text(pDX, IDC_EDIT_JF8_CH14_FREQ, m_fJF8_Freq[13]);
	DDX_Text(pDX, IDC_EDIT_JF8_CH15_FREQ, m_fJF8_Freq[14]);
	DDX_Text(pDX, IDC_EDIT_JF8_CH16_FREQ, m_fJF8_Freq[15]);
	DDX_Text(pDX, IDC_EDIT_JF8_CH1_DUTY, m_fJF8_Duty[0]);
	DDX_Text(pDX, IDC_EDIT_JF8_CH2_DUTY, m_fJF8_Duty[1]);
	DDX_Text(pDX, IDC_EDIT_JF8_CH3_DUTY, m_fJF8_Duty[2]);
	DDX_Text(pDX, IDC_EDIT_JF8_CH4_DUTY, m_fJF8_Duty[3]);
	DDX_Text(pDX, IDC_EDIT_JF8_CH5_DUTY, m_fJF8_Duty[4]);
	DDX_Text(pDX, IDC_EDIT_JF8_CH6_DUTY, m_fJF8_Duty[5]);
	DDX_Text(pDX, IDC_EDIT_JF8_CH7_DUTY, m_fJF8_Duty[6]);
	DDX_Text(pDX, IDC_EDIT_JF8_CH8_DUTY, m_fJF8_Duty[7]);
	DDX_Text(pDX, IDC_EDIT_JF8_CH9_DUTY, m_fJF8_Duty[8]);
	DDX_Text(pDX, IDC_EDIT_JF8_CH10_DUTY, m_fJF8_Duty[9]);
	DDX_Text(pDX, IDC_EDIT_JF8_CH11_DUTY, m_fJF8_Duty[10]);
	DDX_Text(pDX, IDC_EDIT_JF8_CH12_DUTY, m_fJF8_Duty[11]);
	DDX_Text(pDX, IDC_EDIT_JF8_CH13_DUTY, m_fJF8_Duty[12]);
	DDX_Text(pDX, IDC_EDIT_JF8_CH14_DUTY, m_fJF8_Duty[13]);
	DDX_Text(pDX, IDC_EDIT_JF8_CH15_DUTY, m_fJF8_Duty[14]);
	DDX_Text(pDX, IDC_EDIT_JF8_CH16_DUTY, m_fJF8_Duty[15]);
	DDX_Text(pDX, IDC_EDIT_JF8_CH1_DELAY, m_fJF8_Delay[0]);
	DDX_Text(pDX, IDC_EDIT_JF8_CH2_DELAY, m_fJF8_Delay[1]);
	DDX_Text(pDX, IDC_EDIT_JF8_CH3_DELAY, m_fJF8_Delay[2]);
	DDX_Text(pDX, IDC_EDIT_JF8_CH4_DELAY, m_fJF8_Delay[3]);
	DDX_Text(pDX, IDC_EDIT_JF8_CH5_DELAY, m_fJF8_Delay[4]);
	DDX_Text(pDX, IDC_EDIT_JF8_CH6_DELAY, m_fJF8_Delay[5]);
	DDX_Text(pDX, IDC_EDIT_JF8_CH7_DELAY, m_fJF8_Delay[6]);
	DDX_Text(pDX, IDC_EDIT_JF8_CH8_DELAY, m_fJF8_Delay[7]);
	DDX_Text(pDX, IDC_EDIT_JF8_CH9_DELAY, m_fJF8_Delay[8]);
	DDX_Text(pDX, IDC_EDIT_JF8_CH10_DELAY, m_fJF8_Delay[9]);
	DDX_Text(pDX, IDC_EDIT_JF8_CH11_DELAY, m_fJF8_Delay[10]);
	DDX_Text(pDX, IDC_EDIT_JF8_CH12_DELAY, m_fJF8_Delay[11]);
	DDX_Text(pDX, IDC_EDIT_JF8_CH13_DELAY, m_fJF8_Delay[12]);
	DDX_Text(pDX, IDC_EDIT_JF8_CH14_DELAY, m_fJF8_Delay[13]);
	DDX_Text(pDX, IDC_EDIT_JF8_CH15_DELAY, m_fJF8_Delay[14]);
	DDX_Text(pDX, IDC_EDIT_JF8_CH16_DELAY, m_fJF8_Delay[15]);
	DDX_Text(pDX, IDC_EDIT_JF7_CH1_FREQ, m_fJF7_Freq[0]);
	DDX_Text(pDX, IDC_EDIT_JF7_CH2_FREQ, m_fJF7_Freq[1]);
	DDX_Text(pDX, IDC_EDIT_JF7_CH3_FREQ, m_fJF7_Freq[2]);
	DDX_Text(pDX, IDC_EDIT_JF7_CH4_FREQ, m_fJF7_Freq[3]);
	DDX_Text(pDX, IDC_EDIT_JF7_CH5_FREQ, m_fJF7_Freq[4]);
	DDX_Text(pDX, IDC_EDIT_JF7_CH6_FREQ, m_fJF7_Freq[5]);
	DDX_Text(pDX, IDC_EDIT_JF7_CH7_FREQ, m_fJF7_Freq[6]);
	DDX_Text(pDX, IDC_EDIT_JF7_CH8_FREQ, m_fJF7_Freq[7]);
	DDX_Text(pDX, IDC_EDIT_JF7_CH9_FREQ, m_fJF7_Freq[8]);
	DDX_Text(pDX, IDC_EDIT_JF7_CH10_FREQ, m_fJF7_Freq[9]);
	DDX_Text(pDX, IDC_EDIT_JF7_CH11_FREQ, m_fJF7_Freq[10]);
	DDX_Text(pDX, IDC_EDIT_JF7_CH12_FREQ, m_fJF7_Freq[11]);
	DDX_Text(pDX, IDC_EDIT_JF7_CH13_FREQ, m_fJF7_Freq[12]);
	DDX_Text(pDX, IDC_EDIT_JF7_CH14_FREQ, m_fJF7_Freq[13]);
	DDX_Text(pDX, IDC_EDIT_JF7_CH15_FREQ, m_fJF7_Freq[14]);
	DDX_Text(pDX, IDC_EDIT_JF7_CH16_FREQ, m_fJF7_Freq[15]);
	DDX_Text(pDX, IDC_EDIT_JF7_CH1_DUTY, m_fJF7_Duty[0]);
	DDX_Text(pDX, IDC_EDIT_JF7_CH2_DUTY, m_fJF7_Duty[1]);
	DDX_Text(pDX, IDC_EDIT_JF7_CH3_DUTY, m_fJF7_Duty[2]);
	DDX_Text(pDX, IDC_EDIT_JF7_CH4_DUTY, m_fJF7_Duty[3]);
	DDX_Text(pDX, IDC_EDIT_JF7_CH5_DUTY, m_fJF7_Duty[4]);
	DDX_Text(pDX, IDC_EDIT_JF7_CH6_DUTY, m_fJF7_Duty[5]);
	DDX_Text(pDX, IDC_EDIT_JF7_CH7_DUTY, m_fJF7_Duty[6]);
	DDX_Text(pDX, IDC_EDIT_JF7_CH8_DUTY, m_fJF7_Duty[7]);
	DDX_Text(pDX, IDC_EDIT_JF7_CH9_DUTY, m_fJF7_Duty[8]);
	DDX_Text(pDX, IDC_EDIT_JF7_CH10_DUTY, m_fJF7_Duty[9]);
	DDX_Text(pDX, IDC_EDIT_JF7_CH11_DUTY, m_fJF7_Duty[10]);
	DDX_Text(pDX, IDC_EDIT_JF7_CH12_DUTY, m_fJF7_Duty[11]);
	DDX_Text(pDX, IDC_EDIT_JF7_CH13_DUTY, m_fJF7_Duty[12]);
	DDX_Text(pDX, IDC_EDIT_JF7_CH14_DUTY, m_fJF7_Duty[13]);
	DDX_Text(pDX, IDC_EDIT_JF7_CH15_DUTY, m_fJF7_Duty[14]);
	DDX_Text(pDX, IDC_EDIT_JF7_CH16_DUTY, m_fJF7_Duty[15]);
	DDX_Text(pDX, IDC_EDIT_JF7_CH1_DELAY, m_fJF7_Delay[0]);
	DDX_Text(pDX, IDC_EDIT_JF7_CH2_DELAY, m_fJF7_Delay[1]);
	DDX_Text(pDX, IDC_EDIT_JF7_CH3_DELAY, m_fJF7_Delay[2]);
	DDX_Text(pDX, IDC_EDIT_JF7_CH4_DELAY, m_fJF7_Delay[3]);
	DDX_Text(pDX, IDC_EDIT_JF7_CH5_DELAY, m_fJF7_Delay[4]);
	DDX_Text(pDX, IDC_EDIT_JF7_CH6_DELAY, m_fJF7_Delay[5]);
	DDX_Text(pDX, IDC_EDIT_JF7_CH7_DELAY, m_fJF7_Delay[6]);
	DDX_Text(pDX, IDC_EDIT_JF7_CH8_DELAY, m_fJF7_Delay[7]);
	DDX_Text(pDX, IDC_EDIT_JF7_CH9_DELAY, m_fJF7_Delay[8]);
	DDX_Text(pDX, IDC_EDIT_JF7_CH10_DELAY, m_fJF7_Delay[9]);
	DDX_Text(pDX, IDC_EDIT_JF7_CH11_DELAY, m_fJF7_Delay[10]);
	DDX_Text(pDX, IDC_EDIT_JF7_CH12_DELAY, m_fJF7_Delay[11]);
	DDX_Text(pDX, IDC_EDIT_JF7_CH13_DELAY, m_fJF7_Delay[12]);
	DDX_Text(pDX, IDC_EDIT_JF7_CH14_DELAY, m_fJF7_Delay[13]);
	DDX_Text(pDX, IDC_EDIT_JF7_CH15_DELAY, m_fJF7_Delay[14]);
	DDX_Text(pDX, IDC_EDIT_JF7_CH16_DELAY, m_fJF7_Delay[15]);
	DDX_Text(pDX, IDC_EDIT_ANAL_CH1_FREQ, m_fAnal_Freq[0]);
	DDX_Text(pDX, IDC_EDIT_ANAL_CH2_FREQ, m_fAnal_Freq[1]);
	DDX_Text(pDX, IDC_EDIT_ANAL_CH1_AMP, m_fAnal_Amp[0]);
	DDX_Text(pDX, IDC_EDIT_ANAL_CH2_AMP, m_fAnal_Amp[1]);
	DDX_Text(pDX, IDC_EDIT_ANAL_CH1_RATIO, m_fAnal_Ratio[0]);
	DDX_Text(pDX, IDC_EDIT_ANAL_CH2_RATIO, m_fAnal_Ratio[1]);
	DDX_Text(pDX, IDC_EDIT_ANAL_CH1_DELAY, m_fAnal_Delay[0]);
	DDX_Text(pDX, IDC_EDIT_ANAL_CH2_DELAY, m_fAnal_Delay[1]);
	DDX_Control(pDX, IDC_COMBO_LED_STATUS, m_cbLedStatus);
	DDX_Control(pDX, IDC_COMBO_FUNCTION_TYPE1, m_cbFuncType_1);
	DDX_Control(pDX, IDC_COMBO_FUNCTION_TYPE2, m_cbFuncType_2);
}

BEGIN_MESSAGE_MAP(CFunctionGeneratorDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	// AFX_MSG_MAP
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_BUTTON_SETLED, &CFunctionGeneratorDlg::OnBnClickedButtonSetLED)
	ON_BN_CLICKED(IDC_BUTTON_SETOUTPUTEX, &CFunctionGeneratorDlg::OnBnClickedButtonSetOutputEx)
	ON_BN_CLICKED(IDC_BUTTON_SETOUTPUT, &CFunctionGeneratorDlg::OnBnClickedButtonSetOutput)
	ON_BN_CLICKED(IDC_BUTTON_SETANALOG1OUT, &CFunctionGeneratorDlg::OnBnClickedButtonSetOutAnalog1)
	ON_BN_CLICKED(IDC_BUTTON_SETANALOG2OUT, &CFunctionGeneratorDlg::OnBnClickedButtonSetOutAnalog2)
	ON_CBN_SELCHANGE(IDC_COMBO_FUNCTION_TYPE1, &CFunctionGeneratorDlg::OnCbnSelchangeComboFunctionType1)
	ON_CBN_SELCHANGE(IDC_COMBO_FUNCTION_TYPE2, &CFunctionGeneratorDlg::OnCbnSelchangeComboFunctionType2)
END_MESSAGE_MAP()

// CFunctionGeneratorDlg 訊息處理常式

BOOL CFunctionGeneratorDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 將 [關於...] 功能表加入系統功能表。

	// IDM_ABOUTBOX 必須在系統命令範圍之中。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 設定此對話方塊的圖示。當應用程式的主視窗不是對話方塊時，
	// 框架會自動從事此作業
	SetIcon(m_hIcon, TRUE);			// 設定大圖示
	SetIcon(m_hIcon, FALSE);		// 設定小圖示

	// TODO: 在此加入額外的初始設定
	DllLoader();
	InitialDev();
	m_uiSetLED = 0;
	m_cbLedStatus.SetCurSel(CLOSELED);
	m_strLedStatus = _T("");
	m_cbFuncType_1.SetCurSel(CLOSE_ANALOG);
	m_cbFuncType_2.SetCurSel(CLOSE_ANALOG);

	for (int i = 0; i < 16; i++)
	{
		m_fJF8_Freq[i] = 0.0;
		m_fJF8_Duty[i] = 0.0;
		m_fJF8_Delay[i] = 0.0;
		m_fJF7_Freq[i] = 0.0;
		m_fJF7_Duty[i] = 0.0;
		m_fJF7_Delay[i] = 0.0;
	}

	for (int i = 0; i < 2; i++)
	{
		m_fAnal_Freq[i] = 0.0;
		m_fAnal_Amp[i] = 0.0;
		m_fAnal_Ratio[i] = 0.0;
		m_fAnal_Delay[i] = 0.0;
	}

	UpdateData(FALSE);

	return TRUE;  // 傳回 TRUE，除非您對控制項設定焦點
}

void CFunctionGeneratorDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// 如果將最小化按鈕加入您的對話方塊，您需要下列的程式碼，
// 以便繪製圖示。對於使用文件/檢視模式的 MFC 應用程式，
// 框架會自動完成此作業。

void CFunctionGeneratorDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 繪製的裝置內容

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 將圖示置中於用戶端矩形
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 描繪圖示
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// 當使用者拖曳最小化視窗時，
// 系統呼叫這個功能取得游標顯示。
HCURSOR CFunctionGeneratorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

BOOL CFunctionGeneratorDlg::IsWow64()
{
    BOOL bIsWow64 = FALSE;

    //IsWow64Process is not available on all supported versions of Windows.
    //Use GetModuleHandle to get a handle to the DLL that contains the function
    //and GetProcAddress to get a pointer to the function if available.

    fnIsWow64Process = (LPFN_ISWOW64PROCESS) GetProcAddress(
        GetModuleHandle(TEXT("kernel32")),"IsWow64Process");

    if(NULL != fnIsWow64Process)
    {
        if (!fnIsWow64Process(GetCurrentProcess(),&bIsWow64))
        {
            //handle error
        }
    }
    return bIsWow64;
}

void CFunctionGeneratorDlg::DllLoader()
{
	CString strDLLname;

	if (IsWow64())
	{
		strDLLname = _T("FunctionGenerator_x64.dll");
	}
	else
	{
		strDLLname = _T("FunctionGenerator_x86.dll");
	}

	// Load DLL file
    m_hinstLib = LoadLibrary(strDLLname);
    if (m_hinstLib == NULL) {  
        MessageBox(_T("ERROR: unable to load DLL"));
    }
	else
	{
		// Get function pointer
		SetPWM_JF8 = (importFunctionSetPWM)GetProcAddress(m_hinstLib, "SetPWM_JF8");
		if (SetPWM_JF8 == NULL) {  
			MessageBox(_T("ERROR: unable to find DLL function"));
			FreeLibrary(m_hinstLib);
		}

		SetPWM_JF7 = (importFunctionSetPWM)GetProcAddress(m_hinstLib, "SetPWM_JF7");
		if (SetPWM_JF7 == NULL) {  
			MessageBox(_T("ERROR: unable to find DLL function"));
			FreeLibrary(m_hinstLib);
		}

		SetAnalog_1 = (importFunctionSetAnanlog)GetProcAddress(m_hinstLib, "SetAnalog_1");
		if (SetAnalog_1 == NULL) {  
			MessageBox(_T("ERROR: unable to find DLL function"));
			FreeLibrary(m_hinstLib);
		}

		SetAnalog_2 = (importFunctionSetAnanlog)GetProcAddress(m_hinstLib, "SetAnalog_2");
		if (SetAnalog_2 == NULL) {  
			MessageBox(_T("ERROR: unable to find DLL function"));
			FreeLibrary(m_hinstLib);
		}

		SetLED = (importFunctionSet)GetProcAddress(m_hinstLib, "SetLED");
		if (SetLED == NULL) {  
			MessageBox(_T("ERROR: unable to find DLL function"));
			FreeLibrary(m_hinstLib);
		}

		InitialDev = (importFunctionDev)GetProcAddress(m_hinstLib, "InitialDev");
		if (InitialDev == NULL) {  
			MessageBox(_T("ERROR: unable to find DLL function"));
			FreeLibrary(m_hinstLib);
		}

		CloseDev = (importFunctionDev)GetProcAddress(m_hinstLib, "CloseDev");
		if (CloseDev == NULL) {  
			MessageBox(_T("ERROR: unable to find DLL function"));
			FreeLibrary(m_hinstLib);
		}
	}
}

void CFunctionGeneratorDlg::OnDestroy()
{
	CDialog::OnDestroy();
	
	CloseDev();

	FreeLibrary(m_hinstLib);
}

void CFunctionGeneratorDlg::OnBnClickedButtonSetLED()
{
	int iLedStatus = m_cbLedStatus.GetCurSel();
	
	switch (iLedStatus)
	{
		case RED:
		{
			m_uiSetLED = 1;
			break;
		}
		case YELLOW1:
		{
			m_uiSetLED = 2;
			break;
		}
		case YELLOW2:
		{
			m_uiSetLED = 4;
			break;
		}
		case YELLOW3:
		{
			m_uiSetLED = 8;
			break;
		}
		case ALLLED:
		{
			m_uiSetLED = 15;
			break;
		}
		case CLOSELED:
		{
			m_uiSetLED = 0;
			break;
		}
		default:
		{
			break;
		}
	}

	unsigned int uLedStatus;
	uLedStatus = SetLED(m_uiSetLED);
	m_strLedStatus.Format(_T("%d"), uLedStatus);
	GetDlgItem(IDC_STATIC_LED_STATUS)->SetWindowText(m_strLedStatus);
}

float* CFunctionGeneratorDlg::SetDigitalParams(float fFreq, float fDuty, float fDelay)
{
	float fDigitalParams[3];

	if (fFreq <= 0.0)
	{
		fFreq = 0.0;
	}
	else if (fFreq > 50000.0)
	{
		fFreq = 50000.0;
	}

	if (fDuty <= 0.0)
	{
		fDuty = 0.0;
	}
	else if (fDuty > 100.0)
	{
		fDuty = 100.0;
	}
	
	if (fDelay < 0.0)
	{
		fDelay = 0.0;
	}

	fDigitalParams[0] = fFreq;
	fDigitalParams[1] = fDuty;
	fDigitalParams[2] = fDelay;

	return fDigitalParams;
}

void CFunctionGeneratorDlg::OnBnClickedButtonSetOutputEx()
{
	UpdateData(TRUE);
	CMD_PWM CmdData;
	float* fParams;
	
	for (int i = 0; i < 16; i++)
	{
		CmdData.m_iChannel = i;
		
		fParams = SetDigitalParams(m_fJF7_Freq[i], m_fJF7_Duty[i], m_fJF7_Delay[i]);
		m_fJF7_Freq[i] = fParams[0];
		m_fJF7_Duty[i] = fParams[1];
		m_fJF7_Delay[i] = fParams[2];
		UpdateData(FALSE);

		CmdData.m_fFreq = m_fJF7_Freq[i];
		CmdData.m_fDuty = m_fJF7_Duty[i];
		CmdData.m_fDelay = m_fJF7_Delay[i];
		SetPWM_JF7(CmdData);
	}
}

void CFunctionGeneratorDlg::OnBnClickedButtonSetOutput()
{
	UpdateData(TRUE);
	CMD_PWM CmdData;
	float* fParams;
	
	for (int i = 0; i < 16; i++)
	{
		CmdData.m_iChannel = i;
		
		fParams = SetDigitalParams(m_fJF8_Freq[i], m_fJF8_Duty[i], m_fJF8_Delay[i]);
		m_fJF8_Freq[i] = fParams[0];
		m_fJF8_Duty[i] = fParams[1];
		m_fJF8_Delay[i] = fParams[2];
		UpdateData(FALSE);

		CmdData.m_fFreq = m_fJF8_Freq[i];
		CmdData.m_fDuty = m_fJF8_Duty[i];
		CmdData.m_fDelay = m_fJF8_Delay[i];
		SetPWM_JF8(CmdData);
	}
}

float* CFunctionGeneratorDlg::SetAnalParams(float fFreq, float fAmp, float fRatio, float fDelay)
{
	float fAnalParams[4];

	if (fFreq < 0.0)
	{
		fFreq = 0.0;
	}
	else if (fFreq > 50000.0)
	{
		fFreq = 50000.0;
	}

	if (fAmp < 0.0)
	{
		fAmp = 0.0;
	}
	else if (fAmp > 11.0)
	{
		fAmp = 11.0;
	}
	
	if (fRatio < 0.0)
	{
		fRatio = 0.0;
	}
	else if (fRatio > 1.0)
	{
		fRatio = 1.0;
	}

	if (fDelay < 0.0)
	{
		fDelay = 0.0;
	}

	fAnalParams[0] = fFreq;
	fAnalParams[1] = fAmp;
	fAnalParams[2] = fRatio;
	fAnalParams[3] = fDelay;
	
	return fAnalParams;
}

void CFunctionGeneratorDlg::SetAnalog(int iChannel)
{
	int iFuncType;
	CMD_ANALOG CmdData;
	float* fParams;

	UpdateData(TRUE);

	if (iChannel == 0)
	{
		iFuncType = m_cbFuncType_1.GetCurSel();
	}
	else if (iChannel == 1)
	{
		iFuncType = m_cbFuncType_2.GetCurSel();
	}
	else
	{
		iChannel = 3;
	}

	if (iChannel != 3)
	{
		fParams = SetAnalParams(m_fAnal_Freq[iChannel], m_fAnal_Amp[iChannel], m_fAnal_Ratio[iChannel], m_fAnal_Delay[iChannel]);
		
		m_fAnal_Freq[iChannel] = fParams[0];
		m_fAnal_Amp[iChannel] = fParams[1];
		m_fAnal_Ratio[iChannel] = fParams[2];
		m_fAnal_Delay[iChannel] = fParams[3];

		if (fParams[0] == 0.0 || fParams[1] == 0.0)
		{
			iFuncType = CLOSE_ANALOG;
			if (iChannel == 0)
			{
				m_cbFuncType_1.SetCurSel(iFuncType);
			}
			else if (iChannel == 1)
			{
				m_cbFuncType_2.SetCurSel(iFuncType);
			}
		}
		
		switch (iFuncType)
		{
			case CLOSE_ANALOG:
			{
				CmdData.m_iFunction = iFuncType;
				m_fAnal_Freq[iChannel] = 0.0;
				m_fAnal_Amp[iChannel] = 0.0;
				m_fAnal_Ratio[iChannel] = 0.0;
				m_fAnal_Delay[iChannel] = 0.0;
				UpdateData(FALSE);
				break;
			}
			
			case SINE_ANALOG:
			{
				m_fAnal_Ratio[iChannel] = 0.0;
				UpdateData(FALSE);
				break;
			}
			
			case TRIANGE_ANALOG:
			{
				m_fAnal_Ratio[iChannel] = 0.5;
				UpdateData(FALSE);
				break;
			}

			case SAWTOOTH_ANALOG:
			{
				UpdateData(FALSE);
				break;
			}

			default:
			{
				break;
			}
		}

		CmdData.m_iFunction = iFuncType;
		CmdData.m_fFreq = m_fAnal_Freq[iChannel];
		CmdData.m_fAmp = m_fAnal_Amp[iChannel];
		CmdData.m_fRatio = m_fAnal_Ratio[iChannel];
		CmdData.m_fDelay = m_fAnal_Delay[iChannel];

		if (iChannel == 0)
		{
			SetAnalog_1(CmdData);
		}
		else if (iChannel == 1)
		{
			SetAnalog_2(CmdData);
		}
	}
}

void CFunctionGeneratorDlg::OnBnClickedButtonSetOutAnalog1()
{
	SetAnalog(0);
}

void CFunctionGeneratorDlg::OnBnClickedButtonSetOutAnalog2()
{
	SetAnalog(1);
}

void CFunctionGeneratorDlg::SetRatioEdit(int iCbCurSel, int iCH)
{
	int iIDC_EDIT;
	bool bFlag;

	bFlag = false;

	if (iCH == 0)
	{
		iIDC_EDIT = IDC_EDIT_ANAL_CH1_RATIO;
		bFlag = true;
	}
	else if (iCH == 1)
	{
		iIDC_EDIT = IDC_EDIT_ANAL_CH2_RATIO;
		bFlag = true;
	}

	if (bFlag)
	{
		if (iCbCurSel == SAWTOOTH_ANALOG)
		{
			GetDlgItem(iIDC_EDIT)->EnableWindow(TRUE);
		}
		else
		{
			GetDlgItem(iIDC_EDIT)->EnableWindow(FALSE);
		}
	}
}

void CFunctionGeneratorDlg::OnCbnSelchangeComboFunctionType1()
{
	int iCbCurSel;
	iCbCurSel = m_cbFuncType_1.GetCurSel();
	
	SetRatioEdit(iCbCurSel, 0);
}

void CFunctionGeneratorDlg::OnCbnSelchangeComboFunctionType2()
{
	int iCbCurSel;
	iCbCurSel = m_cbFuncType_2.GetCurSel();
	
	SetRatioEdit(iCbCurSel, 1);
}
