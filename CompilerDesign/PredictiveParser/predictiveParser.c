#include <stdio.h>
#include <string.h>
#include <ctype.h>

char production[20][10];
char firstTable[20][20];
char followTable[20][20];
char inputString[20];
char stackOne[20];
char stackTwo[20];

int firstPointer;
int followPointer;
int productionCount;
int tableIdx;
int stackTopOne=-1;
int stackTopTwo=-1;
int stringLength;

void buildFollowSet(char);

void buildFirstSet(char rule) {
    for(int i=0;i<productionCount;i++) {
        if(production[i][0]==rule) {
            if(production[i][2]=='#')
                firstTable[tableIdx][firstPointer++]='#';
            else {
                if(isupper(production[i][2]))
                    buildFirstSet(production[i][2]);
                else
                    firstTable[tableIdx][firstPointer++]=production[i][2];
            }
        }
    }
}

void followSetHelper(char rule,int x,int y) {
    if(!isupper(rule))
        followTable[tableIdx][followPointer++]=rule;
    else {
        int i=0, j=1; 
        for(i=0;i<tableIdx;i++) 
            if(firstTable[i][0] == rule) 
                break;
        while(firstTable[i][j] != '\0') { 
            if(firstTable[i][j] != '#')  
                followTable[tableIdx][followPointer++] = firstTable[i][j]; 
            else { 
                if(production[x][y] == '\0') 
                    buildFollowSet(production[x][0]); 
                else
                    followSetHelper(production[x][y], x, y+1); 
            } 
            j++; 
        } 
    }
}

void buildFollowSet(char rule) {
    if(production[0][0] == rule) 
        followTable[tableIdx][followPointer++] = '$'; 
    for(int i=0;i<productionCount;i++) {
        for(int j=2;production[i][j]!='\0';j++) {
            if(production[i][j]==rule) {
                if(production[i][j+1]=='\0' && production[i][0]!=rule)
                    buildFollowSet(production[i][0]);
                else if(production[i][j+1] != '\0')
                    followSetHelper(production[i][j+1], i, (j+2)); 
            }
        }
    }
}

void printFirstTable() {
    for(int i=0;i<tableIdx;i++)  {
        printf("FIRST(%c): ",firstTable[i][0]);
        for(int j=1;firstTable[i][j]!='\0';j++)
            printf("%c ",firstTable[i][j]);
        printf("\n");
    }
    printf("\n");
}

void printFollowTable() {
    for(int i=0;i<tableIdx;i++)  {
        printf("FOLLOW(%c): ",followTable[i][0]);
        for(int j=1;followTable[i][j]!='\0';j++)
            printf("%c ",followTable[i][j]);
        printf("\n");
    }
    printf("\n");
}

int getProductionIndex(char stringChar,char stackTopChar) {
    for(int i=0;i<productionCount;i++) 
        if(production[i][0]==stackTopChar && stringChar==production[i][2])
            return i;
    for(int i=0;i<productionCount;i++) 
        if(production[i][0]==stackTopChar && production[i][2]=='#')
             return -1;
    for(int i=0;i<productionCount;i++) 
        if(production[i][0]==stackTopChar)
             return i;
}

void applyProduction(char stringChar,char stackTopChar) {
    int productionIdx=getProductionIndex(stringChar,stackTopChar);
    if(productionIdx==-1) {
        stackTopOne--;
        return;
    }
    int idx=2;
    while(production[productionIdx][idx]!='\0')
        stackTwo[++stackTopTwo]=production[productionIdx][idx++];
    stackTopOne--;
    while(stackTopTwo!=-1)
        stackOne[++stackTopOne]=stackTwo[stackTopTwo--];
}

void printStatus(int idx) {
    printf("S: ");
    for(int i=0;i<=stackTopOne;i++)
            printf(" %c ",stackOne[i]);
    printf("\n");
    printf("T: ");
    for(int i=stringLength-1;i>=idx;i--)
            printf(" %c ",inputString[i]);
    printf("\n\n");
}

void stringValidation() {
    int idx=0;
    stackOne[++stackTopOne]='$';
    stackOne[++stackTopOne]=production[0][0];
    printf("-------------|Stack & String Status|-------------\n");
    while(1) {
        printStatus(idx);
        if(isupper(stackOne[stackTopOne]))
            applyProduction(inputString[idx],stackOne[stackTopOne]);
        else
        {
            if(stackOne[stackTopOne]==inputString[idx]) {
                idx++;
                stackTopOne--;
            } else {
                printf("-------------------------------------------------\n");
                printf("------------> Invalid String <------------\n");
                return;
            }
        }
        if(idx==stringLength) {
            printf("-------------------------------------------------\n");
            printf("------------> Valid String <------------\n");
            return;
        }
    }
}

void main() {
    //-------------|Input Here|-------------//
    productionCount=6;
    strcpy(production[0], "S=A"); 
    strcpy(production[1], "A=aBC"); 
    strcpy(production[2], "C=dC"); 
    strcpy(production[3], "C=#"); 
    strcpy(production[4], "B=b"); 
    strcpy(production[5], "E=g"); 

    // strcpy(production[0], "S=aABb"); 
    // strcpy(production[1], "A=c"); 
    // strcpy(production[2], "A=#"); 
    // strcpy(production[3], "B=d");
    // strcpy(production[4], "B=#");  


    // strcpy(production[0], "E=TR"); 
    // strcpy(production[1], "R=+TR"); 
    // strcpy(production[2], "R=#"); 
    // strcpy(production[3], "T=FY"); 
    // strcpy(production[4], "Y=*FY"); 
    // strcpy(production[5], "Y=#"); 
    // strcpy(production[6], "F=(E)"); 
    // strcpy(production[7], "F=i"); 
    //-------------|Input Ends|-------------//
    for(int i=0;i<productionCount;i++) {
        if((i>0) && (production[i][0]==production[i-1][0]))
            continue;
        firstTable[tableIdx][0]=production[i][0];
        followTable[tableIdx][0]=production[i][0];
        firstPointer=1;
        followPointer=1;
        buildFirstSet(production[i][0]);
        buildFollowSet(production[i][0]);
        tableIdx++;
    }
    printFirstTable();
    printFollowTable();
    strcpy(inputString,"abd$");
    for(stringLength=0;inputString[stringLength]!='\0';stringLength++);
    stringValidation();
}