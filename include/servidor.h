#ifndef SERVIDOR_H
#define SERVIDOR_H

#include <vector>
#include <string>
#include <iostream>
#include "canaltexto.h"
#include "usuario.h"

/*
Cp2 ok

Documentação 0,8, faltou documentar os atributos
*/
class Servidor{
	/*
		Botar os métodos em um arquivo cpp
	*/
	private:
		std::string serv_name;
		std::string serv_desc;
		int owner_id;
		std::string codigoConvite;
		std::vector <int> users_id;
		std::vector <CanalTexto> serv_channels;

	public:

		/*!
				@return Uma string contendo o convite
		*/
		std::string get_invite();


		/*! Seta o convite para entrar no servidor.
				@param codigo Codigo do convite para entrar no servidor
		*/
		void set_invite(std::string codigo);

		/*!
				@return retorna o nome do servidor
		*/
		std::string get_serv_name();

		/*!
				@return retorna o id do usuário dono do servidor
		*/
		int get_owner_id();

		/*! Seta a descrição do servidor.
				@param serv_desc_ Nova descrição do servidor
		*/
		void set_disc(std::string serv_desc_);

		/*! Construtor da classe servidor.
				@param se_name nome do servidor
				@param id id do dono do servidor
		*/
		Servidor(std::string se_name , int id);

		/*! Adiciona o id de um usuário na lista de usuários logados do servidor.
				@param user_id id do usuário logado no servidor
		*/
		void add_user(int user_id);

		/*! remove um usuário da lista de usuários logados no servidor.
				@param id_ id do usuário para ser removido do servidor
				@return booleano true se o usuário for removido e false se não for encontrado
		*/
		bool erase_user(int id_);

		/*! procura um usuário dentro da lista de usuários logados no servidor.
				@param id_ id do usuário para ser procurado do servidor
				@return booleano true se o usuário for encontrado e false se não for encontrado
		*/
		bool find_user(int id_);

		/*! Lista os canais de texto do servidor.
				@param id_ id do usuário para ser procurado do servidor
				@return booleano true se o usuário for encontrado e false se não for encontrado
		*/
		void list_channel();

		/*! Adiciona um canal de texto ao servidor
				@param channel canal de texto a ser adicionado ao servidor
		*/
		void add_channel(CanalTexto channel);

		/*! Procura um canal de texto dentro do servidor
				@param channel_name nome do canal a ser procurado
				@return booleano true se o canal for encontrado e false se não for encontrado
		*/
		bool find_channel(std::string channel_name);

		/*! Procura um canal de texto dentro do servidor
				@param message mensagem a ser adicionada
				@param id id do criador da mensagem
				@param channel_name nome do canal em que a mensagem será adicionada
		*/
		void add_message(std::string message, int id, std::string channel_name);

		/*! Procura um canal de texto dentro do servidor
				@param usuarios vetor de usuários do servidor
				@param channel_name nome do canal em que a mensagem será adicionada
				@return booleana com true se houverem mensagens e false se não houverem
		*/
		bool show_channel_messages(std::string channel_name, std::vector<Usuario> usuarios);

};

#endif
