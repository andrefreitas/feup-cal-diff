 /****************************************************************************
 * Author:      - André Freitas, p.andrefreitas@gmail.com
 * Author:      - Tiago Tavares, tiagomctavares@gmail.com
 * Author:      - Olivier Alves, olivieralves1@gmail.com
 * Copyright:   - 29/05/2012, CAL, FEUP
 ****************************************************************************/
#include "diff.h"
#include <iostream>
#include <string>
#include <cstdio>
#include "color.h"
using namespace std;

int main(int argc, char *argv[]){
    Color::color(RESET_COLOR);
	vector<string> diffs;
	// if no files are given, ask them
	try{
		if(argc==1) {
			string input1, input2;
			cout<<"File1: ";
			cin>>input1;
			cout<<"File2: ";
			cin>>input2;
			diffs=Diff::computeFilesDiff(input1,input2);
			Diff::showDiffs(diffs);

		} else if(argc==3) {
	// if the files are given, directly compute the differences
			diffs=Diff::computeFilesDiff(argv[1],argv[2]);
			Diff::showDiffs(diffs);

		}
	// wrong number of arguments
		else  cout<<"usage: " << argv[0] << " [<file1> <file2>]";
	}
	// invalid file name exception
	catch(invalidFileNameException f){
		Color::color(RED);
		cout << "Invalid filename: " << f.getFileName();
		Color::color(RESET_COLOR);
		getchar();
	}

	cout<<endl; //Added because of buffer error
	
	#ifdef _WIN32
		getchar();
        getchar();
	#elif _WIN64
        getchar();
		getchar();
    #elif __linux__
        getchar();
	#endif
	return 0;
}
