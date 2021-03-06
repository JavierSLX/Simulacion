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
	permisoVP = permisoObj.sacarPermiso(permisoObj.sacarIDOculto(ddUsuario));
	ddPermisos.SetSelected(permisoVP);
}

//Cuando se cambia el usuario
void PermisoDlg::ddUsuario_SelChange(Win::Event& e)
{
	LibreriaDll::PermisoCLS permisoObj;
	llenarInformacionBasica(permisoObj.sacarIDOculto(ddUsuario));
}

//Cuando se presiona el bot�n de Actualizar
void PermisoDlg::btActualizar_Click(Win::Event& e)
{
	LibreriaDll::PermisoCLS permisoObj;
	if (permisoVP != permisoObj.sacarPermiso(permisoObj.sacarIDOculto(ddUsuario)))
	{
		permisoObj.actualizarPermiso(permisoObj.sacarIDOculto(ddUsuario), permisoObj.sacarIDOculto(ddPermisos));
		MessageBoxW(L"Acceso actualizado correctamente", L"Acceso", MB_OK | MB_ICONINFORMATION);
	}
}

void PermisoDlg::llenarInformacionBasica(int usuario_id)
{
	LibreriaDll::PermisoCLS permisoObj;
	tbxNick.Text = permisoObj.sacarNick(usuario_id);
	tbxPwd.Text = permisoObj.sacarPwd(usuario_id);
}