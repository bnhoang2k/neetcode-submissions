class Node {
public:
    int data;
    Node* next;

    Node(int data = 0) {
        this->data = data;
        next = nullptr;
    }
};

class LinkedList {
public:
    Node* head;
    int length;

    LinkedList() {
        // head = new Node();   // makes a fake node, so an "empty" list has 1 node
        head = nullptr;         // empty list = points at nothing
        length = 0;
    }

    int get(int index) {        // unchanged, this one was already right
        if (index >= length) return -1;
        Node* lol = head;
        for (int i = 0; i < index; i++) lol = lol->next;
        return lol->data;
    }

    void insertHead(int val) {
        // Node* newHead = new Node();   // ignored val
        Node* newHead = new Node(val);
        // newHead.next = head;          // newHead is a pointer, so use ->
        newHead->next = head;
        head = newHead;
        // size += 1;                    // no member called size, it's length
        length += 1;
    }

    void insertTail(int val) {
        Node* newTail = new Node(val);
        if (head == nullptr) {           // empty list: new node IS the head
            head = newTail;
            length += 1;
            return;
        }
        // Node lol = head;              // head is a Node*, so lol must be too
        Node* lol = head;
        while (lol->next != nullptr) lol = lol->next;
        // Node newTail = Node(val);     // local object, dies when function ends
        // lol->next = newTail;          // would store a dangling address
        lol->next = newTail;
        // size += 1;
        length += 1;
    }

    bool remove(int index) {
        // if (index >= size) ...        // size -> length
        if (index >= length) return false;
        if (index == 0) {                // no previous node, so move head
            Node* old = head;
            head = head->next;
            delete old;
            length -= 1;
            return true;
        }
        // for (int i = 0; i < size; i++) { prev = lol; lol = lol->next; }
        // that walked the whole list; you only need to reach the node BEFORE index
        Node* prev = head;
        for (int i = 0; i < index - 1; i++) prev = prev->next;
        Node* target = prev->next;
        prev->next = target->next;       // skip over target
        delete target;                   // give its memory back
        length -= 1;
        return true;
    }

    vector<int> getValues() {
        vector<int> res;
        // Node lol = head;
        Node* lol = head;
        // while (lol->next != nullptr)  // stops BEFORE the last node, skipping it
        while (lol != nullptr) {
            // res.pushback(lol->data);  // vector's method is push_back
            res.push_back(lol->data);
            lol = lol->next;
        }
        // you were also missing a return
        return res;
    }
};