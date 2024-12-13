#include <stdio.h>
#include <stdlib.h>

// Define Content Metadata Structure
typedef struct {
    char title[50];
    double rating;
    int runtime; // in minutes
} Content;

// Functions to manage the engagement matrix
double** createEngagementMatrix(int users, int categories) {
    double** matrix = (double**)malloc(users * sizeof(double*));
    for (int i = 0; i < users; i++) {
        matrix[i] = (double*)malloc(categories * sizeof(double));
        for (int j = 0; j < categories; j++) {
            matrix[i][j] = 0.0; // Initialize scores to zero
        }
    }
    return matrix;
}

void updateEngagement(double** matrix, int userIndex, int categoryIndex, double score) {
    matrix[userIndex][categoryIndex] += score; // Update engagement score
}

void displayEngagement(double** matrix, int users, int categories) {
    for (int i = 0; i < users; i++) {
        printf("User %d: ", i + 1);
        for (int j = 0; j < categories; j++) {
            printf("%.2f ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Main Function
int main() {
    int users = 3, categories = 4;
    double** engagementMatrix = createEngagementMatrix(users, categories);

    // Update some engagement scores
    updateEngagement(engagementMatrix, 0, 0, 5.5);
    updateEngagement(engagementMatrix, 1, 2, 3.2);
    updateEngagement(engagementMatrix, 2, 3, 4.8);

    // Display engagement matrix
    printf("Engagement Matrix:\n");
    displayEngagement(engagementMatrix, users, categories);

    // Clean up memory
    for (int i = 0; i < users; i++) {
        free(engagementMatrix[i]);
    }
    free(engagementMatrix);

    return 0;
}

