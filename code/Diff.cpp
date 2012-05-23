#include "Diff.h"

int Diff::computeLCSLen(string a, string b){
	 if(a.empty()|| b.empty()) return -1;

	 int *curr = new int [b.size()];
	 int *prev = new int [b.size()];
	 int *swap;
	 int maxSubstr=0;

	 for (int unsigned i=0; i<a.size(); i++){
		 for (int unsigned j=0; j<b.size(); j++){
			 if(a[i]!=b[j]) curr[j]=0;
			 else{
				 if(i==0 || j==0) curr[j]=1;
				 else curr[j]=1+prev[j-1];
				 if(maxSubstr<curr[j]) maxSubstr=curr[j];
			 }

		 }
		 swap=curr;
		 curr=prev;
		 prev=swap;
	 }
	 delete [] curr;
	 delete [] prev;
	 return maxSubstr;
}
int Diff::retrieveLCS(string a,string b, string &sequence){
	int num[b.size()][a.size()];
	int maxlen=0;
	int lastSubsBegin=0;
	string sequenceBuilder;
	for(int i=0; i<a.size(); i++){
		for(int j=0;j<b.size();j++){
			if(a[i]!=b[j]) num[i][j]=0;
			else{
				if((i==0) || (j==0)) num[i][j]=1;
				else num[i][j]=1+num[i-1][j-1];
				if(num[i][j]>maxlen){
					maxlen=num[i][j];
					int thisSubsBegin=i-num[i][j]+1;
					if (lastSubsBegin== thisSubsBegin){
						sequenceBuilder.append(&a[i]);
					}
					else{
						lastSubsBegin=thisSubsBegin;
						sequenceBuilder.clear();
						sequenceBuilder.append(a.substr(lastSubsBegin,(i+1)-lastSubsBegin));
					}
				}
			}
		}
	}

	sequence=sequenceBuilder.substr(0,maxlen);
	return sequence.size();
}
