#include "GerenciadorEntidades.h"

GerenciadorEntidades::GerenciadorEntidades()
{
	window = NULL;
}
GerenciadorEntidades::GerenciadorEntidades(RenderWindow* _window)
{
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

void GerenciadorEntidades::adicionar_entidade(const float cx, const float cy, const int tipo, const int codigo)
{
	Entidade* entidade = NULL;
	switch (tipo) {
	case 0:
		Bau* entidade = new Bau(window, &t_bau, cx, cy, 3, codigo);
		break;
	case 1:
		Item* entidade = new Item(window, &t_blueorb, cx, cy, 3, codigo, BLUEORB);
		break;
	case 2:
		Item* entidade = new Item(window, &t_redorb, cx, cy, 3, codigo, REDORB);
		break;
	case 3:
		Item* entidade = new Item(window, &t_greenorb, cx, cy, 3, codigo, GREENORB);
		break;
	case 4:
		Item * entidade = new Item(window, &t_moeda, cx, cy, 3, codigo, MOEDA);
		break;
	case 5:
		ParedeLevadica* entidade = new ParedeLevadica(window, &t_paredelevadica, cx, cy, 3, codigo);
		break;
	case 6:
		Caixa* entidade = new Caixa(window, &t_caixaleve, cx, cy, 3, codigo, 3);
		break;
	case 7:
		Caixa* entidade = new Caixa(window, &t_caixapesada, cx, cy, 3, codigo, 9);
		break;
	case 8:
		Superficie* entidade = new Superficie(window, &t_chao, cx, cy, 0, codigo);
		break;
	case 9:
		Item * entidade = new Item(window, &t_chave, cx, cy, 3, codigo, CHAVE);
		break;
	case 10:
		Item* entidade = new Item(window, &t_moeda, cx, cy, 3, codigo, CHAVE);
		break;
	case 11:
		Coluna* entidade = new Coluna(window, &t_colunahorizontal, cx, cy, 4, codigo);
		break;
	case 12:
		Coluna * entidade = new Coluna(window, &t_colunaverticaldireita, cx, cy, 4, codigo);
		break;
	case 13:
		Coluna * entidade = new Coluna(window, &t_colunaverticalesquerda, cx, cy, 4, codigo);
		break;
	case 14:
		Superficie * entidade = new Superficie(window, &t_colunaverticaldireitab, cx, cy, 2, codigo);
		break;
	case 15:
		Superficie * entidade = new Superficie(window, &t_colunaverticalesquerdab, cx, cy, 2, codigo);
		break;
	case 16:
		Jogador * entidade = new Jogador(window, &t_jogador, cx, cy, 3, codigo);
		break;
	case 17:
		Perseguidor * entidade = new Perseguidor(window, &t_esqueleto, cx, cy, 3, codigo, 3);
		break;
	case 18:
		Perseguidor * entidade = new Perseguidor(window, &t_zumbi, cx, cy, 3, codigo, 9);
		break;
	case 19:
		Movimentador * entidade = new Movimentador(window, &t_movimentador, cx, cy, 1, codigo, BAIXO);
		break;
	case 20:
		Movimentador * entidade = new Movimentador(window, &t_movimentador, cx, cy, 1, codigo, ESQUERDA);
		break;
	case 21:
		Movimentador * entidade = new Movimentador(window, &t_movimentador, cx, cy, 1, codigo, DIREITA);
		break;
	case 22:
		Movimentador * entidade = new Movimentador(window, &t_movimentador, cx, cy, 1, codigo, CIMA);
		break;
	case 23:
		Rato * entidade = new Rato(window, &t_rato, cx, cy, 3, codigo, BAIXO);
		break;
	case 24:
		Rato * entidade = new Rato(window, &t_rato, cx, cy, 3, codigo, ESQUERDA);
		break;
	case 25:
		Rato * entidade = new Rato(window, &t_rato, cx, cy, 3, codigo, DIREITA);
		break;
	case 26:
		Rato * entidade = new Rato(window, &t_rato, cx, cy, 3, codigo, CIMA);
		break;
	case 27:
		Superficie * entidade = new Superficie(window, &t_parede, cx, cy, 1, codigo);
		break;
	case 28:
		PassagemSecreta * entidade = new PassagemSecreta(window, &t_passagemsecreta, cx, cy, 2, codigo);
		break;
	case 29:
		Abismo * entidade = new Abismo(window, &t_abismo, cx, cy, 1, codigo, 0, 2);
		break;
	case 30:
		Abismo * entidade = new Abismo(window, &t_abismo, cx, cy, 1, codigo, 1, 0);
		break;
	case 31:
		Abismo * entidade = new Abismo(window, &t_abismo, cx, cy, 1, codigo, 2, 0);
		break;
	case 32:
		Abismo * entidade = new Abismo(window, &t_abismo, cx, cy, 1, codigo, 1, 2);
		break;
	case 33:
		Abismo * entidade = new Abismo(window, &t_abismo, cx, cy, 1, codigo, 3, 0);
		break;
	case 34:
		Abismo * entidade = new Abismo(window, &t_abismo, cx, cy, 1, codigo, 1, 1);
		break;
	case 35:
		Abismo * entidade = new Abismo(window, &t_abismo, cx, cy, 1, codigo, 3, 1);
		break;
	case 36:
		Abismo * entidade = new Abismo(window, &t_abismo, cx, cy, 1, codigo, 2, 2);
		break;
	case 37:
		Abismo * entidade = new Abismo(window, &t_abismo, cx, cy, 1, codigo, 3, 2);
		break;
	case 38:
		Abismo * entidade = new Abismo(window, &t_abismo, cx, cy, 1, codigo, 2, 1);
		break;
	case 39:
		Abismo * entidade = new Abismo(window, &t_abismo, cx, cy, 1, codigo, 4, 0);
		break;
	case 40:
		Abismo * entidade = new Abismo(window, &t_abismo, cx, cy, 1, codigo, 4, 1);
		break;
	case 41:
		Abismo * entidade = new Abismo(window, &t_abismo, cx, cy, 1, codigo, 5, 0);
		break;
	case 42:
		Abismo * entidade = new Abismo(window, &t_abismo, cx, cy, 1, codigo, 5, 1);
		break;
	case 43:
		Porta * entidade = new Porta(window, &t_porta, cx, cy, 2, codigo);
		break;
	case 44:
		break;
	case 45:
		Superficie * entidade = new Superficie(window, &t_umbralhorizontal, cx, cy, 4, codigo);
		break;
	case 46:
		Superficie * entidade = new Superficie(window, &t_umbralverticaldireita, cx, cy, 4, codigo);
		break;
	case 47:
		Superficie * entidade = new Superficie(window, &t_umbralverticalesquerda, cx, cy, 4, codigo);
		break;
	case 48:
		Pedra * entidade = new Pedra(window, &t_pedra, cx, cy, 3, codigo);
		break;
	case 49:
		Atirador * entidade = new Atirador(window, &t_atirador, cx, cy, 3, codigo, BAIXO);
		break;
	case 50:
		Atirador * entidade = new Atirador(window, &t_atirador, cx, cy, 3, codigo, ESQUERDA);
		break;
	case 51:
		Atirador * entidade = new Atirador(window, &t_atirador, cx, cy, 3, codigo, DIREITA);
		break;
	case 52:
		Atirador * entidade = new Atirador(window, &t_atirador, cx, cy, 3, codigo, CIMA);
		break;
	case 53:
		Espinhos * entidade = new Espinhos(window, &t_espinhos, cx, cy, 2, codigo);
		break;
	case 54:
		Escada * entidade = new Escada(window, &t_escada, cx, cy, 2, codigo, BAIXO);
		break;
	case 55:
		Escada * entidade = new Escada(window, &t_escada, cx, cy, 2, codigo, CIMA);
		break;
	case 56:
		Superficie * entidade = new Superficie(window, &t_topocolunadireita, cx, cy, 5, codigo);
		break;
	case 57:
		Superficie * entidade = new Superficie(window, &t_topocolunaesquerda, cx, cy, 5, codigo);
		break;
	case 58:
		Interruptor * entidade = new Interruptor(window, &t_interruptor, cx, cy, 3, codigo);
		break;
	case 59:
		Tocha * entidade = new Tocha(window, &t_tocha, cx, cy, 2, codigo);
		break;
	case 60:
		Botao * entidade = new Botao(window, &t_botao, cx, cy, 2, codigo);
		break;
	}
}