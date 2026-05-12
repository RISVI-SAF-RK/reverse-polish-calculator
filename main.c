#include <stdio.h>
#include <stdlib.h>

#define MAX 100

float stack[MAX];
int top = -1;

/* PUSH FUNCTION */
void push(float value)
{
    if(top == MAX - 1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        top++;
        stack[top] = value;
    }
}

/* POP FUNCTION */
float pop()
{
    if(top == -1)
    {
        printf("Stack Underflow\n");
        return 0;
    }
    else
    {
        return stack[top--];
    }
}

/* DISPLAY TOP VALUE */
void displayTop()
{
    if(top == -1)
    {
        printf("Stack is Empty\n");
    }
    else
    {
        printf("Top of Stack = %.2f\n", stack[top]);
    }
}

int main()
{
    char choice;
    float a, b, num;

    printf("=====================================\n");
    printf(" Reverse Polish Calculator\n");
    printf("=====================================\n");

    while(1)
    {
        printf("\nChoose an option:\n");
        printf("?  -> Push Number\n");
        printf("+  -> Addition\n");
        printf("-  -> Subtraction\n");
        printf("*  -> Multiplication\n");
        printf("/  -> Division\n");
        printf("=  -> Display Top Value\n");
        printf("q  -> Quit\n");

        printf("\nEnter Choice: ");
        scanf(" %c", &choice);

        /* PUSH NUMBER */
        if(choice == '?')
        {
            printf("Enter Number: ");
            scanf("%f", &num);

            push(num);

            printf("%.2f pushed into stack\n", num);
        }

        /* ADDITION */
        else if(choice == '+')
        {
            b = pop();
            a = pop();

            push(a + b);

            printf("Addition Performed\n");
        }

        /* SUBTRACTION */
        else if(choice == '-')
        {
            b = pop();
            a = pop();

            push(a - b);

            printf("Subtraction Performed\n");
        }

        /* MULTIPLICATION */
        else if(choice == '*')
        {
            b = pop();
            a = pop();

            push(a * b);

            printf("Multiplication Performed\n");
        }

        /* DIVISION */
        else if(choice == '/')
        {
            b = pop();
            a = pop();

            if(b == 0)
            {
                printf("Division by Zero Error\n");
            }
            else
            {
                push(a / b);

                printf("Division Performed\n");
            }
        }

        /* DISPLAY RESULT */
        else if(choice == '=')
        {
            displayTop();
        }

        /* QUIT */
        else if(choice == 'q')
        {
            printf("Program Terminated\n");
            break;
        }

        else
        {
            printf("Invalid Input\n");
        }
    }

    return 0;
}
