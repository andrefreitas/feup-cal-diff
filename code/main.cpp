#include "Diff.h"
#include <iostream>
#include <string>
using namespace std;

int main(){

	string a, b,result;
	int len;
	a = "hello how45454545 are you ?hu7jyihu";
	b = "hello who4554 are you ?3434343434343";

	len= Diff::retrieveLCS(a,b,result);

	cout << result<< endl;
	return 0;
}
