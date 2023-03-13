#include<iostream>
#include<iomanip>
using namespace std;

void myMatrix(int ***x,int M){
*x = new int*[M];
for(int i=0;i < M; i++){
(*x)[i] = new int[M];
}
for(int i=0;i < M; i++){
for(int j=0;j < M; j++){
(*x)[i][j] = i+j;
}
}
}


void freeSpace(int **x,int M){
for(int i=0;i < M; i++){
delete [] x[i];
}
delete [] x;
}

int main(){
int **p;
int N;
cout << "N = ";
cin >> N;
myMatrix(&p,N);
for(int i=0;i < N; i++){
for(int j=0;j < N; j++){
cout << setw(4) << p[i][j];
}
cout << "\n";
}
freeSpace(p,N);
return 0;
}