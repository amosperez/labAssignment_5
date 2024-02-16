// Amos Perez
// 02/09/24

#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    char letter;
    struct node* next;
} node;
// Returns number of nodes in the linkedList.
int length(node* head)
{
    int numOfNodes = 0;

    if(head == NULL){printf("Head is NULL."); exit(1);}
    while(head->next != NULL){
        numOfNodes++;
        head = head->next;
    }

    return numOfNodes;
}


// parses the string in the linkedList
// if the linked list is head -> |a|->|b|->|c|
// then toCString function wil return "abc"
char* toCString(node* head)
{


    char* the_string = (char*) malloc(((length(head))*sizeof(node))+1);
    //*(the_string+length(head)+1) = '\0';

    //char* string_pointer = the_string;
    node* temp = head;
    int i = 0;

    for(i ; i<length(head)+1; i++){
       // *(the_string+i) = *string_pointer;
        //string_pointer++;
        the_string[i]=temp->letter;
        temp = temp->next;
    }
    the_string[i] = '\0';
    return the_string;
}


// inserts character to the linkedlist
// f the linked list is head -> |a|->|b|->|c|
// then insertChar(&head, 'x') will update the linked list as foolows:
// head -> |a|->|b|->|c|->|x|
void insertChar(node** pHead, char c)
{
    node* newNode = (node*) malloc(sizeof(node));
    if(newNode == NULL){printf("malloc failed!"); exit(1);}
    newNode->letter = c;
    newNode->next = NULL;

    node* current = *pHead;


    if (*pHead==NULL){
        *pHead = newNode;
    } else {
        while(current->next != NULL){
            current = current->next;
        }
        current->next = newNode;
    }
}


// deletes all nodes in the linkedList.
void deleteList(node** pHead)
{
    node* current;

    if(*pHead != NULL){
        while((*pHead)->next != NULL){
            current = (*pHead)->next;
            free(*pHead);
            *pHead = current;
        }
        *pHead = NULL;

    }
}


int main(void)
{
    int i, strLen, numInputs;
    node* head = NULL;
    char* str;
    char c;


    FILE* inFile = fopen("input.txt","r");
    fscanf(inFile, " %d\n", &numInputs); /* What is the purpose of &numInputs here? */


    while (numInputs-- > 0) /* numInputs is the number of lines in the file? So, run until numInputs is less than 0. Until theres is no more lines. */
    {
        fscanf(inFile, " %d\n", &strLen); /* This is the string length */

        for (i = 0; i < strLen; i++) /* Run for each letter */
        {
            fscanf(inFile," %c", &c); /* Get the character */
            insertChar(&head, c); /* Create the node with the character */
        }

        str = toCString(head); /* Now that we have the our linked list with each character on the current line, traverse the list and return a string. */

        printf("String is : %s\n", str);

        free(str);

        deleteList(&head);

        if (head != NULL)
        {
            printf("deleteList is not correct!");
            break;
        }
    }


    fclose(inFile);

}
