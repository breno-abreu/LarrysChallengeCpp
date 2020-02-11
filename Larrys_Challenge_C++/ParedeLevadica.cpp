#include "ParedeLevadica.h"

ParedeLevadica::ParedeLevadica()
{
	ativado = false;
	fimAnimacao = false;
	emCima = false;
}
ParedeLevadica::ParedeLevadica(RenderWindow* _window, Texture* _textura, const float cx, const float cy, const int _profundidade, const int _codigo):
	SuperficieInterativa(_window, _textura, cx, cy, _profundidade, _codigo)
{
	ativado = false;
	fimAnimacao = false;
	emCima = false;
	coordenadasTile.height = 0;
}
ParedeLevadica::~ParedeLevadica()
{

}
void ParedeLevadica::existir()
{
	if (!ativado) 
		coordenadasTile.width = 0;

	else if (ativado && !emCima && !fimAnimacao) {
		if (contAnimacao >= velAnimacao) {
			contAnimacao = 0;
			contFrames++;
			coordenadasTile.width = contFrames * dimensoes.x;

			if (contFrames >= 6)
				fimAnimacao = true;
		}
		contAnimacao++;
	}

	else if (fimAnimacao) 
		coordenadasTile.width = 5 * dimensoes.x;

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