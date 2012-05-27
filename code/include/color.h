#ifdef __linux__
	#define RESET_COLOR "\033[0m"
	#define GREEN "\e[32m"
	#define RED "\e[31m"
#elif _WIN32
	#include <windows.h>
	#define GREEN "2"
	#define RED "4"
	#define RESET_COLOR "7"
#elif _WIN64
	#include <windows.h>
	#define GREEN "2"
	#define RED "4"
	#define RESET_COLOR "7"
#endif

#include <iostream>

// A class with static methods for changing the

class Color {
public:
	//Changes the current color of text
	static void color(std::string color);

	//Color to change, string to print, line=true for new line
	static void color(std::string color, std::string print, bool line);
};
