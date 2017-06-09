#pragma once   //_____________________________________________ LibreriaDll.h  
#include "resource.h"

class LibreriaDll: public Win::Dialog
{
public:
	LibreriaDll()
	{
	}
	~LibreriaDll()
	{
	}

	class Login :public Win::Dialog
	{
	public:
		Login()
		{
		}
		~Login()
		{
		}
		int LibreriaDll::Login::accederUsuario(wstring nick, wstring pwd);
	};
	class Eliminar : public Win::Dialog
	{
	public:
		Eliminar()
		{

		}
		~Eliminar()
		{
		}

		void LibreriaDll::Eliminar::llenarUsuariosLV(Win::ListView lvDepartamento, int large);
		int LibreriaDll::Eliminar::sacarIDOcultoLV(Win::ListView lv2);
		void LibreriaDll::Eliminar::eliminaUsuario( int id_usuario);
	private:

	};

	class Actualizacion: public Win::Dialog
	{
	public:
		Actualizacion()
		{

		}
		wstring consultarUsuario(wstring usuarioNombre);
		wstring consultarActivo(int usuarioId);
		int consultarPuestoId(int usuarioId);
		wstring consultarPuestoDescripcion(int puestoId);
		int consultarCategoriaId(int usuarioId);
		wstring consultarCategoriaDescripcion(int categoriaId);
		int consultarCategoriaIdNueva(wstring categoriaDescripcion);
		int consultarPuestoIdNuevo(wstring puestoDescripcion);
		void actualizarInformacion(int id, wstring nombre, int activo, int puesto_id, int categoria_id);
	};

	class PermisoCLS : public Win::Dialog
	{
	public:
		void llenadoDdUsuario(Win::DropDownList ddNombre, int large);
		void llenadoDdAcceso(Win::DropDownList ddAcceso, int large);
		int sacarIDOculto(Win::DropDownList ddLista);
		wstring sacarNick(int usuario_id);
		wstring sacarPwd(int usuario_id);
		wstring sacarPermiso(int usuario_id);
		void actualizarPermiso(int usuario_id, int acceso_id);
	};

	class Recuperar : public Win::Dialog
	{
	public:
		Recuperar()
		{

		}
		~Recuperar()
		{

		}

		void LibreriaDll::Recuperar::llenarUsuariosInactivos(Win::ListView lvDepartamento, int large);
		int LibreriaDll::Recuperar::sacarIDOcultoLV2(Win::ListView lv2);
		void LibreriaDll::Recuperar::recuperarUsuario(int id_usuario);

	private:

	};



private:


};
