#ifndef SERVIDOR_H
#define SERVIDOR_H

class Servidor{
	/*
		TODO implementação dos atributos e métodos
	*/

	public:
		std::string serv_name;
		std::string serv_desc;
		std::string owner;
		
		Servidor(std::string se_name ,std::string ow_name){
			serv_name = se_name;
			owner = ow_name;
		}

};

#endif
