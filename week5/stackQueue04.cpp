class MyCircularQueue {
public:
    int size,capacity,front,rear;
    vector<int> qu;
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        size=0;
        capacity=k;
        front=0;
        rear=-1;
        qu.resize(k);
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if(size<capacity){
            rear=(rear+1)%capacity;
            qu[rear]=value;
            size++;
            return true;
        }
        return false;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if(size>0){
            front=(front+1)%capacity;
            size--;
            return true;
        }
        return false;
    }
    
    /** Get the front item from the queue. */
    int Front() {
        if(size>0)
            return qu[front];
        return -1;
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        if(size>0)
            return qu[rear];
        return -1;
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        if(size>0)
            return false;
        return true;
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        if(size==capacity)
            return true;
        return false;
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
