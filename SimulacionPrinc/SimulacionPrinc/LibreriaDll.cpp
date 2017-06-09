#include "stdafx.h"  //_____________________________________________ LibreriaDll.cpp
#include "LibreriaDll.h"
#include "ModificarDlg.h"

int LibreriaDll::Login::accederUsuario(wstring nick, wstring pwd)
{
	wstring consulta;
	Sql::SqlConnection conn;
	int resultadoConsulta = 0;

	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L" SELECT p.usuario_id\
			FROM permiso p\
			WHERE p.nick = '%s'\
			AND p.pwd = '%s' ", nick.c_str(), pwd.c_str());
		resultadoConsulta = conn.GetInt(consulta);
	}
	catch (Sql::SqlException e)
	{
		/*this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);*/
	}

	conn.CloseSession();

	return resultadoConsulta;

}

wstring LibreriaDll::Actualizacion::consultarUsuario(wstring usuarioNombre)
{
	Sql::SqlConnection conn;
	wstring consulta;
	wstring id;
	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta,L"SELECT id FROM usuario WHERE nombre='%s'",usuarioNombre.c_str());
		conn.GetString(consulta, id, 100);
	}
	catch (Sql::SqlException e)
	{
		this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);
	}
	conn.CloseSession();
	return id;
}
wstring LibreriaDll::Actualizacion::consultarActivo(int usuarioId)
{
	Sql::SqlConnection conn;
	wstring consulta;
	wstring activo;
	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"SELECT activo FROM usuario WHERE id=%d", usuarioId);
		conn.GetString(consulta, activo, 100);
	}
	catch (Sql::SqlException e)
	{
		this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);
	}
	conn.CloseSession();
	return activo;
}
int LibreriaDll::Actualizacion::consultarPuestoId(int usuarioId)
{
	Sql::SqlConnection conn;
	wstring consulta;
	int puestoId;
	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"SELECT puesto_id FROM usuario WHERE id=%d", usuarioId);
		puestoId=conn.GetInt(consulta);
	}
	catch (Sql::SqlException e)
	{
		this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);
	}
	conn.CloseSession();
	return puestoId;
}
wstring LibreriaDll::Actualizacion::consultarPuestoDescripcion(int puestoId)
{
	Sql::SqlConnection conn;
	wstring consulta;
	wstring puestoDescripcion;
	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"SELECT tipo FROM puesto WHERE id=%d", puestoId);
		conn.GetString(consulta, puestoDescripcion, 100);
	}
	catch (Sql::SqlException e)
	{
		this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);
	}
	conn.CloseSession();
	return puestoDescripcion;
}
int LibreriaDll::Actualizacion::consultarCategoriaId(int usuarioId)
{
	Sql::SqlConnection conn;
	wstring consulta;
	int categoriaId;
	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"SELECT categoria_id FROM usuario WHERE id=%d", usuarioId);
		categoriaId = conn.GetInt(consulta);
	}
	catch (Sql::SqlException e)
	{
		this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);
	}
	conn.CloseSession();
	return categoriaId;
}
wstring LibreriaDll::Actualizacion::consultarCategoriaDescripcion(int categoriaId)
{
	Sql::SqlConnection conn;
	wstring consulta;
	wstring categoriaDescripcion;
	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"SELECT descr FROM categoria WHERE id=%d", categoriaId);
		conn.GetString(consulta, categoriaDescripcion, 100);
	}
	catch (Sql::SqlException e)
	{
		this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);
	}
	conn.CloseSession();
	return categoriaDescripcion;
}
int LibreriaDll::Actualizacion::consultarCategoriaIdNueva(wstring categoriaDescripcion)
{
	Sql::SqlConnection conn;
	wstring consulta;
	int categoriaId;
	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"SELECT id FROM categoria WHERE descr='%s'", categoriaDescripcion.c_str());
		categoriaId = conn.GetInt(consulta);
	}
	catch (Sql::SqlException e)
	{
		this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);
	}
	conn.CloseSession();
	return categoriaId;
}
int LibreriaDll::Actualizacion::consultarPuestoIdNuevo(wstring puestoDescripcion)
{
	Sql::SqlConnection conn;
	wstring consulta;
	int puestoId;
	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"SELECT id FROM puesto WHERE tipo='%s'", puestoDescripcion.c_str());
		puestoId = conn.GetInt(consulta);
	}
	catch (Sql::SqlException e)
	{
		this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);
	}
	conn.CloseSession();
	return puestoId;
}
void LibreriaDll::Actualizacion::actualizarInformacion(int id, wstring nombre, int activo, int puesto_id, int categoria_id)
{
	Sql::SqlConnection conn;
	wstring consulta;
	try
	{
		conn.OpenSession(hWnd, CONNECTION_STRING);
		Sys::Format(consulta, L"UPDATE usuario SET nombre='%s'",nombre.c_str()," WHERE id=%d",id);
		conn.ExecuteNonQuery(consulta);
		Sys::Format(consulta, L"UPDATE usuario SET activo='%d'", activo, " WHERE id=%d", id);
		conn.ExecuteNonQuery(consulta);
		Sys::Format(consulta, L"UPDATE usuario SET puesto_id='%d'", puesto_id, " WHERE id=%d", id);
		conn.ExecuteNonQuery(consulta);
		Sys::Format(consulta, L"UPDATE usuario SET categoria_id='%d'", categoria_id, " WHERE id=%d", id);
		conn.ExecuteNonQuery(consulta);
	}
	catch (Sql::SqlException e)
	{
		this->MessageBox(e.GetDescription(), L"Error", MB_OK | MB_ICONERROR);
	}
	conn.CloseSession();
}

