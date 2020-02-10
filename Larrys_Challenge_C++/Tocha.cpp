#include "Tocha.h"
Tocha::Tocha()
{

}
Tocha::Tocha(RenderWindow* _window, Texture* _textura, const float cx, const float cy, const int _profundidade, const int _codigo):
	Entidade(_window, _textura, cx, cy, _profundidade, _codigo)
{

}
Tocha::~Tocha()
{

}
void Tocha::existir()
{
	if (contAnimacao >= velAnimacao) {
		coordenadasTile.width = contFrames * dimensoes.x;
		contFrames++;
		if (contFrames >= 6)
			contFrames = 0;

		contAnimacao = 0;
	}
	contAnimacao++;

	entidade.setTextureRect(IntRect(coordenadasTile.width, coordenadasTile.height, dimensoes.x, dimensoes.y));
	//entidade.setSize(Vector2f(dimensoes.x * proporcao, dimensoes.y * proporcao));
	window->draw(entidade);
}