#include "Fase.h"


Fase::Fase()
{
	window = NULL;
	gerenciadorEntidades = NULL;
	listaEntidades = NULL;
}
Fase::Fase(RenderWindow* _window)
{
	window = _window;
	jogador = new Jogador();
	gerenciadorEntidades = new GerenciadorEntidades(window);
	listaEntidades = new ListaEntidades(window, gerenciadorEntidades);
}
Fase::~Fase()
{
	delete listaEntidades;
	delete gerenciadorEntidades;
}

void Fase::adicionar_entidade(const float cx, const float cy, const int tipo, const int conexao)
{
	listaEntidades->adicionar_entidade(cx, cy, tipo);
}

void Fase::executar()
{
	
	listaEntidades->percorrer();
	jogador_item();
	//personagem_barreira();
	jogador_abismo();
	jogador_movimentador();
}

void Fase::jogador_item()
{
	list<Item*>::iterator itr;
	list<Item*> listaItens = gerenciadorEntidades->getListaItens();
	Jogador* jogador = gerenciadorEntidades->getJogador();

	for (itr = listaItens.begin(); itr != listaItens.end(); itr++) {
		if (jogador->getCoordenadas().x < (*itr)->getCoordenadas().x + (*itr)->getDimensoes().x &&
			jogador->getCoordenadas().x + jogador->getDimensoes().x >(*itr)->getCoordenadas().x&&
			jogador->getCoordenadas().y < (*itr)->getCoordenadas().y + (*itr)->getDimensoes().y &&
			jogador->getCoordenadas().y + jogador->getDimensoes().y > (*itr)->getCoordenadas().y) {

			if ((*itr)->getExiste())
				(*itr)->setExiste(false);

			if ((*itr)->getTipo() == CHAVE)
				jogador->adicionarChave();
			else if ((*itr)->getTipo() == MOEDA)
				jogador->adicionarMoeda();
			else if ((*itr)->getTipo() == BLUEORB)
				jogador->setBlueOrb(true);
			else if ((*itr)->getTipo() == REDORB)
				jogador->setRedOrb(true);
			else if ((*itr)->getTipo() == GREENORB)
				jogador->setGreenOrb(true);
		}
	}
}
void Fase::personagem_barreira()
{
	list<Barreira*>::iterator itr;
	list<Barreira*> listaBarreiras = gerenciadorEntidades->getListaBarreiras();
	Jogador* jogador = gerenciadorEntidades->getJogador();

	for (itr = listaBarreiras.begin(); itr != listaBarreiras.end(); itr++) {
		if (jogador->getCoordenadas().x < (*itr)->getCoordenadas().x + (*itr)->getDimensoes().x &&
			jogador->getCoordenadas().x + jogador->getDimensoes().x >(*itr)->getCoordenadas().x&&
			jogador->getCoordenadas().y < (*itr)->getCoordenadas().y + (*itr)->getDimensoes().y &&
			jogador->getCoordenadas().y + jogador->getDimensoes().y >(*itr)->getCoordenadas().y) {

			if (jogador->getDirecao() == DIREITA)
				jogador->setxEntidade(jogador->getCoordenadas().x - jogador->getVelocidade());
			else if (jogador->getDirecao() == ESQUERDA)
				jogador->setxEntidade(jogador->getCoordenadas().x + jogador->getVelocidade());
			else if (jogador->getDirecao() == CIMA)
				jogador->setyEntidade(jogador->getCoordenadas().y + jogador->getVelocidade());
			else if (jogador->getDirecao() == BAIXO)
				jogador->setyEntidade(jogador->getCoordenadas().y - jogador->getVelocidade());
				
		}
	}
}

void Fase::jogador_abismo()
{
	list<Abismo*>::iterator itr;
	list<Abismo*> listaAbismo = gerenciadorEntidades->getListaAbismo();
	Jogador* jogador = gerenciadorEntidades->getJogador();

	for (itr = listaAbismo.begin(); itr != listaAbismo.end(); itr++) {
		if (jogador->getCoordenadas().x < (*itr)->getCoordenadas().x + (*itr)->getDimensoes().x &&
			jogador->getCoordenadas().x + jogador->getDimensoes().x >(*itr)->getCoordenadas().x&&
			jogador->getCoordenadas().y < (*itr)->getCoordenadas().y + (*itr)->getDimensoes().y &&
			jogador->getCoordenadas().y + jogador->getDimensoes().y >(*itr)->getCoordenadas().y) {

			jogador->setExiste(false);
		}
	}
}

void Fase::jogador_inimigo()
{
	list<Inimigo*>::iterator itr;
	list<Inimigo*> listaInimigos = gerenciadorEntidades->getListaInimigos();
	Jogador* jogador = gerenciadorEntidades->getJogador();

	for (itr = listaInimigos.begin(); itr != listaInimigos.end(); itr++) {
		if (jogador->getCoordenadas().x < (*itr)->getCoordenadas().x + (*itr)->getDimensoes().x &&
			jogador->getCoordenadas().x + jogador->getDimensoes().x >(*itr)->getCoordenadas().x&&
			jogador->getCoordenadas().y < (*itr)->getCoordenadas().y + (*itr)->getDimensoes().y &&
			jogador->getCoordenadas().y + jogador->getDimensoes().y >(*itr)->getCoordenadas().y) {

			jogador->setExiste(false);
		}
	}
}

void Fase::jogador_movimentador()
{
	list<Movimentador*>::iterator itr;
	list<Movimentador*> listaMovimentadores = gerenciadorEntidades->getListaMovimentadores();
	Jogador* jogador = gerenciadorEntidades->getJogador();

	float velocidade = 10;

	for (itr = listaMovimentadores.begin(); itr != listaMovimentadores.end(); itr++) {
		if (jogador->getCoordenadas().x < (*itr)->getCoordenadas().x + (*itr)->getDimensoes().x &&
			jogador->getCoordenadas().x + jogador->getDimensoes().x >(*itr)->getCoordenadas().x&&
			jogador->getCoordenadas().y < (*itr)->getCoordenadas().y + (*itr)->getDimensoes().y &&
			jogador->getCoordenadas().y + jogador->getDimensoes().y >(*itr)->getCoordenadas().y) {

			if ((*itr)->getDirecao() == DIREITA)
				jogador->setMovimentadorx(velocidade);
			else if ((*itr)->getDirecao() == ESQUERDA)
				jogador->setMovimentadorx(-velocidade);
			else if ((*itr)->getDirecao() == CIMA)
				jogador->setMovimentadory(-velocidade);
			else if ((*itr)->getDirecao() == BAIXO)
				jogador->setMovimentadory(velocidade);
		}
	}
}