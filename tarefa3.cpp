#include <iostream>
#define M  100
using namespace std;
void grafosespeciais ();
void graf2();
void graf3();
void graf4();
void bicmp(int, int);
void cmp(int);
void pass(int);
void ciclo(int);
void roda(int);
void imprime(int[][M],int);
int main (){
	grafosespeciais();
	return 0;
}

void grafosespeciais(){
	int op;
	cout << "Escolha uma dos tipos de entrada" << endl;
	cout << "Digite 1 para grafos do tipo 1n " << endl;
	cout << "Digite 2 para grafos do tipo 2n " << endl;
	cout << "Digite 3 para grafos do tipo 3n " << endl;
	cout << "Digite 4 para grafos do tipo 4n " << endl;
	cin >> op;
	if ( op == 1){
		//graf1();
	}
	else if ( op == 2)
		graf2();
	else if (op == 3)
		graf3();
    else if (op == 4)
        graf4();
}


void graf2 (){
	int op,n;
	cout << "Digite o valor de n, sendo n >= 2" << endl;
    cin >> n;
	cout << "Matriz de adjacencia" << endl;
	cout << "a) Grafo completo - Digite 1" << endl;
    cout << "b) Grafo passeio  - Digite 2" << endl;
	cin >> op;
	if (op == 1)
		cmp(n);
	else
		pass(n);
}



void graf3 (){
	int op,n;
	cout << "Digite o valor de n, sendo n >= 3" << endl;
    cin >> n;
	cout << "Matriz de adjacencia" << endl;
	cout << "a) Grafo ciclo - Digite 1" << endl;
    cout << "b) Grafo Roda  - Digite 2" << endl;
	cin >> op;
	if (op == 1){
        cout << "Grafo ciclo" << endl;
        ciclo(n);
	}
    else{
        cout << "Grafo Roda" << endl;
        roda(n);
    }

}


void cmp(int n){
	int i,j, ma[M][M];
	for (i=0; i < n; i++){
		for (j=i; j < n; j++){
				if (i == j)
					ma[i][j] = 0;
				else{
					ma[i][j] = 1;
					ma[j][i] = 1;
				}
		}
	}
	imprime(ma,n);
}

void pass(int n){
	int i,j, ma[M][M];
	for (i=0; i < n; i++){
		for (j=i; j < n; j++){
				if (i != j - 1)
					ma[i][j] = 0;
				else{
					ma[i][j] = 1;
					ma[j][i] = 1;
				}
		}
	}
	imprime(ma,n);
}

void ciclo(int n){
	int i,j, ma[M][M];
	for (i=0; i < n; i++){
		for (j=i; j < n; j++){
				if (i == (j - 1) || ( (i == 0) && (j == n-1))){
					ma[i][j] = 1;
					ma[j][i] = 1;
				}
				else{
					ma[i][j] = 0;
					ma[j][i] = 0;
				}
		}
	}
   imprime(ma,n);
}

void roda(int n){
	int i,j, ma[M][M];
	for (i=0; i < n; i++){
		for (j=i; j <= n; j++){
				if (i == (j - 1) || ( (i == 0) && (j == n-1)) || (j == n)){
					ma[i][j] = 1;
					ma[j][i] = 1;
				}
				else{
					ma[i][j] = 0;
					ma[j][i] = 0;
				}
		}
	}
	ma[n][n] =0;
    imprime(ma,n+1);
}


void imprime (int ma [][M],int n){
	for (int i=0; i < n; i++){
            for(int j=0; j < n; j++){
                  cout <<" "<< ma[i][j];
            }
            cout << endl;
   }
}

void graf4 (){
	int op,nv,n1,n2;
	cout << "Grafo Bipartido Completo" << endl;
	cout << "Digite o valor de n1" << endl;
	cin >> n1;
	cout << "Digite o valor de n2" << endl;
    cin >> n2;
    nv = n1 + n2;
	cout << "Matriz de adjacencia do Bipartido Completo" << endl;
	bicmp(nv,n1);
}

void bicmp(int n, int n1){
    int i,j,ma[M][M];
    for (i=0; i < n; i++){
        for (j=i; j < n; j++){
            if (i < n1 && j >=  n1){
                ma[i][j] = 1;
                ma[j][i] = 1;
            }
            else{
                ma[i][j] = 0;
                ma[j][i] = 0;
            }
        }
    }
    imprime (ma,n);
}
