#include "StrList.h"
#include <stdio.h>
#include <string.h>

#define MEMORY_ALLOCATION_ERROR "Error: couldn't allocate memory!"
#define INCORRECT_INDEX_ERROR "Error: incorrect index!"

/*
 * StrList represents a StrList data structure.
 */

typedef struct _Node {
    char* data;
    struct _Node* next;
} Node;

typedef struct _StrList {
    Node* head;
    size_t size;        // ASK: can i store the size of it?
} StrList;

/*
 * Allocates a new empty StrList.
 * It's the user responsibility to free it with StrList_free.
 * Returns a pointer to the allocated list or NULL if allocation failed.
 */
StrList* StrList_alloc(){
    StrList* strList = NULL;
    strList = (StrList*)malloc(sizeof(StrList));

    if (strList == NULL) {
        printf("%s\n", MEMORY_ALLOCATION_ERROR);
    }
    strList->head = NULL;
    strList->size = 0;

    return strList;        // returns NULL if allocation failed
}

/*
 * Frees the memory and resources allocated to StrList.
 * If StrList==NULL does nothing (same as free).
 */
void StrList_free(StrList* strList){
    // Frees the list and all its nodes
    if (strList != NULL) {
        Node *p = strList->head;
        Node *temp = p;

        while (p != NULL){
            temp = p;
            p = p->next;
            if (temp->data != NULL)
                free(temp->data);
            free(temp);
        }
        free (strList);
    }
}

/*
 * Returns the number of elements in the StrList.
 */
size_t StrList_size(const StrList* strList){
    return strList->size;
}

/*
 * Inserts an element in the end of the StrList.
 */
void StrList_insertLast(StrList* strList, const char* data){
    if (strList == NULL) {
        strList = StrList_alloc();
    }

    // TODO: duplicated code -> make func

    // Create a new node
    Node *temp = NULL;
    temp = (Node*)malloc(sizeof(Node));
    if (temp == NULL){
        printf("%s\n", MEMORY_ALLOCATION_ERROR);
        return;
    }

    temp->data = (char*)malloc(sizeof(char) * (strlen(data) + 1));
    if (temp->data == NULL) {
        printf("%s\n", MEMORY_ALLOCATION_ERROR);
        return;
    }
    strcpy(temp->data, data);

    // TODO: END OF duplicated code -> make func

    /* If strList->head in NULL - this is the first node.
        else - find the last node and insert in there */
    if (strList->head == NULL){
        strList->head = temp;
        temp->next = NULL;
    }
    else {
        Node *p = strList->head;
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = temp;
        temp->next = NULL;
    }
    strList->size++;
}

/*
* Inserts an element at given index
    assuming the index is valid
*/
void StrList_insertAt(StrList* strList, const char* data,int index){
    // ASK: do i need to check these conditions? if index is out of bound, etc.
    if (index > strList->size || index < 0){
        printf("%s\n", INCORRECT_INDEX_ERROR);
        return;
    }

    // TODO: duplicated code -> make func

    // Create a new node
    Node *temp = NULL;
    temp = (Node*)malloc(sizeof(Node));
    if (temp == NULL){
        printf("%s\n", MEMORY_ALLOCATION_ERROR);
        return;
    }

    temp->data = (char*)malloc(sizeof(char) * (strlen(data) + 1));
    if (temp->data == NULL) {
        printf("%s\n", MEMORY_ALLOCATION_ERROR);
        return;
    }
    strcpy(temp->data, data);

    // TODO: END OF duplicated code -> make func

    if (index == 0){
        // If another node exists after the head, set it as temp's next, else, set temp's next to NULL
        if (strList->head->next != NULL){
            temp->next = strList->head;
        }
        else{
            temp->next = NULL;
        }
        strList->head = temp;
    }
    else {
        Node *p = temp;
        // TODO 2: kind of repeated code - get node at index
        int count = 0;
        // Go through list until the node before the desired index is reached
        while (count < index-1) {
            p = p->next;
            count++;
        }
        // "Push" temp between these 2 nodes - in desired index
        temp->next = p->next;
        p->next = temp;
    }

    strList->size++;
}


/*
 * Returns the StrList first data.
 */
char* StrList_firstData(const StrList* strList){
    if (strList != NULL && strList->head != NULL)
        return strList->head->data;
    return 0;
}

/*
 * Prints the StrList to the standard output.
 */
void StrList_print(const StrList* strList){
    Node *p = NULL;
    if (strList != NULL) {
        p = strList->head;
    }
    while (p != NULL){
        if (p->data != NULL) {
            printf("%s ", p->data);
        }
        p = p->next;
    }
    printf("\n");
}

/*
 Prints the word at the given index to the standard output.
*/
void StrList_printAt(const StrList* strList,int index){
    // TODO 2: kind of repeated code - get node at index
    // ASK: do i need to check these conditions? if index is out of bound, etc.
    if (index > strList->size || index < 0){
        printf("%s\n", INCORRECT_INDEX_ERROR);
        return;
    }
    // Go through list until the node at the desired index is reached
    Node *p = NULL;
    if (strList != NULL){
        p = strList->head;
    }
    int count = 0;
    while (count != index && p != NULL) {
        p = p->next;
        count++;
    }
    // If p != null???
    printf("%s\n", p->data);
}

/*
 * Return the amount of chars in the list.
*/
int StrList_printLen(const StrList* strList) {
    int count = 0;
    Node *p = NULL;
    if (strList != NULL){
        p = strList->head;
    }
    while (p != NULL){
        count += strlen(p->data) + 1;         // length of curr data + a space
        p = p->next;
    }
    return count - 1;       // remove last space
}

/*
Given a string, return the number of times it exists in the list.
*/
int StrList_count(StrList* strList, const char* data){
    // ASK: exists as a whole in one data string? or can it also exist as a substring inside a data string?
    // I assume it's the whole data that needs to be this string
    Node *p = NULL;
    if (strList != NULL){
        p = strList->head;
    }
    int count = 0;
    while (p != NULL){
        if (!strcmp(p->data, data)){      // strcmp returns 0 when they are equal so we added '!'
            count++;
        }
        p = p->next;
    }
    return count;
}

/*
	Given a string and a list, remove all the appearences of this string in the list.
*/
void StrList_remove(StrList* strList, const char* data){
    Node *p = NULL;
    if (strList != NULL){
        p = strList->head;
    }
    // Deal with the head of the list - If the string match - the list needs to change its head
    while (p != NULL && p->data != NULL && !strcmp(p->data, data)){
        strList->head = p->next;
        free(p->data);
        free(p);
        p = strList->head;   
        strList->size--;
    }
    // Head is not the string, go through the list now
    Node *temp = NULL;
    if (p != NULL){
        temp = p;
        p = p->next;
    }
    while (p != NULL && p->data != NULL){
        if (!strcmp(p->data, data)){
            temp->next = p->next;

            // TODO 4: func to free node (data aswell)???
            free(p->data);
            free(p);
            p = temp->next;
            strList->size--;
        }
        else{
            p = p->next;
            temp = temp->next;
        }
    }
}

/*
	Given an index and a list, remove the string at that index.
*/
void StrList_removeAt(StrList* strList, int index){
    // ASK: do i need to check these conditions? if index is out of bound, etc.
    if (index > strList->size || index < 0){
        printf("%s\n", INCORRECT_INDEX_ERROR);
        return;
    }
    int count = 0;
    Node *p = NULL;
    if (strList != NULL){
        p = strList->head;
    }

    // Go through list until the node before the desired index is reached
    while (count < index-1 && p != NULL){
        count++;
        p = p->next;
    }

    Node *temp = p->next;
    p->next = p->next->next;
    if (temp != NULL){
        if (temp->data != NULL){
            free (temp->data);
        }
        free (temp);
    }
    strList->size--;
}

/*
 * Checks if two StrLists have the same elements
 * returns 0 if not and any other number if yes
 */
int StrList_isEqual(const StrList* strList1, const StrList* strList2){
    if (strList1->size != strList2->size){
        return 0;
    }

    Node *p1 = NULL;
    Node *p2 = NULL;
    if (strList1 != NULL){
        p1 = strList1->head;
    }
    if (strList2 != NULL){
        p2 = strList2->head;
    }

    while (p1 != NULL && p2 != NULL){
        // TODO: So many check for nulls, is this correct? do I need to check so much?
        if (p1->data != NULL && p2->data != NULL && strcmp(p1->data, p2->data)){
            return 0;
        }
        p1 = p1->next;
        p2 = p2->next;
    }

    return 1;
}

/*
 * Clones the given StrList. 
 * It's the user responsibility to free it with StrList_free.
 */
StrList* StrList_clone(const StrList* strList){
    if (strList == NULL){
        return NULL;
    }
    StrList *clonedList = StrList_alloc();
    Node *p = NULL;
    p = strList->head;
    // TODO: so many checks for null!!!
    if (clonedList != NULL) {
        StrList_insertAt(clonedList, p->data, 0);
        p = p->next;
    }
    return clonedList;
}

/*
 * Reverces the given StrList. 
 */
void StrList_reverse( StrList* strList){
    // We will use 3 pointers, each iteration we will "change the direction" of the "next" pointer
    

}

/*
 * Sort the given list in lexicographical order 
 */
void StrList_sort( StrList* strList);

/*
 * Checks if the given list is sorted in lexicographical order
 * returns 1 for sorted,   0 otherwise
 */
int StrList_isSorted(StrList* strList);
