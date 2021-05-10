#ifndef PARTIDO_H_
#define PARTIDO_H_

#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include "Candidato.h"

using namespace std;

class Partido {
    private:
    int numeroPartido; // Número do partido;
    int votosLegenda; // Total de votos de legenda do partido;
    string nomePartido; // Nome do partido;
    string siglaPartido; // Sigla do partido;
    vector <Candidato> candidatosPartido; // Lista de candidados pertencentes ao partido
    int votosNomimaisTotaisPartido;
    int pos; // Posição

    public:

    //Construtores
    Partido();

    Partido(int numeroPartido, int votosLegenda, const string& nomePartido,const string& siglaPartido,const vector<Candidato>& candidadosPartido);

    //GETs & SETs
    void setNumeroPartido(const int numero);
    const int getNumeroPartido() const;

    void setVotosLegenda(const int votosLegenda);
    const int getVotosLegenda() const;   

    void setVotosNominaisTotal(const int votos);
    const int getVotosNominaisTotal() const;

    void setNomePartido(const string &nome);
    const string& getNomePartido() const;   

    void setSiglaPartido(const string &sigla);
    const string& getSiglaPartido() const;   

    void setNomeUrna(const string &nome);
    const string& getNomeUrna();

    void setNovoCandidatoPartido(const Candidato &candidato);
    const vector <Candidato>& getCandidatoPartido();

    void setPos(const int pos);
    const int getPos() const;

    //Métodos
    const int getVotosTotais() const;

    const Candidato retornaCandidatoMaisVotadoPartido() const;

    const Candidato retornaCandidatoMenosVotadoPartido(const string& dataEleicao) const;

    const int Candidato1MaisVelho(const Candidato& candidato1, const Candidato& candidato2) const;

    static bool compareVotosTotais(const Partido& p1, const Partido& p2);

    friend ostream& operator<< (ostream &out, const Partido &p1);
};

#endif