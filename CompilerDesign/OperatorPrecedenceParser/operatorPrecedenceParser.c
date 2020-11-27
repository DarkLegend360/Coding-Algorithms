#include <stdio.h>
#include <stdlib.h>
#include <string.h>
    
char table[10][10];
char header[10]={"+*i()$"};
char Stack[100];
int stackTop=-1;
char inputString[100];
int idx=0;
int inputLength;

int getRelationHelper(char terminal) {
    for(int i=0;header[i]!='\0';i++)
        if(header[i]==terminal)
            return i;
    printf("String Invalid\n");
    exit(0);
}

char getRelation(char st,char inp) {
    return table[getRelationHelper(st)][getRelationHelper(inp)];
}

void printAction(int mode) {
    for(int i=0;i<=stackTop;i++)
        printf("%c",Stack[i]);
    printf("\t\t");
    for(int i=idx;i<inputLength;i++)
        printf("%c",inputString[i]);
    printf("\t\t");
    if(mode==1)
        printf("Shift\n");
    else
        printf("Pop\n");
}

void parseInput() {
    printf("STACK\t\tINPUT\t\tACTION\n");
    Stack[++stackTop]='$';
    while(stackTop!=-1 && (idx<inputLength)) {
        if(Stack[stackTop]=='$' && inputString[idx]=='$')
            break;
        char rel = getRelation(Stack[stackTop],inputString[idx]);
        if(rel=='>') {
            printAction(0);
            Stack[stackTop--];
        }
        else if((rel=='<')||(rel=='=')){
            printAction(1);
            Stack[++stackTop]=inputString[idx++];
        }
    }
    if(Stack[stackTop]=='$' && inputString[idx]=='$')
        printf("String Accepted\n");
    else 
        printf("String Invalid\n");
}

void main() {
    //TABLE
    //  +   *   i   (   )   $ 
    /* + */strcpy(table[0],"><<<>>");
    /* * */strcpy(table[1],">><<>>");
    /* i */strcpy(table[2],">>  >>");
    /* ( */strcpy(table[3],"<<<<= ");
    /* ) */strcpy(table[4],">>  >>");
    /* $ */strcpy(table[5],"<<<<  ");
    //INPUT STRING
    scanf("%s",inputString);
    for(inputLength=0;inputString[inputLength]!='\0';inputLength++);
    parseInput();
}