#include <iostream>

using namespace std;

struct Node {
    int data;
    Node *next;
};

class list {
    public:
        Node *root;
        int size;
        list();
        void show();
        void append(int);
        void insert(int, int);
        void remove(int);
        void swap(int, int);
};

list::list() {
    root = NULL;
    size = 0;
}

void list::show() {
    Node *current = root;
    while (current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

void list::append(int data) {
    Node *new_node = new Node;
    new_node->data = data;
    new_node->next = NULL;
    if (root == NULL) {
        root = new_node;
    } else {
        Node *current = root;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
    size++;
}

void list::insert(int index, int data) {
    if (index < 0 || index > size) {
        cout << "Index out of range" << endl;
        return;
    }
    Node *new_node = new Node;
    new_node->data = data;
    if (index == 0) {
        new_node->next = root;
        root = new_node;
    } else {
        Node *current = root;
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }
    size++;
}

void list::remove(int index) {
    if (index < 0 || index >= size) {
        cout << "Index out of range" << endl;
        return;
    }
    if (index == 0) {
        Node *temp = root;
        root = root->next;
        delete temp;
    } else {
        Node *current = root;
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }
        Node *temp = current->next;
        current->next = temp->next;
        delete temp;
    }
    size--;
}

void list::swap(int index1, int index2) {
    if (index1 < 0 || index1 >= size || index2 < 0 || index2 >= size) {
        cout << "Index out of range" << endl;
        return;
    }
    Node *current1 = root;
    for (int i = 0; i < index1; i++) {
        current1 = current1->next;
    }
    Node *current2 = root;
    for (int i = 0; i < index2; i++) {
        current2 = current2->next;
    }
    int temp = current1->data;
    current1->data = current2->data;
    current2->data = temp;
}


int main() {
    list l;
    l.append(1);
    l.append(2);
    l.append(3);
    l.append(4);
    l.append(5);
    l.show();
    l.swap(0, 4);
    l.show();
    l.swap(1, 3);
    l.show();
    l.swap(2, 2);
    l.show();
    l.swap(0, 5);
    l.show();
    l.swap(-1, 0);
    l.show();
    return 0;
}