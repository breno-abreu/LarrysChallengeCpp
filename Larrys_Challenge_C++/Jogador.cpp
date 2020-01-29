#include "Jogador.h"
Jogador::Jogador()
{
	acao = false;

}
Jogador::~Jogador()
{

}
void Jogador::existir()
{
	if (acao)
		acao = false;

	if (Keyboard::isKeyPressed(Keyboard::Key::Right)){
		coordenadasTile.height = 0;
		coordenadas.x += velocidade;
		direcao = DIREITA;
	}
		
	else if (Keyboard::isKeyPressed(Keyboard::Key::Left)){
		coordenadasTile.height = dimensoes.height;
		coordenadas.x -= velocidade;
		direcao = ESQUERDA;
	}
		
	else if (Keyboard::isKeyPressed(Keyboard::Key::Up)) {
		coordenadas.y -= velocidade;
		coordenadasTile.height = 2 * dimensoes.height;
		direcao = CIMA;
	}
		
	else if (Keyboard::isKeyPressed(Keyboard::Key::Down)) {
		coordenadas.y += velocidade;
		coordenadasTile.height = 3 * dimensoes.height;
		direcao = DIREITA;
	}
	
	else if (direcao == BAIXO) 
		coordenadasTile.height = 4 * dimensoes.height;

	else if (direcao == ESQUERDA)
		coordenadasTile.height = 5 * dimensoes.height;

	else if (direcao == CIMA)
		coordenadasTile.height = 6 * dimensoes.height;

	else if (direcao == BAIXO)
		coordenadasTile.height = 7 * dimensoes.height;


	if (Keyboard::isKeyPressed(Keyboard::Key::E))
		acao = true;

	contAnimacao++;

	if (contAnimacao >= velAnimacao) {
		contAnimacao = 0;
		contFrames++;
		coordenadasTile.width += contFrames * dimensoes.width;

		if (coordenadasTile.width >= 6 * dimensoes.width)
			coordenadasTile.width = 0;
	}

	entidade.setTextureRect(coordenadasTile);
	window->draw(entidade);
}

bool Jogador::getAcao()const
{
	return acao;
}