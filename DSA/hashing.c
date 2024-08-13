#include <stdio.h>
#define TABLE_SIZE 10
#define PRIME 7

int hashTable[TABLE_SIZE];

void insertKey()
{
    int i, key, hIndex, h1Key, h2Key;
    printf("\n ENter the element to insert");
    scanf("%d", &key);
    h1Key = key % TABLE_SIZE;
    h2Key = PRIME - (key % PRIME); //double hashing
    for (i = 0; i < TABLE_SIZE; i++)
    {
        hIndex = (h1Key + i * h2Key) % TABLE_SIZE; 
        if (hashTable[hIndex] == -1)
        {   
            hashTable[hIndex] = key;
            printf("\nkey inserted");
            return;
        }
    }
    printf("\n Insertion failed table full");
}
void deleteKey()
{
    int i, key, hIndex, hKey;
    printf("\n%d", "ENter the element to delete");
    scanf("%d", &key);
    hKey = key % TABLE_SIZE;
    for (i = 0; i < TABLE_SIZE; i++)
    {
        hIndex = (hKey + i) % TABLE_SIZE; // linear probing through the table
        if (hashTable[hIndex] == key)
        {
            printf("\n %d found at h[%d] location and is delelted", key, hIndex);
            hashTable[hIndex] = -1;
            return;
        }
    }
    printf("\n Key not found! Delete operation failed");
}

void searchKey()
{
    int i, key, hIndex, hKey;
    printf("\n%d", "ENter the element to search");
    scanf("%d", &key);
    hKey = key % TABLE_SIZE;
    for (i = 0; i < TABLE_SIZE; i++)
    {
        hIndex = (hKey + i) % TABLE_SIZE; // linear probing through the table
        if (hashTable[hIndex] == key)
        {
            printf("\n %d found at h[%d] location", key, hIndex);
            return;
        }
    }
    printf("\n Key not found!");
}
void display()
{
    printf("\n Hash table contents are: ");
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        printf("h[%d] = %d\n", i, hashTable[i]);
    }
}
int main()
{
    int i, choice;
    for (i = 0; i < TABLE_SIZE; i++)
    {
        hashTable[i] = -1;
    }

    while (1)
    {
        printf("1.INsert 2.Delte 3.Search 4.Display");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            insertKey();
            break;

        case 2:
            deleteKey();
            break;
        case 3:
            searchKey();
            break;
        case 4:
            display();
            break;
        default:
            return 0;
        }
    }
}