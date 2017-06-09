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
	};
private:
	
};
