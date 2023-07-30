#include <stdlib.h>
#include <stdio.h>

void menu(char *election) {
    printf("\n\n********   Menu List   ********\n\n");
    printf("1-Addition operation (+)\n");
    printf("2-Subtraction operation (-)\n");
    printf("3-Multiplication operation (*)\n");
    printf("4-Division operation (/)\n");
    printf("5-Exponentiation (^2)\n");
    printf("6-Take mod (%%)\n\n\n");

    printf("Select the operation you want to perform (1-6): ");
    scanf(" %c", election);
}

int power(int base, int exponent) {
    int result_power = 1;
    int i;
    for (i = 0; i < exponent; i++) {
        result_power *= base;
    }
    return result_power;
}

int main() {
    int num1, num2, base, exponent;
    float result;
    char election;


while(1){



    menu(&election);
    
    switch (election) {
        case '1':
            printf("Enter your number 1: ");
            scanf("%d", &num1);
            printf("Enter your number 2: ");
            scanf("%d", &num2);
            result = num1 + num2;
            printf("%d + %d = %.0f\n", num1, num2, result);
            break;

        case '2':
            printf("Enter your number 1: ");
            scanf("%d", &num1);
            printf("Enter your number 2: ");
            scanf("%d", &num2);
            result = num1 - num2;
            printf("%d - %d = %.0f\n", num1, num2, result);
            break;

        case '3':
            printf("Enter your number 1: ");
            scanf("%d", &num1);
            printf("Enter your number 2: ");
            scanf("%d", &num2);
            result = num1 * num2;
            printf("%d * %d = %.0f\n", num1, num2, result);
            break;

        case '4':
            printf("Enter your number 1: ");
            scanf("%d", &num1);
            printf("Enter your number 2: ");
            scanf("%d", &num2);
            result = (float)num1 / num2;
            printf("%d / %d = %.2f\n", num1, num2, result);
            break;

        case '5':
            printf("Enter the base number: ");
            scanf("%d", &base);

            printf("Enter the exponent: ");
            scanf("%d", &exponent);

            int result_power = power(base, exponent);
            printf("%d ^ %d = %d \n", base, exponent, result_power);
            break;
            
        case '6':
        	printf("Enter the first number: ");
    		scanf("%d", &num1);

    		printf("Enter the second number: ");
    		scanf("%d", &num2);

    		result = num1 % num2;

    		printf("Modulus of %d and %d is : %d\n", num1, num2, result);
    		break;

        default:
            printf("Invalid selection. Please select a valid operation (1-6).\n");
    }
    
    	char choice;
        printf("Do you want to perform another operation? (y/n): ");
        scanf(" %c", &choice);

        if (choice != 'y' && choice != 'Y')
            break;
            
   }

    return 0;
}

