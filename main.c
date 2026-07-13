#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
typedef struct
{
    int id;
    char description[50];
    char category[20];
    float amount;
} Expense;
Expense list[MAX];
int count = 0;
float budget = 0;
void setBudget();
void addExpense();
void viewExpenses();
void statistics();
void saveToFile();

int main()
{
    int choice;

    printf("Hello! Welcome to your Personal Expense Tracker.\n");

    do
    {
        printf("\n=======================================\n");
        printf("                 MENU\n");
        printf("=======================================\n");
        printf("1. Set Total Budget\n");
        printf("2. Add Expense\n");
        printf("3. View All Expenses\n");
        printf("4. Statistical Analysis\n");
        printf("5. Save & Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            setBudget();
            break;
        case 2:
            addExpense();
            break;
        case 3:
            viewExpenses();
            break;
        case 4:
            statistics();
            break;
        case 5:
            saveToFile();
            printf("Data saved. Goodbye!\n");
            break;
        default:
            printf("Invalid choice!\n");
        }
    }
    while (choice != 5);

    return 0;
}

void setBudget()
{
    printf("Enter your total monthly budget: ");
    scanf("%f", &budget);
    printf("Budget set to %.2f\n", budget);
}

void addExpense()
{
    if (count >= MAX)
    {
        printf("Storage full!\n");
        return;
    }

    int catChoice;
    printf("\n--- Select Category ---\n");
    printf("1. Food\n2. Study Materials\n3. Others\n");
    printf("Enter choice: ");
    scanf("%d", &catChoice);

    Expense e;
    e.id = count + 1;

    printf("Enter description: ");
    scanf(" %49[^\n]", e.description);

    if (catChoice == 1)
        strcpy(e.category, "Food");
    else if (catChoice == 2)
        strcpy(e.category, "Study Materials");
    else
        strcpy(e.category, "Others");

    printf("Enter amount: ");
    scanf("%f", &e.amount);

    list[count] = e;
    count++;

    printf("Expense added! (Total entries: %d)\n", count);
}

void viewExpenses()
{
    if (count == 0)
    {
        printf("No expenses recorded yet.\n");
        return;
    }

    printf("\n%-5s%-20s%-15s%-10s\n", "ID", "Description", "Category", "Amount");
    for (int i = 0; i < count; i++)
    {
        printf("%-5d%-20s%-15s%-10.2f\n",
               list[i].id, list[i].description, list[i].category, list[i].amount);
    }
}

void statistics()
{
    if (count == 0)
    {
        printf("No data available.\n");
        return;
    }

    float total = 0, foodTotal = 0, studyTotal = 0, otherTotal = 0;

    for (int i = 0; i < count; i++)
    {
        total += list[i].amount;

        if (strcmp(list[i].category, "Food") == 0)
            foodTotal += list[i].amount;
        else if (strcmp(list[i].category, "Study Materials") == 0)
            studyTotal += list[i].amount;
        else
            otherTotal += list[i].amount;
    }

    float average = total / count;

    printf("\n--- Statistical Analysis ---\n");
    printf("Total Expenses       : %.2f\n", total);
    printf("Number of Entries    : %d\n", count);
    printf("Average per Entry    : %.2f\n", average);
    printf("Food Total           : %.2f\n", foodTotal);
    printf("Study Materials Total: %.2f\n", studyTotal);
    printf("Others Total         : %.2f\n", otherTotal);

    if (budget > 0)
    {
        printf("Budget Set           : %.2f\n", budget);
        printf("Remaining Balance    : %.2f\n", budget - total);
    }
}

void saveToFile()
{
    FILE *fp = fopen("expenses.csv", "w");
    if (fp == NULL)
    {
        printf("Error saving file.\n");
        return;
    }

    for (int i = 0; i < count; i++)
    {
        fprintf(fp, "%d,%s,%s,%.2f\n",
                list[i].id, list[i].description, list[i].category, list[i].amount);
    }

    fclose(fp);
}
