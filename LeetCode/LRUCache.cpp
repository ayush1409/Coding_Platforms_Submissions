class LRUCache {
public:
    int capacity ;
    int currentSize ;
    
    class element{
        public :
            int key ;
            int val ;
        
            element *next = NULL, *prev = NULL ;
        
            element(int k, int v) : key(k), val(v) {}
    } ;
    
    element *head, *tail ;
    unordered_map<int, element*> umap ;
    
    LRUCache(int capacity) {
        this -> capacity = capacity ;
        this -> currentSize = 0 ;
        head = NULL ;
        tail = NULL ;
    }
    
    int get(int key) {
        if(umap.empty())
            return -1 ;
        
        auto it = umap.find(key) ;
        
        if(it != umap.end()){
            // make the node it as head
            element *curr = it -> second ;
            if(curr == head)
                return curr -> val ;
            if(curr == tail)
                tail = curr -> prev ;
            
            
            // curr -> prev can only be null when curr is the head node
            curr -> prev -> next = curr -> next ;
            if(curr -> next != NULL){
                curr -> next -> prev = curr -> prev ;
            }
            curr -> prev = NULL ;
            curr -> next = NULL ;
            
            head -> prev = curr ;
            curr -> next = head ;
            head = curr ;
            return head -> val ; 
        }
        else
            return -1 ;
    }
    
    void put(int key, int value) {
        
        if(!umap.empty() && umap.find(key) != umap.end()){
            auto currEle = umap.find(key) ;
            element *currNode = currEle -> second ;
            
            currNode -> val = value ;
            // make the new node as head
            if(currNode == head)
                return ;
            if(currNode == tail)
                tail = currNode -> prev ;
            
            currNode -> prev -> next = currNode -> next ;
            if(currNode -> next != NULL)
                currNode -> next -> prev = currNode -> prev ;
            
            currNode -> prev = NULL ;
            currNode -> next = NULL ;
            
            currNode -> next = head ;
            head -> prev = currNode ;
            head = currNode ;
            
            return ;
        }
        else if(this -> currentSize == 0){
            head = new element(key, value) ;
            tail = head ;
            umap.insert({key, head}) ;
            this -> currentSize += 1 ;
            return ;
        }
        
        else if(this -> capacity > this -> currentSize){
                this -> currentSize += 1 ;
                // add new element
                element *newEle = new element(key, value) ;
                umap.insert({key, newEle}) ;

                // make the new node as head
                head -> prev = newEle ;
                newEle -> next = head ;
                head = newEle ;
            
        }
        else{
            // evict element
            element *temp = tail ;
            auto it = umap.find(tail -> key) ;
            umap.erase(it) ;
            
            tail = tail -> prev ;
            if(tail != NULL){
                tail -> next = NULL ;
                // add new element
                element *newEle = new element(key, value) ;
                umap.insert({key, newEle}) ;
        
                // make the new node as head
                head -> prev = newEle ;
                newEle -> next = head ;
                head = newEle ;
            }
            else{
                // that means capacity = 1 and currentSize = 0
                head = new element(key, value) ;
                tail = head ;
                umap.insert({key, head}) ;
            }
            delete temp ;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */