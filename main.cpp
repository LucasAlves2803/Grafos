#include <iostream>
using namespace std;
#define M 100
int ma[100][100];
void recorrencia(int,int);
void alg(int , int);
void imprime(int);
int N = 16;
int main() {
  recorrencia(0,N);
  return 0;
}
void alg (int k, int n){
  int i,j;
  for (i=k; i < n; i++){
    for (j=i; j < n; j++){
        if ((i+j+1) % 2 == 0){
            ma[i][j] = 1;
            ma[j][i] = 1;
        }
    }
  }
}
void recorrencia(int i, int n){
  int m;
  m = (i + n)/2;
  if (i < m){
    recorrencia(i,m);
    recorrencia(m,n);
    alg(i,n);
   imprime(n);
   cout << "----------" << endl;
  }
}

void imprime(int n){
 int i,j;
  for(i=0; i < n; i++){
    for (j=0;j < n; j++){
        cout << ma[i][j] << "";
    }
    cout << endl;
    }
}
