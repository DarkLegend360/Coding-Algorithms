#include <bits/stdc++.h>
using namespace std;
vector<vector<string>> groupAnagrams(vector<string> words) {
  unordered_map<string,vector<string>> anagrams;
	for(auto word:words) {
		string sortedWord = word;
		sort(sortedWord.begin(),sortedWord.end());
		if(anagrams.find(sortedWord)!=anagrams.end())
			anagrams[sortedWord].push_back(word);
		else
			anagrams[sortedWord]=vector<string>{word};
	}
	vector<vector<string>> result;
	for(auto x:anagrams)
		result.push_back(x.second);
  return result;
}
