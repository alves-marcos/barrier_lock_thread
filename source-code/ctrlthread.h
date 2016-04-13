/**

###########################################
#										  #
#	+ Created By: Marcos alves            #
#									      #
#	+ Created Date: March 30th, 2016      #
#									      #
#	+ Last Modified: April 13th, 2016	  #
#									  	  #
#	+ Title: ctrlthread.h 			  	  #
#									      #
#	+ Email: marcos.alves@cc.ci.ufpb.br   #
#										  #
###########################################

**/

#ifndef CTRLTHREAD_H
#define CTRLTHREAD_H


namespace ctrl {

	class barriers {

		private:
			volatile int counter;
			volatile int number_threads;

		public:
			barriers(int number);
			barriers();

			void stay();
	};

	class locks {

		private:
			volatile int counter;
			volatile int locked;
			volatile int next;
			volatile int number_threads;
			volatile int *turn;

		public:
			locks(int number_threads);
			locks();

			void disable();
			void enable(int ticket = -1);
	};
}

#endif //CTRLTHREAD_H