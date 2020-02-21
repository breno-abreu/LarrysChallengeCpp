#include "Entidade.h"


Entidade::Entidade()
{
	codigo = 0;
	coordenadas.x = 0;
	coordenadas.y = 0;
	profundidade = 0;
	dimensoes.x = 0;
	dimensoes.y = 0;
	existe = true;
	proporcao = 0;
	window = NULL;
	textura = NULL;

	//dimensoes.width = textura->getSize().x / (float)quantidadeTile.x;
	//dimensoes.height = textura->getSize().y / (float)quantidadeTile.y;
}

Entidade::Entidade(RenderWindow* _window, Texture* _textura, const float cx, const float cy, const int _profundidade, const int _codigo, const int _xTile, const int _yTile)
{
	codigo = _codigo;
	/*coordenadas.x = cx;
	coordenadas.y = cy;*/
	profundidade = _profundidade;
	textura = _textura;
	
	proporcao = 3;
	/*quantidadeTile.x = 1;
	quantidadeTile.y = 1;*/
	existe = true;
	classe = 0;
	contAnimacao = 0;
	velAnimacao = 7;
	contFrames = 0;
	coordenadasTile.width = 0;
	coordenadasTile.height = 0;
	window = _window;
	/*dimensoes.x = textura->getSize().x;
	dimensoes.y = textura->getSize().y;
	dimensoesAux.x = dimensoes.x * proporcao;
	dimensoesAux.y = dimensoes.y * proporcao;
	entidade.setSize(dimensoesAux);*/
	entidade.setTexture(textura);
	coordenadas.x = cx;
	coordenadas.y = cy;
	entidade.setPosition(coordenadas);

	quantidadeTile.x = _xTile;
	quantidadeTile.y = _yTile;
	dimensoes.x = (textura->getSize().x / quantidadeTile.x);
	dimensoes.y = (textura->getSize().y / quantidadeTile.y);
	dimensoesAux.x = dimensoes.x * proporcao;
	dimensoesAux.y = dimensoes.y * proporcao;
	entidade.setSize(dimensoesAux);
	entidade.setOrigin(Vector2f(dimensoesAux.x / 2, dimensoesAux.y / 2));

	


	hitBox.width = 0;
	hitBox.height = 0;
	hitBox.left = 0;
	hitBox.top = 0;


}
Entidade::~Entidade()
{
	delete textura;
}

int Entidade::getClasse()const
{
	return classe;
}

Vector2f Entidade::getCoordenadas() const
{
	return coordenadas;
}

Vector2f Entidade::getDimensoes() const
{
	return dimensoesAux;
}
int Entidade::getProfundidade() const
{
	return profundidade;
}
bool Entidade::getExiste() const
{
	return existe;
}

void Entidade::setExiste(const bool _existe)
{
	existe = _existe;
}

void Entidade::setxEntidade(const float x)
{
	coordenadas.x = x;
}
void Entidade::setyEntidade(const float y)
{
	coordenadas.y = y;
}
int Entidade::getCodigo()const
{
	return codigo;
}

FloatRect Entidade::getHitBox() const
{
	return hitBox;
}