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
		int consultarCategoriaIdNueva(wstring categoriaDescripcion);
		int consultarPuestoIdNuevo(wstring puestoDescripcion);
		void actualizarInformacion(int id, wstring nombre, int activo, int puesto_id, int categoria_id);
	};
private:
	
};
