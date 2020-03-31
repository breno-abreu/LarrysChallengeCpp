#pragma once
#include "bibliotecas.h"
#include "Personagem.h"

class Jogador : public Personagem
{
private:
	bool acao;
	bool acaoPressionado;
	bool blueOrb;
	bool greenOrb;
	bool redOrb;
	float hitBoxAux;
	int chaves;
	int moedas;

public:
	Jogador();
	Jogador(RenderWindow* _window, Texture* _textura, const float cx, const float cy, const int _profundidade, const int _codigo, const int _xTile, const int _yTile);
	~Jogador();
	bool getAcao()const;
	bool getAcaoPressionado() const;
	bool getBlueOrb()const;
	bool getGreenOrb()const;
	bool getRedOrb()const;
	float getHitBoxAux()const;
	int getChaves()const;
	int getMoedas()const;
	void adicionarChave();
	void adicionarMoeda();
	void existir();
	void retirarChave();
	void retirarMoeda();
	void setBlueOrb(const bool _blueOrb);
	void setGreenOrb(const bool _greenOrb);
	void setMovimentadorx(const float _velocidade);
	void setMovimentadory(const float _velocidade);
	void setRedOrb(const bool _redOrb);
};

