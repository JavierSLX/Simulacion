#include "stdafx.h"  //________________________________________ SimulacionPrinc.cpp
#include "SimulacionPrinc.h"
#include "AboutDlg.h"

int APIENTRY wWinMain(HINSTANCE hInstance, HINSTANCE , LPTSTR cmdLine, int cmdShow){
	SimulacionPrinc app;
	app.CreateMainWindow(L"SimulacionPrinc", cmdShow, IDI_SimulacionPrinc, IDC_SimulacionPrinc, (HBRUSH)(COLOR_WINDOW+1), hInstance);
	return app.MessageLoop(IDC_SimulacionPrinc);
}

void SimulacionPrinc::Window_Open(Win::Event& e)
{
	// Use Resource View to edit the menu
	menu.Attach(hWnd, false);
}

void SimulacionPrinc::Cmd_About(Win::Event& e)
{
	AboutDlg dlg;
	dlg.BeginDialog(hWnd);
}

//Ventana Login
void SimulacionPrinc::Cmd_Login(Win::Event& e)
{
	LoginDlg loginObj;
	loginObj.BeginDialog(hWnd);

}

//Ventana creación de usuario
void SimulacionPrinc::Cmd_Usuario(Win::Event& e)
{
}

//Ventana modificación de usuario
void SimulacionPrinc::Cmd_Modificar(Win::Event& e)
{
	ModificarDlg actualiacionObj;
	actualiacionObj.BeginDialog(hWnd);
}

//Ventana modificacion de permisos
void SimulacionPrinc::Cmd_Permiso(Win::Event& e)
{
	PermisoDlg permisoObj;
	permisoObj.BeginDialog(hWnd);
}
// Ventana de eliminar  usuarios
void SimulacionPrinc::Cmd_Eliminar(Win::Event& e)
{
	EliminarDlg EliminarObj;
	EliminarObj.BeginDialog(hWnd);

}

void SimulacionPrinc::Cmd_Recuperar(Win::Event& e)
{
	RecuperarUsuarioDlg recuperarObj;
	recuperarObj.BeginDialog(hWnd);
}

