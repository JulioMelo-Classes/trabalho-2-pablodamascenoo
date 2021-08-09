#include "mensagem.h"
#include <iostream>
#include <string>
#include <ctime>


using namespace std;

Mensagem::Mensagem(string msg_content_, int owner_msg_){

    time_t now = time(0);

    tm *ltm = localtime(&now);

    string day = to_string(ltm->tm_mday);
    string month = to_string(ltm->tm_mon+1);
    string hour = to_string(ltm->tm_hour);
    string min = to_string(ltm->tm_min);


    if(stoi(day) < 10){
        day = "0"+day;
    }
    if(stoi(month) < 10){
        month = "0"+month;
    }
    if(stoi(hour) < 10){
        hour = "0"+hour;
    }
    if(stoi(min) < 10){
        min = "0"+min;
    }

    

    string date = "<"+day+"/"+month+"/"+to_string(ltm->tm_year+1900)+" - "+hour+":"+min+">";


    dateTime = date;
    msg_content = msg_content_;
    owner_msg = owner_msg_;
}

void Mensagem::show_message(){

    cout<<dateTime<<": "<<msg_content<<endl;

}

int Mensagem::getOwnerId(){
    return owner_msg;
}