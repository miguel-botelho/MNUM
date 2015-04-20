#include<cmath>
#include<cstdlib>
#include<iomanip>
#include<iostream>
#include"macros.h"
#include"diferenciais.h"
#include"zeros.h"
#include"sistemas.h"


using namespace std;

int zeros();
int EqDiferenciais();
int Sistemas();
int Ideais();


int main()
{
	int opcao;
	cout << "1 - Metodo dos Zeros." << endl;
	cout << "2 - Metodo das Equacoes Diferenciais." << endl;
	cout << "3 - Metodo dos Sistemas." << endl;
	cout << "0 - Sair." << endl;
	cout << "Insira a opcao: ";
	if (!(cin >> opcao))
	{
		cin.ignore(1000, '\n');
		cout << "Opcao errada!" << endl;
		main();
	}

	switch(opcao)
	{
	case 1: 
		{
			zeros();
			break;
		}
	case 2: 
		{
			EqDiferenciais();
			break;
		}
	case 3: 
		{
			Sistemas();
			break;
		}
	case 0:
		{
			return 0;
			break;
		}
	default:
		{
			cout << "Opcao errada! (escolha entre 1 e 4)" << endl;
			system("pause");
			system("cls");
			main();
		}
	}

	return 0;
}

int zeros()
{
	system("cls");
	cout << "1 - Metodo de Bissecao." << endl;
	cout << "2 - Metodo das Cordas." << endl;
	cout << "3 - Metodo de Newton." << endl;
	cout << "0 - Retroceder" << endl;
	int opcao;
	cout << "Insira a opcao: "; 
	if (!(cin >> opcao))
	{
		cin.ignore(1000, '\n');
		cout << "Opcao errada!" << endl;
		main();
	}

	switch(opcao)
	{
	case 1: 
		{
			Bissecao();
			main();
			break;
		}
	case 2: 
		{
			Corda();
			main();
			break;
		}
	case 3: 
		{
			Newton();
			main();
			break;
		}
	case 0:
		{
			main();
			break;
		}
	default:
		{
			cout << "Opcao errada! (escolha entre 1 e 4)" << endl;
			system("pause");
			system("cls");
			main();
		}
	}

	
	return 0;
}

int EqDiferenciais()
{
	system("cls");
	cout << "1 - Metodo de Euler." << endl;
	cout << "2 - Metodo de Euler Modificado." << endl;
	cout << "3 - Metodo de Runge-Kutta 2 Ordem." << endl;
	cout << "4 - Metodo de Runge-Kutta 4 Ordem." << endl;
	cout << "0 - Retroceder" << endl;
	int opcao;
	cout << "Insira a opcao: "; 
	if (!(cin >> opcao))
	{
		cin.ignore(1000, '\n');
		cout << "Opcao errada!" << endl;
		main();
	}

	switch(opcao)
	{
	case 1: 
		{
			Euler();
			main();
			break;
		}
	case 2: 
		{
			EulerModificado();
			main();
			break;
		}
	case 3: 
		{
			RungeKutta2();
			main();
			break;
		}
	case 4: 
		{
			RungeKutta4();
			main();
			break;
		}
	case 0:
		{
			main();
			break;
		}
	default:
		{
			cout << "Opcao errada! (escolha entre 1 e 4)" << endl;
			system("pause");
			system("cls");
			main();
		}
	}

	
	return 0;

}

int Sistemas()
{
	system("cls");
	cout << "1 - Metodo de Euler simples." << endl;
	cout << "2 - Metodo de Runge-Kutta 2 Ordem." << endl;
	cout << "0 - Retroceder" << endl;
	int opcao;
	cout << "Insira a opcao: "; 
	if (!(cin >> opcao))
	{
		cin.ignore(1000, '\n');
		cout << "Opcao errada!" << endl;
		main();
	}

	switch(opcao)
	{
	case 1: 
		{
			eulerSistemas();
			main();
			break;
		}
	case 2: 
		{
			rungeSistemas();
			main();
			break;
		}
	case 0:
		{
			main();
			break;
		}
	default:
		{
			cout << "Opcao errada! (escolha entre 1 e 4)" << endl;
			system("pause");
			system("cls");
			main();
		}
	}

	
	return 0;
}