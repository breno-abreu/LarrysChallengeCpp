#include "GerenciadorEntidades.h"

GerenciadorEntidades::GerenciadorEntidades()
{
	window = NULL;
}
GerenciadorEntidades::GerenciadorEntidades(RenderWindow* _window)
{
	jogadorJ = NULL;
	bauA = NULL;
	
	window = _window;
	t_flecha.loadFromFile("Textures/Arrow.png");
	t_blueorb.loadFromFile("Textures/Blue_orb.png");
	t_redorb.loadFromFile("Textures/Red_orb.png");
	t_greenorb.loadFromFile("Textures/Green_orb.png");
	t_moeda.loadFromFile("Textures/Coin.png");
	t_chave.loadFromFile("Textures/Golden_key.png");
	t_paredelevadica.loadFromFile("Textures/Blue_wall_up.png");
	t_caixaleve.loadFromFile("Textures/Box.png");
	t_caixapesada.loadFromFile("Textures/Box_heavy.png");
	t_chao.loadFromFile("Textures/Chao.png");
	t_jogador.loadFromFile("Textures/Character.png");
	t_bau.loadFromFile("Textures/Chest.png");
	t_colunahorizontal.loadFromFile("Textures/Coluna_Horizontal.png");
	t_colunaverticaldireita.loadFromFile("Textures/Coluna_Vertical_Direita.png");
	t_colunaverticalesquerda.loadFromFile("Textures/Coluna_Vertical_Esquerda.png");
	t_colunaverticaldireitab.loadFromFile("Textures/Coluna_Vertical2_Direita.png");
	t_colunaverticalesquerdab.loadFromFile("Textures/Coluna_Vertical2_Esquerda.png");
	t_parede.loadFromFile("Textures/Parede.png");
	t_passagemsecreta.loadFromFile("Textures/Passagem.png");
	t_abismo.loadFromFile("Textures/Pit.png");
	t_porta.loadFromFile("Textures/Porta.png");
	t_umbralhorizontal.loadFromFile("Textures/Porta_Cima.png");
	t_umbralverticaldireita.loadFromFile("Textures/Porta_Vertical_Direita.png");
	t_umbralverticalesquerda.loadFromFile("Textures/Porta_Vertical_Esquerda.png");
	t_movimentador.loadFromFile("Textures/Pushing_Floor.png");
	t_rato.loadFromFile("Textures/Rat.png");
	t_pedra.loadFromFile("Textures/Rock2.png");
	t_atirador.loadFromFile("Textures/Shooting_Trap.png");
	t_esqueleto.loadFromFile("Textures/Skel.png");
	t_espinhos.loadFromFile("Textures/Spike_trap.png");
	t_escada.loadFromFile("Textures/Stairs.png");
	t_interruptor.loadFromFile("Textures/Switch_blue_orange.png");
	t_botao.loadFromFile("Textures/Switch_press.png");
	t_topocolunadireita.loadFromFile("Textures/Topo_Coluna_Direita.png");
	t_topocolunaesquerda.loadFromFile("Textures/Topo_Coluna_Esquerda.png");
	t_tocha.loadFromFile("Textures/Torch.png");
	t_zumbi.loadFromFile("Textures/Zombie.png");

	quantidadeMoedas = 0;
}
GerenciadorEntidades::~GerenciadorEntidades()
{

}

void GerenciadorEntidades::excluir_itens()
{
	list<Item*>::iterator itr;
	for (itr = listaItens.begin(); itr != listaItens.end(); itr++) {
		if (!(*itr)->getExiste()) {
			listaItens.erase(itr);
			break;
		}
	}
}

void GerenciadorEntidades::excluir_flechas()
{
	list<Flecha*>::iterator itr;
	for (itr = listaFlechas.begin(); itr != listaFlechas.end(); itr++) {
		if (!(*itr)->getExiste()) {
			listaFlechas.erase(itr);
			break;
		}
	}
}

void GerenciadorEntidades::setQuantidadeMoedas(const int _quantidadeMoedas)
{
	quantidadeMoedas = _quantidadeMoedas;
}
int GerenciadorEntidades::getQuantidadeMoedas()const
{
	return quantidadeMoedas;
}

Entidade* GerenciadorEntidades::adicionar_entidade(const float cx, const float cy, const int tipo, const int codigo, const int conexao)
{
	if (tipo == 0) {
		Bau* bau = new Bau(window, &t_bau, cx, cy, 3, codigo, 6, 1);
		Interativo* bauI = static_cast<Interativo*>(bau);
		listaInterativos.push_back(bauI);
		Entidade* bauE = static_cast<Entidade*>(bau);
		bauA = bau;
		return bauE;
	}

	else if (tipo == 1) {
		Item* blueOrb = new Item(window, &t_blueorb, cx, cy, 2, codigo, 1, 1, BLUEORB);
		listaItens.push_back(blueOrb);
		Entidade* blueOrbE = static_cast<Entidade*>(blueOrb);
		return blueOrbE;
	}
	else if (tipo == 2) {
		Item* redOrb = new Item(window, &t_redorb, cx, cy, 2, codigo, 1, 1, REDORB);
		listaItens.push_back(redOrb);
		Entidade* redOrbE = static_cast<Entidade*>(redOrb);
		return redOrbE;
	}
	else if (tipo == 3) {
		Item* greenOrb = new Item(window, &t_greenorb, cx, cy, 2, codigo, 1, 1, GREENORB);
		listaItens.push_back(greenOrb);
		Entidade* greenOrbE = static_cast<Entidade*>(greenOrb);
		return greenOrbE;
	}
	else if (tipo == 4) {
		quantidadeMoedas++;
		Item* moeda = new Item(window, &t_moeda, cx, cy, 2, codigo, 1, 1, MOEDA);
		listaItens.push_back(moeda);
		Entidade* moedaE = static_cast<Entidade*>(moeda);
		return moedaE;
	}
	else if (tipo == 5) {
		ParedeLevadica* paredeLevadica = new ParedeLevadica(window, &t_paredelevadica, cx, cy, 3, codigo, 6, 1);
		listaParedesLevadicas.push_back(paredeLevadica);
		Entidade* paredeLevadicaE = static_cast<Entidade*>(paredeLevadica);
		return paredeLevadicaE;
	}
	else if (tipo == 6) {
		Caixa* caixaLeve = new Caixa(window, &t_caixaleve, cx, cy, 3, codigo, 1, 1, LEVE);
		listaCaixas.push_back(caixaLeve);
		listaBarreirasCaixas.push_back(caixaLeve);
		Entidade* caixaLeveE = static_cast<Entidade*>(caixaLeve);
		listaObjetos.push_back(caixaLeveE);
		return caixaLeveE;
	}
	else if (tipo == 7) {
		Caixa* caixaPesada = new Caixa(window, &t_caixapesada, cx, cy, 3, codigo, 1, 1, PESADA);	
		listaCaixas.push_back(caixaPesada);
		listaBarreirasCaixas.push_back(caixaPesada);
		Entidade* caixaPesadaE = static_cast<Entidade*>(caixaPesada);
		listaObjetos.push_back(caixaPesadaE);
		return caixaPesadaE;
	}
	else if (tipo == 8) {
		Superficie* chao = new Superficie(window, &t_chao, cx, cy, 0, codigo, 1, 1);
		Entidade* chaoE = static_cast<Entidade*>(chao);
		return chaoE;
	}
	else if (tipo == 9) {
		Item* chave = new Item(window, &t_chave, cx, cy, 2, codigo, 1, 1, CHAVE);
		listaItens.push_back(chave);
		Entidade* chaveE = static_cast<Entidade*>(chave);
		return chaveE;
	}
	else if (tipo == 10) {
		Coluna* colunaHorizontal = new Coluna(window, &t_colunahorizontal, cx, cy, 4, codigo, 1, 1, HORIZONTAL);
		Barreira* colunaHorizontalB = static_cast<Barreira*>(colunaHorizontal);
		listaBarreiras.push_back(colunaHorizontal);
		listaBarreirasCaixas.push_back(colunaHorizontal);
		Entidade* colunaHorizontalE = static_cast<Entidade*>(colunaHorizontal);
		return colunaHorizontalE;
	}
	else if (tipo == 11) {
		Coluna* colunaVerticalDireita = new Coluna(window, &t_colunaverticaldireita, cx, cy, 4, codigo, 1, 1, VERTICALDIREITA);
		Barreira* colunaVerticalDireitaB = static_cast<Barreira*>(colunaVerticalDireita);
		listaBarreiras.push_back(colunaVerticalDireita);
		listaBarreirasCaixas.push_back(colunaVerticalDireita);
		Entidade* colunaVerticalDireitaE = static_cast<Entidade*>(colunaVerticalDireita);
		return colunaVerticalDireitaE;
	}
	else if (tipo == 12) {
		Coluna* colunaVerticalEsquerda = new Coluna(window, &t_colunaverticalesquerda, cx, cy, 4, codigo, 1, 1, VERTICALESQUERDA);
		Barreira* colunaVerticalEsquerdaB = static_cast<Barreira*>(colunaVerticalEsquerda);
		listaBarreiras.push_back(colunaVerticalEsquerdaB);
		listaBarreirasCaixas.push_back(colunaVerticalEsquerda);
		Entidade* colunaVerticalEsquerdaE = static_cast<Entidade*>(colunaVerticalEsquerda);
		return colunaVerticalEsquerdaE;
	}
	else if (tipo == 13) {
		Superficie* colunaVerticalDireita2 = new Superficie(window, &t_colunaverticaldireitab, cx, cy, 2, codigo, 1, 1);
		Entidade* colunaVerticalDireitaBE = static_cast<Entidade*>(colunaVerticalDireita2);
		listaBarreirasCaixas.push_back(colunaVerticalDireita2);
		return colunaVerticalDireitaBE;
	}
	else if (tipo == 14) {
		Superficie* colunaVerticalEsquerda2 = new Superficie(window, &t_colunaverticalesquerdab, cx, cy, 2, codigo, 1, 1);
		Entidade* colunaVerticalEsquerdaBE = static_cast<Entidade*>(colunaVerticalEsquerda2);
		listaBarreirasCaixas.push_back(colunaVerticalEsquerda2);
		return colunaVerticalEsquerdaBE;
	}
	else if (tipo == 15) {
		Jogador* jogador = new Jogador(window, &t_jogador, cx, cy, 3, codigo, 6, 8);
		Personagem* jogadorP = static_cast<Personagem*>(jogador);
		jogadorJ = jogador;
		listaPersonagens.push_back(jogadorP);
		Entidade* jogadorE = static_cast<Entidade*>(jogador);
		listaObjetos.push_back(jogadorE);
		return jogadorE;
	}
	else if (tipo == 16) {
		Perseguidor* esqueleto = new Perseguidor(window, &t_esqueleto, cx, cy, 3, codigo, 6, 8, 3);
		listaPerseguidores.push_back(esqueleto);
		Inimigo* esqueletoI = static_cast<Inimigo*>(esqueleto);
		listaInimigos.push_back(esqueletoI);
		Personagem* esqueletoP = static_cast<Personagem*>(esqueleto);
		listaPersonagens.push_back(esqueletoP);
		Entidade* esqueletoE = static_cast<Entidade*>(esqueleto);
		return esqueletoE;
	}
	else if (tipo == 17) {
		Perseguidor* zumbi = new Perseguidor(window, &t_zumbi, cx, cy, 3, codigo, 6, 8, 7);
		listaPerseguidores.push_back(zumbi);
		Inimigo* zumbiI = static_cast<Inimigo*>(zumbi);
		listaInimigos.push_back(zumbiI);
		Personagem* zumbiP = static_cast<Personagem*>(zumbi);
		listaPersonagens.push_back(zumbiP);
		Entidade* zumbiE = static_cast<Entidade*>(zumbi);
		return zumbiE;
	}
	else if (tipo == 18) {
		Movimentador* movimentadorBaixo = new Movimentador(window, &t_movimentador, cx, cy, 1, codigo, 4, 1, BAIXO);
		listaMovimentadores.push_back(movimentadorBaixo);
		Entidade* movimentadorBaixoE = static_cast<Entidade*>(movimentadorBaixo);
		return movimentadorBaixoE;
	}
	else if (tipo == 19) {
		Movimentador* movimentadorEsquerda = new Movimentador(window, &t_movimentador, cx, cy, 1, codigo, 4, 1, ESQUERDA);
		listaMovimentadores.push_back(movimentadorEsquerda);
		Entidade* movimentadorEsquerdaE = static_cast<Entidade*>(movimentadorEsquerda);
		return movimentadorEsquerdaE;
	}
	else if (tipo == 20) {
		Movimentador* movimentadorDireita = new Movimentador(window, &t_movimentador, cx, cy, 1, codigo, 4, 1, DIREITA);
		listaMovimentadores.push_back(movimentadorDireita);
		Entidade* movimentadorDireitaE = static_cast<Entidade*>(movimentadorDireita);
		return movimentadorDireitaE;
	}
	else if (tipo == 21) {
		Movimentador* movimentadorCima = new Movimentador(window, &t_movimentador, cx, cy, 1, codigo, 4, 1, CIMA);
		listaMovimentadores.push_back(movimentadorCima);
		Entidade* movimentadorCimaE = static_cast<Entidade*>(movimentadorCima);
		return movimentadorCimaE;
	}
	else if (tipo == 22) {
		Rato* ratoBaixo = new Rato(window, &t_rato, cx, cy, 3, codigo, 2, 4, BAIXO);
		listaRatos.push_back(ratoBaixo);
		Inimigo* ratoBaixoI = static_cast<Inimigo*>(ratoBaixo);
		listaInimigos.push_back(ratoBaixoI);
		Personagem* ratoBaixoP = static_cast<Personagem*>(ratoBaixo);
		listaPersonagens.push_back(ratoBaixoP);
		Entidade* ratoBaixoE = static_cast<Entidade*>(ratoBaixo);
		return ratoBaixoE;
	}
	else if (tipo == 23) {
		Rato* ratoEsquerda = new Rato(window, &t_rato, cx, cy, 3, codigo, 2, 4, ESQUERDA);
		listaRatos.push_back(ratoEsquerda);
		Inimigo* ratoEsquerdaI = static_cast<Inimigo*>(ratoEsquerda);
		listaInimigos.push_back(ratoEsquerdaI);
		Personagem* ratoEsquerdaP = static_cast<Personagem*>(ratoEsquerda);
		listaPersonagens.push_back(ratoEsquerdaP);
		Entidade* ratoEsquerdaE = static_cast<Entidade*>(ratoEsquerda);
		return ratoEsquerdaE;
	}
	else if (tipo == 24) {
		Rato* ratoDireita = new Rato(window, &t_rato, cx, cy, 3, codigo, 2, 4, DIREITA);
		listaRatos.push_back(ratoDireita);
		Inimigo* ratoDireitaI = static_cast<Inimigo*>(ratoDireita);
		listaInimigos.push_back(ratoDireitaI);
		Personagem* ratoDireitaP = static_cast<Personagem*>(ratoDireita);
		listaPersonagens.push_back(ratoDireitaP);
		Entidade* ratoDireitaE = static_cast<Entidade*>(ratoDireita);
		return  ratoDireitaE;
	}
	else if (tipo == 25) {
		Rato* ratoCima = new Rato(window, &t_rato, cx, cy, 3, codigo, 2, 4, CIMA);
		listaRatos.push_back(ratoCima);
		Inimigo* ratoCimaI = static_cast<Inimigo*>(ratoCima);
		listaInimigos.push_back(ratoCimaI);
		Personagem* ratoCimaP = static_cast<Personagem*>(ratoCima);
		listaPersonagens.push_back(ratoCimaP);
		Entidade* ratoCimaE = static_cast<Entidade*>(ratoCima);
		return ratoCimaE;
	}
	else if (tipo == 26) {
		Superficie* parede = new Superficie(window, &t_parede, cx, cy, 1, codigo, 1, 1);
		Entidade* paredeE = static_cast<Entidade*>(parede);
		return paredeE;
	}
	else if (tipo == 27) {
		PassagemSecreta* passagemSecreta = new PassagemSecreta(window, &t_passagemsecreta, cx, cy, 2, codigo, 1, 1);
		listaPortais.push_back(passagemSecreta);
		Entidade* passagemSecretaE = static_cast<Entidade*>(passagemSecreta);
		return passagemSecretaE;
	}
	else if (tipo == 28) {
		Abismo* abismo0 = new Abismo(window, &t_abismo, cx, cy, 1, codigo, 6, 3, 0, 2);
		listaAbismo.push_back(abismo0);
		Entidade* abismo0E = static_cast<Entidade*>(abismo0);
		return abismo0E;
	}
	else if (tipo == 29) {
		Abismo* abismo1 = new Abismo(window, &t_abismo, cx, cy, 1, codigo, 6, 3, 1, 0);
		listaAbismo.push_back(abismo1);
		Entidade* abismo1E = static_cast<Entidade*>(abismo1);
		return abismo1E;
	}
	else if (tipo == 30) {
		Abismo* abismo2 = new Abismo(window, &t_abismo, cx, cy, 1, codigo, 6, 3, 2, 0);
		listaAbismo.push_back(abismo2);
		Entidade* abismo2E = static_cast<Entidade*>(abismo2);
		return abismo2E;
	}
	else if (tipo == 31) {
		Abismo* abismo3 = new Abismo(window, &t_abismo, cx, cy, 1, codigo, 6, 3, 1, 2);
		listaAbismo.push_back(abismo3);
		Entidade* abismo3E = static_cast<Entidade*>(abismo3);
		return abismo3E;
	}
	else if (tipo == 32) {
		Abismo* abismo4 = new Abismo(window, &t_abismo, cx, cy, 1, codigo, 6, 3, 3, 0);
		listaAbismo.push_back(abismo4);
		Entidade* abismo4E = static_cast<Entidade*>(abismo4);
		return abismo4E;
	}
	else if (tipo == 33) {
		Abismo* abismo5 = new Abismo(window, &t_abismo, cx, cy, 1, codigo, 6, 3, 1, 1);
		listaAbismo.push_back(abismo5);
		Entidade* abismo5E = static_cast<Entidade*>(abismo5);
		return abismo5E;
	}
	else if (tipo == 34) {
		Abismo* abismo6 = new Abismo(window, &t_abismo, cx, cy, 1, codigo, 6, 3, 3, 1);
		listaAbismo.push_back(abismo6);
		Entidade* abismo6E = static_cast<Entidade*>(abismo6);
		return abismo6E;
	}
	else if (tipo == 35) {
		Abismo* abismo7 = new Abismo(window, &t_abismo, cx, cy, 1, codigo, 6, 3, 2, 2);
		listaAbismo.push_back(abismo7);
		Entidade* abismo7E = static_cast<Entidade*>(abismo7);
		return abismo7E;
	}

	else if (tipo == 36) {
		Abismo* abismo8 = new Abismo(window, &t_abismo, cx, cy, 1, codigo, 6, 3, 3, 2);
		listaAbismo.push_back(abismo8);
		Entidade* abismo8E = static_cast<Entidade*>(abismo8);
		return abismo8E;
	}
	else if (tipo == 37) {
		Abismo* abismo9 = new Abismo(window, &t_abismo, cx, cy, 1, codigo, 6, 3, 2, 1);
		listaAbismo.push_back(abismo9);
		Entidade* abismo9E = static_cast<Entidade*>(abismo9);
		return abismo9E;
	}
	else if (tipo == 38) {
		Abismo* abismo10 = new Abismo(window, &t_abismo, cx, cy, 1, codigo, 6, 3, 4, 0);
		listaAbismo.push_back(abismo10);
		Entidade* abismo10E = static_cast<Entidade*>(abismo10);
		return abismo10E;
	}
	else if (tipo == 39) {
		Abismo* abismo11 = new Abismo(window, &t_abismo, cx, cy, 1, codigo, 6, 3, 4, 1);
		listaAbismo.push_back(abismo11);
		Entidade* abismo11E = static_cast<Entidade*>(abismo11);
		return abismo11E;
	}
	else if (tipo == 40) {
		Abismo* abismo12 = new Abismo(window, &t_abismo, cx, cy, 1, codigo, 6, 3, 5, 0);
		listaAbismo.push_back(abismo12);
		Entidade* abismo12E = static_cast<Entidade*>(abismo12);
		return abismo12E;
	}
	else if (tipo == 41) {
		Abismo* abismo13 = new Abismo(window, &t_abismo, cx, cy, 1, codigo, 6, 3, 5, 1);
		listaAbismo.push_back(abismo13);
		Entidade* abismo13E = static_cast<Entidade*>(abismo13);
		return abismo13E;
	}
	else if (tipo == 42) {
		Porta* porta = new Porta(window, &t_porta, cx, cy, 2, codigo, 2, 1, conexao);
		listaInterativos.push_back(porta);
		listaPortas.push_back(porta);
		Entidade* portaE = static_cast<Entidade*>(porta);
		return portaE;
	}
	else if (tipo == 43) {

	}
	else if (tipo == 44) {
		Superficie* umbralHorizontal = new Superficie(window, &t_umbralhorizontal, cx, cy, 4, codigo, 1, 1);
		Entidade* umbralHorizontalE = static_cast<Entidade*>(umbralHorizontal);
		return umbralHorizontalE;
	}
	else if (tipo == 45) {
		Superficie* umbralVerticalDireita = new Superficie(window, &t_umbralverticaldireita, cx, cy, 4, codigo, 1, 1);
		Entidade* umbralVerticalDireitaE = static_cast<Entidade*>(umbralVerticalDireita);
		return umbralVerticalDireitaE;
	}
	else if (tipo == 46) {
		Superficie* umbralVerticalEsquerda = new Superficie(window, &t_umbralverticalesquerda, cx, cy, 4, codigo, 1, 1);
		Entidade* umbralVerticalEsquerdaE = static_cast<Entidade*>(umbralVerticalEsquerda);
		return umbralVerticalEsquerdaE;
	}
	else if (tipo == 47) {
		Pedra* pedra = new Pedra(window, &t_pedra, cx, cy, 3, codigo, 1, 1);
		Barreira* pedraAux = static_cast<Barreira*>(pedra);
		listaBarreiras.push_back(pedraAux);
		Entidade* pedraE = static_cast<Entidade*>(pedra);
		listaBarreirasCaixas.push_back(pedraE);
		return pedraE;
	}
	else if (tipo == 48) {
		Atirador* atiradorBaixo = new Atirador(window, &t_atirador, cx, cy, 3, codigo, 4, 1, BAIXO, conexao);
		listaAtiradores.push_back(atiradorBaixo);
		listaBarreirasCaixas.push_back(atiradorBaixo);
		Barreira* atiradorBaixoAux = static_cast<Barreira*>(atiradorBaixo);
		listaBarreiras.push_back(atiradorBaixo);
		Entidade* atiradorBaixoE = static_cast<Entidade*>(atiradorBaixo);
		return atiradorBaixoE;
	}
	else if (tipo == 49) {
		Atirador* atiradorEsquerda = new Atirador(window, &t_atirador, cx, cy, 3, codigo, 4, 1, ESQUERDA, conexao);
		listaAtiradores.push_back(atiradorEsquerda);
		listaBarreirasCaixas.push_back(atiradorEsquerda);
		Barreira* atiradorEsquerdaAux = static_cast<Barreira*>(atiradorEsquerda);
		listaBarreiras.push_back(atiradorEsquerda);
		Entidade* atiradorEsquerdaE = static_cast<Entidade*>(atiradorEsquerda);
		return atiradorEsquerda;
	}
	else if (tipo == 50) {
		Atirador* atiradorDireita = new Atirador(window, &t_atirador, cx, cy, 3, codigo, 4, 1, DIREITA, conexao);
		listaAtiradores.push_back(atiradorDireita);
		listaBarreirasCaixas.push_back(atiradorDireita);
		Barreira* atiradorDireitaAux = static_cast<Barreira*>(atiradorDireita);
		listaBarreiras.push_back(atiradorDireita);
		Entidade* atiradorDireitaE = static_cast<Entidade*>(atiradorDireita);
		return atiradorDireitaE;
	}
	else if (tipo == 51) {
		Atirador* atiradorCima = new Atirador(window, &t_atirador, cx, cy, 3, codigo, 4, 1, CIMA, conexao);
		listaAtiradores.push_back(atiradorCima);
		listaBarreirasCaixas.push_back(atiradorCima);
		Barreira* atiradorCimaAux = static_cast<Barreira*>(atiradorCima);
		listaBarreiras.push_back(atiradorCima);
		Entidade* atiradorCimaE = static_cast<Entidade*>(atiradorCima);
		return atiradorCimaE;
	}
	else if (tipo == 52) {
		Espinhos* espinhos = new Espinhos(window, &t_espinhos, cx, cy, 2, codigo, 7, 1, conexao);
		listaEspinhos.push_back(espinhos);
		Entidade* espinhosE = static_cast<Entidade*>(espinhos);
		return espinhosE;
	}
	else if (tipo == 53) {
		Escada* escadaBaixo = new Escada(window, &t_escada, cx, cy, 2, codigo, 2, 1, BAIXO, conexao);
		listaPortais.push_back(escadaBaixo);
		Entidade* escadaBaixoE = static_cast<Entidade*>(escadaBaixo);
		return escadaBaixoE;
	}
	else if (tipo == 54) {
		Escada* escadaCima = new Escada(window, &t_escada, cx, cy, 2, codigo, 2, 1, CIMA, conexao);
		listaPortais.push_back(escadaCima);
		Entidade* escadaCimaE = static_cast<Entidade*>(escadaCima);
		return escadaCimaE;
	}
	else if (tipo == 55) {
		Superficie* topoColunaDireita = new Superficie(window, &t_topocolunadireita, cx, cy, 5, codigo, 1, 1);
		Entidade* topoColunaDireitaE = static_cast<Entidade*>(topoColunaDireita);
		return topoColunaDireitaE;
	}
	else if (tipo == 56) {
		Superficie* topoColunaEsquerda = new Superficie(window, &t_topocolunaesquerda, cx, cy, 5, codigo, 1, 1);
		Entidade* topoColunaEsquerdaE = static_cast<Entidade*>(topoColunaEsquerda);
		return topoColunaEsquerdaE;
	}
	else if (tipo == 57) {
		Interruptor* interruptor = new Interruptor(window, &t_interruptor, cx, cy, 2, codigo, 2, 1, conexao);
		Interativo* interruptorAux = static_cast<Interativo*>(interruptor);
		listaInterativos.push_back(interruptorAux);
		listaInterruptores.push_back(interruptor);
		Entidade* interruptorE = static_cast<Entidade*>(interruptor);
		return  interruptorE;
	}
	else if (tipo == 58) {
		Tocha* tocha = new Tocha(window, &t_tocha, cx, cy, 2, codigo, 6, 1);
		Entidade* tochaE = static_cast<Entidade*>(tocha);
		return tochaE;
	}
	else if (tipo == 59) {
		Botao* botao = new Botao(window, &t_botao, cx, cy, 2, codigo, 2, 1, conexao);
		listaBotoes.push_back(botao);
		Entidade* botaoE = static_cast<Entidade*>(botao);
		return botaoE;
	}
	else if (tipo == 100) {
		Flecha* flechaCima = new Flecha(window, &t_flecha, cx, cy, 2, codigo, 1, 1, CIMA);
		listaFlechas.push_back(flechaCima);
		Entidade* flechaCimaE = static_cast<Entidade*>(flechaCima);
		return flechaCimaE;
	}
	else if (tipo == 101) {
		Flecha* flechaBaixo = new Flecha(window, &t_flecha, cx, cy, 2, codigo, 1, 1, BAIXO);
		listaFlechas.push_back(flechaBaixo);
		Entidade* flechaBaixoE = static_cast<Entidade*>(flechaBaixo);
		return flechaBaixoE;
	}
	else if (tipo == 102) {
		Flecha* flechaDireita = new Flecha(window, &t_flecha, cx, cy, 2, codigo, 1, 1, DIREITA);
		listaFlechas.push_back(flechaDireita);
		Entidade* flechaDireitaE = static_cast<Entidade*>(flechaDireita);
		return flechaDireitaE;
	}
	else if (tipo == 103) {
		Flecha* flechaEsquerda = new Flecha(window, &t_flecha, cx, cy, 2, codigo, 1, 1, ESQUERDA);
		listaFlechas.push_back(flechaEsquerda);
		Entidade* flechaEsquerdaE = static_cast<Entidade*>(flechaEsquerda);
		return flechaEsquerdaE;
	}
}

list<Letal*> GerenciadorEntidades::getListaLetais()const
{
	return listaLetais;
}
list<Barreira*> GerenciadorEntidades::getListaBarreiras()const
{
	return listaBarreiras;
}
list<Interativo*> GerenciadorEntidades::getListaInterativos()const
{
	return listaInterativos;
}
list<SuperficieInterativa*> GerenciadorEntidades::getListaSuperficiesInterativas()const
{
	return listaSuperficiesInterativas;
}

list<Porta*> GerenciadorEntidades::getListaPortas()const
{
	return listaPortas;
}

list<Rato*> GerenciadorEntidades::getListaRatos()const
{
	return listaRatos;
}

list<Interruptor*> GerenciadorEntidades::getListaInterruptores()const
{
	return listaInterruptores;
}
list<Caixa*> GerenciadorEntidades::getListaCaixas()const
{
	return listaCaixas;
}
list<Flecha*> GerenciadorEntidades::getListaFlechas()const
{
	return listaFlechas;
}

list<Entidade*> GerenciadorEntidades::getListaBarreirasCaixas()const
{
	return listaBarreirasCaixas;
}

list<Perseguidor*> GerenciadorEntidades::getListaPerseguidores()const
{
	return listaPerseguidores;
}
list<Entidade*> GerenciadorEntidades::getListaObjetos()const
{
	return listaObjetos;
}
list<Inimigo*> GerenciadorEntidades::getListaInimigos()const
{
	return listaInimigos;
}
list<Personagem*> GerenciadorEntidades::getListaPersonagens()const
{
	return listaPersonagens;
}
list<Item*> GerenciadorEntidades::getListaItens()const
{
	return listaItens;
}
Jogador* GerenciadorEntidades::getJogador()const
{
	return jogadorJ;
}

Bau* GerenciadorEntidades::getBau()const
{
	return bauA;
}

list<Abismo*> GerenciadorEntidades::getListaAbismo()const
{
	return listaAbismo;
}

list<Movimentador*> GerenciadorEntidades::getListaMovimentadores()const
{
	return listaMovimentadores;
}

list<Botao*> GerenciadorEntidades::getListaBotoes()const
{
	return listaBotoes;
}

list<ParedeLevadica*> GerenciadorEntidades::getListaParedesLevadicas()const
{
	return listaParedesLevadicas;
}

list<Espinhos*> GerenciadorEntidades::getListaEspinhos()const
{
	return listaEspinhos;
}

list<Interativo*> GerenciadorEntidades::getListaPortais()const
{
	return listaPortais;
}
list<Atirador*> GerenciadorEntidades::getListaAtiradores()const
{
	return listaAtiradores;
}