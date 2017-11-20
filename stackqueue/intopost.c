#include<stdio.h>
//Conversion of infix to postfix using stack

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

void traverse() {
  int p = 0;
  while(p <= top){
    printf(" %c",stack[p]);
    p++;
  }
}

int prec(char op) {
  switch(op) {
    case '+': case '-': return 1;
    case '*': case '/': return 2;
    case '^': return 3;
    default: return 0;
  }
}

void convert(char exp[100]) {
  int i, k;
  for(i = 0, k = -1; exp[i]; ++i){

    if(isOperand(exp[i]))
      exp[++k] = exp[i];
    else if(exp[i] == '(')
      push(exp[i]);
    else if(exp[i] == ')') {
      while(stack[top] != '(' && top != -1)
        exp[++k] = pop();
      top--; //remove ( from stack
    }
    else {
          while(prec(exp[i]) <= prec(stack[top])){
            exp[++k] = pop();
          }
          push(exp[i]);
   }
 }
  while(top != -1)
    exp[++k] = pop();
  exp[++k] = '\0';
  printf("\nPostfix expression : %s\n\n", exp);
}

void main() {
  char inf[100];
  printf("\nEnter infix expression : ");
  scanf("%s", inf);
  convert(inf);
}
