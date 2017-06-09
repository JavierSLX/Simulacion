#pragma once   //_____________________________________________ EliminarDlg.h  
#include "resource.h"
#include "LibreriaDll.h"

class EliminarDlg: public Win::Dialog
{
public:
	EliminarDlg()
	{
	}
	~EliminarDlg()
	{
	}
private:
	//______ Wintempla GUI manager section begin: DO NOT EDIT AFTER THIS LINE
	Win::ListView lvUsuarios;
	Win::Button btEliminar;
	Win::Label lb1;
protected:
	Win::Gdi::Font fontArial009A;
	void GetDialogTemplate(DLGTEMPLATE& dlgTemplate)
	{
		dlgTemplate.cx=Sys::Convert::CentimetersToDlgUnitX(15.63688);
		dlgTemplate.cy=Sys::Convert::CentimetersToDlgUnitY(10.45104);
		dlgTemplate.style = WS_CAPTION | WS_POPUP | WS_SYSMENU | WS_VISIBLE | DS_CENTER | DS_MODALFRAME;
	}
	//_________________________________________________
	void InitializeGui()
	{
		lvUsuarios.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | LVS_REPORT, 0.74083, 1.00542, 14.71083, 8.28146, hWnd, 1000);
		btEliminar.CreateX(NULL, L"Eliminar", WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_PUSHBUTTON | BS_CENTER | BS_VCENTER, 13.14979, 9.57792, 2.30187, 0.68792, hWnd, 1001);
		lb1.CreateX(NULL, NULL, WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 10.76854, 9.65729, 1.71979, 0.60854, hWnd, 1002);
		lvUsuarios.SetExtStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES, LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
		fontArial009A.CreateX(L"Arial", 0.317500, false, false, false, false);
		lvUsuarios.Font = fontArial009A;
		btEliminar.Font = fontArial009A;
		lb1.Font = fontArial009A;
	}
	//_________________________________________________
	void lvUsuarios_ItemActivate(Win::Event& e);
	void btEliminar_Click(Win::Event& e);
	void Window_Open(Win::Event& e);
	//_________________________________________________
	bool EventHandler(Win::Event& e)
	{
		if (lvUsuarios.IsEvent(e, LVN_ITEMACTIVATE)) {lvUsuarios_ItemActivate(e); return true;}
		if (btEliminar.IsEvent(e, BN_CLICKED)) {btEliminar_Click(e); return true;}
		return false;
	}
};
