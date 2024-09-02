

#include <iostream>

using namespace std;
class Pieza
{
private:
	short fila;
	short columna;

public:
	Pieza() : fila(1), columna(1) {}

	Pieza(short f, short c) : fila(f), columna(c) {}

	
	short getFila() const { return fila; }
	short getColumna() const { return columna; }
	void setFila(short f) { fila = f; }
	void setColumna(short c) { columna = c; }

	
	void verInfo() {
		cout << "Fila: " << fila << ", Columna: " << columna << endl;
	}

	
	bool esCeldaValida(short f, short c) {
		return (f >= 1 && f <= 8 && c >= 1 && c <= 8);
	}

	
	virtual bool puedoIrA(short f, short c) = 0;

};

class Peon : public Pieza
{
private:
	short direccion; // 1 para peones blancos, -1 para peones negros

public:
	Peon(short f, short c, short dir) : Pieza(f, c), direccion(dir) {}

	void avanzar() {
		short nuevaFila = getFila() + direccion;
		if (esCeldaValida(nuevaFila, getColumna())) {
			setFila(nuevaFila);
			cout << "Peón avanza a (" << nuevaFila << ", " << getColumna() << ")\n";
		}
		else {
			cout << "Movimiento inválido para el peón.\n";
		}
	}
		
		bool puedoIrA(short f, short c) override {
			if (c == getColumna() && f == getFila() + direccion) {
				return true;
			}
			
			if (c == getColumna() && ((direccion == 1 && f == getFila() + 2 && getFila() == 2) ||
				(direccion == -1 && f == getFila() - 2 && getFila() == 7))) {
				return true;
			}
			return false;
		}
};

class Torre : public Pieza
{
public:
	Torre(short f, short c) : Pieza(f, c) {}

	void avanzar(short f, short c) {
		if (puedoIrA(f, c)) {
			setFila(f);
			setColumna(c);
			cout << "Torre se mueve a (" << f << ", " << c << ")\n";
		}
		else {
			cout << "Movimiento inválido para la torre.\n";
		}
	}

	
	bool puedoIrA(short f, short c) override {
		// Movimiento vertical o horizontal
		return (f == getFila() || c == getColumna());
	}
};



class Tablero
{
private:
	Pieza* piezas[8][8]; 

public:
	Tablero() {
		
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				piezas[i][j] = nullptr;
			}
		}
	}

	
	void colocarPieza(Pieza* p, short f, short c) {
		if (p->esCeldaValida(f, c)) {
			piezas[f - 1][c - 1] = p;
		}
		else {
			cout << "Posición inválida para colocar la pieza.\n";
		}
	}

	
	void mostrarTablero() {
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				if (piezas[i][j] != nullptr) {
					cout << "P ";
				}
				else {
					cout << ". ";
				}
			}
			cout << endl;
		}
	}
};
int main()

{
	Pieza* p1 = new Peon(2, 1, 1); 
	p1->verInfo();

	Peon peon(2, 1, 1);
	peon.verInfo();
	peon.avanzar();
	peon.verInfo();

	Torre torre(1, 1);
	torre.avanzar(1, 8);
	torre.verInfo();

	Tablero tablero;
	tablero.colocarPieza(&peon, peon.getFila(), peon.getColumna());
	tablero.colocarPieza(&torre, torre.getFila(), torre.getColumna());
	tablero.mostrarTablero();

	delete p1;

	return 0;
}
 