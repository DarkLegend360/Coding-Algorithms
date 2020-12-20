#include <bits/stdc++.h>
using namespace std;

class DLL {
    public:
    string key;
    int value;
    DLL *next,*prev;
    DLL(string key,int value) {
        this->key=key;
        this->value=value;
        this->next=NULL;
        this->prev=NULL;
    }
};

class LRUCache {
    public:
    int maxSize;
    int curSize;
    DLL *head = new DLL("Head",-1);
    DLL *tail = new DLL("TAIL",-1);
    unordered_map<string,DLL*> cache;
    LRUCache(int maxSize) { 
        this->maxSize = maxSize > 1 ? maxSize : 1;
        this->head->next=tail;
        this->tail->prev=head;
        this->curSize=0;
    }

    void addNodeToHead(DLL *node) {
        node->next=head->next;
        head->next->prev=node;
        node->prev=head;
        head->next=node;
    }

    void evictNodeFromTail() {
        this->cache.erase(tail->prev->key);
        tail->prev->prev->next=tail;
        tail->prev=tail->prev->prev;
    }

    void updateNode(string key,int value) {
        DLL *node = this->cache[key];
        node->prev->next=node->next;
        node->next->prev=node->prev;
        node->value=value;
        this->addNodeToHead(node);
    }

    void insertKeyValuePair(string key, int value) {
        if(this->cache.find(key)==this->cache.end()) {
            if(this->curSize==this->maxSize)
                this->evictNodeFromTail();
            else
                this->curSize++;
            this->cache[key]=new DLL(key,value);
            this->addNodeToHead(this->cache[key]);
        } else {
            this->updateNode(key,value);
        }
    }

    int *getValueFromKey(string key) {
        if(this->cache.find(key)==this->cache.end())
            return NULL;
        this->updateNode(key,this->cache[key]->value);
        return &this->cache[key]->value;
        
    }

    string getMostRecentKey() {
        if(this->head->next!=tail)
            return this->head->next->key;
        return "";
    }
};

int main() {
    LRUCache lruCache(3);
    lruCache.insertKeyValuePair("b", 2);
    lruCache.insertKeyValuePair("a", 1);
    lruCache.insertKeyValuePair("c", 3);
    cout<<(lruCache.getMostRecentKey() == "c")<<endl;
    cout<<(*lruCache.getValueFromKey("a") == 1)<<endl;
    cout<<(lruCache.getMostRecentKey() == "a")<<endl;
    lruCache.insertKeyValuePair("d", 4);
    cout<<(lruCache.getValueFromKey("b") == 0)<<endl;
    lruCache.insertKeyValuePair("a", 5);
    cout<<(*lruCache.getValueFromKey("a") == 5)<<endl;
    return 0;
}