#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void inputRatings(int** ratings, int numEmployees, int numPeriods);
void displayRatings(int** ratings, int numEmployees, int numPeriods);
int findBestEmployee(int** ratings, int numEmployees, int numPeriods);
int findBestPeriod(int** ratings, int numEmployees, int numPeriods);
int findWorstEmployee(int** ratings, int numEmployees, int numPeriods);

int main() {
    int numEmployees, numPeriods;

    // Input employee and period count
    printf("Enter number of employees: ");
    scanf("%d", &numEmployees);
    printf("Enter number of evaluation periods: ");
    scanf("%d", &numPeriods);

    // Allocate memory for ratings
    int** ratings = (int**)malloc(numEmployees * sizeof(int*));
    for (int i = 0; i < numEmployees; i++) {
        ratings[i] = (int*)malloc(numPeriods * sizeof(int));
    }

    // Input, display, and analyze ratings
    inputRatings(ratings, numEmployees, numPeriods);
    displayRatings(ratings, numEmployees, numPeriods);

    printf("Employee of the Year: Employee %d\n", findBestEmployee(ratings, numEmployees, numPeriods) + 1);
    printf("Highest Rated Period: Period %d\n", findBestPeriod(ratings, numEmployees, numPeriods) + 1);
    printf("Worst Performing Employee: Employee %d\n", findWorstEmployee(ratings, numEmployees, numPeriods) + 1);

    // Free allocated memory
    for (int i = 0; i < numEmployees; i++) {
        free(ratings[i]);
    }
    free(ratings);

    return 0;
}

// Input ratings for employees
void inputRatings(int** ratings, int numEmployees, int numPeriods) {
    for (int i = 0; i < numEmployees; i++) {
        printf("Enter ratings for Employee %d:\n", i + 1);
        for (int j = 0; j < numPeriods; j++) {
            do {
                printf("Period %d (1-10): ", j + 1);
                scanf("%d", &ratings[i][j]);
                if (ratings[i][j] < 1 || ratings[i][j] > 10) {
                    printf("Invalid input! Enter a number between 1 and 10.\n");
                }
            } while (ratings[i][j] < 1 || ratings[i][j] > 10);
        }
    }
}

// Display ratings
void displayRatings(int** ratings, int numEmployees, int numPeriods) {
    printf("\nRatings:\n");
    for (int i = 0; i < numEmployees; i++) {
        printf("Employee %d: ", i + 1);
        for (int j = 0; j < numPeriods; j++) {
            printf("%d ", ratings[i][j]);
        }
        printf("\n");
    }
}

// Find the employee with the highest average rating
int findBestEmployee(int** ratings, int numEmployees, int numPeriods) {
    int bestIndex = 0;
    double bestAvg = 0;

    for (int i = 0; i < numEmployees; i++) {
        int sum = 0;
        for (int j = 0; j < numPeriods; j++) {
            sum += ratings[i][j];
        }
        double avg = (double)sum / numPeriods;
        if (avg > bestAvg) {
            bestAvg = avg;
            bestIndex = i;
        }
    }

    return bestIndex;
}

// Find the period with the highest average rating
int findBestPeriod(int** ratings, int numEmployees, int numPeriods) {
    int bestPeriod = 0;
    double bestAvg = 0;

    for (int j = 0; j < numPeriods; j++) {
        int sum = 0;
        for (int i = 0; i < numEmployees; i++) {
            sum += ratings[i][j];
        }
        double avg = (double)sum / numEmployees;
        if (avg > bestAvg) {
            bestAvg = avg;
            bestPeriod = j;
        }
    }

    return bestPeriod;
}

// Find the employee with the lowest average rating
int findWorstEmployee(int** ratings, int numEmployees, int numPeriods) {
    int worstIndex = 0;
    double worstAvg = 1e9;

    for (int i = 0; i < numEmployees; i++) {
        int sum = 0;
        for (int j = 0; j < numPeriods; j++) {
            sum += ratings[i][j];
        }
        double avg = (double)sum / numPeriods;
        if (avg < worstAvg) {
            worstAvg = avg;
            worstIndex = i;
        }
    }

    return worstIndex;
}

