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
	m_cbFuncType_1.SetCurSel(CLOSE_ANALOG_1);
	m_cbFuncType_2.SetCurSel(CLOSE_ANALOG_2);

	for (int i = 0; i < 16; i++)
	{
		m_fJF8_Freq[i] = 0.0;
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

void CFunctionGeneratorDlg::OnBnClickedButtonSetOutputEx()
{
	
}

void CFunctionGeneratorDlg::OnBnClickedButtonSetOutput()
{
	UpdateData(TRUE);
	
	for (int i = 0; i < 16; i++)
	{
		CMD_PWM CmdData;
		CmdData.m_fFreq = m_fJF8_Freq[i];
		CmdData.m_fDuty = 0.0;
		CmdData.m_fDelay = 0.0;
		SetPWM_JF8(CmdData);
	}
}

void CFunctionGeneratorDlg::OnBnClickedButtonSetOutAnalog1()
{
	
}

void CFunctionGeneratorDlg::OnBnClickedButtonSetOutAnalog2()
{
	
}
