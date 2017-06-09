#include "stdafx.h"  //_____________________________________________ LoginDlg.cpp
#include "LoginDlg.h"

void LoginDlg::Window_Open(Win::Event& e)
{
}



void LoginDlg::btAceptar_Click(Win::Event& e)
{

	LibreriaDll::Login libreriaObj;
	int resultadoConsulta;
	wstring Nick = tbxNick.Text;
	wstring Pwd = tbxPwd.Text;
	resultadoConsulta = libreriaObj.accederUsuario(Nick,Pwd);
	if (resultadoConsulta > 0)
	{
		if (MessageBoxW(L"Bienvenido  "+ Nick, L"Registro exitoso", MB_OK | MB_ICONINFORMATION) == IDYES)
		{

		}
		tbxNick.SetText(L"");
		tbxPwd.SetText(L"");
		tbxNick.SetFocus();
	}
	else
	{
		if (MessageBoxW(L"Este usuario no existe", L"Error", MB_OK | MB_ICONERROR) == IDYES)
		{

		}
		tbxNick.SetText(L"");
		tbxPwd.SetText(L"");
		tbxNick.SetFocus();
	}

}

