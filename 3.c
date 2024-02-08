#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

#include<math.h>

#define max 5
int s[max], stop;
int ele, st[max], sp, ch;
void push(int ele, int s[], int * stop) {
  if ( * stop >= max - 1)
    printf("stock overflow\n");
  else
    s[++ * stop] = ele;
}
int pop(int s[], int * top) {
  if ( * top == -1) {
    printf("stock emptynderflow ");
    return 0;
  } else
    return (s[( * top) --]);
}
void palindrome(int ele, int st[]) {
  int rem, rev = 0, temp = ele, i = 0;
  while (temp != 0) {
    rem = temp % 10;
    push(rem, st, & sp);
    temp = temp / 10;
  }
  while (sp != -1)
    rev = rev + (pop(st, & sp) * pow(10, i++));
  if (ele == rev)
    printf("palendrome\n");
  else
    printf("not a palindrome\n");

}
void display(int s[], int * stop) {
  int i;
  if ( * stop == -1)
    printf("stalk is empty\n");
  else
    for (i = * stop; i > -1; i--)
      printf("%d\n", s[i]);
}
void main() {
  stop = -1;
  sp = -1;
  while (1) {
    printf("enter tne choice\n");
    printf("enter 1 to insert an element into the STACK\n");
    printf("enter 2 to delete an element from the STACK\n");
    printf("enter 3 to check an element is palindrome or not\n");
    printf("enter 4 to check the status of the STACK\n");
    printf("enter 5 to exit\n");
    scanf("%d", & ch);
    switch (ch) {
    case 1:
      printf("enter the elements to de inserted to STACK\n");
      scanf("%d", & ele);
      push(ele, s, & stop);
      break;
    case 2:
      ele = pop(s, & stop);
      if (ele != 0)
        printf("element poped is %d\n", ele);
      break;
    case 3:
      printf("enter the elements to chech weather it is a palindrome\n");
      scanf("%d", & ele);
      palindrome(ele, st);
      break;
    case 4:
      printf("the status of the STACK \n");
      display(s, & stop);
      break;
    case 5:
      exit(0);
    }
  }
}