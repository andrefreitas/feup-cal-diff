#include "diff.h"
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
	return words;
}
