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

void Fase::excluir_entidades()
{

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
	atiradores();
	flecha_barreira();
	jogador_flecha();
	flecha_caixa();
	caixa_botao();
	
	
}

bool Fase::verificar_colisao(Entidade* a, Entidade* b)
{
	if (a->getHitBox().left < b->getHitBox().left + b->getHitBox().width &&
		a->getHitBox().left + a->getHitBox().width > b->getHitBox().left &&
		a->getHitBox().top < b->getHitBox().top + b->getHitBox().height &&
		a->getHitBox().top + a->getHitBox().height > b->getHitBox().top) {
		return true;
	}
	return false;

	/*if (a->getCoordenadas().x < b->getCoordenadas().x + b->getDimensoes().x &&
		a->getCoordenadas().x + a->getDimensoes().x > b->getCoordenadas().x &&
		a->getCoordenadas().y < b->getCoordenadas().y + b->getDimensoes().y &&
		a->getCoordenadas().y + a->getDimensoes().y > b->getCoordenadas().y) {
		return true;
	}
	return false;*/
}


Vector2f Fase::getCoordenadasJogador()const
{
	Jogador* jogador = gerenciadorEntidades->getJogador();
	Vector2f coordenadas = jogador->getCoordenadas();
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
	bool excluir = false;

	for (itr = listaItens.begin(); itr != listaItens.end(); itr++) {
		if (verificar_colisao(jogador, (*itr))) {
			if ((*itr)->getExiste())
				(*itr)->setExiste(false);

			if ((*itr)->getTipo() == CHAVE)
				jogador->adicionarChave();
			else if ((*itr)->getTipo() == MOEDA)
				jogador->adicionarMoeda();
			else if ((*itr)->getTipo() == BLUEORB)
				jogador->setVelocidade(jogador->getVelocidade() + 3);
			else if ((*itr)->getTipo() == REDORB)
				jogador->setRedOrb(true);
			else if ((*itr)->getTipo() == GREENORB)
				jogador->setGreenOrb(true);

			excluir = true;
		}
	}

	if (excluir == true) {
		listaEntidades->excluir_entidades();
		gerenciadorEntidades->excluir_itens();
	}
}
void Fase::jogador_barreira()
{
	list<Barreira*>::iterator itr;
	list<Barreira*> listaBarreiras = gerenciadorEntidades->getListaBarreiras();
	Jogador* jogador = gerenciadorEntidades->getJogador();

	for (itr = listaBarreiras.begin(); itr != listaBarreiras.end(); itr++) {
		if (verificar_colisao(jogador, (*itr))) {

			if (jogador->getDirecao() == DIREITA)
				jogador->setxEntidade(jogador->getCoordenadas().x - jogador->getVelocidade());
			else if (jogador->getDirecao() == ESQUERDA)
				jogador->setxEntidade(jogador->getCoordenadas().x + jogador->getVelocidade());
			else if (jogador->getDirecao() == CIMA)
				jogador->setyEntidade(jogador->getCoordenadas().y + jogador->getVelocidade());
			else if (jogador->getDirecao() == BAIXO)
				jogador->setyEntidade(jogador->getCoordenadas().y - jogador->getVelocidade());
				
			break;
		}
	}
}

void Fase::jogador_abismo()
{
	list<Abismo*>::iterator itr;
	list<Abismo*> listaAbismo = gerenciadorEntidades->getListaAbismo();
	Jogador* jogador = gerenciadorEntidades->getJogador();
	float aux = 20;

	for (itr = listaAbismo.begin(); itr != listaAbismo.end(); itr++) {
		if (verificar_colisao(jogador, (*itr))) {
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
		if (verificar_colisao(jogador, (*itr))) {

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

		if (!jogador->getGreenOrb()) {
			if (verificar_colisao(jogador, (*itr))) {

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
}

void Fase::jogador_botao()
{
	list<Botao*>::iterator itr;
	list<Botao*> listaBotoes = gerenciadorEntidades->getListaBotoes();
	Jogador* jogador = gerenciadorEntidades->getJogador();

	float hitBox = 20;

	for (itr = listaBotoes.begin(); itr != listaBotoes.end(); itr++) {
		if (verificar_colisao(jogador, (*itr))) {

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
		if (verificar_colisao(jogador, (*itr))) {

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
		if (verificar_colisao(jogador, (*itr))) {

			if (!(*itr)->getDesativado()){
				jogador->setExiste(false);
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
		if (verificar_colisao(jogador, (*itr))) {

			if ((*itr)->getClasse() != 2) {
				if (jogador->getDirecao() == DIREITA)
					jogador->setxEntidade(jogador->getCoordenadas().x - jogador->getVelocidade());
				else if (jogador->getDirecao() == ESQUERDA)
					jogador->setxEntidade(jogador->getCoordenadas().x + jogador->getVelocidade());
				else if (jogador->getDirecao() == CIMA)
					jogador->setyEntidade(jogador->getCoordenadas().y + jogador->getVelocidade());
				else if (jogador->getDirecao() == BAIXO)
					jogador->setyEntidade(jogador->getCoordenadas().y - jogador->getVelocidade());

				if ((*itr)->getClasse() == 3) {
					if(jogador->getMoedas() >= gerenciadorEntidades->getQuantidadeMoedas() && (jogador->getAcao() && !(*itr)->getAtivado()))
						(*itr)->setAtivado(true);
				}
				else {
					if (jogador->getAcao() && (*itr)->getAtivado())
						(*itr)->setAtivado(false);

					else if (jogador->getAcao() && !(*itr)->getAtivado())
						(*itr)->setAtivado(true);
				}
			}
			else {
				if (!(*itr)->getAtivado()) {
					if (verificar_colisao(jogador, (*itr))) {

						if (jogador->getDirecao() == CIMA)
							jogador->setyEntidade(jogador->getCoordenadas().y + jogador->getVelocidade());
						else if (jogador->getDirecao() == BAIXO)
							jogador->setyEntidade(jogador->getCoordenadas().y - jogador->getVelocidade());
					}

					if (jogador->getAcao() && !(*itr)->getAtivado() && jogador->getChaves() > 0) {
						(*itr)->setAtivado(true);
						jogador->retirarChave();
					}
				}
			}
		}
	}
}

void Fase::jogador_caixas()
{
	list<Caixa*>::iterator itr;
	list<Caixa*> listaCaixas = gerenciadorEntidades->getListaCaixas();
	Jogador* jogador = gerenciadorEntidades->getJogador();

	for (itr = listaCaixas.begin(); itr != listaCaixas.end(); itr++) {
		if (verificar_colisao(jogador, (*itr))) {

			if ((*itr)->getTipo() == LEVE || ((*itr)->getTipo() == PESADA && jogador->getRedOrb())) {
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

			else if ((*itr)->getTipo() == PESADA && !jogador->getRedOrb()) {
				if (jogador->getDirecao() == DIREITA)
					jogador->setxEntidade(jogador->getCoordenadas().x - jogador->getVelocidade());
				else if (jogador->getDirecao() == ESQUERDA)
					jogador->setxEntidade(jogador->getCoordenadas().x + jogador->getVelocidade());
				else if (jogador->getDirecao() == CIMA)
					jogador->setyEntidade(jogador->getCoordenadas().y + jogador->getVelocidade());
				else if (jogador->getDirecao() == BAIXO)
					jogador->setyEntidade(jogador->getCoordenadas().y - jogador->getVelocidade());
			}
			break;
		}
	}
}

void Fase::jogador_portais()
{
	list<Interativo*>::iterator itr;
	list<Interativo*> listaPortais = gerenciadorEntidades->getListaPortais();
	Jogador* jogador = gerenciadorEntidades->getJogador();

	for (itr = listaPortais.begin(); itr != listaPortais.end(); itr++) {
		if (verificar_colisao(jogador, (*itr))) {

			if (jogador->getAcao()) {

			}

		}
	}
}

void Fase::atiradores()
{
	list<Atirador*>::iterator itr;
	list<Atirador*> listaPortais = gerenciadorEntidades->getListaAtiradores();

	for (itr = listaPortais.begin(); itr != listaPortais.end(); itr++) {
		if ((*itr)->getAtivo()) {
			if((*itr)->getDirecao() == CIMA)
				listaEntidades->adicionar_entidade((*itr)->getCoordenadas().x, (*itr)->getCoordenadas().y, 100);
			else if ((*itr)->getDirecao() == BAIXO)
				listaEntidades->adicionar_entidade((*itr)->getCoordenadas().x, (*itr)->getCoordenadas().y, 101);
			else if ((*itr)->getDirecao() == DIREITA)
				listaEntidades->adicionar_entidade((*itr)->getCoordenadas().x, (*itr)->getCoordenadas().y, 102);
			else if ((*itr)->getDirecao() == ESQUERDA)
				listaEntidades->adicionar_entidade((*itr)->getCoordenadas().x, (*itr)->getCoordenadas().y, 103);
		}
	}
}

void Fase::flecha_barreira()
{
	list<Flecha*>::iterator itrF;
	list<Flecha*> listaFlechas = gerenciadorEntidades->getListaFlechas();
	list<Barreira*>::iterator itrB;
	list<Barreira*> listaBarreiras = gerenciadorEntidades->getListaBarreiras();
	bool excluir = false;

	for (itrF = listaFlechas.begin(); itrF != listaFlechas.end(); itrF++) {
		for (itrB = listaBarreiras.begin(); itrB != listaBarreiras.end(); itrB++) {
			if ((*itrB)->getClasse() != 1) {
				if (verificar_colisao((*itrF), (*itrB))) {
					(*itrF)->setExiste(false);
					excluir = true;
				}
			}
		}
	}
	if (excluir == true) {
		listaEntidades->excluir_entidades();
		gerenciadorEntidades->excluir_flechas();
	}
}

void Fase::jogador_flecha()
{
	list<Flecha*>::iterator itr;
	list<Flecha*> listaFlechas = gerenciadorEntidades->getListaFlechas();
	Jogador* jogador = gerenciadorEntidades->getJogador();

	for (itr = listaFlechas.begin(); itr != listaFlechas.end(); itr++) {
		if (verificar_colisao(jogador, (*itr))) {
			jogador->setExiste(false);
		}
	}
}

void Fase::flecha_caixa()
{
	list<Flecha*>::iterator itrF;
	list<Flecha*> listaFlechas = gerenciadorEntidades->getListaFlechas();
	list<Caixa*>::iterator itrC;
	list<Caixa*> listaCaixas = gerenciadorEntidades->getListaCaixas();
	bool excluir = false;

	for (itrF = listaFlechas.begin(); itrF != listaFlechas.end(); itrF++) {
		for (itrC = listaCaixas.begin(); itrC != listaCaixas.end(); itrC++) {
			if (verificar_colisao((*itrF), (*itrC))) {
				(*itrF)->setExiste(false);
				excluir = true;
			}
		}
	}
	if (excluir == true) {
		listaEntidades->excluir_entidades();
		gerenciadorEntidades->excluir_flechas();
	}
}

void Fase::caixa_botao()
{
	list<Botao*>::iterator itrB;
	list<Botao*> listaBotoes = gerenciadorEntidades->getListaBotoes();
	list<Caixa*>::iterator itrC;
	list<Caixa*> listaCaixas = gerenciadorEntidades->getListaCaixas();
	bool excluir = false;

	for (itrB = listaBotoes.begin(); itrB != listaBotoes.end(); itrB++) {
		for (itrC = listaCaixas.begin(); itrC != listaCaixas.end(); itrC++) {
			if (verificar_colisao((*itrB), (*itrC))) {
				(*itrB)->setAtivado(true);
			}
			else{
				(*itrB)->setAtivado(false);
			}
		}
	}
}