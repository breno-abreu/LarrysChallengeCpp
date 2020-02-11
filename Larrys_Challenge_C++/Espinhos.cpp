#include "Espinhos.h"
Espinhos::Espinhos()
{

}
Espinhos::Espinhos(RenderWindow* _window, Texture* _textura, const float cx, const float cy, const int _profundidade, const int _codigo):
	Letal(_window, _textura, cx, cy, _profundidade, _codigo)
{

}
Espinhos::~Espinhos()
{

}
void Espinhos::existir()
{
	if (contAnimacao >= velAnimacao) {
		coordenadasTile.width = contFrames * dimensoes.x;
		contFrames++;
		if (contFrames >= 7)
			contFrames = 0;

		contAnimacao = 0;
	}
	contAnimacao++;

	entidade.setTextureRect(IntRect(coordenadasTile.width, coordenadasTile.height, dimensoes.x, dimensoes.y));
	window->draw(entidade);
}