#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PATIENTS 100
#define MAX_DOCTORS 50

typedef struct {
    int id;
    char name[100];
    int age;
    char gender[10];
    char contact[15];
    int isInpatient;  // 1 for inpatient, 0 for outpatient
    char admissionDate[12];
    char dischargeDate[12];
    int doctorId;
} Patient;

typedef struct {
    int id;
    char name[100];
    char specialization[50];
} Doctor;

Patient patients[MAX_PATIENTS];
Doctor doctors[MAX_DOCTORS];
int patientCount = 0;
int doctorCount = 0;

// Utility function to check if a string is a valid integer
int isValidInteger(const char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isdigit(str[i])) return 0;
    }
    return 1;
}

// Utility function to check if a string contains only letters and spaces
int isValidName(const char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isalpha(str[i]) && str[i] != ' ') return 0;
    }
    return 1;
}

// Function to register a patient with input validation
void registerPatient() {
    if (patientCount >= MAX_PATIENTS) {
        printf("Maximum patient limit reached.\n");
        return;
    }
    Patient p;
    p.id = patientCount + 1;

    // Get patient name with validation
    while (1) {
        printf("Enter patient name: ");
        scanf(" %[^\n]", p.name);
        if (isValidName(p.name)) break;
        else printf("Invalid name. Only letters and spaces are allowed.\n");
    }

    // Get patient age with validation
    char ageStr[10];
    while (1) {
        printf("Enter patient age: ");
        scanf("%s", ageStr);
        if (isValidInteger(ageStr)) {
            p.age = atoi(ageStr);
            break;
        } else {
            printf("Invalid age. Please enter a valid integer.\n");
        }
    }

    // Get patient gender with validation
    while (1) {
        printf("Enter patient gender (Male/Female): ");
        scanf("%s", p.gender);
        if (strcmp(p.gender, "Male") == 0 || strcmp(p.gender, "Female") == 0) break;
        else printf("Invalid input. Please enter 'Male' or 'Female'.\n");
    }

    // Get contact information
    printf("Enter contact information: ");
    scanf("%s", p.contact);

    // Get inpatient status with validation
    while (1) {
        printf("Is the patient an inpatient? (1 for Yes, 0 for No): ");
        scanf("%d", &p.isInpatient);
        if (p.isInpatient == 1 || p.isInpatient == 0) break;
        else printf("Invalid input. Please enter 1 for Yes or 0 for No.\n");
    }

    // Get admission and discharge dates if inpatient
    if (p.isInpatient) {
        printf("Enter admission date (dd/mm/yyyy): ");
        scanf("%s", p.admissionDate);
        printf("Enter discharge date (dd/mm/yyyy): ");
        scanf("%s", p.dischargeDate);
    }

    // Get assigned doctor ID with validation
    char doctorIdStr[10];
    while (1) {
        printf("Enter assigned doctor ID: ");
        scanf("%s", doctorIdStr);
        if (isValidInteger(doctorIdStr)) {
            p.doctorId = atoi(doctorIdStr);
            break;
        } else {
            printf("Invalid doctor ID. Please enter a valid integer.\n");
        }
    }

    patients[patientCount++] = p;
    printf("Patient registered successfully with ID %d\n", p.id);
}

// Function to register a doctor with input validation
void registerDoctor() {
    if (doctorCount >= MAX_DOCTORS) {
        printf("Maximum doctor limit reached.\n");
        return;
    }
    Doctor d;
    d.id = doctorCount + 1;

    // Get doctor name with validation
    while (1) {
        printf("Enter doctor name: ");
        scanf(" %[^\n]", d.name);
        if (isValidName(d.name)) break;
        else printf("Invalid name. Only letters and spaces are allowed.\n");
    }

    // Get doctor specialization
    printf("Enter doctor specialization: ");
    scanf(" %[^\n]", d.specialization);

    doctors[doctorCount++] = d;
    printf("Doctor registered successfully with ID %d\n", d.id);
}

// Function to display a patient's details
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
    if (p.isInpatient) {
        printf("Patient Type: Inpatient\n");
        printf("Admission Date: %s\n", p.admissionDate);
        printf("Discharge Date: %s\n", p.dischargeDate);
    } else {
        printf("Patient Type: Outpatient\n");
    }
    if (p.doctorId > 0 && p.doctorId <= doctorCount) {
        printf("Assigned Doctor: %s\n", doctors[p.doctorId - 1].name);
    } else {
        printf("No doctor assigned.\n");
    }
}

// Function to search for a patient by ID
void searchPatient() {
    int id;
    printf("Enter patient ID to search: ");
    scanf("%d", &id);
    displayPatient(id);
}

// Function to search for a doctor by ID
void searchDoctor() {
    int id;
    printf("Enter doctor ID to search: ");
    scanf("%d", &id);
    if (id < 1 || id > doctorCount) {
        printf("Doctor not found.\n");
        return;
    }
    Doctor d = doctors[id - 1];
    printf("\nDoctor ID: %d\n", d.id);
    printf("Name: %s\n", d.name);
    printf("Specialization: %s\n", d.specialization);
}

// Main function
int main() {
    int choice;
    while (1) {
        printf("\nHospital Management System\n");
        printf("1. Register Patient\n");
        printf("2. Register Doctor\n");
        printf("3. Search Patient\n");
        printf("4. Search Doctor\n");
        printf("5. Exit\n");
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
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}
