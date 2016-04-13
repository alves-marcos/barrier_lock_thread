###########################################
#										  #
#	+ Created By: Marcos alves            #
#									      #
#	+ Created Date: April 8th, 2016	      #
#									      #
#	+ Last Modified: April 12th, 2016	  #
#									  	  #
#	+ Title: Makefile   				  #
#									      #
#	+ Email: marcos.alves@cc.ci.ufpb.br   #
#										  #
###########################################

# >>>>>>>>>>>>>>>> Variables <<<<<<<<<<<<<<<<<<<< #

# compiler

CC = g++

# variable directory

ANSWER = ../answ

# >>>>>>>> Rules default to create program <<<<<< #

all: main

main: main.o runnable.o ioaction.o ctrlthread.o
	$(CC) -g3 -std=c++11 -pthread main.o runnable.o ioaction.o ctrlthread.o -o main
	./main

main.o: main.cpp
	$(CC) -c -std=c++11 main.cpp

ioaction.o: ioaction.cpp
	$(CC) -c -std=c++11 ioaction.cpp

runnable.o: runnable.cpp
	$(CC) -c -std=c++11 runnable.cpp

ctrlthread.o: ctrlthread.cpp
	$(CC) -c -std=c++11 ctrlthread.cpp

.PHONY: clean
	
clean:
	rm main *.o $(ANSWER)/*.ans

# >>>>>>>>>>>>>>>>>>> END FILE <<<<<<<<<<<<<<<<<<< #