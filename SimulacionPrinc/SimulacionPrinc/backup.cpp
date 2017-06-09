#include "stdafx.h"  //_____________________________________________ PermisoDlg.cpp
#include "PermisoDlg.h"

void PermisoDlg::Window_Open(Win::Event& e)
{
	LibreriaDll::PermisoCLS permisoObj;
	permisoObj.llenadoDdUsuario(ddUsuario, 200);
	ddUsuario.SetSelectedIndex(0);

	permisoObj.llenadoDdAcceso(ddPermisos, 100);
	ddPermisos.SetSelectedIndex(0);
}

//Cuando se cambia el usuario
void PermisoDlg::ddUsuario_SelChange(Win::Event& e)
{
	LibreriaDll::PermisoCLS permisoObj;
	int id_oculto = permisoObj.sacarIDOculto(ddUsuario);
}

//Cuando se presiona el botón de Actualizar
void PermisoDlg::btActualizar_Click(Win::Event& e)
{
}

