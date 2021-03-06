/*
All arrays are used for integers in this example
*/

// To detect if an array contains an element

int contains(int arr[], int size, int element) {
    int i;
    for (i = 0; i < size; i++) {
        if (arr[i] == element) {
            return 1;
        }
    }
    return 0;
}


// To detect size of an unknown sized array 

int size (int arr[]) {
    int i = 0;
    while (arr[i] != '\0') {
        i++;
    }
    
    return i;
}


// To insert a new element into a theoretically infinite array (size) 

int insert_at (int arr[], int element, int atIndex, int size) {
    int i;
    for (i = size-1; i >= atIndex; i--) {
        arr[i+1] = arr[i];
    }
    arr[atIndex] = element;
    size++;
    return size;
}

// To remove an element from a specified index
int remove_at (int arr[], int atIndex, int size) {
    int i;
    for (i = atIndex; i < size; i++) {
        arr[i] = arr[i+1];
    }
    size--;
    return size;
}


void reversal(int arr[],int size){
    int i = 0, j = size-1;
    for ( ; i < j; i++,j--){
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

// Pop it off at the head 
int pop (int arr[], int size) {
    int i;
    for (i = 0; i < size - 1; i++) {
        arr[i] = arr[i+1];
    }
    size--;
    return size;
}

// Push it in the tail
int push (int arr[], int element, int size) {
    arr[size] = element;
    size++;
    return size;
}
