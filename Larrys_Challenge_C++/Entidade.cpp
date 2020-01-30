#include "Entidade.h"


Entidade::Entidade()
{
	codigo = 0;
	coordenadas.x = 0;
	coordenadas.y = 0;
	profundidade = 0;
	dimensoes.x = 0;
	dimensoes.y = 0;
	existe = false;
	proporcao = 0;
	window = NULL;
	textura = NULL;

	//dimensoes.width = textura->getSize().x / (float)quantidadeTile.x;
	//dimensoes.height = textura->getSize().y / (float)quantidadeTile.y;
}

Entidade::Entidade(RenderWindow* _window, const float cx, const float cy, const int _codigo)
{
	codigo = _codigo;
	coordenadas.x = cx;
	coordenadas.y = cy;
	profundidade = 0;

	textura = new Texture();
	
	proporcao = 5;
	quantidadeTile.x = 6;
	quantidadeTile.y = 8;
	existe = true;
	
	contAnimacao = 0;
	velAnimacao = 7;
	contFrames = 0;
	coordenadasTile.width = 0;
	coordenadasTile.height = 0;
	window = _window;

	entidade.setPosition(coordenadas.x, coordenadas.y);
}
Entidade::~Entidade()
{
	delete textura;
}

Vector2f Entidade::getCoordenadas() const
{
	return coordenadas;
}

Vector2f Entidade::getDimensoes() const
{
	return dimensoes;
}
int Entidade::getProfundidade() const
{
	return profundidade;
}
bool Entidade::getExistir() const
{
	return existe;
}