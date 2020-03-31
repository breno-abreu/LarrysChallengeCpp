#include "Rato.h"
Rato::Rato()
{

}

Rato::Rato(RenderWindow* _window, Texture* _textura, const float cx, const float cy, const int _profundidade, const int _codigo, const int _xTile, const int _yTile, const int _direcao):
	Inimigo(_window, _textura, cx, cy, _profundidade, _codigo, _xTile, _yTile)
{
	coordenadasTile.width = 0;
	coordenadasTile.height = 0;
	direcao = _direcao;
	velocidade = 4;
	posicao = 0;
	velAnimacao = 6;
}
Rato::~Rato()
{

}

void Rato::existir()
{
	if (direcao == DIREITA) {
		coordenadas.x += velocidade;
		coordenadasTile.height = 2 * dimensoes.y;
	}
	else if (direcao == ESQUERDA) {
		coordenadas.x -= velocidade;
		coordenadasTile.height = dimensoes.y;
	}
	else if (direcao == BAIXO) {
		coordenadas.y += velocidade;
		coordenadasTile.height = 0;
	}
	else if (direcao == CIMA) {
		coordenadas.y -= velocidade;
		coordenadasTile.height = 3 * dimensoes.y;
	}

	if (contAnimacao >= velAnimacao) {
		if (posicao == 0)
			posicao = 1;
		else
			posicao = 0;

		contAnimacao = 0;
	}
	contAnimacao++;
	coordenadasTile.width = posicao * dimensoes.x;

	entidade.setTextureRect(IntRect(coordenadasTile.width, coordenadasTile.height, dimensoes.x, dimensoes.y));
	entidade.setPosition(coordenadas.x, coordenadas.y);
	window->draw(entidade);
}

void Rato::setDirecao(const int _direcao)
{
	direcao = _direcao;
}

void Rato::alterar_direcao()
{
	if (direcao == DIREITA)
		direcao = CIMA;
	else if (direcao == CIMA)
		direcao = ESQUERDA;
	else if (direcao == ESQUERDA)
		direcao = BAIXO;
	else
		direcao = DIREITA;
}

int Rato::getDirecao()const
{
	return direcao;
}