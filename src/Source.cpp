#include <iostream>
#include <thread>/*Used for "sleep_for" functions that blocks execution of current process for a specified period of time*/
#include <chrono>/*Used for "sleep_for" functions that blocks execution of current process for a specified period of time*/
#include < cstdlib >/*Used for random number generator - rand()*/
#include <ctime>/*Used for random number generator - srand()*/
#include <algorithm>/*Used for removing elements from vector - remove()*/
#include <fstream>/*Used for outputting bunny results into file- ofstream()*/
#include  <conio.h> /*Used for _getch() and _kbhit()*/

#include "Header.h"


int main() {
	//Prints all outputs into a file including the bunny information and grid for each year
	std::ofstream file("Bunny_Farm.txt", std::ios::app);

	//makes rand() base itself on computer time
	srand(time(NULL));

	//creation of a linked list for the first 5 bunnies
	bunny* head = NULL;
	bunny* second = NULL;
	bunny* third = NULL;
	bunny* fourth = NULL;
	bunny* fifth = NULL;

	head = new bunny();
	second = new bunny();
	third = new bunny();
	fourth = new bunny();
	fifth = new bunny();

	head->setup();
	second->setup();
	third->setup();
	fourth->setup();
	fifth->setup();

	head->next = second;
	second->next = third;
	third->next = fourth;
	fourth->next = fifth;
	fifth->next = NULL;

	

	for (int t = 1; t < 12; t++) {
		std::cout << "----------Year " << t << "----------" << std::endl;
		file << "----------Year " << t << "----------" << std::endl;
		cull_check(&head);
		bunny_ai(&head, t);
		logic(&head);
		std::this_thread::sleep_for(std::chrono::seconds(2));
		draw(head);
		std::this_thread::sleep_for(std::chrono::seconds(2));

		if (_kbhit()) {
			char input = _getch();
			if (input == 'k' || input == 'K') {
				cull_check(&head, true);
				std::this_thread::sleep_for(std::chrono::seconds(1));

			}
		}


	}


	file.close();

}

