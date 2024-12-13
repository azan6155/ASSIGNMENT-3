#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void addSupplies(char*** inventory, int numSpecies, int* numSupplies);
void updateSupply(char*** inventory, int speciesIndex, int supplyIndex);
void removeSpecies(char*** inventory, int* numSupplies, int speciesIndex, int numSpecies);
void displayInventory(char** inventory[], int numSpecies, int* numSupplies);

int main() {
    int numSpecies, choice;
    printf("Enter the number of species: ");
    scanf("%d", &numSpecies);

    char*** inventory = (char***)malloc(numSpecies * sizeof(char**));
    int* numSupplies = (int*)calloc(numSpecies, sizeof(int));

    while (1) {
        printf("\n1. Add Supplies\n2. Update Supply\n3. Remove Species\n4. Display Inventory\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            addSupplies(inventory, numSpecies, numSupplies);
        } else if (choice == 2) {
            int speciesIndex, supplyIndex;
            printf("Enter species index (0-%d): ", numSpecies - 1);
            scanf("%d", &speciesIndex);
            printf("Enter supply index (0-%d): ", numSupplies[speciesIndex] - 1);
            scanf("%d", &supplyIndex);
            updateSupply(inventory, speciesIndex, supplyIndex);
        } else if (choice == 3) {
            int speciesIndex;
            printf("Enter species index (0-%d) to remove: ", numSpecies - 1);
            scanf("%d", &speciesIndex);
            removeSpecies(inventory, numSupplies, speciesIndex, numSpecies);
        } else if (choice == 4) {
            displayInventory(inventory, numSpecies, numSupplies);
        } else if (choice == 5) {
            for (int i = 0; i < numSpecies; i++) {
                for (int j = 0; j < numSupplies[i]; j++) {
                    free(inventory[i][j]);
                }
                free(inventory[i]);
            }
            free(inventory);
            free(numSupplies);
            break;
        } else {
            printf("Invalid choice!\n");
        }
    }

    return 0;
}

void addSupplies(char*** inventory, int numSpecies, int* numSupplies) {
    int speciesIndex, supplyCount;
    printf("Enter species index (0-%d): ", numSpecies - 1);
    scanf("%d", &speciesIndex);
    printf("Enter number of supplies to add: ");
    scanf("%d", &supplyCount);

    inventory[speciesIndex] = (char**)realloc(inventory[speciesIndex], (numSupplies[speciesIndex] + supplyCount) * sizeof(char*));

    for (int i = 0; i < supplyCount; i++) {
        printf("Enter name of supply %d: ", i + 1);
        inventory[speciesIndex][numSupplies[speciesIndex] + i] = (char*)malloc(50 * sizeof(char));
        scanf("%s", inventory[speciesIndex][numSupplies[speciesIndex] + i]);
    }
    numSupplies[speciesIndex] += supplyCount;
}

void updateSupply(char*** inventory, int speciesIndex, int supplyIndex) {
    printf("Enter new name for supply: ");
    scanf("%s", inventory[speciesIndex][supplyIndex]);
}

void removeSpecies(char*** inventory, int* numSupplies, int speciesIndex, int numSpecies) {
    for (int i = 0; i < numSupplies[speciesIndex]; i++) {
        free(inventory[speciesIndex][i]);
    }
    free(inventory[speciesIndex]);
    inventory[speciesIndex] = NULL;
    numSupplies[speciesIndex] = 0;
    printf("Species %d removed.\n", speciesIndex);
}

void displayInventory(char*** inventory, int numSpecies, int* numSupplies) {
    printf("\nInventory:\n");
    for (int i = 0; i < numSpecies; i++) {
        printf("Species %d: ", i);
        for (int j = 0; j < numSupplies[i]; j++) {
            printf("%s ", inventory[i][j]);
        }
        printf("\n");
    }
}

