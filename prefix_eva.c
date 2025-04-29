#include<stdio.h>
#include<string.h>
#define max 10

struct stack {
   int item[max];
   int top;
}s;

void push(struct stack *, int);
int pop(struct stack *);

int main() {
   char prefix[20];
   int i, x, y, z;
   
   // Initialize the stack
   s.top = -1;

   printf("\nEnter the prefix expression: ");
   gets(prefix);
   
   // Evaluate the expression from right to left
   for(i = strlen(prefix) - 1; i >= 0; i--) {
       // Check if the character is an operator
       if (prefix[i] == '+' || prefix[i] == '-' || prefix[i] == '*' || prefix[i] == '/') {
           x = pop(&s);
           y = pop(&s);
           
           if (prefix[i] == '+') {
               z = x + y;
               push(&s, z);
           }
           if (prefix[i] == '-') {
               z = x - y;
               push(&s, z);
           }
           if (prefix[i] == '*') {
               z = x * y;
               push(&s, z);
           }
           if (prefix[i] == '/') {
               z = x / y;
               push(&s, z);
           }
       } else { // If the character is an operand
           z = (int)prefix[i] - 48;  // Convert character to integer
           push(&s, z);
       }
   }
   
   // The final result will be at the top of the stack
   printf("\nThe evaluated prefix result is %d\n", pop(&s));
   
   return 0;
}

void push(struct stack *s, int x) {
   if(s->top == max - 1) {
       printf("\nOVERFLOW");
       return;
   }
   s->item[++s->top] = x;
}

int pop(struct stack *s) {
   if(s->top == -1) {
       printf("\nUNDERFLOW");
       return 0;
   }
   return s->item[s->top--];
}
