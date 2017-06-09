#pragma once   //_____________________________________________ RecuperarDlg.h  
#include "resource.h"
#include "LibreriaDll.h"

class RecuperarDlg: public Win::Dialog
{
public:
	RecuperarDlg()
	{
	}
	~RecuperarDlg()
	{
	}
private:
	//______ Wintempla GUI manager section begin: DO NOT EDIT AFTER THIS LINE
	Win::Button btRestaurar;
	Win::ListView lvUsuarios2;
	Win::Button btRecuperar;
protected:
	Win::Gdi::Font fontArial009A;
	void GetDialogTemplate(DLGTEMPLATE& dlgTemplate)
	{
		dlgTemplate.cx=Sys::Convert::CentimetersToDlgUnitX(20.92854);
		dlgTemplate.cy=Sys::Convert::CentimetersToDlgUnitY(17.19792);
		dlgTemplate.style = WS_CAPTION | WS_POPUP | WS_SYSMENU | WS_VISIBLE | DS_CENTER | DS_MODALFRAME;
	}
	//_________________________________________________
	void InitializeGui()
	{

		btRestaurar.CreateX(NULL, NULL, NULL, 0.00000, 0.00000, 0.00000, 0.00000, hWnd, 1001);
		lvUsuarios2.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | LVS_REPORT, 1.00542, 1.19063, 9.23396, 6.48229, hWnd, 1002);
		btRecuperar.CreateX(NULL, L"Recuperar", WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_PUSHBUTTON | BS_CENTER | BS_VCENTER, 7.96396, 8.06979, 2.24896, 0.68792, hWnd, 1003);
		lvUsuarios2.SetExtStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES, LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
		fontArial009A.CreateX(L"Arial", 0.317500, false, false, false, false);
		btRestaurar.Font = fontArial009A;
		lvUsuarios2.Font = fontArial009A;
		btRecuperar.Font = fontArial009A;
	}
	//_________________________________________________
	void lvUsuarios2_ItemActivate(Win::Event& e);
	void btRecuperar_Click(Win::Event& e);
	void Window_Open(Win::Event& e);
	//_________________________________________________
	bool EventHandler(Win::Event& e)
	{
		if (lvUsuarios2.IsEvent(e, LVN_ITEMACTIVATE)) {lvUsuarios2_ItemActivate(e); return true;}
		if (btRecuperar.IsEvent(e, BN_CLICKED)) {btRecuperar_Click(e); return true;}
		return false;
	}
};
