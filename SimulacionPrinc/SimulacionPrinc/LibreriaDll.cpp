#include "stdafx.h"  //_____________________________________________ LibreriaDll.cpp
#include "LibreriaDll.h"
#include "ModificarDlg.h"
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

