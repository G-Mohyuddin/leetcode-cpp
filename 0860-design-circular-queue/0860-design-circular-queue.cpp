class MyCircularQueue {
public:
    int size;
    int front=-1;
    int rear=-1;
    vector<int> queue;
    MyCircularQueue(int k) {
        size=k;
        queue.resize(k);
    }
    
    bool enQueue(int value) {
        if((rear+1)%size==front){
            return false;
        }else if(isEmpty()){
            front=rear=0;
            queue[rear]=value;
            return true;
        }else{
            rear=(rear+1)%size;
            queue[rear]=value;
            return true;
        }
    }
    
    bool deQueue() {
        if(isEmpty()){
            return false;
        }else if(front==rear){
            front=rear=-1;
            return true;
        }else{
            front=(front+1)%size;
            return true;
        }
    }
    
    int Front() {
        if(isEmpty()){
            return -1;
        }else{
            return queue[front];
        }
    }
    
    int Rear() {
        if(isEmpty()){
            return -1;
        }else{
            return queue[rear];
        }
    }
    
    bool isEmpty() {
        if(front==-1 && rear==-1){
            return true;
        }else{
            return false;
        }
    }
    
    bool isFull() {
        if((rear+1)%size==front){
            return true;
        }else{
            return false;
        }
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