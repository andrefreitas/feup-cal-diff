#include "Diff.h"
#include "color.h"
#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

int main(){

	string a, b,result;
	int len;
	a = "hello how45454545 are you ?hu7jyihu";
	b = "hello who4554 are you ?3434343434343";

	len= Diff::retrieveLCS(a,b,result);

	cout << result<< endl;



	cout << "Colors Test" << endl<<endl;

	Color::showAllColors();
	cout<<endl;

	Color::changeTextColor(Color::darkGrey);
	cout << "Hello ";
	Color::changeTextColor(Color::red);
	cout << "how";
	Color::changeTextColor(Color::hGreen);
	cout << "who";
	Color::changeTextColor(Color::darkGrey);
	cout << " are you ?"<<endl;

	//OU TAMBEM
	Color::changeTextColor(Color::darkGrey, "Hello ", false);
	Color::changeTextColor(Color::red, "how", false);
	Color::changeTextColor(Color::hGreen, "who ", false);
	Color::changeTextColor(Color::darkGrey, " are you ?", true);

	cout<<"End press any key to end";
	getchar();
	return 0;
}
