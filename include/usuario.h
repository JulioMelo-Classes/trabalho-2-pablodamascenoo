#ifndef USUARIO_H
#define USUARIO_H

#include <string>


class Usuario{
	/*
		Botar os métodos em um arquivo cpp
	*/

	public:

		std::string email;
		std::string senha;
		std::string nome;
		int id;

		Usuario(std::string email_, std::string senha_, std::string nome_, int id_){
			email = email_;
			senha = senha_;
			nome = nome_;
			id = id_;
		};

		std::string get_user_name(){
			return nome;
		}

		int get_user_id(){
			return  id;
		}
};

#endif
