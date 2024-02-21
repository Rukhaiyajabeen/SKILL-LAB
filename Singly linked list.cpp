#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
 int data;
 struct Node *next;
} Node;
Node* createNode(int data) {
 Node *newNode = (Node*)malloc(sizeof(Node));
 newNode->data = data;
 newNode->next = NULL;
 return newNode;
}
void insertAtBeginning(Node **head, int data) {
 Node *newNode = createNode(data);
 newNode->next = *head;
 *head = newNode;
}
void insertAtMiddle(Node *prevNode, int data) {
 if (prevNode == NULL) {
 printf("Previous node cannot be NULL.\n");
 return;
 }
 Node *newNode = createNode(data);
 newNode->next = prevNode->next;
 prevNode->next = newNode;
}
void insertAtEnd(Node **head, int data) {
 Node *newNode = createNode(data);
 if (*head == NULL) {
 *head = newNode;
 return;
 }
 Node *lastNode = *head;
 while (lastNode->next != NULL) {
 lastNode = lastNode->next;
 }
 lastNode->next = newNode;
}
void deleteNode(Node **head, int key) {
 Node *temp = *head, *prev = NULL;
 if (temp != NULL && temp->data == key) {
 *head = temp->next;
 free(temp);
 return;
 }
 while (temp != NULL && temp->data != key) {
 prev = temp;
 temp = temp->next;
 }
 if (temp == NULL) return;
 prev->next = temp->next;
 free(temp);
}
void printLinkedList(Node *head) {
 while (head != NULL) {
 printf("%d ", head->data);
 head = head->next;
 }
 printf("\n");
}
int main() {
 Node *head = NULL;
 insertAtEnd(&head, 1);
 insertAtBeginning(&head, 2);
 insertAtBeginning(&head, 3);
 insertAtEnd(&head, 4);
 insertAtMiddle(head->next, 5);
 printf("Linked List after insertions: ");
 printLinkedList(head);
 deleteNode(&head, 3);
 printf("Linked List after deletion: ");
 printLinkedList(head);
 return 0;
}
