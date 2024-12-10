#include <stdio.h>//Includes standard Input Output library 
#include <stdlib.h>//Inlcudes standard library to hanlde file operations
#include <string.h>//To hanlde string related operations

// Define constants for the phonebook
#define MAX_CONTACTS 100 // Maximum number of contacts that can be stored
#define NAME_LENGTH 50   // Maximum length of a contact's name
#define PHONE_LENGTH 10  // Maximum length of a contact's phone number

// Define a structure to store contact details
typedef struct
{
    char name[NAME_LENGTH];   // Array to store the contact's name
    char phone[PHONE_LENGTH]; // Array to store the contact's phone number
} Contact;

// Function prototypes to declare the functions used in the program
void addContact(Contact contacts[], int *count);           // Adds a new contact to the phonebook
void displayContacts(Contact contacts[], int count);       // Displays all contacts in the phonebook
void loadContactsFromFile(Contact contacts[], int *count); // Loads contacts from a file into the phonebook

int main()
{
    // Declare an array to hold the contacts and a counter to track the number of contacts
    Contact contacts[MAX_CONTACTS];
    int count = 0; // Initialize the contact counter to 0

    // Variable to store the user's menu choice
    int choice;

    // Load contacts from the file at the start of the program
    loadContactsFromFile(contacts, &count);

    // Main program loop for the menu
    do
    {
        // Display the menu options to the user
        printf("\nPhonebook Menu:\n");
        printf("1. Add Contact\n");//Prompts user to enter new contact
        printf("2. Display Contacts\n");//Prompts user to display contact
        printf("3. Load Contacts\n");//Loads contact
        printf("4. Exit\n");//Exits and terminates the program
        printf("Enter your choice: ");
        scanf("%d", &choice); // Read the user's choice

        // Perform actions based on the user's choice
        switch (choice)
        {
        case 1:
            addContact(contacts, &count); // Add a new contact
            break;
        case 2:
            displayContacts(contacts, count); // Display all contacts
            break;
        case 3:
            loadContactsFromFile(contacts, &count); // Reload contacts from the file
            break;
        case 4:
            printf("Exiting...\n"); // Exit the program
            break;
        default:
            printf("Invalid choice. Please try again.\n"); // Handle invalid menu choices
        }
    } while (choice != 4); // Repeat the menu until the user chooses to exit

    return 0; // Return 0 to indicate successful program execution
}

// Function to add a new contact to the phonebook
void addContact(Contact contacts[], int *count)
{
    // Check if the phonebook is full
    if (*count >= MAX_CONTACTS)
    {
        printf("Phonebook is full!\n");
        return; // Exit the function if no more contacts can be added
    }

    // Prompt the user for the contact's name and phone number
    printf("Enter name: ");
    scanf("%49s", contacts[*count].name); // Read the name with size restriction
    printf("Enter phone: ");
    scanf("%9s", contacts[*count].phone); // Read the phone number with size restriction

    // Increment the count of contacts after adding the new contact
    (*count)++;
    printf("Contact added successfully!\n"); // Confirm that the contact was added
}

// Function to display all contacts in the phonebook
void displayContacts(Contact contacts[], int count)
{
    // Check if there are any contacts to display
    if (count == 0)
    {
        printf("No contacts to display.\n");
        return; // Exit the function if the phonebook is empty
    }

    // Loop through each contact and display its details
    printf("\nContacts:\n");
    for (int i = 0; i < count; i++)
    {
        printf("Name: %s, Phone: %s\n", contacts[i].name, contacts[i].phone);
    }
}

// Function to load contacts from a file into the phonebook
void loadContactsFromFile(Contact contacts[], int *count)
{
    // Open the file "contacts.txt" for reading
    FILE *file = fopen("contacts.txt", "r");

    // Check if the file could not be opened
    if (file == NULL)
    {
        printf("No contacts file found. Starting fresh.\n");
        return; // Exit the function if the file does not exist
    }

    // Read the contacts from the file until the end of the file is reached
    while (fscanf(file, "%49s %9s", contacts[*count].name, contacts[*count].phone) == 2)
    {
        (*count)++; // Increment the count for each successfully read contact
    }

    // Close the file after reading
    fclose(file);
    printf("Contacts loaded from file successfully!\n"); // Confirm successful loading of contacts
}