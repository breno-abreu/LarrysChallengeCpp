#include "LarrysChallenge.h"

LarrysChallenge::LarrysChallenge():
	comprimentoTela(1600),
	alturaTela(900)
{
	window = new RenderWindow(VideoMode(1600, 900), "Larry's Challenge", Style::Close | Style::Resize);
	window->setFramerateLimit(60);
	opmenu = true;
	menu = new Menu(window);
	fase = new Fase(window);
	gerenciadorPersistencia = new GerenciadorPersistencia();
	view = new View(Vector2f(0, 0), Vector2f(1600, 900));
	executar();
}
LarrysChallenge::~LarrysChallenge()
{
	delete window;
	delete view;
	delete gerenciadorPersistencia;
	delete fase;
	delete menu;
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
			case Event::Resized:
				view->setSize((float)evnt.size.width, (float)evnt.size.height);
				break;
			}
		}
		window->clear(Color(50, 90, 80, 255));
		window->setView(*view);

		if (!opmenu) {
			fase->executar();
			view->setCenter(fase->getCoordenadasJogador());
			if (!fase->getJogadorVivo())
				opmenu = true;
		}
		else {
			view->setCenter(0, 0);
			opcao = menu->executar();

			if (opcao == INICIARJOGO) {
				opmenu = false;
				fase = gerenciadorPersistencia->carregar(menu->getFase(), window);
				menu->resetOpcaoSelecionada();
			}

			else if (opcao == SAIR)
				window->close();
		}

		if (Keyboard::isKeyPressed(Keyboard::Key::Escape))
			opmenu = true;

		window->display();
	}
}