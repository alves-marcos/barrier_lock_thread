/**

###########################################
#										  #
#	+ Created By: Marcos alves            #
#									      #
#	+ Created Date: March 30th, 2016      #
#									      #
#	+ Last Modified: April 7th, 2016	  #
#									  	  #
#	+ Title: runnable.h				      #
#									      #
#	+ Email: marcos.alves@cc.ci.ufpb.br   #
#										  #
###########################################

**/

#ifndef RUNNABLE_H
#define RUNNABLE_H

#include <cstring>
#include <string>
#include <vector>
#include "ioaction.h"

class Runnable {
	
	private:
	     static const char PATH_ANSWER[];
		 static const char PATH_FILES[];
		 static const char PATH_REQUEST[];

	public:
		static int answer(std::string name_file, std::string name_req);
		static std::string request(std::string name_req);

};

#endif //RUNNABLE_H
