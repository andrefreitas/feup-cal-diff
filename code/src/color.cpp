#include "color.h"
#include <iostream>
using namespace std;

void Color::color(std::string color) {
     #ifdef __APPLE__
        cout<<color;
    #elif __linux__
		cout<<color;
	#elif _WIN32
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), atoi(color.c_str()));
	#elif _WIN64
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), atoi(color.c_str()));
	#endif

}

void Color::color(std::string color, std::string print, bool line) {
	Color::color(color);
	std::cout<<print;

	if(line)
		std::cout<<std::endl;

	Color::color(RESET_COLOR);
}