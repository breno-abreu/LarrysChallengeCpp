#include "Jogador.h"
Jogador::Jogador()
{
	acao = false;

}

Jogador::Jogador(RenderWindow* _window, Texture* _textura, const float cx, const float cy, const int _profundidade, const int _codigo, const int _xTile, const int _yTile):
	Personagem(_window, _textura, cx, cy, _profundidade, _codigo, _xTile, _yTile)
{
	acao = false;
	acaoPressionado = false;
	chaves = 0;
	moedas = 0;
	blueOrb = false;
	redOrb = false;
	greenOrb = false;
	velocidade = 6;
	existe = true;

	hitBox.width = -6;
	hitBox.height = -5;
	hitBox.left = 8;
	hitBox.top = -2;
}

Jogador::~Jogador()
{

}

void Jogador::existir()
{
	entidade.setPosition(coordenadas);

	if (Keyboard::isKeyPressed(Keyboard::Key::Right) ||
		Keyboard::isKeyPressed(Keyboard::Key::Left) ||
		Keyboard::isKeyPressed(Keyboard::Key::Up) ||
		Keyboard::isKeyPressed(Keyboard::Key::Down)) {

		if (Keyboard::isKeyPressed(Keyboard::Key::Right)) {
			coordenadasTile.height = 0;
			coordenadas.x += velocidade;
			direcao = DIREITA;
		}

		else if (Keyboard::isKeyPressed(Keyboard::Key::Left)) {
			coordenadasTile.height = dimensoes.y;
			coordenadas.x -= velocidade;
			direcao = ESQUERDA;
		}

		else if (Keyboard::isKeyPressed(Keyboard::Key::Up)) {
			coordenadas.y -= velocidade;
			coordenadasTile.height = 2 * dimensoes.y;
			direcao = CIMA;
		}

		else if (Keyboard::isKeyPressed(Keyboard::Key::Down)) {
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

	if (Keyboard::isKeyPressed(Keyboard::Key::E) && !acaoPressionado) {
		acaoPressionado = true;
		if (acao)
			acao = false;
		else
			acao = true;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Key::E) && acaoPressionado){
		acao = false;
	}

	if (!Keyboard::isKeyPressed(Keyboard::Key::E)) 
		acaoPressionado = false;
	
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
	window->draw(entidade);
}

bool Jogador::getAcao()const
{
	return acao;
}

void Jogador::setMovimentadorx(const float _velocidade)
{
	coordenadas.x += _velocidade;
}

void Jogador::setMovimentadory(const float _velocidade)
{
	coordenadas.y += _velocidade;
}

bool Jogador::getAcaoPressionado() const
{
	return acaoPressionado;
}

void Jogador::setBlueOrb(const bool _blueOrb)
{
	blueOrb = _blueOrb;
}

void Jogador::setRedOrb(const bool _redOrb)
{
	redOrb = _redOrb;
}

void Jogador::setGreenOrb(const bool _greenOrb)
{
	greenOrb = _greenOrb;
}

void Jogador::adicionarMoeda()
{
	moedas++;
}

void Jogador::adicionarChave()
{
	chaves++;
}

void Jogador::retirarMoeda()
{
	moedas--;
}

void Jogador::retirarChave()
{
	chaves--;
}

bool Jogador::getBlueOrb()const
{
	return blueOrb;
}

bool Jogador::getRedOrb()const
{
	return redOrb;
}

bool Jogador::getGreenOrb()const
{
	return greenOrb;
}

int Jogador::getChaves()const
{
	return chaves;
}

int Jogador::getMoedas()const
{
	return moedas;
}

float Jogador::getHitBoxAux()const
{
	return hitBoxAux;
}