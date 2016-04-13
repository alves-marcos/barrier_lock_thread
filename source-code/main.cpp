/**

###########################################
#										  #
#	+ Created By: Marcos alves            #
#									      #
#	+ Created Date: April 3th, 2016	      #
#									      #
#	+ Last Modified: April 13th, 2016	  #
#									  	  #
#	+ Title: main.cpp					  #
#									      #
#	+ Email: marcos.alves@cc.ci.ufpb.br   #
#										  #
###########################################

**/

#include <iostream> // cout, cin
#include <thread> //joins
#include <string> //strings
#include <algorithm> //sort
#include "ioaction.h"
#include "runnable.h"
#include "ctrlthread.h"

/* global variables */

unsigned long _number_bytes = 0;

ctrl::locks _lock;

ctrl::barriers _barrier_answ, _barrier_req;


/* function declaration */

void activity(int index, std::string name_req);


/* function definition */

int main (int argc, char **argv) {

	std::vector<std::string> directory;

	std::vector<std::thread> thread_activ;

	std::vector<std::string> buffer_request;

	std::string choice;

	IOAction::load_folder("../reqs/", &directory);

	std::sort(directory.begin(), directory.end());

	std::cout << "Email: marcos.alves@cc.ci.ufpb.br \t Autor: Marcos Alves" << std::endl;

	std::cout << "\n##################### LOCKS E BARREIRAS ####################\n" << std::endl; 

	std::cout << "@ FORMATO: req(index).req \t MAXIMO REQUEST: 1000\n" << std::endl;

	for(unsigned int i = 0 ; i < directory.size(); i++)
		std::cout <<"..:: /"<< directory[i] << std::endl;
	
	std::cout << "\n$ Digite a(s) requisição(ões): ";

	std::getline(std::cin, choice);

	int length = 0;

	if(choice.compare("all") == 0){
		
		length = directory.size();

		std::cout << "\n> Processando " << length << " requisição(ões)\n" << std::endl;

		_lock = ctrl::locks(length);
		
		_barrier_answ = ctrl::barriers(length);

		_barrier_req = ctrl::barriers(length);

		for(int i = 0 ; i < length ; i++)
			thread_activ.push_back(std::thread(activity, i, directory[i]));

 	} else {

 		std::string name_temp;

 		for(int i = 0 ; i < choice.size() ; i++) {

 			if(choice[i] == ' ') {

 				name_temp = "req" + name_temp + ".req";

 				buffer_request.push_back(name_temp);

 				name_temp = "";

 				continue;
 			}

 			name_temp += choice[i];
 		}

 		length = buffer_request.size();

		std::cout << "\n> Processando " << length << " requisição(ões)\n" << std::endl;

		_lock = ctrl::locks(length);

		_barrier_answ = ctrl::barriers(length);

		_barrier_req = ctrl::barriers(length);
		
 		for(int i = 0 ; i < length ; i++)
			thread_activ.push_back(std::thread(activity, i, buffer_request[i]));
 	}

	for(auto &thr: thread_activ) thr.join();

	std::cout << "\n* Respostas criadas com sucesso. Total: " 
			  << _number_bytes << " bytes\n" << std::endl;

	return 0; 
}

/* function  definition */

void activity(int index, std::string name_req) {

	std::string req = Runnable::request(name_req); 

	std::cout << "@ Wait: " << index + 1 << std::endl;

	_barrier_answ.stay();

	_lock.enable(index);
	
	std::cout << "~ Critical Section: "<< index + 1 << std::endl;
	
	std::cout << "+ [Thread " << index + 1 << "] Processando " << name_req << std::endl;

	_number_bytes += Runnable::answer(req, name_req);

	_lock.disable();

	_barrier_req.stay();
}