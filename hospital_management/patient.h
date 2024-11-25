#ifndef PATIENT_H
#define PATIENT_H

typedef struct {
    int id;
    char name[100];
    int age;
    char gender[10];
    char contact[15];
    int isInpatient;
    char admissionDate[12];
    char dischargeDate[12];
    char disease[100];
} Patient;

void registerPatient();
void displayPatient(int id);
void editPatientDetails();
void editPatientDisease();
void searchPatient();
void patientMenu();

#endif
