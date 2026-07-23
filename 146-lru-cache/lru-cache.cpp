struct Node {
    int key;
    int data;
    Node* next;
    Node* prev;
    Node(int k, int d) : key(k), data(d), next(nullptr), prev(nullptr) {}
};

class DLL {
private:
    Node* head;
    Node* tail;
    int size;
public:
    DLL() : head(nullptr), tail(nullptr), size(0) {}
    void remove(Node* n) {
        if (n == nullptr) return;
        else {
            if (n->prev) {
                n->prev->next = n->next;
            }
            else head = n->next;
            if (n->next) {
                n->next->prev = n->prev;
            }
            else tail = n->prev;
            delete n;
            size--;
        }
    }
    void push_front(int key, int data) {
        Node* n = new Node(key, data);
        if(head) {
            n->next = head;
            head->prev = n;
            head = n;
        }
        else head = tail =  n;
        size++;
    }
    Node* read_head() const {
        return head;
    }
    Node* read_tail() const {
        return tail;
    }
    int read_size() const {
        return size;
    }
    ~DLL() {
        while (head) {
            Node* n = head;
            head = head->next;
            delete n;
        }
    }
};

class LRUCache {
private:
    DLL lru;
    std::unordered_map<int, Node*> map;
    int c;
public:
    LRUCache(int capacity) {
        this->c = capacity;
    }
    
    int get(int key) {
        if (this->map.count(key)) {
            int val = map[key]->data;
            this->lru.remove(map[key]);
            this->lru.push_front(key, val);
            this->map[key] = this->lru.read_head();
            return val;
        }
        else return -1;
    }
    
    void put(int key, int value) {
        if (this->map.count(key)) { 
            this->lru.remove(map[key]);
            this->lru.push_front(key, value);
            this->map[key] = this->lru.read_head();
        }
        else {
            int size = this->lru.read_size(); 
            if (size < this->c) {
                this->lru.push_front(key, value);
                this->map[key] = this->lru.read_head();
            }
            else {
                Node* t = this->lru.read_tail();
                this->map.erase(t->key);
                this->lru.remove(this->lru.read_tail());
                this->lru.push_front(key, value);
                this->map[key] = this->lru.read_head();
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */