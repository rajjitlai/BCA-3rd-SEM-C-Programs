#include <stdio.h>
#include <conio.h>

int main() {
    char set[] = "#C programming $cool";
    char search;
    int loc = 0;
    int pos = -1;

    printf("Enter a character to be searched: ");
    scanf(" %c", &search);

    for (int i = 0; set[i] != '\0'; i++) {
        if (set[i] == search) {
            loc = 1;
            pos = i;
            break;
        }
    }

    if (loc) {
        printf("Character %c is found in the set at pos %d", search, pos);
    } else {
        printf("Character %c is not found in the set", search);
    }

    return 0;
}
