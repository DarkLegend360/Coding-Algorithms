#include <stdio.h>

int input[10][10];

void commonSubexpressionElimination() {

}

void main() {
    strcpy(input[0],"a=b+c");
    strcpy(input[1],"e=f+g");
    strcpy(input[2],"b=j");
    strcpy(input[3],"t=b+c");
    commonSubexpressionElimination();
}