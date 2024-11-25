#include <stdio.h>
#include <string.h>
#include "utility.h"
#include "patient.h"
#include "doctor.h"
#include "receptionist.h"


int main() {
    int choice;
    char receptionistPassword[20];

    while (1) {
        printf("\nMain Menu\n");
        printf("1. Receptionist\n");
        printf("2. Doctor\n");
        printf("3. Patient\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
    

        switch (choice) {
            case 1:
                printf("Enter receptionist password: ");
                scanf("%s", receptionistPassword);
                if (strcmp(receptionistPassword, "iitj") == 0) {
                    receptionistMenu();
                } else {
                    printf("Incorrect password.\n");
                }
                break;
            case 2:
                doctorMenu();
                break;
            case 3:
                printf("Patient menu is under development.\n");
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}
