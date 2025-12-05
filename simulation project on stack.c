#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int stack[MAX];
int top = -1;

// PUSH operation
void push(int x) {
    if (top == MAX - 1) {
        printf("Stack Overflow!\n");
        return;
    }
    stack[++top] = x;
    printf("%d pushed to stack.\n", x);
}

// POP operation
void pop() {
    if (top == -1) {
        printf("Stack Underflow!\n");
        return;
    }
    printf("%d popped from stack.\n", stack[top--]);
}

// PEEK operation
void peek() {
    if (top == -1) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Top element: %d\n", stack[top]);
}

// DISPLAY operation
void display() {
    if (top == -1) {
        printf("Stack is empty.\n");
        return;
    }

    printf("Stack elements: ");
    for (int i = 0; i <= top; i++) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    int choice = 0, value = 0;
    char line[128];
    struct node* root = NULL; // if you don't use BST, you can ignore this

    while (1) {
        printf("\n====== STACK SIMULATION ======\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter choice: ");

        if (!fgets(line, sizeof(line), stdin)) { /* input error / EOF */
            printf("Input error. Exiting.\n");
            break;
        }
        /* parse integer safely */
        if (sscanf(line, "%d", &choice) != 1) {
            printf("Invalid input. Please enter a number between 1 and 5.\n");
            continue;
        }

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                if (!fgets(line, sizeof(line), stdin)) { printf("Input error.\n"); break; }
                if (sscanf(line, "%d", &value) != 1) {
                    printf("Invalid number. Push cancelled.\n");
                } else {
                    push(value);
                }
                break;

            case 2:
                pop();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 5:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice! Enter 1-5.\n");
        }
    }

    return 0;
}
