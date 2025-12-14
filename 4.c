/*4. A bank wants to test three different algorithms to compute compound interest on user
savings. The system displays a menu with: (1) Recursive interest calculation, (2) Iterative
calculation storing final balance using a pointer, and (3) calling both functions through a
single function pointer to test consistency. Users enter principal, interest rate, and
number of years. The menu runs repeatedly until Exit is selected.*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double recursiveCI(double p, double r, int y) {
    if (y == 0)
        return p;
    return recursiveCI(p * (1 + r), r, y - 1);
}

void iterativeCI(double p, double r, int y, double *result) {
    for (int i = 0; i < y; i++)
        p = p * (1 + r);
    *result = p;
}

double callThroughPointer(double (*fp)(double, double, int), double p, double r, int y) {
    return fp(p, r, y);
}

double wrapperRecursive(double p, double r, int y) {
    return recursiveCI(p, r, y);
}

int main() {
    int choice;
    double p, r, result;
    int y;

    while (1) {
        printf("\n1. Recursive Calculation\n");
        printf("2. Iterative Calculation (Pointer)\n");
        printf("3. Function Pointer Test\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 4)
            break;

        printf("Enter principal: ");
        scanf("%lf", &p);
        printf("Enter interest rate (e.g., 0.05): ");
        scanf("%lf", &r);
        printf("Enter years: ");
        scanf("%d", &y);

        if (choice == 1) {
            result = recursiveCI(p, r, y);
            printf("Final Amount: %.2lf\n", result);
        }

        else if (choice == 2) {
            iterativeCI(p, r, y, &result);
            printf("Final Amount: %.2lf\n", result);
        }

        else if (choice == 3) {
            double (*fp)(double, double, int) = wrapperRecursive;
            result = callThroughPointer(fp, p, r, y);
            printf("Final Amount (Function Pointer): %.2lf\n", result);
        }
    }

    return 0;
}
