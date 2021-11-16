/*  Complete program of implementation and algorithms of
             singly linked list
                                -K.S.Ragavan
*/

/*
A singly linked list is a type of linked list that is unidirectional,
i.e it can be traversed in only one direction from head to the last node.
Each element in a linked list is called a node.
A single node contains data and a pointer to the next node which helps in maintaining the structure of the list.
*/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node  // implementing node of linked list
{
    int data;   // data part of the node
    struct node* next;  // pointer pointing to the next node of the linked list
}*head=NULL,*temp,*newnode;  // declaring 3 global variables to implement linked list

// head -> the first node of the linked list
// newnode -> temporary node created to attach new nodes during insertion
// temp -> node used for traversal purposes

void create(int); // to create new nodes in linked list
void insertlast(); // insert the created node in the last position
void deletelast(); // delete the last node of the linked list
bool search(int); // to search for a particular node using the value of the data
void display(); // to display the linked list
void insertfirst(); // to insert the created node at the first position
void insertafter(int); // to insert the node after a particular node using value of the node
void discard(int); // to delete a node in the list by entering the value of the node
void middlenode(); // to find the middle node of the linked list
void lasttofirst(); // to move the last node to the first position

void create(int data)
{
    newnode = (struct node*)malloc(sizeof(struct node)); // space for a new node is allocated in the memory
    newnode->data = data; // data sent as the argument is assigned as the data to the node created
    newnode->next = NULL; // next node doesn't exist hence the pointer is set to null.
}

void insertfirst()
{
    printf("Enter the number to be inserted at first: ");
    int key;
    scanf("%d",&key);
    if(head==NULL) //checks if the list exists initailly
    {
        create(key);
        head = (struct node*)malloc(sizeof(struct node));
        head = newnode; // created node is assigned to the head since the list doesn,t exist
                        // linked list is created
    }
    else
    {
        create(key);
        temp = newnode; // new node is assigned to the temp node
        temp->next = head; // the next pointer in the created node now points to the head node
        head = temp; // head node is now points to the newly created node making it the head node
    }
}

void insertafter(int data)
{
    printf("Enter the number to be inserted: ");
    int key;
    scanf("%d",&key);
    if(head==NULL)  // checks the existence of the list
    {
        create(key);
        head = (struct node*)malloc(sizeof(struct node));
        head = newnode;
    }
    else
    {
        temp=head;
        while(temp->data!=data&&temp->next!=NULL) // if the data the of the present node is the node instructed to instruct after
            temp=temp->next;
        create(key);
        struct node* temp1 = (struct node*)malloc(sizeof(struct node)); // new temporary node is created
        temp1 = newnode; // new created node is assigned to the newly created temporary node
        temp1->next = temp->next; // both the temporary nodes point to the same next node
        temp->next = temp1; // newly created temp node is pointed by the previous temp node
    }
}

void insertlast()
{
    printf("Enter the number to be inserted at last: ");
    int key;
    scanf("%d",&key);
    if(head==NULL)
    {
        create(key);
        head = (struct node*)malloc(sizeof(struct node));
        head = newnode;
    }
    else
    {
        create(key);
        temp = head;
        while(temp->next!=NULL) // searches for the last node
            temp = temp->next;
        temp->next = newnode; // attaching the created node to the end of the list
    }
}

void deletelast()
{
    temp = head;
    if(temp==NULL) // checks for the deletion condition
        printf("Stack Underflow\n");
    else if(temp->next==NULL) // if only one node exists in the list
    {
        free(temp); // frees the memory space of the node
        head = NULL;
    }
    else // if multiple nodes exist in the list
    {
        while(temp->next->next!=NULL)
            temp=temp->next;
        free(temp->next);
        temp->next=NULL;
    }
}

void discard(int data)
{
    if(search(data)) // checks for the existence of the node i.e to be deleted
    {
        if(head == NULL)
        {
            printf("List doesn't exist to delete.\n");
        }
        else
        {
            temp = head;
            if(temp->data==data)
            {
                head = head->next;
                free(temp);
                return;
            }
            while(temp!=NULL)
            {
                if(temp->next->data==data)
                {
                    struct node* temp1 = (struct node*)malloc(sizeof(struct node));
                    temp1 = temp->next;
                    temp->next = temp1->next;
                    free(temp1);
                    return;
                }
                temp = temp->next;
            }
        }
    }
    else
    {
        printf("Data entered doesn't exist in the list.\n");
    }
}

void middlenode()
{
    if(head==NULL)
    {
        printf("List doesn't exist.\n");
        return;
    }
    else
    {
        int count=0; // keeps the number of nodes in the list
        temp=head;
        while(temp!=NULL)
        {
            count++;
            temp = temp->next;
        } // count is now updated with the number of the nodes in the list
        temp=head;
        for(int i=0;i<count/2;i++)
            temp=temp->next; // middle node is found and arrived
        printf("The middle node is %d.\n",temp->data);
    }
}

void display()
{
    temp = head;
    while(temp!=NULL) // traversing the list till the end
    {
        if(temp->next!=NULL)
            printf("%d ",temp->data);
        else
            printf("%d\n",temp->data);
        temp = temp->next;
    }
}

bool search(int key)
{
    temp = head;
    while(temp!=NULL)
    {
        if(temp->data==key)
            return true; // if key value exists in the list
        temp = temp->next;
    }
    return false; // if not
}

void lasttofirst()
{
    if(head==NULL)
    {
        printf("List doesn't exist\n");
        return;
    }
    else if(head->next==NULL)
        return;
    else
    {
        temp = head;
        while(temp->next->next!=NULL)
            temp=temp->next;
        struct node* temp1 = (struct node*)malloc(sizeof(struct node)); // new node is temporarily created to keep track of the last node
            temp1 = temp->next; //last node assigned to the created node
        temp->next=temp1->next;  // null being assigned to the penultimate node making it the final node
        temp1->next = head; // inserting the last node as the first node
        head = temp1; // assigning the last node as the first node
    }
}

int main()
{
    printf("\t\t\tMENU BAR!!!\n"); // to guide user through various functions of the list
    printf("1. Insert Element at last\n");
    printf("2. Insert Element at first\n");
    printf("3. Insert Element after a specific element\n");
    printf("4. Delete Element at last\n");
    printf("5. Delete a specific Element\n");
    printf("6. Display\n");
    printf("7. Search\n");
    printf("8. Finding the Middle Node\n");
    printf("9. Move Last node to first place\n");
    int choice;
    printf("Enter your choice: ");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
            insertlast();
            break;
        case 2:
            insertfirst();
            break;
        case 3:
            {
                int key;
                printf("After which element should the new element be inserted: ");
                scanf("%d",&key);
                insertafter(key);
            }
            break;
        case 4:
            deletelast();
            break;
        case 5:
            {
                int key;
                printf("Which element should be deleted: ");
                scanf("%d",&key);
                discard(key);
            }
            break;
        case 6:
            display();
            break;
        case 7:
        {
            printf("Enter element to be searched for: ");
            int key;
            scanf("%d",&key);
            if(search(key))
                printf("%d is found.\n",key);
            else
                printf("%d is not found.\n",key);
        }
        break;
        case 8:
            middlenode();
            break;
        case 9:
            lasttofirst();
            break;
        default:
            printf("Invalid input found!!!\n");
    }
    printf("Do you want to continue[Y/N]: ");
    char control;
    scanf(" %c",&control);
    if(control=='y'||control=='Y')
    {
        system("pause");
        system("cls");
        main();
    }
    return 0;
}
