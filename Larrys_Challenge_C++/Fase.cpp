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
	jogador_barreira();
	jogador_abismo();
	jogador_movimentador();
	jogador_botao();
	jogador_parede_levadica();
	jogador_espinhos();
	jogador_interativo();
	jogador_caixas();
	jogador_portais();
}

Vector2f Fase::getCoordenadasJogador()const
{
	Jogador* jogador = gerenciadorEntidades->getJogador();
	Vector2f coordenadas =  jogador->getCoordenadas();
	coordenadas.y += 100;
	return coordenadas;
}

bool Fase::getJogadorVivo()const
{
	Jogador* jogador = gerenciadorEntidades->getJogador();
	return jogador->getExiste();
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
void Fase::jogador_barreira()
{
	list<Barreira*>::iterator itr;
	list<Barreira*> listaBarreiras = gerenciadorEntidades->getListaBarreiras();
	Jogador* jogador = gerenciadorEntidades->getJogador();

	for (itr = listaBarreiras.begin(); itr != listaBarreiras.end(); itr++) {
		if (jogador->getCoordenadas().x  + 6 < (*itr)->getCoordenadas().x + (*itr)->getDimensoes().x &&
			jogador->getCoordenadas().x + jogador->getDimensoes().x > (*itr)->getCoordenadas().x &&
			jogador->getCoordenadas().y - 6 < (*itr)->getCoordenadas().y + (*itr)->getDimensoes().y &&
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

void Fase::jogador_botao()
{
	list<Botao*>::iterator itr;
	list<Botao*> listaBotoes = gerenciadorEntidades->getListaBotoes();
	Jogador* jogador = gerenciadorEntidades->getJogador();

	float hitBox = 20;

	for (itr = listaBotoes.begin(); itr != listaBotoes.end(); itr++) {
		if (jogador->getCoordenadas().x < (*itr)->getCoordenadas().x + (*itr)->getDimensoes().x - hitBox &&
			jogador->getCoordenadas().x + jogador->getDimensoes().x >(*itr)->getCoordenadas().x + hitBox &&
			jogador->getCoordenadas().y < (*itr)->getCoordenadas().y + (*itr)->getDimensoes().y - hitBox * 2 &&
			jogador->getCoordenadas().y + jogador->getDimensoes().y >(*itr)->getCoordenadas().y + hitBox) {

			(*itr)->setAtivado(true);
		}
		else
			(*itr)->setAtivado(false);
	}
}

void Fase::jogador_parede_levadica()
{
	list<ParedeLevadica*>::iterator itr;
	list<ParedeLevadica*> listaParedesLevadicas = gerenciadorEntidades->getListaParedesLevadicas();
	Jogador* jogador = gerenciadorEntidades->getJogador();

	for (itr = listaParedesLevadicas.begin(); itr != listaParedesLevadicas.end(); itr++) {
		if (jogador->getCoordenadas().x < (*itr)->getCoordenadas().x + (*itr)->getDimensoes().x &&
			jogador->getCoordenadas().x + jogador->getDimensoes().x >(*itr)->getCoordenadas().x &&
			jogador->getCoordenadas().y < (*itr)->getCoordenadas().y + (*itr)->getDimensoes().y &&
			jogador->getCoordenadas().y + jogador->getDimensoes().y >(*itr)->getCoordenadas().y) {

			(*itr)->setEmCima(true);

			if (!(*itr)->getAtivado()) {
				(*itr)->setAtivado(true);
			}
			else if((*itr)->getAtivado() && (*itr)->getBarreira()){
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
		else
			(*itr)->setEmCima(false);
	}
}

void Fase::jogador_espinhos()
{
	list<Espinhos*>::iterator itr;
	list<Espinhos*> listaEspinhos = gerenciadorEntidades->getListaEspinhos();
	Jogador* jogador = gerenciadorEntidades->getJogador();

	for (itr = listaEspinhos.begin(); itr != listaEspinhos.end(); itr++) {
		if (jogador->getCoordenadas().x < (*itr)->getCoordenadas().x + (*itr)->getDimensoes().x &&
			jogador->getCoordenadas().x + jogador->getDimensoes().x >(*itr)->getCoordenadas().x&&
			jogador->getCoordenadas().y < (*itr)->getCoordenadas().y + (*itr)->getDimensoes().y &&
			jogador->getCoordenadas().y + jogador->getDimensoes().y >(*itr)->getCoordenadas().y) {

			if (!(*itr)->getDesativado()){
				//jogador morre
			}
		}
	}
}

void Fase::jogador_interativo()
{
	list<Interativo*>::iterator itr;
	list<Interativo*> listaInterativos = gerenciadorEntidades->getListaInterativos();
	Jogador* jogador = gerenciadorEntidades->getJogador();

	for (itr = listaInterativos.begin(); itr != listaInterativos.end(); itr++) {
		if (jogador->getCoordenadas().x < (*itr)->getCoordenadas().x + (*itr)->getDimensoes().x &&
			jogador->getCoordenadas().x + jogador->getDimensoes().x >(*itr)->getCoordenadas().x&&
			jogador->getCoordenadas().y < (*itr)->getCoordenadas().y + (*itr)->getDimensoes().y &&
			jogador->getCoordenadas().y + jogador->getDimensoes().y >(*itr)->getCoordenadas().y) {

			if (jogador->getAcao() && (*itr)->getAtivado())
				(*itr)->setAtivado(false);

			else if (jogador->getAcao() && !(*itr)->getAtivado())
				(*itr)->setAtivado(true);

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

void Fase::jogador_caixas()
{
	list<Caixa*>::iterator itr;
	list<Caixa*> listaCaixas = gerenciadorEntidades->getListaCaixas();
	Jogador* jogador = gerenciadorEntidades->getJogador();

	for (itr = listaCaixas.begin(); itr != listaCaixas.end(); itr++) {
		if (jogador->getCoordenadas().x < (*itr)->getCoordenadas().x + (*itr)->getDimensoes().x &&
			jogador->getCoordenadas().x + jogador->getDimensoes().x >(*itr)->getCoordenadas().x &&
			jogador->getCoordenadas().y < (*itr)->getCoordenadas().y + (*itr)->getDimensoes().y &&
			jogador->getCoordenadas().y + jogador->getDimensoes().y >(*itr)->getCoordenadas().y) {

			if (jogador->getDirecao() == DIREITA) {
				jogador->setxEntidade(jogador->getCoordenadas().x - (*itr)->getPeso());
				(*itr)->setxEntidade(jogador->getCoordenadas().x + jogador->getDimensoes().x);
			}

			else if (jogador->getDirecao() == ESQUERDA) {
				jogador->setxEntidade(jogador->getCoordenadas().x + (*itr)->getPeso());
				(*itr)->setxEntidade(jogador->getCoordenadas().x - (*itr)->getDimensoes().x);
			}
				
			else if (jogador->getDirecao() == CIMA) {
				jogador->setyEntidade(jogador->getCoordenadas().y + (*itr)->getPeso());
				(*itr)->setyEntidade(jogador->getCoordenadas().y - (*itr)->getDimensoes().y);
			}
				
			else if (jogador->getDirecao() == BAIXO) {
				jogador->setyEntidade(jogador->getCoordenadas().y - (*itr)->getPeso());
				(*itr)->setyEntidade(jogador->getCoordenadas().y + jogador->getDimensoes().y);
			}
		}
	}
}

void Fase::jogador_portais()
{
	list<Interativo*>::iterator itr;
	list<Interativo*> listaPortais = gerenciadorEntidades->getListaPortais();
	Jogador* jogador = gerenciadorEntidades->getJogador();

	for (itr = listaPortais.begin(); itr != listaPortais.end(); itr++) {
		if (jogador->getCoordenadas().x < (*itr)->getCoordenadas().x + (*itr)->getDimensoes().x &&
			jogador->getCoordenadas().x + jogador->getDimensoes().x >(*itr)->getCoordenadas().x&&
			jogador->getCoordenadas().y < (*itr)->getCoordenadas().y + (*itr)->getDimensoes().y &&
			jogador->getCoordenadas().y + jogador->getDimensoes().y >(*itr)->getCoordenadas().y) {

			if (jogador->getAcao()) {

			}

		}
	}
}