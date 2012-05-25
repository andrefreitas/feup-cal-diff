#include "diff.h"
#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

int main(){
	vector<string> words;

	words=Diff::splitToWords("O João correu        muito.");

	string diff;
	diff=Diff::computeLineDiff("O Joao corre mais uma vez Mario","O Mario corre depois");
	cout << "Dif: " << diff << endl;
	return 0;
}
