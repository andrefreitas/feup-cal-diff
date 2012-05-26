#ifndef DIFF_H
#define DIFF_H
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Diff{
	static vector<string> readFile(string fileToRead);
	static void normalizeFilesLines(vector<string> &file1, vector<string> &file2);
	static vector<string> splitToWords(string line);
	static bool wordsExists(string word,vector<string> words,int fromPos);
	public:
	static string computeLineDiff(string line1,string line2);
	static vector<string> computeFilesDiff(string file1, string file2);
	static void showDiffs(vector<string> lineDiffs);

};

#endif
