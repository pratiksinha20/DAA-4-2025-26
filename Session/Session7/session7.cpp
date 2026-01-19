#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    // Insert at beginning
    void insertAtBeg(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    // Insert at end
    void insertAtEnd(int val) {
        Node* newNode = new Node(val);

        if (head == nullptr) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Insert at position
    void insertAtPosition(int val, int position) {
        if (position == 1) {
            insertAtBeg(val);
            return;
        }

        Node* temp = head;
        for (int i = 1; i < position - 1 && temp != nullptr; i++) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Position out of range!\n";
            return;
        }

        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Delete at beginning
    void DelAtBeg() {
        if (head == nullptr) {
            cout << "List is empty!\n";
            return;
        }

        Node* temp = head;
        head = head->next;
        delete temp;
    }

    // Delete at end
    void DelAtEnd() {
        if (head == nullptr) {
            cout << "List is empty!\n";
            return;
        }

        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }

        Node* temp = head;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = nullptr;
    }

    // Delete at position
    void DelAtPos(int pos) {
        if (pos == 1) {
            DelAtBeg();
            return;
        }

        Node* temp = head;
        for (int i = 1; i < pos - 1 && temp != nullptr; i++) {
            temp = temp->next;
        }

        if (temp == nullptr || temp->next == nullptr) {
            cout << "Position out of range!\n";
            return;
        }

        Node* toDelete = temp->next;
        temp->next = toDelete->next;
        delete toDelete;
    }

    // Display list
    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    LinkedList list;

    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    cout << "After inserting at end: ";
    list.display();

    list.insertAtBeg(5);
    cout << "After inserting at beginning: ";
    list.display();

    list.insertAtPosition(15, 3);
    cout << "After inserting 15 at position 3: ";
    list.display();

    list.DelAtBeg();
    cout << "After deleting at beginning: ";
    list.display();

    list.DelAtEnd();
    cout << "After deleting at end: ";
    list.display();

    list.DelAtPos(2);
    cout << "After deleting at position 2: ";
    list.display();

    return 0;
}
