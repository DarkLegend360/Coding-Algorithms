#include <stdio.h>
#include <string.h>
#include <stdbool.h>

char str[100];
int idx;
void E();
bool flag=true;

void X_dash() {
        if(str[idx]==',') {
            idx++;
            E();
        } else
            return;
}
void X() {
    E();
    X_dash();
}

void T_Ddash() {
    if(str[idx]==']') {
        idx++;
    } else {
        X();
        if(str[idx]==']')
            idx++;
        else
            flag=false;
    }
}
void T_dash() {
    if(str[idx]=='[') {
        idx++;
        T_Ddash();
    } else
        return;
}
void T() {
    if(str[idx]=='a') {
        idx++;
        T_dash();
    } else
        flag=false;
}

void E_dash() {
    if(str[idx]=='+') {
        idx++;
        T();
        E_dash();
    } else
        return;
}
void E() {
    T();
    E_dash();
}

void main() {
    scanf("%s",str);
    E();
    if(strlen(str)==idx && flag)
        printf("%s is valid\n",str);
    else
        printf("%s is invalid\n",str);
}
// a+a[a,a]
// []a+a