#include "LarrysChallenge.h"

LarrysChallenge::LarrysChallenge():
	comprimentoTela(1600),
	alturaTela(900)
{
	window = new RenderWindow(VideoMode(1600, 900), "Larry's Challenge", Style::Close | Style::Resize);
	
	window->setFramerateLimit(60);
	//window->setMouseCursorVisible(false);
	//listaEntidades->adicionar_entidade(100, 100);
	aux = true;
	
	/*gerenciadorEntidades = new GerenciadorEntidades(window, listaLetais, listaBarreiras, listaInterativos,
													listaSuperficiesInterativas, listaCaixas, listaFlechas,
													listaInimigos, listaPersonagens, listaItens);*/


	fase = new Fase(window);
	gerenciadorPersistencia = new GerenciadorPersistencia();
	//listaEntidades = new ListaEntidades(window, gerenciadorEntidades);

	/*listaEntidades->adicionar_entidade(100, 100, 54);
	listaEntidades->adicionar_entidade(200, 100, 55);
	listaEntidades->adicionar_entidade(300, 100, 56);
	listaEntidades->adicionar_entidade(400, 100, 57);
	listaEntidades->adicionar_entidade(500, 100, 58);*/

	view = new View(Vector2f(0, 0), Vector2f(1600, 900));


	executar();

}
LarrysChallenge::~LarrysChallenge()
{
	delete window;
	delete listaEntidades;
	delete view;
}
void LarrysChallenge::executar()
{
	string arquivo;
	bool done = false;
	while (!done) {
		system("cls");
		gerenciadorPersistencia->listar_arquivos();
		cout << endl;
		cin >> arquivo;
		if (gerenciadorPersistencia->pesquisar_lista_arquivos(arquivo)) {
			fase = gerenciadorPersistencia->carregar(arquivo, window);
			done = true;
		}
		else
			cout << "Arquivo não existente!\nEscolha outro arquivo:" << endl;
	}
	
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
		fase->executar();
		view->setCenter(fase->getCoordenadasJogador());
		window->display();

		if (!fase->getJogadorVivo()) {

			
			system("cls");
			string opcao;
			cout << "Voce perdeu!\nO Que deseja fazer?" << endl;
			cin >> opcao;

			done = false;

			if (opcao == "Recomecar" || opcao == "recomecar" || opcao == "r")
				fase = gerenciadorPersistencia->carregar(arquivo, window);

			
			else if (opcao == "mudarfase") {

				while (!done) {
					system("cls");
					gerenciadorPersistencia->listar_arquivos();
					cout << endl;
					cin >> arquivo;
					if (gerenciadorPersistencia->pesquisar_lista_arquivos(arquivo)) {
						fase = gerenciadorPersistencia->carregar(arquivo, window);
						done = true;
					}
					else
						cout << "Arquivo não existente!" << endl;
				}
			}
			
		}
		

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

		/*if (jogador->getCoordenadas().x < botao->getCoordenadas().x + botao->getDimensoes().x &&
			jogador->getCoordenadas().x + jogador->getDimensoes().x > botao->getCoordenadas().x&&
			jogador->getCoordenadas().y < botao->getCoordenadas().y + botao->getDimensoes().y &&
			jogador->getCoordenadas().y + jogador->getDimensoes().y > botao->getCoordenadas().y) {
			
			botao->setExiste(true);
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
				aux2 = true;
			}

			else if (jogador->getAcao() && !interruptor->getAtivado()) {
				interruptor->setAtivado(true);
				aux2 = true;
			}
		}

		if (jogador->getCoordenadas().x < bau->getCoordenadas().x + bau->getDimensoes().x &&
			jogador->getCoordenadas().x + jogador->getDimensoes().x > bau->getCoordenadas().x&&
			jogador->getCoordenadas().y < bau->getCoordenadas().y + bau->getDimensoes().y &&
			jogador->getCoordenadas().y + jogador->getDimensoes().y > bau->getCoordenadas().y) {

			if (jogador->getCoordenadas().x < bau->getCoordenadas().x + bau->getDimensoes().x &&
				jogador->getCoordenadas().x + jogador->getDimensoes().x > bau->getCoordenadas().x + bau->getDimensoes().x)
				jogador->setxEntidade(jogador->getCoordenadas().x + jogador->getVelocidade());
			if (jogador->getCoordenadas().x + jogador->getDimensoes().x > bau->getCoordenadas().x &&
				jogador->getCoordenadas().x < bau->getCoordenadas().x + bau->getDimensoes().x)
				jogador->setxEntidade(jogador->getCoordenadas().x - jogador->getVelocidade());
			if (jogador->getCoordenadas().y < bau->getCoordenadas().y + bau->getDimensoes().y &&
				jogador->getCoordenadas().y + jogador->getDimensoes().y > bau->getCoordenadas().y + bau->getDimensoes().y)
				jogador->setyEntidade(jogador->getCoordenadas().y + jogador->getVelocidade());
			if (jogador->getCoordenadas().y + jogador->getDimensoes().y > bau->getCoordenadas().y &&
				jogador->getCoordenadas().y < bau->getCoordenadas().y + bau->getDimensoes().y)
				jogador->setyEntidade(jogador->getCoordenadas().y - jogador->getVelocidade());

			if (jogador->getDirecao() == DIREITA)
				jogador->setxEntidade(jogador->getCoordenadas().x - jogador->getVelocidade());
			else if (jogador->getDirecao() == ESQUERDA)
				jogador->setxEntidade(jogador->getCoordenadas().x + jogador->getVelocidade());
			else if (jogador->getDirecao() == CIMA)
				jogador->setyEntidade(jogador->getCoordenadas().y + jogador->getVelocidade());
			else if (jogador->getDirecao() == BAIXO)
				jogador->setyEntidade(jogador->getCoordenadas().y - jogador->getVelocidade());



			if (jogador->getAcao() && !bau->getAtivado()) {
				bau->setAtivado(true);
			}
		}*/

		//cout << jogador->getCoordenadas().x << "     " << movimentador->getCoordenadas().x + movimentador->getDimensoes().x << "    " << 
			//jogador->getCoordenadas().x + jogador->getDimensoes().x << "   " << movimentador->getCoordenadas().x << endl;

		


		//zumbi->setCoodenadasJogador(jogador->getCoordenadas().x, jogador->getCoordenadas().y);
		//zumbi->existir();
		

	}
}