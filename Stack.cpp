//Implement Stack

#include <stdio.h>

int A[10] = {0};
int ptr = 0;
int t = 0;

void push(int a) {
    A[ptr + 1] = a;
    ptr++;
}

void pop() {
    A[ptr] = 0;
    ptr--;
}

int top() {
    return A[ptr];
}

int main() {
    push(5); // Insert Operation
    t = top(); // View elements on the end
    printf("%d\n", t); 
    pop(); // Delete Operation
    
    return 0;
}