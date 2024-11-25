#include <stdio.h>
#include <string.h>
#include "patient.h"
#include "utility.h"
#include "disease_info.h"

#define MAX_PATIENTS 100

extern Patient patients[];
extern int patientCount;

void registerPatient() {
    if (patientCount >= MAX_PATIENTS) {
        printf("Maximum patient limit reached.\n");
        return;
    }
    Patient p;
    p.id = patientCount + 1;

    // Name validation
    do {
        printf("Enter patient name (letters and spaces only): ");
        scanf(" %[^\n]", p.name);
        if (!isValidName(p.name)) {
            printf("Invalid name. No special characters or numbers allowed.\n");
        }
    } while (!isValidName(p.name));

    // Age validation
    do {
        printf("Enter patient age (1-99): ");
        scanf("%d", &p.age);
        if (p.age <= 0 || p.age >= 100) {
            printf("Invalid age. Enter a value between 1 and 99.\n");
        }
    } while (p.age <= 0 || p.age >= 100);

    // Gender selection
    int genderChoice;
    do {
        printf("Select gender: 1. Male  2. Female  3. Other\n");
        printf("Enter your choice: ");
        scanf("%d", &genderChoice);
        switch (genderChoice) {
            case 1:
                strcpy(p.gender, "Male");
                break;
            case 2:
                strcpy(p.gender, "Female");
                break;
            case 3:
                strcpy(p.gender, "Other");
                break;
            default:
                printf("Invalid choice. Please select 1, 2, or 3.\n");
        }
    } while (genderChoice < 1 || genderChoice > 3);

    // Validate contact number
    do {
        printf("Enter contact information (10 digits): ");
        scanf("%s", p.contact);
        if (!isValidContact(p.contact)) {
            printf("Invalid contact. Please enter a 10-digit number.\n");
        }
    } while (!isValidContact(p.contact));

    // Disease selection only if patient is not inpatient
    int diseaseChoice = 0;
    char admissionStatus;
    do {
        printf("Is the patient an inpatient? (y/n): ");
        scanf(" %c", &admissionStatus);
        if (admissionStatus == 'y' || admissionStatus == 'Y') {
            p.isInpatient = 1;
            printf("Enter admission date (dd/mm/yyyy): ");
            scanf("%s", p.admissionDate);
            while (!isValidDate(p.admissionDate)) {
                printf("Invalid date. Please enter a valid admission date (dd/mm/yyyy): ");
                scanf("%s", p.admissionDate);
            }
            printf("Enter discharge date (dd/mm/yyyy): ");
            scanf("%s", p.dischargeDate);
            while (!isValidDate(p.dischargeDate)) {
                printf("Invalid date. Please enter a valid discharge date (dd/mm/yyyy): ");
                scanf("%s", p.dischargeDate);
            }
        } else {
            p.isInpatient = 0;
        }
    } while (admissionStatus != 'y' && admissionStatus != 'n' && admissionStatus != 'Y' && admissionStatus != 'N');

    // Skip disease selection for inpatients
    if (p.isInpatient == 0) {
        // Disease selection (only for outpatient)
        do {
            printf("Select disease:\n");
            printf("1. Cold\n2. Fever\n3. Tuberculosis\n4. Malaria\n5. Dengue Fever\n6. Typhoid\n7. Hepatitis B\n8. Hepatitis C\n9. HIV/AIDS\n10. Diabetes\n11. Heart Disease\n12. Cancer\n");
            printf("Enter your choice: ");
            scanf("%d", &diseaseChoice);
            if (diseaseChoice < 1 || diseaseChoice > 12) {
                printf("Invalid choice. Please select a valid disease.\n");
            }
        } while (diseaseChoice < 1 || diseaseChoice > 12);

        displayDiseaseInfo(diseaseChoice);  // Display disease info based on selection
        strcpy(p.disease, "Disease information added.");
    }

    // Register patient
    patients[patientCount++] = p;
    printf("Patient registered successfully with ID: %d\n", p.id);
}


void displayPatient(int id) {
    if (id < 1 || id > patientCount) {
        printf("Patient not found.\n");
        return;
    }
    Patient p = patients[id - 1];
    printf("\nPatient ID: %d\n", p.id);
    printf("Name: %s\n", p.name);
    printf("Age: %d\n", p.age);
    printf("Gender: %s\n", p.gender);
    printf("Contact: %s\n", p.contact);
    printf("Inpatient: %s\n", p.isInpatient ? "Yes" : "No");
    if (p.isInpatient) {
        printf("Admission Date: %s\n", p.admissionDate);
        printf("Discharge Date: %s\n", p.dischargeDate);
    }
    printf("Disease: %s\n", p.disease);
}

void editPatientDetails() {
    int id;
    printf("Enter patient ID to edit details: ");
    scanf("%d", &id);
    if (id < 1 || id > patientCount) {
        printf("Patient not found.\n");
        return;
    }

    Patient *p = &patients[id - 1];
    int choice;
    do {
        printf("\nEditing Patient ID: %d\n", p->id);
        printf("1. Name\n2. Age\n3. Gender\n4. Contact\n5. Admission/Discharge Dates\n6. Exit\n");
        printf("Enter field to edit: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                do {
                    printf("Enter new name: ");
                    scanf(" %[^\n]", p->name);
                    if (!isValidName(p->name)) {
                        printf("Invalid name. Only letters and spaces allowed.\n");
                    }
                } while (!isValidName(p->name));
                break;
            case 2:
                do {
                    printf("Enter new age: ");
                    scanf("%d", &p->age);
                    if (p->age <= 0 || p->age >= 100) {
                        printf("Invalid age. Please enter a value between 1 and 99.\n");
                    }
                } while (p->age <= 0 || p->age >= 100);
                break;
            case 3:
                printf("Select new gender: 1. Male  2. Female  3. Other\n");
                int genderChoice;
                do {
                    printf("Enter your choice: ");
                    scanf("%d", &genderChoice);
                    switch (genderChoice) {
                        case 1:
                            strcpy(p->gender, "Male");
                            break;
                        case 2:
                            strcpy(p->gender, "Female");
                            break;
                        case 3:
                            strcpy(p->gender, "Other");
                            break;
                        default:
                            printf("Invalid choice. Please select 1, 2, or 3.\n");
                    }
                } while (genderChoice < 1 || genderChoice > 3);
                break;
            case 4:
                do {
                    printf("Enter new contact number (10 digits): ");
                    scanf("%s", p->contact);
                    if (!isValidContact(p->contact)) {
                        printf("Invalid contact. Please enter a valid 10-digit number.\n");
                    }
                } while (!isValidContact(p->contact));
                break;
            case 5:
                if (p->isInpatient) {
                    printf("Enter new admission date (dd/mm/yyyy): ");
                    scanf("%s", p->admissionDate);
                    while (!isValidDate(p->admissionDate)) {
                        printf("Invalid date. Please enter a valid admission date (dd/mm/yyyy): ");
                        scanf("%s", p->admissionDate);
                    }
                    printf("Enter new discharge date (dd/mm/yyyy): ");
                    scanf("%s", p->dischargeDate);
                    while (!isValidDate(p->dischargeDate)) {
                        printf("Invalid date. Please enter a valid discharge date (dd/mm/yyyy): ");
                        scanf("%s", p->dischargeDate);
                    }
                } else {
                    printf("Patient is not an inpatient.\n");
                }
                break;
            case 6:
                printf("Exiting edit mode.\n");
                return;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (1);
}



void editPatientDisease() {
    int id;
    printf("Enter patient ID to edit disease details: ");
    scanf("%d", &id);
    if (id < 1 || id > patientCount) {
        printf("Patient not found.\n");
        return;
    }

    printf("Enter new disease information: ");
    scanf(" %[^\n]", patients[id - 1].disease);
    printf("Disease information updated.\n");
}

void searchPatient(){
    int id;
    printf("Enter patient ID to search: ");
    scanf("%d", &id);
    displayPatient(id);
}

void patientMenu() {
// Function for patient menu
    
    int choice, patientId;

    printf("\nPatient Menu\n");
    printf("1. View My Details\n");
    printf("2. View Disease Information\n");
    printf("3. Exit\n");

    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // View patient details
                printf("Enter your Patient ID: ");
                scanf("%d", &patientId);
                displayPatient(patientId);
                break;

            case 2:
                // View disease information
                printf("Enter the disease number 1. Cold\n2. Fever\n3. Tuberculosis\n4. Malaria\n5. Dengue Fever\n6. Typhoid\n7. Hepatitis B\n8. Hepatitis C\n9. HIV/AIDS\n10. Diabetes\n11. Heart Disease\n12. Cancer\n to view details: ");
                int diseaseChoice;
                scanf("%d", &diseaseChoice);
                displayDiseaseInfo(diseaseChoice);
                break;

            case 3:
                // Exit the patient menu
                printf("Exiting Patient Menu.\n");
                return;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}