#include <iostream>

void printArray(int *a, int n,int l,int r){
    for(int i = 0;i<n;i++){
        if(i == l)
            std::cout<<"(";
        std::cout << a[i];
        if(i != n-1 && i != r)
            std::cout<<" ";
        if(i == r)
            std::cout<<") ";
    }
    std::cout<<std::endl;
}

int min(int a,int b){
    if(a <= b){
        return a;
    } else {
        return b;
    }
}

void merge(int *a, int *b, int l, int m, int r){
    int i = l;
    int j = m;
    for(int k=l; k<r; k++){
        if((j>=r) || ((i<m) && (a[i] <= a[j])))
            b[k] = a[i++];
        else
            b[k] = a[j++];
    }

    for(int n=0; n<r; n++){
        a[n] = b[n];
    }
}

void mergesort_r(int *a, int *b, int l, int r){
    if(l<r-1){
        int m = ((l+r)/2);
        if((l+r)%2 != 0){
            m++;
        }
        mergesort_r(a,b,l,m);
        mergesort_r(a,b,m,r);
        merge(a,b,l,m,r);
        printArray(a,5,l,r-1);
    }
}

void mergesort_i(int *a, int *b, int len){
    for(int w = 1;w<len;w*=2){
        for(int i = 0;i<len;i+=2*w){
            int l = i;
            int m = min(len,i+w);
            int r = min(len,i+2*w);
            merge(a,b,l,m,r);
            printArray(a,5,l,r-1);
        }
    }
}

int main() {
    int a[] = {31,27,16,3,12};
    int b[] = {0,0,0,0,0};

    std::cout << "Anfang (rekursiv):"<<std::endl;
    printArray(a,5,0,4);
    std::cout << std::endl;

    mergesort_r(a,b,0,5);

    std::cout << std::endl << "Ergebnis (rekursiv):"<<std::endl;
    printArray(a,5,0,4);

    std::cout << "----------------------------------" << std::endl;

    int c[] = {31,27,16,3,12};
    int d[] = {0,0,0,0,0};

    std::cout << "Anfang (iterativ):" << std::endl;
    printArray(c,5,0,4);
    std::cout << std::endl;

    mergesort_i(c,d,5);

    std::cout << std::endl << "Ergebnis (iterativ):" << std::endl;
    printArray(c,5,0,4);
    return 0;
}
