// FunctionGenerator.h : PROJECT_NAME ���ε{�����D�n���Y��
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�� PCH �]�t���ɮ׫e���]�t 'stdafx.h'"
#endif

#include "resource.h"		// �D�n�Ÿ�


// CFunctionGeneratorApp:
// �аѾ\��@�����O�� FunctionGenerator.cpp
//

class CFunctionGeneratorApp : public CWinApp
{
public:
	CFunctionGeneratorApp();

// �мg
	public:
	virtual BOOL InitInstance();

// �{���X��@

	DECLARE_MESSAGE_MAP()
};

extern CFunctionGeneratorApp theApp;