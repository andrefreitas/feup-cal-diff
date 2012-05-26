#include "diff.h"
#include <iostream>
#include <string>
#include <cstdio>
#include "color.h"
using namespace std;

int main(int argc, char *argv[]){
	vector<string> diffs;

	if(argc==1) {
		string input1, input2;
		cout<<"File1: ";
		cin>>input1;
		cout<<"File2: ";
		cin>>input2;
		diffs=Diff::computeFilesDiff(input1,input2);
		Diff::showDiffs(diffs);

	}else if(argc==3) {

		diffs=Diff::computeFilesDiff(argv[1],argv[2]);
		Diff::showDiffs(diffs);

	}else {

		cout<<"Wrong number of arguments";

	}

	cout<<endl; //Added because of buffer error
	#ifdef _WIN32
		getchar();
	#elif _WIN64
		getchar();
	#endif

	return 0;
}
