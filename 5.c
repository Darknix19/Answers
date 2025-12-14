/*5. A gaming company is experimenting with different methods to compute score
multipliers when a player levels up. The menu must show three methods: (1) Recursive
multiplier, (2) Loop-based multiplier using pointer for output, and (3) Function pointer to
switch between both dynamically. A player’s base score and level multiplier are entered
by the user. Menu repeats until Exit
*/

#include <stdio.h>
#include <stdlib.h>

double recursiveMultiplier(double base, double mult, int level) {
    if (level == 0)
        return base;
    return recursiveMultiplier(base * mult, mult, level - 1);
}

void loopMultiplier(double base, double mult, int level, double *result) {
    for (int i = 0; i < level; i++)
        base = base * mult;
    *result = base;
}

double callFP(double (*fp)(double, double, int), double base, double mult, int level) {
    return fp(base, mult, level);
}

double wrapper(double base, double mult, int level) {
    return recursiveMultiplier(base, mult, level);
}

int main() {
    int choice, level;
    double base, mult, result;

    while (1) {
        printf("\n1. Recursive Multiplier\n");
        printf("2. Loop Multiplier (Pointer Output)\n");
        printf("3. Function Pointer Call\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 4)
            break;

        printf("Enter base score: ");
        scanf("%lf", &base);
        printf("Enter level multiplier: ");
        scanf("%lf", &mult);
        printf("Enter number of levels: ");
        scanf("%d", &level);

        if (choice == 1) {
            result = recursiveMultiplier(base, mult, level);
            printf("Final Score: %.2lf\n", result);
        }

        else if (choice == 2) {
            loopMultiplier(base, mult, level, &result);
            printf("Final Score: %.2lf\n", result);
        }

        else if (choice == 3) {
            double (*fp)(double, double, int) = wrapper;
            result = callFP(fp, base, mult, level);
            printf("Final Score (Function Pointer): %.2lf\n", result);
        }
    }

    return 0;
}
