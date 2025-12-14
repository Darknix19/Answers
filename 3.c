/*3. In a cinema management system, a single cinema building has multiple screens, and each
screen shows several movies in a single day. The number of movies playing on each
screen is not fixed, so the system uses dynamic memory allocation to store movie titles
efficiently. A structure is used for each screen, which contains the screen name, the
number of movies it is showing, and a double pointer (char **movies) for storing all
movie names dynamically. If a customer wants to find whether a particular movie is
being shown in the cinema today, a recursive function is used to search movie titles
screen by screen. The base case occurs when all screens have been checked and still the
movie has not been found, or when all movies on the current screen have been checked
and then the search moves to the next screen. If a match is found at any time, the
recursion stops and returns that the movie is available. This approach makes the cinema
system scalable and flexible, allowing the addition or removal of screens and movies at
runtime without wasting memory.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char screenName[50];
    int movieCount;
    char **movies;
} Screen;

int searchMovie(Screen *s, int totalScreens, int screenIndex, int movieIndex, char *target) {
    if (screenIndex == totalScreens)
        return 0;

    if (movieIndex == s[screenIndex].movieCount)
        return searchMovie(s, totalScreens, screenIndex + 1, 0, target);

    if (strcmp(s[screenIndex].movies[movieIndex], target) == 0)
        return 1;

    return searchMovie(s, totalScreens, screenIndex, movieIndex + 1, target);
}

int main() {
    int n;
    printf("Enter number of screens: ");
    scanf("%d", &n);
    getchar();

    Screen *s = (Screen *)malloc(n * sizeof(Screen));

    for (int i = 0; i < n; i++) {
        printf("Enter screen name: ");
        fgets(s[i].screenName, sizeof(s[i].screenName), stdin);
        s[i].screenName[strcspn(s[i].screenName, "\n")] = '\0';

        printf("Enter number of movies: ");
        scanf("%d", &s[i].movieCount);
        getchar();

        s[i].movies = (char **)malloc(s[i].movieCount * sizeof(char *));
        for (int j = 0; j < s[i].movieCount; j++) {
            char temp[200];
            printf("Enter movie %d: ", j + 1);
            fgets(temp, sizeof(temp), stdin);
            temp[strcspn(temp, "\n")] = '\0';

            s[i].movies[j] = (char *)malloc(strlen(temp) + 1);
            strcpy(s[i].movies[j], temp);
        }
    }

    char target[200];
    printf("\nEnter movie to search: ");
    fgets(target, sizeof(target), stdin);
    target[strcspn(target, "\n")] = '\0';

    if (searchMovie(s, n, 0, 0, target))
        printf("Movie FOUND\n");
    else
        printf("Movie NOT FOUND\n");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < s[i].movieCount; j++)
            free(s[i].movies[j]);
        free(s[i].movies);
    }
    free(s);

    return 0;
}
