/**

###########################################
#										  #
#	+ Created By: Marcos alves            #
#									      #
#	+ Created Date: April 3th, 2016       #
#									      #
#	+ Last Modified: April 12th, 2016	  #
#									  	  #
#	+ Title: runnable.cpp			      #
#									      #
#	+ Email: marcos.alves@cc.ci.ufpb.br   #
#										  #
###########################################

**/

#include "runnable.h"


const char Runnable::PATH_ANSWER[] = "../answ/";

const char Runnable::PATH_FILES[] = "../files/";

const char Runnable::PATH_REQUEST[] = "../reqs/";


int Runnable::answer(std::string name_file, std::string name_req) {

	unsigned long number_bytes;

	name_req = "ans-" + name_req.substr(0, name_req.size() - 4) + ".ans";

	std::string output = PATH_ANSWER + name_req;

	std::string test = name_file.substr(0, 10);

	if((name_file.compare("ERROR BAD COMMAND") == 0) || (test.compare("ERROR FILE") == 0)) {
		
		IOAction::write_file(output.c_str(), name_file.c_str());
		
		IOAction::getByte(output.c_str(), &number_bytes);

		return number_bytes; 

	} else {
		
		name_file = PATH_FILES + name_file;

		IOAction::getByte(name_file.c_str(), &number_bytes);

		IOAction::copyto(name_file.c_str(), output.c_str());
		
		return number_bytes;
	}
}

std::string Runnable::request(std::string name_req) {

	bool flag = false;

	std::string get = "", type_req = "";

	char *answ;

	name_req = PATH_REQUEST + name_req;

	IOAction::read_file(name_req.c_str(), &answ);

	for(int i = 0 ; i < strlen(answ); i++) {

		if(answ[i] == ' ') { flag = true; continue; }

		if(answ[i] == '\n') break;

		if(flag)
			type_req += answ[i];
		else
			get += answ[i];
	} 

	if(get.compare("GET") == 0) {

		char *file_exist = NULL;

		name_req = PATH_FILES + type_req;

		IOAction::read_file(name_req.c_str(), &file_exist);

		if(file_exist == NULL)
			return "ERROR FILE " + type_req + " NOT FOUND";
		else
			return type_req;

	} else
		return "ERROR BAD COMMAND";
}