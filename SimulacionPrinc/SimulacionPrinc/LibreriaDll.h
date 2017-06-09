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
