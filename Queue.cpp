//Implement Queue

#include <stdio.h>

int A[10] = { 0 };
int head = 0;
int tail = 0;
int tmp;

void enqueue(int a) {
    A[tail] = a;
    tail++;
}

void dequeue() {
    for (int i = 0; i < tail; i++) {
        A[i] = A[i + 1];
    }
}

int front() {
    return A[head];
}

int back() {
    return A[tail - 1];
}

int main() {
    enqueue(1); // Insert Operation
    enqueue(5); 
    tmp = front(); // View elements on head
    printf("%d\n", tmp);
    tmp = back(); // View elements on tail
    printf("%d", tmp);
    dequeue(); // Delete Operation
    dequeue();

    return 0;
}