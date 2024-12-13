#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structures
typedef struct {
    char cropType[20];
    char growthStage[20];
    double expectedYield;
} Crop;

typedef struct {
    double temperature;
    double rainfall;
    double windSpeed;
} Weather;

typedef struct {
    char equipmentType[20];
    char status[20];
    double fuelLevel;
} Equipment;

typedef struct {
    double nutrientLevel;
    double pHLevel;
    double pestActivity;
} Sensor;

typedef struct {
    double latitude, longitude;
    double soilHealth, moistureLevel;
    Crop* crops;
    int numCrops;
    Weather* weather;
    Equipment* equipment;
    int numEquipment;
    Sensor* sensors;
    int numSensors;
} Field;

typedef struct {
    char regionName[20];
    Field* fields;
    int numFields;
} RegionalHub;

// Functions
Field createField(int numCrops, int numEquipment, int numSensors) {
    Field field;
    field.crops = (Crop*)malloc(numCrops * sizeof(Crop));
    field.weather = (Weather*)malloc(sizeof(Weather));
    field.equipment = (Equipment*)malloc(numEquipment * sizeof(Equipment));
    field.sensors = (Sensor*)malloc(numSensors * sizeof(Sensor));
    field.numCrops = numCrops;
    field.numEquipment = numEquipment;
    field.numSensors = numSensors;
    return field;
}

void displayField(Field field) {
    printf("Field GPS: (%lf, %lf)\n", field.latitude, field.longitude);
    printf("Soil Health: %lf, Moisture Level: %lf\n", field.soilHealth, field.moistureLevel);

    printf("Crops:\n");
    for (int i = 0; i < field.numCrops; i++) {
        printf("  Crop Type: %s, Growth Stage: %s, Expected Yield: %.2f\n",
               field.crops[i].cropType, field.crops[i].growthStage, field.crops[i].expectedYield);
    }

    printf("Weather: Temperature: %.2f, Rainfall: %.2f, Wind Speed: %.2f\n",
           field.weather->temperature, field.weather->rainfall, field.weather->windSpeed);

    printf("Equipment:\n");
    for (int i = 0; i < field.numEquipment; i++) {
        printf("  Type: %s, Status: %s, Fuel Level: %.2f\n",
               field.equipment[i].equipmentType, field.equipment[i].status, field.equipment[i].fuelLevel);
    }

    printf("Sensors:\n");
    for (int i = 0; i < field.numSensors; i++) {
        printf("  Nutrient: %.2f, pH: %.2f, Pest Activity: %.2f\n",
               field.sensors[i].nutrientLevel, field.sensors[i].pHLevel, field.sensors[i].pestActivity);
    }
}

int main() {
    // Create a field
    Field field = createField(2, 2, 2);
    field.latitude = 37.7749;
    field.longitude = -122.4194;
    field.soilHealth = 85.5;
    field.moistureLevel = 60.2;

    // Initialize crops
    strcpy(field.crops[0].cropType, "Wheat");
    strcpy(field.crops[0].growthStage, "Sprouting");
    field.crops[0].expectedYield = 1200;

    strcpy(field.crops[1].cropType, "Corn");
    strcpy(field.crops[1].growthStage, "Mature");
    field.crops[1].expectedYield = 1500;

    // Initialize weather
    field.weather->temperature = 28.5;
    field.weather->rainfall = 10.2;
    field.weather->windSpeed = 5.0;

    // Initialize equipment
    strcpy(field.equipment[0].equipmentType, "Tractor");
    strcpy(field.equipment[0].status, "Active");
    field.equipment[0].fuelLevel = 80.5;

    strcpy(field.equipment[1].equipmentType, "Drone");
    strcpy(field.equipment[1].status, "Standby");
    field.equipment[1].fuelLevel = 50.3;

    // Initialize sensors
    field.sensors[0].nutrientLevel = 75.4;
    field.sensors[0].pHLevel = 6.8;
    field.sensors[0].pestActivity = 10.5;

    field.sensors[1].nutrientLevel = 80.1;
    field.sensors[1].pHLevel = 7.0;
    field.sensors[1].pestActivity = 5.2;

    // Display field details
    displayField(field);

    // Free allocated memory
    free(field.crops);
    free(field.weather);
    free(field.equipment);
    free(field.sensors);

    return 0;
}

