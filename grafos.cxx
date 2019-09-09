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
vector <int> vizinho [MAXN];
int ma [MAXN][MAXN];

int main(){
    int n = number();
    constroi(n);
    imprime(n);
    vizinhaca(n);
    printvi(n);
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
    int i,j,cont=0;
    for (i=0; i <n;i++){
        for (j=0;j<n; j++){
                if (ma[i][j] == 1)
                        vizinho[i].push_back(j);
        }
    cont =0;
    }
}

void printvi (int n){
    int i,j,cont;
    for (i=0; i <n;i++){
    cout << "Os vizinhos dos vertice " << i+1 << "são";
        for (j=0; j < int(vizinho[i].size()); j++){
            cout << vizinho[i][j]+1;
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
