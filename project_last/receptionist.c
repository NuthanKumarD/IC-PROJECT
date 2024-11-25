#include <stdio.h>
#include "receptionist.h"
#include "patient.h"
#include "doctor.h"
#include <stdlib.h>

void receptionistMenu() {
    int choice;
    while (1) {
        printf("\nReceptionist Menu\n");
        printf("1. Register Patient\n");
        printf("2. Register Doctor\n");
        printf("3. Search Patient\n");
        printf("4. Search Doctor\n");
        printf("5. Edit Patient Details\n");
        printf("6. Edit Doctor Details\n");
        printf("7. Go to Main Menu\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                registerPatient();
                break;
            case 2:
                registerDoctor();
                break;
            case 3:
                searchPatient();
                break;
            case 4:
                searchDoctor();
                break;
            case 5:
                editPatientDetails();
                break;
            case 6:
                editDoctorDetails();
                break;
            case 7:
                return;
            case 8:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}
