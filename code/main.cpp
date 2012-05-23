#include "Diff.h"
#include <iostream>
#include <string>
using namespace std;

int main(){

	string result, a, b;
	a = "hello how are you ?";
	b = "hello who are you ?";

	result = Diff::computeLCS(a,b);

	cout << "olá mundo" << endl;
	return 0;
}
