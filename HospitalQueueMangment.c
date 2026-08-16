#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50

struct Patient {
    int id;
    char name[50];
    char disease[50];
};

struct Patient queue[MAX];
int front = -1, rear = -1;
int patientID = 1;

// Check if queue is full
int isFull() {
    return rear == MAX - 1;
}

// Check if queue is empty
int isEmpty() {
    return front == -1 || front > rear;
}

// Add patient (enqueue)
void addPatient() {
    if (isFull()) {
        printf("Queue is full! Cannot add more patients.\n");
        return;
    }
    struct Patient p;
    p.id = patientID++;
    printf("Enter Patient Name: ");
    scanf(" %[^\n]", p.name);
    printf("Enter Disease: ");
    scanf(" %[^\n]", p.disease);

    if (front == -1) front = 0;
    queue[++rear] = p;
    printf("Patient added successfully!\n");
}

// Serve patient (dequeue)
void servePatient() {
    if (isEmpty()) {
        printf("No patients in queue!\n");
        return;
    }
    struct Patient p = queue[front++];
    printf("Serving Patient ID: %d, Name: %s, Disease: %s\n", p.id, p.name, p.disease);
}

// Show next patient
void nextPatient() {
    if (isEmpty()) {
        printf("No patients waiting!\n");
        return;
    }
    struct Patient p = queue[front];
    printf("Next Patient → ID: %d, Name: %s, Disease: %s\n", p.id, p.name, p.disease);
}

// Display all patients
void displayQueue() {
    if (isEmpty()) {
        printf("Queue is empty!\n");
        return;
    }
    printf("\n--- Current Queue ---\n");
    for (int i = front; i <= rear; i++) {
        printf("ID: %d, Name: %s, Disease: %s\n", queue[i].id, queue[i].name, queue[i].disease);
    }
}

int main() {
    int choice;
    while (1) {
        printf("\n--- Hospital Queue Menu ---\n");
        printf("1. Add Patient\n2. Serve Patient\n3. Next Patient\n4. Display Queue\n5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addPatient(); break;
            case 2: servePatient(); break;
            case 3: nextPatient(); break;
            case 4: displayQueue(); break;
            case 5: printf("Exiting...\n"); exit(0);
            default: printf("Invalid choice!\n");
        }
    }
}
