#pragma once   //_____________________________________________ LoginDlg.h  
#include "resource.h"
#include "LibreriaDll.h"

class LoginDlg: public Win::Dialog
{
public:
	LoginDlg()
	{
	}
	~LoginDlg()
	{
	}
private:
	//______ Wintempla GUI manager section begin: DO NOT EDIT AFTER THIS LINE
	Win::Textbox tbxNick;
	Win::Textbox tbxPwd;
	Win::Label lbUsuario;
	Win::Label lbContrase_a;
	Win::Button btAceptar;
protected:
	Win::Gdi::Font fontArial009A;
	void GetDialogTemplate(DLGTEMPLATE& dlgTemplate)
	{
		dlgTemplate.cx=Sys::Convert::CentimetersToDlgUnitX(6.13833);
		dlgTemplate.cy=Sys::Convert::CentimetersToDlgUnitY(4.12750);
		dlgTemplate.style = WS_CAPTION | WS_POPUP | WS_SYSMENU | WS_VISIBLE | DS_CENTER | DS_MODALFRAME;
	}
	//_________________________________________________
	void InitializeGui()
	{
		tbxNick.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_LEFT | ES_WINNORMALCASE, 2.77812, 1.03188, 3.17500, 0.60854, hWnd, 1000);
		tbxPwd.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_LEFT | ES_WINNORMALCASE, 2.77812, 2.03729, 3.17500, 0.60854, hWnd, 1001);
		lbUsuario.CreateX(NULL, L"Usuario", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 0.44979, 1.00542, 1.82562, 0.60854, hWnd, 1002);
		lbContrase_a.CreateX(NULL, L"Contraseña", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 0.42333, 2.16958, 1.87854, 0.60854, hWnd, 1003);
		btAceptar.CreateX(NULL, L"Aceptar", WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_PUSHBUTTON | BS_CENTER | BS_VCENTER, 1.48167, 3.25438, 3.30729, 0.68792, hWnd, 1004);
		fontArial009A.CreateX(L"Arial", 0.317500, false, false, false, false);
		tbxNick.Font = fontArial009A;
		tbxPwd.Font = fontArial009A;
		lbUsuario.Font = fontArial009A;
		lbContrase_a.Font = fontArial009A;
		btAceptar.Font = fontArial009A;
	}
	//_________________________________________________
	void btAceptar_Click(Win::Event& e);
	void Window_Open(Win::Event& e);
	//_________________________________________________
	bool EventHandler(Win::Event& e)
	{
		if (btAceptar.IsEvent(e, BN_CLICKED)) {btAceptar_Click(e); return true;}
		return false;
	}
};
