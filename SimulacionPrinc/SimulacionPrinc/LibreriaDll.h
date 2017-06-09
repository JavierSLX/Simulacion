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
private:
	
};
