#ifndef HASH_CLASS
#define HASH_CLASS
#include <list>
#include <vector>

using namespace std;

template <typename T>

class hasht{
	public:
		// Constructor que especifica el numero de cubetas (entradas)
		// en la tabla
		hasht(int nEntradas){
			tabla.resize(nEntradas);
			numEntradas = nEntradas;
		};

		// Constructor copia
		hasht(const hasht<T>& obj){
		};

		// Destructor (borra la tabla)
		~hasht(){
			//hmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm
		};

		// Retorna un puntero a la llave o NULL si no se encuentra
		T* search(const T& item){
			int spot = item % numEntradas;
			auto p = tabla[spot].begin();
			while(p !=  tabla[spot].end() && *p != item){
				++p;
			}
			T* q = *p == item ? &(*p) : NULL;
			return q;
		};

		// Inserta el elemento en la tabla
		void insert(const T& item){
			tabla[item % numEntradas].push_back(item);
		};


	private:
		// N�mero de entradas en la tabla
		int numEntradas;

		// La tabla es un vector de listas de STL
		vector<list<T> > tabla;
};
#endif
