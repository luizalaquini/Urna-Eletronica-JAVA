// #include "Leitura.h"
#include <cstdio>
#include "Sistema.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using std::stringstream;

Leitura::Leitura() {};

const vector <Partido>& Leitura::leituraPartidos(string &path, vector <Partido>& partidos){
    ifstream in(path);
    string linha;
    int j = 0, num = 0, votosLegenda = 0;
    //string linha;
    vector<string> tokens;

    // variável de trabalho
    string token;
     
    if(in.is_open()){
            while(getline(in, linha)){
            // stream de strings de input inicializado com a string a ser separada
            istringstream tokenizer { linha };

            //separando a linha lida pelas vírgulas.
            while (getline(tokenizer, token, ','))
                tokens.push_back(token);
        }
        j=0;
        // setando os partidos e adicionando na lista de partidos.
        for (std::vector<string>::size_type i=0; i < tokens.size();i += 4){
            if(i != 0 || i % 4){
                // convertendo a string em int.
                num = 0;
                vector<Candidato> candidadosPartido;
                num = stoi(tokens[i]);
                votosLegenda = stoi(tokens[i+1]);
                Partido p(num, votosLegenda,tokens[i+2],tokens[i+3],candidadosPartido);
                j++;
                partidos.push_back(p);
            }
        }
        in.close();
        return partidos;
    }else {
        throw runtime_error("Não foi possivel abrir o arquivo de partidos");
    }
}

const vector <Candidato>& Leitura::leituraCandidatos(string &path,vector<Partido> &partidos, vector <Candidato> &candidatos){
    ifstream in(path);
    string linha;
    int j = 0, num = 0, numVotosNominais = 0, numPartido = 0;

    //string linha;
    vector<string> tokens;

    // variável de trabalho
    string token;
    if(in.is_open()){
        //Lendo linha por linha.
        while(getline(in, linha)){
            // stream de strings de input inicializado com a string a ser separada
            istringstream tokenizer { linha };
            //separando a linha lida pelas vírgulas.
            while (getline(tokenizer, token, ','))
                tokens.push_back(token);
        }
        
        j=0;
        // Setando os candidatos e adicionando na lista de candidatos.
        for (std::vector<string>::size_type i=0; i < tokens.size(); i += 9){
            if(i != 0 || i % 9){
                Partido partidoRtn;
                Sistema sistema;
                num = stoi(tokens[i]);
                numVotosNominais = stoi(tokens[i+1]);
                numPartido = stoi(tokens[i+8]);
                Candidato c(num,numVotosNominais, tokens[i+2],tokens[i+3],tokens[i+4], tokens[i+5], tokens[i+6], tokens[i+7],numPartido,j);
                j++;
                candidatos.push_back(c);
            }   
        }
        in.close();
        return candidatos;
    }else{
        throw runtime_error("Não foi possivel abrir o arquivo de candidatos");
    }   
}   