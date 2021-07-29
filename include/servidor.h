#ifndef SERVIDOR_H
#define SERVIDOR_H

/*
CP1 classe servidor 60%
Tirei pontos pois vc implemetou tudo no .h
O owner tem que ser int e não uma string
*/
class Servidor{
	/*
		TODO implementação dos atributos e métodos
	*/
	private:
		std::string serv_name;
		std::string serv_desc;
		std::string owner;

	public:

		std::string get_serv_name(){
			return serv_name;
		}
		std::string get_owner(){
			return owner;
		}

		void set_disc(std::string serv_desc_){
			serv_desc = serv_desc_;
		}

		Servidor(std::string se_name ,std::string ow_name){
			serv_name = se_name;
			owner = ow_name;
		}

};

#endif
