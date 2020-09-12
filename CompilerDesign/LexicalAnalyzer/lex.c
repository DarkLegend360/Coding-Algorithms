#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 
#include <string.h>
#define curChar str[rightIdx]
int state=0;
char symtab[50][10];
int leftIdx=0,rightIdx=0;
int tabPointer=0;
bool isValidDelimiter(char s) {
    switch(s){
        case ';':
        case ',':
        case '(':
        case ')':
        case '{':
        case '}':
        case ' ':
        return true;
        default: return false;
    }
}
bool isValidNumber(char* str) 
{ 
    int len = strlen(str); 
    for (int i = 0; i < len; i++)
        if (str[i]<'0' || str[i]>'9')
            if(str[i]!=' ')
                return false; 
    return true; 
} 
bool isValidOperator(char s) {
    switch(s){
        case '>':
        case '<':
        case '/':
        case '*':
        return true;
        default: return false;
    }
}
char *subString(char *str, int leftIdx, int rightIdx) 
{ 
    char *subStr = (char*)malloc( sizeof(char) * (rightIdx - leftIdx + 2)); 
    for (int i = leftIdx; i <= rightIdx; i++) 
        subStr[i - leftIdx] = str[i]; 
    subStr[rightIdx - leftIdx + 1] = '\0'; 
    return subStr; 
}
void addToSymbolTable(char *str) {
    strcpy(symtab[tabPointer++],str);
}
int checkSymbolTable(char *str) {
    for(int i=0;i<tabPointer;i++)
        if(strcmp(symtab[i],str)==0)
            return i+1;
    return -1;
}
void printToken(char *str) {
    char *subStr=subString(str,leftIdx,rightIdx-1);
    if(isValidNumber(subStr))
        printf("< number , %s >\n",subStr);
    else if(str[leftIdx]=='"')
        printf("< literal , %s >\n",subString(subStr,1,strlen(subStr)));
    else if(subStr[0] >='0' && subStr[0]<='9')
        printf("< lexical error >\n");
    else {
        int isAvail=checkSymbolTable(subStr);
        if(isAvail!=-1)
           printf("< identifier , %d >\n",isAvail);
        else {
            addToSymbolTable(subStr);
            printf("< identifier , %d >\n",tabPointer);
        }
    }
    state=0;
    if(curChar==',')
        state=19;
    leftIdx=rightIdx+1;
}
void displaySymbolTable() {
    printf("\nID\tLEXEME\n");
    for(int i=0;i<tabPointer;i++)
        printf("%d\t%s\n",i+1,symtab[i]);
    printf("\n");
}
void processString(char *str) {
    state=0;
    leftIdx=0;
    rightIdx=0;
    int size = strlen(str);
    while(rightIdx<size) {
        if(isValidOperator(curChar)) {
            printf("< operator , %c >\n",curChar);
            rightIdx++;
            continue;
        }
        if(state==20 && curChar!='+') {
            state=0;
            printf("< operator , + >\n");
        }
        if(state==16 && curChar!='=') {
            state=0;
            printf("< operator , = >\n");
        }
        switch(state) {
            case 0: {//Initial State
                switch(curChar) {
                    case 'i': {
                        state=1;
                        break;
                    }
                    case 'f': {
                        state=17;
                        break;
                    }
                    case 't': {
                        state=14;
                        break;
                    }
                    case 'c': {
                        state=10;
                        break;
                    }
                    case '"': {
                        state=15;
                        break;
                    }
                    case ' ':break;
                    default: {
                        state=19;
                    }
                }
                leftIdx=rightIdx;
                break;
            }
            case 1:{
                if(isValidDelimiter(curChar)) {
                    printToken(str);
                    state=0;
                } else {
                    switch (curChar) {
                        case 'n': {
                            state=5;
                            break;
                        }
                        case 'f': {
                            state=2;
                            break;
                        }
                        default: {
                            state=19;
                        }
                    }
                } break;
            }
            case 2:{
                if(isValidDelimiter(curChar)) {
                    printf("< keyword , if >\n");
                    state=0;
                } else
                    state=19;
                break;
            }
            case 3: { 
                if(isValidDelimiter(curChar)) {
                    printToken(str);
                    state=0;
                } else if(curChar=='r')
                    state=4;
                else
                    state=19;
                break;
            }
            case 17: {
                if(isValidDelimiter(curChar)) {
                    printToken(str);
                    state=0;
                } else if(curChar=='o')
                    state=3;
                else
                    state=19;
                break;
            }
            case 4:{
                if(isValidDelimiter(curChar)) {
                    printf("< keyword , for >\n");
                    state=0;
                } break;
            }
            case 5: {
                if(isValidDelimiter(curChar)) {
                    printToken(str);
                    state=0;
                } else if(curChar=='t')
                    state=6;
                else 
                    state=19;
                break;
            }
            case 6:{
                if(isValidDelimiter(curChar)) {
                    printf("< type , int >\n");
                    state=0;
                } else
                    state=19;
                break;
            }
            case 7: {
                if(isValidDelimiter(curChar)) {
                    printToken(str);
                    state=0;
                } else if(curChar=='e')
                    state=8;
                else 
                    state=19;
                break;
            }
            case 8: {
                if(isValidDelimiter(curChar)) {
                    printToken(str);
                    state=0;
                } else if(curChar=='n')
                    state=9;
                else 
                    state=19;
                break;
            }
            case 9: {
                if(isValidDelimiter(curChar)) {
                    printf("< keyword , then >\n");
                    state=0;
                } else
                    state=19;
                break;
            }
            case 10: {
                if(isValidDelimiter(curChar)) {
                    printToken(str);
                    state=0;
                } else if(curChar=='h')
                    state=11;
                else 
                    state=19;
                break;
            }
            case 11: {
                if(isValidDelimiter(curChar)) {
                    printToken(str);
                    state=0;
                } else if(curChar=='a')
                    state=12;
                else 
                    state=19;
                break;
            }
            case 12: {
                if(isValidDelimiter(curChar)) {
                    printToken(str);
                    state=0;
                } else if(curChar=='r')
                    state=13;
                else 
                    state=19;
                break;
            }
            case 13: {
                if(isValidDelimiter(curChar)) {
                    printf("< type , char >\n");
                    state=0;
                } break;
            }
            case 14:{
                if(isValidDelimiter(curChar)) {
                    printToken(str);
                    state=0;
                }
                else if(curChar=='h')
                    state=7;
                else 
                    state=19;
                break;
            }
            case 15: {
                if(curChar=='"') {
                    printToken(str);
                    state=0;
                } break;
            }
            case 19: { //Identifier
                if(isValidDelimiter(curChar) || isValidOperator(curChar)) {
                    printToken(str);
                } break;
            }
        }
        if(isValidDelimiter(curChar) && curChar!=' ') {
            printf("< delimiter , %c >\n",curChar);
            state=0;
        }
        if(curChar=='+') {
            if(state!=20)
                state=20;
            else {
                printf("< operator , ++ >\n");
                state=0;
            }
        }
        if(curChar=='=') {
            if(state!=16)
                state=16;
            else {
                printf("< operator , == >\n");
                state=0;
            }
        }
        rightIdx++;
    }
}
void main() {
    FILE *f;
    f=fopen("inp","r");
    char str[100];
    while (fgets(str,100,f))
        processString(str);
    displaySymbolTable();
    fclose(f);
}