#include "canaltexto.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;


CanalTexto::CanalTexto(string c_name){
    channel_name = c_name;
}


string CanalTexto::get_channel_name(){
    return channel_name;
}

void CanalTexto::add_message(string message, int id){
    Mensagem mensagem(message, id);
    messages.push_back(mensagem);
}

void CanalTexto::show_messages(vector<Usuario> usuarios){

    for(auto it_msg = messages.begin(); it_msg!=messages.end(); it_msg++){
        for(auto it_user = usuarios.begin(); it_user!=usuarios.end(); it_user++){
            if(it_msg->getOwnerId() == it_user->get_user_id()){
                cout<<it_user->get_user_name();
                break;
            }
        }
        it_msg->show_message();
    }
}

int CanalTexto::msg_number(){
	return messages.size();
}