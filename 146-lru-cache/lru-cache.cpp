class Node {
public:
    int key;
    int value;
    Node* prev;
    Node* next;

    Node(int k,int v) {
        key = k;
        value = v;
        prev = NULL;
        next = NULL;
    }
};

class LRUCache {

    unordered_map<int,Node*> mp;
    int cap;

    Node* head;
    Node* tail;

public:

    LRUCache(int capacity) {

        cap = capacity;

        head = new Node(-1,-1);
        tail = new Node(-1,-1);

        head->next = tail;
        tail->prev = head;
    }

    void deleteNode(Node* node) {

        Node* prevNode = node->prev;
        Node* nextNode = node->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    void insertAfterHead(Node* node) {

        Node* nextNode = head->next;

        head->next = node;
        node->prev = head;

        node->next = nextNode;
        nextNode->prev = node;
    }

    int get(int key) {

        if(mp.find(key) == mp.end()) {
            return -1;
        }

        Node* node = mp[key];

        deleteNode(node);
        insertAfterHead(node);

        return node->value;
    }

    void put(int key,int value) {

        if(mp.find(key) != mp.end()) {

            Node* node = mp[key];

            node->value = value;

            deleteNode(node);
            insertAfterHead(node);

            return;
        }

        if(mp.size() == cap) {

            Node* lru = tail->prev;

            mp.erase(lru->key);

            deleteNode(lru);
        }

        Node* newNode = new Node(key,value);

        mp[key] = newNode;

        insertAfterHead(newNode);
    }
};