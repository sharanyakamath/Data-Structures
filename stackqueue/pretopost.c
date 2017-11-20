#include<stdio.h>
#include<string.h>
//prefix to postfix

char stack[50][100];
int top = -1;

void push(char data[100]) {
  stack[++top] = data;
}

char[100] pop() {
  if(top == -1)
    return;
  return stack[top--];
}

int isOperand(char c) {
  return (c >= 'a' && c <='z');
}

void traverse() {

}

void convert(char exp[100]) {
  int i, k;
  char a[100], b[100];

  for(i = strlen(exp)-1; i >= 0; ++i) {
    printf("\n %d", top);
    if(!isOperand(exp[i])){
      char t[100];
      t[0] = exp[i];
      t[1] = '\0';
      push(t);
    }
    else {
      a = pop();
      b = pop();
      strcat(a,b);
      int l = strlen(a);
      a[l] = exp[i];
      a[l+1] = '\0';
      push(a);
    }
  }
  printf("\n %s\n", stack[top]);
}
void main() {
  char pre[100];
  printf("\nEnter postfix expression : ");
  scanf("%s", pre);
  convert(pre);
}
