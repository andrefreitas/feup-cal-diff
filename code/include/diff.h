#ifndef DIFF_H
#define DIFF_H
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Diff{
	public:
	static vector<string> splitToWords(string line);
	static string computeLineDiff(string line1,string line2);
};

#endif
