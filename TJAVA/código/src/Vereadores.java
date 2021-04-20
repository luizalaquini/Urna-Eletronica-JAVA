package src;

import java.util.ArrayList;
import java.util.Collections;
import java.io.IOException;
import java.util.Locale;
import java.lang.ArrayIndexOutOfBoundsException;

public class Vereadores {
    public static void main(String[] args) throws IOException{
        Locale.setDefault(new Locale("pt", "BR"));

        // Array para armazenar todos os candidatos
        ArrayList<Candidato> candidatos = new ArrayList<Candidato>(); 
        
        // Array para armazenar todos os partidos
        ArrayList<Partido> partidos = new ArrayList<Partido>(); 
        
        // Instancia a classe do sistema
        Sistema sistema = new Sistema(); 
        
        String data = ""; //Instancia data vazia

        //Leitura de partidos e candidatos passados como parâmetro
        try{
            Leitura in = new Leitura();
            partidos = in.leituraPartidos(args[1], sistema, partidos);
            candidatos = in.leituraCandidatos(args[0], sistema, partidos, candidatos);
        }catch (ArrayIndexOutOfBoundsException e){
            System.out.println("Diretório nao informado");
            return;
        }catch (java.lang.NullPointerException e){
            System.out.println("Diretório nao informado");
            return;
        }

        //Leitura da data passada como parâmetro
        try{
            data = args[2];
        }catch(ArrayIndexOutOfBoundsException e){
            System.out.println("Data da eleição nao informada");
            return;
        }
        
        // Organiza arrays por quantidade de votos (Do mais votado para o menos votado)
        try{
            Collections.sort(candidatos);
            Collections.sort(partidos); 
        }catch(java.lang.NullPointerException e){
            return;
        }

        ArrayList<Candidato> candidatosEmOrdemGeral = new ArrayList<Candidato>(); //instancia array
        int pos = 0;

        try{
            for(int i=0; i < candidatos.size(); i++){ //organiza array
                if (sistema.confereSeValido(candidatos.get(i)) == 1){
                    candidatos.get(i).setPos(pos+1);
                    candidatosEmOrdemGeral.add(candidatos.get(i));
                    pos++;
                }else{continue;}
            } 
        }catch(IndexOutOfBoundsException e){
            System.out.println("Erro de acesso");
        }

        // 1 - NUMERO DE VAGAS (= NUMERO DE ELEITOS) 

        double numeroVagas = sistema.retornaNumeroDeVagas(candidatos);
        
        sistema.imprimeNumeroVagas(numeroVagas); 

        // 2 - CANDIDATOS ELEITOS (NOME COMPLETO E NA URNA) INDICANDO PARTIDO E NUMERO DE VOTOS NOMINAIS
        
        ArrayList<Candidato> candidatosEleitos = new ArrayList<Candidato>();
        candidatosEleitos = sistema.retornaCandidatosEleitos(candidatos);
        Collections.sort(candidatosEleitos); //Organiza por quantidade de votos (Do mais votado para o menos votado)

        sistema.imprimeVereadoresEleitos(candidatosEleitos, partidos);

        // 3 - CANDIDATOS MAIS VOTADOS DENTRO DO NUMERO DE VAGAS

        ArrayList<Candidato> candidatosMaisVotados = new ArrayList<Candidato>(); //instancia array
        for(int i =0; i < numeroVagas; i++){ //organiza array
            candidatosMaisVotados.add(candidatos.get(i));
        }

        try{
            sistema.imprimeCandidatosMaisVotados(candidatosMaisVotados, partidos);
        }catch(IndexOutOfBoundsException e){
            System.out.println("Exception: " + e);
            
        }

        // 4 - CANDIDATOS NAO ELEITOS E QUE SERIAM ELEITOS SE A VOTACAO FOSSE MAJORITARIA
        ArrayList<Candidato> candidatosEleitosSeMajoritaria = new ArrayList<Candidato>();
        candidatosEleitosSeMajoritaria = sistema.retornaArrayCandidatosMaisVotadosNaoEleitos(candidatosMaisVotados);
        sistema.imprimeCandidatosEleitosMaj(candidatosEleitosSeMajoritaria, partidos);

        // 5 - CANDIDATOS ELEITOS NO SISTEMA PROPORCIONAL VIGENTE E QUE NAO SERIAM ELEITOS SE A VOTACAO FOSSE MAJORITARIA

        ArrayList<Candidato> candidatosEleitosBeneficiadosProp = new ArrayList<Candidato>();
        candidatosEleitosBeneficiadosProp = sistema.retornaArrayBeneficiadosProp(candidatosEleitos, candidatosMaisVotados);
        
        sistema.imprimeCandidatosEleitosBeneficiadosProp(candidatosEleitosBeneficiadosProp, partidos);

        // 6 - VOTOS TOTALIZADOS POR PARTIDO E NUMERO DE CANDIDATOS ELEITOS

        sistema.imprimeVotacaoPartidos(candidatosEleitos, partidos);

        // 7 - PRIMEIRO E ULTIMO COLOCADOS DE CADA PARTIDO

        ArrayList<Candidato> candidatoMaisVotado = new ArrayList<Candidato>();   
        
        sistema.imprimePrimeiroUltimoPartido(candidatoMaisVotado, partidos,data);

        // 8 - DISTRIBUICAO DE ELEITOS POR FAIXA ETARIA 
        
        sistema.imprimeEleitosFaixaEtaria(candidatosEleitos, numeroVagas, data);

        // 9 - DISTRIBUICAO DE ELEITOS POR SEXO

        double qtdF = sistema.retornaQtdEleitosSexoFeminino(candidatosEleitos);
        double porcentagemF = (qtdF/numeroVagas)*100;
        double porcentagemM = ((numeroVagas - qtdF)/numeroVagas)*100;

        sistema.imprimeEleitosPorSexo(numeroVagas, qtdF, porcentagemF, porcentagemM);
        
        // 10 - TOTAL DE VOTOS, TOTAL DE VOTOS NOMINAIS E TOTAL DE VOTOS DE LEGENDA

        double totalVotosValidos = sistema.retornaTotalVotosValidos(candidatos, partidos);
        double totalVotosNominais = sistema.retornaTotalVotosNominais(candidatos);
        double totalVotosLegenda = sistema.retornaTotalVotosLegenda( partidos);
        double porcentagemVN = (totalVotosNominais/totalVotosValidos)*100;
        double porcentagemVL = (totalVotosLegenda/totalVotosValidos)*100;

        sistema.imprimeTotal(totalVotosValidos, totalVotosNominais, totalVotosLegenda, porcentagemVN, porcentagemVL);
    }
}