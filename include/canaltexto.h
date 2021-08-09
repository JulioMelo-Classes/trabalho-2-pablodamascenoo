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

		/*! Construtor da classe CanalTexto
        @param c_name nome do canal
		*/
		CanalTexto(std::string c_name);

		/*!
			@return retorna o nome do canal
		*/
		std::string get_channel_name();

		/*! adiciona mensagem ao servidor
        @param message mensagem a ser adicionada
        @param id id do dono da mensagem
		*/
		void add_message(std::string message, int id);
 
		/*! mostra todas as mensagens do canal
        	@param usuarios vetor com os usuários do servidor
		*/
		void show_messages(std::vector<Usuario>usuarios);

		/*! 
			@return retorna o número de mensagens no canal
		*/
		int msg_number();
};

#endif
