#include "Zumbi.h"

Zumbi::Zumbi()
{

}
Zumbi::Zumbi(RenderWindow* _window, const float cx, const float cy, const int _codigo):
	Inimigo(_window, cx, cy, _codigo)
{
	textura->loadFromFile("Tiny Dungeon Pack/Enemies/Zombie/Zombie.png");
	dimensoes.x = (textura->getSize().x / quantidadeTile.x);
	dimensoes.y = (textura->getSize().y / quantidadeTile.y);
	entidade.setPosition(coordenadas.x, coordenadas.y);
	entidade.setSize(dimensoes);
	entidade.setTexture(textura);
}
Zumbi::~Zumbi()
{

}
void Zumbi::existir()
{
	/*if (x - x0 != 0)
		ax = (y - y0) / (x - x0);

	bx = y0 - ax * x0;

	ax2 = 1 + ax * ax;
	bx2 = (-2 * x0) + (2 * ax * bx) + (-2 * y0 * ax);
	cx2 = (bx * bx) + (-2 * y0 * bx) + (x0 * x0) + (y0 * y0) - (d * d);

	raiz1 = (-bx2 + sqrt((bx2 * bx2) - (4 * ax2 * cx2)) / (2 * ax2);
	raiz2 = (-bx2 - sqrt((bx2 * bx2) - (4 * ax2 * cx2)) / (2 * ax2);

	if (x > x0)
		x0 = raiz1;
	else
		x0 = raiz2;

	(x > x0 ? x0 = raiz1 : x0 = raiz2);




	y0 = ax * x0 + bx;*/
}

void Zumbi::setCoodenadasJogador(const float jx, const float jy)
{
	coordenadasJogador.x = jx;
	coordenadasJogador.y = jy;
}
