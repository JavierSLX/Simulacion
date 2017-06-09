#include "stdafx.h"  //_____________________________________________ PermisoDlg.cpp
#include "PermisoDlg.h"

void PermisoDlg::Window_Open(Win::Event& e)
{
	//________________________________________________________ ddUsuario
	ddUsuario.Items.Add(L"Item 0 with value 10", 10);
	ddUsuario.Items.Add(L"Item 1 with value 20", 20);
	//________________________________________________________ ddPermisos
	ddPermisos.Items.Add(L"Item 0 with value 10", 10);
	ddPermisos.Items.Add(L"Item 1 with value 20", 20);
}



void PermisoDlg::ddUsuario_SelChange(Win::Event& e)
{
}

void PermisoDlg::btActualizar_Click(Win::Event& e)
{
}

