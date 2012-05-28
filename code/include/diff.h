 /****************************************************************************
 * Author:      - André Freitas, p.andrefreitas@gmail.com
 * Author:      - Tiago Tavares, tiagomctavares@gmail.com
 * Author:      - Olivier Alves, olivieralves1@gmail.com
 * Copyright:   - 29/05/2012, CAL, FEUP
 ****************************************************************************/
#ifndef DIFF_H
#define DIFF_H
#include <iostream>
#include <string>
#include <vector>
#include <time.h>
using namespace std;
/**
 * Diff - A class for computing the differences between 2 files.
 * It represents the insertions and deletions from a file to other, using colors.
 */
class Diff{

	static int deletedWords;	/* The number of deleted words */
	static int addedWords;		/* The number of added words */
	static double startClock;	/* The cpu number of clocks before computing the diffs */
	static double endClock;	/* The cpu number of clocks after computing the diffs */

	/**
	 * Reads a given file and fetch it as a vector of lines (strings)
	 * @throws invalidFileNameException if the file doesn't exist
	 * @param filetoread the file name
	 * @return a vector of strings
	 */
	static vector<string> readFile(string fileToRead);

	/**
	 * Normalize 2 files filling with blank lines if necessary
	 * @param file1 a file name
	 * @param file2 a file name
	 */
	static void normalizeFilesLines(vector<string> &file1, vector<string> &file2);

	/**
	 * Splits a string in words.
	 * @param line a string
	 * @return a vector of strings
	 */
	static vector<string> splitToWords(string line);

	/**
	 * Check if a word exists in a vector of string from a given position
	 * @param word the string to search
	 * @param the vector of words
	 * @param fromPos the initial position to be considered
	 * @return true if word exists
	 */
	static bool wordsExists(string word,vector<string> words,int fromPos);
	public:
	/**
	 * Compute the differences between 2 lines using the following representation:
	 * =Hello +John -Mark =how =are =you =?
	 * @param line1 the original string
	 * @param line2 the final string
	 * @return a string pointing the differences using the +,=,- notation
	 */
	static string computeLineDiff(string line1,string line2);
	/**
	 * This function basicly calls the computeLineDiff in every line of the files.
	 *
	 * @param file1 the original file
	 * @param file2 the final file
	 * @return a vector of strings pointing the differences
	 */
	static vector<string> computeFilesDiff(string file1, string file2);

	/**
	 * Represents the differences in the output console (stdout) using colours by
	 * giving the string that points the differences.
	 * @param lineDiffs a vector of diff strings
	 */
	static void showDiffs(vector<string> lineDiffs);

};

/**
 * This class is thrown when a invalid file name is given in any function call
 */
class invalidFileNameException{
	string file;	/** The file name **/
public:
	/** Constructor
	 * @param file the invalid file name
	 */
	invalidFileNameException(string file);

	/** Returns the invalid file name
	 * @return a string
	 */
	string getFileName();
};
/**
 * Clears the screen (cross platform)
 */
void cls();

#endif
