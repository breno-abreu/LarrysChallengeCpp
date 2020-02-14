#pragma once
#include "bibliotecas.h"
#include "Personagem.h"

class Jogador : public Personagem
{
private:
	bool acao;
	bool acaoPressionado;
	int chaves;
	int moedas;
	bool blueOrb;
	bool redOrb;
	bool greenOrb;

public:
	Jogador();
	Jogador(RenderWindow* _window, Texture* _textura, const float cx, const float cy, const int _profundidade, const int _codigo, const int _xTile, const int _yTile);
	~Jogador();
	void existir();
	bool getAcao()const;
	void setMovimentadorx(const float _velocidade);
	void setMovimentadory(const float _velocidade);
	bool getAcaoPressionado() const;
	//int getDirecao()const;
	void setBlueOrb(const bool _blueOrb);
	void setRedOrb(const bool _redOrb);
	void setGreenOrb(const bool _greenOrb);
	void adicionarMoeda();
	void adicionarChave();
	void retirarMoeda();
	void retirarChave();
	bool getBlueOrb()const;
	bool getRedOrb()const;
	bool getGreenOrb()const;
	int getChaves()const;
	int getMoedas()const;

};

