#include <iostream>
#include<fstream>
#include <vector>
#include<queue>
#include <math.h>
#define MAXN 100
// Algoritmos em grafos
// Lucas Alves Da Costa
int number (void);
using namespace std;
int trat();
void grafo();
void menu();
void menu2(int);
void constroi(int);
void imprime(int);
bool checa_bipartido(int);
void biparticao(int , int);
void imprime_conjuntos();
void cria_conjuntos(int);
int componente_conexa(int);
int componente(int,int, int []);
void zera(int *, int);
void grafosespeciais ();
void graf1();
void graf2();
void graf3();
void graf4();
void bicmp(int, int);
void cmp(int);
void pass(int);
void ciclo(int);
void roda(int);
void recorrencia(int);
void alg(int,int,int);
void arvore_geradora(int);
void alg_guloso_de_coloracao(int);
void grafo_de_micuelsoij();
int cria(int,int);
void copia(int,int);
void imprimecor(int *,int);
void imprime1(int);
bool avalia(int, int);
string nome();
vector <int> vizinho [MAXN];
int ar [MAXN][MAXN];
int ma [MAXN][MAXN];
int cor[MAXN];
int part1[MAXN], part2[MAXN];

int main(){
    menu();
    return 0;
}

void menu() {
   int op;
   do {
   cout << "====Algoritmos em grafos====" << endl;
   cout << "Novo grafo - Digite 1" << endl;
   cout << "Carregar um grafo - Digite 2" << endl;
   cout << "Matriz de adjacencia de grafos especiais - Digite 3" << endl;
   cout << "Grafo de Mycielsky - Digite 4" << endl;
   cout << "Finalizar o programa - Digite 5" << endl;
   do {
      cin >> op;
      if (op < 1 || op > 5)
        cout << "Digite um valor entre 1 e 5" << endl;
   } while (op < 1 || op > 5);
   switch (op){
   case 1:
       grafo();
       break;
   case 2:
       break;
   case 3:
       grafosespeciais();
       break;
   case 4:
       grafo_de_micuelsoij();
       break;
   case 5:
      break;
   default:
       cout << "Opcao inva'lida" << endl;
        break;
   }
   } while (op != 5);
}

void grafo(){
  int n = number();
  constroi(n);
  cout << "O grafo foi criado" << endl;
  menu2(n);
}

void menu2(int n){
  int op=0;
  do{
  cout << "Para checar se e' bipartido - Digite 1 " << endl;
  cout << "Para contar as componentes conexas - Digite 2" << endl;
  cout << "Para imprimir - Digite 3" << endl;
  cout << "Para executar o algoritmo guloso de coloracao - Digite 4" << endl;
  cout << "Para voltar ao menu - Digite 5" << endl;
  do{
    cin >> op;
    if (op > 5 || op < 1)
        cout << "Digite um valor entre 1 e 5" << endl;
  }while (op > 5 || op < 1);
  if (op == 1)
     if (checa_bipartido(n)){
        cout << "O Grafo é bipartido" << endl;
        cria_conjuntos(n);
        imprime_conjuntos();
     }
     else
        cout << "O Grafo nao eh bipartido" << endl;
  else if (op == 2){
      int comp = componente_conexa(n);
      if ( comp == 1){
        cout << "O grafo tem uma componente conexa" << endl;
        cout << "Arvore Geradora" << endl;
        arvore_geradora(n);
        }
       else
        cout << "O grafo tem " << comp << " componentes conexas"  << endl;
  }
  else if (op == 3)
       imprime(n);
  else if (op == 4)
    alg_guloso_de_coloracao(n);
  } while (op != 5);
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
    cout << "Os vizinhos dos vertice " << i+1 << "sao";
        for (j=0; j < int(vizinho[i].size()); j++){
            cout << " " << vizinho[i][j]+1;
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
   // cout << "Deseja imprimir a matriz de adjacencia" << endl;
   // cout << "Digite 1- Para Sim" << endl;
  //  cout << "Digite 0- Para Nao" << endl;
 //   cin >> a;
 //   if (a){
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
 //   }
}



void zera(int * v,int n){
    for (int i =0; i < n; i++){
        v[i] = -1;
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

bool checa_bipartido (int n){
	int v;
	zera(cor,n);
	for (v=0; v < n; v++ ){
	   biparticao(v,n);
	}
	v=0;
	int j=0;
	while ( v < n && j != -1){
		for (j = v+1; j < n; j++){
			if ( (ma[v][j] == 1) && (cor[v] == cor[j])) {
				j= -1;
				break;
			}
		}
		v++;
	}
	if ( j != -1)
	   return true;
	else
	   return false;
}


void biparticao(int v, int n){
	int fila[n];
	int i,pos=0,pr=0;
	zera(fila,n);
	pos = pr +1;
	fila[pr] = v;
	if (cor[v] == -1){
	cor[v] = 1;
	while (v >= 0){
	  for (i=0; i < n; i++){
		if (ma[i][v] == 1 && cor[i] == -1){
			fila[(pos++)%n] = i;
			cor[i]= 1 - cor[v];
	   }
	}
	fila[(pr++)%n] = -1;
	v= fila[pr%n];
   }
   }
}

void cria_conjuntos(int n){
	int i=0,j=0;
	zera(part1,n);
	zera(part2,n);
	for(int v=0; v < n; v++){
		if (cor[v] == 1){
		  part1[i] = v;
		  i++;
	    }
		else{
		  part2[j] = v;
		  j++;
		 }
   }
}

void imprime_conjuntos(){
	cout << "Conjunto 1" << endl;
	int v=0;
	while (part1[v] != -1){
		cout << part1[v] << " ";
		v++;
	}
	cout << endl;
	cout << "Conjunto 2" << endl;
	v=0;
	while(part2[v] != -1){
		cout << part2[v] << " ";
		v++;
	}
	cout << endl;
}

void grafosespeciais(){
	int op=0;
	cout << "Escolha uma dos tipos de entrada" << endl;
	cout << "Digite 1 para grafos do tipo 1n => n_Cubo " << endl;
	cout << "Digite 2 para grafos do tipo 2n => Kn ou Passeio " << endl;
	cout << "Digite 3 para grafos do tipo 3n => Ciclo ou Roda" << endl;
	cout << "Digite 4 para grafos do tipo 4n => Grafo Completo Bipartido" << endl;
	do{
       cin >> op;
       if (op < 1 || op > 4)
         cout << "Valor inva'lido - Digite um valor entre 1 e 4" << endl;
	} while (op < 1 || op > 4);
	if ( op == 1)
		graf1();
	else if ( op == 2)
		graf2();
	else if (op == 3)
		graf3();
    else if (op == 4)
        graf4();
}

void graf1(){
    int n;
    cout << "Digite o valor de n >= 1 - Para o n_Cubo" << endl;
    cin >> n;
    recorrencia(n);
    imprime((int)pow(2,n));
}

void graf2 (){
	int op,n;
	cout << "Digite o valor de n, sendo n >= 2" << endl;
    cin >> n;
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
	int i,j;
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
	imprime(n);
}

void pass(int n){
	int i,j;
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
	imprime(n);
}

void ciclo(int n){
	int i,j;
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
   imprime(n);
}

void roda(int n){
	int i,j;
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
    imprime(n+1);
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
    int i,j;
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
    imprime (n);
}
void alg (int n){
  int v = pow(2,n);
  int m = v/2;
  int i,j;
  for (i=0; i < v ; i++){
    for (j=i; j < v; j++){
            ma[i+m][j+m] = ma[i][j];
            ma[j+m][i+m] = ma[i][j];
        }
    }
  for (i=0; i < m; i++){
    ma[i][(2*m)-1-i] = 1;
    ma[(2*m)-1-i][i] = 1;
  }
 //imprime(v);
}
void recorrencia(int n){
  if (n == 1){
    ma[0][0] = 0;
    ma[1][0] = 1;
    ma[0][1] = 1;
    ma[1][1] = 0;
  }
  else{
    recorrencia(n-1);
    alg(n);
  }
}

void arvore_geradora(int n){
	int v[n];
	int cont=1;
	int i,j;
	while (cont < n ){
          for (i=0; i < n; i++){
           for (j=i+1; j < n; j++){
                if (ma[i][j] == 1 && v[j] != 1) {
                    v[i]=1;
                    ar[i][j] = 1;
                    ar[j][i] = 1;
                    cont++;
                    break;
                }
            }
          }
	}
	for (i=0; i < n; i++){
		for (int j=0; j < n; j++){
			cout << ar[i][j] << " ";
		}
		cout << endl;
	}
}

void alg_guloso_de_coloracao(int n){
	int max1=0;
	int k;
	//cout << "A" << endl;
	//cout << "Valor de n " << n << endl;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if (ma[i][j]==1)
			   k++;
        if (k > max1)
			max1 = k;
		}
	}
	int corv[n];
	int cores[max1+1];
	zera(corv,n);
	zera(cores,max1+1);
	//cout << "B" << endl;
	max1=0;
	int i,j,cor=0;
	//imprimecor(corv, n);
	for (i=0;i< n;i++){
		cor=1;
		for(j=0; j < n; j++){

        if (ma[i][j] == 1){
			int m = corv[j];
			if ( avalia(m,cor)){
                cor++;
			}
		}
        corv[i] = cor;
       cores[cor-1]=cor;
        if (cor > max1)
            max1 = cor;
     }
   }
	imprimecor(cores,max1);
	//cout << "C" << endl;
}

void imprimecor(int * cores, int max1){
	cout << "Eh possivel colorir o grafo com " << max1 << " cores" << endl;
	cout << "f = { ";
	for (int i=0; i < max1; i++){
		cout << cores[i] << " ";
	}
	cout << "}"<<endl;
}
void grafo_de_micuelsoij(){
   int W,X;
   cout << "Digite o valor de w" << endl;
   cin >> W;
   do{
   cout << "Digite o valor de x" << endl;
   cin >> X;
     if (X < W){
       cout << "X não pode ser menor que W" << endl;
       cout << "Digite novamente" << endl;
     }
   } while (X < W);
   int n=cria(W,X);
}

int cria(int w, int x){
    if (x == w){
     int  n = 2*x+1;
        for (int i=0; i < w ; i++){
        for(int j=i+1; j < w; j++){
             ma[i][j]=1;
             ma[j][i] =1;
          }
        }
      imprime1(w);
      return n;
     }
    else if (x > w){
        int n = cria(w,x-1);
       copia((n-1)/2,n);
       alg(x,w,n);
       cout << "M"<<w << x << endl;
       imprime1(n);
      return 2*n+1;
    }
}

void alg(int x, int w, int n)
{
     for (int i=n-1; i >= (n-1)-((n-1)/2)+1 ; i--){
        for(int j=((n-1)-((n-1)/2)); j > 0; j--){
             ma[i][j] = ma[i][j+((n-1)/2)];
             ma[j][i] = ma[i][j+((n-1)/2)];
          }
        }
    for (int j=1;j<=(n-1)/2;j++){
        ma[0][j]=1;
        ma[j][0]=1;
    }

}

void imprime1(int n){
      for (int i=0; i < n; i++){
           for(int j=0; j < n; j++){
                cout <<" "<< ma[i][j];
            }
            cout << endl;
        }
 }

void copia (int n,int N)
{
    for (int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++){
            ma[N-n+i][N-n+j]= ma[i][j];
            ma[i][j]=0;
        }
    }
}

bool avalia(int x, int y){
    if (x == y)
      return true;
    else
       return false;
}
