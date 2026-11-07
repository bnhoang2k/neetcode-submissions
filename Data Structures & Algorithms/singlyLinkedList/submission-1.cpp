class Node {
    public:
        int data;
        Node* next;
        Node(int data = 0){
            this->data = data;
            next = nullptr;
        }
};

class LinkedList {
public:
    Node* head;
    int size;
    LinkedList() {
        head = nullptr; // initialize empty list
        size = 0;
    }

    int get(int index) {
        if (index < 0 || index >= size) {return -1;}
        Node* temp = head;
        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }
        return temp->data;
    }

    void insertHead(int val) {
        Node* temp = new Node(val);
        temp->next = head;
        head = temp;
        size += 1;
    }
    
    void insertTail(int val) {
        Node* temp = new Node(val);
        if(size==0) {
            head = temp;
            size += 1;
            return;
        }
        Node* travel = head;
        while (travel->next != nullptr) {
            travel = travel->next;
        }
        travel->next = temp;
        size += 1;
    }

    bool remove(int index) {
        if ((index < 0) || (index >= size)) {
            return false;
        }
        if (index == 0) {
            head = head->next;
            size -= 1;
            return true;
        }
        Node* temp = head;
        Node* prev = nullptr;
        for(int i = 0; i < index; i++){
            prev = temp;
            temp = temp->next;
        }
        prev->next = temp->next;
        size -= 1;
        return true;
    }

    vector<int> getValues() {
        vector<int> res;
        Node* temp = head;
        for(int i = 0; i < size; i++) {
            res.push_back(temp->data);
            temp = temp->next;
        }
        return res;
    }
};
