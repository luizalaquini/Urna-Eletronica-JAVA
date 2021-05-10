#include "Candidato.h"
#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

// Construtores

Candidato::Candidato() {};

Candidato::Candidato(int numero, int votosNominais, const string &situacao,const string& nome, const string& nomeUrna,const string& sexo,const string &dataNasc,const string&destinoVoto, int numeroPartido, int pos) {
    this->numero = numero;
    this->votosNominais = votosNominais;
    this->situacao = situacao;
    this->nome = nome;
    this->nomeUrna = nomeUrna;
    this->sexo = sexo;
    this->dataNasc = dataNasc;
    this->destinoVoto = destinoVoto;
    this->numeroPartido = numeroPartido;
    this->pos = pos;
    this->flagCompare = 0;
};

// GETs & SETs

void Candidato::setNumero(int numero){
    this->numero = numero;
}
const int Candidato::getNumero() const{
    return this->numero;
}

void Candidato::setVotosNominais(int votosNominais){
    this->votosNominais = votosNominais;
}
const int Candidato::getVotosNominais() const{
    return this->votosNominais;
}   

void Candidato::setSituacao(const string& situacao){
    this->situacao = situacao;
}
const string& Candidato::getSituacao() const{
    return this->situacao;
}   

void Candidato::setNome(const string& nome){
    this->nome = nome;
}
const string& Candidato::getNome() const{
    return this->nome;
}

void Candidato::setNomeUrna(const string& nome){
    this->nomeUrna = nome;
}
const string& Candidato::getNomeUrna() const{
    return this->nomeUrna;
}

void Candidato::setSexo(const string& sexo){
    this->sexo = sexo;
}
const string& Candidato::getSexo() const{
    return this->sexo;
}

void Candidato::setDataNasc(const string& data){
    this->dataNasc = data;
}
const string& Candidato::getDataNasc() const{
    return this->dataNasc;
}

void Candidato::setDestinoVoto(const string& destinoVoto){
    this->destinoVoto = destinoVoto;
}
const string& Candidato::getDestinoVoto() const{
    return this->destinoVoto;
}

void Candidato::setNumeroPartido(int numeroPartido){
    this->numeroPartido = numeroPartido;
}
const int Candidato::getNumeroPartido() const{
    return this->numeroPartido;
}

void Candidato::setPos(int pos){
    this->pos = pos;
}
const int Candidato::getPos() const{
    return this->pos;
}

void Candidato::setFlagCompare(int flagCompare){
    this->flagCompare = flagCompare;
}
const int Candidato::getFlagCompare() const{
    return this->flagCompare;
}

// Métodos

const bool Candidato::operator==(const Candidato& c1) const{
    if(this->getNome() == c1.getNome()){
        return true;
    }else {
        return false;
    }
}

const int Candidato::retornaIdadeCandidato(const string& dataEleicao) const{
    vector<string> dataEleicaoSeparada;

    // variável de trabalho
    string token;

    //Lendo linha por linha.
    // stream de strings de input inicializado com a string a ser separada
    istringstream tokenizer { dataEleicao };

    //separando a linha lida pelas vírgulas.
    while (getline(tokenizer, token, '/'))
        dataEleicaoSeparada.push_back(token);


    vector<string> dataNascSeparada;
    string dataNasc = this->getDataNasc();
    // variável de trabalho
    string token2;

    //Lendo linha por linha.
    // stream de strings de input inicializado com a string a ser separada
    istringstream tokenizer2 { dataNasc };

    //separando a linha lida pelas vírgulas.
    while (getline(tokenizer2, token2, '/'))
        dataNascSeparada.push_back(token2);

    int idade = 0;
    int diaEleicao = 0, diaNasc = 0;
    int MesEleicao = 0, MesNasc = 0;
    int AnoEleicao = 0, AnoNasc = 0;
    diaEleicao = stoi(dataEleicaoSeparada[0]);
    MesEleicao = stoi(dataEleicaoSeparada[1]);
    AnoEleicao = stoi(dataEleicaoSeparada[2]);
    diaNasc = stoi(dataNascSeparada[0]);
    MesNasc = stoi(dataNascSeparada[1]);
    AnoNasc = stoi(dataNascSeparada[2]);
    
    if( MesNasc < MesEleicao){
        idade = AnoEleicao - AnoNasc;
    }else if(MesNasc == MesEleicao){
        if(diaNasc <= diaEleicao){
            idade = AnoEleicao - AnoNasc;
        }else{
            idade = (AnoEleicao - AnoNasc) - 1;
        }
    }else if(MesNasc > MesEleicao){
        idade = (AnoEleicao - AnoNasc) - 1;
    }
    return idade;
}

bool Candidato::compareVotosNominais(const Candidato& c1,const Candidato& c2) {
    if(c1.getVotosNominais() > c2.getVotosNominais()){
        return true;
    }else if(c1.getVotosNominais() < c2.getVotosNominais()){
        return false;
    }else{
        if(c2.getFlagCompare() == 1){
            if(c1.getNumeroPartido() < c2.getNumeroPartido()){
                return true;
            }else{
                return false;
            }
        }else{
            if(stoi(c1.getDataNasc().substr(6,4)) > stoi(c2.getDataNasc().substr(6,4))){
                return false;
            }
            else if(stoi(c1.getDataNasc().substr(6,4)) == stoi(c2.getDataNasc().substr(6,4))){
                if(stoi(c1.getDataNasc().substr(3,2)) > stoi(c2.getDataNasc().substr(3,2))){
                    return false;
                }else if(stoi(c1.getDataNasc().substr(3,2)) == stoi(c2.getDataNasc().substr(3,2))){
                    if((stoi(c2.getDataNasc().substr(0,2)) > stoi(c2.getDataNasc().substr(0,2)))){
                        return false;
                    }else{
                        return true;
                    }
                }else{
                    return true;
                }
            }else{
                return true;
            }
        }
    }
}