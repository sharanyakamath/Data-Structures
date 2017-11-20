#include<stdio.h>
#include<string.h>
//Evaluate prefix expression using stack
int stack[100];
int top =-1;

void push(int data) {
  stack[++top] = data;
}

int pop() {
  if(top == -1)
    return;
  return stack[top--];
}

int isOperand(char c) {
  return (c >= '0' && c <='9');
}

int compute(int a, int b, char op) {
    switch(op) {
      case '+' : return a+b;
      case '-' : return a-b;
      case '*' : return a*b;
      case '/' : return a/b;
      case '^' : return a^b;
    }
}

void main() {
  char pre[100];
  int i;
  printf("\nEnter expression");
  scanf("%s", pre);
  for(i = strlen(pre) - 1; i >= 0; --i) {
    if(isOperand(pre[i]))
      push(pre[i]-'0');
    else {
      int op = pre[i];
      int a = pop(), b = pop();
      push(compute(b, a, op));
    }
  }
  printf("\nResult : %d\n", stack[top]);
}
