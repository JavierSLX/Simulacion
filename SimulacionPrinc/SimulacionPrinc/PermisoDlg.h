#pragma once   //_____________________________________________ PermisoDlg.h  
#include "resource.h"
#include "LibreriaDll.h"

class PermisoDlg: public Win::Dialog
{
public:
	PermisoDlg()
	{
	}
	~PermisoDlg()
	{
	}
private:
	wstring permisoVP;
	void llenarInformacionBasica(int usuario_id);
	//______ Wintempla GUI manager section begin: DO NOT EDIT AFTER THIS LINE
	Win::DropDownList ddUsuario;
	Win::Textbox tbxNick;
	Win::Textbox tbxPwd;
	Win::DropDownList ddPermisos;
	Win::Button btActualizar;
protected:
	Win::Gdi::Font fontArial009A;
	void GetDialogTemplate(DLGTEMPLATE& dlgTemplate)
	{
		dlgTemplate.cx=Sys::Convert::CentimetersToDlgUnitX(11.03313);
		dlgTemplate.cy=Sys::Convert::CentimetersToDlgUnitY(3.70417);
		dlgTemplate.style = WS_CAPTION | WS_POPUP | WS_SYSMENU | WS_VISIBLE | DS_CENTER | DS_MODALFRAME;
	}
	//_________________________________________________
	void InitializeGui()
	{
		ddUsuario.CreateX(NULL, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | WS_VSCROLL | CBS_DROPDOWNLIST | CBS_WINNORMALCASE, 0.18521, 0.21167, 7.88458, 0.60854, hWnd, 1000);
		tbxNick.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_READONLY | ES_LEFT | ES_WINNORMALCASE, 0.18521, 1.50812, 4.84187, 0.60854, hWnd, 1001);
		tbxPwd.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_PASSWORD | ES_READONLY | ES_LEFT | ES_WINNORMALCASE, 5.50333, 1.50812, 5.34458, 0.60854, hWnd, 1002);
		ddPermisos.CreateX(NULL, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | WS_VSCROLL | CBS_DROPDOWNLIST | CBS_WINNORMALCASE, 0.18521, 2.83104, 4.94771, 0.60854, hWnd, 1003);
		btActualizar.CreateX(NULL, L"Actualizar", WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_PUSHBUTTON | BS_CENTER | BS_VCENTER, 5.74146, 2.83104, 4.44500, 0.68792, hWnd, 1004);
		fontArial009A.CreateX(L"Arial", 0.317500, false, false, false, false);
		ddUsuario.Font = fontArial009A;
		tbxNick.Font = fontArial009A;
		tbxPwd.Font = fontArial009A;
		ddPermisos.Font = fontArial009A;
		btActualizar.Font = fontArial009A;
	}
	//_________________________________________________
	void ddUsuario_SelChange(Win::Event& e);
	void btActualizar_Click(Win::Event& e);
	void Window_Open(Win::Event& e);
	//_________________________________________________
	bool EventHandler(Win::Event& e)
	{
		if (ddUsuario.IsEvent(e, CBN_SELCHANGE)) {ddUsuario_SelChange(e); return true;}
		if (btActualizar.IsEvent(e, BN_CLICKED)) {btActualizar_Click(e); return true;}
		return false;
	}
};
