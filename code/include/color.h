 /****************************************************************************
 * Author:      - André Freitas, p.andrefreitas@gmail.com
 * Author:      - Tiago Tavares, tiagomctavares@gmail.com
 * Author:      - Olivier Alves, olivieralves1@gmail.com
 * Copyright:   - 29/05/2012, CAL, FEUP
 ****************************************************************************/
#ifdef __APPLE__
    #define RESET_COLOR "\e[1;30m"
    #define GREEN "\e[1;32m"
    #define RED "\e[1;31m"
#elif __linux__
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

/** Color - A class for defining the consolo color
 * This class use static methods for changing the console output color.
 */

class Color {
public:
	/** Changes the current color of text
	 * @param color the color (use constants above)
	 */
	static void color(std::string color);

	/** Changes a color of a given string
	 * @param color the color (use constants above)
	 * @param print the string to be in the output
	 * @param line true if is a line (\n)
	 */
	static void color(std::string color, std::string print, bool line);
};
