class Node{
public:
    int key;
    int val;
    Node* prev;
    Node* next;

    Node(int key, int val){
        this->key = key;
        this->val = val;
        this->prev = NULL;
        this->next = NULL;
    }
};

class LRUCache {
public:
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);
    int cap;
    unordered_map<int, Node*> keyPtrMap;

    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(keyPtrMap.find(key) == keyPtrMap.end()) return -1;
        int ans = keyPtrMap[key]->val;
        moveToFront(keyPtrMap[key]);
        return ans;
    }
    
    void put(int key, int value) {
        if(keyPtrMap.find(key) != keyPtrMap.end()){
            changeAlreadyPresent(key, value);
        } 
        else {
            if(keyPtrMap.size() == cap){
                eraseValue();
            }

            Node* newNode = new Node(key, value);
            keyPtrMap[key] = newNode;


            newNode->next = head->next;
            newNode->prev = head;
            head->next->prev = newNode;
            head->next = newNode;
        }
    }

    void eraseValue(){
        Node* toDelete = tail->prev;
        tail->prev = tail->prev->prev;
        tail->prev->next = tail;
        keyPtrMap.erase(toDelete->key);
    }

    void changeAlreadyPresent(int key, int value){ 
        keyPtrMap[key]->val = value;
        moveToFront(keyPtrMap[key]);
    }

    void moveToFront(Node* nodeToMove){
        nodeToMove->prev->next = nodeToMove->next;
        nodeToMove->next->prev = nodeToMove->prev;

        //connect on front
        nodeToMove->next = head->next;
        head->next->prev = nodeToMove;
        nodeToMove->prev = head;
        head->next = nodeToMove;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */