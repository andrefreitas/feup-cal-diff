#include "diff.h"
#include <iostream>
#include <string>
#include <cstdio>
#include "color.h"
using namespace std;

int main(){
	vector<string> diffs;
	diffs=Diff::computeFilesDiff("a.txt","b.txt");
	Diff::showDiffs(diffs);
	return 0;
}
