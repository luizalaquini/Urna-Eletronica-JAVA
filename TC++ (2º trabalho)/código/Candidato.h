#ifndef CANDIDATO_H_
#define CANDIDATO_H_

#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

class Candidato {
    private:
    int numero; // Número do candidato na urna
    int votosNominais; // Total de votos nominais do candidato
    string situacao; // (Eleito / Não Eleito / Suplente)
    string nome; // Nome completo do candidato 
    string nomeUrna; // Nome do candidato como mostrado na urna eletrônica
    string sexo; // (F / M)
    string dataNasc; // Data de nascimento do candidato no formato dd/mm/aaaa
    string destinoVoto; // (Válido / Anulado / Anulado sub Justice)
    int numeroPartido; // Número do partido do candidato
    int pos; // Posição
    int flagCompare = 0; // Flag de comparação

    public:

    // Construtores
    Candidato();
    
    Candidato(int numero, int votosNominais, const string &situacao,const string& nome, const string& nomeUrna,const string& sexo,const string &dataNasc,const string&destinoVoto, int numeroPartido, int pos);

    // GETs & SETs
    void setNumero(const int numero);
    const int getNumero() const;

    void setVotosNominais(const int votosNominais);
    const int getVotosNominais() const;   

    void setSituacao(const string& situacao);
    const string& getSituacao() const;   

    void setNome(const string& nome);
    const string& getNome() const;   

    void setNomeUrna(const string& nome);
    const string& getNomeUrna() const;

    void setSexo(const string& sexo);
    const string& getSexo() const;

    void setDataNasc(const string& data);
    const string& getDataNasc() const;

    void setDestinoVoto(const string& destinoVoto);
    const string& getDestinoVoto() const;

    void setNumeroPartido(const int numeroPartido);
    const int getNumeroPartido() const;

    void setPos(const int pos);
    const int getPos() const;

    void setFlagCompare(const int flagCompare);
    const int getFlagCompare() const;

    //Métodos
    const int retornaIdadeCandidato(const string& dataEleicao) const;

    static bool compareVotosNominais(const Candidato& c1, const Candidato& c2);

    const bool operator==(const Candidato& c1) const;

    friend ostream& operator<< (ostream &out, const Candidato &c1);
};

#endif