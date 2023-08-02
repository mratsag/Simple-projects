#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> // isdigit fonksiyonu için

#define STACK_SIZE 20

struct node {
    int data;
    struct node *next;
};

typedef struct {
    int data[STACK_SIZE];
    int top;
} stack;

void initialize(stack *stk) {
    stk->top = -1;
}

void push(stack *stk, int x) {
    if (stk->top == STACK_SIZE - 1) {
        printf("Stack is full.\n");
    } else {
        stk->top++;
        stk->data[stk->top] = x;
    }
}

int pop(stack *stk) {
    if (stk->top == -1) {
        printf("Stack is empty.\n");
        return -100;
    } else {
        return stk->data[stk->top--];
    }
}

int main() {
    stack s;
    initialize(&s);
    char exp[20], *e;
    int n1, n2, num;
    printf("Enter a postfix expression: ");
    scanf("%s", exp);

    e = exp;

    while (*e != '\0') {
        if (isdigit(*e)) {
            num = *e - '0'; // ASCII'den çıkararak sayıya çevir
            push(&s, num);
        } else {
            n1 = pop(&s);
            n2 = pop(&s);

            switch (*e) {
                case '+':
                    push(&s, n1 + n2);
                    break;
                case '-':
                    push(&s, n2 - n1);
                    break;
                case '*':
                    push(&s, n1 * n2);
                    break;
                case '/':
                    push(&s, n2 / n1);
                    break;
                default:
                    break;
            }
        }

        e++;
    }

    printf("The result is %d\n", pop(&s));
    return 0; // main fonksiyonundan çıkarken 0 değeri döndürülerek programın başarılı bir şekilde sonlandığını belirtiyoruz
}
