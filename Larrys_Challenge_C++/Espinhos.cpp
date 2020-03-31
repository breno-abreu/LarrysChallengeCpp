#include "Espinhos.h"
Espinhos::Espinhos()
{

}

Espinhos::Espinhos(RenderWindow* _window, Texture* _textura, const float cx, const float cy, const int _profundidade, const int _codigo, const int _xTile, const int _yTile, const int _conexao):
	Letal(_window, _textura, cx, cy, _profundidade, _codigo, _xTile, _yTile)
{
	conexao = _conexao;
	desativado = true;
	hitBox.height = -44;
	ativado = true;
}

Espinhos::~Espinhos()
{

}

void Espinhos::existir()
{
	if (ativado) {
		if (contAnimacao >= velAnimacao) {
			coordenadasTile.width = contFrames * dimensoes.x;
			contFrames++;
			if (contFrames >= 7)
				contFrames = 0;

			contAnimacao = 0;
		}
		contAnimacao++;

		if (contFrames == 0)
			desativado = true;
		else
			desativado = false;
	}
	else
		coordenadasTile.width = 0;

	entidade.setTextureRect(IntRect(coordenadasTile.width, coordenadasTile.height, dimensoes.x, dimensoes.y));
	window->draw(entidade);
}

bool Espinhos::getDesativado()const
{
	return desativado;
}

void Espinhos::setAtivado(const bool _ativado)
{
	ativado = _ativado;
}

bool Espinhos::getAtivado()const
{
	return ativado;
}