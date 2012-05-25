#include "color.h"

void Color::changeTextColor(int color) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}


void Color::changeTextColor(int color, std::string print, bool line) {
	changeTextColor(color);
	std::cout<<print;

	if(line)
		std::cout<<std::endl;

	changeTextColor(colorDefault);
}

void Color::showAllColors() {
	std::cout << "All Colors:" << std::endl;
	for(int i=0; i<=maxColors; i++) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);
		std::cout <<i<<": All Colors." << std::endl;
	}
}
