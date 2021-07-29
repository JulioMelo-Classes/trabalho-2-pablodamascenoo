#ifndef USUARIO_H
#define USUARIO_H

#include <string>


/*
CP1 classe usuário 60%
o mesmo problema da classe servidor
faltou o atributo id!
*/
class Usuario{
	/*
		TODO implementação dos atributos e métodos
	*/

	public:
		std::string email;
		std::string senha;
		std::string nome;
		Usuario(std::string email_, std::string senha_, std::string nome_){
			email = email_;
			senha = senha_;
			nome = nome_;
		};
};

#endif
