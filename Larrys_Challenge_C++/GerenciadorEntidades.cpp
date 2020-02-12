#include "GerenciadorEntidades.h"

GerenciadorEntidades::GerenciadorEntidades()
{
	window = NULL;
}
GerenciadorEntidades::GerenciadorEntidades(RenderWindow* _window, list<Letal*> _listaLetais, list<Barreira*> _listaBarreiras,
										   list<Interativo*> _listaInterativos, list<SuperficieInterativa*> _listaSuperficiesInterativas,
										   list<Caixa*> _listaCaixas, list<Flecha*> _listaFlechas, list<Inimigo*> _listaInimigos,
										   list<Personagem*> _listaPersonagens, list<Item*> _listaItens)
{
	listaLetais = _listaLetais;
	listaBarreiras = _listaBarreiras;
	listaInterativos = _listaInterativos;
	listaSuperficiesInterativas = _listaSuperficiesInterativas;
	listaCaixas = _listaCaixas;
	listaFlechas = _listaFlechas;
	listaInimigos = _listaInimigos;
	listaPersonagens = _listaPersonagens;
	listaItens = _listaItens;
	
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
}
GerenciadorEntidades::~GerenciadorEntidades()
{

}

Entidade* GerenciadorEntidades::adicionar_entidade(const float cx, const float cy, const int tipo, const int codigo)
{
	switch (tipo) {
	case 0://
		Bau* bau = new Bau(window, &t_bau, cx, cy, 3, codigo);
		Interativo* bauAux = static_cast<Interativo*>(bau);
		listaInterativos.push_back(bauAux);
		Entidade* bauE = static_cast<Entidade*>(bau);
		return bauE;
		break;
	case 1://
		Item* blueOrb = new Item(window, &t_blueorb, cx, cy, 3, codigo, BLUEORB);
		listaItens.push_back(blueOrb);
		Entidade* blueOrbE = static_cast<Entidade*>(blueOrb);
		return blueOrbE;
		break;
	case 2://
		Item* redOrb = new Item(window, &t_redorb, cx, cy, 3, codigo, REDORB);
		listaItens.push_back(redOrb);
		Entidade* redOrbE= static_cast<Entidade*>(redOrb);
		return redOrbE;
		break;
	case 3://
		Item* greenOrb = new Item(window, &t_greenorb, cx, cy, 3, codigo, GREENORB);
		listaItens.push_back(greenOrb);
		Entidade* greenOrbE = static_cast<Entidade*>(greenOrb);
		return greenOrbE;
		break;
	case 4://
		Item * moeda = new Item(window, &t_moeda, cx, cy, 3, codigo, MOEDA);
		listaItens.push_back(moeda);
		Entidade* moedaE = static_cast<Entidade*>(moeda);
		return moedaE;
		break;
	case 5://
		ParedeLevadica* paredeLevadica = new ParedeLevadica(window, &t_paredelevadica, cx, cy, 3, codigo);
		SuperficieInterativa* paredeLevadicaAux = static_cast<SuperficieInterativa*>(paredeLevadica);
		listaSuperficiesInterativas.push_back(paredeLevadicaAux);
		Entidade* paredeLevadicaE = static_cast<Entidade*>(paredeLevadica);
		return paredeLevadicaE;
		break;
	case 6://
		Caixa* caixaLeve = new Caixa(window, &t_caixaleve, cx, cy, 3, codigo, 3);
		listaCaixas.push_back(caixaLeve);
		Entidade* caixaLeveE = static_cast<Entidade*>(caixaLeve);
		return caixaLeveE;
		break;
	case 7://
		Caixa* caixaPesada = new Caixa(window, &t_caixapesada, cx, cy, 3, codigo, 9);
		listaCaixas.push_back(caixaPesada);
		Entidade* caixaPesadaE = static_cast<Entidade*>(caixaPesada);
		return caixaPesadaE;
		break;
	case 8://
		Superficie* chao = new Superficie(window, &t_chao, cx, cy, 0, codigo);
		Entidade* chaoE = static_cast<Entidade*>(chao);
		return chaoE;
		break;
	case 9://
		Item * chave = new Item(window, &t_chave, cx, cy, 3, codigo, CHAVE);
		listaItens.push_back(chave);
		Entidade* chaveE = static_cast<Entidade*>(chave);
		return chaveE;
		break;
	case 10://
		Coluna* colunaHorizontal = new Coluna(window, &t_colunahorizontal, cx, cy, 4, codigo);
		Barreira* colunaHorizontalB = static_cast<Barreira*>(colunaHorizontal);
		listaBarreiras.push_back(colunaHorizontal);
		Entidade* colunaHorizontalE = static_cast<Entidade*>(colunaHorizontal);
		return colunaHorizontalE;
		break;
	case 11://
		Coluna * colunaVerticalDireita = new Coluna(window, &t_colunaverticaldireita, cx, cy, 4, codigo);
		Barreira* colunaVerticalDireitaB = static_cast<Barreira*>(colunaVerticalDireita);
		listaBarreiras.push_back(colunaVerticalDireita);
		Entidade* colunaVerticalDireitaE = static_cast<Entidade*>(colunaVerticalDireita);
		return colunaVerticalDireitaE;
		break;
	case 12://
		Coluna * colunaVerticalEsquerda = new Coluna(window, &t_colunaverticalesquerda, cx, cy, 4, codigo);
		Barreira* colunaVerticalEsquerdaB = static_cast<Barreira*>(colunaVerticalEsquerda);
		listaBarreiras.push_back(colunaVerticalEsquerdaB);
		Entidade* colunaVerticalEsquerdaE = static_cast<Entidade*>(colunaVerticalEsquerda);
		return colunaVerticalEsquerdaE;
		break;
	case 13://
		Superficie * colunaVerticalDireita2 = new Superficie(window, &t_colunaverticaldireitab, cx, cy, 2, codigo);
		Entidade* colunaVerticalDireitaBE = static_cast<Entidade*>(colunaVerticalDireita2);
		return colunaVerticalDireitaBE;
		break;
	case 14://
		Superficie * colunaVerticalEsquerda2 = new Superficie(window, &t_colunaverticalesquerdab, cx, cy, 2, codigo);
		Entidade* colunaVerticalEsquerdaBE = static_cast<Entidade*>(colunaVerticalEsquerda2);
		return colunaVerticalEsquerdaBE;
		break;
	case 15://
		Jogador * jogador = new Jogador(window, &t_jogador, cx, cy, 3, codigo);
		Personagem* jogadorP = static_cast<Personagem*>(jogador);
		listaPersonagens.push_back(jogadorP);
		Entidade* jogadorE = static_cast<Entidade*>(jogador);
		return jogadorE;
		break;
	case 16://
		Perseguidor * esqueleto = new Perseguidor(window, &t_esqueleto, cx, cy, 3, codigo, 3);
		Inimigo* esqueletoI = static_cast<Inimigo*>(esqueleto);
		listaInimigos.push_back(esqueletoI);
		Personagem* esqueletoP = static_cast<Personagem*>(esqueleto);
		listaPersonagens.push_back(esqueletoP);
		Entidade* esqueletoE = static_cast<Entidade*>(esqueleto);
		return esqueletoE;
		break;
	case 17://
		Perseguidor * zumbi = new Perseguidor(window, &t_zumbi, cx, cy, 3, codigo, 9);
		Inimigo* zumbiI = static_cast<Inimigo*>(zumbi);
		listaInimigos.push_back(zumbiI);
		Personagem* zumbiP = static_cast<Personagem*>(zumbi);
		listaPersonagens.push_back(zumbiP);
		Entidade* zumbiE = static_cast<Entidade*>(zumbi);
		return zumbiE;
		break;
	case 18://
		Movimentador * movimentadorBaixo = new Movimentador(window, &t_movimentador, cx, cy, 1, codigo, BAIXO);
		SuperficieInterativa* movimentadorBaixoS = static_cast<SuperficieInterativa*>(movimentadorBaixo);
		listaSuperficiesInterativas.push_back(movimentadorBaixoS);
		Entidade* movimentadorBaixoE = static_cast<Entidade*>(movimentadorBaixo);
		return movimentadorBaixoE;
		break;
	case 19://
		Movimentador * movimentadorEsquerda = new Movimentador(window, &t_movimentador, cx, cy, 1, codigo, ESQUERDA);
		SuperficieInterativa* movimentadorEsquerdaS = static_cast<SuperficieInterativa*>(movimentadorEsquerda);
		listaSuperficiesInterativas.push_back(movimentadorEsquerdaS);
		Entidade* movimentadorEsquerdaE = static_cast<Entidade*>(movimentadorEsquerda);
		return movimentadorEsquerdaE;
		break;
	case 20://
		Movimentador * movimentadorDireita = new Movimentador(window, &t_movimentador, cx, cy, 1, codigo, DIREITA);
		SuperficieInterativa* movimentadorDireitaS = static_cast<SuperficieInterativa*>(movimentadorDireita);
		listaSuperficiesInterativas.push_back(movimentadorDireitaS);
		Entidade* movimentadorDireitaE = static_cast<Entidade*>(movimentadorDireita);
		return movimentadorDireitaE;
		break;
	case 21://
		Movimentador * movimentadorCima = new Movimentador(window, &t_movimentador, cx, cy, 1, codigo, CIMA);
		SuperficieInterativa* movimentadorCimaS = static_cast<SuperficieInterativa*>(movimentadorCima);
		listaSuperficiesInterativas.push_back(movimentadorCimaS);
		Entidade* movimentadorCimaE = static_cast<Entidade*>(movimentadorCima);
		return movimentadorCimaE;
		break;
	case 22://
		Rato * ratoBaixo = new Rato(window, &t_rato, cx, cy, 3, codigo, BAIXO);
		Inimigo* ratoBaixoI = static_cast<Inimigo*>(ratoBaixo);
		listaInimigos.push_back(ratoBaixoI);
		Personagem* ratoBaixoP = static_cast<Personagem*>(ratoBaixo);
		listaPersonagens.push_back(ratoBaixoP);
		Entidade* ratoBaixoE = static_cast<Entidade*>(ratoBaixo);
		return ratoBaixoE;
		break;
	case 23://
		Rato * ratoEsquerda = new Rato(window, &t_rato, cx, cy, 3, codigo, ESQUERDA);
		Inimigo* ratoEsquerdaI = static_cast<Inimigo*>(ratoEsquerda);
		listaInimigos.push_back(ratoEsquerdaI);
		Personagem* ratoEsquerdaP = static_cast<Personagem*>(ratoEsquerda);
		listaPersonagens.push_back(ratoEsquerdaP);
		Entidade* ratoEsquerdaE = static_cast<Entidade*>(ratoEsquerda);
		return ratoEsquerdaE;
		break;
	case 24://
		Rato * ratoDireita = new Rato(window, &t_rato, cx, cy, 3, codigo, DIREITA);
		Inimigo* ratoDireitaI = static_cast<Inimigo*>(ratoDireita);
		listaInimigos.push_back(ratoDireitaI);
		Personagem* ratoDireitaP = static_cast<Personagem*>(ratoDireita);
		listaPersonagens.push_back(ratoDireitaP);
		Entidade* ratoDireitaE = static_cast<Entidade*>(ratoDireita);
		return  ratoDireitaE;
		break;
	case 25://
		Rato * ratoCima = new Rato(window, &t_rato, cx, cy, 3, codigo, CIMA);
		Inimigo* ratoCimaI = static_cast<Inimigo*>(ratoCima);
		listaInimigos.push_back(ratoCimaI);
		Personagem* ratoCimaP = static_cast<Personagem*>(ratoCima);
		listaPersonagens.push_back(ratoCimaP);
		Entidade* ratoCimaE = static_cast<Entidade*>(ratoCima);
		return ratoCimaE;
		break;
	case 26://
		Superficie * parede = new Superficie(window, &t_parede, cx, cy, 1, codigo);
		Entidade* paredeE = static_cast<Entidade*>(parede);
		return paredeE;
		break;
	case 27://
		PassagemSecreta *passagemSecreta = new PassagemSecreta(window, &t_passagemsecreta, cx, cy, 2, codigo);
		Interativo* passagemSecretaAux = static_cast<Interativo*>(passagemSecretaAux);
		listaInterativos.push_back(passagemSecretaAux);
		Entidade* passagemSecretaE = static_cast<Entidade*>(passagemSecreta);
		return passagemSecretaE;
		break;
	case 28://
		Abismo* abismo0 = new Abismo(window, &t_abismo, cx, cy, 1, codigo, 0, 2);
		Letal* abismo0Aux = static_cast<Letal*>(abismo0);
		listaLetais.push_back(abismo0Aux);
		Entidade* abismo0E = static_cast<Entidade*>(abismo0);
		return abismo0E;
		break;
	case 29://
		Abismo* abismo1 = new Abismo(window, &t_abismo, cx, cy, 1, codigo, 1, 0);
		Letal* abismo1Aux = static_cast<Letal*>(abismo1);
		listaLetais.push_back(abismo1Aux);
		Entidade* abismo1E = static_cast<Entidade*>(abismo1);
		return abismo1E;
		break;
	case 30://
		Abismo* abismo2 = new Abismo(window, &t_abismo, cx, cy, 1, codigo, 2, 0);
		Letal* abismo2Aux = static_cast<Letal*>(abismo2);
		listaLetais.push_back(abismo2Aux);
		Entidade* abismo2E = static_cast<Entidade*>(abismo2);
		return abismo2E;
		break;
	case 31://
		Abismo* abismo3 = new Abismo(window, &t_abismo, cx, cy, 1, codigo, 1, 2);
		Letal* abismo3Aux = static_cast<Letal*>(abismo3);
		listaLetais.push_back(abismo3Aux);
		Entidade* abismo3E = static_cast<Entidade*>(abismo3);
		return abismo3E;
		break;
	case 32://
		Abismo* abismo4 = new Abismo(window, &t_abismo, cx, cy, 1, codigo, 3, 0);
		Letal* abismo4Aux = static_cast<Letal*>(abismo4);
		listaLetais.push_back(abismo4Aux);
		Entidade* abismo4E = static_cast<Entidade*>(abismo4);
		return abismo4E;
		break;
	case 33://
		Abismo* abismo5 = new Abismo(window, &t_abismo, cx, cy, 1, codigo, 1, 1);
		Letal* abismo5Aux = static_cast<Letal*>(abismo5);
		listaLetais.push_back(abismo5Aux);
		Entidade* abismo5E = static_cast<Entidade*>(abismo5);
		return abismo5E;
		break;
	case 34://
		Abismo* abismo6 = new Abismo(window, &t_abismo, cx, cy, 1, codigo, 3, 1);
		Letal* abismo6Aux = static_cast<Letal*>(abismo6);
		listaLetais.push_back(abismo6Aux);
		Entidade* abismo6E = static_cast<Entidade*>(abismo6);
		return abismo6E;
		break;
	case 35://
		Abismo* abismo7 = new Abismo(window, &t_abismo, cx, cy, 1, codigo, 2, 2);
		Letal* abismo7Aux = static_cast<Letal*>(abismo7);
		listaLetais.push_back(abismo7Aux);
		Entidade* abismo7E = static_cast<Entidade*>(abismo7);
		return abismo7E;
		break;
	case 36://
		Abismo* abismo8 = new Abismo(window, &t_abismo, cx, cy, 1, codigo, 3, 2);
		Letal* abismo8Aux = static_cast<Letal*>(abismo8);
		listaLetais.push_back(abismo8Aux);
		Entidade* abismo8E = static_cast<Entidade*>(abismo8);
		return abismo8E;
		break;
	case 37://
		Abismo* abismo9 = new Abismo(window, &t_abismo, cx, cy, 1, codigo, 2, 1);
		Letal* abismo9Aux = static_cast<Letal*>(abismo9);
		listaLetais.push_back(abismo9Aux);
		Entidade* abismo9E = static_cast<Entidade*>(abismo9);
		return abismo9E;
		break;
	case 38://
		Abismo* abismo10 = new Abismo(window, &t_abismo, cx, cy, 1, codigo, 4, 0);
		Letal* abismo10Aux = static_cast<Letal*>(abismo10);
		listaLetais.push_back(abismo10Aux);
		Entidade* abismo10E = static_cast<Entidade*>(abismo10);
		return abismo10E;
		break;
	case 39://
		Abismo* abismo11 = new Abismo(window, &t_abismo, cx, cy, 1, codigo, 4, 1);
		Letal* abismo11Aux = static_cast<Letal*>(abismo11);
		listaLetais.push_back(abismo11Aux);
		Entidade* abismo11E = static_cast<Entidade*>(abismo11);
		return abismo11E;
		break;
	case 40://
		Abismo* abismo12 = new Abismo(window, &t_abismo, cx, cy, 1, codigo, 5, 0);
		Letal* abismo12Aux = static_cast<Letal*>(abismo12);
		listaLetais.push_back(abismo12Aux);
		Entidade* abismo12E = static_cast<Entidade*>(abismo12);
		return abismo12E;
		break;
	case 41://
		Abismo * abismo13 = new Abismo(window, &t_abismo, cx, cy, 1, codigo, 5, 1);
		Letal* abismo13Aux = static_cast<Letal*>(abismo13);
		listaLetais.push_back(abismo13Aux);
		Entidade* abismo13E = static_cast<Entidade*>(abismo13);
		return abismo13E;
		break;
	case 42://
		Porta * porta = new Porta(window, &t_porta, cx, cy, 2, codigo);
		Interativo* portaAux = static_cast<Interativo*>(porta);
		listaInterativos.push_back(portaAux);
		Entidade* portaE = static_cast<Entidade*>(porta);
		return portaE;
		break;
	case 43://
		Porta * porta = new Porta(window, &t_porta, cx, cy, 2, codigo);
		Interativo* portaAux = static_cast<Interativo*>(porta);
		listaInterativos.push_back(portaAux);
		Entidade* portaE = static_cast<Entidade*>(porta);
		return portaE;
		break;
	case 44://
		Superficie * umbralHorizontal = new Superficie(window, &t_umbralhorizontal, cx, cy, 4, codigo);
		Entidade* umbralHorizontalE = static_cast<Entidade*>(umbralHorizontal);
		return umbralHorizontalE;
		break;
	case 45://
		Superficie * umbralVerticalDireita = new Superficie(window, &t_umbralverticaldireita, cx, cy, 4, codigo);
		Entidade* umbralVerticalDireitaE = static_cast<Entidade*>(umbralVerticalDireita);
		return umbralVerticalDireitaE;
		break;
	case 46://
		Superficie * umbralVerticalEsquerda = new Superficie(window, &t_umbralverticalesquerda, cx, cy, 4, codigo);
		Entidade* umbralVerticalEsquerdaE = static_cast<Entidade*>(umbralVerticalEsquerda);
		return umbralVerticalEsquerdaE;
		break;
	case 47://
		Pedra * pedra = new Pedra(window, &t_pedra, cx, cy, 3, codigo);
		Barreira* pedraAux = static_cast<Barreira*>(pedra);
		listaBarreiras.push_back(pedraAux);
		Entidade* pedraE = static_cast<Entidade*>(pedra);
		return pedraE;
		break;
	case 48://
		Atirador * atiradorBaixo = new Atirador(window, &t_atirador, cx, cy, 3, codigo, BAIXO);
		Barreira* atiradorBaixoAux = static_cast<Barreira*>(atiradorBaixo);
		listaBarreiras.push_back(atiradorBaixo);
		Entidade* atiradorBaixoE = static_cast<Entidade*>(atiradorBaixo);
		return atiradorBaixoE;
		break;
	case 49://
		Atirador * atiradorEsquerda = new Atirador(window, &t_atirador, cx, cy, 3, codigo, ESQUERDA);
		Barreira* atiradorEsquerdaAux = static_cast<Barreira*>(atiradorEsquerda);
		listaBarreiras.push_back(atiradorEsquerda);
		Entidade* atiradorEsquerdaE = static_cast<Entidade*>(atiradorEsquerda);
		return atiradorEsquerda;
		break;
	case 50://
		Atirador * atiradorDireita = new Atirador(window, &t_atirador, cx, cy, 3, codigo, DIREITA);
		Barreira* atiradorDireitaAux = static_cast<Barreira*>(atiradorDireita);
		listaBarreiras.push_back(atiradorDireita);
		Entidade* atiradorDireitaE = static_cast<Entidade*>(atiradorDireita);
		return atiradorDireitaE;
		break;
	case 51://
		Atirador * atiradorCima = new Atirador(window, &t_atirador, cx, cy, 3, codigo, CIMA);
		Barreira* atiradorCimaAux = static_cast<Barreira*>(atiradorCima);
		listaBarreiras.push_back(atiradorCima);
		Entidade* atiradorCimaE = static_cast<Entidade*>(atiradorCima);
		return atiradorCimaE;
		break;
	case 52://
		Espinhos * espinhos = new Espinhos(window, &t_espinhos, cx, cy, 2, codigo);
		Letal* espinhosAux = static_cast<Letal*>(espinhos);
		listaLetais.push_back(espinhosAux);
		Entidade* espinhosE = static_cast<Entidade*>(espinhos);
		return espinhosE;
		break;
	case 53://
		Escada * escadaBaixo = new Escada(window, &t_escada, cx, cy, 2, codigo, BAIXO);
		Interativo* escadaBaixoAux = static_cast<Interativo*>(escadaBaixo);
		listaInterativos.push_back(escadaBaixoAux);
		Entidade* escadaBaixoE = static_cast<Entidade*>(escadaBaixo);
		return escadaBaixoE;
		break;
	case 54://
		Escada * escadaCima = new Escada(window, &t_escada, cx, cy, 2, codigo, CIMA);
		Interativo* escadaCimaAux = static_cast<Interativo*>(escadaCima);
		listaInterativos.push_back(escadaCimaAux);
		Entidade* escadaCimaE = static_cast<Entidade*>(escadaCima);
		return escadaCimaE;
		break;
	case 55: //
		Superficie * topoColunaDireita = new Superficie(window, &t_topocolunadireita, cx, cy, 5, codigo);
		Entidade* topoColunaDireitaE = static_cast<Entidade*>(topoColunaDireita);
		return topoColunaDireitaE;
		break;
	case 56: //
		Superficie * topoColunaEsquerda = new Superficie(window, &t_topocolunaesquerda, cx, cy, 5, codigo);
		Entidade* topoColunaEsquerdaE = static_cast<Entidade*>(topoColunaEsquerda);
		return topoColunaEsquerdaE;
		break;
	case 57: //
		Interruptor * interruptor = new Interruptor(window, &t_interruptor, cx, cy, 3, codigo);
		Interativo* interruptorAux = static_cast<Interativo*>(interruptor);
		listaInterativos.push_back(interruptorAux);
		Entidade* interruptorE = static_cast<Entidade*>(interruptor);
		return  interruptorE;
		break;
	case 58: //
		Tocha * tocha = new Tocha(window, &t_tocha, cx, cy, 2, codigo);
		Entidade* tochaE = static_cast<Entidade*>(tocha);
		return tochaE;
		break;
	case 59://
		Botao * botao = new Botao(window, &t_botao, cx, cy, 2, codigo);
		SuperficieInterativa* auxBotao = static_cast<SuperficieInterativa*>(paredeLevadica);
		listaSuperficiesInterativas.push_back(paredeLevadica);
		Entidade* botaoE = static_cast<Entidade*>(botao);
		return botaoE;
		break;
	}

	return NULL;
}