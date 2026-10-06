/*
Name: Bahar Ozer
*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *int_ptr;  
    // Pointer for the integer array

    int_ptr = malloc(2 * sizeof(int));  
    // Allocate memory for 2 integers

    if (int_ptr == NULL)
    {
        // Check if memory allocation failed
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter first integer: ");
    if (scanf("%d", &int_ptr[0]) != 1)
    {
        // Read first integer and validate input
        printf("Invalid input.\n");
        free(int_ptr);
        return 1;
    }

    printf("Enter second integer: ");
    if (scanf("%d", &int_ptr[1]) != 1)
    {
        // Read second integer and validate input
        printf("Invalid input.\n");
        free(int_ptr);
        return 1;
    }

    printf("Original values: 1st = %d , 2nd = %d\n",
           int_ptr[0], int_ptr[1]);
    // Display original values before swapping

    /* XOR swap without using a third variable */
    int_ptr[0] = int_ptr[0] ^ int_ptr[1];  
    int_ptr[1] = int_ptr[0] ^ int_ptr[1]; 
    int_ptr[0] = int_ptr[0] ^ int_ptr[1];  

    printf("Swapped values: 1st = %d , 2nd = %d\n",
           int_ptr[0], int_ptr[1]);
    // Display values after swapping

    free(int_ptr);  
    // Free allocated memory

    return 0;
}
