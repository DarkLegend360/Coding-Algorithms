#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//GRAMMAR: A->(A)/a
#define INPUT_STRING "(a)$"

//Shift Positive
//Reduce Negative
//500 Empty
//100 Accept

char terminals[]="a()$";
char nonTerminals[]="A";

int action[][5] = {
/*        a    (    )       $   */
/* I0 */ {3, 2, 500, 500},
/* I1 */ {500, 500, 500, 100},
/* I2 */ {3, 2, 500, 500},
/* I3 */ {500, 500, -2, -2},
/* I4 */ {500, 500, 5, 500},
/* I5 */ {500, 500, -1, -1}
};
int goTo[][1] = {
/*        A   */
/* I0 */ {1},
/* I1 */ {500},
/* I2 */ {4},
/* I3 */ {500},
/* I4 */ {500},
/* I5 */ {500}
};

int stringLength;
int stringIdx;
char stackA[20];
char stackTop=-1;
char inputString[10];

char R1[]="AA";//left
char R2[][5]={"(A)","a"};//right

int getTerminalIdx(char target) {
    for(int i=0;terminals[i]!='\0';i++)
        if(terminals[i]==target)
            return i;
    printf("You have failed this city.");
    return -1;
}

int getNonTerminalIdx(char target) {
    for(int i=0;nonTerminals[i]!='\0';i++)
        if(nonTerminals[i]==target)
            return i;
    printf("you have failed this world.");
    return -1;
}

char getStackTop() {
    return stackA[stackTop];
}

char getStackTopPrev() {
    return stackA[stackTop-1];
}

int getOperation() {
    return action[getStackTop()-'0'][getTerminalIdx(inputString[stringIdx])];
}

void pushTerminalToStack(char I) {
    stackA[++stackTop]=inputString[stringIdx++];
    stackA[++stackTop]=I;
}

void printStackContents() {
    printf("\nSTACK: ");
    for(int i=0;i<=stackTop;i++)
        printf("%c ",stackA[i]);
    printf("\n");
}

void printAction(int op,int flag) {
    if(flag==1) {
        printf("\nShift %d",op);
    } else {
        printf("Reduce %d",op);
    }
}

int getLength(int r) {
    return strlen(R2[r]);
}

void applyReduction(int reduction) {
    int idx=getLength(reduction-1)-1;
    while(idx!=-1) {
        while(stackA[stackTop]!=R2[reduction-1][idx])
            stackTop--;
        stackTop--;
        idx--;
    }
    stackA[++stackTop]=R1[reduction-1];
    stackA[++stackTop]=goTo[getStackTopPrev()-'0'][getNonTerminalIdx(stackA[stackTop])]+'0';
    printStackContents();
}

void parseString() {
    stackA[++stackTop]='$';
    stackA[++stackTop]='0';
    while(1) {
        printStackContents();
        printf("CURCHAR: %c",inputString[stringIdx]);
        int operation = getOperation();
        if(operation==100) {
            printf("\nString Accepted.\n");
            exit(0);
        }
        else if(operation==500) {
            printf("\nString Rejected\n");
            exit(0);
        } else if(operation>=0) {//Shift
            pushTerminalToStack(operation+'0');
            printAction(operation,1);
        } else {//Reduce
            operation*=-1;
            applyReduction(operation);
            printAction(operation,0);
        }
    }
}

int main() {
    strcpy(inputString,INPUT_STRING);
    stringLength=strlen(inputString);
    parseString();
    return 0;
}