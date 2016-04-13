###########################################
#										  #
#	+ Created By: Marcos alves            #
#									      #
#	+ Created Date: April 8th, 2016	      #
#									      #
#	+ Last Modified: April 13th, 2016	  #
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

#flags

FLAGS = -O2 -std=c++11 -Werror

# >>>>>>>> Rules default to create program <<<<<< #

all: main

main: main.o runnable.o ioaction.o ctrlthread.o
	$(CC) -g3 $(FLAGS) -pthread main.o runnable.o ioaction.o ctrlthread.o -o main
	./main

main.o: main.cpp
	$(CC) -c $(FLAGS) main.cpp

ioaction.o: ioaction.cpp
	$(CC) -c $(FLAGS) ioaction.cpp

runnable.o: runnable.cpp
	$(CC) -c $(FLAGS) runnable.cpp

ctrlthread.o: ctrlthread.cpp
	$(CC) -c $(FLAGS) ctrlthread.cpp

.PHONY: clean
	
clean:
	rm main *.o $(ANSWER)/*.ans

# >>>>>>>>>>>>>>>>>>> END FILE <<<<<<<<<<<<<<<<<<< #