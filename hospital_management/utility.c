#include <stdio.h>
#include <ctype.h>
#include <string.h>

void clearBuffer() {
    while (getchar() != '\n');
}

int isValidContact(const char *contact) {
    if (strlen(contact) != 10) return 0;
    for (int i = 0; i < 10; i++) {
        if (!isdigit(contact[i])) return 0;
    }
    return 1;
}

int isValidDate(char *date) {
    int day, month, year;
    sscanf(date, "%d/%d/%d", &day, &month, &year);
    if (year != 2024 || month < 1 || month > 12 || day < 1 || day > 31) return 0;
    return 1;
}

int isValidName(const char *name) {
    for (int i = 0; i < strlen(name); i++) {
        if (!isalpha(name[i]) && name[i] != ' ') return 0;
    }
    return 1;
}
