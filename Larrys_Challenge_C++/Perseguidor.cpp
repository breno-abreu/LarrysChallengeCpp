#include "Perseguidor.h"

Perseguidor::Perseguidor()
{

}
Perseguidor::Perseguidor(RenderWindow* _window, Texture* _textura, const float cx, const float cy, const int _profundidade, const int _codigo, const int _xTile, const int _yTile, const float _velocidade):
	Inimigo(_window, _textura, cx, cy, _profundidade, _codigo, _xTile, _yTile)
{
	velocidade = _velocidade;
	/*quantidadeTile.x = 6;
	quantidadeTile.y = 8;
	dimensoes.x = (textura->getSize().x / quantidadeTile.x);
	dimensoes.y = (textura->getSize().y / quantidadeTile.y);
	dimensoesAux.x = dimensoes.x * proporcao;
	dimensoesAux.y = dimensoes.x * proporcao;
	entidade.setSize(dimensoesAux);*/
}
Perseguidor::~Perseguidor()
{

}
void Perseguidor::existir()
{
	//começa
	/*double coeficienteAngular = 0;
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

	int posicao = 0;*/
	//termina






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



	//começa
	/*
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
	}*/
	//termina








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


	float limiteDireita = coordenadas.x + abs(coordenadasJogador.y - coordenadas.y) * 2;
	float limiteEsquerda = coordenadas.x - abs(coordenadasJogador.y - coordenadas.y) * 2;
	float limiteCima = coordenadas.y + abs(coordenadasJogador.x - coordenadas.x) / 2;
	float limiteBaixo = coordenadas.y - abs(coordenadasJogador.x - coordenadas.x) / 2;

	/*RectangleShape auxD;
	RectangleShape auxE;
	auxD.setSize(Vector2f(5, 5));
	auxE.setSize(Vector2f(5, 5));
	auxD.setFillColor(Color::Blue);
	auxE.setFillColor(Color::Blue);
	auxD.setPosition(Vector2f(coordenadas.x, limiteCima));
	auxE.setPosition(Vector2f(coordenadas.x, limiteBaixo));

	window->draw(auxD);
	window->draw(auxE);

	RectangleShape auxC;
	RectangleShape auxB;
	auxC.setSize(Vector2f(5, 5));
	auxB.setSize(Vector2f(5, 5));
	auxC.setFillColor(Color::Blue);
	auxB.setFillColor(Color::Blue);
	auxC.setPosition(Vector2f(limiteDireita, coordenadas.y));
	auxB.setPosition(Vector2f(limiteEsquerda, coordenadas.y));

	window->draw(auxC);
	window->draw(auxB);*/
	

	int posicao = 0;

	if (coordenadasJogador.x >= limiteEsquerda && coordenadasJogador.x <= limiteDireita) {
		if (coordenadasJogador.y >= coordenadas.y) {
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
	else if (coordenadasJogador.y >= limiteBaixo && coordenadasJogador.y <= limiteCima) {
		if (coordenadasJogador.x >= coordenadas.x) {
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
	//entidade.setSize(Vector2f(dimensoes.x * proporcao, dimensoes.y * proporcao));
	window->draw(entidade);
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
