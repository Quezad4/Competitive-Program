#include <bits/stdc++.h>
using namespace std;
const int maxN = 6;
class segTree{
	private:
		int N;
		int vet[4*maxN];
		int merge(int l, int r){
			return min(l,r);
		}
		void build(int id, int l, int r, vector<int> &a){
			if(l == r){
				vet[id] = a[l];
				return;
			}
			build(id*2,l,(l+r)/2, a); // constroi pra esquerda
			build(id*2+1,(l+r)/2+1,r,a); // controi para direita
			vet[id] = merge(vet[2*id], vet[2*id+1]);
		}
		int query(int id, int l, int r,int x, int y){
			if(x>r or y<l){ // se ta totalmente fora
				return 1000000; // valor que nao modifica a resposta
			}
			if(l>=x and r<= y){ // totalmente dentro
				return vet[id];
			}
			int p1 = query(2*id,l,(l+r)/2,x,y);
			int p2 = query(2*id+1,(l+r)/2+1,r,x,y);
			return merge(p1,p2); // cobre parcialmente
		}
		void update(int id, int l, int r, int x, int valor){ // trocar valores da seg
			if(x>r or x < l) return;
			if(x == l and x == r){
				vet[id] = valor;
				return;
			}
			update(2*id,l,(l+r)/2,x,valor);
			update(2*id+1,(l+r)/2+1,r,x,valor);
			vet[id] = merge(vet[2*id], vet[2*id+1]);
			
		}
		
	public:
		segTree(int newN, vector<int> &a){
			N = newN;
			build(1,0,N-1,a);
		}
		int query(int x, int y){
			return query(1,0,N-1,x-1,y-1); // x-1 e y-1 por conta de geralmente os ex comecarem com o primeiro vertice valendo 1;
		}
		void update(int x,int valor){
			update(1,0,N-1,x-1,valor);
		}	
		
};





int main(){
	vector<int> v;
	v.push_back(-1);
	v.push_back(3);
	v.push_back(4);
	v.push_back(0);
	v.push_back(2);
	v.push_back(1);
	segTree ST(6,v);
	cout << ST.query(1,1);
	ST.update(2,-5);
	cout << ST.query(1,2);
	
		
	
	
}






