#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

#define STACK_SIZE 20

int top = -1;
int s[STACK_SIZE];

void push(int item) {
    if (top == STACK_SIZE - 1) {
        printf("Stack Overflow\n");
        exit(1);
    }
    top++;
    s[top] = item;
}

int pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return s[top--];
}

int main() {
    int op1, op2, res;
    char postfix[90], symb;
    int i = 0; // Declare and initialize 'i' here
    int j;     // Declare 'j' here

    clrscr(); // Clear screen in Turbo C

    printf("\nEnter a valid postfix expression:\n");
    scanf("%s", postfix);

    while (postfix[i] != '\0') { // Use a while loop instead of a for loop
        symb = postfix[i];
        if (isdigit((unsigned char)symb)) { // Cast char to unsigned char
            push(symb - '0'); // Convert char to int
        } else {
            op2 = pop();
            op1 = pop();
            switch (symb) {
                case '+':
                    push(op1 + op2);
                    break;
                case '-':
                    push(op1 - op2);
                    break;
                case '*':
                    push(op1 * op2);
                    break;
                case '/':
                    if (op2 == 0) {
                        printf("Division by zero\n");
                        exit(1);
                    }
                    push(op1 / op2);
                    break;
                case '%':
                    push(op1 % op2);
                    break;
                case '^': // Handle exponentiation differently
                    res = 1;
                    j = 0; // Initialize 'j' here
                    while (j < op2) {
                        res *= op1;
                        j++;
                    }
                    push(res);
                    break;
                default:
                    printf("Invalid operator\n");
                    exit(1);
            }
        }
        i++; // Increment i
    }
    res = pop();
    printf("\nResult = %d", res);

    getch(); // Wait for user input before closing the window
    return 0;
}


#include<stdio.h>
#include<math.h>

void tower(int n, char source, char temp, char destination) {
  if (n == 0)
    return;
  tower(n - 1, source, destination, temp);
  printf("\nMove disc %d from %c to %c", n, source, destination);
  tower(n - 1, temp, source, destination);
}

int main() {
  int n;
  printf("\nEnter the number of discs: \n");
  scanf("%d", & n);
  tower(n, 'A', 'B', 'C');
  printf("\n\nTotal Number of moves are: %d", (int) pow(2, n) - 1);
  return 0;
}

