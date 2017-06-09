#include "stdafx.h"  //_____________________________________________ RecuperarUsuarioDlg.cpp
#include "RecuperarUsuarioDlg.h"

void RecuperarUsuarioDlg::Window_Open(Win::Event& e)
{
	btRecuperar.Visible = false;
	LibreriaDll::Recuperar recuperarObj;
	recuperarObj.llenarUsuariosInactivos(lvRecuperarUsuaurios,200);
}



void RecuperarUsuarioDlg::lvRecuperarUsuaurios_ItemActivate(Win::Event& e)
{

	btRecuperar.Visible = true;
}

void RecuperarUsuarioDlg::btRecuperar_Click(Win::Event& e)
{


	LibreriaDll::Recuperar recuperarObj;
	int usuarioId = recuperarObj.sacarIDOcultoLV2(lvRecuperarUsuaurios);
	recuperarObj.recuperarUsuario(usuarioId);
	if (MessageBoxW(L"Se recupero correctamente", L"Error", MB_OK | MB_ICONINFORMATION) == IDYES)
	{

	}


	recuperarObj.llenarUsuariosInactivos(lvRecuperarUsuaurios, 200);
}

