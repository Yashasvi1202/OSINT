#include <stdio.h>
#include <math.h>

int main() {
    double a, b, c;
    double discriminant, root1, root2, realPart, imagPart;

    printf("Enter coefficients a, b and c: ");
    if (scanf("%lf %lf %lf", &a, &b, &c) != 3) {
        printf("Invalid input.\n");
        return 1;
    }

    // Ensure it is a valid quadratic equation
    if (a == 0) {
        printf("Coefficient 'a' cannot be zero in a quadratic equation.\n");
        return 1;
    }

    // Calculate discriminant
    discriminant = b * b - 4 * a * c;

    // Condition for real and distinct roots
    if (discriminant > 0) {
        root1 = (-b + sqrt(discriminant)) / (2 * a);
        root2 = (-b - sqrt(discriminant)) / (2 * a);
        printf("Roots are real and distinct.\n");
        printf("root1 = %.2lf\n", root1);
        printf("root2 = %.2lf\n", root2);
    }
    // Condition for real and equal roots
    else if (discriminant == 0) {
        root1 = root2 = -b / (2 * a);
        printf("Roots are real and equal.\n");
        printf("root1 = root2 = %.2lf\n", root1);
    }
    // Condition for complex/imaginary roots flagfall{F0UNd_THE_FL@G_GFhvfywdvGDyajnr}
    else {
        realPart = -b / (2 * a);
        imagPart = sqrt(-discriminant) / (2 * a);
        printf("Roots are complex and distinct.\n");
        printf("root1 = %.2lf + %.2lfi\n", realPart, imagPart);
        printf("root2 = %.2lf - %.2lfi\n", realPart, imagPart);
    }

    return 0;
}
