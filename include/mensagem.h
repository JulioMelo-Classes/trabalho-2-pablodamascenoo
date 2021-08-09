#ifndef MENSAGEM_H
#define MENSAGEM_H

#include <iostream>
#include <string>


class Mensagem{

    private:

    std::string dateTime;
    std::string msg_content;
    int owner_msg;

    public:

    Mensagem(std::string msg_content_, int owner_msg_);

    void show_message();

    int getOwnerId();
};

#endif