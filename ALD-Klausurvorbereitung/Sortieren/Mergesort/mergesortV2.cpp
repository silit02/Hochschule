#include <iostream>
#include <string>

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

void mergesort_r(int *a, int *b, int l, int r, int n_gesamt){
    if(l<r-1){
        int m = ((l+r)/2);
        if((l+r)%2 != 0){
            m++;
        }
        mergesort_r(a,b,l,m, n_gesamt);
        mergesort_r(a,b,m,r, n_gesamt);
        merge(a,b,l,m,r);
        printArray(a,n_gesamt,l,r-1);
    }
}

void mergesort_i(int *a, int *b, int len){
    for(int w = 1;w<len;w*=2){
        for(int i = 0;i<len;i+=2*w){
            int l = i;
            int m = min(len,i+w);
            int r = min(len,i+2*w);
            merge(a,b,l,m,r);
            printArray(a,len,l,r-1);
        }
    }
}

int main(int argc, char *argv[]) {
    if(argc == 1){ //Keine Parameter übergeben
		std::cout << "usage: " << std::string(argv[0]) << " [Zahlen]" << std::endl;
		return 1;
	}
	
	int a[argc-1];
	int b[argc-1];
	
	int c[argc-1];
    int d[argc-1];
	
	//Zahlen in Array speichern
	for(int i = 0; i<argc-1; i++) {
		a[i] = stoi(std::string(argv[i+1]));
		c[i] = stoi(std::string(argv[i+1]));
	}
	
    std::cout << "Anfang (rekursiv):"<<std::endl;
    printArray(a,argc-1,0,argc-2);
    std::cout << std::endl;

    mergesort_r(a,b,0,argc-1, argc-1);

    std::cout << std::endl << "Ergebnis (rekursiv):"<<std::endl;
    printArray(a,argc-1,0,argc-2);

    std::cout << "----------------------------------" << std::endl;

    std::cout << "Anfang (iterativ):" << std::endl;
    printArray(c,argc-1,0,argc-2);
    std::cout << std::endl;

    mergesort_i(c,d,argc-1);

    std::cout << std::endl << "Ergebnis (iterativ):" << std::endl;
    printArray(c,argc-1,0,argc-2);
    return 0;
}
