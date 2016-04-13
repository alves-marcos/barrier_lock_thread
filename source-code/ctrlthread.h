/**

###########################################
#										  #
#	+ Created By: Marcos alves            #
#									      #
#	+ Created Date: March 30th, 2016      #
#									      #
#	+ Last Modified: April 12th, 2016	  #
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
			int counter;
			int number_threads;
			int reset;

		public:
			barriers(int number);
			barriers();

			void stay();
	};

	class locks {

		private:
			int counter;
			int locked;
			int next;
			int number_threads;
			int *turn;

		public:
			locks(int number_threads);
			locks();

			void disable();
			void enable(int ticket = -1);
	};
}

#endif //CTRLTHREAD_H