#include "stdafx.h"  //_____________________________________________ LibreriaDll.cpp
#include "LibreriaDll.h"

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


