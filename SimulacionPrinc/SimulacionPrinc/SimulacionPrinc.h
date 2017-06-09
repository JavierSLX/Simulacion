#pragma once  //______________________________________ SimulacionPrinc.h  
#include "Resource.h"
#include "LoginDlg.h"
#include "ModificarDlg.h"
#include "PermisoDlg.h"

class SimulacionPrinc: public Win::Window
{
public:
	SimulacionPrinc()
	{
	}
	~SimulacionPrinc()
	{
	}
	const wchar_t * GetClassName(){return L"SimulacionPrinc";}
	Win::Menu menu;
protected:
	//______ Wintempla GUI manager section begin: DO NOT EDIT AFTER THIS LINE
protected:
	void GetWindowInformation(CREATESTRUCT& createStruct)
	{
		createStruct.style = WS_CLIPCHILDREN | WS_OVERLAPPEDWINDOW;
	}
	//_________________________________________________
	void InitializeGui()
	{
		this->Text = L"SimulacionPrinc";
	}
	//_________________________________________________
	void Window_Open(Win::Event& e);
	void Cmd_About(Win::Event& e);
	void Cmd_Login(Win::Event& e);
	void Cmd_Usuario(Win::Event& e);
	void Cmd_Modificar(Win::Event& e);
	void Cmd_Permiso(Win::Event& e);
	//_________________________________________________
	bool EventHandler(Win::Event& e)
	{
		if (this->IsEvent(e, IDM_ABOUT)) {Cmd_About(e); return true;}
		if (this->IsEvent(e, IDM_LOGIN)) {Cmd_Login(e); return true;}
		if (this->IsEvent(e, IDM_USUARIO)) {Cmd_Usuario(e); return true;}
		if (this->IsEvent(e, IDM_MODIFICAR)) {Cmd_Modificar(e); return true;}
		if (this->IsEvent(e, IDM_PERMISO)) {Cmd_Permiso(e); return true;}
		return false;
	}
};
