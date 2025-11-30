#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node* prev;
    Node(int val){
    data=val;
    prev=nullptr;
    next=nullptr;
}
};
class Doublylinklist{
    private:
    Node* head;
    public:
    Doublylinklist(){
        head=nullptr;
    }
    void insertatbeginning(int data){
        Node* newnode=new Node(data);
        head=newnode;
        if(head!=nullptr){
            newnode->next=head;
            head->prev=newnode;
        }
head=newnode;
cout<<"inserted "<<data<<"at beginning"<<endl;
        }
        void insertatend(int data){
             Node* newnode=new Node(data);
             if(head==nullptr){
                head=newnode;

             }
             else{
                Node* temp=head;
                while(temp->next!=nullptr){
                    temp=temp->next;
                }
                temp->next=newnode;
                newnode->prev=temp;
                newnode->next=nullptr;
                
             }
             cout<<"inserted "<<data<<"at end";

        }
        void insertatpos(int pos,int data){
            if(pos<=0){
                cout<<"invalid position";
                return;

            }
            else if(pos==1){
                insertatbeginning(data);
                return;
            }
            Node* newnode=new Node(data);
            Node* temp=head;
            while(temp!=nullptr){
                for(int i=0;i<pos-1;i++){
                    temp=temp->next;
                }
            }
          if(temp==nullptr){
            cout<<"invalid position"<<endl;
            return;
          }
          newnode->next=temp->next;

newnode->prev=temp;
if(temp->next!=nullptr){
    temp->next->prev=newnode;

temp->next=newnode;
}
cout<<"inserted "<<data<<"at position"<<pos;

}
void display(){
    if(head==nullptr){
        cout<<"list is empty"<<endl;
    }
    Node*temp=head;
    while(temp!=nullptr){
        cout<<temp->data;
        temp=temp->next;
    }
    
}
};
int main(){
  
        Doublylinklist dll;
    int choice, data, pos;

    while (true) {
        cout << "\n- Doubly Linked List Menu \n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert at Position\n";
        cout << "4. Display List\n";
        cout << "5. Exit\n";
        cout << "Enter your choice (1-5): ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter data to insert at beginning: ";
                cin >> data;
                dll.insertatbeginning(data);
                break;

            case 2:
                cout << "Enter data to insert at end: ";
                cin >> data;
                dll.insertatend(data);
                break;

            case 3:
                cout << "Enter data to insert: ";
                cin >> data;
                cout << "Enter position to insert at: ";
                cin >> pos;
                dll.insertatpos(data, pos);
                break;

            case 4:
                dll.display();
                break;

            case 5:
                cout << "Exiting...\n";
                return 0;

            default:
                cout << "Invalid choice. Please try again.\n";
        }
}

            }
        

