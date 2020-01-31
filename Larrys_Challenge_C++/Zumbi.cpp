#include "Zumbi.h"

Zumbi::Zumbi()
{

}
Zumbi::Zumbi(RenderWindow* _window, const float cx, const float cy, const int _codigo):
	Inimigo(_window, cx, cy, _codigo)
{
	velocidade = 3;
	textura->loadFromFile("Tiny Dungeon Pack/Enemies/Zombie/Zombie.png");
	dimensoes.x = (textura->getSize().x / quantidadeTile.x);
	dimensoes.y = (textura->getSize().y / quantidadeTile.y);
	entidade.setPosition(coordenadas.x, coordenadas.y);
	entidade.setSize(dimensoes);
	entidade.setTexture(textura);
}
Zumbi::~Zumbi()
{

}
void Zumbi::existir()
{
	double coeficienteAngular = 0;
	//explicar essa equação
	if (coordenadasJogador.x - coordenadas.x != 0)
		coeficienteAngular = (coordenadasJogador.y - coordenadas.y) / (coordenadasJogador.x - coordenadas.x);


	double coeficienteLinear = coordenadas.y - coeficienteAngular * coordenadas.x;

	double ax2 = 1 + coeficienteAngular * coeficienteAngular;
	double bx2 = (-2 * (double)coordenadas.x) + (2 * coeficienteAngular * coeficienteLinear) + (-2 * (double)coordenadas.y * coeficienteAngular);
	double cx2 = (coeficienteLinear * coeficienteLinear) + (-2 * (double)coordenadas.y * coeficienteLinear) + 
					((double)coordenadas.x * (double)coordenadas.x) + ((double)coordenadas.y * (double)coordenadas.y) - ((double)velocidade * (double)velocidade);

	double raiz1 = (-bx2 + sqrt((bx2 * bx2) - (4 * ax2 * cx2))) / (2 * ax2);
	double raiz2 = (-bx2 - sqrt((bx2 * bx2) - (4 * ax2 * cx2))) / (2 * ax2);

	if (coordenadasJogador.x > coordenadas.x)
		coordenadas.x = raiz1;
	else
		coordenadas.x = raiz2;

	//(x > x0 ? x0 = raiz1 : x0 = raiz2);

	coordenadas.y = coeficienteAngular * coordenadas.x + coeficienteLinear;

	int posicao = 0;

	/*float coeficienteLinear2 = coordenadas.y - coordenadas.x;
	float y = coordenadas.x + coeficienteLinear2;
	

	if (coordenadasJogador.x < coordenadas.x && coordenadasJogador.y > coordenadas.y) {
		coeficienteLinear2 = coordenadas.y - coordenadas.x;
		y = coordenadasJogador.x + coeficienteLinear2;
		if (coordenadasJogador.y > y)
			posicao = 0;
		else
			posicao = 1;
	}
	else if (coordenadasJogador.x > coordenadas.x&& coordenadasJogador.y < coordenadas.y) {
		coeficienteLinear2 = coordenadas.y - coordenadas.x;
		y = coordenadasJogador.x + coeficienteLinear2;
		if (coordenadasJogador.y > y)
			posicao = 2;
		else
			posicao = 3;
	}
	else if (coordenadasJogador.x < coordenadas.x && coordenadasJogador.y < coordenadas.y) {
		coeficienteLinear2 = coordenadas.y + coordenadas.x;
		y = coeficienteLinear2 - coordenadasJogador.x;
		if (coordenadasJogador.y < y)
			posicao = 1;
		else
			posicao = 3;
	}
	else if (coordenadasJogador.x > coordenadas.x&& coordenadasJogador.y > coordenadas.y) {
		coeficienteLinear2 = coordenadas.y + coordenadas.x;
		y = coeficienteLinear2 - coordenadasJogador.x;
		if (coordenadasJogador.y < y)
			posicao = 0;
		else
			posicao = 2;
	}*/

	//float distancia = abs(coordenadas.x - coordenadasJogador.x);

	float distancia = 250;

	float x1 = coordenadas.x - distancia;
	float x2 = coordenadas.x + distancia;

	//Cria dois pontos no eixo X, com uma distância definida, dependendo da posição em relação aos dois pontos, a animação muda
	if (coordenadasJogador.y > coordenadas.y) {
		if (coordenadasJogador.x > x1 && coordenadasJogador.x < x2)
				posicao = 0;
		else if (coordenadasJogador.x <= x1) 
			posicao = 1;
		else if(coordenadasJogador.x >= x2)
			posicao = 2;
	}
	else {
		if (coordenadasJogador.x > x1 && coordenadasJogador.x < x2)
			posicao = 3;
		else if (coordenadasJogador.x <= x1)
			posicao = 1;
		else if (coordenadasJogador.x >= x2)
			posicao = 2;
	}

	/*float coeficienteLinear2 = coordenadas.y - coordenadas.x;
	int posicao = 0;

	float x = 0;
	float y = 0;

	if (coordenadasJogador.x < coordenadas.x && coordenadasJogador.y > coordenadas.y) {
		coeficienteLinear2 = coordenadas.y - coordenadas.x;
		y = coordenadas.x + coeficienteLinear2;
		x = coordenadas.y - coeficienteLinear2;
		if (coordenadasJogador.y > y && coordenadasJogador.x > x)
			posicao = 0;
		else if(coordenadasJogador.y < y && coordenadasJogador.x < x)
			posicao = 1;
	}
	else if (coordenadasJogador.x < coordenadas.x && coordenadasJogador.y < coordenadas.y) {
		coeficienteLinear2 = coordenadas.y + coordenadas.x;
		y = (-coordenadas.x) + coeficienteLinear2;
		x = (-coordenadas.y) + coeficienteLinear2;
		if (coordenadasJogador.y > y && coordenadasJogador.x < x)
			posicao = 1;
		else if(coordenadasJogador.y < y && coordenadasJogador.x > x)
			posicao = 3;
	}
	else if (coordenadasJogador.x > coordenadas.x && coordenadasJogador.y > coordenadas.y) {
		coeficienteLinear2 = coordenadas.y + coordenadas.x;
		y = (-coordenadas.x) + coeficienteLinear2;
		x = (-coordenadas.y) + coeficienteLinear2;
		if (coordenadasJogador.y > y && coordenadasJogador.x < x)
			posicao = 0;
		else if(coordenadasJogador.y < y && coordenadasJogador.x > x)
			posicao = 2;
	}
	else if (coordenadasJogador.x > coordenadas.x && coordenadasJogador.y < coordenadas.y) {
		coeficienteLinear2 = coordenadas.y - coordenadas.x;
		y = coordenadas.x + coeficienteLinear2;
		x = coordenadas.y - coeficienteLinear2;
		if (coordenadasJogador.y > y && coordenadasJogador.x > x)
			posicao = 2;
		else if(coordenadasJogador.y < y && coordenadasJogador.x < x)
			posicao = 3;
	}*/
	

	coordenadasTile.height = posicao * dimensoes.y;

	contAnimacao++;

	if (contAnimacao >= velAnimacao) {
		contAnimacao = 0;
		contFrames++;
		coordenadasTile.width = contFrames * dimensoes.x;

		if (coordenadasTile.width >= 6 * dimensoes.x) {
			coordenadasTile.width = 0;
		}

		if (contFrames >= 6) {
			contFrames = 0;
		}
	}


	entidade.setTextureRect(IntRect(coordenadasTile.width, coordenadasTile.height, dimensoes.x, dimensoes.y));
	entidade.setPosition(coordenadas.x, coordenadas.y);
	entidade.setSize(Vector2f(dimensoes.x * proporcao, dimensoes.y * proporcao));
	window->draw(entidade);
}

void Zumbi::setCoodenadasJogador(const float jx, const float jy)
{
	coordenadasJogador.x = jx;
	coordenadasJogador.y = jy;
}
