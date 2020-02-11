#include "GerenciadorEntidades.h"

GerenciadorEntidades::GerenciadorEntidades()
{
	window = NULL;
}
GerenciadorEntidades::GerenciadorEntidades(RenderWindow* _window)
{
	window = _window;
	a.loadFromFile("Textures/Arrow.png");
	t_blueorb.loadFromFile("Textures/Blue_orb.png");
	t_redorb.loadFromFile("Textures/Red_orb.png");
	t_greenorb.loadFromFile("Textures/Green_orb.png");
	t_moeda.loadFromFile("Textures/Coin.png");
	f.loadFromFile("Textures/Golden_key.png");
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
	u.loadFromFile("Textures/Porta.png");
	v.loadFromFile("Textures/Porta_Cima.png");
	w.loadFromFile("Textures/Porta_Vertical_Direita.png");
	x.loadFromFile("Textures/Porta_Vertical_Esquerda.png");
	t_movimentador.loadFromFile("Textures/Pushing_Floor.png");
	t_rato.loadFromFile("Textures/Rat.png");
	aa.loadFromFile("Textures/Rock2.png");
	ab.loadFromFile("Textures/Shooting_Trap.png");
	t_esqueleto.loadFromFile("Textures/Skel.png");
	ad.loadFromFile("Textures/Spike_trap.png");
	ae.loadFromFile("Textures/Stairs.png");
	af.loadFromFile("Textures/Switch_blue_orange.png");
	ag.loadFromFile("Textures/Switch_press.png");
	ah.loadFromFile("Textures/Topo_Coluna_Direita.png");
	ai.loadFromFile("Textures/Topo_Coluna_Esquerda.png");
	aj.loadFromFile("Textures/Torch.png");
	t_zumbi.loadFromFile("Textures/Zombie.png");
}
GerenciadorEntidades::~GerenciadorEntidades()
{

}

void GerenciadorEntidades::adicionar_entidade(const float cx, const float cy, const int tipo, const int codigo)
{
	Entidade* entidade = NULL;
	switch (tipo) {
	case 0:
		Bau* bau = new Bau(window, &t_bau, cx, cy, 3, codigo);
		break;
	case 1:
		Item* blueOrb = new Item(window, &t_blueorb, cx, cy, 3, codigo, BLUEORB);
		break;
	case 2:
		Item* redOrb = new Item(window, &t_redorb, cx, cy, 3, codigo, REDORB);
		break;
	case 3:
		Item* greenOrb = new Item(window, &t_greenorb, cx, cy, 3, codigo, GREENORB);
		break;
	case 4:
		Item *moeda = new Item(window, &t_moeda, cx, cy, 3, codigo, MOEDA);
		break;
	case 5:
		ParedeLevadica* paredeLevadica = new ParedeLevadica(window, &t_paredelevadica, cx, cy, 3, codigo);
		break;
	case 6:
		Caixa* caixaLeve = new Caixa(window, &t_caixaleve, cx, cy, 3, codigo, 3);
		break;
	case 7:
		Caixa* caixaPesada = new Caixa(window, &t_caixapesada, cx, cy, 3, codigo, 9);
		break;
	case 8:
		Superficie* chao = new Superficie(window, &t_chao, cx, cy, 0, codigo);
		break;
	case 9:
		Item* chave = new Item(window, &t_moeda, cx, cy, 3, codigo, CHAVE);
		break;
	case 10:
		Coluna* colunaHorizontal = new Coluna(window, &t_colunahorizontal, cx, cy, 4, codigo);
		break;
	case 11:
		Coluna * colunaVerticialDireita = new Coluna(window, &t_colunaverticaldireita, cx, cy, 4, codigo);
		break;
	case 12:
		Coluna * colunaVerticialEsquerda = new Coluna(window, &t_colunaverticalesquerda, cx, cy, 4, codigo);
		break;
	case 13:
		Superficie * colunaVerticalDireitaB = new Superficie(window, &t_colunaverticaldireitab, cx, cy, 2, codigo);
		break;
	case 14:
		Superficie * colunaVerticalEsquerdaB = new Superficie(window, &t_colunaverticalesquerdab, cx, cy, 2, codigo);
		break;
	case 15:
		Jogador * jogador = new Jogador(window, &t_jogador, cx, cy, 3, codigo);
		break;
	case 16:
		Perseguidor * esqueleto = new Perseguidor(window, &t_esqueleto, cx, cy, 3, codigo, 3);
		break;
	case 17:
		Perseguidor * zumbi = new Perseguidor(window, &t_zumbi, cx, cy, 3, codigo, 9);
		break;
	case 18:
		Movimentador * movimentadorBaixo = new Movimentador(window, &t_movimentador, cx, cy, 1, codigo, BAIXO);
		break;
	case 19:
		Movimentador * movimentadorBaixo = new Movimentador(window, &t_movimentador, cx, cy, 1, codigo, ESQUERDA);
		break;
	case 20:
		Movimentador * movimentadorBaixo = new Movimentador(window, &t_movimentador, cx, cy, 1, codigo, DIREITA);
		break;
	case 21:
		Movimentador * movimentadorBaixo = new Movimentador(window, &t_movimentador, cx, cy, 1, codigo, CIMA);
		break;
	case 22:
		Rato * rato = new Rato(window, &t_rato, cx, cy, 3, codigo, BAIXO);
		break;
	case 23:
		Rato * rato = new Rato(window, &t_rato, cx, cy, 3, codigo, ESQUERDA);
		break;
	case 24:
		Rato * rato = new Rato(window, &t_rato, cx, cy, 3, codigo, DIREITA);
		break;
	case 25:
		Rato * rato = new Rato(window, &t_rato, cx, cy, 3, codigo, CIMA);
		break;
	case 26:
		Superficie * parede = new Superficie(window, &t_parede, cx, cy, 1, codigo);
		break;
	case 27:
		PassagemSecreta * passagemSecreta = new PassagemSecreta(window, &t_passagemsecreta, cx, cy, 2, codigo);
		break;
	case 28:
		Abismo * abismo = new Abismo(window, &t_abismo, cx, cy, 1, codigo, 0, 2);
		break;
	case 29:
		Abismo * abismo = new Abismo(window, &t_abismo, cx, cy, 1, codigo, 1, 0);
		break;
	case 30:
		Abismo * abismo = new Abismo(window, &t_abismo, cx, cy, 1, codigo, 2, 0);
		break;
	case 31:
		break;
	case 32:
		break;
	case 33:
		break;
	case 34:
		break;
	case 35:
		break;
	case 36:
		break;
	case 37:
		break;
	case 38:
		break;
	case 39:
		break;
	case 40:
		break;
	case 41:
		break;
	case 42:
		break;
	case 43:
		break;
	case 44:
		break;
	case 45:
		break;
	case 46:
		break;
	case 47:
		break;
	case 48:
		break;
	case 49:
		break;
	case 50:
		break;
	case 51:
		break;
	case 52:
		break;
	case 53:
		break;
	case 54:
		break;
	case 55:
		break;
	case 56:
		break;
	case 57:
		break;
	case 58:
		break;
	case 59:
		break;
	}
}