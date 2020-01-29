#include "Jogador.h"
Jogador::Jogador()
{

}
Jogador::~Jogador()
{

}
void Jogador::existir()
{
	if (acao)
		acao = false;

	if (Keyboard::isKeyPressed(Keyboard::Key::Right)) 
		movimentarDireita();

	if (Keyboard::isKeyPressed(Keyboard::Key::Left)) 
		movimentarEsquerda();

	if (Keyboard::isKeyPressed(Keyboard::Key::Up)) 
		movimentarCima();

	if (Keyboard::isKeyPressed(Keyboard::Key::Down)) 
		movimentarBaixo();

	if (Keyboard::isKeyPressed(Keyboard::Key::E)) 
		acao = true;
}
void Jogador::movimentarDireita()
{
	cx += velocidade;
}
void Jogador::movimentarEsquerda()
{
	cx -= velocidade;
}
void Jogador::movimentarCima()
{
	cy -= velocidade;
}
void Jogador::movimentarBaixo()
{
	cy += velocidade;
}
bool Jogador::getAcao()const
{
	return acao;
}