#pragma once   //_____________________________________________ RecuperarUsuarioDlg.h  
#include "resource.h"
#include "LibreriaDll.h"

class RecuperarUsuarioDlg: public Win::Dialog
{
public:
	RecuperarUsuarioDlg()
	{
	}
	~RecuperarUsuarioDlg()
	{
	}
private:
	//______ Wintempla GUI manager section begin: DO NOT EDIT AFTER THIS LINE
	Win::ListView lvRecuperarUsuaurios;
	Win::Button btRecuperar;
protected:
	Win::Gdi::Font fontArial009A;
	void GetDialogTemplate(DLGTEMPLATE& dlgTemplate)
	{
		dlgTemplate.cx=Sys::Convert::CentimetersToDlgUnitX(11.08604);
		dlgTemplate.cy=Sys::Convert::CentimetersToDlgUnitY(9.31333);
		dlgTemplate.style = WS_CAPTION | WS_POPUP | WS_SYSMENU | WS_VISIBLE | DS_CENTER | DS_MODALFRAME;
	}
	//_________________________________________________
	void InitializeGui()
	{
		lvRecuperarUsuaurios.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | LVS_REPORT, 0.76729, 1.77271, 10.10708, 6.35000, hWnd, 1000);
		btRecuperar.CreateX(NULL, L"Recuperar", WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_PUSHBUTTON | BS_CENTER | BS_VCENTER, 8.17563, 8.44021, 2.72521, 0.68792, hWnd, 1001);
		lvRecuperarUsuaurios.SetExtStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES, LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
		fontArial009A.CreateX(L"Arial", 0.317500, false, false, false, false);
		lvRecuperarUsuaurios.Font = fontArial009A;
		btRecuperar.Font = fontArial009A;
	}
	//_________________________________________________
	void lvRecuperarUsuaurios_ItemActivate(Win::Event& e);
	void btRecuperar_Click(Win::Event& e);
	void Window_Open(Win::Event& e);
	//_________________________________________________
	bool EventHandler(Win::Event& e)
	{
		if (lvRecuperarUsuaurios.IsEvent(e, LVN_ITEMACTIVATE)) {lvRecuperarUsuaurios_ItemActivate(e); return true;}
		if (btRecuperar.IsEvent(e, BN_CLICKED)) {btRecuperar_Click(e); return true;}
		return false;
	}
};
