#include "Escada.h"
Escada::Escada()
{
	tipo = 0;
}
Escada::Escada(RenderWindow* _window, Texture* _textura, const float cx, const float cy, const int _profundidade, const int _codigo, const int _tipo):
	Interativo(_window, _textura, cx, cy, _profundidade, _codigo)
{
	tipo = _tipo;
	coordenadasTile.height = 0;

	if (tipo == CIMA)
		coordenadasTile.width = 0;
	else if(tipo == BAIXO)
		coordenadasTile.width = dimensoes.x;

	entidade.setTextureRect(IntRect(coordenadasTile.width, coordenadasTile.height, dimensoes.x, dimensoes.y));
}
Escada::~Escada()
{
	
}
void Escada::existir()
{
	window->draw(entidade);
}
int Escada::getTipo()const
{
	return tipo;
}