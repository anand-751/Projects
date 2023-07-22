#include <iostream>

class Node {
public:
    int data;
    Node* next;

    Node(int data) : data(data), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    // Function to insert a node at the beginning of the linked list
    void insertNode(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
        std::cout << "Node inserted successfully.\n";
    }

    // Function to display the linked list
    void displayList() {
        if (head == nullptr) {
            std::cout << "List is empty.\n";
        } else {
            Node* temp = head;
            while (temp != nullptr) {
                std::cout << temp->data << " ";
                temp = temp->next;
            }
            std::cout << "\n";
        }
    }

    // Function to update a node in the linked list
    void updateNode(int oldData, int newData) {
        if (head == nullptr) {
            std::cout << "List is empty.\n";
        } else {
            Node* temp = head;
            while (temp != nullptr) {
                if (temp->data == oldData) {
                    temp->data = newData;
                    std::cout << "Node updated successfully.\n";
                    return;
                }
                temp = temp->next;
            }
            std::cout << "Node not found.\n";
        }
    }

    // Function to delete a node from the linked list
    void deleteNode(int data) {
        if (head == nullptr) {
            std::cout << "List is empty.\n";
        } else {
            Node* temp = head;
            Node* prev = nullptr;
            while (temp != nullptr) {
                if (temp->data == data) {
                    if (prev == nullptr) {
                        head = temp->next;
                    } else {
                        prev->next = temp->next;
                    }
                    delete temp;
                    std::cout << "Node deleted successfully.\n";
                    return;
                }
                prev = temp;
                temp = temp->next;
            }
            std::cout << "Node not found.\n";
        }
    }

    // Function to make the linked list cyclic by connecting the last node to the specified node
    void makeCyclic(int position) {
        if (head == nullptr) {
            std::cout << "List is empty.\n";
            return;
        }

        Node* temp = head;
        Node* cyclicNode = nullptr;
        int count = 1;
        while (temp->next != nullptr) {
            if (count == position) {
                cyclicNode = temp;
            }
            temp = temp->next;
            count++;
        }

        if (cyclicNode != nullptr) {
            temp->next = cyclicNode;
            std::cout << "List has been made cyclic.\n";
        } else {
            std::cout << "Invalid position. Unable to make the list cyclic.\n";
        }
    }

    // Function to detect and check if the linked list contains a cycle
    bool detectCycle() {
        if (head == nullptr) {
            std::cout << "List is empty.\n";
            return false;
        }

        Node* slow = head;
        Node* fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                return true; // Cycle detected
            }
        }

        return false; // No cycle detected
    }

    void removeCycle() {
        if (head == nullptr) {
            std::cout << "List is empty.\n";
            return;
        }

        Node* slow = head;
        Node* fast = head;
        Node* prev = nullptr;

        while (fast != nullptr && fast->next != nullptr) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                // Cycle detected, remove the cycle
                slow = head;
                while (slow != fast) {
                    prev = fast;
                    slow = slow->next;
                    fast = fast->next;
                }

                prev->next = nullptr;
                std::cout << "Cycle removed successfully.\n";
                return;
            }
        }

        std::cout << "No cycle found in the list.\n";
    }

    bool search(int value) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data == value) {
                return true; // Value found
            }
            temp = temp->next;
        }
        return false; // Value not found
    }

    void insertNodeAtPosition(int data, int position) {
        Node* newNode = new Node(data);
        if (position <= 0) {
            std::cout << "Invalid position. Node insertion failed.\n";
            return;
        }
        if (position == 1) {
            newNode->next = head;
            head = newNode;
            std::cout << "Node inserted successfully.\n";
            return;
        }

        Node* temp = head;
        int count = 1;
        while (temp != nullptr && count < position - 1) {
            temp = temp->next;
            count++;
        }
        if (temp == nullptr) {
            std::cout << "Invalid position. Node insertion failed.\n";
            return;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        std::cout << "Node inserted successfully.\n";
    }

};

int main() {
    LinkedList linkedList;

    int choice, data, oldData, newData, position,searchValue;

    while (true) {
        std::cout << "Linked List CRUD Operations\n";
        std::cout << "1. Insert a node\n";
        std::cout << "2. Display the list\n";
        std::cout << "3. Update a node\n";
        std::cout << "4. Delete a node\n";
        std::cout << "5. Make the list cyclic\n";
        std::cout << "6. Cycle detection\n";
        std::cout << "7. Remove the cycle from the list\n";
        std::cout << "8. Search for a value\n";
        std::cout << "9. Insert your node at any position\n";
        std::cout << "10. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;


        switch (choice) {
            case 1:
                std::cout << "Enter data to insert: ";
                std::cin >> data;
                linkedList.insertNode(data);
                break;
            case 2:
                linkedList.displayList();
                break;
            case 3:
                std::cout << "Enter the old data value: ";
                std::cin >> oldData;
                std::cout << "Enter the new data value: ";
                std::cin >> newData;
                linkedList.updateNode(oldData, newData);
                break;
            case 4:
                std::cout << "Enter data to delete: ";
                std::cin >> data;
                linkedList.deleteNode(data);
                break;
            case 5:
                std::cout << "Enter the position of the node to connect for creating a cycle: ";
                std::cin >> position;
                linkedList.makeCyclic(position);
                break;
            case 6:
                if (linkedList.detectCycle()) {
                    std::cout << "The list contains a cycle.\n";
                } else {
                    std::cout << "The list does not contain a cycle.\n";
                }
                break;
            case 7:
                linkedList.removeCycle();
                break;
            case 8:
                std::cout << "Enter the value to search: ";
                std::cin >> searchValue;
                if (linkedList.search(searchValue)) {
                    std::cout << "Value found in the list.\n";
                } else {
                    std::cout << "Value not found in the list.\n";
                }
                break;

            case 9:
                std::cout << "Enter the data to insert: ";
                std::cin >> data;
                std::cout << "Enter the position to insert the node: ";
                std::cin >> position;
                linkedList.insertNodeAtPosition(data, position);
                break;

            case 10:
                std::cout << "Exiting...\n";
                exit(0);
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
