class LRUCache {
private:
    struct Node{
        int key;
        int val;
        Node*next;
        Node*prev;
        Node(int key_,int val_):key(key_), val(val_), next(nullptr), prev(nullptr) {}
    };
public:
    Node*dummyhead=new Node(-1,-1);
    Node*dummytail=new Node(-1,-1);
    int cap;
    unordered_map<int,Node*> mp;
    LRUCache(int capacity) {
        cap=capacity;
        dummyhead->next=dummytail;
        dummytail->prev=dummyhead;
    }

    void addafterhead(Node*node){
        node->next=dummyhead->next;
        dummyhead->next->prev=node;
        dummyhead->next=node;
        node->prev=dummyhead;
    }

    void deletenode(Node*node){
        node->prev->next=node->next;
        node->next->prev=node->prev;
    }
    
    int get(int key) {
        if(mp.find(key)!=mp.end()){
            Node*usednode=mp[key];
            int res=usednode->val;
            
            mp.erase(key);
            deletenode(usednode);
            addafterhead(usednode);
            
            mp[key]=dummyhead->next;
            return res;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            Node*temp=mp[key];
            mp.erase(key);
            deletenode(temp);
        }
        
        if(mp.size()==cap){
            mp.erase(dummytail->prev->key);
            deletenode(dummytail->prev);
        }
        Node*newnode=new Node(key,value);
        addafterhead(newnode);
        mp[key]=newnode;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */