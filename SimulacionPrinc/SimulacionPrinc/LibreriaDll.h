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
	private:

	};



private:
	

};
