
class List{
  public: 
    int val;
    List* next;
    
    List(int data){
        this->val = data;
        this->next = nullptr;
    }
    
};


class MyCircularQueue {
public:
    
    List* list = new List(-1);
    List* tail = list;
    List* head = list;
    
    int size = 0, total = 0;
    
    MyCircularQueue(int k) {
        total = k;
    }
    
    bool enQueue(int value) {
        if(size == total) return false;
        
        tail->next = new List(value);
        tail = tail->next;
        size++;
        return true;
    }
    
    bool deQueue() {
        if(size == 0) return false;
        
        if(head->val == -1) head = head->next;
        
        head = head->next;
        size--;
        
        if(size == 0){
            list = new List(-1);
            head = list;
            tail = list;
        }
        
        return true;
    }
    
    int Front() {
        if(size == 0) return -1;
        
        if(head->val == -1) head = head->next;
        
        return head->val;
    }
    
    int Rear() {
        if(size == 0) return -1;
        
        return tail->val;
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == total;   
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */