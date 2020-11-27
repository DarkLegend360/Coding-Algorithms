#include <bits/stdc++.h>
using namespace std;

void fullDiamond(int n) {
    int spacing=n-1;
    for(int i=0;i<n;i++) {
        for(int j=0;j<spacing;j++)
            cout<<" ";
        for(int j=0;j<=i;j++)
            cout<<"* ";
        cout<<endl;
        spacing--;
    }
    spacing=1;
    for(int i=n-2;i>=0;i--) {
        for(int j=0;j<spacing;j++)
            cout<<" ";
        for(int j=0;j<=i;j++)
            cout<<"* ";
        cout<<endl;
        spacing++;
    }
}

void hollowDiamond(int n) {
    int spacing=n-1;
    for(int i=0;i<n;i++) {
        for(int j=0;j<spacing;j++)
            cout<<" ";
        for(int j=0;j<=i;j++)
            if(j==0 || j==i)
                cout<<"* ";
            else
                cout<<"  ";
        cout<<endl;
        spacing--;
    }
    spacing=1;
    for(int i=n-2;i>=0;i--) {
        for(int j=0;j<spacing;j++)
            cout<<" ";
        for(int j=0;j<=i;j++)
            if(j==0 || j==i)
                cout<<"* ";
            else
                cout<<"  ";
        cout<<endl;
        spacing++;
    }
}
void numberTree(int n) {
    int spacing=n+2;
    for(int i=1;i<=n;i++) {
        for(int j=0;j<spacing;j++)
            cout<<" ";
        for(int j=i;j<i*2;j++)
            cout<<j<<" ";
        for(int j=i*2-2;j>=i;j--)
            cout<<j<<" ";
        spacing-=2;
        cout<<endl;
    }
}
void pascalTriangle(int n) {
    vector<vector<int>> pascal(n);
    for(int i=0;i<n;i++) {
        pascal[i].resize(i+1);
        pascal[i][0]=1;
        pascal[i][i]=1;
        for(int j=1;j<i;j++)
            pascal[i][j]=pascal[i-1][j]+pascal[i-1][j-1];
    }
    int spacing=n;
    for(auto x:pascal) {
        for(int i=0;i<spacing;i++)
            cout<<" ";
        for(auto y:x)
            cout<<y<<" ";
        spacing--;
        cout<<endl;
    }
}
void palinTriangle(int n) {
    cout<<"*"<<endl;
    for(int i=1;i<=n;i++) {
        cout<<"* ";
        for(int j=1;j<=i;j++)
            cout<<j<<" ";
        for(int j=i-1;j>=1;j--)
            cout<<j<<" ";
        cout<<"*"<<endl;
    }
    for(int i=n-1;i>=1;i--) {
        cout<<"* ";
        for(int j=1;j<=i;j++)
            cout<<j<<" ";
        for(int j=i-1;j>=1;j--)
            cout<<j<<" ";
        cout<<"*"<<endl;
    }
    cout<<"*"<<endl;
}
int main() {
    int n;
    cin>>n;
    // hollowDiamond(n);
    // cout<<endl;
    // fullDiamond(n);
    //numberTree(n);
    //pascalTriangle(n);
    palinTriangle(n);
    return 0;
}