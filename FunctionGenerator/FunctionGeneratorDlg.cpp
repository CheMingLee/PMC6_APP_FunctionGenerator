// FunctionGeneratorDlg.cpp : ��@��
//

#include "stdafx.h"
#include "FunctionGenerator.h"
#include "FunctionGeneratorDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

typedef BOOL (WINAPI *LPFN_ISWOW64PROCESS) (HANDLE, PBOOL);
LPFN_ISWOW64PROCESS fnIsWow64Process;

// �� App About �ϥ� CAboutDlg ��ܤ��

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// ��ܤ�����
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �䴩

// �{���X��@
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


// CFunctionGeneratorDlg ��ܤ��




CFunctionGeneratorDlg::CFunctionGeneratorDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CFunctionGeneratorDlg::IDD, pParent)
	, m_uiSetLED(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CFunctionGeneratorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_uiSetLED);
}

BEGIN_MESSAGE_MAP(CFunctionGeneratorDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON_START, &CFunctionGeneratorDlg::OnBnClickedButtonStart)
	ON_WM_DESTROY()
END_MESSAGE_MAP()


// CFunctionGeneratorDlg �T���B�z�`��

BOOL CFunctionGeneratorDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// �N [����...] �\���[�J�t�Υ\���C

	// IDM_ABOUTBOX �����b�t�ΩR�O�d�򤧤��C
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

	// �]�w����ܤ�����ϥܡC�����ε{�����D�������O��ܤ���ɡA
	// �ج[�|�۰ʱq�Ʀ��@�~
	SetIcon(m_hIcon, TRUE);			// �]�w�j�ϥ�
	SetIcon(m_hIcon, FALSE);		// �]�w�p�ϥ�

	// TODO: �b���[�J�B�~����l�]�w
	DllLoader();
	InitialDev();

	return TRUE;  // �Ǧ^ TRUE�A���D�z�ﱱ��]�w�J�I
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

// �p�G�N�̤p�ƫ��s�[�J�z����ܤ���A�z�ݭn�U�C���{���X�A
// �H�Kø�s�ϥܡC���ϥΤ��/�˵��Ҧ��� MFC ���ε{���A
// �ج[�|�۰ʧ������@�~�C

void CFunctionGeneratorDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ø�s���˸m���e

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// �N�ϥܸm����Τ�ݯx��
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �yø�ϥ�
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// ��ϥΪ̩즲�̤p�Ƶ����ɡA
// �t�ΩI�s�o�ӥ\����o�����ܡC
HCURSOR CFunctionGeneratorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CFunctionGeneratorDlg::OnBnClickedButtonStart()
{
	UpdateData(TRUE);
	SetLED(m_uiSetLED);

}


void CFunctionGeneratorDlg::OnDestroy()
{
	CDialog::OnDestroy();
	
	CloseDev();

	FreeLibrary(m_hinstLib);

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
