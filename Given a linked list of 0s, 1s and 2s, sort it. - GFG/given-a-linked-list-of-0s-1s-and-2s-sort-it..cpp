// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
/* Link list Node */
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node *start = NULL;


 // } Driver Code Ends
/*
 
  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        
        // Add code here
        Node* cur = head;
        Node* zeroStart = new Node(-1); Node* zeroEnd = zeroStart;
        Node* firstStart = new Node(-1); Node* firstEnd = firstStart;
        Node* secondStart = new Node(-1); Node* secondEnd = secondStart;
        
        while(cur){
            if(cur->data == 0){
                zeroEnd->next = cur; zeroEnd = zeroEnd->next;
            }
            else if(cur->data == 1){
                firstEnd->next = cur; firstEnd = firstEnd->next;
            }
            else{
                secondEnd->next = cur; secondEnd = secondEnd->next;
            }
            
            cur = cur->next;
        }
        
        secondEnd->next = NULL;
        firstEnd->next = secondStart->next;
        zeroEnd->next = firstStart->next;
        
        return zeroStart->next;
    }
};


// { Driver Code Starts.

// Function to sort a linked list of 0s, 1s and 2s
void printList(struct Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
void insert(int n1) {
    int n, value, i;
    // scanf("%d",&n);
    n = n1;
    struct Node *temp;
    for (i = 0; i < n; i++) {
        scanf("%d", &value);

        if (i == 0) {
            start = new Node(value);
            temp = start;
            continue;
        } else {
            temp->next = new Node(value);
            temp = temp->next;
            temp->next = NULL;
        }
    }
}

int main() {

    int n;

    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        insert(n);
        Solution ob;
        struct Node *newHead = ob.segregate(start);
        printList(newHead);
    }

    return 0;
}  // } Driver Code Ends