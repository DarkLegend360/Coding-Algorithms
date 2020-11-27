#include <bits/stdc++.h>
using namespace std;

void question1() {
    float fuel,dist;
    cin>>fuel>>dist;
    if(fuel<=0 || dist<=0) {
        cout<<"Invalid Input"<<endl;
        return;
    }
    float perKM=fuel/dist;
    float per100KM=perKM*100;
    printf("%0.2f\n",per100KM);
    double gallon = 0.2642;
    double mile = 0.6214;
    float perLit = (dist*mile)/(fuel*gallon);
    printf("%0.2f\n",perLit);
}

void question2() 
{
    int pizza,puff,cool;
    cin>>pizza>>puff>>cool;
    cout<<"Total:"<<(pizza*100+puff*20+cool*10)<<endl<<"ENJOY THE SHOW!!!"<<endl;

}

void question3() {
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    cout<<a<<"-"<<char(a)<<endl;
    cout<<b<<"-"<<char(b)<<endl;
    cout<<c<<"-"<<char(c)<<endl;
    cout<<d<<"-"<<char(d)<<endl;
}

void question4() {
    int cse,ece,mech;
    cout<<"CSE:";
    cin>>cse;
    cout<<"ECE:";
    cin>>ece;
    cout<<"MECH:";
    cin>>mech;
    if(cse<0)
        cout<<"Input is Invalid"<<endl;
    else if(ece<0)
        cout<<"Input is Invalid"<<endl;
    else if(mech<0)
        cout<<"Input is Invalid"<<endl;
    else if(cse==mech && mech==ece)
        cout<<"None of the department has got the highest placement"<<endl;
    else {
        int mx=max(ece,max(cse,mech));
        if(mx==cse)
            cout<<"CSE"<<endl;
        if(mx==ece)
            cout<<"ECE"<<endl;
        if(mech==mx)
            cout<<"MECH"<<endl;
    }
}

void question5() {
    int n;
    cin>>n;
    char ref,coup,type;
    cin>>ref>>coup>>type;
    float cost=n;
    cout<<type<<endl;
    if(n<5 || n>40) {
        cout<<"Minimum of 5 and Maximum of 40 Tickets"<<endl;
        return;
    }
    if(type!='k' && type!='q') {
        cout<<"Invalid Input"<<endl;
        return;
    }
    if(type=='k')
        cost*=75;
    else if(type=='q')
        cost*=150;
    float fin;
    cout<<cost<<endl;
    if(n>20) {
        fin=cost-((1.0/10)*cost);
    }
    if(coup=='y')
        fin=fin-((2.0/100)*fin);
    if(ref=='y')
        fin+=(n*50);
    cout<<"Amount:"<<fin<<endl;
}

void question6() {
    int month;
    cin>>month;
    if (month<1 && month>12) {
        cout<<"Invalid Month"<<endl;
        return;
    }
    if(month>=3 && month<=5)
        cout<<"Spring"<<endl;
    else if(month>=6 && month<=8)
        cout<<"Summer"<<endl;
    else if(month>=9 && month<=11)
        cout<<"Autumn"<<endl;
    else
        cout<<"Winter"<<endl;
}

void question7() {
    int start,end;
    cin>>start>>end;
    vector<bool> prime(end+1,true);
    for(int i=2;i*i<=end;i++)
        if(prime[i])
            for(int j=i*i;j<=end;j+=i)
                prime[j]=false;
    for(int i=start;i<=end;i++)
        if(prime[i])
            cout<<i<<" ";
    cout<<endl;
}

void question8() {
    string s;
    cin>>s;
    if(s[0]=='-') {
        cout<<"Invalid Number"<<endl;
        return;
    }
    int left=0;
    int right=s.size()-1;
    while(left<right) {
        if(s[left]!=s[right]) {
            cout<<"Not Palindrome"<<endl;
            return;
        }
        left++;
        right--;
    }
    cout<<"Palindrome"<<endl;
}

void question9() {
    float sal,app;
    float inc;
    cin>>sal>>app;
    if(sal<=0 || app<1 || app>5) {
        cout<<"Invalid Input"<<endl;
        return;
    }
    if(app>=1 && app<=3)
        inc=(11.0/10)*sal;
    else if(app>=3.1 && app<=4)
        inc=(125.0/100)*sal;
    else 
        inc=(13.0/10)*sal;
    cout<<inc<<endl;
}

void question10(){
    int n;
    cin>>n;
    int temp=n;
    int count=0;
    int sm=0;
    while(temp!=0) {
        count++;
        sm+=temp%10;
        temp/=10;
    }
    if(count!=4 || n<=0) {
        cout<<"Invalid Number"<<endl;
        return;
    }
    if((sm%3==0) || (sm%5==0) || (sm%7==0))
        cout<<"Lucky Number"<<endl;
    else
        cout<<"Unlucky Number"<<endl;
}

void question11() {
    int n;
    cin>>n;
    if(n<=0) {
        cout<<"Invalid Range"<<endl;
        return;
    }
    unordered_set<string> courses;
    string tmp;
    for(int i=0;i<n;i++) {
        cin>>tmp;
        courses.insert(tmp);
    }
    string sr;
    cin>>sr;
    if(courses.find(sr)==courses.end())
        cout<<"Course Not Found"<<endl;
    else
        cout<<"Course is Found"<<endl;
}

void question12() {
    stack<int> st;
    int n;
    cin>>n;
    n=abs(n);
    for(int i=1;i*i<=n;i++) {
        if(n/i==i)
            cout<<i<<" ";
        else if(n%i==0) {
            cout<<i<<" ";
            st.push(n/i);
        }
    }
    while(!st.empty()) {
        cout<<st.top()<<" ";
        st.pop();
    }
}

int main() {
    //question1();
    //question2();
    //question3();
    //question4();
    //question5();
    //question6();
    //question7();
    //question8();
    //question9();
    //question10();
    //question11();
    question12();
    return 0;
}