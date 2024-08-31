

#include <iostream>

using namespace std;
class Pieza
{

};

class Peon : public Pieza
{

};

class Torre : public Pieza
{

};

class Caballo : public Pieza
{

};

class Alfil : public Pieza
{

};

class Reina : public Pieza
{

};

class Rey : public Pieza
{

};

class Tablero
{
private:
	Pieza* tablero[8][8];
public:
	Tablero()
	{
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				tablero[i][j] = NULL;
			}
		}
	}
	void imprimir()
	{
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (tablero[i][j] == NULL)
				{
					cout << "0 ";
				}
				else
				{
					cout << "1 ";
				}
			}
			cout << endl;
		}
	}
	void agregarPieza(Pieza* pieza, int x, int y)
	{
		tablero[x][y] = pieza;
	}
	void moverPieza(int x1, int y1, int x2, int y2)
	{
		tablero[x2][y2] = tablero[x1][y1];
		tablero[x1][y1] = NULL;
	}
};
int main()

{
	Tablero tablero;
	return 0;	
}
 