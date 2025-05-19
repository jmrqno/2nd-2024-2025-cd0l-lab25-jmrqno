/*
 * CMSC 125 Lab 04
 * Simple Calculator Program Template
 * Complete the implementation and customize as needed.
 */

 #include <stdio.h>
 #include <math.h>
 
 // Function prototypes
 double add(double a, double b);
 double subtract(double a, double b);
 double multiply(double a, double b);
 double divide(double a, double b);
 int modulus(int a, int b);
 double power(double base, int exponent);
 void print_menu();
 
 int main() {
     int choice;
     double num1, num2, result;
     int int1, int2;
 
     do {
         print_menu();
         printf("Select an operation (1-7), or 0 to exit: ");
         if (scanf("%d", &choice) != 1) {
             printf("Invalid input! Please enter a number.\n");
             while(getchar() != '\n'); // clear input buffer
             continue;
         }
 
         if (choice == 0) {
             printf("Exiting the calculator. Goodbye!\n");
             break;
         }
 
         if (choice < 0 || choice > 7) {
             printf("Invalid choice! Please select a valid option.\n");
             continue;
         }
 
         if (choice == 5 || choice == 6) {
             // For modulus and power, get integer inputs
             printf("Enter first integer: ");
             if (scanf("%d", &int1) != 1) {
                 printf("Invalid input! Please enter an integer.\n");
                 while(getchar() != '\n');
                 continue;
             }
             printf("Enter second integer: ");
             if (scanf("%d", &int2) != 1) {
                 printf("Invalid input! Please enter an integer.\n");
                 while(getchar() != '\n');
                 continue;
             }
         } else {
             // For other operations, get double inputs
             printf("Enter first number: ");
             if (scanf("%lf", &num1) != 1) {
                 printf("Invalid input! Please enter a number.\n");
                 while(getchar() != '\n');
                 continue;
             }
             printf("Enter second number: ");
             if (scanf("%lf", &num2) != 1) {
                 printf("Invalid input! Please enter a number.\n");
                 while(getchar() != '\n');
                 continue;
             }
         }
 
         switch(choice) {
             case 1:
                 result = add(num1, num2);
                 printf("Result: %.2lf + %.2lf = %.2lf\n", num1, num2, result);
                 break;
             case 2:
                 result = subtract(num1, num2);
                 printf("Result: %.2lf - %.2lf = %.2lf\n", num1, num2, result);
                 break;
             case 3:
                 result = multiply(num1, num2);
                 printf("Result: %.2lf * %.2lf = %.2lf\n", num1, num2, result);
                 break;
             case 4:
                 if (num2 == 0) {
                     printf("Error: Division by zero is not allowed.\n");
                 } else {
                     result = divide(num1, num2);
                     printf("Result: %.2lf / %.2lf = %.2lf\n", num1, num2, result);
                 }
                 break;
             case 5:
                 if (int2 == 0) {
                     printf("Error: Modulus by zero is not allowed.\n");
                 } else {
                     int modResult = modulus(int1, int2);
                     printf("Result: %d %% %d = %d\n", int1, int2, modResult);
                 }
                 break;
             case 6:
                 result = power((double)int1, int2);
                 printf("Result: %d ^ %d = %.2lf\n", int1, int2, result);
                 break;
             case 7:
                 printf("Thank you for using the calculator.\n");
                 break;
             default:
                 printf("Invalid choice.\n");
         }
 
         printf("\n");
 
     } while(choice != 7);
 
     return 0;
 }
 
 // Function definitions
 double add(double a, double b) {
     return a + b;
 }
 
 double subtract(double a, double b) {
     return a - b;
 }
 
 double multiply(double a, double b) {
     return a * b;
 }
 
 double divide(double a, double b) {
     return a / b;
 }
 
 int modulus(int a, int b) {
     return a % b;
 }
 
 double power(double base, int exponent) {
     double result = 1.0;
     int i;
     int positiveExponent = exponent >= 0 ? exponent : -exponent;
 
     for (i = 0; i < positiveExponent; i++) {
         result *= base;
     }
 
     if (exponent < 0) {
         return 1.0 / result;
     }
 
     return result;
 }
 
 void print_menu() {
     printf("=== Simple Calculator ===\n");
     printf("1. Addition (+)\n");
     printf("2. Subtraction (-)\n");
     printf("3. Multiplication (*)\n");
     printf("4. Division (/)\n");
     printf("5. Modulus (%%)\n");
     printf("6. Power (^)\n");
     printf("7. Exit\n");
 }
 