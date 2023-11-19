
#include <iostream>
using namespace std;

/*
DISE�O DEL ALGORITMO:
-- Describe con claridad, justificando las decisiones de dise�o realizadas,
-- el funcionamiento de tu algoritmo. Especifica claramente el cometido de cada 
-- par�metro (en caso de que utilices una generalizaci�n), los casos base, y los 
-- casos recursivos

ANALISIS DE LA COMPLEJIDAD:
-- Determina justificadamente el orden de complejidad del algoritmo dise�ado.
-- Escribe y resuelve las ecuaciones de recurrencia.

*/

bool es_interesante_aux(int n, int& dr, int& iz) {
	int ev = (n / 10);

	if (ev == 0)
	{
		iz = n;
		return true;
	}
	else {
		int element = n % 10;
		dr += element;
		if (es_interesante_aux(n / 10, dr, iz) && element != 0)
		{
			if ((dr % element == 0) && (iz % element == 0))
			{
				iz += element;
				dr -= element;
				return true;
			}
			else {
				return false;
			}
		}
		else {
			return false;
		}
	}
}

bool es_interesante(unsigned int n) {
	// A IMPLEMENTAR
	int dr = 0;
	int iz = 0;
	return es_interesante_aux(n, dr, iz);
}

void ejecuta_caso() {
	unsigned int n;
	cin >> n;
	if (es_interesante(n)) {
		cout << "SI" << endl;
	}
	else {
		cout << "NO" << endl;
	}
}

int main() {
	unsigned int num_casos;
	cin >> num_casos;
	for (int i = 0; i < num_casos; i++) {
		ejecuta_caso();
    }
}