#include <stdio.h>
#include <string.h>
#include "doctor.h"
#include "utility.h"
#include "patient.h"
#include "disease_info.h"

extern Doctor doctors[];
extern int doctorCount;
#define MAX_PATIENTS 100
#define MAX_DOCTORS 50



Patient patients[MAX_PATIENTS];
Doctor doctors[MAX_DOCTORS];
int patientCount = 0;
int doctorCount = 0;



void registerDoctor() {
    if (doctorCount >= MAX_DOCTORS) {
        printf("Maximum doctor limit reached.\n");
        return;
    }
    Doctor d;
    d.id = doctorCount + 1;

    // Name validation
    do {
        printf("Enter doctor name (letters and spaces only): ");
        scanf(" %[^\n]", d.name);
        if (!isValidName(d.name)) {
            printf("Invalid name. No special characters or numbers allowed.\n");
        }
    } while (!isValidName(d.name));

    // Specialization input
    printf("Enter specialization: ");
    scanf(" %[^\n]", d.specialization);

    // Password input
    printf("Enter password: ");
    scanf("%s", d.password);

    doctors[doctorCount++] = d;
    printf("Doctor registered successfully with ID: %d\n", d.id);
}

void searchDoctor() {
    int id;
    printf("Enter doctor ID to search: ");
    scanf("%d", &id);
    if (id < 1 || id > doctorCount) {
        printf("Doctor not found.\n");
    } else {
        Doctor d = doctors[id - 1];
        printf("\nDoctor ID: %d\n", d.id);
        printf("Name: %s\n", d.name);
        printf("Specialization: %s\n", d.specialization);
    }
}
void editDoctorDetails() {
    int id;
    printf("Enter doctor ID to edit details: ");
    scanf("%d", &id);
    if (id < 1 || id > doctorCount) {
        printf("Doctor not found.\n");
        return;
    }

    Doctor *d = &doctors[id - 1];
    int choice;
    do {
        printf("\nEditing Doctor ID: %d\n", d->id);
        printf("1. Name\n2. Specialization\n3. Password\n4. Exit\n");
        printf("Enter field to edit: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                do {
                    printf("Enter new name: ");
                    scanf(" %[^\n]", d->name);
                    if (!isValidName(d->name)) {
                        printf("Invalid name. Only letters and spaces allowed.\n");
                    }
                } while (!isValidName(d->name));
                break;
            case 2:
                printf("Enter new specialization: ");
                scanf(" %[^\n]", d->specialization);
                break;
            case 3:
                printf("Enter new password: ");
                scanf("%s", d->password);
                break;
            case 4:
                printf("Exiting edit mode.\n");
                return;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (1);
}


void doctorMenu() {
   int doctorID;
    char password[20];
    printf("Enter doctor ID: ");
    scanf("%d", &doctorID);
    if (doctorID < 1 || doctorID > doctorCount) {
        printf("Doctor not found.\n");
        return;
    }
    printf("Enter password: ");
    scanf("%s", password);

    if (strcmp(password, doctors[doctorID - 1].password) != 0) {
        printf("Incorrect password.\n");
        return;
    }

    int choice;
    while (1) {
        printf("\nDoctor Menu\n");
        printf("1. Display Patient\n");
        printf("2. Assign Disease to Patient\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter patient ID to display: ");
                scanf("%d", &choice);
                displayPatient(choice);
                break;
            case 2:
                printf("Enter patient ID to assign disease: ");
                scanf("%d", &choice);
                if (choice < 1 || choice > patientCount) {
                    printf("Patient not found.\n");
                    break;
                }
                // Assign disease to patient
                int diseaseChoice;
                printf("Select disease:\n");
                printf("1. Cold\n2. Fever\n3. Tuberculosis\n4. Malaria\n5. Dengue Fever\n6. Typhoid\n7. Hepatitis B\n8. Hepatitis C\n9. HIV/AIDS\n10. Diabetes\n11. Heart Disease\n12. Cancer\n");
                printf("Enter your choice: ");
                scanf("%d", &diseaseChoice);
                if (diseaseChoice < 1 || diseaseChoice > 12) {
                    printf("Invalid choice. Please select a valid disease.\n");
                    break;
                }
                // Update patient's disease
                displayDiseaseInfo(diseaseChoice);
                strcpy(patients[choice - 1].disease, "Disease information updated by doctor.");
                printf("Disease assigned to patient ID: %d\n", choice);
                break;
            case 3:
                return;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}
