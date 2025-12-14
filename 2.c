/*2. In a banking management system, every bank has multiple branches, and each branch
offers a different set of services such as ATM services, Pay Orders, and Locker facilities.
The number of services offered by each branch is not fixed, so dynamic memory
allocation is used to store this information. A structure is created for each branch, which
contains the branch name, the number of services it offers, and a double pointer (char
**services) to store the list of service names dynamically. Since customers may need to
know whether a specific facility like Locker Service is available in any branch, a
recursive function is used to search through all branches and their services one by one.
The base case of recursion occurs when all branches have been checked or when all
services inside a branch have been compared and still the locker service is not found. If
the service matches, the recursion stops and confirms availability. This dynamic and
recursive approach helps banks manage services efficiently without wasting memory,
while making the system flexible to future changes such as adding or removing branches
and services.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n;
    char **names;

    printf("Enter number of students: ");
    scanf("%d", &n);

    names = (char **)malloc(n * sizeof(char *));
    getchar();

    for (int i = 0; i < n; i++) {
        char temp[1000];
        printf("Enter name of student %d: ", i + 1);
        fgets(temp, sizeof(temp), stdin);
        temp[strcspn(temp, "\n")] = '\0';

        names[i] = (char *)malloc(strlen(temp) + 1);
        strcpy(names[i], temp);
    }

    printf("\nStored Student Names:\n");
    for (int i = 0; i < n; i++)
        printf("%s\n", names[i]);

    for (int i = 0; i < n; i++)
        free(names[i]);
    free(names);

    return 0;
}
