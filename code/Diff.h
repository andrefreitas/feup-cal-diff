#ifndef DIFF_H
#define DIFF_H
#include <iostream>
#include <string>
using namespace std;

class Diff{
	public:
	static int computeLCSLen(string a, string b);
	static int retrieveLCS(string a,string b, string &sequence);
};

#endif
