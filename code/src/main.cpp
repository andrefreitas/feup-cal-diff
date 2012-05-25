#include "diff.h"
#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

int main(){
	vector<string> words;

	words=Diff::splitToWords("O João correu        muito.");
	for(int unsigned i=0; i<words.size(); i++){
		cout <<":" << words[i] << ":"<< endl;
	}
	return 0;
}
