#include<stdio.h>

void addEntry();
void viewEntries();
void editEntry();
void deleteEntries();
void searchEntry();

int main()
{
    int choice;

    while(1)
    {
        printf("\n--- Personal Diary Menu ---\n");
        printf("1. Add Entry\n");
        printf("2. View Entries\n");
        printf("3. Edit Entries\n");
        printf("4. Delete All Entries\n");
        printf("5. Search Entry\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEntry();
                break;
            case 2:
                viewEntries();
                break;
            case 3:
                editEntry();
                break;
            case 4:
                deleteEntries();
                break;
            case 5:
                searchEntry();
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;

 }

void addEntry()
{

}
void viewEntries()
{

}
void editEntry()
{

}
void deleteEntries()
{

}
void searchEntry()
{

}
