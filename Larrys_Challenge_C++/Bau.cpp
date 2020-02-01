#include "Bau.h"

Bau::Bau()
{

}
Bau::Bau(RenderWindow* _window, const float cx, const float cy, const int _codigo):
	Interativo(_window, cx, cy, _codigo)
{
	textura->loadFromFile("Tiny Dungeon Pack/Misc/Big_treasure_chest.png");
	quantidadeTile.x = 6;
	quantidadeTile.y = 1;
	dimensoes.x = (textura->getSize().x / quantidadeTile.x);
	dimensoes.y = (textura->getSize().y / quantidadeTile.y);
	dimensoesAux.x = dimensoes.x * proporcao;
	dimensoesAux.y = dimensoes.x * proporcao;
	entidade.setPosition(coordenadas.x, coordenadas.y);
	entidade.setSize(dimensoes);
	entidade.setTexture(textura);
	coordenadasTile.height = 0;
	coordenadasTile.width = 0;
	velAnimacao = 7;
	fim = false;
}
Bau::~Bau()
{

}
void Bau::existir()
{
	if (ativado && !fim) {
		if (contAnimacao >= velAnimacao) {
			coordenadasTile.width = contFrames * dimensoes.x;
			contFrames++;
			if (contFrames >= 6) {
				ativado = false;
				fim = true;
			}
			contAnimacao = 0;
		}
		contAnimacao++;
	}

	entidade.setTextureRect(IntRect(coordenadasTile.width, coordenadasTile.height, dimensoes.x, dimensoes.y));
	entidade.setSize(Vector2f(dimensoes.x * proporcao, dimensoes.y * proporcao));
	window->draw(entidade);
}
