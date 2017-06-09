#include "stdafx.h"  //_____________________________________________ LibreriaDll.cpp
#include "LibreriaDll.h"

//Saca todos los tipos de la tabla Puesto de la BD (Ordenados alfabeticamente)
void LibreriaDll::PermisoCLS::llenadoDdUsuario(Win::DropDownList ddNombre, int large)
{
	Sql::SqlConnection conn;
	wstring consulta;

	//Borra todos los posibles elementos que puedan ya existir
	ddNombre.DeleteAllItems();

	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);

		//Ejecuta la consulta en la drop down list (Solo muestra las salidas)
		Sys::Format(consulta, L"SELECT id, nombre\
		FROM usuario \
		ORDER BY nombre ASC;");

		conn.ExecuteSelect(consulta, large, ddNombre);
	}
	catch (Sql::SqlException e)
	{
		this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);
	}

	conn.CloseSession();
}

//Saca el id oculto en cualquier drop down list, lo regresa
int LibreriaDll::PermisoCLS::sacarIDOculto(Win::DropDownList ddLista)
{
	int indice = ddLista.GetSelectedIndex();
	int id = ddLista.Items[indice].Data;

	return id;
}

//Saca todos los tipos de la tabla Puesto de la BD (Ordenados alfabeticamente)
void LibreriaDll::PermisoCLS::llenadoDdAcceso(Win::DropDownList ddAcceso, int large)
{
	Sql::SqlConnection conn;
	wstring consulta;

	//Borra todos los posibles elementos que puedan ya existir
	ddAcceso.DeleteAllItems();

	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);

		//Ejecuta la consulta en la drop down list (Solo muestra las salidas)
		Sys::Format(consulta, L"SELECT id, tipo\
		FROM acceso \
		ORDER BY tipo ASC;");

		conn.ExecuteSelect(consulta, large, ddAcceso);
	}
	catch (Sql::SqlException e)
	{
		this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);
	}

	conn.CloseSession();
}

wstring LibreriaDll::PermisoCLS::sacarNick(int usuario_id)
{
	wstring nick = L"";
	wstring consulta;
	Sql::SqlConnection conn;

	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"SELECT nick \
		FROM permiso\
		WHERE usuario_id = %d", usuario_id);
		conn.GetString(consulta, nick, 50);
	}
	catch (Sql::SqlException e)
	{
		//this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);
	}

	conn.CloseSession();
	return nick;
}

wstring LibreriaDll::PermisoCLS::sacarPwd(int usuario_id)
{
	wstring pwd;
	wstring consulta;
	Sql::SqlConnection conn;

	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"SELECT pwd \
		FROM permiso\
		WHERE usuario_id = %d", usuario_id);
		conn.GetString(consulta, pwd, 50);
	}
	catch (Sql::SqlException e)
	{
		//this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);
	}

	conn.CloseSession();
	return pwd;
}

wstring LibreriaDll::PermisoCLS::sacarPermiso(int usuario_id)
{
	wstring acceso;
	wstring consulta;
	Sql::SqlConnection conn;

	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"SELECT a.tipo \
		FROM permiso p, acceso a\
		WHERE p.acceso_id = a.id\
		WHERE p.usuario_id = %d", usuario_id);
		conn.GetString(consulta, acceso, 50);
	}
	catch (Sql::SqlException e)
	{
		//this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);
	}

	conn.CloseSession();
	return acceso;
}

void LibreriaDll::PermisoCLS::actualizarPermiso(int usuario_id, int acceso_id)
{
	wstring consulta;
	Sql::SqlConnection conn;
	int rows = 0;

	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"UPDATE permiso \
		SET acceso_id = %d\
		WHERE usuario_id = %d;", acceso_id, usuario_id);
		rows = conn.ExecuteNonQuery(consulta);
		if (rows > 1)
		{
			this->MessageBox(Sys::Convert::ToString(rows), L"Error al actualizar Nómina: number of updated rows", MB_OK | MB_ICONERROR);
		}
	}
	catch (Sql::SqlException e)
	{
		this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);
	}

	conn.CloseSession();
}