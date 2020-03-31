#pragma once

#include <iostream>
#include <string>
//Biblioteca gráfica do SFML
#include <SFML/Graphics.hpp>
#include <list>
#include <fstream>
#include <math.h>
#include <filesystem>
#include <cstdio>
#include <windows.h>

enum {
	DIREITA,
	ESQUERDA,
	CIMA,
	BAIXO,
	BLUEORB,
	REDORB,
	GREENORB,
	CHAVE,
	MOEDA,
	HORIZONTAL,
	VERTICALDIREITA,
	VERTICALESQUERDA,
	PESADA,
	LEVE,
	INICIARJOGO,
	SAIR
};

using namespace std;
//SFML utiliza o namespace 'sf' para seus métodos
using namespace sf;
