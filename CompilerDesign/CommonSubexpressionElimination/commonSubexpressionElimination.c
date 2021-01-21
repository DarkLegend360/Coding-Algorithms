#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char input[10][10];
int inputCount;

bool isSame(int i, int j) {
    return input[i][2]==input[j][2] && input[i][3]==input[j][3] && input[i][4]==input[j][4] && strlen(input[j])>3 && strlen(input[i])>3;
}

bool isChange(int i, int j, int k) {
    return input[k][0]==input[i][2] || input[k][0]==input[i][4];
}

bool isChanged=false;

char *subString(char *str, int leftIdx, int rightIdx) 
{ 
    char *subStr = (char*)malloc( sizeof(char) * (rightIdx - leftIdx + 2)); 
    for (int i = leftIdx; i < rightIdx; i++) 
        subStr[i - leftIdx] = str[i]; 
    subStr[rightIdx - leftIdx + 1] = '\0'; 
    return subStr; 
}

char tmp[5];
char newString[20];

int T=0;

void commonSubexpressionElimination() {
    for(int i=0;i<inputCount;i++) {
        bool flag=false;
        bool match=false;
        for(int j=i+1;j<inputCount;j++) {
            isChanged=false;
            if(isSame(i, j)) {
                match=true;
                for(int k=i;k<j;k++)
                    if(isChange(i, j, k)){
                        isChanged=true;
                        flag=true;
                    }
                if(!isChanged) {
                    sprintf(tmp, "%d", T);
                    strcpy(newString,subString(input[j], 0, 2));
                    strcat(newString, "T");
                    strcat(newString, tmp);
                    strcpy(input[j],newString);
                }
            }
        }
        if(!flag && match && strlen(input[i])>4) {
            printf("T%d=%s\n", T, subString(input[i], 2, strlen(input[i])));
            printf("%c=T%d\n",input[i][0],T++);
        } else 
            printf("%s\n",input[i]);
    }
}

void main() {
    strcpy(input[0],"x=a+b");
    strcpy(input[1],"c=x+d");
    strcpy(input[2],"e=a+b");
    inputCount=3;
    commonSubexpressionElimination();
}