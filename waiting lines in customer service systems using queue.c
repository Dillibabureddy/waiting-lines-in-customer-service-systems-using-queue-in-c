#include <stdio.h>
#include <stdlib.h>

// Define a structure for a call
struct Call {
    int callID;               // Unique ID for each call
    char callerName[50];      // Name of the caller
};

// Define a structure for a node in the call queue
struct Node {
    struct Call data;         // Call data stored in the node
    struct Node* next;       // Pointer to the next node
};

// Define the call queue
struct Queue {
    struct Node* front;      // Front of the queue
    struct Node* rear;       // Rear of the queue
};

// Initialize an empty queue
void initQueue(struct Queue* queue) {
    queue->front = NULL;
    queue->rear = NULL;
}

// Check if the queue is empty
int isEmpty(struct Queue* queue) {
    return queue->front == NULL;
}

// Enqueue a call into the queue
void enqueue(struct Queue* queue, struct Call call) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); // Create a new node
    newNode->data = call;     // Set the data in the new node
    newNode->next = NULL;    // Initialize the next pointer

    if (isEmpty(queue)) {
        queue->front = newNode;  // If the queue is empty, set the front to the new node
        queue->rear = newNode;   // Set the rear to the new node
    } else {
        queue->rear->next = newNode; // Otherwise, add the new node to the rear
        queue->rear = newNode;       // Update the rear pointer to the new node
    }

    printf("Call with ID %d added to the queue.\n", call.callID);
}

// Dequeue a call from the queue
void dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. No calls to dequeue.\n");
    } else {
        struct Node* temp = queue->front;   // Get the front node
        queue->front = queue->front->next;  // Update the front pointer
        printf("Call with ID %d has been dequeued.\n", temp->data.callID); // Display dequeued call information
        free(temp);  // Free the memory of the dequeued node
    }
}

int main() {
    struct Queue callQueue;
    initQueue(&callQueue);

    int choice;
    struct Call newCall;
    newCall.callID = 1; // Initialize the call ID

    while (1) {
        printf("\nCall Management System\n");
        printf("1. Enqueue a call\n");
        printf("2. Dequeue a call\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter caller name: ");
                scanf("%s", newCall.callerName); // Input caller name
                enqueue(&callQueue, newCall);    // Enqueue the call
                newCall.callID++;                // Increment the call ID for the next call
                break;
            case 2:
                dequeue(&callQueue);             // Dequeue a call
                break;
            case 3:
                printf("Exiting the program.\n");
                exit(0);                          // Exit the program
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}