#include <iostream>
using namespace std;
void desenTabla(char tablaDeJoc[][3])
{
	system("cls");
	cout << "Bun venit la joculetul meu creat in consola! :D" << endl<<endl;
	for (int index = 0; index < 3; index++)
	{
			cout << "\t   |   |" << endl;
			cout << "\t " << tablaDeJoc[index][0] << " | " << tablaDeJoc[index][1] << " | " << tablaDeJoc[index][2] << endl;
			if(index!=2)
			cout << "\t___|___|___" << endl;
	}
	cout << "\t   |   |" << endl<<endl;

}

int castigat(char tablaDeJoc[][3])
{
	if (tablaDeJoc[0][0] == tablaDeJoc[0][1] and tablaDeJoc[0][0] == tablaDeJoc[0][2])
	{
		if (tablaDeJoc[0][0] == 'X')
			return 1;
		return 2;
	}
	if (tablaDeJoc[1][0] == tablaDeJoc[1][1] and tablaDeJoc[1][0] == tablaDeJoc[1][2])
	{
		if (tablaDeJoc[1][0] == 'X')
			return 1;
		return 2;
	}
	if (tablaDeJoc[2][0] == tablaDeJoc[2][1] and tablaDeJoc[2][0] == tablaDeJoc[2][2])
	{
		if (tablaDeJoc[2][0] == 'X')
			return 1;
		return 2;
	}
	if (tablaDeJoc[0][0] == tablaDeJoc[1][0] and tablaDeJoc[0][0] == tablaDeJoc[2][0])
	{
		if (tablaDeJoc[0][0] == 'X')
			return 1;
		 return 2;
	}
	if (tablaDeJoc[0][1] == tablaDeJoc[1][1] and tablaDeJoc[0][1] == tablaDeJoc[2][1])
	{
		if (tablaDeJoc[0][1] == 'X')
			return 1;
		return 2;
	}
	if (tablaDeJoc[0][0] == tablaDeJoc[1][1] and tablaDeJoc[2][2] == tablaDeJoc[0][0])
	{
		if (tablaDeJoc[0][0] == 'X')
			return 1;
		return 2;
	 }
	if (tablaDeJoc[0][2] == tablaDeJoc[1][1] and tablaDeJoc[0][2] == tablaDeJoc[2][0])
	{
		if (tablaDeJoc[0][2] == 'X')
			return 1;
		return 2;
	}
	return 0;
}
void desfasurareJoc(int jucator, char tablaDeJoc[3][3])
{
	int mutari = 0;
	while (mutari <= 9)
	{
		desenTabla(tablaDeJoc);
		char simbol;
		int alegere;
		if (jucator % 2 == 1)
			simbol = 'X';
		else simbol = '0';
		cout << "Jucatorul " << jucator << " alege patratica unde vrea sa puna " << simbol << ": ";
		cin >> alegere;
		int linie, coloana;
		if (alegere % 3 == 0)
		{
			linie = alegere / 3 - 1;
			coloana = 2;
		}
		else
		{
			linie = alegere / 3;
			coloana = alegere % 3 - 1;
		}
		if (tablaDeJoc[linie][coloana] != 'X' && tablaDeJoc[linie][coloana] != '0')
		{
			tablaDeJoc[linie][coloana] = simbol;
			if (jucator == 1)
				jucator = 2;
			else jucator = 1;
			mutari++;
		}
		if (castigat(tablaDeJoc) == 1)
		{
			desenTabla(tablaDeJoc);
			cout << "Jucatorul 1 a castigat!";
			break;
		}
		if (castigat(tablaDeJoc) == 2)
		{
			desenTabla(tablaDeJoc);
			cout << "Jucatorul 2 a castigat!";
			break;
		}
		if (mutari == 9)
		{
			desenTabla(tablaDeJoc);
			cout << "Egalitate";
			break;
		}
	}
}

int main()
{ 
	char tablaDeJoc[3][3] = { '1','2','3','4','5','6','7','8','9' };
	int jucator = 1;
	bool incaUnJoc = true;
	while (incaUnJoc == true)
	{
		desenTabla(tablaDeJoc);
		desfasurareJoc(jucator, tablaDeJoc);
		std::cout << "Mai vreti sa jucati un joc? "<<std::endl;
		std::cout << "1. Da" << std::endl;
		std::cout << "2. Nu" << std::endl;
		int alegere;
		std::cin >> alegere;
		if (alegere == 2)
			incaUnJoc = false;
		if (alegere > 2 or alegere < 1)
		{
			std::cout << "Alegeti 1 sau 2!";
			while (alegere > 2 and alegere < 1)
			{
				std::cin >> alegere;
			}
			if (alegere == 2)
				incaUnJoc = false;
		}
		
	}

	return 0;
}