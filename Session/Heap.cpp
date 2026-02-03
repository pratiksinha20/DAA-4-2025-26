#include<bits/stdc++.h>

#define MAX 100
using namespace std;

int heap[MAX];
int heapSize=0;


void heapifyUp(int i ) {

while(i>0 && heap[(i-1)/2] > heap[i]) {

swap(heap[i] , heap[(i-1)/2]);
i = (i-1)/2;
}

}



void insert(int val) {
if(heapSize == MAX) {
cout<<"heap full";
return ;
}
heap[heapSize] =val;
heapSize++;

heapifyUp(heapSize-1);
}


int main() {

insert(2);
insert(4);
insert(6);
insert(1);

for(int i =0;i<heapSize;i++) {
cout<<heap[i]<< " ";
}


}