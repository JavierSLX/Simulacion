#include "stdafx.h"  //_____________________________________________ PermisoDlg.cpp
#include "PermisoDlg.h"

void PermisoDlg::Window_Open(Win::Event& e)
{
	LibreriaDll::PermisoCLS permisoObj;
	permisoObj.llenadoDdUsuario(ddUsuario, 200);
	ddUsuario.SetSelectedIndex(0);

	permisoObj.llenadoDdAcceso(ddPermisos, 100);
	ddPermisos.SetSelectedIndex(0);

	llenarInformacionBasica(permisoObj.sacarIDOculto(ddUsuario));
}

//Cuando se cambia el usuario
void PermisoDlg::ddUsuario_SelChange(Win::Event& e)
{
	LibreriaDll::PermisoCLS permisoObj;
	llenarInformacionBasica(permisoObj.sacarIDOculto(ddUsuario));
}

//Cuando se presiona el botón de Actualizar
void PermisoDlg::btActualizar_Click(Win::Event& e)
{
	//
}

void PermisoDlg::llenarInformacionBasica(int usuario_id)
{
	LibreriaDll::PermisoCLS permisoObj;
	tbxNick.Text = permisoObj.sacarNick(usuario_id);
	tbxPwd.Text = permisoObj.sacarPwd(usuario_id);
}