
#include <iostream>
#include<fstream>
#include <vector>
#define MAXN 100
int number (void);
using namespace std;
int trat();
void vizinhaca(int);
void printvi(int);
void constroi(int);
void imprime(int);
string nome();
int componente_conexa(int);
int componente(int,int, int []);
void zera(int [], int);
vector <int> vizinho [MAXN];
int ma [MAXN][MAXN];

int main(){
    int n = number();
    int componentes=0;
    constroi(n);
    imprime(n);
    vizinhaca(n);
    printvi(n);
    if ( (componentes= componente_conexa(n)) == 1)
        cout << "O grafo é conexo" << endl;
   else
        cout << "O grafo não é conexo, ele tem "<< componentes << " componentes conexas"<< endl;
    return 0;
}

int number (){
    int n;
    do{
        cout << "Digite o valor de n:" << endl;
        cin >> n;
        if ( n <= 0) cout << "Digite um valor maior que zero" << endl;
    } while (n <= 0);
    return n;
}

int trat(){
    int n;
    do{
        cin >> n;
        if ( n != 0 && n != 1)
         cout << "Digite somente 1 ou 0"<< endl;
    } while (n != 0 && n != 1);
    return n;
}

string nome (void){
    string nome;
    cout << "Digite o nome do grafo:";
    cin >> nome;
    return nome;
}

void vizinhaca (int n){
    int i,j;
    for (i=0; i <n;i++){
        for (j=0;j<n; j++){
                if (ma[i][j] == 1)
                        vizinho[i].push_back(j);
        }
    }
}

void printvi (int n){
    int i,j;
    for (i=0; i <n;i++){
    cout << "Os vizinhos dos vertice " << i+1 << " são: ";
        for (j=0; j < int(vizinho[i].size()); j++){
            cout << vizinho[i][j]+1 << " ";
        }
    cout << endl;
    }
}

void constroi (int n){
    for (int i=0; i < n-1; i++){
            ma[i][i]=0;
            ma[i+1][i+1]=0;
            for(int j=i+1; j < n; j++){
                    cout << "Ha aresta entre " << i+1 << " e " << j+1 << endl;
                    cout << "Digite 1- Para Sim" << endl;
                    cout << "Digite 0- Para Nao" << endl;
                    ma[i][j] = trat();
                    ma[j][i] = ma[i][j];
            }
        }
}
void imprime(int n){
bool a;
    cout << "Deseja imprimir a matriz de adjacencia" << endl;
    cout << "Digite 1- Para Sim" << endl;
    cout << "Digite 0- Para Nao" << endl;
    cin >> a;
    if (a){
            string gname= nome();
            ofstream arq(gname+".txt");
        cout << "Grafo " << gname << endl;
        for (int i=0; i < n; i++){
            for(int j=0; j < n; j++){
                arq <<" "<< ma[i][j];
            }
            arq << endl;
        }
         for (int i=0; i < n; i++){
            for(int j=0; j < n; j++){
                cout <<" "<< ma[i][j];
            }
            cout << endl;
        }
        cout <<"A matriz de adjacencia do grafo foi salva no arquivo " << gname <<".txt" <<endl;
    }
}

int componente_conexa(int n){
	int v,comp=0,vi[n];
	zera(vi,n);
	for (v=0; v < n; v++ ){
	   comp += componente(v,n,vi);
	}
	return comp;
}


int componente(int v, int n, int vi[]){
	int fila[n];
	int i,pos=0,pr=0;
	zera(fila,n);
	pos = pr +1;
	fila[pr] = v;
	if (vi[v] == 1)
		return 0;
	else{
		vi[v]= 1;
	while (v >= 0){
		
	  for (i=0; i < n; i++){	
		if (ma[i][v] == 1 && vi[i] == -1){
			fila[(pos++)%n] = i;
			vi[i]= 1;
	   }		
	}
	fila[(pr++)%n] = -1;
	v= fila[pr%n];
   }
   return 1;
 }
}
	
void zera (int fila[], int n){
	for (int i=0; i < n; i++)
		fila[i] = -1;
}
