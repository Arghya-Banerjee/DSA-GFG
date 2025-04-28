//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    struct Node* bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};

void printList(Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->bottom;
    }
    printf("\n");
}

Node* createLinkedList(vector<Node*>& v) {
    Node* head = new Node(0);
    Node* temp = head;
    int n = v.size();
    for (int i = 0; i < n; i++) {
        temp->next = v[i];
        temp = temp->next;
    }
    return head->next;
}


// } Driver Code Ends

/* Node structure  used in the program

struct Node{
    int data;
    struct Node * next;
    struct Node * bottom;

    Node(int x){
        data = x;
        next = NULL;
        bottom = NULL;
    }

};
*/

class Solution {
  private:
    Node* merge(Node* h1, Node* h2) {
        if(!h1) return h2;
        if(!h2) return h1;
        Node* dummy = new Node(-1);
        Node* head = dummy;
        while(h1 && h2) {
            if(h1->data <= h2->data) {
                dummy->bottom = h1;
                h1 = h1->bottom;
                dummy = dummy->bottom;
            }
            else {
                dummy->bottom = h2;
                h2 = h2->bottom;
                dummy = dummy->bottom;
            }
        }
        while(h1) {
            dummy->bottom = h1;
            dummy = dummy->bottom;
            h1 = h1->bottom;
        }
        while(h2) {
            dummy->bottom = h2;
            dummy = dummy->bottom;
            h2 = h2->bottom;
        }
        return head->bottom;
    }
    
  public:
    // Function which returns the  root of the flattened linked list.
    Node *flatten(Node *root) {
        // Your code here
        if(!root) return root;
        Node* mergedHead = flatten(root->next);
        Node* merged = merge(root, mergedHead);
        return merged;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n;
        cin >> n;
        cin.ignore();

        vector<Node*> v(n);

        for (int i = 0; i < n; i++) {
            string line;
            getline(cin, line);
            stringstream ss(line);

            Node* head = new Node(0);
            Node* temp = head;
            int x;
            while (ss >> x) {
                Node* newNode = new Node(x);
                temp->bottom = newNode;
                temp = temp->bottom;
            }
            v[i] = head->bottom;
        }

        Solution ob;
        Node* list = createLinkedList(v);
        Node* head = ob.flatten(list);
        printList(head);
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends