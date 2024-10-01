class AllOne {
public:
    struct Node {
        int count; // stores the freq
        list<string> keys;
        Node* prev;
        Node* next;

        Node(int f) {
            count = f;
            prev = NULL;
            next = NULL;
        }
    };

    unordered_map<string, Node*> mp;

    Node* head; // head-> next stores the first pointer value
    // Node* first; // points to first node (getMinKey)
    Node* last; // points to last node (getMaxKey)

    // function to addNode
    void addNode(Node* prevNode, int count) {
        Node* newNode = new Node(count); // initialization of new node
        newNode->next = prevNode->next;
        newNode->prev = prevNode;
        // if there is another node after prevNode (we are inserting in between)
        if (prevNode->next != NULL) {
            prevNode->next->prev =
                newNode; // updating prev pointer the another node which is
                         // after prevNode before insertion
        }

        prevNode->next = newNode;

        // updating last pointer
        if (prevNode == last) {
            // update it to newNode
            last = newNode;
        }
    }

    // function to remove pointer
    void removeNode(Node* node) {
        node->prev->next = node->next;
        if (node->next != NULL) {
            node->next->prev = node->prev;
        }

        // checking lastNode
        if (last == node) {
            last = node->prev;
        }

        delete (node);
    }

    AllOne() {
        head = new Node(0);
        last = head; // initially alst will be at head only
    }

    void inc(string key) {
        // if there is no entry in map for that particular string
        if (mp.find(key) == mp.end()) {
            // not exists
            // we check if there exists a node for 1 count if not we create it
            if (head->next == NULL || head->next->count != 1) {
                addNode(head, 1); // func that add nodes with 1 count
                // head->next = newNode
            }

            // there is already a node with 1 count
            head->next->keys.push_back(key); // pushing in thr node(list)

            // updating in map
            mp[key] = head->next;
        } else {
            // entry is present in mp
            Node* currNode =
                mp[key]; // will sends us the node where it is present
            int currCount = currNode->count;

            // checking for node with +1 freq and if not we create it
            if (currNode->next == NULL ||
                currNode->next->count != currCount + 1) {
                addNode(currNode,
                        currCount + 1); // create a node next to currNode with
                                        // freq + 1 from it
            }

            // now assigning the new key
            currNode->next->keys.push_back(key);

            // updating the map to new Node
            mp[key] = currNode->next;

            // removing the key from our currNode
            currNode->keys.remove(key);

            // now if currNode is empty toh we have to delete it
            if (currNode->keys.empty()) {
                removeNode(currNode); // this func will remove currNode
            }
        }
    }

    void dec(string key) {
        Node *curNode = mp[key];
        int curCount = curNode->count;
        
        // Remove the key if count becomes zero
        curNode->keys.remove(key);
        if (curCount == 1) {
            mp.erase(key);
        } else {
            // Move it to the previous count
            if (curNode->prev == head || curNode->prev->count != curCount - 1) {
                addNode(curNode->prev, curCount - 1);
            }
            curNode->prev->keys.push_front(key);
            mp[key] = curNode->prev;
        }
        
        // Remove the current node if it has no more keys
        if (curNode->keys.empty()) {
            removeNode(curNode);
        }
    }

    string getMaxKey() { return (last == head) ? "" : last->keys.front(); }

    string getMinKey() {
        return (head->next == nullptr) ? "" : head->next->keys.front();
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
