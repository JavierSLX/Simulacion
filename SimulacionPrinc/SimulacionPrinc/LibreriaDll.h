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

	
private:
	
};
