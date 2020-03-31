#include "PassagemSecreta.h"

PassagemSecreta::PassagemSecreta()
{

}

PassagemSecreta::PassagemSecreta(RenderWindow* _window, Texture* _textura, const float cx, const float cy, const int _profundidade, const int _codigo, const int _xTile, const int _yTile):
	Interativo(_window, _textura, cx, cy, _profundidade, _codigo, _xTile, _yTile)
{
	ativado = true;
}

PassagemSecreta::~PassagemSecreta()
{

}

void PassagemSecreta::existir()
{
	if(ativado)
		window->draw(entidade);
}