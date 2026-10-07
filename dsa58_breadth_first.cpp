#include <iostream>
using namespace std;
struct queue{
    int size;
    int f;
    int r;
    int * arr;
};
int isEmpty(queue * n){
    if(n->r == n->f){
        return 1;
    }
    return 0;
}
int isFull(queue * n){
    if(n->r == n->size-1){
        return 1;
    }
    return 0;
}
int enqueue(queue * n, int val){
    if(isFull(n)){
        cout <<"this queue is full"<<endl;
    }
    else{
        n->r++;
        n->arr[n->r] = val;
    }
    return val;
}
int dequeue(queue * n){
    int a = -1;
    if(isEmpty(n) ){
        cout <<"this queue is empty"<<endl;
    }
    else{
      n->f++;
      a= n->arr[n->f];
    }
    return a;
}
int main() {
    queue n;
    n.size= 400;
    n.r = n.f = 0;
    n.arr = new int[n.size];
    int u ;
    int i = 0;
    int visited[7] = {0,0,0,0,0,0,0};
    int a [7][7] = {
        {0,1,1,1,0,0,0},
        {1,0,1,0,0,0,0},
        {1,1,0,1,1,0,0},
        {1,0,1,0,1,0,0},
        {0,0,1,1,0,1,1},
        {0,0,0,0,1,0,0},
        {0,0,0,0,1,0,0}
    };
    cout <<i<<" ";
    visited[i] = 1;
    enqueue(&n ,i);
    while (!isEmpty(&n))
    {
         int u = dequeue(&n);
       for (int j = 0; j < 7; j++)
       {
       if (a[u][j] == 1 && visited[j] ==0)
       {
        cout <<j <<" ";
        visited[j] = 1;
        enqueue(&n , j);
           }
       }
       
    }
    return 0;
}