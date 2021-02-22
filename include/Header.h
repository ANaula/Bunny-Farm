#include <string>
#ifndef Header
#define Header

class bunny {
public:
	static int bunny_count;
	char sex;
	std::string fur_color;
	std::string name;
	int age;
	bool mutant = false;
	bunny* next;
	bool dead = false;
	char grid_mark;
	int grid_x;
	int grid_y;

	void set_sex();

	void set_color();

	void set_name();
	void set_mutant();
	void setup();


	void set_bunny();

	std::string display_m();
};

void bunny_ai(bunny** ptp, int year);

void draw(bunny* ptb);

void logic(bunny** ptp);

void cull_check(bunny** head, bool manual_cull = false);
#endif