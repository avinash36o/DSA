#include <iostream>
#include <unordered_map>
using namespace std;

class LRUCache {
    class Node{
    public:
        int key;    
        int val;
        Node* next;
        Node* prev;
            Node(int k, int v){
                this->key=k;
                this->val=v;
                next=prev=NULL;
            }
    };

    class LL{
        public:
        Node* head;
        Node* tail;
            LL(){
                head=NULL;
                tail=NULL;
            }
    };

 
public:  
    unordered_map<int, Node*>m;
    int capacity;
    LRUCache(int capacity) {
        this->capacity=capacity;
    }
    
    int get(int key) {
        return m.count(key) ? m[key]->val : -1;
    }
    
    void put(int key, int value) {
        LL ll;
        if(!m.count(key)){ //not exist in map
            if(m.size()<capacity){
                Node* newNode=new Node(key,value);
                newNode->prev=NULL;
                newNode->next=ll.head;
                ll.head->prev=newNode;
                ll.head=newNode;
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