#include <stdio.h>
#include "disease_info.h"

void displayDiseaseInfo(int diseaseChoice) {
printf("\nDisease Information:\n");
    printf("+------------------+-------------------------+-------------------------+-------------------------+-------------------------+\n");
    printf("| Disease          | Symptoms                | Medications (Morning)    | Medications (Afternoon)  | Medications (Night)     |\n");
    printf("+------------------+-------------------------+-------------------------+-------------------------+-------------------------+\n");
    
    switch (diseaseChoice) {
        case 1:
            printf("| Cold             | Runny nose, sore throat,| Cough syrup             | Paracetamol             | Cough syrup             |\n");
            printf("+------------------+-------------------------+-------------------------+-------------------------+-------------------------+\n");
            printf("|                  | Cough                   |                         |                         |                         |\n");
            printf("| Diet Plan        | Warm fluids, rest       |                         |                         |                         |\n");
            break;
        case 2:
            printf("| Fever            | High temperature, chills,| Paracetamol             | Paracetamol             | Paracetamol             |\n");
            printf("+------------------+-------------------------+-------------------------+-------------------------+-------------------------+\n");
            printf("|                  | body aches              |                         |                         |                         |\n");
            printf("| Diet Plan        | Hydrate well, light food|                         |                         |                         |\n");
            break;
        case 3:
            printf("| Tuberculosis     | Persistent cough, chest | Isoniazid               | -                       | Isoniazid               |\n");
            printf("+------------------+-------------------------+-------------------------+-------------------------+-------------------------+\n");
            printf("|                  | pain                    |                         |                         |                         |\n");
            printf("| Diet Plan        | High-calorie, protein-  |                         |                         |                         |\n");
            printf("                   | rich diet               |                         |                         |                         |\n");
            break;        
        case 4:
            printf("| Malaria          | Fever, chills, sweats   | Antimalarial drugs      | -                       | Antimalarial drugs      |\n");
            printf("+------------------+-------------------------+-------------------------+-------------------------+-------------------------+\n");
            printf("|                  |                         |                         |                         |                         |\n");
            printf("| Diet Plan        | Hydrate well, light food|                         |                         |                         |\n");
            break;
        case 5:
            printf("| Dengue Fever     | High fever, headache, rash| Pain relievers         | Fluids                  |                         |\n");
            printf("+------------------+-------------------------+-------------------------+-------------------------+-------------------------+\n");
            printf("|                  |                         |                         |                         |                         |\n");
            printf("| Diet Plan        | Hydrate well, rest      |                         |                         |                         |\n");
            break;
        case 6:
            printf("| Typhoid          | Fever, weakness, abdominal| Antibiotics as prescribed|                         |                         |\n");
            printf("+------------------+-------------------------+-------------------------+-------------------------+-------------------------+\n");
            printf("|                  | pain                    |                         |                         |                         |\n");
            printf("| Diet Plan        | Soft, bland diet        |                         |                         |                         |\n");
            break;
        case 7:
            printf("| Hepatitis B      | Jaundice, fatigue, nausea| Antiviral medications   |                         |                         |\n");
            printf("+------------------+-------------------------+-------------------------+-------------------------+-------------------------+\n");
            printf("|                  |                         |                         |                         |                         |\n");
            printf("| Diet Plan        | Low-fat, balanced diet  |                         |                         |                         |\n");
            break;
        case 8:
            printf("| Hepatitis C      | Jaundice, fatigue, joint| Antiviral medications   |                         |                         |\n");
            printf("+------------------+-------------------------+-------------------------+-------------------------+-------------------------+\n");
            printf("|                  | pain                    |                         |                         |                         |\n");
            printf("| Diet Plan        | Avoid alcohol, balanced diet|                     |                         |                         |\n");
            break;
        case 9:
            printf("| HIV/AIDS         | Fever, fatigue, swollen lymph| Antiretroviral therapy |                         |                         |\n");
            printf("+------------------+-------------------------+-------------------------+-------------------------+-------------------------+\n");
            printf("|                  | nodes                   |                         |                         |                         |\n");
            printf("| Diet Plan        | Balanced diet, high in vitamins|                  |                         |                         |\n");
            break;
        case 10:
            printf("| Diabetes         | Increased thirst, frequent| Insulin, oral hypoglycemics |                   |                         |\n");
            printf("+------------------+-------------------------+-------------------------+-------------------------+-------------------------+\n");
            printf("|                  | urination               |                         |                         |                         |\n");
            printf("| Diet Plan        | Low sugar, balanced diet|                         |                         |                         |\n");
            break;
        case 11:
            printf("| Heart Disease    | Chest pain, shortness of| As prescribed by cardiologist|                   |                         |\n");
            printf("+------------------+-------------------------+-------------------------+-------------------------+-------------------------+\n");
            printf("|                  | breath                  |                         |                         |                         |\n");
            printf("| Diet Plan        | Low-fat, heart-healthy diet|                     |                         |                         |\n");
            break;
        case 12:
            printf("| Cancer           | Weight loss, fatigue, pain| Chemotherapy as prescribed|                     |                         |\n");
            printf("+------------------+-------------------------+-------------------------+-------------------------+-------------------------+\n");
            printf("|                  |                         |                         |                         |                         |\n");
            printf("| Diet Plan        | High-protein, high-calorie diet|                  |                         |                         |\n");
            break;
        default:
            printf("| Disease not found|                         |                         |                         |                         |\n");
            printf("+------------------+-------------------------+-------------------------+-------------------------+-------------------------+\n");
            break;
    }
}
