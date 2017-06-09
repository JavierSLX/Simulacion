#include "stdafx.h"  //_____________________________________________ RecuperarDlg.cpp
#include "RecuperarDlg.h"

void RecuperarDlg::Window_Open(Win::Event& e)
{
	LibreriaDll::Recuperar objRecuperar;
	objRecuperar.llenarUsuariosLVInactivo(lvUsuarios2, 200);
}



void RecuperarDlg::lvUsuarios2_ItemActivate(Win::Event& e)
{
}

void RecuperarDlg::btRecuperar_Click(Win::Event& e)
{
}

