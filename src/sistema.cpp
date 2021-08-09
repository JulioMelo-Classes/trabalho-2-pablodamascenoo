#include "sistema.h"
#include "usuario.h"
#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;


auto iterador(map<int, pair<string, string>> users, int id){

  auto it = find_if(users.begin(), users.end(), [&](pair<int, pair<string, string>> entrada){
    if(entrada.first == id){  
      return true;
    }
    else{
      return false; 
    }
  });

  return it;
}


string Sistema::quit() {
  return "Saindo...";
}

string Sistema::create_user (const string email, const string senha, const string nome) {

  Usuario user(email, senha, nome, usuarios.size());

  for(auto it = usuarios.begin(); it<usuarios.end(); it++){
    if(it->email == email){
      return "Usuário já registrado";
    }
  }

  usuarios.push_back(user);

  return "User criado\n";
}

string Sistema::login(const string email, const string senha) {

  pair<string, string> serv_channel = {"", ""};

  for(auto i=usuarios.begin(); i<usuarios.end(); i++){

    if(i->email == email){
      if(i->senha == senha){
        auto it_log = usuariosLogados.find(i->id);
        if(it_log != usuariosLogados.end()){
          return "Usuário já está logado";
        }
        usuariosLogados.insert({i->id, serv_channel});
        return "Logado com sucesso!";/* Falta criar a excessão para usuário já logado */
      }
      else if(i->senha != senha){
        return "Senha incorreta!";
      }
    }
  }
  return "Usuário não encontrado";
}

string Sistema::disconnect(int id) {


  if(iterador(usuariosLogados, id) == usuariosLogados.end()){
    return "Usuário não está logado";
  }

  usuariosLogados.erase(id);
  return "Usuário desconectado";
}

string Sistema::create_server(int id, const string nome) {


  if(iterador(usuariosLogados, id)== usuariosLogados.end()){
    return "Usuário não está logado";
  }

  for(auto it = servidores.begin(); it<servidores.end(); it++){
    if(it->get_serv_name() == nome){
      return "Servidor já existe";
    }
  }

  Servidor server(nome, id);
  servidores.push_back(server);
  return "Servidor Criado";
}

string Sistema::set_server_desc(int id, const string nome, const string descricao) {


  if(iterador(usuariosLogados, id)== usuariosLogados.end()){
    return "Usuário não está logado";
  }

  for(auto it=servidores.begin(); it< servidores.end(); it++){
    if(it->get_serv_name() == nome){
      if(it->get_owner_id() == id){
        it->set_disc(descricao);
        return "Descrição do servidor modificada!";
      }
      else{
        return "Você não pode alterar a descrição de um servidor que não foi criado por você";
      }
    }
  }

  return "Servidor não encontrado";
}

string Sistema::set_server_invite_code(int id, const string nome, const string codigo) {

  if(iterador(usuariosLogados, id)== usuariosLogados.end()){
    return "Usuário não está logado";
  }

  for(auto it=servidores.begin(); it< servidores.end(); it++){
    if(it->get_serv_name() == nome){
      if(it->get_owner_id() == id){
        if(codigo != ""){
          it->set_invite(codigo);
          return "Código de convite modificado";
        }
        else{
          it->set_invite(codigo);
          return "Código de convite removido";
        }
      }
      else{
        return "Você não pode alterar o convite de um servidor que não foi criado por você";
      }
    }
  }

  return "Servidor não encontrado";
}

string Sistema::list_servers(int id) {

  if(iterador(usuariosLogados, id)== usuariosLogados.end()){
    return "Usuário não está logado";
  }

  for(auto it = servidores.begin(); it<servidores.end(); it++){
    cout<<it->get_serv_name()<<endl;
  }

  return "";
}

string Sistema::remove_server(int id, const string nome) {

  if(iterador(usuariosLogados, id)== usuariosLogados.end()){
    return "Usuário não está logado";
  }
  
  for(auto it_serv = servidores.begin(); it_serv<servidores.end(); it_serv++){
    if(it_serv->get_serv_name() == nome){
      if(it_serv->get_owner_id() == id){
        for(auto it_user = usuariosLogados.begin(); it_user != usuariosLogados.end(); it_user++){
          if(it_user->second.first == nome){
            it_user->second = {"",""};
          }
        }
        servidores.erase(it_serv);
        return "servidor removido";
      }
      else{
        return "Você não pode remover um servidor que não foi criado por você";
      }
    }
  }


  return "servidor não encontrado";
}

string Sistema::enter_server(int id, const string nome, const string codigo) {

  if(iterador(usuariosLogados, id) == usuariosLogados.end()){
    return "Usuário não está logado";
  }

  for(auto it_serv = servidores.begin(); it_serv<servidores.end(); it_serv++){
    if(it_serv->get_serv_name() == nome){
      if(it_serv->find_user(id)){
        return "usuário já está logado no servidor";
      }
      if((it_serv->get_invite() != "" && it_serv->get_invite() == codigo) || it_serv->get_invite() == "" || it_serv->get_owner_id() == id){
          auto it_user = usuariosLogados.find(id);
          it_user->second.first = nome;
          it_serv->add_user(id);
          return "Entrou no servidor com sucesso";
      }
      else if(it_serv->get_invite() != "" && codigo == ""){
        return "Servidor requer código de convite";
      }
      else{
        return "Código de convite incorreto";
      }
    }
  }

  return "Servidor não encontrado";
}

string Sistema::leave_server(int id, const string nome) {

  if(iterador(usuariosLogados, id) == usuariosLogados.end()){
    return "Usuário não está logado";
  }

  for(auto it_serv = servidores.begin(); it_serv<servidores.end(); it_serv++){
    if(it_serv->get_serv_name() == nome){
      if(it_serv->erase_user(id)){
        auto it_user = usuariosLogados.find(id);
        it_user->second = {"", ""};
        return "Saindo do servidor";
      }
      else{
        return "Usuário não está conectado ao servidor";
      }
    }
  }
  return "Servidor não encontrado";
}

string Sistema::list_participants(int id) {

  auto user = iterador(usuariosLogados, id);
  auto it_server = servidores.begin();


  if(user  == usuariosLogados.end()){
    return "Usuário não está logado";
  }

  for(auto it_server=servidores.begin(); it_server!=servidores.end(); it_server++){ /* talvez substituir isso*/
    if(it_server->get_serv_name() == user->second.first){
      break;
    }
  }

  if(it_server == servidores.end()){
    return "Usuário não está em um servidor";
  }

  for(auto it_user = usuarios.begin(); it_user!= usuarios.end(); it_user++){
    if(it_server->find_user(it_user->id)){
      cout<<it_user->nome<<endl;
    }
  }


  return "";
}

string Sistema::list_channels(int id) {

  auto user = iterador(usuariosLogados, id);
  auto it_server = servidores.begin();


  if(user  == usuariosLogados.end()){
    return "Usuário não está logado";
  }

  for(it_server=servidores.begin(); it_server!=servidores.end(); it_server++){ /* talvez substituir isso*/
    if(it_server->get_serv_name() == user->second.first){
      break;
    }
  }

  if(it_server == servidores.end()){
    return "Usuário não está em um servidor";
  }

  cout<<"#Canais de texto"<<endl;
  it_server->list_channel();
  cout<<"#fim canais de texto"<<endl;
  return "";
}

string Sistema::create_channel(int id, const string nome) {

  auto user = iterador(usuariosLogados, id);
  auto it_server = servidores.begin();


  if(user  == usuariosLogados.end()){
    return "Usuário não está logado";
  }

  for(it_server=servidores.begin(); it_server!=servidores.end(); it_server++){ /* talvez substituir isso*/
    if(it_server->get_serv_name() == user->second.first){
      break;
    }
  }

  if(it_server == servidores.end()){
    return "Usuário não está em um servidor";
  }

  if(it_server->find_channel(nome)){
    return "Canal de texto já existe";
  }

  CanalTexto canal = nome;
  it_server->add_channel(canal);

  return "canal de texto criado";
}

string Sistema::enter_channel(int id, const string nome) {

  auto user = iterador(usuariosLogados, id);
  auto it_server = servidores.begin();


  if(user  == usuariosLogados.end()){
    return "Usuário não está logado";
  }

  for(it_server=servidores.begin(); it_server!=servidores.end(); it_server++){ /* talvez substituir isso*/
    if(it_server->get_serv_name() == user->second.first){
      break;
    }
  }

  if(it_server == servidores.end()){
    return "Usuário não está em um servidor";
  }

  if(it_server->find_channel(nome)){

    user = usuariosLogados.find(id);
    user->second.second = nome;
    return "Entrou no canal de texto";
  }

  return "Canal de Texto não encontrado";
}

string Sistema::leave_channel(int id) {

  auto user = iterador(usuariosLogados, id);
  auto it_server = servidores.begin();


  if(user  == usuariosLogados.end()){
    return "Usuário não está logado";
  }

  for(it_server=servidores.begin(); it_server!=servidores.end(); it_server++){ /* talvez substituir isso*/
    if(it_server->get_serv_name() == user->second.first){
      break;
    }
  }

  if(it_server == servidores.end()){
    return "Usuário não está em um servidor";
  }

  user = usuariosLogados.find(id);
  if(user->second.second != ""){
    user->second.second = "";
    return "Saindo do canal de texto";
  }

  return "Usuário não está em um canal de texto";
}

string Sistema::send_message(int id, const string mensagem) {

  auto user = iterador(usuariosLogados, id);
  auto it_server = servidores.begin();

  if(user  == usuariosLogados.end()){
    return "Usuário não está logado";
  }

  for(it_server=servidores.begin(); it_server!=servidores.end(); it_server++){ /* talvez substituir isso*/
    if(it_server->get_serv_name() == user->second.first){
      break;
    }
  }

  if(it_server == servidores.end()){
    return "Usuário não está em um servidor";
  }

  if(it_server->find_channel(user->second.second)){

    it_server->add_message(mensagem, id, user->second.second);
    return "Mensagem cadastrada"; 
  }

  return "Usuário não está no canal";
}

string Sistema::list_messages(int id) {

  auto user = iterador(usuariosLogados, id);
  auto it_server = servidores.begin();

  if(user  == usuariosLogados.end()){
    return "Usuário não está logado";
  }

  for(it_server=servidores.begin(); it_server!=servidores.end(); it_server++){ /* talvez substituir isso*/
    if(it_server->get_serv_name() == user->second.first){
      break;
    }
  }

  if(it_server == servidores.end()){
    return "Usuário não está em um servidor";
  }

  if(it_server->find_channel(user->second.second)){

    if(!it_server->show_channel_messages(user->second.second, usuarios)){
      return "Não há mensagens para exibir.";
    }
    return "";
  }
  return "Usuário não está no canal";
}

