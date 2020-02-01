#include "LarrysChallenge.h"

LarrysChallenge::LarrysChallenge()
{
	window = new RenderWindow(VideoMode(1600, 900), "Larry's Challenge", Style::Close);
	listaEntidades = new ListaEntidades(window);
	window->setFramerateLimit(60);
	window->setMouseCursorVisible(false);
	//listaEntidades->adicionar_entidade(100, 100);


	movimentador = new Movimentador(window, 200, 200, 1, CIMA);
	movimentador2 = new Movimentador(window, 200, 280, 1, CIMA);
	movimentador3 = new Movimentador(window, 200, 120, 1, DIREITA);
	botao = new Botao(window, 200, 200, 1);
	interruptor = new Interruptor(window, 400, 200, 1);
	aux = true;
	jogador = new Jogador(window, 100, 100, 1);
	zumbi = new Zumbi(window, 200, 200, 1);
	bau = new Bau(window, 600, 200, 1);
	executar();

}
LarrysChallenge::~LarrysChallenge()
{
	delete window;
	delete listaEntidades;
}
void LarrysChallenge::executar()
{
	while (window->isOpen()) {
		Event evnt;
		while (window->pollEvent(evnt)) {
			switch (evnt.type) {
			case Event::Closed:
				window->close();
				break;
			}
		}

		window->clear(Color(50, 90, 80, 255));
		interruptor->existir();
		botao->existir();
		bau->existir();
		jogador->existir();

		/*if (jogador->getCoordenadas().x + jogador->getDimensoes().x < movimentador->getCoordenadas().x ||
			jogador->getCoordenadas().x > movimentador->getCoordenadas().x + movimentador->getDimensoes().x ||
			jogador->getCoordenadas().y + jogador->getDimensoes().y < movimentador->getCoordenadas().y ||
			jogador->getCoordenadas().y > movimentador->getCoordenadas().y + movimentador->getDimensoes().y) {

		}
		else {
			if (movimentador->getDirecao() == CIMA)
				jogador->setMovimentadory(-8);
			else if (movimentador->getDirecao() == BAIXO)
				jogador->setMovimentadory(-8);
			else if (movimentador->getDirecao() == ESQUERDA)
				jogador->setMovimentadory(-8);
			else if (movimentador->getDirecao() == DIREITA)
				jogador->setMovimentadory(8);

			cout << "aqui" << endl;
		}*/

		/*if (jogador->getCoordenadas().x < movimentador->getCoordenadas().x + movimentador->getDimensoes().x &&
			jogador->getCoordenadas().x + jogador->getDimensoes().x > movimentador->getCoordenadas().x &&
			jogador->getCoordenadas().y < movimentador->getCoordenadas().y + movimentador->getDimensoes().y &&
			jogador->getCoordenadas().y + jogador->getDimensoes().y > movimentador->getCoordenadas().y) {

			jogador->setMovimentadory(-15);
		}
		if (jogador->getCoordenadas().x < movimentador2->getCoordenadas().x + movimentador2->getDimensoes().x &&
			jogador->getCoordenadas().x + jogador->getDimensoes().x > movimentador2->getCoordenadas().x&&
			jogador->getCoordenadas().y < movimentador2->getCoordenadas().y + movimentador2->getDimensoes().y &&
			jogador->getCoordenadas().y + jogador->getDimensoes().y > movimentador2->getCoordenadas().y) {

			jogador->setMovimentadory(-15);
		}*/

		if (jogador->getCoordenadas().x < botao->getCoordenadas().x + botao->getDimensoes().x &&
			jogador->getCoordenadas().x + jogador->getDimensoes().x > botao->getCoordenadas().x&&
			jogador->getCoordenadas().y < botao->getCoordenadas().y + botao->getDimensoes().y &&
			jogador->getCoordenadas().y + jogador->getDimensoes().y > botao->getCoordenadas().y) {
			
			botao->setAtivado(true);
		}
		else 
			botao->setAtivado(false);

		if (jogador->getCoordenadas().x < interruptor->getCoordenadas().x + interruptor->getDimensoes().x &&
			jogador->getCoordenadas().x + jogador->getDimensoes().x > interruptor->getCoordenadas().x&&
			jogador->getCoordenadas().y < interruptor->getCoordenadas().y + interruptor->getDimensoes().y &&
			jogador->getCoordenadas().y + jogador->getDimensoes().y > interruptor->getCoordenadas().y) {

			
			if (jogador->getAcao() && interruptor->getAtivado()) {
				interruptor->setAtivado(false);
			}

			else if (jogador->getAcao() && !interruptor->getAtivado()) {
				interruptor->setAtivado(true);
			}
		}

		if (jogador->getCoordenadas().x < bau->getCoordenadas().x + bau->getDimensoes().x &&
			jogador->getCoordenadas().x + jogador->getDimensoes().x > bau->getCoordenadas().x&&
			jogador->getCoordenadas().y < bau->getCoordenadas().y + bau->getDimensoes().y &&
			jogador->getCoordenadas().y + jogador->getDimensoes().y > bau->getCoordenadas().y) {


			if (jogador->getAcao() && !bau->getAtivado()) {
				bau->setAtivado(true);
			}
		}

		//cout << jogador->getCoordenadas().x << "     " << movimentador->getCoordenadas().x + movimentador->getDimensoes().x << "    " << 
			//jogador->getCoordenadas().x + jogador->getDimensoes().x << "   " << movimentador->getCoordenadas().x << endl;

		


		//zumbi->setCoodenadasJogador(jogador->getCoordenadas().x, jogador->getCoordenadas().y);
		//zumbi->existir();
		window->display();

	}
}