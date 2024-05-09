#ifndef REGISTER_H
#define REGISTER_H

#include <stdio.h>

/**
 * Print the sales data for a specific item.
 *
 * @param rows The number of rows in the data array.
 * @param cols The number of columns in the data array.
 * @param data The 2D array containing sales data.
 */
void print_item(int rows, int cols, int data[][cols]);

/**
 * Calculate and print the total sales for each item.
 *
 * @param rows The number of rows in the data array.
 * @param cols The number of columns in the data array.
 * @param data The 2D array containing sales data.
 * The results are printed to a file named "sales.txt".
 */
void total_sales(int rows, int cols, int data[][cols]);

/**
 * Find and print the most popular item overall.
 *
 * @param rows The number of rows in the data array.
 * @param cols The number of columns in the data array.
 * @param data The 2D array containing sales data.
 * Prints the most popular item to the terminal.
 */
void top_overall(int rows, int cols, int data[][cols]);

#endif  // REGISTER_H
