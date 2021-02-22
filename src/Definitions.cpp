#include <iostream>
#include <vector>
#include <thread>/*Used for "sleep_for" functions that blocks execution of current process for a specified period of time*/
#include <chrono>/*Used for "sleep_for" functions that blocks execution of current process for a specified period of time*/
#include < cstdlib >/*Used for random number generator - rand()*/
#include <ctime>/*Used for random number generator - srand()*/
#include <algorithm>/*Used for removing elements from vector - remove()*/
#include <fstream>/*Used for outputting bunny results into file- ofstream()*/
#include  <conio.h> /*Used for _getch() and _kbhit()*/

#include "Header.h"






	void bunny::set_sex() {
		int gender = rand() % 2;
		if (gender == 0) {
			sex = 'm';
			grid_mark = 'm';
		}
		else {
			sex = 'f';
			grid_mark = 'f';
		}
	}

	void bunny::set_color() {
		std::string color[] = { "white","brown","black","spotted" };
		int rand_sel = rand() % 4;
		switch (rand_sel) {
		case 0:
			fur_color = color[0];
			break;
		case 1:
			fur_color = color[1];
			break;
		case 2:
			fur_color = color[2];
			break;
		case 3:
			fur_color = color[3];
			break;
		}
	}
	

	void bunny::set_name() {
		std::string m_names[] = { "Ace", "Apollo","Blue","Finn","Gunner","Gus","Rex","Rufus","Scooby","Brutus" };
		std::string f_names[] = { "Bailey","Molly","Coco","Sadie","Luna","Stella","Penny","Gracie","Zoe","Layla" };
		int rand_sel = rand() % 10;
		bunny_count++;
		if (sex == 'm') {
			name = m_names[rand_sel];
		}
		else {
			name = f_names[rand_sel];
		}
	}
	void bunny::set_mutant() {
		int m = rand() % 11;
		if (m == 1) {
			mutant = true;
			grid_mark = 'x';
		}
	}
	void bunny::setup() {
		set_sex();
		set_color();
		set_name();

	}


	void bunny::set_bunny() {
		set_sex();
		set_color();
		set_name();
		set_mutant();
	}

	std::string bunny::display_m() {
		std::string status;
		if (mutant == false) {
			status = "Non-mutant";
			return status;
		}
		else {
			status = "Mutant";
			return status;
		}

	}

int bunny::bunny_count = 0;
std::vector<std::vector<char>>grid =
{ {'.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.'},
{'.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.'},
{'.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.'},
{'.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.'},
{'.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.'},
{'.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.'},
{'.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.'},
{'.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.'},
{'.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.'},
{'.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.'},
{'.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.'},
{'.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.'},
{'.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.'},
{'.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.'},
{'.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.'},
{'.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.'},
{'.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.'},
{'.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.'},
{'.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.'},
{'.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.'},
{'.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.'},
{'.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.'},
{'.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.'},
{'.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.'},
{'.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.'}
};

//Function that places 1st year bunnies on the grid randomly or moves the bunnies randomly
void bunny_ai(bunny** ptp, int year) {
	std::ofstream file("Bunny_Farm.txt", std::ios::app);

	bunny* traverse = *ptp;
	if (traverse == NULL) {
		std::cout << "No bunnies - No bunny ai" << std::endl;
		file << "No bunnies - No bunny ai" << std::endl;

		return;
	}

	while (traverse != NULL) {
		bool done = false;
		if (year == 1) {
			traverse->grid_x = rand() % 25;
			traverse->grid_y = rand() % 25;
			grid[traverse->grid_y][traverse->grid_x] = traverse->grid_mark;

		}
		else {
			std::vector <int> dir_choice = { 0,1,2,3 };

			while (done != true && dir_choice.size() != 0) {
				int range = dir_choice.size();

				int direction = rand() % (range);
				switch (dir_choice[direction]) {
				case 0:
					if (traverse->grid_y != 0 && grid[traverse->grid_y - 1][traverse->grid_x] == '.') {
						grid[traverse->grid_y][traverse->grid_x] = '.';
						traverse->grid_y--;
						grid[traverse->grid_y][traverse->grid_x] = traverse->grid_mark;
						done = true;

					}
					else {

						dir_choice.erase(std::remove(dir_choice.begin(), dir_choice.end(), 0), dir_choice.end());


					}
					break;
				case 1:
					if (traverse->grid_x != 24 && grid[traverse->grid_y][traverse->grid_x + 1] == '.') {
						grid[traverse->grid_y][traverse->grid_x] = '.';
						traverse->grid_x++;
						done = true;
						grid[traverse->grid_y][traverse->grid_x] = traverse->grid_mark;

					}
					else {
						dir_choice.erase(std::remove(dir_choice.begin(), dir_choice.end(), 1), dir_choice.end());


					}
					break;
				case 2:
					if (traverse->grid_y != 24 && grid[traverse->grid_y + 1][traverse->grid_x] == '.') {
						grid[traverse->grid_y][traverse->grid_x] = '.';
						traverse->grid_y++;
						done = true;
						grid[traverse->grid_y][traverse->grid_x] = traverse->grid_mark;


					}
					else {
						dir_choice.erase(std::remove(dir_choice.begin(), dir_choice.end(), 2), dir_choice.end());


					}
					break;
				case 3:
					if (traverse->grid_x != 0 && grid[traverse->grid_y][traverse->grid_x - 1] == '.') {
						grid[traverse->grid_y][traverse->grid_x] = '.';
						traverse->grid_x--;
						done = true;
						grid[traverse->grid_y][traverse->grid_x] = traverse->grid_mark;


					}
					else {
						dir_choice.erase(std::remove(dir_choice.begin(), dir_choice.end(), 3), dir_choice.end());

					}
					break;
				}

			}
			if (dir_choice.size() == 0) {
				std::cout << traverse->name << " could not move anywhere since there was no room" << std::endl;
				file << traverse->name << " could not move anywhere since there was no room" << std::endl;

			}

		}
		traverse = traverse->next;
	}
	file.close();
}

//Function that prints the info on each bunny, the total population, and the grid
void draw(bunny* ptb) {
	std::ofstream file("Bunny_Farm.txt", std::ios::app);

	bunny* head = ptb;
	if (head == NULL) {
		std::cout << "No bunnies in list, nothing to print" << std::endl;
		file << "No bunnies in list, nothing to print" << std::endl;
		std::this_thread::sleep_for(std::chrono::seconds(2));
		for (int i = 0; i < 25; i++) {
			for (int b = 0; b < 25; b++) {
				std::cout << grid[i][b];
				file << grid[i][b];

			}
			std::cout << std::endl;
			file << std::endl;

		}
		std::this_thread::sleep_for(std::chrono::seconds(2));

		return;
	}
	while (head != NULL) {
		std::cout << "Name: " << head->name << " | Age: " << head->age << " | Sex: " << head->sex << " | Color: " << head->fur_color << " | Mutant status: " << head->display_m() << std::endl;
		file << "Name: " << head->name << " | Age: " << head->age << " | Sex: " << head->sex << " | Color: " << head->fur_color << " | Mutant status: " << head->display_m() << std::endl;

		head = head->next;
	}
	std::this_thread::sleep_for(std::chrono::seconds(2));

	std::cout << "Population: " << bunny::bunny_count << std::endl;
	file << "Population: " << bunny::bunny_count << std::endl;

	std::this_thread::sleep_for(std::chrono::seconds(2));

	for (int i = 0; i < 25; i++) {
		for (int b = 0; b < 25; b++) {
			std::cout << grid[i][b];
			file << grid[i][b];

		}
		std::cout << std::endl;
		file << std::endl;

	}

	file.close();
}



void logic(bunny** ptp) {
	std::ofstream file("Bunny_Farm.txt", std::ios::app);

	bunny* traverse = *ptp;



	//--------------Check to see if list is empty-----------------
	if (traverse == NULL) {
		std::cout << "No bunnies left" << std::endl;
		file << "No bunnies left" << std::endl;

		return;
	}

	//---------Process that deletes bunnies older than 10 years old-----------------
	bunny* age_check_ptr = *ptp;
	bunny* previous = NULL;
	int deaths = 0;


	while (age_check_ptr != NULL) {
		if (age_check_ptr->mutant == false && age_check_ptr->age >= 5) {
			age_check_ptr->dead = true;
			deaths++;
		}
		else if (age_check_ptr->mutant == true && age_check_ptr->age >= 10) {
			age_check_ptr->dead = true;
			deaths++;
		}
		age_check_ptr = age_check_ptr->next;
	}
	for (int d = 0; d < deaths; d++) {
		age_check_ptr = *ptp;
		previous = NULL;

		if (age_check_ptr != NULL && age_check_ptr->dead == true) {
			*ptp = age_check_ptr->next;

			if (age_check_ptr->mutant == false) {
				std::cout << "Bunny " << age_check_ptr->name << " has died" << std::endl;
				file << "Bunny " << age_check_ptr->name << " has died" << std::endl;
			}
			else {
				std::cout << "Mutant Bunny " << age_check_ptr->name << " has died" << std::endl;
				file << "Mutant Bunny " << age_check_ptr->name << " has died" << std::endl;
			}

			grid[age_check_ptr->grid_y][age_check_ptr->grid_x] = '.';
			bunny::bunny_count--;
			delete age_check_ptr;
			continue;
		}
		else {
			while (age_check_ptr != NULL && age_check_ptr->dead != true) {
				previous = age_check_ptr;
				age_check_ptr = age_check_ptr->next;
			}
			if (age_check_ptr->mutant == false) {
				std::cout << "Bunny " << age_check_ptr->name << " has died" << std::endl;
				file << "Bunny " << age_check_ptr->name << " has died" << std::endl;
			}
			else {
				std::cout << "Mutant Bunny " << age_check_ptr->name << " has died" << std::endl;
				file << "Mutant Bunny " << age_check_ptr->name << " has died" << std::endl;
			}


			previous->next = age_check_ptr->next;
			grid[age_check_ptr->grid_y][age_check_ptr->grid_x] = '.';
			bunny::bunny_count--;

			delete age_check_ptr;
		}
	}
	std::this_thread::sleep_for(std::chrono::seconds(1));

	//-------Process that creates new bunnies and adds them to the linked list as well as ages the bunnies-----------

	traverse = *ptp;

	int mature_m = 0;
	int mature_f = 0;
	std::vector <int> x_coordinates = {};
	std::vector<int> y_coordinates = {};
	std::vector<std::string> furcolorlist = {};


	while (traverse != NULL) {
		if (traverse->mutant == false && traverse->sex == 'm' && traverse->age >= 2) {
			mature_m++;
		}
		else if (traverse->mutant == false && traverse->sex == 'f' && traverse->age >= 2) {
			mature_f++;
			x_coordinates.push_back(traverse->grid_x);
			y_coordinates.push_back(traverse->grid_y);
			furcolorlist.push_back(traverse->fur_color);

		}
		if (traverse->mutant == false && traverse->age >= 2) {
			if (traverse->sex == 'm') {
				traverse->grid_mark = 'M';
				grid[traverse->grid_y][traverse->grid_x] = traverse->grid_mark;
			}
			else if (traverse->sex == 'f') {
				traverse->grid_mark = 'F';
				grid[traverse->grid_y][traverse->grid_x] = traverse->grid_mark;

			}
		}
		else if (traverse->mutant == true && traverse->age >= 2) {
			traverse->grid_mark = 'X';
			grid[traverse->grid_y][traverse->grid_x] = traverse->grid_mark;
		}
		traverse->age++;

		traverse = traverse->next;
	}


	int born_bunnies = 0;
	if (mature_m > 0 && mature_f > 0) {
		for (int i = 0; i < mature_m; i++) {
			for (int u = 0; u < mature_f; u++) {
				born_bunnies++;

			}
		}
	}
	std::cout << "Mature Males: " << mature_m << " | Mature Females: " << mature_f <<" | Bunnnies to be born: "<<born_bunnies <<std::endl;

	int bunnies_created = 0;

	if (born_bunnies > 0) {

		for (int m = 0; m < mature_f; m++) {
			int i = 0;

			while (i < 4 && bunnies_created!=born_bunnies) {

				bool born = false;
				bunny* new_bunny = new bunny();
				bunny* last = *ptp;
				new_bunny->set_bunny();
				new_bunny->next = NULL;
				new_bunny->fur_color = furcolorlist[m];
				if (y_coordinates[m] != 0 && grid[y_coordinates[m] - 1][x_coordinates[m]] == '.') {
					new_bunny->grid_x = x_coordinates[m];
					new_bunny->grid_y = y_coordinates[m] - 1;
					grid[new_bunny->grid_y][new_bunny->grid_x] = new_bunny->grid_mark;
					born = true;
					bunnies_created++;
				}
				else if (x_coordinates[m] != 24 && grid[y_coordinates[m]][x_coordinates[m] + 1] == '.') {
					new_bunny->grid_x = x_coordinates[m] + 1;
					new_bunny->grid_y = y_coordinates[m];
					grid[new_bunny->grid_y][new_bunny->grid_x] = new_bunny->grid_mark;
					born = true;
					bunnies_created++;


				}
				else if (y_coordinates[m] != 24 && grid[y_coordinates[m] + 1][x_coordinates[m]] == '.') {
					new_bunny->grid_x = x_coordinates[m];
					new_bunny->grid_y = y_coordinates[m] + 1;
					grid[new_bunny->grid_y][new_bunny->grid_x] = new_bunny->grid_mark;
					born = true;
					bunnies_created++;


				}
				else if (x_coordinates[m] != 0 && grid[y_coordinates[m]][x_coordinates[m] - 1] == '.') {
					new_bunny->grid_x = x_coordinates[m] - 1;
					new_bunny->grid_y = y_coordinates[m];
					grid[new_bunny->grid_y][new_bunny->grid_x] = new_bunny->grid_mark;
					born = true;
					bunnies_created++;

				}
				else {
					delete new_bunny;
					std::cout << "Bunny deleted due to no space around its mother! " << std::endl;
					file << "Bunny deleted due to no space around its mother! " << std::endl;

					i++;
					bunny::bunny_count--;

					continue;
				}

				if (born == true) {
					while (last->next != NULL) {
						last = last->next;
					}
					last->next = new_bunny;
					if (new_bunny->mutant == false) {
						std::cout << "Bunny " << new_bunny->name << " has been born!" << std::endl;
						file << "Bunny " << new_bunny->name << " has been born!" << std::endl;
					}
					else {
						std::cout << "Mutant Bunny " << new_bunny->name << " has been born!" << std::endl;
						file << "Mutant Bunny " << new_bunny->name << " has been born!" << std::endl;

					}

					i++;
				}

			}

			if (bunnies_created == born_bunnies) {
				std::cout << "Bunnies_Created: "<<bunnies_created << std::endl;
				break;
			}
		}

		if (bunnies_created < born_bunnies) {
			std::cout << "Bunnies_created: " << bunnies_created << " | Bunnies deleted due to no space: " << born_bunnies - bunnies_created << std::endl;
		}
	}
	else {
		std::cout << "No bunnies born this year" << std::endl;
	}

	
	
	std::this_thread::sleep_for(std::chrono::seconds(1));

	file.close();
}

//function that deletes half of the bunny population if population reaches a ceratin number or if prompted to
void cull_check(bunny** head, bool manual_cull) {
	std::ofstream file("Bunny_Farm.txt", std::ios::app);

	if (bunny::bunny_count > 50 || manual_cull == true) {
		std::cout << "---------Cull-----------" << std::endl;
		file << "---------Cull-----------" << std::endl;


		int cull_num = bunny::bunny_count / 2;
		for (int i = 0; i < (cull_num); i++) {
			bunny* cull_pointer = *head;
			bunny* cull_pointer_b = NULL;
			int bunny_num = rand() % (bunny::bunny_count);
			int count = 0;
			if (bunny_num == 0) {
				*head = cull_pointer->next;
				if (cull_pointer->mutant == false) {
					std::cout << "Bunny " << cull_pointer->name << " has been culled" << std::endl;
					file << "Bunny " << cull_pointer->name << " has been culled" << std::endl;
				}
				else {
					std::cout << "Mutant Bunny " << cull_pointer->name << " has been culled" << std::endl;
					file << "Mutant Bunny " << cull_pointer->name << " has been culled" << std::endl;
				}

				grid[cull_pointer->grid_y][cull_pointer->grid_x] = '.';

				delete cull_pointer;
				bunny::bunny_count--;
				continue;
			}

			while (count < bunny_num && cull_pointer->next != NULL) {
				cull_pointer_b = cull_pointer;
				cull_pointer = cull_pointer->next;
				count++;
			}

			if (cull_pointer->next == NULL) {
				cull_pointer_b->next = NULL;
				if (cull_pointer->mutant == false) {
					std::cout << "Bunny " << cull_pointer->name << " has been culled" << std::endl;
					file << "Bunny " << cull_pointer->name << " has been culled" << std::endl;
				}
				else {
					std::cout << "Mutant Bunny " << cull_pointer->name << " has been culled" << std::endl;
					file << "Mutant Bunny " << cull_pointer->name << " has been culled" << std::endl;
				}

				grid[cull_pointer->grid_y][cull_pointer->grid_x] = '.';
				delete cull_pointer;
				bunny::bunny_count--;

			}
			else {
				cull_pointer_b->next = cull_pointer->next;
				if (cull_pointer->mutant == false) {
					std::cout << "Bunny " << cull_pointer->name << " has been culled" << std::endl;
					file << "Bunny " << cull_pointer->name << " has been culled" << std::endl;
				}
				else {
					std::cout << "Mutant Bunny " << cull_pointer->name << " has been culled" << std::endl;
					file << "Mutant Bunny " << cull_pointer->name << " has been culled" << std::endl;
				}

				grid[cull_pointer->grid_y][cull_pointer->grid_x] = '.';

				delete cull_pointer;
				bunny::bunny_count--;

			}

		}
	}

	file.close();
}

