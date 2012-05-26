#ifdef __linux__
	#define RESET_COLOR "\033[0m"
	#define GREEN "\e[32m"
	#define RED "\e[31m"
#elif _WIN32
	#include <windows.h>
	#define GREEN "2"
	#define RED "11"
	#define RESET_COLOR "8"
#elif _WIN64
	#include <windows.h>
	#define GREEN "2"
	#define RED "11"
	#define RESET_COLOR "8"
#endif

#include <iostream>

//14 Colors Index: 1-14

class Color {
public:
	//Changes the current color of text
	static void color(std::string color);

	//Color to change, string to print, line=true for new line
	static void color(std::string color, std::string print, bool line);
};
