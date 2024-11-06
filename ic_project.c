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

Patient patients[MAX_PATIENTS];
Doctor doctors[MAX_DOCTORS];
int patientCount = 0;
int doctorCount = 0;

void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int isValidInteger(const char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isdigit(str[i])) return 0;
    }
    return 1;
}

int isValidName(const char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isalpha(str[i]) && str[i] != ' ') return 0;
    }
    return 1;
}

int isValidDate(const char *date) {
    int day, month, year;
    if (sscanf(date, "%d/%d/%d", &day, &month, &year) != 3) return 0;
    if (year < 2024 || year > 2025 || month < 1 || month > 12 || day < 1 || day > 31) return 0;
    return 1;
}

void registerPatient() {
    if (patientCount >= MAX_PATIENTS) {
        printf("Maximum patient limit reached.\n");
        return;
    }
    Patient p;
    p.id = patientCount + 1;

    while (1) {
        printf("Enter patient name: ");
        scanf(" %[^\n]", p.name);
        if (isValidName(p.name)) break;
        else printf("Invalid name. Only letters and spaces are allowed.\n");
    }

    char ageStr[10];
    while (1) {
        printf("Enter patient age: ");
        scanf("%s", ageStr);
        if (isValidInteger(ageStr)) {
            p.age = atoi(ageStr);
            break;
        } else {
            printf("Invalid age. Please enter a valid integer.\n");
            clearBuffer();
        }
    }

    while (1) {
        printf("Enter patient gender (Male/Female): ");
        scanf("%s", p.gender);
        if (strcmp(p.gender, "Male") == 0 || strcmp(p.gender, "Female") == 0) break;
        else printf("Invalid input. Please enter 'Male' or 'Female'.\n");
        clearBuffer();
    }

    printf("Enter contact information: ");
    scanf("%s", p.contact);

    while (1) {
        printf("Is the patient an inpatient? (1 for Yes, 0 for No): ");
        scanf("%d", &p.isInpatient);
        if (p.isInpatient == 1 || p.isInpatient == 0) break;
        else printf("Invalid input. Please enter 1 for Yes or 0 for No.\n");
        clearBuffer();
    }

    if (p.isInpatient) {
        while (1) {
            printf("Enter admission date (dd/mm/yyyy): ");
            scanf("%s", p.admissionDate);
            if (isValidDate(p.admissionDate)) break;
            else printf("Invalid date. Please enter a valid date between 2024 and 2025.\n");
        }

        while (1) {
            printf("Enter discharge date (dd/mm/yyyy): ");
            scanf("%s", p.dischargeDate);
            if (isValidDate(p.dischargeDate)) break;
            else printf("Invalid date. Please enter a valid date between 2024 and 2025.\n");
        }
    }

    char doctorIdStr[10];
    while (1) {
        printf("Enter assigned doctor ID: ");
        scanf("%s", doctorIdStr);
        if (isValidInteger(doctorIdStr)) {
            p.doctorId = atoi(doctorIdStr);
            break;
        } else {
            printf("Invalid doctor ID. Please enter a valid integer.\n");
            clearBuffer();
        }
    }

    patients[patientCount++] = p;
    printf("Patient registered successfully with ID %d\n", p.id);
}

void registerDoctor() {
    if (doctorCount >= MAX_DOCTORS) {
        printf("Maximum doctor limit reached.\n");
        return;
    }
    Doctor d;
    d.id = doctorCount + 1;

    while (1) {
        printf("Enter doctor name: ");
        scanf(" %[^\n]", d.name);
        if (isValidName(d.name)) break;
        else printf("Invalid name. Only letters and spaces are allowed.\n");
    }

    printf("Enter doctor specialization: ");
    scanf(" %[^\n]", d.specialization);

    doctors[doctorCount++] = d;
    printf("Doctor registered successfully with ID %d\n", d.id);
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
    if (p.isInpatient) {
        printf("Patient Type: Inpatient\n");
        printf("Admission Date: %s\n", p.admissionDate);
        printf("Discharge Date: %s\n", p.dischargeDate);
    } else {
        printf("Patient Type: Outpatient\n");
    }
    printf("Disease: %s\n", p.disease[0] ? p.disease : "No disease information available.");
    if (p.doctorId > 0 && p.doctorId <= doctorCount) {
        printf("Assigned Doctor: %s\n", doctors[p.doctorId - 1].name);
    } else {
        printf("No doctor assigned.\n");
    }
}

void displayDoctor(int id) {
    if (id < 1 || id > doctorCount) {
        printf("Doctor not found.\n");
        return;
    }
    Doctor d = doctors[id - 1];
    printf("\nDoctor ID: %d\n", d.id);
    printf("Name: %s\n", d.name);
    printf("Specialization: %s\n", d.specialization);
}

void editPatientDetails() {
    int id;
    printf("Enter Patient ID to edit: ");
    scanf("%d", &id);
    clearBuffer();

    if (id < 1 || id > patientCount) {
        printf("Patient not found.\n");
        return;
    }
    Patient *p = &patients[id - 1];

    printf("Editing details for Patient ID %d\n", id);
    printf("Current name: %s\n", p->name);
    printf("Enter new name (leave blank to keep current): ");
    char name[100];
    fgets(name, sizeof(name), stdin);
    if (strcmp(name, "\n") != 0) {
        name[strcspn(name, "\n")] = 0;
        strcpy(p->name, name);
    }

    printf("Current age: %d\n", p->age);
    printf("Enter new age (or 0 to keep current): ");
    int age;
    scanf("%d", &age);
    if (age > 0) p->age = age;

    printf("Current contact: %s\n", p->contact);
    printf("Enter new contact (leave blank to keep current): ");
    clearBuffer();
    char contact[15];
    fgets(contact, sizeof(contact), stdin);
    if (strcmp(contact, "\n") != 0) {
        contact[strcspn(contact, "\n")] = 0;
        strcpy(p->contact, contact);
    }

    printf("Details updated successfully.\n");
}

void editDoctorDetails() {
    int id;
    printf("Enter Doctor ID to edit: ");
    scanf("%d", &id);
    clearBuffer();

    if (id < 1 || id > doctorCount) {
        printf("Doctor not found.\n");
        return;
    }
    Doctor *d = &doctors[id - 1];

    printf("Editing details for Doctor ID %d\n", id);
    printf("Current name: %s\n", d->name);
    printf("Enter new name (leave blank to keep current): ");
    char name[100];
    fgets(name, sizeof(name), stdin);
    if (strcmp(name, "\n") != 0) {
        name[strcspn(name, "\n")] = 0;
        strcpy(d->name, name);
    }

    printf("Current specialization: %s\n", d->specialization);
    printf("Enter new specialization (leave blank to keep current): ");
    char specialization[50];
    fgets(specialization, sizeof(specialization), stdin);
    if (strcmp(specialization, "\n") != 0) {
        specialization[strcspn(specialization, "\n")] = 0;
        strcpy(d->specialization, specialization);
    }

    printf("Details updated successfully.\n");
}

void receptionistMenu() {
    int choice, id;
    while (1) {
        printf("\nReceptionist Menu\n");
        printf("1. Register Patient\n");
        printf("2. Register Doctor\n");
        printf("3. Search Patient\n");
        printf("4. Search Doctor\n");
        printf("5. Edit Patient Details\n");
        printf("6. Edit Doctor Details\n");
        printf("7. Exit to Main Menu\n");
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
                printf("Enter Patient ID to search: ");
                scanf("%d", &id);
                displayPatient(id);
                break;
            case 4:
                printf("Enter Doctor ID to search: ");
                scanf("%d", &id);
                displayDoctor(id);
                break;
            case 5:
                editPatientDetails();
                break;
            case 6:
                editDoctorDetails();
                break;
            case 7:
                return;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

void doctorMenu() {
    int doctorId, patientId;
    printf("Enter your Doctor ID: ");
    scanf("%d", &doctorId);
    printf("Enter Patient ID to add disease information: ");
    scanf("%d", &patientId);
    clearBuffer();
    printf("Enter disease details for patient ID %d: ", patientId);
    scanf(" %[^\n]", patients[patientId - 1].disease);
    printf("Disease information added successfully.\n");
}

void patientMenu() {
    int id;
    printf("Enter your Patient ID: ");
    scanf("%d", &id);
    clearBuffer();
    displayPatient(id);
}

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
