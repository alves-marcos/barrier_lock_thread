/**

###########################################
#										  #
#	+ Created By: Marcos alves            #
#									      #
#	+ Created Date: March 30th, 2016      #
#									      #
#	+ Last Modified: April 9th, 2016	  #
#									  	  #
#	+ Title: ioaction.cpp			      #
#									      #
#	+ Email: marcos.alves@cc.ci.ufpb.br   #
#										  #
###########################################

**/

#include "ioaction.h"

void IOAction::copyto(const char *source, const char *destination) {

	std::ifstream input(source, std::ios::binary);

	std::ofstream output(destination, std::ios::binary | std::ios::trunc);

	output << input.rdbuf(); 

	output.close();

	input.close();
}

void IOAction::getByte(const char *path, unsigned long *bytes) {

	std::ifstream input(path, std::ios::binary);

	if(input.good()){

		input.seekg(0, std::ios::end);

		*bytes = input.tellg();

		input.close();

	} else
		*bytes = 0;
}

void IOAction::load_folder(const char *path, std::vector<std::string> *list_file) {
	
	DIR *directory;
    
    struct dirent *entry;
    
    if(directory = opendir(path)){
        
        while(entry = readdir(directory)){
        	
        	if(strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0)
            	list_file->push_back(entry->d_name);
        }

        closedir(directory);
    }
}

void IOAction::read_file(const char *path, char **destination) {

	std::ifstream input;

	std::string buffer, line;

	input.open(path, std::ios::binary);

	if(input.good()) {

		while(getline(input, line)) buffer += line + '\n';

		input.close();
	
		*destination = new char[buffer.size()];

		strcpy(*destination, buffer.c_str());
	} 
}

void IOAction::write_file(const char *path, const char *data) {

	std::ofstream output;

	output.open(path, std::ios::binary | std::ios::trunc);

	output << data;

	output.close();
}