#include "diff.h"
#include <sstream>
#define DEBUG_MODE 0
vector<string>  Diff::splitToWords(string line){
	vector<string> words;

	// Add a space in the end if necessary
	if(line[line.size()!=' ']) line.append(" ");

	// Normalize the string (1 space between words)
	int unsigned spaceCounter=0;
	for(int unsigned i=0; i<line.size(); i++){
		if(line[i]==' ') spaceCounter++;
		else spaceCounter=0;
		// found more than 1 space
		if(spaceCounter>1){
			for(int unsigned j=i; j<(line.size()-1); j++ ){
				line[j]=line[j+1];
			}
			// pop the last element
			line=line.substr(0,line.size()-1);
			spaceCounter=0;
			i=i-2;
		}

	}

	// Parse all the words
	int pos,lastpos;
	lastpos=-1;
	while((pos=line.find(" "))!=-1){
		words.push_back(line.substr(lastpos+1,(pos-lastpos)-1));
		lastpos=pos;
		line[pos]='*';
	}

	// Debug MODE
	if(DEBUG_MODE){
		for(int unsigned i=0; i<words.size(); i++){
				cout <<":" << words[i];
				if(i==(words.size()-1)) cout <<":";
			}
	}
	return words;
}

bool Diff::wordsExists(string word,vector<string> words,int fromPos){
	for(int unsigned i=fromPos; i<words.size(); i++){
		if(words[i]==word) return 1;
	}
	return 0;
}

string Diff::computeLineDiff(string line1,string line2){
	// Parse words of the two lines
	vector<string> line1Words, line2Words;
	line1Words=splitToWords(line1);
	line2Words=splitToWords(line2);

	// Compare the sequence of words
	int unsigned counter1,counter2;
	counter1=counter2=0;
	stringstream diffLine;
	do{

		// the line 1 is greater than 2
		if(counter2>=line2Words.size() && counter1<line1Words.size())
		{
			do{
				diffLine<<"-";
				diffLine<<line1Words[counter1]<< " ";
				counter1++;
			}while(counter1<line1Words.size());
		}
		// the line 2 is greater than 1
		else if(counter1>=line1Words.size() && counter2<line2Words.size()){
			do{
				diffLine<<"+";
				diffLine<<line2Words[counter2]<< " ";
				counter2++;
			}while(counter2<line2Words.size());
		}
		else{
			// both the words are equal
			if(line1Words[counter1]==line2Words[counter2]){
				diffLine<<"=";
				diffLine<<line1Words[counter1] << " ";
			}
			// the word doesn't exist
			else if(!wordsExists(line1Words[counter1],line2Words,counter2)){
				diffLine<<"-";
				diffLine<<line1Words[counter1] << " ";
				diffLine<<"+";
				diffLine<<line2Words[counter2] << " ";
			}
			// the words exists
			else {
				do{
					diffLine<<"+";
					diffLine<<line2Words[counter2]<< " ";
					counter2++;
				} while(line2Words[counter2]!=line1Words[counter1]);
				diffLine<<"=";
				diffLine<< line1Words[counter1] << " ";
			}

		}

		counter1++; counter2++;
	} while(counter1<line1Words.size() || counter2<line2Words.size());
	return diffLine.str();
}