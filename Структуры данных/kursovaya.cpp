#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <fstream>
#include <map>
#include <conio.h>
#include <algorithm>
using namespace std;
int rost = false;
int kol = 0;
char str[10];
#define N 4000
struct record{
  char fio[32];
  char street[18];
  short int house;
  short int apartment;
  char data[10];
};

struct queue{
 queue *next;
 record* data;
};

struct vertex{
	vertex* left = NULL;
	vertex* right = NULL;
	record* data = NULL;
	short int balance = 0;
	vector<record*> mid;
};
vertex* root_avl = NULL;
bool choise;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void global_search1(string key, vertex*& p){
	if(p){
		if(p->data->fio[0] == key[0] || p->data->data[0] == key[0] || p->data->street[0] == key[0]){
			cout << p->data->fio << ' ' << p->data->street << ' ' << p->data->data << ' '<< p->data->house <<' '<< p->data->apartment << '\n';
		}
		for(int i = 0; i < p->mid.size(); ++i){
			if(p->mid[i]->fio[0] == key[0] || p->mid[i]->street[0] == key[0] || p->mid[i]->data[0] == key[0]){
				cout << p->mid[i]->fio << ' ' << p->mid[i]->street << ' ' << p->mid[i]->data << ' '<< p->mid[i]->house <<' '<< p->mid[i]->apartment << '\n';
			}
		}
		global_search1(key, p->left);
		global_search1(key, p->right);
	}
}
void global_search2(string key, vertex*& p){
	if(p){
		if(p->data->fio[0] == key[0] && p->data->fio[1] == key[1] || p->data->data[0] == key[0] && p->data->data[1] == key[1] || p->data->street[0] == key[0] && p->data->street[1] == key[1]){
			cout << p->data->fio << ' ' << p->data->street << ' ' << p->data->data << ' '<< p->data->house <<' '<< p->data->apartment << '\n';
		}
		for(int i = 0; i < p->mid.size(); ++i){
			if(p->mid[i]->fio[0] == key[0] && p->mid[i]->fio[1] == key[1] || p->mid[i]->street[0] == key[0] && p->mid[i]->street[1] == key[1] || p->mid[i]->data[0] == key[0] && p->mid[i]->data[1] == key[1]){
				cout << p->mid[i]->fio << ' ' << p->mid[i]->street << ' ' << p->mid[i]->data << ' '<< p->mid[i]->house <<' '<< p->mid[i]->apartment << '\n';
			}
		}
		global_search2(key, p->left);
		global_search2(key, p->right);
	}
}
int less_find(char* s, string e){
	int t = 0;
	for(int i = 0; i < 5; ++i){
		if(s[i] > e[i]){
			t = 1;
			return 1;
		}
		if(s[i] < e[i]){
			t = -1;
			return -1;
		}
		if(s[i] == e[i]) ++t;
	}
	return 0;
}
void ulica(string key, vertex*& p){
	if(p){
		if(less_find(p->data->street, key) == 1){
			ulica(key, p->left);
		}else if(less_find(p->data->street, key) == -1){
			ulica(key, p->right);
		}else{
			cout << p->data->fio << ' ' << p->data->street << ' ' << p->data->data << ' ' << p->data->house << ' ' << p->data->apartment << '\n';
			for(int i = 0; i < p->mid.size(); ++i){
				cout << p->mid[i]->fio << ' ' << p->mid[i]->street << ' ' << p->mid[i]->data << ' ' << p->mid[i]->house << ' ' << p->mid[i]->apartment << '\n';
			}
		}
	}
}
void obhod(vertex*& p){
	if(p){
		cout << p->data->fio << ' ' << p->data->street << ' ' << p->data->data << ' '<< p->data->house << ' ' << p->data->apartment << '\n';
		++kol;
		for(int i = 0; i < p->mid.size(); ++i){
			++kol;
			cout << p->mid[i]->fio << ' ' << p->mid[i]->street << ' ' << p->mid[i]->data << ' ' << p->mid[i]->house << ' ' << p->mid[i]->apartment << '\n';
		}
		obhod(p->left);
		obhod(p->right);
	}
}
int razmer (vertex*& p){
	int n = 0;
	if(p == NULL){
	    n = 0;
	}else{
	   	n = 1 + razmer(p->left) + razmer(p->right);
	}
	return n;
}
void LL(vertex*& p){
	vertex* q;
	q = p->left;
	p->balance = 0;
	q->balance = 0;
	p->left = q->right;
	q->right = p;
	p = q;
}

void RR(vertex*& p){
	vertex *q;
    q->balance = 0;
    p->balance = 0;
    p->right = q->left;
    q->left = p;
    p = q;
}
void LR(vertex*& p){
	vertex* q,* r;
	q = p->left;
	r = q->right;
	if(r->balance < 0){
		p->balance = 1;
	}else{
		p->balance = 0;
	}
	if(r->balance > 0){
		q->balance = -1;
	}else{
		q->balance = 0;
	}
	r->balance = 0;
	q->right = r->left;
	p->left = r->right;
	r->left = q;
	r->right = p;
	p = r;
}

void RL(vertex*& p){
	vertex *r,*q;
    q = p->right; r=q->left;
    if (r->balance > 0) {
		p->balance = -1; 
	}else{
		p->balance=0;
	}
    if (r->balance<0){
		q->balance=1; 
	}
    else{
		q->balance = 0;
	}
    r->balance = 0;
    q->left = r->right;
    p->right = r->left;
    r->right = q; 
    r->left = p; 
    p = r;
}
int myless(char* q, char* w){
	int t = 0;
	for(int i = 0; i < 5; ++i){
		if(q[i] > w[i]){
			t = 1;
			break;
		}
		if(q[i] < w[i]){
			t = -1;
			break;
		}
		if(q[i] == w[i]) ++t;
	}

	if(t == 1) return 1;
	else if(t == -1) return -1;
	else if(t == 5) return 0;
}
void avl(vertex*& p, record* element){
	if(!p){
		p = new vertex;
		p->data = element;
		rost = true;
	}else if (myless(p->data->street, element->street) == 1){
		avl(p->left, element);
		if(rost){
			if(p->balance > 0){
				p->balance = 0;
				rost = false;
			}else if(p->balance == 0){
				p->balance = -1;
				rost = true;
			}else if(p->left->balance < 0){
				LL(p);
				rost = false;
			}else{
				LR(p);
				rost = false;
			}
		}
	}else if(myless(p->data->street, element->street) == -1){
		avl(p->right, element);
		if(rost){
			if(p->balance < 0){
				p->balance = 0;
				rost = false;
			}else if(p->balance == 0){
				p->balance = 1;
				rost = true;
			}else if(p->right->balance > 0){
				RR(p);
				rost = false;
			}else{
				RL(p);
				rost = false;
			}
		}
	}else{
		p->mid.push_back(element);
	}
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
inline int search_less(vector <record*>& index, string key, int M){
	string s = key; 
	for(int i = 0; i < 3; ++i){
		s[i] = index[M]->data[i]; 
	}
	if(key < s) return -1;
	else if(key > s) return 1;
	else if (key == s)return 0;
}
inline int binsearch(vector <record*>& index, string key, int L, int R){
	int M;
	while(L < R){
		M = L+(R-L)/2;
		if(search_less(index,key,M) <= 0){
			R = M;
		}else{
			L = M + 1;
		}																									//bin_poisk
	}
	if(search_less(index,key,L) == 0){
		return L;
	}else{
		return -1;
	}
}
inline int binsearch2(vector <record*>& index, string key, int L, int R){
	int M;
	while(L < R){
		M = R - (R - L)/2;
		if(search_less(index,key,M) >= 0){
			L = M;
		}else{
			R = M - 1;
		}
	}
	if(search_less(index,key,L) == 0){
		return L;
	}else{
		return -1;
	}
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
inline bool sravnenie1(int q, int L, vector <record*>& index){
	if(strcmp(index.at(q)->data, index.at(L) -> data) < 0){
		return true;
	}else if(strcmp(index.at(q)->data, index.at(L) -> data) > 0){
		return false;
	}else{
		return (strcmp(index.at(q)->fio, index.at(L)->fio) < 0);
	}
}
inline bool sravnenie2(int q, int L, vector <record*>& index){
	if(strcmp(index.at(q)->data, index.at(L) -> data) >0){
		return true;
	}else if(strcmp(index.at(q)->data, index.at(L) -> data) <0){										//Quick_sort
		return false;
	}else{
		return (strcmp(index.at(q)->fio, index.at(L)->fio) >0);
	}
}


inline void quick_sort(vector <record*>& index, int L, int R){
	int i = L, j = R;
	while(i<=j){
		while(sravnenie1(i,L,index)) ++i;
		while(sravnenie2(j,L,index)) --j;
		if(i <= j){
			swap(index.at(i), index.at(j));
			++i;
			--j;
		}
	}
	if(L < j)
		quick_sort(index, L, j);
	if(i < R)
		quick_sort(index, i, R);
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void add_q(record* element, queue*& p){
	if(!p){
		p = new queue;
		p->data = element;
		p->next = NULL;
	}else{
		add_q(element, p->next);
	}
}
void del_q(queue*& p){
	queue* q;
	while(p){
		q = p;
		p = p->next;
		delete q;
	}
}
print_q(queue*& p){
	if(p){
		cout << p->data->fio<< ' ' << p->data->street<< ' ' << p->data->data<< ' ' << p->data->house<<' ' << p->data->apartment << '\n';
		print_q(p->next);
	}
}
queue* add_avl(queue*& p){
	queue* q = p;
	while(p){
		avl(root_avl, p->data);
		p = p->next;
	}
	return q;
}
int med(int L, int R, vector<pair<long double, char>>&P){
  double suml = 0;
  for(int i = L; i < R; ++i){
    suml += P[i].first;
  }
  double sumr = P[R].first;
  int m = R ;
  while(suml >= sumr){
    m--;
    suml -= P[m].first;
    sumr += P[m].first;
  }
  return m;
}

void kod(int L, int R, int k, vector<pair<long double, char>>&P, vector<int> &_L, vector<vector<int>>&C){
	if(L < R){
    k++;
    int m = med(L, R, P);
    for(int i = L; i <= R; i++){
      i <= m ? C[i][k] = 0 : C[i][k] = 1;
      _L[i]++;
    }
    kod(L, m, k, P, _L, C);
    kod(m+1, R, k, P, _L, C);
  }
}
bool comp(const pair<long double, char>&a, const pair<long double, char>&b){
	return(a.first > b.first);

}



// גûגמה םומעסמנע
void print_base(record* array){
int c,k=20,i=0,y;
		cout<<"Kakou BapuaHT? 1- 20; 2-4000"<<endl;
	cin>>c;
	i=0;
	switch(c)
	{
	case 1:
	while(c==1)	{
		while(i<k){
		cout <<i+1 << ") " << 
		array[i].fio <<" "<< 
		  array[i].street << " " << 
		  	array[i].data << " " << 
			  array[i].house << " " << 
			  	array[i].apartment << "\n";
		i++;	}	
	cout<<"print more? press: 1"<<endl;
	cin>>c;
	if(c==1)
	k=k+20;
	else
	break;
	}
	break;
		
	case 2:
	for(i=0;i<N;i++)
	{
		cout <<i+1 << ") " << 
		array[i].fio <<" "<< 
		  array[i].street << " " << 
		  	array[i].data << " " << 
			  array[i].house << " " << 
			  	array[i].apartment << "\n";
		if(kbhit())
		{
			cout<<"Continue? "<<endl;
			cin>>y;
			if(!y)
			break;
		}
	}
	break;
}
}
// ÂÛÂÎÄ ÈÍÄÅÊÑ
void print_index(vector <record*>& index){
	for(int i = 0; i < N; i++){
       	cout <<i+1 << ") " <<
		index[i]->fio <<" "<< 																					
			index[i]->street << " " << 
				index[i]->data << " " << 
					index[i]->house << " " << 
						index[i]->apartment << "\n";
  	}
}


int main(){
  ios::sync_with_stdio(false);
  FILE* fp = fopen("testBase4.dat", "rb");
  record* array  = new record[N];
  vector <record*> index(4000);
  fread((record* )array, sizeof(record), N, fp);
  for(int j = 0; j < N; ++j){
	index[j] = &array[j];	
  }
  
  quick_sort(index, 0 ,N-1);
  
  print_base(array);
  
  cout <<"vivesti otsortirovanni massiv?\n1 = DA\n0 = NET\n"; cin >> choise;
  if(choise){
  	system("CLS");
  	print_index(index);
  }
  cout << "Search on data (First two symb)\n";
  string key;
  int t , q;
  while(1){

  	cin >> key;
  	if(key == "-1") break;
  	if(t == -1 && q == -1){
  		cout << "element not found: \n";
  		
	}
	t = binsearch(index, key,0,N-1)+1;
  	q = binsearch2(index, key,0,N-1)+1;
	int i=t;
	queue* root_q = NULL;
	while(i<q){
		add_q(index[i], root_q);	i++;
	  }

  	cout << "The most left element: "<< t << '\n' << "The most right element: " << q << '\n' << "Number of element's with this key: " << q-t+1 << '\n';

	root_q = add_avl(root_q);
	del_q(root_q);
	delete root_q;
  }
  obhod(root_avl);

  cout<<"Kolichestvo elementov v dereve: " << kol << endl;
  cout << "Poisk po ulice\n";
  	cin >> key;
	ulica(key, root_avl);
	
  cout << "KOD FANO\n";
  map<char, pair<int, long double>> x;
  long double summa_povtorenii = 0;
  for(int i = 0; i < N; ++i){
  	for(int j = 0; j < 32; ++j){
  		x[index[i]->fio[j]].first = 0;
	}
	for(int j = 0; j < 18; ++j){
		x[index[i]->street[j]].first = 0;
	}
	for(int j = 0; j < 10; ++j){
		x[index[i]->data[j]].first = 0;
	}
	x[index[i]->house + '0'].first = 0;
	for(int b = index[i]->apartment; b > 0; b /= 10){
		x[b % 10+'0'].first = 0;
	}
  }
  for(int i = 0; i < N; ++i){
  	for(int j = 0; j < 32; ++j){
  		x[index[i]->fio[j]].first++;
	}
	for(int j = 0; j < 18; ++j){
		x[index[i]->street[j]].first++;
	}
	for(int j = 0; j < 10; ++j){
		x[index[i]->data[j]].first++;
	}
	x[index[i]->house + '0'].first++;
	for(int b = index[i]->apartment; b > 0; b /= 10){
		x[b%10+'0'].first++;
	}
  }
  for(auto&i : x){
  	summa_povtorenii += i.second.first;
  }
  for(auto&i : x){
  	i.second.second = i.second.first / summa_povtorenii;
  }
  int size = 0;
  for(auto&i : x){
  	cout << i.first << ' ' << i.second.first << ' ' << i.second.second <<'\n';
  	++size;
  }
  long double control = 0;
  int e = 0;
  vector<pair<long double, char>> P(size);
  for(auto&i : x){
  	control += i.second.second;
  	P[e].first = i.second.second;
  	P[e].second = i.first;
  	++e;
  }
  sort(P.begin(), P.end(), comp);
  cout << "summa veroyatnostei = " << control << '\n';
  vector<int>L(size);
  vector<vector<int>> C(size, vector<int>(size, 9));
  kod(0, size-1, 0, P, L, C);
  e = 0;
  for(auto& i : C){
  	cout << P[e].second << "  ------> ";
  	for(auto&j : i){
  		if(j != 9){
  			cout << j << ' ';
		  }
	  }
	  cout << endl;
	  ++e;
  }
  long double sred = 0, entro = 0;
  for(int i = 0; i < size; ++i){
  	sred += P[i].first * L[i];
  	entro += (P[i].first*(log(P[i].first) / log(2)));
  }
  cout << "Srednya dlina = " << sred << '\n';
  cout << "Entropia = " << -entro << '\n';
}


