#include "PassagemSecreta.h"
PassagemSecreta::PassagemSecreta()
{

}
PassagemSecreta::PassagemSecreta(RenderWindow* _window, Texture* _textura, const float cx, const float cy, const int _profundidade, const int _codigo):
	Interativo(_window, _textura, cx, cy, _profundidade, _codigo)
{

}
PassagemSecreta::~PassagemSecreta()
{

}
void PassagemSecreta::existir()
{
	if(ativado)
		window->draw(entidade);
}