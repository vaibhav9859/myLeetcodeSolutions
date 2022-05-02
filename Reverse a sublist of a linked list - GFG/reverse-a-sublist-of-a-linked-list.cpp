// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};


 // } Driver Code Ends
//User function Template for C++

/*Link list node 
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};*/

class Solution
{
    public:
    
    void addNode(Node* nodeToAdd, Node* &th, Node* &tt){
        if(!th) th = tt = nodeToAdd;
        else{
            nodeToAdd->next = th;
            th = nodeToAdd;
        }
    }
    
    void rev(Node* head, Node* &th, Node* tt){
        Node* cur = head;
        
        while(cur){
            Node* forw = cur->next;
            cur->next = NULL;
            addNode(cur, th, tt);
            cur = forw;
        }
    }
    
    Node* reverseBetween(Node* head, int m, int n)
    {
        //code here
        if(m==n) return head;
        
        Node * first = new Node(-1); Node* second = new Node(-1); Node* third = new Node(-1);
        
        Node* cur = head; first->next = head;
        
        for(int i=1; i<=n; i++){
            if(i==1 and m==1){
                second->next = cur;
                first->next = NULL;
            }
            
            if(i+1 == m){
                second->next = cur->next;
                cur->next = NULL;
                cur = second->next;
                continue;
            }
            
            if(i == n){
                third->next = cur->next;
                cur->next = NULL;
                break;
            }
            
            cur = cur->next;
        }
        
        Node* th = NULL; Node* tt = NULL;
        rev(second->next, th, tt);
        
        cur = first;
        
        while(cur->next){
            cur = cur->next;
        }
        
        cur->next = th;
        
        cur = th;
        while(cur->next){
            cur = cur->next;
        }
        
        cur->next = third->next;
        
        // tt->next = third->next;
        
        return first->next;
    }
};

// { Driver Code Starts.

/* Function to print linked list */
void printList(struct Node *head)
{
	struct Node *temp = head;
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
}



// Driver program to test above functions
int main()
{
	int T;
	cin >> T;

	while (T--)
	{
		int N, m, n;
		cin >> N>>m>>n;

		Node *head = NULL;
		Node *temp = head;

		for (int i = 0; i < N; i++) {
			int data;
			cin >> data;
			if (head == NULL)
				head = temp = new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}

		

        Solution ob;

		Node* newhead = ob.reverseBetween(head, m, n);
		printList(newhead);

		cout << "\n";



	}
	return 0;
}
  // } Driver Code Ends