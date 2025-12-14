/*8. An airline booking system manages passenger names in a seating chart (rows × seats per
row). The names are stored in a double pointer to a 2D dynamically allocated array,
representing a real-time booking table. When a user books a seat, the system updates the
table using string functions. If the aircraft changes to a bigger or smaller model, memory
must be resized using realloc(), adjusting the number of rows dynamically. Passengers
can also search seats by name, and upon cancellation the memory for that seat is cleared.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **allocateSeats(int rows, int seatsPerRow) {
    char **table = (char **)malloc(rows * sizeof(char *));
    for (int i = 0; i < rows; i++)
        table[i] = (char *)calloc(seatsPerRow * 50, sizeof(char));
    return table;
}

char **resizeSeats(char **table, int oldRows, int newRows, int seatsPerRow) {
    table = (char **)realloc(table, newRows * sizeof(char *));
    if (newRows > oldRows) {
        for (int i = oldRows; i < newRows; i++)
            table[i] = (char *)calloc(seatsPerRow * 50, sizeof(char));
    }
    return table;
}

void bookSeat(char **table, int row, int seat, int seatsPerRow, char *name) {
    strcpy(table[row] + seat * 50, name);
}

void cancelSeat(char **table, int row, int seat, int seatsPerRow) {
    table[row][seat * 50] = '\0';
}

int searchPassenger(char **table, int rows, int seatsPerRow, char *name) {
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < seatsPerRow; j++)
            if (strcmp(table[i] + j * 50, name) == 0)
                return 1;
    return 0;
}

int main() {
    int rows = 3, seatsPerRow = 4;
    char **table = allocateSeats(rows, seatsPerRow);

    int choice;
    while (1) {
        printf("\n1. Book Seat\n");
        printf("2. Cancel Seat\n");
        printf("3. Search Passenger\n");
        printf("4. Resize Aircraft\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 5)
            break;

        if (choice == 1) {
            int r, s;
            char name[50];
            printf("Enter row: ");
            scanf("%d", &r);
            printf("Enter seat: ");
            scanf("%d", &s);
            printf("Enter passenger name: ");
            scanf("%s", name);
            bookSeat(table, r, s, seatsPerRow, name);
        }

        else if (choice == 2) {
            int r, s;
            printf("Enter row: ");
            scanf("%d", &r);
            printf("Enter seat: ");
            scanf("%d", &s);
            cancelSeat(table, r, s, seatsPerRow);
        }

        else if (choice == 3) {
            char name[50];
            printf("Enter name to search: ");
            scanf("%s", name);
            if (searchPassenger(table, rows, seatsPerRow, name))
                printf("Passenger FOUND\n");
            else
                printf("Passenger NOT FOUND\n");
        }

        else if (choice == 4) {
            int newRows;
            printf("Enter new number of rows: ");
            scanf("%d", &newRows);
            table = resizeSeats(table, rows, newRows, seatsPerRow);
            rows = newRows;
        }
    }

    for (int i = 0; i < rows; i++)
        free(table[i]);
    free(table);

    return 0;
}
