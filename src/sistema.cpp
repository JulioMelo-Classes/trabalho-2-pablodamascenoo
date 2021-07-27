#include "sistema.h"
#include "usuario.h"
#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

/* COMANDOS */
string Sistema::quit() {
  return "Saindo...";
}

string Sistema::create_user (const string email, const string senha, const string nome) {

  Usuario user(email, senha, nome);

  usuarios.push_back(user);

  return "User criado";  /* Falta criar as exceções para erros */
}

string Sistema::login(const string email, const string senha) {

  pair<string, string> user = {email, senha};

  for(auto i=usuarios.begin(); i<usuarios.end(); i++){

    if(i->email == email){
      if(i->senha == senha){
        usuariosLogados.insert({usuariosLogados.size(), user});
        return "Logado com sucesso!";/* Falta criar as exceções para erros */
      }
      else if(i->senha != senha){
        return "Senha incorreta!";
      }
    }
  }
  return "Usuário não encontrado";
}

string Sistema::disconnect(int id) {

  /* Criar uma função para substituir isso */

  auto it = find_if(usuariosLogados.begin(), usuariosLogados.end(), [&](pair<int, pair<string, string>> entrada){
    if(entrada.first == id){  
      return true;
    }
    else{
      return false; 
    }
  });

  if(it != usuariosLogados.end()){
    usuariosLogados.erase(id);
    return "Usuário desconectado";
  }
  else{
    return "Usuário não está logado";
  }
}

string Sistema::create_server(int id, const string nome) {

  string owner;

  /* Criar uma função para substituir isso */
  auto it = find_if(usuariosLogados.begin(), usuariosLogados.end(), [&](pair<int, pair<string, string>> entrada){
    if(entrada.first == id){
      owner = entrada.second.first; 
      return true;
    }
    else{
      return false; 
    }
  });

  if(it != usuariosLogados.end()){
    Servidor server(nome, owner);
    servidores.push_back(server);
    return "Servidor Criado";    /* Adicionar exceção para servidor já existente */
  }
  else{
    return "Usuário não está logado";
  }
}

string Sistema::set_server_desc(int id, const string nome, const string descricao) {

  string owner;
  string response;

  /* Criar uma função para substituir isso */
    auto it = find_if(usuariosLogados.begin(), usuariosLogados.end(), [&](pair<int, pair<string, string>> entrada){
    if(entrada.first == id){
      owner = entrada.second.first; 
      return true;
    }
    else{
      return false; 
    }
  });

  if(it == usuariosLogados.end()){
      return "Usuário não está logado";
  }

  for(auto it=servidores.begin(); it< servidores.end(); it++){
    if(it->get_serv_name() == nome){
      if(it->get_owner() == owner){
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
  return "set_server_invite_code NÃO IMPLEMENTADO";
}

string Sistema::list_servers(int id) {
  return "list_servers NÃO IMPLEMENTADO";
}

string Sistema::remove_server(int id, const string nome) {
  return "remove_server NÃO IMPLEMENTADO";
}

string Sistema::enter_server(int id, const string nome, const string codigo) {
  return "enter_server NÃO IMPLEMENTADO";
}

string Sistema::leave_server(int id, const string nome) {
  return "leave_server NÃO IMPLEMENTADO";
}

string Sistema::list_participants(int id) {
  return "list_participants NÃO IMPLEMENTADO";
}

string Sistema::list_channels(int id) {
  return "list_channels NÃO IMPLEMENTADO";
}

string Sistema::create_channel(int id, const string nome) {
  return "create_channel NÃO IMPLEMENTADO";
}

string Sistema::enter_channel(int id, const string nome) {
  return "enter_channel NÃO IMPLEMENTADO";
}

string Sistema::leave_channel(int id) {
  return "leave_channel NÃO IMPLEMENTADO";
}

string Sistema::send_message(int id, const string mensagem) {
  return "send_message NÃO IMPLEMENTADO";
}

string Sistema::list_messages(int id) {
  return "list_messages NÃO IMPLEMENTADO";
}




/* IMPLEMENTAR MÉTODOS PARA OS COMANDOS RESTANTES */
