#include "Menu.h"

Menu::Menu(RenderWindow* _window)
{
	opcao = INICIARJOGO;
	nfase = 1;
	window = _window;
	fonte.loadFromFile("CompassPro.ttf");

	gerenciadorPersistencia = new GerenciadorPersistencia();

	quantidadeFases = gerenciadorPersistencia->getQuantidadeFases();
	opcaoSelecionada = 0;
	auxDireita = false;
	auxEsquerda = false;

	iniciarJogo.setFont(fonte);
	sair.setFont(fonte);
	fase.setFont(fonte);

	iniciarJogo.setCharacterSize(52);
	sair.setCharacterSize(52);
	fase.setCharacterSize(52);

	iniciarJogo.setFillColor(Color::Yellow);
	sair.setFillColor(Color::White);
	fase.setFillColor(Color::White);

	iniciarJogo.setString("Iniciar Jogo");
	sair.setString("Sair");
	fase.setString("Fase " + to_string(nfase));

	iniciarJogo.setOrigin(Vector2f(iniciarJogo.getGlobalBounds().width / 2, iniciarJogo.getGlobalBounds().height));
	sair.setOrigin(Vector2f(sair.getGlobalBounds().width / 2, sair.getGlobalBounds().height));
	fase.setOrigin(Vector2f(fase.getGlobalBounds().width / 2, fase.getGlobalBounds().height));

	iniciarJogo.setPosition(Vector2f(0, -100));
	sair.setPosition(Vector2f(0, -50));
	fase.setPosition(Vector2f(0, 100));
}

Menu::~Menu()
{
	delete gerenciadorPersistencia;
}

int Menu::executar()
{
	if (Keyboard::isKeyPressed(Keyboard::Key::Up)) {
		iniciarJogo.setFillColor(Color::Yellow);
		sair.setFillColor(Color::White);
		opcao = INICIARJOGO;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Key::Down)) {
		iniciarJogo.setFillColor(Color::White);
		sair.setFillColor(Color::Yellow);
		opcao = SAIR;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Key::Right) && nfase < quantidadeFases && !auxDireita) {
		nfase++;
		auxDireita = true;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Key::Left) && nfase > 1 && !auxEsquerda) {
		nfase--;
		auxEsquerda = true;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Key::Enter)) 
		opcaoSelecionada = opcao;

	if (!Keyboard::isKeyPressed(Keyboard::Key::Right))
		auxDireita = false;

	if (!Keyboard::isKeyPressed(Keyboard::Key::Left))
		auxEsquerda = false;

	fase.setString("Fase " + to_string(nfase));
	window->draw(iniciarJogo);
	window->draw(sair);
	window->draw(fase);

	return opcaoSelecionada;
}

int Menu::getFase()
{
	return nfase;
}

void Menu::resetOpcaoSelecionada()
{
	opcaoSelecionada = 0;
}
