#include "Perseguidor.h"

Perseguidor::Perseguidor()
{

}

Perseguidor::Perseguidor(RenderWindow* _window, Texture* _textura, const float cx, const float cy, const int _profundidade, const int _codigo, const int _xTile, const int _yTile, const float _velocidade):
	Inimigo(_window, _textura, cx, cy, _profundidade, _codigo, _xTile, _yTile)
{
	velocidade = _velocidade;

	coordenadasOrigem.x = cx;
	coordenadasOrigem.y = cy;
	distanciaOrigemPadrao = 600;
	distanciaJogadorPadrao = 150;
}

Perseguidor::~Perseguidor()
{

}

void Perseguidor::existir()
{
	//Algoritmo mais preciso de persegui��o, estudar posteriormente.
	/*double coeficienteAngular = 0;
	//explicar essa equa��o
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


	//--------------------/----------------------//
	
	float distancia = 250;

	float x1 = coordenadas.x - distancia;
	float x2 = coordenadas.x + distancia;

	//Cria dois pontos no eixo X, com uma dist�ncia definida, dependendo da posi��o em rela��o aos dois pontos, a anima��o muda
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
	}*/
	//termina


	float limiteDireita = coordenadas.x + abs(coordenadasAlvo.y - coordenadas.y) * 2;
	float limiteEsquerda = coordenadas.x - abs(coordenadasAlvo.y - coordenadas.y) * 2;
	float limiteCima = coordenadas.y + abs(coordenadasAlvo.x - coordenadas.x) / 2;
	float limiteBaixo = coordenadas.y - abs(coordenadasAlvo.x - coordenadas.x) / 2;

	int posicao = 0;

	if (coordenadasAlvo.x >= limiteEsquerda && coordenadasAlvo.x <= limiteDireita) {
		if (coordenadasAlvo.y >= coordenadas.y) {
			posicao = 4;
			coordenadas.y += velocidade;
			direcao = BAIXO;
		}
		else {
			posicao = 7;
			coordenadas.y -= velocidade;
			direcao = CIMA;
		}
	}
	else {
		if (coordenadasAlvo.x >= coordenadas.x) {
			posicao = 6;
			coordenadas.x += velocidade;
			direcao = DIREITA;
		}
		else {
			posicao = 5;
			coordenadas.x -= velocidade;
			direcao = ESQUERDA;
		}
	}

	if (coordenadas.x == coordenadasOrigem.x && coordenadas.y == coordenadasOrigem.y + velocidade)
		coordenadas.y -= velocidade;

	if (coordenadas.x == coordenadasOrigem.x && coordenadas.y == coordenadasOrigem.y)
		posicao = 0;

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
	window->draw(entidade);
}

void Perseguidor::perseguir(const bool _perseguir)
{
	if (_perseguir)
		coordenadasAlvo = coordenadasJogador;
	else
		coordenadasAlvo = coordenadasOrigem;
}

void Perseguidor::setCoodenadasAlvo(const float jx, const float jy)
{
	coordenadasAlvo.x = jx;
	coordenadasAlvo.y = jy;
}

void Perseguidor::setCoodenadasJogador(const float jx, const float jy)
{
	coordenadasJogador.x = jx;
	coordenadasJogador.y = jy;
}

int Perseguidor::getDirecao()const
{
	return direcao;
}

float Perseguidor::getDistanciaOrigem()const
{
	return sqrt(((coordenadas.x - coordenadasOrigem.x) * (coordenadas.x - coordenadasOrigem.x)) + ((coordenadas.y - coordenadasOrigem.y) * (coordenadas.y - coordenadasOrigem.y)));
}

float Perseguidor::getxOrigem()const
{
	return coordenadasOrigem.x;
}

float Perseguidor::getyOrigem()const
{
	return coordenadasOrigem.y;
}

float Perseguidor::getDistanciaOrigemPadrao()const
{
	return distanciaOrigemPadrao;
}

float Perseguidor::getDistanciaJogador()const
{
	return sqrt(((coordenadasOrigem.x - coordenadasJogador.x) * (coordenadasOrigem.x - coordenadasJogador.x)) + ((coordenadasOrigem.y - coordenadasJogador.y) * (coordenadasOrigem.y - coordenadasJogador.y)));
}

float Perseguidor::getDistanciaJogadorPadrao()const
{
	return distanciaJogadorPadrao;
}
