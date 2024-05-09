#include <stdio.h>
#include "register.h"

int main() {
    // Create a 50x12 array to store the input files
    int salesData[50][12];
    
    FILE* f1;
    
    // Open 12 files from Jan to Dec
    for (int i = 0; i < 12; i++)
    {
        switch (i)
        {
        case 0:
            f1 = fopen("Jan_2023_data.txt","r");
            break;
        case 1:
            f1 = fopen("Feb_2023_data.txt","r");
            break;
        case 2:
            f1 = fopen("Mar_2023_data.txt","r");
            break;
        case 3:
            f1 = fopen("Apr_2023_data.txt","r");
            break;
        case 4:
            f1 = fopen("May_2023_data.txt","r");
            break;
        case 5:
            f1 = fopen("Jun_2023_data.txt","r");
            break;
        case 6:
            f1 = fopen("Jul_2023_data.txt","r");
            break;
        case 7:
            f1 = fopen("Aug_2023_data.txt","r");
            break;
        case 8:
            f1 = fopen("Sep_2023_data.txt","r");
            break;
        case 9:
            f1 = fopen("Oct_2023_data.txt","r");
            break;
        case 10:
            f1 = fopen("Nov_2023_data.txt","r");
            break;
        case 11:
            f1 = fopen("Dec_2023_data.txt","r");
            break;
        default:
            fprintf(stderr, "Invalid month: %d\n", i + 1);
            return 1; // Exit the program with an error code
        }
        if (f1 == NULL) {
            fprintf(stderr, "Error opening file for month %d.\n", i + 1);
            return 1; // Exit the program with an error code
        }

        // Read data from the file and store it in the salesData array
        for (int j = 0; j < 50; j++) {
            // Use the provided formatting to skip the first two columns and read the third column as an integer
            int sales;
            int result = fscanf(f1, "%*d %*s %d", &sales);

            // Check if fscanf was successful
            if (result == 1) {
                // Assign the read value to the array
                salesData[j][i] = sales;
            } else {
                fprintf(stderr, "Error reading from file for month %d.\n", i + 1);
                fclose(f1);
                return 1; // Exit the program with an error code
            }
        }

        // Close the file
        fclose(f1);
    }
    
    // Prompt the user for the desired calculation
    int choice;
    printf("Which program would you like to run?\n");
    printf("(1) Output the monthly sales of an item.\n");
    printf("(2) Calculate overall sales for all items.\n");
    printf("(3) Find the most popular item.\n");
    scanf("%d", &choice);

    // Get the user input and run the corresponding function
    switch (choice) {
        case 1:
            // Call print_item function
            print_item(50, 12, salesData);
            break;
        case 2:
            // Call total_sales function
            total_sales(50, 12, salesData);
            break;
        case 3:
            // Call top_overall function
            top_overall(50, 12, salesData);
            break;
        default:
            printf("Invalid choice. Exiting.\n");
            return 1; // Exit with an error code
    }

    return 0; // Exit successfully
}
