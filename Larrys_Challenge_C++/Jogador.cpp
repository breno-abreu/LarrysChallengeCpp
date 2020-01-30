#include "Jogador.h"
Jogador::Jogador()
{
	acao = false;

}
Jogador::Jogador(RenderWindow* _window, const float cx, const float cy, const int _codigo):
	Personagem(_window, cx, cy, _codigo)
{
	acao = false;
	textura->loadFromFile("Tiny Dungeon Pack/Character/Character.png");

	dimensoes.x = (textura->getSize().x / quantidadeTile.x);
	dimensoes.y = (textura->getSize().y / quantidadeTile.y);
	entidade.setPosition(coordenadas.x, coordenadas.y);
	entidade.setSize(dimensoes);
	entidade.setTexture(textura);
}
Jogador::~Jogador()
{

}
void Jogador::existir()
{
	if (acao)
		acao = false;

	if (Keyboard::isKeyPressed(Keyboard::Key::Right) ||
		Keyboard::isKeyPressed(Keyboard::Key::Left) ||
		Keyboard::isKeyPressed(Keyboard::Key::Up) ||
		Keyboard::isKeyPressed(Keyboard::Key::Down)) {

		if (Keyboard::isKeyPressed(Keyboard::Key::Right)) {
			coordenadasTile.height = 0;
			coordenadas.x += velocidade;
			direcao = DIREITA;
		}

		if (Keyboard::isKeyPressed(Keyboard::Key::Left)) {
			coordenadasTile.height = dimensoes.y;
			coordenadas.x -= velocidade;
			direcao = ESQUERDA;
		}

		if (Keyboard::isKeyPressed(Keyboard::Key::Up)) {
			coordenadas.y -= velocidade;
			coordenadasTile.height = 2 * dimensoes.y;
			direcao = CIMA;
		}

		if (Keyboard::isKeyPressed(Keyboard::Key::Down)) {
			coordenadas.y += velocidade;
			coordenadasTile.height = 3 * dimensoes.y;
			direcao = BAIXO;
		}
	}
	else{
		if (direcao == DIREITA)
			coordenadasTile.height = 4 * dimensoes.y;

		else if (direcao == ESQUERDA)
			coordenadasTile.height = 5 * dimensoes.y;

		else if (direcao == CIMA)
			coordenadasTile.height = 6 * dimensoes.y;

		else if (direcao == BAIXO)
			coordenadasTile.height = 7 * dimensoes.y;
	}
	
	


	if (Keyboard::isKeyPressed(Keyboard::Key::E))
		acao = true;

	contAnimacao++;

	if (contAnimacao >= velAnimacao) {
		contAnimacao = 0;
		contFrames++;
		coordenadasTile.width = contFrames * dimensoes.x;

		if (coordenadasTile.width >= 6 * dimensoes.x) {
			coordenadasTile.width = 0;
		}

		if (contFrames > 5) {
			contFrames = 0;
		}
	}

	entidade.setTextureRect(IntRect(coordenadasTile.width, coordenadasTile.height, dimensoes.x, dimensoes.y));
	entidade.setPosition(coordenadas.x, coordenadas.y);
	entidade.setSize(Vector2f(dimensoes.x * proporcao, dimensoes.y * proporcao));
	window->draw(entidade);
}

bool Jogador::getAcao()const
{
	return acao;
}