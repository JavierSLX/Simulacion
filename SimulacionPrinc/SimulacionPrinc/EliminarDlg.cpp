#include "stdafx.h"  //_____________________________________________ EliminarDlg.cpp
#include "EliminarDlg.h"

void EliminarDlg::Window_Open(Win::Event& e)
{

	btEliminar.Visible = false;
	LibreriaDll::Eliminar eliminarObj;
	eliminarObj.llenarUsuariosLV(lvUsuarios, 200);

}
	



void EliminarDlg::btEliminar_Click(Win::Event& e)
{
	LibreriaDll::Eliminar eliminarObj;
	int usuarioId = eliminarObj.sacarIDOcultoLV(lvUsuarios);
	lb1.SetText(Sys::Convert::ToString(usuarioId));
	eliminarObj.eliminaUsuario(usuarioId);
	if (MessageBoxW(L"Se elimino correctamente", L"Error", MB_OK | MB_ICONERROR) == IDYES)
	{

	}

	
	eliminarObj.llenarUsuariosLV(lvUsuarios, 200);
}

void EliminarDlg::lvUsuarios_ItemActivate(Win::Event& e)
{
	btEliminar.Visible = true;
	





}

