#include "LarrysChallenge.h"

LarrysChallenge::LarrysChallenge()
{
	window = new RenderWindow(VideoMode(1600, 900), "Larry's Challenge", Style::Close);
	listaEntidades = new ListaEntidades(window);
	window->setFramerateLimit(60);
	window->setMouseCursorVisible(false);
	listaEntidades->adicionar_entidade(100, 100);
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
		listaEntidades->percorrer();
		window->display();

	}
}