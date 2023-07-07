/*/////////////////////////////////////////////////////////////////////////
                        Assignment 1 - Milestone 2
Full Name  : Chan Ka Ying
Student ID#: 123231227
Email      : kchan151@myseneca.ca
Section    : NDD

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

// include the user library "core" so we can use those functions
#include "core.h"
// include the user library "clinic" where the function prototypes are declared
#include "clinic.h"


//////////////////////////////////////
// DISPLAY FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display's the patient table header (table format)
void displayPatientTableHeader(void)
{
    printf("Pat.# Name            Phone#\n"
        "----- --------------- --------------------\n");
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Displays a single patient record in FMT_FORM | FMT_TABLE format
void displayPatientData(const struct Patient* patient, int fmt)
{
    if (fmt == FMT_FORM)
    {
        printf("Name  : %s\n"
            "Number: %05d\n"
            "Phone : ", patient->name, patient->patientNumber);
        displayFormattedPhone(patient->phone.number);
        printf(" (%s)\n", patient->phone.description);
    }
    else
    {
        printf("%05d %-15s ", patient->patientNumber,
            patient->name);
        displayFormattedPhone(patient->phone.number);
        printf(" (%s)\n", patient->phone.description);
    }
}


//////////////////////////////////////
// MENU & ITEM SELECTION FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// main menu
void menuMain(struct ClinicData* data)
{
    int selection;

    do {
        printf("Veterinary Clinic System\n"
            "=========================\n"
            "1) PATIENT     Management\n"
            "2) APPOINTMENT Management\n"
            "-------------------------\n"
            "0) Exit System\n"
            "-------------------------\n"
            "Selection: ");
        selection = inputIntRange(0, 2);
        putchar('\n');
        switch (selection)
        {
        case 0:
            printf("Are you sure you want to exit? (y|n): ");
            selection = !(inputCharOption("yn") == 'y');
            putchar('\n');
            if (!selection)
            {
                printf("Exiting system... Goodbye.\n\n");
            }
            break;
        case 1:
            menuPatient(data->patients, data->maxPatient);
            break;
        case 2:
            printf("<<< Feature not yet available >>>\n\n");
            break;
        }
    } while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient Management
void menuPatient(struct Patient patient[], int max)
{
    int selection;

    do {
        printf("Patient Management\n"
            "=========================\n"
            "1) VIEW   Patient Data\n"
            "2) SEARCH Patients\n"
            "3) ADD    Patient\n"
            "4) EDIT   Patient\n"
            "5) REMOVE Patient\n"
            "-------------------------\n"
            "0) Previous menu\n"
            "-------------------------\n"
            "Selection: ");
        selection = inputIntRange(0, 5);
        putchar('\n');
        switch (selection)
        {
        case 1:
            displayAllPatients(patient, max, FMT_TABLE);
            suspend();
            break;
        case 2:
            searchPatientData(patient, max);
            break;
        case 3:
            addPatient(patient, max);
            suspend();
            break;
        case 4:
            editPatient(patient, max);
            break;
        case 5:
            removePatient(patient, max);
            suspend();
            break;
        }
    } while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient edit
void menuPatientEdit(struct Patient* patient)
{
    int selection;

    do {
        printf("Edit Patient (%05d)\n"
            "=========================\n"
            "1) NAME : %s\n"
            "2) PHONE: ", patient->patientNumber, patient->name);

        displayFormattedPhone(patient->phone.number);

        printf("\n"
            "-------------------------\n"
            "0) Previous menu\n"
            "-------------------------\n"
            "Selection: ");
        selection = inputIntRange(0, 2);
        putchar('\n');

        if (selection == 1)
        {
            printf("Name  : ");
            inputCString(patient->name, 1, NAME_LEN);
            putchar('\n');
            printf("Patient record updated!\n\n");
        }
        else if (selection == 2)
        {
            inputPhoneData(&patient->phone);
            printf("Patient record updated!\n\n");
        }

    } while (selection);
}


// ---------------------------------------------------------------------------
// !!! Put all the remaining function definitions below !!!
// Note: Maintain the same order/sequence as it is listed in the header file
// ---------------------------------------------------------------------------

// Display's all patient data in the FMT_FORM | FMT_TABLE format
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void displayAllPatients(const struct Patient patient[], int max, int fmt)
{
    int i = 0;

    displayPatientTableHeader();

    for (i = 0; i < max; i++)
    {
        if (patient[i].patientNumber != 0)
        {
            displayPatientData(&patient[i], fmt);
        }
    }
    printf("\n");

    if (&patient->patientNumber == NULL)
    {
        printf("*** No records found ***");
    }

}


// Search for a patient record based on patient number or phone number
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void searchPatientData(const struct Patient patient[], int max)
{
    int selection;

    do {
        printf("Search Options\n"
            "==========================\n"
            "1) By patient number\n"
            "2) By phone number\n"
            "..........................\n"
            "0) Previous menu\n"
            "..........................\n"
            "Selection: ");

        selection = inputIntRange(0, 2);
        putchar('\n');

        if (selection == 1)
        {
            searchPatientByPatientNumber(patient, max);
        }
        else if (selection == 2)
        {
            searchPatientByPhoneNumber(patient, max);
        }

    } while (selection);

}

// Add a new patient record to the patient array
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void addPatient(struct Patient patient[], int max)
{
    int i = 0;
    int vacant = 0;

    while (i < max && vacant == 0)
    {
        // printf("patient number: %d\n", patient[i].patientNumber);
        patient[i].patientNumber == 0 ? 
            vacant++, patient[i].patientNumber = nextPatientNumber(patient, max):
            i++;
    }

    if (vacant == 0)
    {
        puts("ERROR: Patient listing is FULL!\n");
    }
    else
    {
        inputPatient(&patient[i]);
        puts("*** New patient record added ***\n");
    }

    // displayAllPatients(patient, max, FMT_TABLE);
}

// Edit a patient record from the patient array
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void editPatient(struct Patient patient[], int max)
{
    int numberInput = 0;
    int result;
    printf("Enter the patient number: ");
    numberInput = inputIntPositive();
    putchar('\n');
    result = findPatientIndexByPatientNum(numberInput, patient, max);
    result == -1 ?
        printf("ERROR: Patient record not found!") :
        menuPatientEdit(&patient[result]);

}


// Remove a patient record from the patient array
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void removePatient(struct Patient patient[], int max)
{
    int numberInput = 0;
    int result = 0;
    char selection = 0;
    printf("Enter the patient number: ");
    numberInput = inputIntPositive();
    putchar('\n');
    result = findPatientIndexByPatientNum(numberInput, patient, max);
    if (result == -1)
    {
        printf("ERROR: Patient record not found!\n\n");
    }
    else
    {
        //printf("%d", result);

        displayPatientData(&patient[result], FMT_FORM);
        putchar('\n');
        printf("Are you sure you want to remove this patient record? (y/n): ");
        selection = inputCharOption("yn");
        if (selection == 'y')
        {
            printf("Patient record has been removed!\n\n");
            patient[result].patientNumber = '\0';
        }
        else
        {
            printf("Operation aborted.\n\n");
        }

    }

}

//////////////////////////////////////
// UTILITY FUNCTIONS
//////////////////////////////////////

// Search and display patient record by patient number (form)
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void searchPatientByPatientNumber(const struct Patient patient[], int max)
{
    int numberInput;
    int indexPosition;

    printf("Search by patient number: ");
    numberInput = inputIntPositive();

    indexPosition = findPatientIndexByPatientNum(numberInput, patient, max);

    puts("");
    if (indexPosition == -1)
    {
        puts("*** No records found ***");
    }
    else
    {
        displayPatientData(&patient[indexPosition], FMT_FORM);
    }
    puts("");
    suspend();
}


// Search and display patient records by phone number (tabular)
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void searchPatientByPhoneNumber(const struct Patient patient[], int max)
{
    char phoneInput[PHONE_LEN + 1] = { 0 };
    int i = 0;
    int result;
    int found = 0;

    printf("Search by phone number: ");
    inputCString(&phoneInput, PHONE_LEN, PHONE_LEN);
    //scanf("%10s", phoneInput);
    //clearInputBuffer();
    
    putchar('\n');
    for (i = 0; i < max; i++)
    {
        result = strcmp(phoneInput, patient[i].phone.number);
        if (result == 0)
        {
            found++;
            if (found < 2)
            {
                displayPatientTableHeader();
            }
            displayPatientData(&patient[i], FMT_TABLE);
        }
    }
    if (found == 0)
    {
        displayPatientTableHeader();
        puts("\n*** No records found ***");
    }

    putchar('\n');
    suspend();
}

// Get the next highest patient number
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
int nextPatientNumber(const struct Patient patient[], int max)
{
    int highest = 0;
    int i = 0;

    for (i = 0; i < max; i++)
    {
        if (highest < patient[i].patientNumber)
        {
            highest = patient[i].patientNumber;
        }
    }
    //printf("highest: %d\n", highest);

    return highest + 1;
}

// Find the patient array index by patient number (returns -1 if not found)
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
int findPatientIndexByPatientNum(int patientNumber, const struct Patient patient[], int max)
{
    int i = 0;
    int result = -1;

    for (i = 0; i < max; i++)
    {
        //printf("input: %d, patient number on iterate: %d\n", patientNumber, patient[i].patientNumber);
        if (patientNumber == patient[i].patientNumber && patient[i].patientNumber != 0)
        {
            //printf("%d\n", i);
            result = i;
        }
    }

    return result;
}


//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

// Get user input for a new patient record
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void inputPatient(struct Patient* patient)
{
    printf("Patient Data Input\n"
        "------------------\n");
    printf("Number: %05d\n", patient->patientNumber);
    printf("Name  : ");
    inputCString(patient->name, 1, NAME_LEN);
    //scanf("%15[^\n]", patient->name);
    //clearInputBuffer();
    putchar('\n');
    
    inputPhoneData(&patient->phone);
}


// Get user input for phone contact information
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void inputPhoneData(struct Phone* phone)
{
    int selection;
    char phonenumInput[PHONE_LEN + 1] = { 0 };

    printf("Phone Information\n"
        "-----------------\n"
        "How will the patient like to be contacted?\n"
        "1. Cell\n"
        "2. Home\n"
        "3. Work\n"
        "4. TBD\n"
        "Selection: ");
    selection = inputIntRange(1, 4);
    putchar('\n');
    switch (selection)
    {
    case 1:
        strcpy(phone->description, "CELL");
        break;
    case 2:
        strcpy(phone->description, "HOME");
        break;
    case 3:
        strcpy(phone->description, "WORK");
        break;
    case 4:
        strcpy(phone->description, "TBD");
        strcpy(phone->number, phonenumInput);
        break;
    }
    if (selection != 4)
    {
        printf("Contact: %s\n", phone->description);
        printf("Number : ");
        inputCString(phone->number, PHONE_LEN, PHONE_LEN);
        //scanf("%10[^\n]", phonenumInput);
        //strcpy(phone->number, phonenumInput);
        putchar('\n');
    }
}