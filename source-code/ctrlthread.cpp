/**

###########################################
#										  #
#	+ Created By: Marcos alves            #
#									      #
#	+ Created Date: March 30th, 2016      #
#									      #
#	+ Last Modified: April 12th, 2016	  #
#									  	  #
#	+ Title: ctrlthread.cpp			      #
#									      #
#	+ Email: marcos.alves@cc.ci.ufpb.br   #
#										  #
###########################################

**/

#include "ctrlthread.h"

namespace ctrl {

	ctrl::barriers::barriers(int number) : number_threads(number) {
		
		this->counter = 0;
		
		this->reset = 0;
	}

	ctrl::barriers::barriers() { /* no implementation */ }

	void ctrl::barriers::stay() {

		__sync_fetch_and_add(&this->counter, 1);

		while(this->counter < this->number_threads);
		
		__sync_fetch_and_add(&this->reset, 1);

		if(number_threads == this->reset) { 
			
			this->reset = 0;
			
			this->counter = 0;
		}
	}

	ctrl::locks::locks(int number): number_threads(number) { 

		this->turn = new int[this->number_threads];

		this->next = 0;

		this->counter = 0;
	}

	ctrl::locks::locks() { this->locked = 0; }

	void ctrl::locks::disable() {

		__sync_synchronize();

		this->next++;
		
		this->locked = 0;
	}

	void ctrl::locks::enable(int ticket) {

		if(ticket < 0)
			while(__sync_lock_test_and_set(&this->locked, 1));

		else {

			this->turn[ticket] = __sync_fetch_and_add(&this->counter, 1);

			while(this->turn[ticket] != this->next);
		}
	}
}