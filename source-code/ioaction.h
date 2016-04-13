/**

###########################################
#										  #
#	+ Created By: Marcos alves            #
#									      #
#	+ Created Date: March 30th, 2016      #
#									      #
#	+ Last Modified: April 9th, 2016	  #
#									  	  #
#	+ Title: ioaction.h				      #
#									      #
#	+ Email: marcos.alves@cc.ci.ufpb.br   #
#										  #
###########################################

**/

#ifndef IOACTION_H
#define IOACTION_H

#include <fstream> //ifstream, ofstream
#include <dirent.h> //lib C ler diretorio
#include <cstring> //strcmp, strcpy
#include <string> //strings
#include <vector> //vector

class IOAction {

	public:
		static void copyto(const char *source, const char *destination);
		static void getByte(const char *path, unsigned long *bytes);
		static void load_folder(const char *path, std::vector<std::string> *list_file);
		static void read_file(const char *path, char **destination);
		static void write_file(const char *path, const char *data);
};

#endif //IOACTION_H