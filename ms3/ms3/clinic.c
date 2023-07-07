/*/////////////////////////////////////////////////////////////////////////
                        Assignment 1 - Milestone 3
Full Name  : CHAN KA YING
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

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display's appointment schedule headers (date-specific or all records)
void displayScheduleTableHeader(const struct Date* date, int isAllRecords)
{
    printf("Clinic Appointments for the Date: ");

    if (isAllRecords)
    {
        printf("<ALL>\n\n");
        printf("Date       Time  Pat.# Name            Phone#\n"
            "---------- ----- ----- --------------- --------------------\n");
    }
    else
    {
        printf("%04d-%02d-%02d\n\n", date->year, date->month, date->day);
        printf("Time  Pat.# Name            Phone#\n"
            "----- ----- --------------- --------------------\n");
    }
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display a single appointment record with patient info. in tabular format
void displayScheduleData(const struct Patient* patient,
    const struct Appointment* appoint,
    int includeDateField)
{
    if (includeDateField)
    {
        printf("%04d-%02d-%02d ", appoint->date.year, appoint->date.month,
            appoint->date.day);
    }
    printf("%02d:%02d %05d %-15s ", appoint->time.hour, appoint->time.min,
        patient->patientNumber, patient->name);

    displayFormattedPhone(patient->phone.number);

    printf(" (%s)\n", patient->phone.description);
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
            menuAppointment(data);
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


// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Appointment Management
void menuAppointment(struct ClinicData* data)
{
    int selection;

    do {
        printf("Appointment Management\n"
            "==============================\n"
            "1) VIEW   ALL Appointments\n"
            "2) VIEW   Appointments by DATE\n"
            "3) ADD    Appointment\n"
            "4) REMOVE Appointment\n"
            "------------------------------\n"
            "0) Previous menu\n"
            "------------------------------\n"
            "Selection: ");
        selection = inputIntRange(0, 4);
        putchar('\n');
        switch (selection)
        {
        case 1:
            viewAllAppointments(data);  // ToDo: You will need to create this function!
            suspend();
            break;
        case 2:
            viewAppointmentSchedule(data);  // ToDo: You will need to create this function!
            suspend();
            break;
        case 3:
            addAppointment(data->appointments, data->maxAppointments,
                data->patients, data->maxPatient);  // ToDo: You will need to create this function!
            suspend();
            break;
        case 4:
            removeAppointment(data->appointments, data->maxAppointments,
                data->patients, data->maxPatient);  // ToDo: You will need to create this function!
            suspend();
            break;
        }
    } while (selection);
}


// ---------------------------------------------------------------------------
// !!! INSERT/COPY YOUR MS#2 FUNCTION DEFINITIONS BELOW... !!!
// Note: Maintain the same order/sequence as it is listed in the header file
//       Properly organize/categorize any new functions accordingly
// ---------------------------------------------------------------------------

// Display's all patient data in the FMT_FORM | FMT_TABLE format
// (Copy your code from MS#2)
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
// (Copy your code from MS#2)
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
            searchPatientByPatientNumber(patient, max, FMT_Patient);
        }
        else if (selection == 2)
        {
            searchPatientByPhoneNumber(patient, max);
        }

    } while (selection);

}

// Add a new patient record to the patient array
// (Copy your code from MS#2)
void addPatient(struct Patient patient[], int max)
{
    int i = 0;
    int vacant = 0;

    while (i < max && vacant == 0)
    {
        patient[i].patientNumber == 0 ?
            vacant++, patient[i].patientNumber = nextPatientNumber(patient, max) :
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
}

// Edit a patient record from the patient array
// (Copy your code from MS#2)
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
// (Copy your code from MS#2)
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

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// Milestone #3 mandatory functions...
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

// View ALL scheduled appointments
// Todo:
void viewAllAppointments(const struct ClinicData* data)
{
    int i = 0;
    int index;

    displayScheduleTableHeader(&data->appointments->date, FMT_ALL);
    sortingbyDate(data->appointments, MAX_APPOINTMENTS);

    for (i = 0; i < MAX_APPOINTMENTS; i++)
    {
        index = matching(&data->appointments[i], MAX_APPOINTMENTS, data->patients, MAX_PETS);
        if (data->appointments[i].date.year != 0)
        {
            displayScheduleData(&data->patients[index], &data->appointments[i], FMT_ALL);
        }
    }
    printf("\n");

}

// View appointment schedule for the user input date
// Todo:
void viewAppointmentSchedule(const struct ClinicData* data)
{
    int i = 0;
    int index = 0;
    struct Date vAS_Date;

    InputYearMonthDay(&vAS_Date);
    //printf("DATE: %d, %d, %d\n", vAS_Date.year, vAS_Date.month, vAS_Date.day);
    //printf("Patient ID in view: %d\n", data->appointments->patients.patientNumber);
    putchar('\n');

    displayScheduleTableHeader(&vAS_Date, FMT_SPECIFIC);
    sortingbyDate(data->appointments, MAX_APPOINTMENTS);

    for (i = 0; i < MAX_APPOINTMENTS; i++)
    {
        if (vAS_Date.year == data->appointments[i].date.year &&
            vAS_Date.month == data->appointments[i].date.month &&
            vAS_Date.day == data->appointments[i].date.day)
        {
            index = matching(&data->appointments[i], MAX_APPOINTMENTS, data->patients, MAX_PETS);
            displayScheduleData(&data->patients[index], &data->appointments[i], FMT_SPECIFIC);
        }
    }
    printf("\n");
}


// Add an appointment record to the appointment array
// Todo:
//void addAppointment(const struct Appointment *appoints, const struct Patient* patients)
void addAppointment(struct Appointment appointments[], int maxAppointments, struct Patient patients[], int maxPatient)
{
    struct Date addA_Date = { 0 };
    struct Time addA_Time = { 0 };
    int result = 0;
    int i = 0;
    int j = 0;
    int notAvaliable = 0;
    int index = 0;
    int vacant = 0;

    result = searchPatientByPatientNumber(patients, maxPatient, FMT_Appointment);

    do
    {
        InputYearMonthDay(&addA_Date);
        InputHourMin(&addA_Time);

        for (i = 0, notAvaliable = 0; i < maxAppointments; i++)
        {
            if (addA_Date.year == appointments[i].date.year && addA_Date.month == appointments[i].date.month && addA_Date.day == appointments[i].date.day &&
                addA_Time.hour == appointments[i].time.hour && addA_Time.min == appointments[i].time.min)
            {
                notAvaliable++;
            }
        }
        if (notAvaliable)
        {
            puts("\nERROR: Appointment timeslot is not available!\n");
        }
    } while (result != -1 && notAvaliable);

    while (j < maxAppointments && appointments[j].date.year != 0)
    {
        j++;

        if (appointments[j].date.year == 0)
        {
            index = j;
            vacant++;
        }
        else if (vacant == 0)
        {
            puts("\nERROR: Appointment listing is FULL!\n");
        }
    }

    appointments[index].date = addA_Date;
    appointments[index].time = addA_Time;
    appointments[index].patientsID = patients[result].patientNumber;

    puts("\n*** Appointment scheduled! ***\n");
}


// Remove an appointment record from the appointment array
// Todo:
void removeAppointment(struct Appointment appointments[], int maxAppointments, struct Patient patients[], int maxPatient)
{
    struct Date rmA_Date = { 0 };
    int result = 0;
    int i = 0;
    int index = 0;
    int found = 0;
    int selection = 0;

    result = searchPatientByPatientNumber(patients, maxPatient, FMT_Appointment);
    //printf("result: %d\n", result);

    if (result != -1)
    {
        InputYearMonthDay(&rmA_Date);

        while (i < maxAppointments && found == 0)
        {
            i++;
            if (patients[result].patientNumber == appointments[i].patientsID &&
                rmA_Date.year == appointments[i].date.year && rmA_Date.month == appointments[i].date.month && rmA_Date.day == appointments[i].date.day)
            {
                index = i;
                found++;
            }
        }
        putchar('\n');
    }

    if (found)
    {
        displayPatientData(&patients[result], FMT_FORM);
        printf("Are you sure you want to remove this appointment (y,n): ");
        selection = inputCharOption("yn");
        if (selection == 'y')
        {
            appointments[index].patientsID = 0;
            appointments[index].date = (struct Date){ 0 };
            appointments[index].time = (struct Time){ 0 };

            printf("\nAppointment record has been removed!\n\n");
        }
        else
        {
            printf("\nOperation aborted.\n\n");
        }
    }
}

//////////////////////////////////////////////
// UTILITY FUNCTIONS FOR PATIENT MANAGEMENT
//////////////////////////////////////////////

// Search and display patient record by patient number (form)
// (Copy your code from MS#2)
int searchPatientByPatientNumber(const struct Patient patient[], int max, int fmt)
{
    int numberInput;
    int indexPosition;

    if (fmt == FMT_Patient)
    {
        printf("Search by patient number: ");
    }
    else
    {
        printf("Patient Number: ");
    }

    numberInput = inputIntPositive();
    indexPosition = findPatientIndexByPatientNum(numberInput, patient, max);
    //printf("indexPosition: %d\n", indexPosition);

    if (fmt == FMT_Patient)
    {
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
    else
    {
        if (indexPosition == -1)
        {
            puts("ERROR: Patient record not found!\n");
        }
    }

    return indexPosition;
}

// Search and display patient records by phone number (tabular)
// (Copy your code from MS#2)
void searchPatientByPhoneNumber(const struct Patient patient[], int max)
{
    char phoneInput[PHONE_LEN + 1] = { 0 };
    int i = 0;
    int result = 0;
    int found = 0;

    printf("Search by phone number: ");
    inputCString(phoneInput, PHONE_LEN, PHONE_LEN);

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
// (Copy your code from MS#2)
int nextPatientNumber(const struct Patient patient[], int max)
{
    int i = 0;
    int highest = 0;
    int result = 0;

    for (i = 0; i < max; i++)
    {
        if (highest < patient[i].patientNumber)
        {
            highest = patient[i].patientNumber;
        }
    }
    result = highest + 1;

    return result;
}

// Find the patient array index by patient number (returns -1 if not found)
// (Copy your code from MS#2)
int findPatientIndexByPatientNum(int patientNumber, const struct Patient patient[], int max)
{
    int i = 0;
    int result = -1;

    for (i = 0; i < max; i++)
    {
        if (patientNumber == patient[i].patientNumber && patient[i].patientNumber != 0)
        {
            result = i;
        }
    }

    return result;
}

//////////////////////////////////////////////////
// UTILITY FUNCTIONS FOR APPOINTMENT MANAGEMENT
//////////////////////////////////////////////////

// Sorting appointments by Date and Time
void sortingbyDate(struct Appointment appoints[], int max)
{
    int i, j;
    int minIndex;
    struct Appointment temp;

    for (i = 0; i < max; i++)
    {
        minIndex = i;

        for (j = i + 1; j < max; j++)
        {
            if ((appoints[j].date.year < appoints[minIndex].date.year) || (appoints[j].date.year == appoints[minIndex].date.year && appoints[j].date.month < appoints[minIndex].date.month) ||
                (appoints[j].date.year == appoints[minIndex].date.year && appoints[j].date.month == appoints[minIndex].date.month && appoints[j].date.day < appoints[minIndex].date.day) ||
                (appoints[j].date.year == appoints[minIndex].date.year && appoints[j].date.month == appoints[minIndex].date.month && appoints[j].date.day == appoints[minIndex].date.day && appoints[j].time.hour < appoints[minIndex].time.hour) ||
                (appoints[j].date.year == appoints[minIndex].date.year && appoints[j].date.month == appoints[minIndex].date.month && appoints[j].date.day == appoints[minIndex].date.day && appoints[j].time.hour == appoints[minIndex].time.hour && appoints[j].time.min < appoints[minIndex].time.min))
            {
                minIndex = j;
            }
        }

        if (minIndex != i)
        {
            temp = appoints[i];
            appoints[i] = appoints[minIndex];
            appoints[minIndex] = temp;
        }
    }
}

// Matching data from inputted file for display
int matching(const struct Appointment appoints[], int maxAppoints, const struct Patient patients[], int maxPatients)
{
    int i;
    int index = 0;
    for (i = 0; i < MAX_PETS; i++)
    {
        if (appoints->patientsID == patients[i].patientNumber)
        {
            index = i;
        }
    }

    return index;
}

// Get user input Year, Month and Day
void InputYearMonthDay(struct Date* dt)
{
    dt->year = 0;
    dt->month = 0;
    dt->day = 0;

    do {
        printf("Year        : ");
        dt->year = inputIntRange(MIN_YEAR, MAX_YEAR);

        printf("Month (%d-%d): ", MIN_MON, MAX_MON);
        dt->month = inputIntRange(MIN_MON, MAX_MON);
        if (dt->month == 1 ||
            dt->month == 3 ||
            dt->month == 5 ||
            dt->month == 7 ||
            dt->month == 8 ||
            dt->month == 10 ||
            dt->month == 12)
        {
            printf("Day (%d-%d)  : ", MIN_DAY, 31);
            dt->day = inputIntRange(MIN_DAY, 31);
        }
        else if (dt->month == 2)
        {
            if (dt->year != 2024)
            {
                printf("Day (%d-%d)  : ", MIN_DAY, 28);
                dt->day = inputIntRange(MIN_DAY, 28);
            }
            else
            {
                printf("Day (%d-%d)  : ", MIN_DAY, 29);
                dt->day = inputIntRange(MIN_DAY, 29);
            }
        }
        else
        {
            printf("Day (%d-%d)  : ", MIN_DAY, 30);
            dt->day = inputIntRange(MIN_DAY, 30);
        }

    } while (!dt->year && !dt->month && !dt->day);

}

// Get user input Hour and Min
void InputHourMin(struct Time* tm)
{
    int done = 0;

    tm->hour = 0;
    tm->min = 0;

    do {
        printf("Hour (0-23)  : ");
        tm->hour = inputIntRange(0, 23);

        printf("Minute (0-59): ");
        tm->min = inputIntRange(0, 59);

        if (tm->hour < MIN_HOUR || tm->hour > MAX_HOUR ||
            !(tm->min == MINUTE_INTERVAL_0 || tm->min == MINUTE_INTERVAL_30) ||
            (tm->hour == MAX_HOUR && tm->min == MINUTE_INTERVAL_30))
        {
            printf("ERROR: Time must be between %02d:%02d and %02d:%02d in %02d minute intervals.\n\n", MIN_HOUR, MINUTE_INTERVAL_0, MAX_HOUR, MINUTE_INTERVAL_0, MINUTE_INTERVAL_30);
        }
        else
        {
            done = 1;
        }

    } while (!done);

}

//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

// Get user input for a new patient record
// (Copy your code from MS#2)
void inputPatient(struct Patient* patient)
{
    printf("Patient Data Input\n"
        "------------------\n");
    printf("Number: %05d\n", patient->patientNumber);
    printf("Name  : ");
    inputCString(patient->name, 1, NAME_LEN);
    putchar('\n');

    inputPhoneData(&patient->phone);
}

// Get user input for phone contact information
// (Copy your code from MS#2)
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
        inputPhoneValidation(phone->number, PHONE_LEN, PHONE_LEN);
        putchar('\n');
    }
}

//////////////////////////////////////
// FILE FUNCTIONS
//////////////////////////////////////

// Import patient data from file into a Patient array (returns # of records read)
int importPatients(const char* datafile, struct Patient patients[], int max)
{
    FILE* fp = fopen(datafile, "r");
    int i = 0;

    if (datafile != NULL)
    {
        for (i = 0; i < max && !feof(fp); i++)
        {
            fscanf(fp, "%d|%[^|]|%[^|]|%[^\n]", &patients[i].patientNumber, patients[i].name, patients[i].phone.description, patients[i].phone.number);
        }
        fclose(fp);
        fp = NULL;
    }
    else
    {
        puts("ERROR: Failed to access file!");
    }

    return i;
}

// Import appointment data from file into an Appointment array (returns # of records read)
int importAppointments(const char* datafile, struct Appointment appoints[], int max)
{
    FILE* fp = fopen(datafile, "r");
    int i = 0;

    if (datafile != NULL)
    {
        while (fscanf(fp, "%d,%d,%d,%d,%d,%d\n", &appoints[i].patientsID, &appoints[i].date.year, &appoints[i].date.month, &appoints[i].date.day, &appoints[i].time.hour, &appoints[i].time.min) == 6 && i < max) // !EOF
        {
            i++;
        }
        fclose(fp);
        fp = NULL;
    }
    else
    {
        puts("ERROR: Failed to access file!");
    }

    return i;
}