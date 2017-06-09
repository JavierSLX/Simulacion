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