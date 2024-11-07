#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


#define MAX_PATIENTS 100
#define MAX_DOCTORS 50

// Structs
typedef struct {
    int id;
    char name[100];
    int age;
    char gender[10];
    char contact[15];
    int isInpatient;
    char admissionDate[12];
    char dischargeDate[12];
    int doctorId;
    char disease[100];
} Patient;

typedef struct {
    int id;
    char name[100];
    char specialization[50];
} Doctor;

// Arrays and Counters
Patient patients[MAX_PATIENTS];
Doctor doctors[MAX_DOCTORS];
int patientCount = 0;
int doctorCount = 0;

// Function Prototypes
void clearBuffer();
int isValidContact(const char *contact);
int isValidDate(char *date);
void displayDiseaseInfo(int diseaseChoice);
void registerPatient();
void registerDoctor();
void displayPatient(int id);
void editPatientDisease();
void searchPatient();
void searchDoctor();
void doctorMenu();
void receptionistMenu();
void patientMenu();

// Main function
int main() {
    int choice;
    while (1) {
        printf("\nMain Menu\n");
        printf("1. Receptionist\n");
        printf("2. Doctor\n");
        printf("3. Patient\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clearBuffer();
        switch (choice) {
            case 1:
                receptionistMenu();
                break;
            case 2:
                doctorMenu();
                break;
            case 3:
                patientMenu();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

// Function to clear input buffer
void clearBuffer() {
    while (getchar() != '\n');
}

// Function to validate contact number (10 digits only)
int isValidContact(const char *contact) {
    if (strlen(contact) != 10) return 0;
    for (int i = 0; i < 10; i++) {
        if (!isdigit(contact[i])) {
            return 0;
        }
    }
    return 1;
}

// Function to validate the date format (dd/mm/yyyy) and year range (2024)
int isValidDate(char *date) {
    int day, month, year;
    sscanf(date, "%d/%d/%d", &day, &month, &year);
    if (year != 2024 || month < 1 || month > 12 || day < 1 || day > 31) {
        return 0;
    }
    return 1;
}

// Function to validate name (only alphabets and spaces)
int isValidName(const char *name) {
    for (int i = 0; i < strlen(name); i++) {
        if (!isalpha(name[i]) && name[i] != ' ') {
            return 0;
        }
    }
    return 1;
}

// Function to display disease information (symptoms, medication, and diet plan)
void displayDiseaseInfo(int diseaseChoice) {
    switch (diseaseChoice) {
        case 1: // Fever
            printf("\nFever Symptoms: High temperature, chills, body aches.\n");
            printf("Medications: Paracetamol (Morning, Afternoon, Night)\n");
            printf("Diet Plan: Hydrate well, light food.\n");
            break;
        case 2: // Cold
            printf("\nCold Symptoms: Runny nose, sore throat, cough.\n");
            printf("Medications: Cough syrup (Morning, Night), Paracetamol (Afternoon)\n");
            printf("Diet Plan: Warm fluids, rest.\n");
            break;
        // Add more diseases here...
        default:
            printf("Disease not found.\n");
            break;
    }
}

// Function to register a new patient
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

    // Inpatient check and date validation
    printf("Is the patient an incoming patient? (1 for Yes, 0 for No): ");
    scanf("%d", &p.isInpatient);
    if (p.isInpatient) {
        do {
            printf("Enter admission date (dd/mm/yyyy): ");
            scanf("%s", p.admissionDate);
            if (!isValidDate(p.admissionDate)) {
                printf("Invalid date format. Enter in dd/mm/yyyy format.\n");
            }
        } while (!isValidDate(p.admissionDate));

        do {
            printf("Enter discharge date (dd/mm/yyyy): ");
            scanf("%s", p.dischargeDate);
            if (!isValidDate(p.dischargeDate)) {
                printf("Invalid date format. Enter in dd/mm/yyyy format.\n");
            }
        } while (!isValidDate(p.dischargeDate));
    }

    printf("Enter assigned doctor ID: ");
    scanf("%d", &p.doctorId);

    patients[patientCount++] = p;
    printf("Patient registered successfully with ID %d\n", p.id);
}

// Function to register a new doctor
void registerDoctor() {
    if (doctorCount >= MAX_DOCTORS) {
        printf("Maximum doctor limit reached.\n");
        return;
    }
    Doctor d;
    d.id = doctorCount + 1;
    printf("Enter doctor name: ");
    scanf(" %[^\n]", d.name);
    printf("Enter doctor specialization: ");
    scanf("%s", d.specialization);
    doctors[doctorCount++] = d;
    printf("Doctor registered successfully with ID %d\n", d.id);
}

// Function to display patient details
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
    printf("Disease: %s\n", p.disease[0] ? p.disease : "None");
}

// Function to edit only disease details of a patient by assigned doctor
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

// Search functions
void searchPatient() {
    int id;
    printf("Enter patient ID to search: ");
    scanf("%d", &id);
    displayPatient(id);
}

void searchDoctor() {
    int id;
    printf("Enter doctor ID to search: ");
    scanf("%d", &id);
    if (id < 1 || id > doctorCount) {
        printf("Doctor not found.\n");
        return;
    }
    printf("\nDoctor ID: %d\n", doctors[id - 1].id);
    printf("Name: %s\n", doctors[id - 1].name);
    printf("Specialization: %s\n", doctors[id - 1].specialization);
}

// Menu functions
void receptionistMenu() {
    int choice;
    do {
        printf("\nReceptionist Menu\n");
        printf("1. Register Patient\n");
        printf("2. Register Doctor\n");
        printf("3. Search Patient\n");
        printf("4. Search Doctor\n");
        printf("5. Go to Main Menu\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clearBuffer();
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
                return;
            case 6:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);
}

void doctorMenu() {
    int choice;
    do {
        printf("\nDoctor Menu\n");
        printf("1. Edit Patient Disease Information\n");
        printf("2. Search Patient\n");
        printf("3. Go to Main Menu\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clearBuffer();
        switch (choice) {
            case 1:
                editPatientDisease();
                break;
            case 2:
                searchPatient();
                break;
            case 3:
                return;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);
}

void patientMenu() {
    printf("\nPatient Menu\n");
    printf("Please contact the receptionist for assistance.\n");
}
