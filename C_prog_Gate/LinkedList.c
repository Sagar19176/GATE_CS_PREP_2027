#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};

void printList(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void insertAtBeginning(struct Node **Head)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter data: ");
    scanf("%d", &newNode->data);
    newNode->next = *Head;
    *Head = newNode;
}

void insertAtEnd(struct Node **Head)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter data: ");
    scanf("%d", &newNode->data);
    newNode->next = NULL;

    if (*Head == NULL)
    {
        *Head = newNode;
    }
    else
    {
        struct Node *temp = *Head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void createNode(struct Node **headRef)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter data: ");
    scanf("%d", &newNode->data);
    newNode->next = NULL;

    if (*headRef == NULL)
    {
        *headRef = newNode;
    }
    else
    {
        struct Node *temp = *headRef;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void deleteAtStart(struct Node **head)
{
    struct Node *temp = *head;
    if(temp == NULL)
    return;

    *head = (*head)->next;
    temp->next = NULL;
    free(temp);

}

void printMid(int n,struct Node *head)
{
    struct Node *ptr = head;

    int mid = 0;
    if(n%2 == 0){
        mid = (n/2) +1;
    }else{
        mid = (n+1)/2;
    }
    int count=1;
    while(ptr != NULL){
        if(count == mid){
            printf("Mid Value:%d\n", ptr->data);
            break;
        }
        ptr = ptr->next;
        count++;
        
    }
}

void printMid2(int n,struct Node *head)
{
    struct Node *ptr = head;

    if(n == 0) return;
    for(int i=1;i<(n/2);i++){
        ptr = ptr->next;
    }
    printf("Middle Node:%d\n",ptr->next->data);
}

void deleteAtLast(struct Node **head)
{
    struct Node *ptr = *head;

    if(ptr == NULL)return;
    if(ptr->next == NULL){
        deleteAtStart(head);
        return; 
    }

    while(ptr->next->next != NULL){
        ptr = ptr->next;
    }
    free(ptr->next);
        ptr->next = NULL;

}

struct Node *mergeSortedList(struct Node *ptr1,struct Node *ptr2)
{
    struct Node *first,*last;
    if(ptr1 == NULL) return ptr2;
    if(ptr2 == NULL) return ptr1;

    if(ptr1->data < ptr2->data){
            first = last = ptr1;
            ptr1 = ptr1->next;
    }else{
            first = last = ptr2;
            ptr2 = ptr2->next;
    }

    while(ptr1 !=NULL && ptr2 != NULL){
        if(ptr1->data < ptr2->data){
            last->next = ptr1;
            last = ptr1;
            ptr1 = ptr1->next;
        }else{
            last->next = ptr2;
            last = ptr2;
            ptr2 = ptr2->next;
        }
    }

    if(ptr1 != NULL){
        last->next = ptr1;
    }else{
        last->next = ptr2;
    }

    return first;
}

void intersectionPoint(struct Node *Head1,struct Node *Head2)
{
    struct Node *cptr1,*cptr2, *ptr1,*ptr2;

    if(Head1 == NULL || Head2 == NULL) return;

    cptr1=ptr1 = Head1;
    cptr2=ptr2 = Head2;

    int count1=0;
    int count2=0;


    while (cptr1 != NULL)
    {
        count1++;
        cptr1 = cptr1->next;
    }
    while (cptr2 != NULL)
    {
        count2++;
        cptr2 = cptr2->next;
    }


    int diff = abs(count1 - count2);

    if(count1 < count2){
        for(int i=1;i<=diff;i++){
            ptr2 = ptr2->next;
        }
    }

    if(count1 > count2){
        for(int i=1;i<=diff;i++){
            ptr1 = ptr1->next;
        }
    }


    while(ptr1 !=NULL && ptr2 != NULL){
        if(ptr1 == ptr2){
            printf("Intersection at Node: %d\n",ptr1->data);
            return;
        }
        ptr1= ptr1->next;
        ptr2=ptr2->next;
    }

    printf("No Intersection found");

}

void createDynamicIntersection(struct Node* Head1, struct Node* Head2, int targetIndex)
 {
    if (Head1 == NULL || Head2 == NULL) return ;

    struct Node* targetNode = Head1;
    int currentPos = 0;

    // 1. Find the exact node in List 1 where we want to intersect
    while (targetNode != NULL && currentPos < targetIndex) {
        targetNode = targetNode->next;
        currentPos++;
    }

    // If targetIndex is larger than List 1's length, we can't intersect
    if (targetNode == NULL) {
        printf("Target index out of bounds. No intersection created.\n");
        return ;
    }

    // 2. Traverse to the very end of List 2
    struct Node* lastNode2 = Head2;
    while (lastNode2->next != NULL) {
        lastNode2 = lastNode2->next;
    }

    // 3. Connect List 2's tail to List 1's target node
    lastNode2->next = targetNode;
}


int main()
{
    struct Node *Head1 = NULL;
    struct Node *Head2 = NULL;
    struct Node *MergedHead = NULL;

    int n;
    printf("How many nodes you want to insert in list1:\n");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        createNode(&Head1);
    }
    int m;
    printf("How many nodes you want to insert in list2:\n");
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        createNode(&Head2);
    }

    printf("\nList 1: ");
    printList(Head1);

    printf("\nList 2: ");
    printList(Head2);
    
    createDynamicIntersection(Head1,Head2,2);
    printList(Head2);

    intersectionPoint(Head1,Head2);

    //MergedHead = mergeSortedList(Head1,Head2);

    //printf("Merged Sorted List: \n");
    //printList(MergedHead);

    return 0;
}