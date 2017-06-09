#pragma once   //_____________________________________________ ModificarDlg.h  
#include "resource.h"
#include "LibreriaDll.h"
class ModificarDlg: public Win::Dialog
{
public:
	ModificarDlg()
	{
	}
	~ModificarDlg()
	{
	}
private:
	//______ Wintempla GUI manager section begin: DO NOT EDIT AFTER THIS LINE
	Win::Label lbUsuario;
	Win::Textbox tbxNombre;
	Win::Label lbId;
	Win::Textbox tbxId;
	Win::Label lbActivo;
	Win::Textbox tbxActivo;
	Win::Label lbPuesto;
	Win::Textbox tbxPuesto;
	Win::Label lbCategoria;
	Win::Textbox tbxCategoria;
	Win::Button btActualizar;
	Win::Button btConsultar;
protected:
	Win::Gdi::Font fontArial009A;
	void GetDialogTemplate(DLGTEMPLATE& dlgTemplate)
	{
		dlgTemplate.cx=Sys::Convert::CentimetersToDlgUnitX(15.05479);
		dlgTemplate.cy=Sys::Convert::CentimetersToDlgUnitY(6.32354);
		dlgTemplate.style = WS_CAPTION | WS_POPUP | WS_SYSMENU | WS_VISIBLE | DS_CENTER | DS_MODALFRAME;
	}
	//_________________________________________________
	void InitializeGui()
	{
		lbUsuario.CreateX(NULL, L"Nombre del Usuario", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 0.18521, 0.21167, 3.38667, 0.60854, hWnd, 1000);
		tbxNombre.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_LEFT | ES_WINNORMALCASE, 3.59833, 0.21167, 8.46667, 0.60854, hWnd, 1001);
		lbId.CreateX(NULL, L"Id Usuario", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 0.18521, 1.13771, 3.38667, 0.60854, hWnd, 1002);
		tbxId.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_READONLY | ES_LEFT | ES_WINNORMALCASE, 3.59833, 1.08479, 1.82562, 0.60854, hWnd, 1003);
		lbActivo.CreateX(NULL, L"Activo", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 0.18521, 2.11667, 3.38667, 0.60854, hWnd, 1004);
		tbxActivo.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_LEFT | ES_WINNORMALCASE, 3.59833, 2.09021, 1.82562, 0.60854, hWnd, 1005);
		lbPuesto.CreateX(NULL, L"Puesto", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 0.18521, 3.17500, 3.38667, 0.60854, hWnd, 1006);
		tbxPuesto.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_LEFT | ES_WINNORMALCASE, 3.59833, 3.17500, 8.46667, 0.60854, hWnd, 1007);
		lbCategoria.CreateX(NULL, L"Categoria", WS_CHILD | WS_VISIBLE | SS_LEFT | SS_WINNORMAL, 0.18521, 4.20688, 3.38667, 0.60854, hWnd, 1008);
		tbxCategoria.CreateX(WS_EX_CLIENTEDGE, NULL, WS_CHILD | WS_TABSTOP | WS_VISIBLE | ES_AUTOHSCROLL | ES_LEFT | ES_WINNORMALCASE, 3.59833, 4.18042, 8.46667, 0.60854, hWnd, 1009);
		btActualizar.CreateX(NULL, L"Actualizar", WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_PUSHBUTTON | BS_CENTER | BS_VCENTER, 3.96875, 5.45042, 2.77812, 0.68792, hWnd, 1010);
		btConsultar.CreateX(NULL, L"Consultar", WS_CHILD | WS_TABSTOP | WS_VISIBLE | BS_PUSHBUTTON | BS_CENTER | BS_VCENTER, 12.40896, 0.15875, 2.46062, 0.68792, hWnd, 1011);
		fontArial009A.CreateX(L"Arial", 0.317500, false, false, false, false);
		lbUsuario.Font = fontArial009A;
		tbxNombre.Font = fontArial009A;
		lbId.Font = fontArial009A;
		tbxId.Font = fontArial009A;
		lbActivo.Font = fontArial009A;
		tbxActivo.Font = fontArial009A;
		lbPuesto.Font = fontArial009A;
		tbxPuesto.Font = fontArial009A;
		lbCategoria.Font = fontArial009A;
		tbxCategoria.Font = fontArial009A;
		btActualizar.Font = fontArial009A;
		btConsultar.Font = fontArial009A;
	}
	//_________________________________________________
	void btActualizar_Click(Win::Event& e);
	void btConsultar_Click(Win::Event& e);
	void Window_Open(Win::Event& e);
	//_________________________________________________
	bool EventHandler(Win::Event& e)
	{
		if (btActualizar.IsEvent(e, BN_CLICKED)) {btActualizar_Click(e); return true;}
		if (btConsultar.IsEvent(e, BN_CLICKED)) {btConsultar_Click(e); return true;}
		return false;
	}
};
