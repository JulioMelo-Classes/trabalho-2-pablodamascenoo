#include "servidor.h"
#include "canaltexto.h"
#include "usuario.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;


Servidor::Servidor(string se_name , int id){
	serv_name = se_name;
	owner_id = id;
}

string Servidor::get_invite(){
	return codigoConvite;
}

void Servidor::set_invite(string codigo){
	codigoConvite = codigo;
}

string Servidor::get_serv_name(){
	return serv_name;
}

int Servidor::get_owner_id(){
	return owner_id;
}

void Servidor::set_disc(string serv_desc_){
	serv_desc = serv_desc_;
}

void Servidor::add_user(int user_id){
	users_id.push_back(user_id);
}

bool Servidor::erase_user(int id_){

	for(auto it_user_id = users_id.begin(); it_user_id!=users_id.end(); it_user_id++){
		if(*it_user_id == id_){
			users_id.erase(it_user_id);
			return true;
		}
	}
	return false;
}

bool Servidor::find_user(int id_){

	for(auto it_user_id = users_id.begin(); it_user_id!=users_id.end(); it_user_id++){
	    if(*it_user_id == id_){
			return true;
	    }
	}
	return false;
}

void Servidor::list_channel(){

    for(auto it_ch = serv_channels.begin(); it_ch!=serv_channels.end(); it_ch++){
        cout<<it_ch->get_channel_name()<<endl;
    }
}

void Servidor::add_channel(CanalTexto channel){

    serv_channels.push_back(channel);
}

bool Servidor::find_channel(string channel_name){

	for(auto it_ch = serv_channels.begin(); it_ch!=serv_channels.end(); it_ch++){
		if(it_ch->get_channel_name()==channel_name){
			return true;
		}
	}
	return false;
}

void Servidor::add_message(string message, int id, string channel_name){

	for(auto it_ch = serv_channels.begin(); it_ch!=serv_channels.end(); it_ch++){
		if(it_ch->get_channel_name()==channel_name){
			it_ch->add_message(message, id);
			break;
		}
	}
}

bool Servidor::show_channel_messages(string channel_name, vector<Usuario>usuarios){

	for(auto it_ch = serv_channels.begin(); it_ch!=serv_channels.end(); it_ch++){
		if(it_ch->msg_number()==0){
			return false;
		}
		if(it_ch->get_channel_name()==channel_name){
			it_ch->show_messages(usuarios);
			return true;
		}
	}
	return false;
}

