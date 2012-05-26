#include "diff.h"
#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

int main(){
	vector<string> diffs;
	diffs=Diff::computeFilesDiff("a.txt","b.txt");

	for(int unsigned i=0; i<diffs.size(); i++){
		cout << diffs[i] << endl;
	}
	return 0;
}
