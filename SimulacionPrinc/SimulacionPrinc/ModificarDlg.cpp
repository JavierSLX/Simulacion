#include "stdafx.h"  //_____________________________________________ ModificarDlg.cpp
#include "ModificarDlg.h"

void ModificarDlg::Window_Open(Win::Event& e)
{
}


void ModificarDlg::btActualizar_Click(Win::Event& e)
{
	LibreriaDll::Actualizacion consulta;
	wstring nombreEmpleado = tbxNombre.Text;
	int activo = tbxActivo.IntValue;
	wstring puestoEmpleado;
	wstring categoriaEmpleado;
	int puesto=consulta.consultarPuestoIdNuevo(tbxPuesto.Text);
	int categoriaId = consulta.consultarCategoriaIdNueva(tbxCategoria.Text);

}

void ModificarDlg::btConsultar_Click(Win::Event& e)
{
	LibreriaDll::Actualizacion consulta;
	tbxId.Text = consulta.consultarUsuario(tbxNombre.Text);
	tbxActivo.Text = consulta.consultarActivo(tbxId.IntValue);
	int idPuesto=consulta.consultarPuestoId(tbxId.IntValue);
	tbxPuesto.Text = consulta.consultarPuestoDescripcion(idPuesto);
	int idCategoria=consulta.consultarCategoriaId(tbxId.IntValue);
	tbxCategoria.Text = consulta.consultarCategoriaDescripcion(idCategoria);
}

