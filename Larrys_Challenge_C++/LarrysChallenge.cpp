#include "LarrysChallenge.h"

LarrysChallenge::LarrysChallenge()
{
	window = new RenderWindow(VideoMode(1600, 900), "Larry's Challenge", Style::Close);
	listaEntidades = new ListaEntidades(window);
	window->setFramerateLimit(60);
	window->setMouseCursorVisible(false);
	//listaEntidades->adicionar_entidade(100, 100);

	jogador = new Jogador(window, 100, 100, 1);
	zumbi = new Zumbi(window, 200, 200, 1);
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
		jogador->existir();
		zumbi->setCoodenadasJogador(jogador->getCoordenadas().x, jogador->getCoordenadas().y);
		zumbi->existir();
		window->display();

	}
}