#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 50
#define MAX_NAME_SIZE 40
#define MAX_PHONE_NUMBER_SIZE 20
#define MAX_EMAIL_SIZE 30

typedef struct
{
    char *name;
    char *phone_number;
    char *email_address;
} Contact;

Contact *contacts;

int validate_names(char *name);
int validate_emai(char *email_address);
int validate_phone(char *phone_number);
void add_contact(int *contact_length);
void display_contacts(int *contact_length);
void search_contact(char *contacts);
void remove_contact(char *contact_name, int *contact_length);

int main(void)
{
    // Initialization inside function due to error
    //"https://stackoverflow.com/questions/35186290/c-struct-object-stack-function-call-is-not-allowed-in-constant-expression-err"
    contacts = (Contact *)malloc(MAX_CONTACTS * sizeof(Contact));
    int contact_length = 0;

    printf("Welcome to C Address Book\n");

    while (1)
    {
        int option = 0;
        char buffer[50];

        printf("Options:\n\n");
        printf("1-Add new contact\n");
        printf("2-Remove contact\n");
        printf("3-Display Contacts\n");
        printf("4-Search contact\n");
        printf("Exit\n\n");

        printf("Select Option: ");
        // Assuming you read a line into buffer using fgets
        fgets(buffer, sizeof(buffer), stdin);

        // Removing trailing newline
        buffer[strcspn(buffer, "\n")] = '\0';

        // Now you can safely convert it to an integer
        sscanf(buffer, "%d", &option);

        switch (option)
        {
        case 1:
            add_contact(&contact_length);
            break;
        case 2:
            printf("Name of the contact to remove: ");
            char *contact_name = (char *)malloc(MAX_NAME_SIZE);
            fgets(contact_name, sizeof(contact_name), stdin);
            contact_name[strcspn(contact_name, "\n")] = '\0';
            remove_contact(contact_name, &contact_length);
            break;
        case 3:
            display_contacts(&contact_length);
            break;
        case 4:
        case 5:
            break;
        default:
            printf("Unknown Option\n\n");
        }
    }

    return 0;
    printf("Phone Number: ");
}

void add_contact(int *contact_length)
{
    contacts[*contact_length].name = (char *)malloc(MAX_NAME_SIZE);
    printf("First and Last Name: ");
    fgets(contacts[*contact_length].name, MAX_NAME_SIZE, stdin);

    contacts[*contact_length].phone_number = (char *)malloc(MAX_PHONE_NUMBER_SIZE);
    printf("Phone Number: ");
    fgets(contacts[*contact_length].phone_number, MAX_PHONE_NUMBER_SIZE, stdin);

    contacts[*contact_length].email_address = (char *)malloc(MAX_EMAIL_SIZE);
    printf("Email: ");
    fgets(contacts[*contact_length].email_address, MAX_EMAIL_SIZE, stdin);

    (*contact_length)++;
    printf("%d\n", *contact_length);
}

void display_contacts(int *contact_length)
{
    if (*contact_length == 0)
    {
        printf("No contacts on the address book yet!");
        return;
    }
    for (size_t i = 0; i < *contact_length; i++)
    {
        printf("Contact %zu\n\n", i + 1);
        printf("Name: %s", contacts[i].name);
        printf("Phone number: %s", contacts[i].phone_number);
        printf("Email: %s", contacts[i].email_address);
    }
}

void remove_contact(char *contact_name, int *contact_length)
{
    for (size_t i = 0; i < *contact_length; i++)
    {
        if (strcasecmp(contact_name, contacts[i].name) == 0 == 0)
        {
            int index = i;
            free(contacts[i].name);
            free(contacts[i].email_address);
            free(contacts[i].phone_number);
            for (size_t i = index; i < *contact_length-1; i++)
            {
                contacts[i] = contacts[i + 1];
            }
            (*contact_length)--;
            break;
        }
    }
}