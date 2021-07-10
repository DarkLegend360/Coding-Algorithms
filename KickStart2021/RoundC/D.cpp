#include <bits/stdc++.h>
using namespace std;

const unsigned int M = 1000000007;

int countingStonesHire2020(vector<int> stones, vector<int> days) {
	int n=stones.size();
    int maxStone=0;
    vector<int> sum=stones;
    for(int i=0;i<n;i++) {
        for(int j=(i+days[i]-1);j>i;j--)
        	sum[j]+=stones[i];
        maxStone=max(maxStone, sum[i]);
    }
    return maxStone;
}

char KthCharacterHire2020(string s, string t, long long k) {
	int str1Len=s.size();
	int str2Len=t.size();
	int lastOfStr1=1;
	int lastOfStr2=2;
	string newString="";
	while(k>0) {
		int newLen1 = lastOfStr1*str1Len;
		if(k>newLen1) {
			lastOfStr1+=2;
			k-=newLen1;
			int newLen2 = lastOfStr2*str2Len;
			if(k>newLen2) {
				lastOfStr2+=2;
				k-=newLen2;
			} else {
				for(int i=1;i<=lastOfStr2;i++)
					newString+=t;
				return newString[k-1];
			}
		} else {
			for(int i=1;i<=lastOfStr1;i++)
					newString+=s;
				return newString[k-1];
		}
	}
	return 'a';
}

int XorSumHire2020(int a, int b, int c, int d) {
    const unsigned int M = 1000000007;
    long long int res=0;
    for(int i=a;i<=b;i++)
        for(int j=c;j<=d;j++) 
            res+= (i^j);
    return res%M;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//cout<<KthCharacterHire2020("a", "bc", 4)<<endl;//b
	cout<<XorSumHire2020(1,2, 3, 4)<<endl;//b
	return 0;
}