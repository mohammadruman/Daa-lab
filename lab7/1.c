#include <stdio.h>

// Function to check if a number is a Harshad number
int isHarshad(int num) {
    int originalNum = num;
    int sum = 0;
    
    // Calculate the sum of digits
    while (num > 0) {
        int digit = num % 10;
        sum += digit;
        num /= 10;
    }   

    // Check if the original number is divisible by the sum of its digits
    if (originalNum % sum == 0) {
        return 1; // It's a Harshad number
    } else {
        return 0; // It's not a Harshad number
    }
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    if (isHarshad(num)) {
        printf("Yes, it's a Harshad number.\n");
    } else {
        printf("No, it's not a Harshad number.\n");
    }

    return 0;
}