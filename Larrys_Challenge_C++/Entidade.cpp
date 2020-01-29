#include "Entidade.h"


Entidade::Entidade()
{
	codigo = 0;
	coordenadas.x = 0;
	coordenadas.y = 0;
	profundidade = 0;
	dimensoes.height = 0;
	dimensoes.width = 0;
	existe = false;
	proporcao = 0;
	window = NULL;
	textura = NULL;

	//dimensoes.width = textura->getSize().x / (float)quantidadeTile.x;
	//dimensoes.height = textura->getSize().y / (float)quantidadeTile.y;
}
Entidade::~Entidade()
{

}
float Entidade::getcx() const
{
	return cx;
}
float Entidade::getcy() const
{
	return cy;
}
int Entidade::getProfundidade() const
{
	return profundidade;
}
int Entidade::getComprimento() const
{
	return comprimento;
}
int Entidade::getAltura() const
{
	return altura;
}
bool Entidade::getExistir() const
{
	return existe;
}