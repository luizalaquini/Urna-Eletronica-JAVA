#include "Partido.h"
#include<cstdio>
#include<cstring>

// Construtores

Partido::Partido() {};

Partido::Partido(int numeroPartido, int votosLegenda, const string& nomePartido,const string& siglaPartido,const vector<Candidato>& candidadosPartido) {
    this->numeroPartido = numeroPartido;
    this->votosLegenda = votosLegenda;
    this->nomePartido = nomePartido;
    this->siglaPartido = siglaPartido;
    this->candidatosPartido = candidatosPartido;
    this->votosNomimaisTotaisPartido = 0;
};

// GETs & SETs

void Partido::setNumeroPartido(const int numero){
    this->numeroPartido = numero;
}
const int Partido::getNumeroPartido() const{
    return this->numeroPartido;
}

void Partido::setVotosLegenda(int votosLegenda){
    this->votosLegenda = votosLegenda;
}
const int Partido::getVotosLegenda() const{
    return this->votosLegenda;
}   

void Partido::setVotosNominaisTotal(int votos){
    this->votosNomimaisTotaisPartido += votos;
}
const int Partido::getVotosNominaisTotal() const{
    return this->votosNomimaisTotaisPartido;
}

void Partido::setNomePartido(const string &nome){
    this->nomePartido = nome;
}
const string& Partido::getNomePartido() const{
    return this->nomePartido;
}   

void Partido::setSiglaPartido(const string &sigla){
    this->siglaPartido = sigla;
}
const string& Partido::getSiglaPartido() const{
    return this->siglaPartido;
}   

void Partido::setNovoCandidatoPartido(const Candidato &candidato){
    this->candidatosPartido.push_back(candidato);
}
const vector <Candidato>& Partido::getCandidatoPartido(){
    return this->candidatosPartido;
}

void Partido::setPos(int pos){
    this->pos = pos;
}
const int Partido::getPos() const{
    return this->pos;
}

// Métodos

const int Partido::getVotosTotais() const{
    int votosNominaisPartido = 0, votosTotais = 0;
    for(std::vector<Candidato>::size_type i=0; i < this->candidatosPartido.size(); i++){
        if(this->candidatosPartido[i].getDestinoVoto() == "Válido"){
            votosNominaisPartido += this->candidatosPartido[i].getVotosNominais();
        }
    }
    votosTotais = votosNominaisPartido + this->getVotosLegenda();
    return votosTotais;
}

const Candidato Partido::retornaCandidatoMaisVotadoPartido() const{
    int maior = 0;
    Candidato candidato;
    for(std::vector<Candidato>::size_type i=0; i < this->candidatosPartido.size();i++){
        if(this->candidatosPartido[i].getVotosNominais() > maior &&  this->candidatosPartido[i].getDestinoVoto() == "Válido"){
            maior = this->candidatosPartido[i].getVotosNominais();
            candidato = this->candidatosPartido[i];
        }else{
            continue;
        }
    }
    return candidato;
}

const Candidato Partido::retornaCandidatoMenosVotadoPartido(const string& dataEleicao) const{
    int menor = 0, aux=0;

    Candidato candidato;

    for(std::vector<Candidato>::size_type i=0; i < this->candidatosPartido.size();i++){
            
        if(aux==0){ //define o primeiro valor para a variavel "menor"
            if(this->candidatosPartido[i].getDestinoVoto() == "Válido" ){
                menor = this->candidatosPartido[i].getVotosNominais();
                candidato = this->candidatosPartido[i];
                aux++;
                continue;
            }
        }
        if(this->candidatosPartido[i].getDestinoVoto() == "Válido"){
            if(this->candidatosPartido[i].getVotosNominais() < menor){
                menor = this->candidatosPartido[i].getVotosNominais();
                candidato = this->candidatosPartido[i];
            }
            else if(this->candidatosPartido[i].getVotosNominais() == menor){
                if(this->candidatosPartido[i].retornaIdadeCandidato(dataEleicao) < candidato.retornaIdadeCandidato(dataEleicao)){
                    candidato = this->candidatosPartido[i];
                }
            }else if(this->candidatosPartido[i].retornaIdadeCandidato(dataEleicao) == candidato.retornaIdadeCandidato(dataEleicao)){
                if(this->Candidato1MaisVelho(this->candidatosPartido[i], candidato) == 1){
                    candidato = this->candidatosPartido[i];
                }
            }
        }
    }
    return candidato;
}

const int Partido::Candidato1MaisVelho(const Candidato& candidato1,const Candidato& candidato2) const{
    //31/05/2001
    if(stoi(candidato1.getDataNasc().substr(6,9)) > stoi(candidato2.getDataNasc().substr(6,9))){
        return 0;
    }else if(stoi(candidato1.getDataNasc().substr(6,9)) == stoi(candidato2.getDataNasc().substr(6,9))){
        if(stoi(candidato1.getDataNasc().substr(3,4)) > stoi(candidato2.getDataNasc().substr(3,4))){
            return 0;
        }else if(stoi(candidato1.getDataNasc().substr(3,4)) == stoi(candidato2.getDataNasc().substr(3,4))){
            if(stoi(candidato1.getDataNasc().substr(0,1)) > stoi(candidato2.getDataNasc().substr(0,1))){
                return 0;
            }
        }
    }
    return 1;
}

ostream& operator<< (ostream &out, const Partido &p1){
    if(p1.getVotosTotais() >= 2){
        if(p1.getVotosTotais() - p1.getVotosLegenda() >= 2){
            return out << p1.siglaPartido << " - " << p1.numeroPartido << ", " << p1.getVotosTotais() << " votos " << "(" << (p1.getVotosTotais() - p1.getVotosLegenda()) << " nominais e " << p1.getVotosLegenda() << " de legenda)" << ", ";
        }else{
            return out << p1.siglaPartido << " - " << p1.numeroPartido << ", " << p1.getVotosTotais() << " votos " << "(" << (p1.getVotosTotais() - p1.getVotosLegenda()) << " nominal e " << p1.getVotosLegenda() << " de legenda)" << ", ";
        }
    }else{
        return out << p1.siglaPartido << " - " << p1.numeroPartido << ", " << p1.getVotosTotais() << " voto " << "(" << (p1.getVotosTotais() - p1.getVotosLegenda()) << " nominal e " << p1.getVotosLegenda() << " de legenda)" << ", ";
    }
}

bool Partido::compareVotosTotais(const Partido& p1, const Partido& p2){
    if(p1.getVotosTotais() > p2.getVotosTotais()){
        return true;
    }else if(p1.getVotosTotais() < p2.getVotosTotais()){
        return false;
    }else{
        return 0;
    }
}