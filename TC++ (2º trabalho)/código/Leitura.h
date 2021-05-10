#ifndef LEITURA_H_
#define LEITURA_H_

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <list>
#include "Partido.h"

using namespace std;

class Leitura {
    public:

    Leitura();

    /*LEITURA DO ARQUIVO DE PARTIDOS
    INPUTs: string indicando o path do arquivo e a referencia para um arquivo de partidos: -
    Pré-condição: o vector de partidos deve existir
    Pós-condição: o vector de partidos preenchido
    */
    const vector <Partido>& leituraPartidos(string &path, vector <Partido>& partidos);

    /*LEITURA DO ARQUIVO DE CANDIDATOS
    INPUTs: string indicando o path do arquivo e a referencia para um arquivo de candidatos: -
    Pré-condição: o vector de candidatos deve existir
    Pós-condição: o vector de candidatos preenchido
    */
    const vector <Candidato>& leituraCandidatos(string &path, vector<Partido>& partidos, vector <Candidato> &candidatos);
};

#endif