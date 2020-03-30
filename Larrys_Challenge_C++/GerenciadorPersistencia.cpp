#include "GerenciadorPersistencia.h"
GerenciadorPersistencia::GerenciadorPersistencia()
{

}
GerenciadorPersistencia::~GerenciadorPersistencia()
{

}
bool GerenciadorPersistencia::pesquisar_lista_arquivos(const string nomeArquivo)
{
	for (const auto& entry : filesystem::directory_iterator("Fases")) {
		if (entry.path().string() == "Fases\\" + nomeArquivo + ".lcs") {
			return true;
		}
	}
	return false;
}
void GerenciadorPersistencia::listar_arquivos()
{
	for (const auto& entry : filesystem::directory_iterator("Fases")) {
		cout << entry.path().string() << endl;
	}
}
int GerenciadorPersistencia::getQuantidadeFases()
{
	int quantidadeFases = 0;
	for (const auto& entry : filesystem::directory_iterator("Fases")) {
		quantidadeFases++;
	}

	return quantidadeFases;
}
Fase* GerenciadorPersistencia::carregar(const int _nfase, RenderWindow* _window)
{
	int cont = 0;
	string nomeArquivo;

	for (const auto& entry : filesystem::directory_iterator("Fases")) {
		nomeArquivo = entry.path().string();
		cont++;

		if (cont == _nfase)
			break;
	}

	Fase* fase = new Fase(_window);
	ifstream arquivo(nomeArquivo);

	int tipo = 1;
	float xEntidade = 0;
	float yEntidade = 0;
	int conexao = 0;

	if (arquivo.is_open()) {
		while (!arquivo.eof()) {
			arquivo >> tipo >> xEntidade >> yEntidade >> conexao;
			if (arquivo.get() == '\n') {
				fase->adicionar_entidade(xEntidade, yEntidade, tipo, conexao);
			}
		}
		arquivo.close();
	}
	return fase;
}