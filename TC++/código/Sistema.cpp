#include "Sistema.h"
#include <cstdio>
#include <cstring>
#include <algorithm>
#include "NumberUtils.h"

// Construtores

Sistema::Sistema() {};

// Métodos

const double Sistema::retornaNumeroDeVagas(vector<Candidato> &candidatos) const{
    double cont = 0;

    vector<Candidato>::iterator ite;
    for (ite = candidatos.begin(); ite != candidatos.end(); ite++) {

        if (ite->getSituacao() == "Eleito"){
            cont++;
        }
    }
    return cont;
}

const vector<Candidato> Sistema::retornaCandidatosEleitos(vector<Candidato> &candidatos) const{
    vector<Candidato> candidatosEleitos;
    vector<Candidato>::iterator ite;
    for (ite = candidatos.begin(); ite != candidatos.end(); ite++) {
        
        if (ite->getSituacao() == "Eleito"){
            candidatosEleitos.push_back(*ite);
        }
    }
    return candidatosEleitos;
}

const double Sistema::retornaQtdEleitosSexoFeminino(vector<Candidato> &candidatosEleitos) const{
    double qtd = 0;
    
    vector<Candidato>::iterator ite;
    for (ite = candidatosEleitos.begin(); ite != candidatosEleitos.end(); ite++) {
        
        if (ite->getSexo() == "F"){
            qtd++;
        }
    }
    return qtd;
}

const int Sistema::retornaQtdCandidatosEleitosPartido(vector<Candidato> &candidatosEleitos, int &numPartido) const{
    int qtd = 0;

    for (std::vector<Candidato>::size_type i=0; i < candidatosEleitos.size(); i++){
        if(candidatosEleitos[i].getNumeroPartido() == numPartido){
            qtd++;
        }
    }
    return qtd;
}

const Partido Sistema::retornaPartidoPeloNumero(vector<Partido> &partidos, const int &numeroPartido) const{
    Partido partido;
    
    vector<Partido>::iterator ite;
    for (ite = partidos.begin(); ite != partidos.end(); ite++) {
        
        if (ite->getNumeroPartido() == numeroPartido){
            partido = (*ite);
            return partido;
        }
    }
    return partido;
}

const Candidato Sistema::retornaCandidatoPeloNumero(vector<Candidato> &candidatos, int &numeroCandidato) const{
    Candidato candidato;

    vector<Candidato>::iterator ite;
    for (ite = candidatos.begin(); ite != candidatos.end(); ite++) {
        // cout << ite->getSituacao() << endl;
        if (ite->getNumero() == numeroCandidato){
            candidato = (*ite);
            return candidato;
        }
    }
    return candidato;    
}

const double Sistema::retornaTotalVotosValidos(vector<Candidato> &candidatos, vector<Partido> &partidos) const{
    double total = 0, nominais = 0, legenda = 0;
    vector<Candidato>::iterator itc;
    for (itc = candidatos.begin(); itc != candidatos.end(); itc++) {
        if (itc->getDestinoVoto() == "Válido"){
            nominais += itc->getVotosNominais();
        }
    }
    vector<Partido>::iterator itp;
    for (itp = partidos.begin(); itp != partidos.end(); itp++) {
        legenda += itp->getVotosLegenda();
    }
    total = nominais + legenda;
    return total;
}

const double Sistema::retornaTotalVotosNominais(const vector<Candidato> &candidatos) const{
    double total = 0;
    vector<Candidato>::iterator itc;

    for (std::vector<Candidato>::size_type i=0; i<candidatos.size();i++) {
        if (candidatos[i].getDestinoVoto() == "Válido"){
            total += candidatos[i].getVotosNominais();
        }
    }
    return total;
}

const double Sistema::retornaTotalVotosLegenda(const vector<Partido> &partidos) const{
    double total = 0;

    for(std::vector<Partido>::size_type i=0; i < partidos.size(); i++){
        total+= partidos[i].getVotosLegenda();
    }
    return total;
}

const vector<Candidato> Sistema::retornaArrayCandidatosMaisVotadosNaoEleitos(vector<Candidato> candidatos) const{
    vector<Candidato> candidatosMaisVotadosNaoEleitos;

    for(std::vector<Candidato>::size_type i=0; i < candidatos.size(); i++){
        if(candidatos[i].getSituacao() == "Eleito"){
            continue;
        }else{
            candidatosMaisVotadosNaoEleitos.push_back(candidatos[i]);
        }
    }
    return candidatosMaisVotadosNaoEleitos;
}

const vector<Candidato> Sistema::retornaArrayBeneficiadosProp(vector<Candidato> candidatosEleitos, vector<Candidato> candidatosMaisVotados) const{
    vector<Candidato> candidatosBeneficiados;
    for(std::vector<Candidato>::size_type j=0; j < candidatosEleitos.size(); j++){
        if(find(candidatosMaisVotados.begin(), candidatosMaisVotados.end(), candidatosEleitos[j])!= candidatosMaisVotados.end()){
            continue;
        }else{
            candidatosBeneficiados.push_back(candidatosEleitos[j]);
        }
    }    
    return candidatosBeneficiados;
}

const void Sistema::imprimeNumeroVagas(int numeroVagas) const{
    cout << "Número de vagas: " << numeroVagas << endl << endl;
}

const void Sistema::imprimeVereadoresEleitos(vector<Candidato> &candidatosEleitos, vector<Partido> &partidos) const{
    cout << "Vereadores eleitos:" << endl;

    for (std::vector<Candidato>::size_type i=0; i<candidatosEleitos.size(); i++) {
        int numeroPartido = candidatosEleitos[i].getNumeroPartido();
        Partido p = retornaPartidoPeloNumero(partidos, numeroPartido);

        cout << i+1 << " - " << candidatosEleitos[i].getNome() << " / " << candidatosEleitos[i].getNomeUrna() << " (" << p.getSiglaPartido() << ", " << candidatosEleitos[i].getVotosNominais() << " voto";
        if(candidatosEleitos[i].getVotosNominais() > 1){
            cout << "s";
        }
        cout << ")" << endl;
    }
    cout << endl;
}

const void Sistema::imprimeCandidatosMaisVotados(const vector<Candidato>&candidatosMaisVotados, vector<Partido> &partidos) {
    cout << "Candidatos mais votados (em ordem decrescente de votação e respeitando número de vagas):" << endl;

    for (std::vector<Candidato>::size_type i=0; i<candidatosMaisVotados.size(); i++) {
        int numeroPartido = candidatosMaisVotados[i].getNumeroPartido();
        Partido p = retornaPartidoPeloNumero(partidos, numeroPartido);

        cout << i+1 << " - " << candidatosMaisVotados[i].getNome() << " / " << candidatosMaisVotados[i].getNomeUrna() << " (" << p.getSiglaPartido() << ", " << candidatosMaisVotados[i].getVotosNominais() << " voto";
        if(candidatosMaisVotados[i].getVotosNominais() > 1){
            cout << "s";
        }
        cout << ")" << endl;
    }
    cout << endl;
}

const void Sistema::imprimeCandidatosEleitosMaj(const vector<Candidato>& candidatosEleitosSeMaj, vector<Candidato>& candidatosMaisVotados, vector<Partido>& partidos){
    cout << "Teriam sido eleitos se a votação fosse majoritária, e não foram eleitos:\n(com sua posição no ranking de mais votados)" << endl;

    for (std::vector<Candidato>::size_type i=0; i<candidatosEleitosSeMaj.size(); i++) {
        int numeroPartido = candidatosEleitosSeMaj[i].getNumeroPartido();
        int numeroCandidato = candidatosEleitosSeMaj[i].getNumero();
        Partido p = retornaPartidoPeloNumero(partidos, numeroPartido);
        Candidato c = retornaCandidatoPeloNumero(candidatosMaisVotados, numeroCandidato);

        cout << c.getPos() << " - " << candidatosEleitosSeMaj[i].getNome() << " / " << candidatosEleitosSeMaj[i].getNomeUrna() << " (" << p.getSiglaPartido() << ", " << candidatosEleitosSeMaj[i].getVotosNominais() << " voto";
        if(candidatosEleitosSeMaj[i].getVotosNominais() > 1){
            cout << "s";
        }
        cout << ")" << endl;
    }
    cout << endl;
}

const void Sistema::imprimeCandidatosEleitosBeneficiadosProp(const vector<Candidato>&candidatosEleitosBeneficiadosProp,const vector<Candidato>& candidatosMaisVotados,vector<Partido>& partidos) const{
    cout << "Eleitos, que se beneficiaram do sistema proporcional:\n(com sua posição no ranking de mais votados)" << endl;

    for(std::vector<Candidato>::size_type i=0; i < candidatosEleitosBeneficiadosProp.size(); i++){
        int numeroPartido = candidatosEleitosBeneficiadosProp[i].getNumeroPartido();
        Partido p = retornaPartidoPeloNumero(partidos, numeroPartido);
        cout << candidatosEleitosBeneficiadosProp[i].getPos() << " - " << candidatosEleitosBeneficiadosProp[i].getNome() << " / " << candidatosEleitosBeneficiadosProp[i].getNomeUrna() << " (" << p.getSiglaPartido() << ", " << candidatosEleitosBeneficiadosProp[i].getVotosNominais() << " voto";
        if(candidatosEleitosBeneficiadosProp[i].getVotosNominais() > 1){
            cout << "s";
        }
        cout << ")" << endl;
    }
    cout << endl;
}

const void Sistema::imprimeVotacaoPartidos (vector<Candidato>& candidatosEleitos, const vector<Partido>& partidos){
    cout << "Votação dos partidos e número de candidatos eleitos:" << endl;
    
    for (std::vector<Partido>::size_type i=0; i < partidos.size(); i++){
        cout << (i+1) << " - " << partidos[i];
        int numeroPartido = partidos[i].getNumeroPartido();
        if(retornaQtdCandidatosEleitosPartido(candidatosEleitos, numeroPartido) >= 2 ){
            cout << retornaQtdCandidatosEleitosPartido(candidatosEleitos,numeroPartido) << " candidatos eleitos" << endl;
        } else {
            cout << retornaQtdCandidatosEleitosPartido(candidatosEleitos,numeroPartido) << " candidato eleito" << endl;
        }
    }
    cout << endl;   
}

const void Sistema::imprimePrimeiroUltimoPartido (const vector<Candidato>& candidatoMaisVotado,vector<Partido>& partidos,const string& dataEleicao) const{
    Candidato candidatoMenosVotado;
    Partido partidoAtual;
    int indice = 1;
    cout << "Primeiro e último colocados de cada partido:" << endl;
    for(std::vector<Candidato>::size_type i=0; i < candidatoMaisVotado.size(); i++){
        string str = candidatoMaisVotado[i].getNome();
        if(str.empty())continue;
        int num = candidatoMaisVotado[i].getNumeroPartido();
        partidoAtual = retornaPartidoPeloNumero(partidos,num);
        candidatoMenosVotado = partidoAtual.retornaCandidatoMenosVotadoPartido(dataEleicao);
        
        if(partidoAtual.getVotosTotais() != 0){

            if(candidatoMaisVotado[i].getVotosNominais() >= 2){
                cout << indice << " - " << partidoAtual.getSiglaPartido() << " - " << partidoAtual.getNumeroPartido() << ", " << candidatoMaisVotado[i].getNomeUrna() << " (" << candidatoMaisVotado[i].getNumero() << ", " << candidatoMaisVotado[i].getVotosNominais() << " votos) / ";
            }else{
                cout << indice << " - " << partidoAtual.getSiglaPartido() << " - " << partidoAtual.getNumeroPartido() << ", " << candidatoMaisVotado[i].getNomeUrna() << " (" << candidatoMaisVotado[i].getNumero() << ", " << candidatoMaisVotado[i].getVotosNominais() << " voto) / ";
            }
            
            if(candidatoMenosVotado.getVotosNominais() >= 2){
                
                cout << candidatoMenosVotado.getNomeUrna() << " (" << candidatoMenosVotado.getNumero() << ", " << candidatoMenosVotado.getVotosNominais() << " votos)" << endl;
            }else{
                cout << candidatoMenosVotado.getNomeUrna() << " (" << candidatoMenosVotado.getNumero() << ", " << candidatoMenosVotado.getVotosNominais() << " voto)" << endl;
            }
        }
        indice++;
    }
    cout << endl;
}

const void Sistema::imprimeEleitosFaixaEtaria (const vector<Candidato>& candidatosEleitos, double numeroVagas,const string& data) const{
    cout << "Eleitos, por faixa etária (na data da eleição):" << endl;
    vector<int> idades;
    // int idades[] = new int[(int)numeroVagas];

    int contMenor30 = 0, cont30Menor40 = 0, cont40Menor50 = 0, cont50Menor60 = 0, contMaior60 =0;

    for(std::vector<Candidato>::size_type i=0; i< candidatosEleitos.size(); i++){
        idades.push_back(candidatosEleitos[i].retornaIdadeCandidato(data));
    }

    for(std::vector<int>::size_type i=0; i < idades.size();i++){
        if(idades[i] < 30){
            contMenor30++;
        }else if(idades[i] >=30 && idades[i] < 40){
            cont30Menor40++;
        }else if(idades[i] >= 40 && idades[i] < 50){
            cont40Menor50++;
        }else if(idades[i] >= 50 && idades[i] < 60){
            cont50Menor60++;
        }else{
            contMaior60++;
        }
    }

    double porcentagem = (float)contMenor30/(float)numeroVagas*100;

    cout << fixed;
    cout.precision(2);
    cout << "      Idade < 30: " << contMenor30;
    cout << " (" << formatDoubleCurrency(porcentagem, LOCALE_PT_BR) << "%" << ")" << endl;

    porcentagem = (float)cont30Menor40/(float)numeroVagas*100;
    cout << "30 <= Idade < 40: " << cont30Menor40;
    cout << " (" << formatDoubleCurrency(porcentagem, LOCALE_PT_BR) << "%" << ")" << endl;

    porcentagem = (float)cont40Menor50/(float)numeroVagas*100;
    cout << "40 <= Idade < 50: " << cont40Menor50;
    cout << " (" << formatDoubleCurrency(porcentagem, LOCALE_PT_BR) << "%" <<")" << endl;

    porcentagem = (float)cont50Menor60/(float)numeroVagas*100;
    cout << "50 <= Idade < 60: " << cont50Menor60;
    cout << " (" << formatDoubleCurrency(porcentagem, LOCALE_PT_BR) << "%" << ")" << endl;

    porcentagem = (float)contMaior60/(float)numeroVagas*100;
    cout << "60 <= Idade     : " << contMaior60;
    cout << " (" << formatDoubleCurrency(porcentagem, LOCALE_PT_BR) << "%" << ")" << endl << endl;
}

const void Sistema::imprimeEleitosPorSexo (double numeroVagas, double qtdF, double porcentagemF, double porcentagemM) const{
    cout << "Eleitos, por sexo:" << endl;
    cout << fixed;
    cout.precision(0);
    cout << "Feminino:  " << qtdF;
    cout.precision(2);
    cout << " (" << formatDoubleCurrency(porcentagemF, LOCALE_PT_BR) << "%" << ")" << endl;
    cout.precision(0);
    cout << "Masculino: " << (numeroVagas-qtdF);
    cout << " (" << formatDoubleCurrency(porcentagemM, LOCALE_PT_BR) << "%" << ")" << endl << endl;
}

const void Sistema::imprimeTotal (double totalVotosValidos, double totalVotosNominais, double totalVotosLegenda, double porcentagemVN, double porcentagemVL) const{
    cout << fixed;
    cout.precision(0);
    cout << "Total de votos válidos:    " << totalVotosValidos << endl;
    cout << "Total de votos nominais:   " << totalVotosNominais;
    cout << " (" << formatDoubleCurrency(porcentagemVN, LOCALE_PT_BR) << "%" << ")" << endl;
    cout.precision(0);
    cout << "Total de votos de Legenda: " << totalVotosLegenda;
    cout << " (" << formatDoubleCurrency(porcentagemVL, LOCALE_PT_BR) << "%" << ")" << endl << endl;
}

const int Sistema::retornaPosPartido(const vector<Partido>& partidos, int numPartido) const{
    int i = 0;
    for(std::vector<Partido>::size_type i=0; i<partidos.size(); i++){
        if(partidos[i].getNumeroPartido() == numPartido){
            return i;
        }
    }
    return i;
}

const vector<Candidato>& Sistema::retornaVectorCandidatosMaisVotadosDoPartido( vector<Candidato>& candidatoMaisVotado, vector<Partido>& partidos){
    
    for(std::vector<Partido>::size_type i=0; i < partidos.size(); i++){
        candidatoMaisVotado.push_back(partidos[i].retornaCandidatoMaisVotadoPartido());
        candidatoMaisVotado[i].setFlagCompare(1);
    }
    return candidatoMaisVotado;
}