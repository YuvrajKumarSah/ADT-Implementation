// #include <stdio.h>
// #include <stdlib.h>
// void main()
// {
//     struct node 
//     {int data;
//     struct node* next;


//     };

//     struct node* head;
//     struct node *newnode;
//     struct node *temp;
//     head =0;
//     int choice;
//     while(choice){
//         newnode=(struct node*)malloc(sizeof(struct node));
//         printf("Enter data");
//         scanf("%d,&newnode->data");
//         newnode->next=0;
//         if(head==0){
//             head=temp=newnode;
//         }
//         else{
//             temp->next=newnode;
//             temp=newnode;
//         }
//         printf("do you want to continue(0,1)?");
//         scanf("%d",&choice);

//     }
//     temp=head;
//     while(temp!=0)
//     {
//         printf("%d", temp->data);
//         temp=temp->next;
//     }
//     getch();
// }


#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

int main() {
    struct node* head = NULL;
    struct node* newnode;
    struct node* temp;
    int choice = 1; // Initialize choice to 1 to enter the loop

    while (choice) {
        newnode = (struct node*)malloc(sizeof(struct node));
        if (newnode == NULL) {
            printf("Memory allocation failed\n");
            return 1;
        }

        printf("Enter data: ");
        scanf("%d", &newnode->data); // Corrected: removed extra comma and fixed address operator
        newnode->next = NULL;

        if (head == NULL) {
            head = temp = newnode;
        } else {
            temp->next = newnode;
            temp = newnode;
        }

        printf("Do you want to continue (0, 1)? ");
        scanf("%d", &choice);
    }

    temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data); // Added space for better readability
        temp = temp->next;
    }

    // Clean up dynamically allocated memory
    temp = head;
    while (temp != NULL) {
        struct node* to_free = temp;
        temp = temp->next;
        free(to_free);
    }

    return 0; // Use return 0 for main function instead of getch()
}
