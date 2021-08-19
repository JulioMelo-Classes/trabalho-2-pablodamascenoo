#ifndef MENSAGEM_H
#define MENSAGEM_H

#include <iostream>
#include <string>

/*
Cp2 ok

Documentação 0,8, faltou documentar os atributos
*/
class Mensagem{

    private:

    std::string dateTime;
    std::string msg_content;
    int owner_msg;

    public:

    /*! Construtor da classe Mensagem
        @param msg_content_ string com o conteúdo da mensagem
        @param owner_msg_ id do dono da mensagem
	*/
    Mensagem(std::string msg_content_, int owner_msg_);

    /*! Imprime o conteúdo da mensagem com o formato de horário <DD/MM/YYYY - HH:MM>
	*/
    void show_message();

    /*!
        @return retorna o id do dono da mensagem
	*/
    int getOwnerId();
};

#endif