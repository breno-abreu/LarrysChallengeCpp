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
	listaEntidades->adicionar_entidade(cx, cy, tipo, conexao);
}

void Fase::excluir_entidades()
{

}

void Fase::executar()
{
	listaEntidades->percorrer();
	//caixa_barreira();
	jogador_caixas();
	jogador_item();
	jogador_barreira();
	jogador_abismo();
	jogador_movimentador();
	jogador_parede_levadica();
	jogador_espinhos();
	jogador_interativo();
	jogador_portais();
	jogador_inimigo();
	atiradores();
	flecha_barreira();
	jogador_flecha();
	flecha_caixa();
	objetos_botao();
	ativador_espinhos();
	ativador_atirador(); 
	ativador_porta();
	perseguidor();
	perseguidor_barreira();
	rato_barreira();
}

bool Fase::verificar_colisao(Entidade* a, Entidade* b)
{
	/*if (a->getHitBox().left < b->getHitBox().left + b->getHitBox().width &&
		a->getHitBox().left + a->getHitBox().width > b->getHitBox().left &&
		a->getHitBox().top < b->getHitBox().top + b->getHitBox().height &&
		a->getHitBox().top + a->getHitBox().height > b->getHitBox().top) {
		return true;
	}
	return false;

	if (a->getCoordenadas().x < b->getCoordenadas().x + b->getDimensoes().x &&
		a->getCoordenadas().x + a->getDimensoes().x > b->getCoordenadas().x&&
		a->getCoordenadas().y < b->getCoordenadas().y + b->getDimensoes().y &&
		a->getCoordenadas().y + a->getDimensoes().y > b->getCoordenadas().y) {
		return true;
	}
	return false;*/

	if (a->getCoordenadas().x + a->getHitBox().left < b->getCoordenadas().x + b->getDimensoes().x + b->getHitBox().width &&
		a->getCoordenadas().x + a->getDimensoes().x + a->getHitBox().width > b->getCoordenadas().x + b->getHitBox().left &&
		a->getCoordenadas().y + a->getHitBox().top < b->getCoordenadas().y + b->getDimensoes().y + b->getHitBox().height &&
		a->getCoordenadas().y + a->getDimensoes().y + a->getHitBox().height > b->getCoordenadas().y + b->getHitBox().top) {
		return true;
	}
	return false;
}

bool Fase::verificar_colisao_aux(Entidade* a, Entidade* b)
{
	if (a->getCoordenadas().x < b->getCoordenadas().x + b->getDimensoes().x &&
		a->getCoordenadas().x + a->getDimensoes().x > b->getCoordenadas().x &&
		a->getCoordenadas().y < b->getCoordenadas().y + b->getDimensoes().y &&
		a->getCoordenadas().y + a->getDimensoes().y > b->getCoordenadas().y) {
		return true;
	}
	return false;
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

void Fase::perseguidor()
{
	list<Perseguidor*>::iterator itr;
	list<Perseguidor*> listaPerseguidores = gerenciadorEntidades->getListaPerseguidores();
	Jogador* jogador = gerenciadorEntidades->getJogador();

	for (itr = listaPerseguidores.begin(); itr != listaPerseguidores.end(); itr++) {

		(*itr)->setCoodenadasJogador(jogador->getCoordenadas().x, jogador->getCoordenadas().y);

		if ((*itr)->getDistanciaJogador() >= (*itr)->getDistanciaOrigemPadrao())
			(*itr)->perseguir(false);
		else
			(*itr)->perseguir(true);
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

void Fase::objetos_botao()
{
	list<Botao*>::iterator itrB;
	list<Botao*> listaBotoes = gerenciadorEntidades->getListaBotoes();
	list<Entidade*>::iterator itrO;
	list<Entidade*> listaObjetos = gerenciadorEntidades->getListaObjetos();
	bool pressionado = false;

	for (itrB = listaBotoes.begin(); itrB != listaBotoes.end(); itrB++) {
		bool pressionado = false;
		for (itrO = listaObjetos.begin(); itrO != listaObjetos.end(); itrO++) {
			if (verificar_colisao((*itrB), (*itrO))) {
				pressionado = true;
			}
		}
		if (pressionado)
			(*itrB)->setAtivado(true);
		else
			(*itrB)->setAtivado(false);
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
					if (jogador->getDirecao() == CIMA)
						jogador->setyEntidade(jogador->getCoordenadas().y + jogador->getVelocidade());
					else if (jogador->getDirecao() == BAIXO)
						jogador->setyEntidade(jogador->getCoordenadas().y - jogador->getVelocidade());
				}
			}
		}
		if (verificar_colisao_aux((*itr), jogador) && (*itr)->getClasse() == 2) {
			if (jogador->getAcao() && !(*itr)->getAtivado() && jogador->getChaves() > 0) {
				(*itr)->setAtivado(true);
				jogador->retirarChave();
			}
		}
	}
}

void Fase::jogador_caixas()
{
	list<Caixa*>::iterator itr;
	list<Caixa*> listaCaixas = gerenciadorEntidades->getListaCaixas();
	list<Entidade*>::iterator itr2;
	list<Entidade*> listaCaixas2 = gerenciadorEntidades->getListaBarreirasCaixas();
	Jogador* jogador = gerenciadorEntidades->getJogador();


	/*else {
	jogador->setxEntidade(jogador->getCoordenadas().x - jogador->getVelocidade() - (*itr)->getPeso());
	(*itr)->setxEntidade((*itr)->getCoordenadas().x - jogador->getVelocidade() + (*itr)->getPeso());
							}
	
							else {
							jogador->setxEntidade(jogador->getCoordenadas().x + jogador->getVelocidade() + (*itr)->getPeso());
							(*itr)->setxEntidade((*itr)->getCoordenadas().x + jogador->getVelocidade() - (*itr)->getPeso());
							}
							else {
							jogador->setyEntidade(jogador->getCoordenadas().y + jogador->getVelocidade() + (*itr)->getPeso());
							(*itr)->setyEntidade((*itr)->getCoordenadas().y + jogador->getVelocidade() - (*itr)->getPeso());
							}
							else {
							jogador->setyEntidade(jogador->getCoordenadas().y - jogador->getVelocidade() - (*itr)->getPeso());
							(*itr)->setyEntidade((*itr)->getCoordenadas().y - jogador->getVelocidade() + (*itr)->getPeso());
							}*/


	for (itr = listaCaixas.begin(); itr != listaCaixas.end(); itr++) {
		if (verificar_colisao(jogador, (*itr))) {
			if ((*itr)->getTipo() == LEVE || ((*itr)->getTipo() == PESADA && jogador->getRedOrb())) {
				if (jogador->getDirecao() == DIREITA) {
					jogador->setxEntidade(jogador->getCoordenadas().x - (*itr)->getPeso());
					(*itr)->setxEntidade(jogador->getCoordenadas().x + jogador->getDimensoes().x + jogador->getHitBox().width - (*itr)->getHitBox().left);
					(*itr)->setContato(DIREITA);
				}
				else if (jogador->getDirecao() == ESQUERDA) {
					jogador->setxEntidade(jogador->getCoordenadas().x + (*itr)->getPeso());
					(*itr)->setxEntidade(jogador->getCoordenadas().x - (*itr)->getDimensoes().x + jogador->getHitBox().left - (*itr)->getHitBox().width);
					(*itr)->setContato(ESQUERDA);
				}

				else if (jogador->getDirecao() == CIMA) {
					jogador->setyEntidade(jogador->getCoordenadas().y + (*itr)->getPeso());
					(*itr)->setyEntidade(jogador->getCoordenadas().y - (*itr)->getDimensoes().y + jogador->getHitBox().top - (*itr)->getHitBox().height);
					(*itr)->setContato(CIMA);
				}

				else if (jogador->getDirecao() == BAIXO) {
					jogador->setyEntidade(jogador->getCoordenadas().y - (*itr)->getPeso());
					(*itr)->setyEntidade(jogador->getCoordenadas().y + jogador->getDimensoes().y + jogador->getHitBox().height - (*itr)->getHitBox().top);
					(*itr)->setContato(BAIXO);
				}
			}

			else if (((*itr)->getTipo() == PESADA && !jogador->getRedOrb())) {
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

		else {
			(*itr)->setContato(-1);
		}
	}

	for (itr = listaCaixas.begin(); itr != listaCaixas.end(); itr++) {
		for (itr2 = listaCaixas2.begin(); itr2 != listaCaixas2.end(); itr2++) {
			if ((*itr)->getCodigo() != (*itr2)->getCodigo() && verificar_colisao((*itr), (*itr2))) {
				if ((*itr)->getContato() == DIREITA) {
					jogador->setxEntidade(jogador->getCoordenadas().x - jogador->getVelocidade());
					(*itr)->setxEntidade(jogador->getCoordenadas().x + jogador->getDimensoes().x + jogador->getHitBox().width - (*itr)->getHitBox().left - jogador->getVelocidade() + 2);

				}
				else if ((*itr)->getContato() == ESQUERDA) {
					jogador->setxEntidade(jogador->getCoordenadas().x + jogador->getVelocidade());
					(*itr)->setxEntidade(jogador->getCoordenadas().x - (*itr)->getDimensoes().x + jogador->getHitBox().left - (*itr)->getHitBox().width + jogador->getVelocidade() - 2);
				}

				else if ((*itr)->getContato() == CIMA) {
					jogador->setyEntidade(jogador->getCoordenadas().y + jogador->getVelocidade());
					(*itr)->setyEntidade(jogador->getCoordenadas().y - (*itr)->getDimensoes().y + jogador->getHitBox().top - (*itr)->getHitBox().height + jogador->getVelocidade() - 2);
				}

				else if ((*itr)->getContato() == BAIXO) {
					jogador->setyEntidade(jogador->getCoordenadas().y - jogador->getVelocidade());
					(*itr)->setyEntidade(jogador->getCoordenadas().y + jogador->getDimensoes().y + jogador->getHitBox().height - (*itr)->getHitBox().top - jogador->getVelocidade() + 2);
				}
			}
		}
	}

	/*else if (verificar_colisao(jogador, (*itr)) && verificar_colisao((*itr), (*itr2))) {

	if (jogador->getDirecao() == DIREITA) {
		jogador->setxEntidade(jogador->getCoordenadas().x - jogador->getVelocidade());
		(*itr)->setxEntidade(jogador->getCoordenadas().x + jogador->getDimensoes().x + jogador->getHitBox().width - (*itr)->getHitBox().left - jogador->getVelocidade() + 2);
	}

	else if (jogador->getDirecao() == ESQUERDA) {
		jogador->setxEntidade(jogador->getCoordenadas().x + jogador->getVelocidade());
		(*itr)->setxEntidade(jogador->getCoordenadas().x - (*itr)->getDimensoes().x + jogador->getHitBox().left - (*itr)->getHitBox().width + jogador->getVelocidade() - 2);
	}

	else if (jogador->getDirecao() == CIMA) {
		jogador->setyEntidade(jogador->getCoordenadas().y + jogador->getVelocidade());
		(*itr)->setyEntidade(jogador->getCoordenadas().y - (*itr)->getDimensoes().y + jogador->getHitBox().top - (*itr)->getHitBox().height + jogador->getVelocidade() - 2);
	}

	else if (jogador->getDirecao() == BAIXO) {
		jogador->setyEntidade(jogador->getCoordenadas().y - jogador->getVelocidade());
		(*itr)->setyEntidade(jogador->getCoordenadas().y + jogador->getDimensoes().y + jogador->getHitBox().height - (*itr)->getHitBox().top - jogador->getVelocidade() + 2);
	}
				}*/


}

void Fase::caixa_barreira()
{
	list<Caixa*>::iterator itr;
	list<Caixa*> listaCaixas = gerenciadorEntidades->getListaCaixas();
	list<Caixa*>::iterator itr2;
	list<Caixa*> listaCaixas2 = gerenciadorEntidades->getListaCaixas();
	Jogador* jogador = gerenciadorEntidades->getJogador();
	bool done = false;

	for (itr = listaCaixas.begin(); itr != listaCaixas.end(); itr++) {
		for (itr2 = listaCaixas2.begin(); itr2 != listaCaixas2.end(); itr2++) {
			if ((*itr)->getCodigo() != (*itr2)->getCodigo()) {
				if (verificar_colisao((*itr), (*itr2))) {
					if (jogador->getDirecao() == DIREITA) {
						(*itr)->setBloqueadoDireita(true);
					}
						
					else if (jogador->getDirecao() == ESQUERDA) {
						(*itr)->setBloqueadoEsquerda(true);
					}
						
					else if (jogador->getDirecao() == CIMA) {
						(*itr)->setBloqueadoCima(true);
					}
						
					else if (jogador->getDirecao() == BAIXO) {
						(*itr)->setBloqueadoBaixo(true);
					}
					done = true;
				}
			}
			else {
				(*itr)->setBloqueadoDireita(false);
				(*itr)->setBloqueadoEsquerda(false);
				(*itr)->setBloqueadoCima(false);
				(*itr)->setBloqueadoBaixo(false);
			}
		}
		if (done)
			break;
	}
}

void Fase::jogador_portais()
{
	list<Interativo*>::iterator itr;
	list<Interativo*> listaPortais = gerenciadorEntidades->getListaPortais();
	list<Interativo*>::iterator itr2;
	list<Interativo*> listaPortais2 = gerenciadorEntidades->getListaPortais();
	Jogador* jogador = gerenciadorEntidades->getJogador();
	bool fim = false;

	for (itr = listaPortais.begin(); itr != listaPortais.end(); itr++) {
		if (verificar_colisao(jogador, (*itr)) && jogador->getAcao()) {
			for (itr2 = listaPortais2.begin(); itr2 != listaPortais2.end(); itr2++) {
				if ((*itr)->getCodigo() != (*itr2)->getCodigo() && (*itr)->getConexao() == (*itr2)->getConexao()) {
					jogador->setxEntidade((*itr2)->getCoordenadas().x);
					jogador->setyEntidade((*itr2)->getCoordenadas().y);
					fim = true;
				}
			}
		}
		if (fim)
			break;
	}
}

void Fase::atiradores()
{
	list<Atirador*>::iterator itr;
	list<Atirador*> listaPortais = gerenciadorEntidades->getListaAtiradores();

	for (itr = listaPortais.begin(); itr != listaPortais.end(); itr++) {
		if ((*itr)->getAtirar()) {
			if((*itr)->getDirecao() == CIMA)
				listaEntidades->adicionar_entidade((*itr)->getCoordenadas().x, (*itr)->getCoordenadas().y, 100, 0);
			else if ((*itr)->getDirecao() == BAIXO)
				listaEntidades->adicionar_entidade((*itr)->getCoordenadas().x, (*itr)->getCoordenadas().y, 101, 0);
			else if ((*itr)->getDirecao() == DIREITA)
				listaEntidades->adicionar_entidade((*itr)->getCoordenadas().x, (*itr)->getCoordenadas().y, 102, 0);
			else if ((*itr)->getDirecao() == ESQUERDA)
				listaEntidades->adicionar_entidade((*itr)->getCoordenadas().x, (*itr)->getCoordenadas().y, 103, 0);
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

void Fase::ativador_espinhos()
{
	list<Espinhos*>::iterator itrE;
	list<Espinhos*> listaEspinhos = gerenciadorEntidades->getListaEspinhos();
	list<Interruptor*>::iterator itrI;
	list<Interruptor*> listaInterruptores = gerenciadorEntidades->getListaInterruptores();
	list<Botao*>::iterator itrB;
	list<Botao*> listaBotoes = gerenciadorEntidades->getListaBotoes();


	for (itrI = listaInterruptores.begin(); itrI != listaInterruptores.end(); itrI++) {
		for (itrE = listaEspinhos.begin(); itrE != listaEspinhos.end(); itrE++) {
			if ((*itrI)->getAtivado() && (*itrI)->getConexao() == (*itrE)->getConexao()) 
				(*itrE)->setAtivado(false);
			else if (!(*itrI)->getAtivado() && (*itrI)->getConexao() == (*itrE)->getConexao()) 
				(*itrE)->setAtivado(true);
		}
	}

	for (itrB = listaBotoes.begin(); itrB != listaBotoes.end(); itrB++) {
		for (itrE = listaEspinhos.begin(); itrE != listaEspinhos.end(); itrE++) {
			if ((*itrB)->getAtivado() && (*itrB)->getConexao() == (*itrE)->getConexao())
				(*itrE)->setAtivado(false);
			else if (!(*itrB)->getAtivado() && (*itrB)->getConexao() == (*itrE)->getConexao())
				(*itrE)->setAtivado(true);
		}
	}
}
void Fase::ativador_atirador()
{
	list<Atirador*>::iterator itrA;
	list<Atirador*> listaAtiradores = gerenciadorEntidades->getListaAtiradores();
	list<Interruptor*>::iterator itrI;
	list<Interruptor*> listaInterruptores = gerenciadorEntidades->getListaInterruptores();
	list<Botao*>::iterator itrB;
	list<Botao*> listaBotoes = gerenciadorEntidades->getListaBotoes();


	for (itrI = listaInterruptores.begin(); itrI != listaInterruptores.end(); itrI++) {
		for (itrA = listaAtiradores.begin(); itrA != listaAtiradores.end(); itrA++) {
			if ((*itrI)->getAtivado() && (*itrI)->getConexao() == (*itrA)->getConexao())
				(*itrA)->setAtivado(false);
			else if (!(*itrI)->getAtivado() && (*itrI)->getConexao() == (*itrA)->getConexao())
				(*itrA)->setAtivado(true);
		}
	}

	for (itrB = listaBotoes.begin(); itrB != listaBotoes.end(); itrB++) {
		for (itrA = listaAtiradores.begin(); itrA != listaAtiradores.end(); itrA++) {
			if ((*itrB)->getAtivado() && (*itrB)->getConexao() == (*itrA)->getConexao())
				(*itrA)->setAtivado(false);
			else if (!(*itrB)->getAtivado() && (*itrB)->getConexao() == (*itrA)->getConexao())
				(*itrA)->setAtivado(true);
		}
	}
}
void Fase::ativador_porta()
{
	list<Porta*>::iterator itrP;
	list<Porta*> listaPortas = gerenciadorEntidades->getListaPortas();
	list<Interruptor*>::iterator itrI;
	list<Interruptor*> listaInterruptores = gerenciadorEntidades->getListaInterruptores();
	list<Botao*>::iterator itrB;
	list<Botao*> listaBotoes = gerenciadorEntidades->getListaBotoes();


	for (itrI = listaInterruptores.begin(); itrI != listaInterruptores.end(); itrI++) {
		for (itrP = listaPortas.begin(); itrP != listaPortas.end(); itrP++) {
			if ((*itrI)->getAtivado() && (*itrI)->getConexao() == (*itrP)->getConexao())
				(*itrP)->setAtivado(true);
			else if (!(*itrI)->getAtivado() && (*itrI)->getConexao() == (*itrP)->getConexao())
				(*itrP)->setAtivado(false);
		}
	}

	for (itrB = listaBotoes.begin(); itrB != listaBotoes.end(); itrB++) {
		for (itrP = listaPortas.begin(); itrP != listaPortas.end(); itrP++) {
			if ((*itrB)->getAtivado() && (*itrB)->getConexao() == (*itrP)->getConexao())
				(*itrP)->setAtivado(true);
			else if (!(*itrB)->getAtivado() && (*itrB)->getConexao() == (*itrP)->getConexao())
				(*itrP)->setAtivado(false);
		}
	}
}

void Fase::perseguidor_barreira()
{
	list<Perseguidor*>::iterator itrP;
	list<Perseguidor*> listaPerseguidores = gerenciadorEntidades->getListaPerseguidores();
	list<Barreira*>::iterator itrB;
	list<Barreira*> listaBarreiras = gerenciadorEntidades->getListaBarreiras();
	list<Caixa*>::iterator itrC;
	list<Caixa*> listaCaixas = gerenciadorEntidades->getListaCaixas();

	for (itrP = listaPerseguidores.begin(); itrP != listaPerseguidores.end(); itrP++) {
		for (itrB = listaBarreiras.begin(); itrB != listaBarreiras.end(); itrB++) {
			if(verificar_colisao((*itrP), (*itrB))) {
				if ((*itrP)->getDirecao() == DIREITA)
					(*itrP)->setxEntidade((*itrP)->getCoordenadas().x - (*itrP)->getVelocidade());
				else if ((*itrP)->getDirecao() == ESQUERDA)
					(*itrP)->setxEntidade((*itrP)->getCoordenadas().x + (*itrP)->getVelocidade());
				else if ((*itrP)->getDirecao() == CIMA)
					(*itrP)->setyEntidade((*itrP)->getCoordenadas().y + (*itrP)->getVelocidade());
				else if ((*itrP)->getDirecao() == BAIXO)
					(*itrP)->setyEntidade((*itrP)->getCoordenadas().y - (*itrP)->getVelocidade());

				break;
			}
		}
	}

	for (itrP = listaPerseguidores.begin(); itrP != listaPerseguidores.end(); itrP++) {
		for (itrC = listaCaixas.begin(); itrC != listaCaixas.end(); itrC++) {
			if (verificar_colisao((*itrP), (*itrC))) {
				if ((*itrP)->getDirecao() == DIREITA)
					(*itrP)->setxEntidade((*itrP)->getCoordenadas().x - (*itrP)->getVelocidade());
				else if ((*itrP)->getDirecao() == ESQUERDA)
					(*itrP)->setxEntidade((*itrP)->getCoordenadas().x + (*itrP)->getVelocidade());
				else if ((*itrP)->getDirecao() == CIMA)
					(*itrP)->setyEntidade((*itrP)->getCoordenadas().y + (*itrP)->getVelocidade());
				else if ((*itrP)->getDirecao() == BAIXO)
					(*itrP)->setyEntidade((*itrP)->getCoordenadas().y - (*itrP)->getVelocidade());

				break;
			}
		}
	}
}
void Fase::rato_barreira()
{
	list<Rato*>::iterator itrR;
	list<Rato*> listaRatos = gerenciadorEntidades->getListaRatos();
	list<Barreira*>::iterator itrB;
	list<Barreira*> listaBarreiras = gerenciadorEntidades->getListaBarreiras();
	list<Caixa*>::iterator itrC;
	list<Caixa*> listaCaixas = gerenciadorEntidades->getListaCaixas();

	for (itrR = listaRatos.begin(); itrR != listaRatos.end(); itrR++) {
		for (itrB = listaBarreiras.begin(); itrB != listaBarreiras.end(); itrB++) {
			if (verificar_colisao((*itrR), (*itrB))) {
				
				
				if ((*itrR)->getDirecao() == DIREITA)
					(*itrR)->setxEntidade((*itrR)->getCoordenadas().x - (*itrR)->getVelocidade());
				else if ((*itrR)->getDirecao() == ESQUERDA)
					(*itrR)->setxEntidade((*itrR)->getCoordenadas().x + (*itrR)->getVelocidade());
				else if ((*itrR)->getDirecao() == CIMA)
					(*itrR)->setyEntidade((*itrR)->getCoordenadas().y + (*itrR)->getVelocidade());
				else if ((*itrR)->getDirecao() == BAIXO)
					(*itrR)->setyEntidade((*itrR)->getCoordenadas().y - (*itrR)->getVelocidade());

				(*itrR)->alterar_direcao();
			}
		}
	}

	for (itrR = listaRatos.begin(); itrR != listaRatos.end(); itrR++) {
		for (itrC = listaCaixas.begin(); itrC != listaCaixas.end(); itrC++) {
			if (verificar_colisao((*itrR), (*itrC))) {


				if ((*itrR)->getDirecao() == DIREITA)
					(*itrR)->setxEntidade((*itrR)->getCoordenadas().x - (*itrR)->getVelocidade());
				else if ((*itrR)->getDirecao() == ESQUERDA)
					(*itrR)->setxEntidade((*itrR)->getCoordenadas().x + (*itrR)->getVelocidade());
				else if ((*itrR)->getDirecao() == CIMA)
					(*itrR)->setyEntidade((*itrR)->getCoordenadas().y + (*itrR)->getVelocidade());
				else if ((*itrR)->getDirecao() == BAIXO)
					(*itrR)->setyEntidade((*itrR)->getCoordenadas().y - (*itrR)->getVelocidade());

				(*itrR)->alterar_direcao();
			}
		}
	}
}

