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
