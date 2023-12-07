#include <iostream>
using namespace std;

class Node{
    public:
        int val;
        Node* next;

        Node( int data){ //Constructor initializes the value of the Node elements val and next.
            val = data;
            next = NULL;
        }
};

void insertAtHead(Node* &head, int val){ // inserting a new node at head
    Node* new_node = new Node(val);
    new_node->next = head;
    head = new_node;
}
    
void display( Node* head){ // Displaying the node
    Node* temp= head;
    while (temp != NULL){
        cout << temp->val <<" ";
        temp = temp->next;
    }
    cout << endl;
    //cout << "NULL" << endl;
}

Node* Reverse(Node* head){ // Reversing the node
    Node* current = head;
    Node* prev = NULL;
    Node* next;
    
    while (current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

int count(Node* head){ // To count the number of nodes present in the linked list
    Node* temp = head;
    int count=0;
    while (temp != NULL){
        count++;
        temp = temp->next;
    }
    return count;
}

void insertattail(Node* &head, int data){// adding an element at the end of the prior linked list
    Node* new_node = new Node(data);
    new_node->next = NULL;
    Node* temp = head;
    
    if (head == NULL){
        head = new_node;
    }
    else {
        while (temp->next != NULL){
            temp= temp->next;
        }
        temp->next = new_node;
    }   
}

Node* element(Node* head, int position){// to isolate a specific node in the list
    if (position < 0){
        return NULL;
    }
    Node* temp = head;
    int current =0;
    while( (temp != NULL) && (current < position)){
        temp = temp->next;
        current++;
    }
    return temp;
}

void insert_node(Node* &head, int position, int data){// Inserts a new node at any position.
    Node* temp;
    Node* temp2;
    Node* new_node = new Node(data);
    int current = 0;

    temp = head;
    while(current < position -1){ // "-1" is added to ensure the accuracy ss current begins from 0
        temp = temp->next;
        current++;
    }
    temp2 = temp->next;
    temp->next = new_node;
    new_node->next = temp2;
}

void delete_node(Node* &head, int position){ // to delete the specific node
    Node* temp = head;
    Node* prev;
    Node* current;

    int curr=0;
    if (position == 0){
        current = head->next;
        delete head;
        head = current;        
    }
    else{
        while( curr < position-1 ){ // "-1" is added because the curr starts from 0 and >>
        temp = temp->next;
        curr++;
    }
    prev = temp;        // >> prev = temp this makes the transversion of the linked list easy, for the temp can be equated to prev.
    current = temp->next;
    prev->next = current->next;
    delete current;
    }
}

int position_from_middle(Node* head, int position){// to display the value which is at kth position from the middle of the linked list towards the head
    Node* temp = head;
    int current = 0;

    while( current< count(head)/2 - position){
        temp = temp->next;
        current++;
    }
    if (position <= count(head)/2) return temp->val;
    else return 0;
}

int main(){
    Node* head = NULL;
    int i;

    for (i=1; i<=13; i++){
        if ((i%2) != 0){
            insertAtHead(head, i);
        }
    }
    cout << "The original list is: "<< endl;
    display(head);

    
    //reverse the node and display it.
    cout << "The reverse list is: "<< endl;
    display(Reverse(head));
    
    

    // counting the number of nodes
    cout << "The number of nodes present in the linked list is: "<< count(head)<<endl;
    

    // Adding the element at the end of the list
    cout << "Enter the element: ";
    int a;
    cin >> a;
    insertattail(head, a);
    display(head);
    

    // To display the element at the middle of the list    
    cout<<"The element at the middle of the list is: " << element(head, count(head)/2)->val <<endl;
    

    // To add a new node
    cout<<"Enter the value for the new node: ";
    int val;
    cin>>val;
    cout<<"Position?: ";
    int Position;
    cin >> Position;
    insert_node(head, Position-1, val);
    display(head);
    

    // To delete a specific node
    cout<<"Enter the position of node you want to delete: ";
    int position;
    cin >> position;
    delete_node(head, position-1);
    display(head);
    

    //to delete middle of the node
    delete_node(head, count(head)/2);
    display(head);
    

   // To display the value of the linked list at kth position from the middle of the linked list towards the head
   cout<<"The position is: ";
   //int position;
   cin >> position;
   cout<<"Position: "<< position<<endl;
   cout<<"Value: "<<position_from_middle(head, position);   
}