class Node {
    public:
    int data;
    Node* next;
    
    Node(int data){
        this->data = data;
        next = nullptr;
    }
};

class LinkedList {
public:

    Node* head;
    int length = 0;

    LinkedList() {
        head = nullptr;
        length = 0;
    }

    int get(int index) {
        if(index >= length) {
            return -1;
        }
        Node* temp = head;
        for(int i = 0; i < index; i++) {
            temp = temp->next;
        }
        return temp->data;
    }

    void insertHead(int val) {
        Node* temp = new Node(val);
        if(length == 0) {
            head = temp;
            length += 1;
            return;
        }
        temp->next = head;
        head = temp;
        length += 1;
    }
    
    void insertTail(int val) {
        Node* temp = new Node(val);
        if(length == 0) {
            head = temp;
            length += 1;
            return;
        }
        Node* travel = head;
        while(travel->next != nullptr) {
            travel = travel->next;
        }
        travel->next = temp;
        length += 1;
    }

    bool remove(int index) {
        if (index < 0 || index >= length) {
            return false;
        }
        if (index == 0) {
            head = head->next;
            length -= 1;
            return true;
        }
        Node* prev = nullptr;
        Node* temp = head;
        for(int i = 0; i < index; i++) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = temp->next;
        length -= 1;
        return true;
    }

    vector<int> getValues() {
        vector<int> res;
        Node* temp = head;
        for(int i = 0; i < length; i++) {
            res.push_back(temp->data);
            temp = temp->next;
        }
        return res;
    }
};
