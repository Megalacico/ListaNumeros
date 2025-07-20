#include <iostream>
#include <cmath>
#include <vector>
#include <cstdlib> 
#include <algorithm>
using namespace std;
struct numero {
	int valor;
	bool esPar;
	int frecuencia;

};
void agregarnumero(vector<numero> &numeros)
{
	int n;
	cout << "Ingrese un numero: ";
	cin >> n;
	numero nuevoNumero;
	nuevoNumero.valor = n;
	nuevoNumero.esPar = (n % 2 == 0);
	nuevoNumero.frecuencia = 1;
	for (auto& num : numeros) {
		if (num.valor == n) {
			num.frecuencia++;
			cout << "El numero ya existe, frecuencia incrementada a: " << num.frecuencia << endl;
			return;
		}
	}
	numeros.push_back(nuevoNumero);
}
void listarNumeros(const vector<numero>& numeros) {
	cout << "Numeros ingresados:\n";
	for (const auto& num : numeros) {
		cout << num.valor << " ("
			<< (num.esPar ? "par" : "impar")
			<< ", frecuencia: " << num.frecuencia << ")" << endl;;
	}
}
void calculapromedio(vector<numero>& numeros) {
	double suma = 0;
	for (const auto& num : numeros) {
		suma += num.valor;
	}
	double promedio = suma / numeros.size();
	cout << "El promedio de los numeros ingresados es: " << promedio << endl;

}
void calcularMayor(vector<numero>& numeros) {
	int mayor = numeros[0].valor;
	for (const auto& num : numeros) {
		if (num.valor > mayor) {
			mayor = num.valor;
		}
	}
	cout << "El numero mayor es: " << mayor << endl;
} 
void contarnumerospares(vector<numero>& numeros) {
	int contador = 0;
	for (const auto& num : numeros) {
		if (num.valor % 2 == 0) {
			contador++;
		}
	}
	cout << "Cantidad de numeros pares: " << contador << endl;
}

void buscarfrecuencia(vector<numero>& numeros) {
	int n;
	cout << "Ingrese un numero para buscar su frecuencia: ";
	cin >> n;
	for (const auto& num : numeros) {
		if (num.valor == n) {
			cout << "El numero " << n << " tiene una frecuencia de: " << num.frecuencia << endl;
			return;
		}
	}
}
void ordenarNumeros(vector<numero>& numeros) {
	int opcion;
	cout << "1.Ordenar de mayor a menor" << endl;
	cout << "2.Ordenar de menor a mayor" << endl;
	cin >> opcion;
	if (opcion == 1) {
		sort(numeros.begin(), numeros.end(), [](const numero& a, const numero& b) {
			return a.valor > b.valor;
			});
		cout << "Numeros ordenados de mayor a menor." << endl;
		for (const auto& num : numeros) {
			cout << num.valor << " ";
		}
	}
	else if (opcion == 2) {
		sort(numeros.begin(), numeros.end(), [](const numero& a, const numero& b) {
			return a.valor < b.valor;
			});
		cout << "Numeros ordenados de menor a mayor." << endl;
		for (const auto& num : numeros) {
			cout << num.valor << " ";
		}
	}
}
void eliminarnumero(vector<numero>& numeros) {
	int n;
	cout << "Ingrese el numero a eliminar: ";
	cin >> n;
	for (auto it = numeros.begin(); it != numeros.end(); ++it) {
		if (it->valor == n) {
			numeros.erase(it);
			cout << "Numero " << n << " eliminado." << endl;
			return;
		}
	}
}
void limpiarLista(vector<numero>& numeros) {
	numeros.clear();
	cout << "Lista de numeros limpiada." << endl;
}
int main()
{
	int n;
	int opcion;
	vector<numero> numeros;
	while (true) {
		cout << "1.Agregar un numero" << endl;
		cout << "2.Lista de los numeros" << endl;
		cout << "3.Promedio de los numeros" << endl;
		cout << "4.Calcular el numero mayor" << endl;
		cout << "5.Contar numeros pares" << endl;
		cout << "6.Buscar frecuencia de un numero" << endl;
		cout << "7.Ordenar numeros" << endl;
		cout << "8.Eliminar un numero" << endl;
		cout << "9.Limpiar lista de numeros" << endl;
		cout << "0.Salir" << endl;
		cin >> opcion;
		system("cls");
		switch (opcion) {
		case 1:
			agregarnumero(numeros);
			system("pause");
			system("cls");
			break;
		case 2:
			listarNumeros(numeros);
			system("pause");
			system("cls");
			break;

		case 3:
			calculapromedio(numeros);
			system("pause");
			system("cls");
			break;

		case 4:
			calcularMayor(numeros);
			system("pause");
			system("cls");
			break;

		case 5:
			contarnumerospares(numeros);
			system("pause");
			system("cls");
			break;

		case 6:
			buscarfrecuencia(numeros);
			system("pause");
			system("cls");
			break;
		case 7:
			ordenarNumeros(numeros);
			system("pause");
			system("cls");
			break;

		case 8:
			eliminarnumero(numeros);
			system("pause");
			system("cls");
			break;
		case 9:
			limpiarLista(numeros);
			system("pause");
			system("cls");
			break;

		case 0:
			cout << "Saliendo del programa." << endl;
			return 0;
		}
	}
	return 0;
}
