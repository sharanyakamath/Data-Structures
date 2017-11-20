#include<stdio.h>
#include<string.h>
// convert infix to prefix

char stack[100];
int top = -1;

void push(int data) {
  stack[++top] = data;
}

char pop() {
  if(top == -1)
    return;
  return stack[top--];
}

int isOperand(char c) {
  return (c >= 'a' && c <='z');
}

int prec(char op) {
  switch(op) {
    case '+': case '-': return 1;
    case '*': case '/': return 2;
    case '^': return 3;
    default: return 0;
  }
}

void reverse(char str[100]) {
  int i, l = strlen(str);
  for(i = 0; i < l/2; ++i) {
    char t = str[i];
    str[i] = str[l-i-1];
    str[l-i-1] = t;
  }
  str[l] = '\0';
  printf("\nPrefix expression%s\n", str);
}

void convert(char exp[100]) {
  int i, k;
  char pre[100];
  for(i = strlen(exp) - 1, k = -1; i >= 0; --i){
    if(isOperand(exp[i]))
      pre[++k] = exp[i];
    else if(exp[i] == ')')
      push(exp[i]);
    else if(exp[i] == '(') {
      while(stack[top] != ')' && top != -1)
        pre[++k] = pop();
      top--; //remove ) from stack
    }
    else {
      while(prec(exp[i]) <= prec(stack[top])){
        pre[++k] = pop();
      }
      push(exp[i]);
   }
 }
  while(top != -1)
    pre[++k] = pop();
  pre[++k] = '\0';
  reverse(pre);
}


void main() {
  char inf[100];
  printf("\nEnter infix expression : ");
  scanf("%s", inf);
  convert(inf);
}
