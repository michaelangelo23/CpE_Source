#include <stdio.h>

int main() {
    float weightLBS, heightCM, weightKG, heightM, bmi;

    printf("Enter weight in pounds (lbs): "); // Prompt user for weight in pounds
    scanf("%f", &weightLBS);

    printf("Enter height in centimeters (cm): "); // Prompt user for height in centimeters
    scanf("%f", &heightCM);

    weightKG = weightLBS * 0.453592; // Convert weight to kilograms

    heightM = heightCM / 100; // Convert height to meters

    bmi = weightKG / (heightM * heightM); // Compute BMI

    printf("Your BMI is: %.2f\n", bmi);  // Print the BMI

    return 0;
}
