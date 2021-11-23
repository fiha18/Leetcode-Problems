class MyCircularQueue {
     final int[] a;
     int head,tail,len;
    public MyCircularQueue(int k) {
        a = new int[k];
        tail = -1;
        len = 0;
    }
    
    public boolean enQueue(int value) {
        if(!isFull())
        {
            tail = (tail + 1) % a.length;
            a[tail] = value;
            len++;
            return true;
        }
        else
            return false;
    }
    
    public boolean deQueue() {
        if(!isEmpty())
        {
            head = (head+1) % a.length;
            len--;
            return true;
        }
        else
            return false;
    }
    
    public int Front() {
        if(isEmpty())
        {return -1;}
        else
           return a[head];
    }
    
    public int Rear() {
        if(isEmpty())
        {return -1;}
        else
        {return a[tail];}
    }
    
    public boolean isEmpty() {
        return len == 0;
    }
    
    public boolean isFull() {
        return len == a.length;
    }
}