#include "Sistema.h"
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <locale>

using namespace std;

int main(int argc, char *argv[]) {
    
    setlocale(LC_ALL, "pt_BR.UTF-8");
    setlocale(LC_NUMERIC, "de_DE.UTF-8");

    // INICIALIZAÇÕES NECESSÁRIAS
    Leitura in;
    Sistema sistema;
    vector <Partido> partidos;
    vector <Candidato> candidatos;

    vector<Candidato>::iterator it;
    
    int i=0,pos=1;
 
    // CONFERINDO A QUANTIDADE DE ARGUMENTOS PASSADOS
    if(argc < 4){
        cout << "Quantidade de argumentos invalidos, favor informar todos os arquivos.";
        return 0;
    }

    string pathCandidatos = argv[1];
    string pathPartidos = argv[2];
    string data = argv[3];

    // LEITURA DE CANDIDATOS E PARTIDOS
    try {
    partidos = in.leituraPartidos(pathPartidos,partidos);
    candidatos = in.leituraCandidatos(pathCandidatos, partidos ,candidatos);
    
    // ORDENANDO OS CANDIDATOS PELOS VOTOS NOMINAIS
    sort(candidatos.begin(), candidatos.end(), Candidato::compareVotosNominais);
    
    // CONFIGURANDO OS VECTORS DE CANDIDATOS E PARTIDOS.
    for(std::vector<Candidato>::size_type i=0; i<candidatos.size(); i++){  
        // Setando as posições de todos os candidatos;
        if(candidatos[i].getDestinoVoto() == "Válido"){
            candidatos[i].setPos(pos);
        pos++; 
        }
        int numPartido = candidatos[i].getNumeroPartido();
        int posPartido = sistema.retornaPosPartido(partidos,numPartido);
        // Setando os candidatos dos partidos;
        partidos[posPartido].setNovoCandidatoPartido(candidatos[i]);   
    }

    // RELATÓRIOS:

    // 1- NÚMERO DE VAGAS (= NÚMERO DE ELEITOS)
    double numeroVagas = sistema.retornaNumeroDeVagas(candidatos);
    sistema.imprimeNumeroVagas(numeroVagas);

    // 2 - CANDIDATOS ELEITOS
    vector <Candidato> candidatosEleitos;
    candidatosEleitos = sistema.retornaCandidatosEleitos(candidatos);
    sort(candidatosEleitos.begin(), candidatosEleitos.end(), Candidato::compareVotosNominais);
    sistema.imprimeVereadoresEleitos(candidatosEleitos, partidos);

    // 3 - CANDIDATOS MAIS VOTADOS DENTRO DO NÚMERO DE VAGAS
    sort(candidatos.begin(), candidatos.end(), Candidato::compareVotosNominais);
    vector<Candidato> candidatosMaisVotados; 
    
    for(it=candidatos.begin(); i<numeroVagas; i++,it++){ 
        candidatosMaisVotados.push_back(*it);
    }
    sistema.imprimeCandidatosMaisVotados(candidatosMaisVotados, partidos);

    // 4 - CANDIDATOS NÃO ELEITOS E QUE SERIAM ELEITOS SE A VOTAÇÃO FOSSE MAJORITÁRIA 
    vector<Candidato> candidatosEleitosSeMajoritaria = sistema.retornaArrayCandidatosMaisVotadosNaoEleitos(candidatosMaisVotados);
    sistema.imprimeCandidatosEleitosMaj(candidatosEleitosSeMajoritaria, candidatosMaisVotados, partidos);

    // 5 - CANDIDATOS ELEITOS NO SISTEMA PROPORCIONAL VIGENTE, E QUE NÃO SERIAM ELEITOS SE A VOTAÇÃO FOSSE MAJORITÁRIA
    vector<Candidato> candidatosEleitosBeneficiadosProp = sistema.retornaArrayBeneficiadosProp(candidatosEleitos, candidatosMaisVotados);
    sistema.imprimeCandidatosEleitosBeneficiadosProp(candidatosEleitosBeneficiadosProp, candidatosMaisVotados, partidos);

    // 6 - VOTOS TOTALIZADOS POR PARTIDO E NUMERO DE CANDIDATOS ELEITOS
    sort(partidos.begin(), partidos.end(),  Partido::compareVotosTotais);
    sistema.imprimeVotacaoPartidos(candidatosEleitos,partidos);    

    // 7 - PRIMEIRO E ULTIMO COLOCADOS DE CADA PARTIDO
    vector<Candidato> candidatoMaisVotado;   
    candidatoMaisVotado = sistema.retornaVectorCandidatosMaisVotadosDoPartido(candidatoMaisVotado, partidos);
    sort(candidatoMaisVotado.begin(), candidatoMaisVotado.end(), Candidato::compareVotosNominais);
    sistema.imprimePrimeiroUltimoPartido(candidatoMaisVotado, partidos,data);

    // 8 - DISTRIBUICAO DE ELEITOS POR FAIXA ETARIA 
    sistema.imprimeEleitosFaixaEtaria(candidatosEleitos, numeroVagas, data);

    // 9 - DISTRIBUIÇÃO DE ELEITOS POR SEXO: 
    double qtdF = sistema.retornaQtdEleitosSexoFeminino(candidatosEleitos);
    double porcentagemF = (qtdF/numeroVagas)*100;
    double porcentagemM = ((numeroVagas - qtdF)/numeroVagas)*100;

    sistema.imprimeEleitosPorSexo(numeroVagas, qtdF, porcentagemF, porcentagemM);

    // 10 - TOTAL DE VOTOS 
    double totalVotosValidos = sistema.retornaTotalVotosValidos(candidatos, partidos);
    double totalVotosNominais = sistema.retornaTotalVotosNominais(candidatos);
    double totalVotosLegenda = sistema.retornaTotalVotosLegenda( partidos);
    double porcentagemVN = (totalVotosNominais/totalVotosValidos)*100;
    double porcentagemVL = (totalVotosLegenda/totalVotosValidos)*100;
    sistema.imprimeTotal(totalVotosValidos, totalVotosNominais, totalVotosLegenda, porcentagemVN, porcentagemVL);

    }catch(exception &e){
        cout << e.what() << endl;
    }
    return 0;
}