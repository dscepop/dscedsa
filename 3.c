#include <stdio.h>
#include <stdlib.h>

#define max 5
int s[max], stop;
int ele, st[max], sp, ch;

void push(int ele, int s[], int *stop) {
    if (*stop >= max - 1)
        printf("Stack overflow\n");
    else
        s[++(*stop)] = ele;
}

int pop(int s[], int *top) {
    if (*top == -1) {
        printf("Stack underflow\n");
        return 0;
    } else
        return (s[(*top)--]);
}

void palindrome(int ele) {
    int rem, rev = 0, temp = ele;
    while (temp != 0) {
        rem = temp % 10;
        rev = rev * 10 + rem;
        temp = temp / 10;
    }
    if (ele == rev)
        printf("Palindrome\n");
    else
        printf("Not a palindrome\n");
}

void display(int s[], int *stop) {
    int i;
    if (*stop == -1)
        printf("Stack is empty\n");
    else
        for (i = *stop; i > -1; i--)
            printf("%d\n", s[i]);
}

int main() {
    stop = -1;
    sp = -1;
    while (1) {
        printf("Enter the choice\n");
        printf("Enter 1 to insert an element into the STACK\n");
        printf("Enter 2 to delete an element from the STACK\n");
        printf("Enter 3 to check if an element is a palindrome or not\n");
        printf("Enter 4 to check the status of the STACK\n");
        printf("Enter 5 to exit\n");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("Enter the element to be inserted into the STACK\n");
                scanf("%d", &ele);
                push(ele, s, &stop);
                break;
            case 2:
                ele = pop(s, &stop);
                if (ele != 0)
                    printf("Element popped is %d\n", ele);
                break;
            case 3:
                printf("Enter the element to check whether it is a palindrome\n");
                scanf("%d", &ele);
                palindrome(ele);
                break;
            case 4:
                printf("The status of the STACK\n");
                display(s, &stop);
                break;
            case 5:
                exit(0);
        }
    }
    return 0;
}
