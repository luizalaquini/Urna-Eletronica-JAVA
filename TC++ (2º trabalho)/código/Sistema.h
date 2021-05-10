#ifndef SISTEMA_H_
#define SISTEMA_H_

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <list>
#include "Leitura.h"
#include <algorithm>

using namespace std;

class Sistema {
    
    public:
    
    Sistema();

    /*RETORNA O NÚMERO DE VAGAS EXISTENTES (= NÚMERO DE ELEITOS)
    INPUTs: Lista de Candidatos
    OUTPUTs: Número de Vagas 
    Pré-condição: Lista de Candidatos deve existir
    Pós-condição: Double para número de vagas existe e é >= 0
    */
    const double retornaNumeroDeVagas(vector<Candidato> &candidatos) const;

    /*RETORNA LISTA DE CANDIDATOS ELEITOS
    INPUTs: Lista de Candidatos
    OUTPUTs: Lista de Candidatos Eleitos
    Pré-condição: Lista de Candidatos deve existir
    Pós-condição: Lista de Candidatos Eleitos existe
    */
    const vector<Candidato> retornaCandidatosEleitos(vector<Candidato> &candidatos) const;

    /*RETORNA O TOTAL DE MULHERES ELEITAS 
    INPUTs: Lista de Candidatos Eleitos
    OUTPUTs: Número de Mulheres eleitas
    Pré-condição: Lista de Candidatos Eleitos deve existir
    Pós-condição: Double para número de Mulheres eleitas existe e é >=0
    */
    const double retornaQtdEleitosSexoFeminino(vector<Candidato> &candidatosEleitos) const;  

    /*RETORNA UM DADO PARTIDO CUJO NUMERO FOI PASSADO COMO CHAVE DE BUSCA
    INPUTs: Array de partidos e um Inteiro com o número do partido a ser encontrado
    OUTPUTs: Partido corresponte ao numero 
    Pré-condição: Array de partidos deve existir e número deve possuir correspondência
    Pós-condição: -
    */
    const Partido retornaPartidoPeloNumero(vector<Partido> &partidos,const int &numeroPartido) const;

    /*RETORNA UM DADO CANDIDATO CUJO NÚMERO FOI PASSADO COMO CHAVE DE BUSCA
    INPUTs: Array de candidatos e um Inteiro com o número do candidato a ser encontrado
    OUTPUTs: Candidato corresponte ao número 
    Pré-condição: Array de candidatos deve existir e número deve possuir correspondência
    Pós-condição: -
    */
    const Candidato retornaCandidatoPeloNumero(vector<Candidato> &candidatos, int &numeroCandidato) const;

    /*RETORNA O TOTAL DE CANDIDATOS ELEITOS POR PARTIDO
    INPUTs: Lista de Candidatos Eleitos e Número do Partido
    OUTPUTs: Quantidade de candidatos eleitos para o dado partido
    Pré-condição: Lista de Candidatos Eleitos e Partido devem existir
    Pós-condição: Inteiro para número de Eleitos do Partido existe e é >=0
    */
    const int retornaQtdCandidatosEleitosPartido(vector<Candidato> &candidatosEleitos, int &numPartido) const;

    /*RETORNA O TOTAL DE VOTOS VALIDOS
    INPUTs: Lista de Candidatos e Lista de Partidos
    OUTPUTs: Quantidade total de votos válidos
    Pré-condição: Lista de Candidatos e Lista de Partidos devem existir
    Pós-condição: Double para total de votos válidos existe e é >=0
    */
    const double retornaTotalVotosValidos(vector<Candidato> &candidatos, vector<Partido> &partidos) const;

    /*RETORNA O TOTAL DE VOTOS NOMINAIS
    INPUTs: Lista de Candidatos
    OUTPUTs: Quantidade total de votos nominais
    Pré-condição: Lista de Candidatos deve existir
    Pós-condição: Double para total de votos nominais existe e é >=0
    */
    const double retornaTotalVotosNominais(const vector<Candidato> &candidatos) const;

    /*RETORNA O TOTAL DE VOTOS DE LEGENDA
    INPUTs: Lista de Partidos
    OUTPUTs: Quantidade total de votos de legenda
    Pré-condição: Lista de Partidos deve existir
    Pós-condição: Double para total de votos de legenda existe e é >=0
    */
    const double retornaTotalVotosLegenda(const vector<Partido> &partidos) const;

    /*RETORNA ARRAY DE CANDIDATOS MAIS VOTADOS NAO ELEITOS
    INPUTs: Array de todos os candidatos
    OUTPUTs: Array de candidatos mais votados, mas que não foram eleitos
    Pré-condição: Array de candidatos deve existir
    Pós-condição: -
    */
    const vector<Candidato> retornaArrayCandidatosMaisVotadosNaoEleitos(vector<Candidato> candidatos) const;

    /*RETORNA ARRAY DE CANDIDATOS BENEFICIADOS PELO SISTEMA PROPORCIONAL DE VOTACAO
    INPUTs: Array de candidatos eleitos e Array de candidatos mais votados
    OUTPUTs: Array de candidatos beneficiados pelo sistema de votação proporcional
    Pré-condição: Array de candidatos deve existir
    Pós-condição: -
    */
    const vector<Candidato> retornaArrayBeneficiadosProp(vector<Candidato> candidatosEleitos, vector<Candidato> candidatosMaisVotados) const;

    /*IMPRIME RELATÓRIO 1
    INPUTs: Número de vagas
    OUTPUTs: -
    Pré-condição: Número de vagas deve existir
    Pós-condição: -
    */
    const void imprimeNumeroVagas(int numeroVagas) const;

    /*IMPRIME RELATÓRIO 2
    INPUTs: Vetor de candidatos eleitos e vetor de partidos
    OUTPUTs: -
    Pré-condição: Vetores devem existir 
    Pós-condição: -
    */
    const void imprimeVereadoresEleitos(vector<Candidato>& candidatosEleitos, vector<Partido>& partidos) const;

    /*IMPRIME RELATÓRIO 3
    INPUTs: Vetor de candidatos mais votados e vetor de partidos
    OUTPUTs: -
    Pré-condição: Vetores devem existir
    Pós-condição: -
    */
    const void imprimeCandidatosMaisVotados(const vector<Candidato>& candidatosMaisVotados,vector<Partido>& partidos);

    /*IMPRIME RELATÓRIO 4
    INPUTs: Vetor de candidatos que seriam eleitos no sistema majoritário, vetor de candidatos mais votados e vetor de partidos
    OUTPUTs: -
    Pré-condição: Vetores devem existir
    Pós-condição: -
    */
    const void imprimeCandidatosEleitosMaj(const vector<Candidato>& candidatosEleitosSeMaj, vector<Candidato>& candidatosMaisVotados, vector<Partido>& partidos);

    /*IMPRIME RELATÓRIO 5
    INPUTs: Vetor de candidatos eleitos no sistema proporcional vigente, vetor de candidatos mais votados e vetor de partidos
    OUTPUTs: -
    Pré-condição: Vetores devem existir
    Pós-condição: -
    */
    const void imprimeCandidatosEleitosBeneficiadosProp(const vector<Candidato>&candidatosEleitosBeneficiadosProp,const vector<Candidato>& candidatosMaisVotados, vector<Partido>& partidos) const;

    /*IMPRIME O RELATÓRIO 6
    INPUTs: Array de Candidatos Eleitos e Array de Partidos
    OUTPUTs: -
    Pré-condição: Arrays devem existir e estarem preenchidos
    Pós-condição: -
    */
    const void imprimeVotacaoPartidos (vector<Candidato>& candidatosEleitos, const vector<Partido>& partidos);

    /*IMPRIME O RELATÓRIO 7
    INPUTs: Array com Candidatos mais votados de cada partido e Array de partidos
    OUTPUTs: -
    Pré-condição: Arrays devem existir e estarem preenchidos
    Pós-condição: -
    */
    const void imprimePrimeiroUltimoPartido (const vector<Candidato>& candidatoMaisVotado, vector<Partido>& partidos,const string& dataEleicao) const;

    /*IMPRIME O RELATÓRIO 8
    INPUTs: Array com Candidatos Eleitos, Número de Vagas e Data da eleição.
    OUTPUTs: -
    Pré-condição: Array deve estar inicializado e preenchido. Número de Vagas deve existir e ser >=0. Data da eleição deve ser válida
    Pós-condição: -
    */
    const void imprimeEleitosFaixaEtaria (const vector<Candidato>& candidatosEleitos, double numeroVagas,const string& data) const;

    /*IMPRIME O RELATÓRIO 9
    INPUTs: Número de Vagas, Quantidade de Eleitos do sexo feminino e Porcentagens (F e M)
    OUTPUTs: -
    Pré-condição: Variáveis devem existir
    Pós-condição: -
    */
    const void imprimeEleitosPorSexo (double numeroVagas, double qtdF, double porcentagemF, double porcentagemM) const;

    /*IMPRIME O RELATÓRIO 10
    INPUTs: Total de Votos Válidos, Nominais e de Legenda e Porcentagens (VN e VL)
    OUTPUTs: -
    Pré-condição: Variáveis devem existir
    Pós-condição: -
    */
    const void imprimeTotal (double totalVotosValidos, double totalVotosNominais, double totalVotosLegenda, double porcentagemVN, double porcentagemVL) const;
    
    /*RETORNA UMA DETERMINADA POSIÇÃO DO VECTOR DE PARTIDOS BUSCANDO PELO NUMERO DO PARTIDO
    INPUTs: Referencia para p vector de partidoss
    OUTPUTs: inteiro representando a pos desejada
    Pré-condição: O vector de partidos deve existir
    Pós-condição: -
    */
    const int retornaPosPartido(const vector<Partido>& partidos, int numPartido) const;

    /*RETORNA UM VECTOR CONTENDO OS CANDIDATOS MAIS VOTADOS DE UM PARTIDO
    INPUTs: Referencia para p vector de partidoss
    OUTPUTs: inteiro representando a pos desejada
    Pré-condição: O vector de partidos deve existir
    Pós-condição: -
    */
    const vector<Candidato>& retornaVectorCandidatosMaisVotadosDoPartido( vector<Candidato>& candidatoMaisVotado, vector<Partido>& partidos);
};

#endif