#include "diff.h"
#include <iostream>
#include <string>
#include <cstdio>
#include "color.h"
using namespace std;

int main(int argc, char *argv[]){
	vector<string> diffs;

	if(argc==0) {

		diffs=Diff::computeFilesDiff("a.txt","b.txt");
		Diff::showDiffs(diffs);

	}else if(argc == 2) {

		diffs=Diff::computeFilesDiff(argv[1],argv[2]);
		Diff::showDiffs(diffs);

	}else {

		cout<<"Wrong number of arguments"<<endl;

	}

	#ifdef _WIN32
		getchar();
	#elif _WIN64
		getchar();
	#endif

	return 0;
}
