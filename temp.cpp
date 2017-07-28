#include <iostream>
using namespace std;

int parent(A,i){
    if (i==1){
        return null;
    }
    else{
        return (i/2);
    }
}

int left_child(A,i){
    if(2*i <= heap_size(A)){
        return 2*i;
    }
    else{
        return null;
    }
}

int right_child(A,i){
    if(2*i+1 <= heap_size(A)){
        return 2*i + 1;
    }
    else{
        return null;
    }
}

Max_Heapify(A,i){
    int l = left_child(i);
    int r = right_child(i);
    int largest = 0;
    if(l <= heap_size(A) and A[l] > A[i]){
        largest = l;
    }
    else{
        largest = i; 
    }
    if(r <= heap_size(A) and A[r] > A[i]){
        largest = r;
    }
    else{
        largest = i;
    }
    if(largest != i ){
        int temp = A[largest];
        A[largest] = A[i];
        A[i] = temp;
        Max_Heapify(A,largest);
    }
}

int main() {
	int T;
	int n;
	int k;
	scanf("%d", &T);
	while(T > 0){
	    scanf("%d", &n);
	    scanf("%d", &k);
	    int *C = (int*)malloc(n * sizeof(int));
	    int *A = (int*)malloc(n * sizeof(int));
	    for(int i = 1; i <= n; i++){
	        scanf("%d", &C[i]);
	    }
	    
	    T--;
	}
	return 0;
}
