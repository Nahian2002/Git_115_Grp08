#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 1000
#define MAX_ENTRY_LEN 100

char diary[MAX_ENTRIES][MAX_ENTRY_LEN];
int entryCount = 0;

void encryptEntry(int index);
void decryptEntry(int index);
void addEntry();
void viewEntries();
void editEntry();
void deleteEntry();
void deleteAllEntries();
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
        printf("4. Delete Entry\n");
        printf("5. Delete All Entries\n");
        printf("6. Search Entry\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
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
                deleteEntry();
                break;
            case 5:
                deleteAllEntries();
                break;
            case 6:
                searchEntry();
                break;
            case 7:
                printf("Exiting...\n");
                exit(0);
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;

 }

void encryptEntry(int index)
{
    for (int i = 0; i < MAX_ENTRY_LEN; i++)
    {
        if (diary[index][i] != '\0')
        {
            diary[index][i] = diary[index][i] + 2;
        }
        else
        {
            break;
        }
    }
}

void decryptEntry(int index)
{
    for (int i = 0; i < MAX_ENTRY_LEN; i++)
    {
        if (diary[index][i] != '\0')
        {
            diary[index][i] = diary[index][i] - 2;
        }
        else
        {
            break;
        }
    }
}

void loadEntries()
{
    FILE *file = fopen("diary_entries.txt", "r");
    if (file != NULL)
    {
        entryCount = 0;
        while (fgets(diary[entryCount], MAX_ENTRY_LEN, file) != NULL)
        {
            if (diary[entryCount][strlen(diary[entryCount]) - 1] == '\n')
            {
                diary[entryCount][strlen(diary[entryCount]) - 1] = '\0';
            }
            entryCount++;
        }
        fclose(file);
    }
}

void saveEntries()
{
    FILE *file = fopen("diary_entries.txt", "w");
    if (file != NULL)
    {
        for (int i = 0; i < entryCount; i++)
        {
            fprintf(file, "%s\n", diary[i]);
        }
        fclose(file);
    }
    else
    {
        printf("Error opening file.\n");
    }
}

void addEntry()
{

}

void viewEntries()
{
    if (entryCount == 0)
    {
        printf("No entries found!\n");
        return;
    }

    printf("Your diary entries:\n");

    for (int i = 0; i < entryCount; i++)
    {
        decryptEntry(i);
        printf("%d. %s\n", i + 1, diary[i]);
        encryptEntry(i);
    }
}

void editEntry()
{

}

void deleteEntry()
{
    if (entryCount == 0)
    {
        printf("No entries to delete!\n");
        return;
    }

    printf("Your diary entries:\n");
    
    for (int i = 0; i < entryCount; i++)
    {
        decryptEntry(i);
        printf("%d. %s\n", i + 1, diary[i]);
        encryptEntry(i);
    }

    int entryNumber;
    printf("Enter the entry number to delete (1 to %d): ", entryCount);
    scanf("%d", &entryNumber);

    if (entryNumber < 1 || entryNumber > entryCount)
    {
        printf("Invalid entry number!\n");
        return;
    }

    for (int i = entryNumber - 1; i < entryCount - 1; i++)
    {
        strcpy(diary[i], diary[i + 1]);
    }

    entryCount--;
    saveEntries();
    printf("Entry %d deleted successfully.\n", entryNumber);
}

void deleteAllEntries()
{
    entryCount = 0;
    saveEntries();
    printf("All entries deleted successfully.\n");
}

void searchEntry()
{

}
