#include "stdafx.h"  //_____________________________________________ LibreriaDll.cpp
#include "LibreriaDll.h"



void LibreriaDll::Eliminar::llenarUsuariosLV(Win::ListView lvDepartamento, int large) {


	wstring consulta;
	Sql::SqlConnection conn;
	int rows = 0;
	lvDepartamento.SetRedraw(false);
	lvDepartamento.Cols.DeleteAll();
	lvDepartamento.Items.DeleteAll();
	lvDepartamento.SetRedraw(true);
	lvDepartamento.Cols.Add(0, LVCFMT_CENTER, 300, L"Usuario");

	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"SELECT u.id,u.nombre \
			FROM usuario u\
			WHERE u.activo = true") ;
		conn.ExecuteSelect(consulta, large, lvDepartamento);
	}
	catch (Sql::SqlException e)
	{
		this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);
	}

	conn.CloseSession();
}

int LibreriaDll::Eliminar::sacarIDOcultoLV(Win::ListView lv2)
{
	int indice = lv2.GetSelectedIndex();
	int id = lv2.Items[indice].Data;

	return id;
}

void LibreriaDll::Eliminar::eliminaUsuario(int id_usuario){
	wstring consulta;
	Sql::SqlConnection conn;
	int rows = 0;
	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"UPDATE usuario u\
		SET activo = false\
		WHERE u.id = %d", id_usuario);
		rows = conn.ExecuteNonQuery(consulta);
		if (rows > 1)
		{
			this->MessageBox(Sys::Convert::ToString(rows), L"Error: number of updated rows", MB_OK | MB_ICONERROR);
		}
	}
	catch (Sql::SqlException e)
	{
		this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);
	}

	conn.CloseSession();
}
