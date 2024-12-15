#include <stdio.h>

void classifyResistance(float R) {
    if (R < 10)
        printf("Resistance: Low\n");
    else if (R <= 100)
        printf("Resistance: Medium\n");
    else
        printf("Resistance: High\n");
}

int main() {
    float V, I, R;
    int choice;

    printf("Select calculation: 1) Voltage 2) Current 3) Resistance: ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Enter Current (I) and Resistance (R): ");
        scanf("%f %f", &I, &R);
        V = I * R;
        printf("Voltage (V): %.2f V\n", V);
    }
    else if (choice == 2) {
        printf("Enter Voltage (V) and Resistance (R): ");
        scanf("%f %f", &V, &R);
        I = V / R;
        printf("Current (I): %.2f A\n", I);
    }
    else if (choice == 3) {
        printf("Enter Voltage (V) and Current (I): ");
        scanf("%f %f", &V, &I);
        R = V / I;
        printf("Resistance (R): %.2f Ω\n", R);
        classifyResistance(R);
    } else {
        printf("Invalid choice.\n");
    }
    return 0;
}
