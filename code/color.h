#include <windows.h>
#include <iostream>

//14 Colors Index: 1-14

class Color {
private:
	static const int colorDefault = 8;
	static const int maxColors = 14;
public:
	enum COLORS { black=0, blue, green, cyan, red, purple, yellow, grey, darkGrey, hBlue, hGreen, hRed, hPurple, hYellow, hWhite };

	//Changes the current color of text
	static void changeTextColor(int color);

	//Color to change, string to print, line=true for new line
	static void changeTextColor(int color, std::string print, bool line);

	//Print all colors and it respective int
	static void showAllColors();
};
