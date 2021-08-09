#ifndef CANALTEXTO_H
#define CANALTEXTO_H

#include <vector>
#include <string>
#include "mensagem.h"
#include "usuario.h"

class CanalTexto{
	/*
		TODO implementação dos atributos e métodos
	*/

	private:

		std::string channel_name;
		std::vector <Mensagem> messages;

	public:

		CanalTexto(std::string c_name);

		std::string get_channel_name();

		void add_message(std::string message, int id);
 
		void show_messages(std::vector<Usuario>usuarios);

		int msg_number(){
			return messages.size();
		}
};

#endif
