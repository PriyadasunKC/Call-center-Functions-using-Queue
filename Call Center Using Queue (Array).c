#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10

int front = -1;
int rear = -1;
int queue[MAX_SIZE];

void addCustomer()
{
    if (rear == MAX_SIZE - 1)
    {
        printf("\nQueue is full. Cannot add more calls.\n");
    }
    else
    {
        if (front == -1)
        {
            front = 0;
        }
        rear++;
        int callTime = rand() % 10 + 1;
        int callID = rand() % 90000 + 10000;
        queue[rear] = callTime;
        printf("New customer added to the queue\n");
        printf("- Customer ID: %d \n- Call Duration: %d minute(s)\n", callID, callTime);
    }
}

void removeCustomer()
{
    if (front == -1 || front > rear)
    {
        printf("\nQueue is empty. No calls to Remove.\n");
    }
    else
    {
        printf("\nCall with Customer ID %d is removed from the queue.\n", front + 1);
        front++;
    }
}

void displayCustomerList()
{
    if (front == -1 || front > rear)
    {
        printf("\nQueue is empty. No calls to display.\n");
    }
    else
    {
        printf("\nCalls in the queue:\n");
        for (int i = front; i <= rear; i++)
        {
            printf("Call ID: %d, Time: %d minute(s)\n", rand() % 90000 + 10000, queue[i]);
        }
    }
}

int main()
{
    srand(time(NULL));
    int operation;

    while (1)
    {
        printf("\n-- Welcome to Call Center --\n\n");
        printf("- Press 1 : Add a new customer call to the queue.\n");
        printf("- Press 2 : Remove the customer call from the queue.\n");
        printf("- Press 3 : Display all the customer calls in the queue.\n");
        printf("- Press 4 : Exit\n\n");
        printf("Enter your choice : ");
        scanf("%d", &operation);
        switch (operation)
        {
        case 1:
            addCustomer();
            break;

        case 2:
            removeCustomer();
            break;

        case 3:
            displayCustomerList();
            break;

        case 4:
            printf("\nExiting the program...\n");
            break;

        default:
            printf("\nInvalid choice. Please enter a valid choice.\n");
        }
    }

    return 0;
}
