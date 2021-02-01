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
	DDX_Text(pDX, IDC_EDIT_JF8_CH1_FREQ, m_fPWM_Freq[0]);
	DDX_Text(pDX, IDC_EDIT_JF8_CH2_FREQ, m_fPWM_Freq[1]);
	DDX_Text(pDX, IDC_EDIT_JF8_CH3_FREQ, m_fPWM_Freq[2]);
	DDX_Text(pDX, IDC_EDIT_JF8_CH4_FREQ, m_fPWM_Freq[3]);
	DDX_Text(pDX, IDC_EDIT_JF8_CH5_FREQ, m_fPWM_Freq[4]);
	DDX_Text(pDX, IDC_EDIT_JF8_CH6_FREQ, m_fPWM_Freq[5]);
	DDX_Text(pDX, IDC_EDIT_JF8_CH7_FREQ, m_fPWM_Freq[6]);
	DDX_Text(pDX, IDC_EDIT_JF8_CH8_FREQ, m_fPWM_Freq[7]);
	DDX_Text(pDX, IDC_EDIT_JF8_CH9_FREQ, m_fPWM_Freq[8]);
	DDX_Text(pDX, IDC_EDIT_JF8_CH10_FREQ, m_fPWM_Freq[9]);
	DDX_Text(pDX, IDC_EDIT_JF8_CH11_FREQ, m_fPWM_Freq[10]);
	DDX_Text(pDX, IDC_EDIT_JF8_CH12_FREQ, m_fPWM_Freq[11]);
	DDX_Text(pDX, IDC_EDIT_JF8_CH13_FREQ, m_fPWM_Freq[12]);
	DDX_Text(pDX, IDC_EDIT_JF8_CH14_FREQ, m_fPWM_Freq[13]);
	DDX_Text(pDX, IDC_EDIT_JF8_CH15_FREQ, m_fPWM_Freq[14]);
	DDX_Text(pDX, IDC_EDIT_JF8_CH16_FREQ, m_fPWM_Freq[15]);
	DDX_Text(pDX, IDC_EDIT_JF7_CH1_FREQ, m_fPWM_Freq[16]);
	DDX_Text(pDX, IDC_EDIT_JF7_CH2_FREQ, m_fPWM_Freq[17]);
	DDX_Text(pDX, IDC_EDIT_JF7_CH3_FREQ, m_fPWM_Freq[18]);
	DDX_Text(pDX, IDC_EDIT_JF7_CH4_FREQ, m_fPWM_Freq[19]);
	DDX_Text(pDX, IDC_EDIT_JF7_CH5_FREQ, m_fPWM_Freq[20]);
	DDX_Text(pDX, IDC_EDIT_JF7_CH6_FREQ, m_fPWM_Freq[21]);
	DDX_Text(pDX, IDC_EDIT_JF7_CH7_FREQ, m_fPWM_Freq[22]);
	DDX_Text(pDX, IDC_EDIT_JF7_CH8_FREQ, m_fPWM_Freq[23]);
	DDX_Text(pDX, IDC_EDIT_JF7_CH9_FREQ, m_fPWM_Freq[24]);
	DDX_Text(pDX, IDC_EDIT_JF7_CH10_FREQ, m_fPWM_Freq[25]);
	DDX_Text(pDX, IDC_EDIT_JF7_CH11_FREQ, m_fPWM_Freq[26]);
	DDX_Text(pDX, IDC_EDIT_JF7_CH12_FREQ, m_fPWM_Freq[27]);
	DDX_Text(pDX, IDC_EDIT_JF7_CH13_FREQ, m_fPWM_Freq[28]);
	DDX_Text(pDX, IDC_EDIT_JF7_CH14_FREQ, m_fPWM_Freq[29]);
	DDX_Text(pDX, IDC_EDIT_JF7_CH15_FREQ, m_fPWM_Freq[30]);
	DDX_Text(pDX, IDC_EDIT_JF7_CH16_FREQ, m_fPWM_Freq[31]);
	DDX_Text(pDX, IDC_EDIT_JF8_CH1_DUTY, m_fPWM_Duty[0]);
	DDX_Text(pDX, IDC_EDIT_JF8_CH2_DUTY, m_fPWM_Duty[1]);
	DDX_Text(pDX, IDC_EDIT_JF8_CH3_DUTY, m_fPWM_Duty[2]);
	DDX_Text(pDX, IDC_EDIT_JF8_CH4_DUTY, m_fPWM_Duty[3]);
	DDX_Text(pDX, IDC_EDIT_JF8_CH5_DUTY, m_fPWM_Duty[4]);
	DDX_Text(pDX, IDC_EDIT_JF8_CH6_DUTY, m_fPWM_Duty[5]);
	DDX_Text(pDX, IDC_EDIT_JF8_CH7_DUTY, m_fPWM_Duty[6]);
	DDX_Text(pDX, IDC_EDIT_JF8_CH8_DUTY, m_fPWM_Duty[7]);
	DDX_Text(pDX, IDC_EDIT_JF8_CH9_DUTY, m_fPWM_Duty[8]);
	DDX_Text(pDX, IDC_EDIT_JF8_CH10_DUTY, m_fPWM_Duty[9]);
	DDX_Text(pDX, IDC_EDIT_JF8_CH11_DUTY, m_fPWM_Duty[10]);
	DDX_Text(pDX, IDC_EDIT_JF8_CH12_DUTY, m_fPWM_Duty[11]);
	DDX_Text(pDX, IDC_EDIT_JF8_CH13_DUTY, m_fPWM_Duty[12]);
	DDX_Text(pDX, IDC_EDIT_JF8_CH14_DUTY, m_fPWM_Duty[13]);
	DDX_Text(pDX, IDC_EDIT_JF8_CH15_DUTY, m_fPWM_Duty[14]);
	DDX_Text(pDX, IDC_EDIT_JF8_CH16_DUTY, m_fPWM_Duty[15]);
	DDX_Text(pDX, IDC_EDIT_JF7_CH1_DUTY, m_fPWM_Duty[16]);
	DDX_Text(pDX, IDC_EDIT_JF7_CH2_DUTY, m_fPWM_Duty[17]);
	DDX_Text(pDX, IDC_EDIT_JF7_CH3_DUTY, m_fPWM_Duty[18]);
	DDX_Text(pDX, IDC_EDIT_JF7_CH4_DUTY, m_fPWM_Duty[19]);
	DDX_Text(pDX, IDC_EDIT_JF7_CH5_DUTY, m_fPWM_Duty[20]);
	DDX_Text(pDX, IDC_EDIT_JF7_CH6_DUTY, m_fPWM_Duty[21]);
	DDX_Text(pDX, IDC_EDIT_JF7_CH7_DUTY, m_fPWM_Duty[22]);
	DDX_Text(pDX, IDC_EDIT_JF7_CH8_DUTY, m_fPWM_Duty[23]);
	DDX_Text(pDX, IDC_EDIT_JF7_CH9_DUTY, m_fPWM_Duty[24]);
	DDX_Text(pDX, IDC_EDIT_JF7_CH10_DUTY, m_fPWM_Duty[25]);
	DDX_Text(pDX, IDC_EDIT_JF7_CH11_DUTY, m_fPWM_Duty[26]);
	DDX_Text(pDX, IDC_EDIT_JF7_CH12_DUTY, m_fPWM_Duty[27]);
	DDX_Text(pDX, IDC_EDIT_JF7_CH13_DUTY, m_fPWM_Duty[28]);
	DDX_Text(pDX, IDC_EDIT_JF7_CH14_DUTY, m_fPWM_Duty[29]);
	DDX_Text(pDX, IDC_EDIT_JF7_CH15_DUTY, m_fPWM_Duty[30]);
	DDX_Text(pDX, IDC_EDIT_JF7_CH16_DUTY, m_fPWM_Duty[31]);
	DDX_Text(pDX, IDC_EDIT_JF8_CH1_DELAY, m_fPWM_Delay[0]);
	DDX_Text(pDX, IDC_EDIT_JF8_CH2_DELAY, m_fPWM_Delay[1]);
	DDX_Text(pDX, IDC_EDIT_JF8_CH3_DELAY, m_fPWM_Delay[2]);
	DDX_Text(pDX, IDC_EDIT_JF8_CH4_DELAY, m_fPWM_Delay[3]);
	DDX_Text(pDX, IDC_EDIT_JF8_CH5_DELAY, m_fPWM_Delay[4]);
	DDX_Text(pDX, IDC_EDIT_JF8_CH6_DELAY, m_fPWM_Delay[5]);
	DDX_Text(pDX, IDC_EDIT_JF8_CH7_DELAY, m_fPWM_Delay[6]);
	DDX_Text(pDX, IDC_EDIT_JF8_CH8_DELAY, m_fPWM_Delay[7]);
	DDX_Text(pDX, IDC_EDIT_JF8_CH9_DELAY, m_fPWM_Delay[8]);
	DDX_Text(pDX, IDC_EDIT_JF8_CH10_DELAY, m_fPWM_Delay[9]);
	DDX_Text(pDX, IDC_EDIT_JF8_CH11_DELAY, m_fPWM_Delay[10]);
	DDX_Text(pDX, IDC_EDIT_JF8_CH12_DELAY, m_fPWM_Delay[11]);
	DDX_Text(pDX, IDC_EDIT_JF8_CH13_DELAY, m_fPWM_Delay[12]);
	DDX_Text(pDX, IDC_EDIT_JF8_CH14_DELAY, m_fPWM_Delay[13]);
	DDX_Text(pDX, IDC_EDIT_JF8_CH15_DELAY, m_fPWM_Delay[14]);
	DDX_Text(pDX, IDC_EDIT_JF8_CH16_DELAY, m_fPWM_Delay[15]);
	DDX_Text(pDX, IDC_EDIT_JF7_CH1_DELAY, m_fPWM_Delay[16]);
	DDX_Text(pDX, IDC_EDIT_JF7_CH2_DELAY, m_fPWM_Delay[17]);
	DDX_Text(pDX, IDC_EDIT_JF7_CH3_DELAY, m_fPWM_Delay[18]);
	DDX_Text(pDX, IDC_EDIT_JF7_CH4_DELAY, m_fPWM_Delay[19]);
	DDX_Text(pDX, IDC_EDIT_JF7_CH5_DELAY, m_fPWM_Delay[20]);
	DDX_Text(pDX, IDC_EDIT_JF7_CH6_DELAY, m_fPWM_Delay[21]);
	DDX_Text(pDX, IDC_EDIT_JF7_CH7_DELAY, m_fPWM_Delay[22]);
	DDX_Text(pDX, IDC_EDIT_JF7_CH8_DELAY, m_fPWM_Delay[23]);
	DDX_Text(pDX, IDC_EDIT_JF7_CH9_DELAY, m_fPWM_Delay[24]);
	DDX_Text(pDX, IDC_EDIT_JF7_CH10_DELAY, m_fPWM_Delay[25]);
	DDX_Text(pDX, IDC_EDIT_JF7_CH11_DELAY, m_fPWM_Delay[26]);
	DDX_Text(pDX, IDC_EDIT_JF7_CH12_DELAY, m_fPWM_Delay[27]);
	DDX_Text(pDX, IDC_EDIT_JF7_CH13_DELAY, m_fPWM_Delay[28]);
	DDX_Text(pDX, IDC_EDIT_JF7_CH14_DELAY, m_fPWM_Delay[29]);
	DDX_Text(pDX, IDC_EDIT_JF7_CH15_DELAY, m_fPWM_Delay[30]);
	DDX_Text(pDX, IDC_EDIT_JF7_CH16_DELAY, m_fPWM_Delay[31]);
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
	DDX_Control(pDX, IDC_CHECK1, m_ckCH1);
	DDX_Control(pDX, IDC_CHECK2, m_ckCH2);
	DDX_Control(pDX, IDC_CHECK3, m_ckCH3);
	DDX_Control(pDX, IDC_CHECK5, m_ckCH4);
	DDX_Control(pDX, IDC_CHECK6, m_ckCH5);
	DDX_Control(pDX, IDC_CHECK7, m_ckCH6);
	DDX_Control(pDX, IDC_CHECK8, m_ckCH7);
	DDX_Control(pDX, IDC_CHECK9, m_ckCH8);
	DDX_Control(pDX, IDC_CHECK10, m_ckCH9);
	DDX_Control(pDX, IDC_CHECK11, m_ckCH10);
	DDX_Control(pDX, IDC_CHECK12, m_ckCH11);
	DDX_Control(pDX, IDC_CHECK13, m_ckCH12);
	DDX_Control(pDX, IDC_CHECK14, m_ckCH13);
	DDX_Control(pDX, IDC_CHECK15, m_ckCH14);
	DDX_Control(pDX, IDC_CHECK16, m_ckCH15);
	DDX_Control(pDX, IDC_CHECK17, m_ckCH16);
	DDX_Control(pDX, IDC_CHECK18, m_ckCH17);
	DDX_Control(pDX, IDC_CHECK19, m_ckCH18);
	DDX_Control(pDX, IDC_CHECK20, m_ckCH19);
	DDX_Control(pDX, IDC_CHECK21, m_ckCH20);
	DDX_Control(pDX, IDC_CHECK22, m_ckCH21);
	DDX_Control(pDX, IDC_CHECK23, m_ckCH22);
	DDX_Control(pDX, IDC_CHECK24, m_ckCH23);
	DDX_Control(pDX, IDC_CHECK25, m_ckCH24);
	DDX_Control(pDX, IDC_CHECK26, m_ckCH25);
	DDX_Control(pDX, IDC_CHECK27, m_ckCH26);
	DDX_Control(pDX, IDC_CHECK28, m_ckCH27);
	DDX_Control(pDX, IDC_CHECK29, m_ckCH28);
	DDX_Control(pDX, IDC_CHECK30, m_ckCH29);
	DDX_Control(pDX, IDC_CHECK31, m_ckCH30);
	DDX_Control(pDX, IDC_CHECK32, m_ckCH31);
	DDX_Control(pDX, IDC_CHECK33, m_ckCH32);
}

BEGIN_MESSAGE_MAP(CFunctionGeneratorDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	// AFX_MSG_MAP
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_BUTTON_SETLED, &CFunctionGeneratorDlg::OnBnClickedButtonSetLED)
	ON_BN_CLICKED(IDC_BUTTON_START, &CFunctionGeneratorDlg::OnBnClickedButtonStart)
	ON_BN_CLICKED(IDC_BUTTON_STOP, &CFunctionGeneratorDlg::OnBnClickedButtonStop)
	ON_BN_CLICKED(IDC_BUTTON_SETPWM, &CFunctionGeneratorDlg::OnBnClickedButtonSetPWM)
	ON_BN_CLICKED(IDC_BUTTON_SETANALOG, &CFunctionGeneratorDlg::OnBnClickedButtonSetOutAnalog)
	ON_BN_CLICKED(IDC_BUTTON_GETRUNTIME, &CFunctionGeneratorDlg::OnBnClickedButtonGetruntime)
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

	if (m_bDLLflag == true)
	{
		InitialDev = (FuncDev)GetProcAddress(m_hinstLib, "InitialDev");
		if (InitialDev == NULL) {  
			// do nothing
		}
		else
		{
			InitialDev();
		}

		GetParamsInit();
	}
	else
	{
		GetParamsZero();
	}

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
		m_bDLLflag = false;
    }
	else
	{
		m_bDLLflag = true;
	}
}

void CFunctionGeneratorDlg::OnDestroy()
{
	CDialog::OnDestroy();

	if (m_bDLLflag == true)
	{
		CloseDev = (FuncDev)GetProcAddress(m_hinstLib, "CloseDev");
		if (CloseDev == NULL) {  
			// do nothing
		}
		else
		{
			CloseDev();
		}

		FreeLibrary(m_hinstLib);
	}
}

void CFunctionGeneratorDlg::GetParamsZero()
{
	m_cbLedStatus.SetCurSel(CLOSELED);

	for (int i = 0; i < 32; i++)
	{
		m_iPWM_flag[i] = 0;
		m_fPWM_Freq[i] = 0.0;
		m_fPWM_Duty[i] = 0.0;
		m_fPWM_Delay[i] = 0.0;
	}

	for (int j = 0; j < 2; j++)
	{
		m_iFuncType[j] = CLOSE_ANALOG;
		m_fAnal_Freq[j] = 0.0;
		m_fAnal_Amp[j] = 0.0;
		m_fAnal_Ratio[j] = 0.0;
		m_fAnal_Delay[j] = 0.0;
	}

	SetCK();
	m_cbFuncType_1.SetCurSel(m_iFuncType[0]);
	m_cbFuncType_2.SetCurSel(m_iFuncType[1]);
	UpdateData(FALSE);
}

void CFunctionGeneratorDlg::GetLEDstatus()
{
	m_uiSetLED = GetLED();
	m_strLedStatus.Format(_T("%d"), m_uiSetLED);
	GetDlgItem(IDC_STATIC_LED_STATUS)->SetWindowText(m_strLedStatus);

	switch(m_uiSetLED)
	{
		case 0:
		{
			m_cbLedStatus.SetCurSel(CLOSELED);
			break;
		}
		case 1:
		{
			m_cbLedStatus.SetCurSel(RED);
			break;
		}
		case 2:
		{
			m_cbLedStatus.SetCurSel(YELLOW1);
			break;
		}
		case 4:
		{
			m_cbLedStatus.SetCurSel(YELLOW2);
			break;
		}
		case 8:
		{
			m_cbLedStatus.SetCurSel(YELLOW3);
			break;
		}
		case 15:
		{
			m_cbLedStatus.SetCurSel(ALLLED);
			break;
		}
		default:
		{
			break;
		}
	}
}

void CFunctionGeneratorDlg::SetCK()
{
	m_ckCH1.SetCheck(m_iPWM_flag[0]);
	m_ckCH2.SetCheck(m_iPWM_flag[1]);
	m_ckCH3.SetCheck(m_iPWM_flag[2]);
	m_ckCH4.SetCheck(m_iPWM_flag[3]);
	m_ckCH5.SetCheck(m_iPWM_flag[4]);
	m_ckCH6.SetCheck(m_iPWM_flag[5]);
	m_ckCH7.SetCheck(m_iPWM_flag[6]);
	m_ckCH8.SetCheck(m_iPWM_flag[7]);
	m_ckCH9.SetCheck(m_iPWM_flag[8]);
	m_ckCH10.SetCheck(m_iPWM_flag[9]);
	m_ckCH11.SetCheck(m_iPWM_flag[10]);
	m_ckCH12.SetCheck(m_iPWM_flag[11]);
	m_ckCH13.SetCheck(m_iPWM_flag[12]);
	m_ckCH14.SetCheck(m_iPWM_flag[13]);
	m_ckCH15.SetCheck(m_iPWM_flag[14]);
	m_ckCH16.SetCheck(m_iPWM_flag[15]);
	m_ckCH17.SetCheck(m_iPWM_flag[16]);
	m_ckCH18.SetCheck(m_iPWM_flag[17]);
	m_ckCH19.SetCheck(m_iPWM_flag[18]);
	m_ckCH20.SetCheck(m_iPWM_flag[19]);
	m_ckCH21.SetCheck(m_iPWM_flag[20]);
	m_ckCH22.SetCheck(m_iPWM_flag[21]);
	m_ckCH23.SetCheck(m_iPWM_flag[22]);
	m_ckCH24.SetCheck(m_iPWM_flag[23]);
	m_ckCH25.SetCheck(m_iPWM_flag[24]);
	m_ckCH26.SetCheck(m_iPWM_flag[25]);
	m_ckCH27.SetCheck(m_iPWM_flag[26]);
	m_ckCH28.SetCheck(m_iPWM_flag[27]);
	m_ckCH29.SetCheck(m_iPWM_flag[28]);
	m_ckCH30.SetCheck(m_iPWM_flag[29]);
	m_ckCH31.SetCheck(m_iPWM_flag[30]);
	m_ckCH32.SetCheck(m_iPWM_flag[31]);
}

void CFunctionGeneratorDlg::GetParamsInit()
{
	GetLED = (FuncGetLED)GetProcAddress(m_hinstLib, "GetLED");
	if (GetLED == NULL) {  
		MessageBox(_T("ERROR: unable to find DLL function GetLED"));
	}
	else
	{
		GetLEDstatus();
	}
	
	GetParamPWM = (FuncGetPWM)GetProcAddress(m_hinstLib, "GetParamPWM");
	if (GetParamPWM == NULL) {  
		MessageBox(_T("ERROR: unable to find DLL function GetParamPWM"));
	}
	else
	{
		for (int i = 0; i < 32; i++)
		{
			GetParamPWM(&m_CmdDataPWM, i);
			m_iPWM_flag[i] = m_CmdDataPWM.m_iflag;
			m_fPWM_Freq[i] = m_CmdDataPWM.m_fFreq;
			m_fPWM_Duty[i] = m_CmdDataPWM.m_fDuty;
			m_fPWM_Delay[i] = m_CmdDataPWM.m_fDelay;
		}
	}

	GetParamAnalog = (FuncGetAnalog)GetProcAddress(m_hinstLib, "GetParamAnalog");
	if (GetParamAnalog == NULL) {  
		MessageBox(_T("ERROR: unable to find DLL function GetParamAnalog"));
	}
	else
	{
		for (int j = 0; j < 2; j++)
		{
			GetParamAnalog(&m_CmdDataAnal, j);
			m_iFuncType[j] = m_CmdDataAnal.m_iFunction;
			m_fAnal_Freq[j] = m_CmdDataAnal.m_fFreq;
			m_fAnal_Amp[j] = m_CmdDataAnal.m_fAmp;
			m_fAnal_Ratio[j] = m_CmdDataAnal.m_fRatio;
			m_fAnal_Delay[j] = m_CmdDataAnal.m_fDelay;
		}
	}

	SetCK();
	m_cbFuncType_1.SetCurSel(m_iFuncType[0]);
	m_cbFuncType_2.SetCurSel(m_iFuncType[1]);
	UpdateData(FALSE);
}

void CFunctionGeneratorDlg::OnBnClickedButtonStart()
{
	if (m_bDLLflag == true)
	{
		SetStart = (FuncStart)GetProcAddress(m_hinstLib, "SetStart");
		if (SetStart == NULL) {  
			MessageBox(_T("ERROR: unable to find DLL function SetStart"));
		}
		else
		{
			SetStart();
		}
	}
	else
	{
		MessageBox(_T("ERROR: unable to load DLL"));
	}
}

void CFunctionGeneratorDlg::OnBnClickedButtonStop()
{
	if (m_bDLLflag == true)
	{
		SetStop = (FuncStart)GetProcAddress(m_hinstLib, "SetStop");
		if (SetStop == NULL) {  
			MessageBox(_T("ERROR: unable to find DLL function SetStop"));
		}
		else
		{
			SetStop();
		}
	}
	else
	{
		MessageBox(_T("ERROR: unable to load DLL"));
	}
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

	if (m_bDLLflag == true)
	{
		SetLED = (FuncSetLED)GetProcAddress(m_hinstLib, "SetLED");
		if (SetLED == NULL) {  
			MessageBox(_T("ERROR: unable to find DLL function SetLED"));
		}
		else
		{
			unsigned int uLedStatus;
			uLedStatus = SetLED(m_uiSetLED);
			m_strLedStatus.Format(_T("%d"), uLedStatus);
			GetDlgItem(IDC_STATIC_LED_STATUS)->SetWindowText(m_strLedStatus);
		}
	}
	else
	{
		MessageBox(_T("ERROR: unable to load DLL"));
	}
}

void CFunctionGeneratorDlg::SetPWMflag()
{
	int state[32];

	state[0] = m_ckCH1.GetCheck();
	state[1] = m_ckCH2.GetCheck();
	state[2] = m_ckCH3.GetCheck();
	state[3] = m_ckCH4.GetCheck();
	state[4] = m_ckCH5.GetCheck();
	state[5] = m_ckCH6.GetCheck();
	state[6] = m_ckCH7.GetCheck();
	state[7] = m_ckCH8.GetCheck();
	state[8] = m_ckCH9.GetCheck();
	state[9] = m_ckCH10.GetCheck();
	state[10] = m_ckCH11.GetCheck();
	state[11] = m_ckCH12.GetCheck();
	state[12] = m_ckCH13.GetCheck();
	state[13] = m_ckCH14.GetCheck();
	state[14] = m_ckCH15.GetCheck();
	state[15] = m_ckCH16.GetCheck();
	state[16] = m_ckCH17.GetCheck();
	state[17] = m_ckCH18.GetCheck();
	state[18] = m_ckCH19.GetCheck();
	state[19] = m_ckCH20.GetCheck();
	state[20] = m_ckCH21.GetCheck();
	state[21] = m_ckCH22.GetCheck();
	state[22] = m_ckCH23.GetCheck();
	state[23] = m_ckCH24.GetCheck();
	state[24] = m_ckCH25.GetCheck();
	state[25] = m_ckCH26.GetCheck();
	state[26] = m_ckCH27.GetCheck();
	state[27] = m_ckCH28.GetCheck();
	state[28] = m_ckCH29.GetCheck();
	state[29] = m_ckCH30.GetCheck();
	state[30] = m_ckCH31.GetCheck();
	state[31] = m_ckCH32.GetCheck();

	for (int i = 0; i < 32; i++)
	{
		if (state[i] == BST_CHECKED)
		{
			m_iPWM_flag[i] = 1;
		}
		else
		{
			m_iPWM_flag[i] = 0;
		}
	}
}

void CFunctionGeneratorDlg::SetDigitalParams(int iCH)
{	
	if (m_fPWM_Freq[iCH] <= 0.0)
	{
		m_fPWM_Freq[iCH] = 0.0;
	}
	else if (m_fPWM_Freq[iCH] > 50000.0)
	{
		m_fPWM_Freq[iCH] = 50000.0;
	}

	if (m_fPWM_Duty[iCH] <= 0.0)
	{
		m_fPWM_Duty[iCH] = 0.0;
	}
	else if (m_fPWM_Duty[iCH] > 100.0)
	{
		m_fPWM_Duty[iCH] = 100.0;
	}
	
	if (m_fPWM_Delay[iCH] < 0.0)
	{
		m_fPWM_Delay[iCH] = 0.0;
	}

	m_CmdDataPWM.m_iChannel = iCH;
	m_CmdDataPWM.m_iflag = m_iPWM_flag[iCH];
	m_CmdDataPWM.m_fFreq = m_fPWM_Freq[iCH];
	m_CmdDataPWM.m_fDuty = m_fPWM_Duty[iCH];
	m_CmdDataPWM.m_fDelay = m_fPWM_Delay[iCH];
	SetPWM(m_CmdDataPWM, iCH);
}

void CFunctionGeneratorDlg::OnBnClickedButtonSetPWM()
{
	UpdateData(TRUE);

	SetPWMflag();

	if (m_bDLLflag == true)
	{
		SetPWM = (FuncSetPWM)GetProcAddress(m_hinstLib, "SetPWM");
		if (SetPWM == NULL) {  
			MessageBox(_T("ERROR: unable to find DLL function SetPWM"));
		}
		else
		{
			for (int i = 0; i < 32; i++)
			{
				SetDigitalParams(i);
			}
		}
	}
	else
	{
		MessageBox(_T("ERROR: unable to load DLL"));
	}

	UpdateData(FALSE);
}

void CFunctionGeneratorDlg::SetAnalParams(int iCH)
{
	if (m_fAnal_Freq[iCH] < 0.0)
	{
		m_fAnal_Freq[iCH] = 0.0;
	}
	else if (m_fAnal_Freq[iCH] > 50000.0)
	{
		m_fAnal_Freq[iCH] = 50000.0;
	}

	if (m_fAnal_Amp[iCH] < 0.0)
	{
		m_fAnal_Amp[iCH] = 0.0;
	}
	else if (m_fAnal_Amp[iCH] > 11.0)
	{
		m_fAnal_Amp[iCH] = 11.0;
	}
	
	if (m_fAnal_Ratio[iCH] < 0.0)
	{
		m_fAnal_Ratio[iCH] = 0.0;
	}
	else if (m_fAnal_Ratio[iCH] > 1.0)
	{
		m_fAnal_Ratio[iCH] = 1.0;
	}

	if (m_fAnal_Delay[iCH] < 0.0)
	{
		m_fAnal_Delay[iCH] = 0.0;
	}

	if (m_fAnal_Freq[iCH] == 0.0 || m_fAnal_Amp[iCH] == 0.0)
	{
		m_iFuncType[iCH] = CLOSE_ANALOG;
	}
	
	switch (m_iFuncType[iCH])
	{
		case CLOSE_ANALOG:
		{
			m_fAnal_Freq[iCH] = 0.0;
			m_fAnal_Amp[iCH] = 0.0;
			m_fAnal_Ratio[iCH] = 0.0;
			m_fAnal_Delay[iCH] = 0.0;
			break;
		}
		
		case SINE_ANALOG:
		{
			m_fAnal_Ratio[iCH] = 0.0;
			break;
		}
		
		case TRIANGE_ANALOG:
		{
			m_fAnal_Ratio[iCH] = 0.5;
			break;
		}

		case SAWTOOTH_ANALOG:
		{
			break;
		}

		default:
		{
			break;
		}
	}

	m_CmdDataAnal.m_iChannel = iCH;
	m_CmdDataAnal.m_iFunction = m_iFuncType[iCH];
	m_CmdDataAnal.m_fFreq = m_fAnal_Freq[iCH];
	m_CmdDataAnal.m_fAmp = m_fAnal_Amp[iCH];
	m_CmdDataAnal.m_fRatio = m_fAnal_Ratio[iCH];
	m_CmdDataAnal.m_fDelay = m_fAnal_Delay[iCH];

	SetAnalog(m_CmdDataAnal, iCH);
}

void CFunctionGeneratorDlg::OnBnClickedButtonSetOutAnalog()
{
	UpdateData(TRUE);

	m_iFuncType[0] = m_cbFuncType_1.GetCurSel();
	m_iFuncType[1] = m_cbFuncType_2.GetCurSel();
	
	if (m_bDLLflag == true)
	{
		SetAnalog = (FuncSetAnanlog)GetProcAddress(m_hinstLib, "SetAnalog");
		if (SetAnalog == NULL) {  
			MessageBox(_T("ERROR: unable to find DLL function SetAnalog"));
		}
		else
		{
			for (int i = 0; i < 2; i++)
			{
				SetAnalParams(i);
			}
		}
	}
	else
	{
		MessageBox(_T("ERROR: unable to load DLL"));
	}
	
	m_cbFuncType_1.SetCurSel(m_iFuncType[0]);
	m_cbFuncType_2.SetCurSel(m_iFuncType[1]);
	
	UpdateData(FALSE);
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

void CFunctionGeneratorDlg::OnBnClickedButtonGetruntime()
{
	if (m_bDLLflag == true)
	{
		GetRunTime = (FuncGetRunTime)GetProcAddress(m_hinstLib, "GetRunTime");
		if (GetRunTime == NULL) {  
			MessageBox(_T("ERROR: unable to find DLL function GetRunTime"));
		}
		else
		{
			double dRunTime;
			GetRunTime(&dRunTime);

			m_strRunTime.Format(_T("%.3f"), dRunTime);
			GetDlgItem(IDC_STATIC_RUNTIME)->SetWindowText(m_strRunTime);
		}
	}
	else
	{
		MessageBox(_T("ERROR: unable to load DLL"));
	}
}
