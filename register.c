#include <stdio.h>
#include "register.h"


void print_item(int rows, int cols, int data[][cols]) {
    // Ask the user which item they want to print
    printf("Which item?\n");

    // Get user input for the item
    int itemCode;
    scanf("%d", &itemCode);

    // Check if the item code is within the valid range
    if (itemCode < 0 || itemCode >= rows) {
        printf("Invalid item code.\n");
        return;
    }

    // Print the header with month names
    printf("Jan\tFeb\tMar\tApr\tMay\tJun\tJul\tAug\tSep\tOct\tNov\tDec\n");

    // Print sales data for the selected item
    for (int month = 0; month < cols - 1; month++) {
        printf("%d\t", data[itemCode][month]);
    }
    
    // Print sales data for the selected item
    printf("%d\n",data[itemCode][cols-1]);
    
}

void total_sales(int rows, int cols, int data[][cols]) {
    // Open sales.txt for writing
    FILE *salesFile = fopen("sales.txt", "w");

    // Check if the file pointer is valid
    if (salesFile == NULL) {
        printf("Error opening sales.txt for writing.\n");
        return;
    }

    // Print the header to sales.txt
    fprintf(salesFile, "Item\tSales\n");

    // Loop through each item
    // Determine the total sales of each item
    for (int itemCode = 0; itemCode < rows; itemCode++) {
        // Initialize total sales for the current item to 0
        int totalSales = 0;

        // Loop through each month and accumulate sales
        for (int month = 0; month < cols; month++) {
            totalSales += data[itemCode][month];
        }

        // Print item code and total sales to sales.txt
        // Created using the following formatting code:
        fprintf(salesFile, "%02d\t%4d\n", itemCode, totalSales);
    }

    // Close sales.txt
    fclose(salesFile);
}

void top_overall(int rows, int cols, int data[][cols]) {
    // Initialize variables to keep track of the most popular item
    int mostPopularItem = 0;
    int maxSales = 0;

    // Loop through each item and calculate total sales
    // Find the total sales of each item
    for (int item = 0; item < rows; ++item) {
        int totalSales = 0;

        for (int month = 0; month < cols; ++month) {
            totalSales += data[item][month];
        }

        // Update mostPopularItem if the current item has higher sales
        if (totalSales > maxSales) {
            maxSales = totalSales;
            mostPopularItem = item;
        }
    }

    // Print the result to the terminal with the following format
    printf("The most popular item is item %d.\n", mostPopularItem);
}

