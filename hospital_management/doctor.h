#ifndef DOCTOR_H
#define DOCTOR_H

typedef struct {
    int id;
    char name[100];
    char specialization[50];
    char password[20];
} Doctor;

void registerDoctor();
void searchDoctor();
void doctorMenu();
void editDoctorDetails();

#endif
