#include "ParedeLevadica.h"

ParedeLevadica::ParedeLevadica()
{
	ativado = false;
	fimAnimacao = false;
	emCima = false;
}

ParedeLevadica::ParedeLevadica(RenderWindow* _window, Texture* _textura, const float cx, const float cy, const int _profundidade, const int _codigo, const int _xTile, const int _yTile):
	SuperficieInterativa(_window, _textura, cx, cy, _profundidade, _codigo, _xTile, _yTile)
{
	ativado = false;
	fimAnimacao = false;
	emCima = false;
	barreira = false;
	coordenadasTile.height = 0;

	hitBox.width = -7;
	hitBox.height = -6;
	hitBox.left = 6;
	hitBox.top = 0;
}

ParedeLevadica::~ParedeLevadica()
{

}

void ParedeLevadica::existir()
{
	if (!ativado) 
		coordenadasTile.width = 0;

	else if (ativado && !emCima && !fimAnimacao) {
		barreira = true;
		if (contAnimacao >= velAnimacao) {
			contAnimacao = 0;
			contFrames++;
			coordenadasTile.width = contFrames * dimensoes.x;

			if (contFrames >= 5)
				fimAnimacao = true;
		}
		contAnimacao++;
	}

	entidade.setTextureRect(IntRect(coordenadasTile.width, coordenadasTile.height, dimensoes.x, dimensoes.y));
	window->draw(entidade);
}

void ParedeLevadica::setAtivado(const bool _ativado)
{
	ativado = _ativado;
}

bool ParedeLevadica::getAtivado()const
{
	return ativado;
}

void ParedeLevadica::setEmCima(const bool _emCima)
{
	emCima = _emCima;
}

bool ParedeLevadica::getEmCima()const
{
	return emCima;
}

bool ParedeLevadica::getBarreira()const
{
	return barreira;
}
