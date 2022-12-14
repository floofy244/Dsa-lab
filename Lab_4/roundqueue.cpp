#include<bits/stdc++.h>
using namespace std;

class Queue
{

 int rear, front;
 int size;
 int *arr;
public:
 Queue(int s)
 {
 front = rear = -1;
 size = s;
 arr = new int[s];
 }

 void enQueue(int ele);
 int deQueue();
 void displayQueue();
};



void Queue::enQueue(int ele)
{
 if ((front == 0 && rear == size-1) ||(rear == (front-1)%(size-1)))
 {
  printf("\nQueue is Full\n");
  return;
 }

 else if (front == -1)
 {
  front = rear = 0;
  arr[rear] = ele;
 }

 else if (rear == size-1 && front != 0)
 {
  rear = 0;
  arr[rear] = ele;
 }

 else
 {
  rear++;
  arr[rear] = ele;
 }
}

int Queue::deQueue()
{
 if (front == -1)
 {
  printf("\nQueue is Empty");
  return INT_MIN;
 }

 int data = arr[front];
 arr[front] = -1;
 if (front == rear)
 {
  front = -1;
  rear = -1;
 }
 else if (front == size-1)
  front = 0;
 else
  front++;

 return data;
}

void Queue::displayQueue()
{
 if (front == -1)
 {
  printf("\nQueue is Empty");
  return;
 }
 printf("\nElements in Circular Queue are: ");
 if (rear >= front)
 {
  for (int i = front; i <= rear; i++)
   printf("%d ",arr[i]);
 }
 else
 {
  for (int i = front; i < size; i++)
   printf("%d ", arr[i]);

  for (int i = 0; i <= rear; i++)
   printf("%d ", arr[i]);
 }
 cout << endl;
}

int main()
{
    int size;
    cout << "Enter size of queue: ";
    cin >> size;
    
    Queue q(size);
    int ch;
    while (ch != -1)
    {
        cout << "Enter 1 to insert, 2 to delete, 3 to display, -1 to exit: ";
        cin >> ch;
        
        switch (ch)
        {
        case 1:
            int ele;
            cout << "Enter value to enqueue: ";
            cin >> ele;
            q.enQueue(ele);
            break;
        case 2:
            cout<< "Element deleted: " << q.deQueue() << endl;
            break;
        case 3:
            q.displayQueue();
            break;
        default:
            break;
        }
    }
    return 0;
        
}