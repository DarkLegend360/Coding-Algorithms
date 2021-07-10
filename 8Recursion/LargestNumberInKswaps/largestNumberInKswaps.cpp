void helper(string &str, int k, string &maxNum, int startIdx) {
    if(str.compare(maxNum)>0)
        maxNum=str;
    if(k==0)
        return;
    int maxIdx=startIdx;
    for(int i=startIdx+1;i<str.size();i++)
        if(str[maxIdx]<str[i])
            maxIdx=i;
    for(int i=startIdx;i<str.size();i++) {
        if(str[maxIdx]==str[i]) {
            swap(str[startIdx], str[i]);
            k-=(str[maxIdx]==str[startIdx])?0:1;
            helper(str, k, maxNum, startIdx+1);
            swap(str[startIdx], str[i]);
        }
    }
}
string findMaximumNum(string str, int k)
{
    string maxNum=str;
    helper(str, k, maxNum, 0);
    return maxNum;
}