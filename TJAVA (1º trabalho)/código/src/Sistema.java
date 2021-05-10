package src;

import java.util.ArrayList;
import java.util.Collections;

public class Sistema {

    /*RETORNA O NÚMERO DE VAGAS EXISTENTES (= NÚMERO DE ELEITOS)
    INPUTs: Lista de Candidatos
    OUTPUTs: Número de Vagas 
    Pré-condição: Lista de Candidatos deve existir
    Pós-condição: Double para número de vagas existe e é >= 0
    */
    public double retornaNumeroDeVagas(ArrayList<Candidato> candidatos){
        double cont = 0;

        for(int i=0; i < candidatos.size(); i++){
            if(candidatos.get(i).getSituacao().equals("Eleito")) cont++;
        }
        
        return cont;
    }

    /*RETORNA LISTA DE CANDIDATOS ELEITOS
    INPUTs: Lista de Candidatos
    OUTPUTs: Lista de Candidatos Eleitos
    Pré-condição: Lista de Candidatos deve existir
    Pós-condição: Lista de Candidatos Eleitos existe
    */
    public ArrayList<Candidato> retornaCandidatosEleitos(ArrayList<Candidato> candidatos){
        ArrayList<Candidato> candidatosEleitos = new ArrayList<Candidato>();
        
        for(int i=0; i < candidatos.size(); i++){
            if(candidatos.get(i).getSituacao().equals("Eleito")){
                candidatosEleitos.add(candidatos.get(i));
            }
        }
        
        return candidatosEleitos;
    }
    
    /*RETORNA O TOTAL DE MULHERES ELEITAS 
    INPUTs: Lista de Candidatos Eleitos
    OUTPUTs: Número de Mulheres eleitas
    Pré-condição: Lista de Candidatos Eleitos deve existir
    Pós-condição: Double para número de Mulheres eleitas existe e é >=0
    */
    public double retornaQtdEleitosSexoFeminino(ArrayList<Candidato> candidatosEleitos){
        double qtd = 0;
        
        for(int i=0; i < candidatosEleitos.size(); i++){
            if(candidatosEleitos.get(i).getSexo().equals("F")) qtd++;
        }
 
        return qtd;
    }

    /*RETORNA O TOTAL DE CANDIDATOS ELEITOS POR PARTIDO
    INPUTs: Lista de Candidatos Eleitos e Número do Partido
    OUTPUTs: Quantidade de candidatos eleitos para o dado partido
    Pré-condição: Lista de Candidatos Eleitos e Partido devem existir
    Pós-condição: Inteiro para número de Eleitos do Partido existe e é >=0
    */
    public int retornaQtdCandidatosEleitosPartido(ArrayList<Candidato> candidatosEleitos, int numPartido){
        int qtd = 0;

        for (int i=0; i < candidatosEleitos.size(); i++){
            if(candidatosEleitos.get(i).getNumeroPartido() == numPartido){
                qtd++;
            }
        }

        return qtd;
    }

    /*RETORNA O TOTAL DE VOTOS VALIDOS
    INPUTs: Lista de Candidatos e Lista de Partidos
    OUTPUTs: Quantidade total de votos válidos
    Pré-condição: Lista de Candidatos e Lista de Partidos devem existir
    Pós-condição: Double para total de votos válidos existe e é >=0
    */
    public double retornaTotalVotosValidos(ArrayList<Candidato> candidatos, ArrayList<Partido> partidos){
        double total = 0, nominais = 0, legenda = 0;
        for(int i=0; i < candidatos.size(); i++){
            if (candidatos.get(i).getDestinoVoto().equals("Válido")){
                nominais += candidatos.get(i).getVotosNominais();
            }  
        }
        for(int i=0; i < partidos.size(); i++){
            legenda += partidos.get(i).getVotosLegendas();
        }
        total = nominais + legenda;
        return total;
    }

    /*RETORNA O TOTAL DE VOTOS NOMINAIS
    INPUTs: Lista de Candidatos
    OUTPUTs: Quantidade total de votos nominais
    Pré-condição: Lista de Candidatos deve existir
    Pós-condição: Double para total de votos nominais existe e é >=0
    */
    public double retornaTotalVotosNominais(ArrayList<Candidato> candidatos){
        double total = 0;
        for(int i=0; i < candidatos.size(); i++){
            if (candidatos.get(i).getDestinoVoto().equals("Válido")){
                total += candidatos.get(i).getVotosNominais();
            } 
        }

        return total;
    }

    /*RETORNA O TOTAL DE VOTOS DE LEGENDA
    INPUTs: Lista de Partidos
    OUTPUTs: Quantidade total de votos de legenda
    Pré-condição: Lista de Partidos deve existir
    Pós-condição: Double para total de votos de legenda existe e é >=0
    */
    public double retornaTotalVotosLegenda(ArrayList<Partido> partidos){
        double total = 0;
        for(int i=0; i < partidos.size(); i++){
            total += partidos.get(i).getVotosLegendas();
        }
        return total;
    }
    
    /*RETORNA ARRAY DE CANDIDATOS MAIS VOTADOS NAO ELEITOS
    INPUTs: Array de todos os candidatos
    OUTPUTs: Array de candidatos mais votados, mas que não foram eleitos
    Pré-condição: Array de candidatos deve existir
    Pós-condição: -
    */
    public ArrayList<Candidato> retornaArrayCandidatosMaisVotadosNaoEleitos(ArrayList<Candidato> candidatos){
        ArrayList<Candidato> candidatosMaisVotadosNaoEleitos = new ArrayList<Candidato>();
        for(int i =0; i < candidatos.size(); i++){
            if(candidatos.get(i).getSituacao().equals("Eleito")){
                continue;
            }else{
                candidatosMaisVotadosNaoEleitos.add(candidatos.get(i));
            }
        }
        return candidatosMaisVotadosNaoEleitos;
    }

    /*RETORNA ARRAY DE CANDIDATOS BENEFICIADOS PELO SISTEMA PROPORCIONAL DE VOTACAO
    INPUTs: Array de candidatos eleitos e Array de candidatos mais votados
    OUTPUTs: Array de candidatos beneficiados pelo sistema de votação proporcional
    Pré-condição: Array de candidatos deve existir
    Pós-condição: -
    */
    public ArrayList<Candidato> retornaArrayBeneficiadosProp(ArrayList<Candidato> candidatosEleitos, ArrayList<Candidato> candidatosMaisVotados){
        ArrayList<Candidato> candidatosBeneficiados = new ArrayList<Candidato>();
            for(int j=0; j < candidatosEleitos.size(); j++){
                if(candidatosMaisVotados.contains(candidatosEleitos.get(j))){
                    continue;
                }else{
                    candidatosBeneficiados.add(candidatosEleitos.get(j));
                }
            }    
        return candidatosBeneficiados;
    }

    /*RETORNA UM PARTIDO DADO PARTIDO CUJO NUMERO FOI PASSADO COMO CHAVE DE BUSCA
    INPUTs: Array de partidos e um Inteiro com o número do partido a ser encontrado
    OUTPUTs: Partido corresponte ao numero 
    Pré-condição: Array de partidos deve existir
    Pós-condição: -
    */
    public Partido retornaPartidoPeloNumero(ArrayList<Partido> partidos, int numeroPartido){
        Partido partido = new Partido();

        for(int i=0; i< partidos.size(); i++){
            if(partidos.get(i).getNumeroPartido() == numeroPartido){
                partido = partidos.get(i);
                return partido; 
            }
        }
        return partido;
    }

    /*IMPRIME O RELATÓRIO 1
    INPUTs: Número de Vagas 
    OUTPUTs: -
    Pré-condição: Número de vagas deve existir e ser >=0
    Pós-condição: - 
    */
    public void imprimeNumeroVagas (double numeroVagas){
        System.out.println(String.format("Número de vagas: %.0f\n", numeroVagas));
    }

    /*IMPRIME O RELATÓRIO 2
    INPUTs: Array de Candidatos Eleitos e Array de Partidos
    OUTPUTs: -
    Pré-condição: Arrays devem existir e estarem preenchidos
    Pós-condição: -
    */
    public void imprimeVereadoresEleitos (ArrayList<Candidato> candidatosEleitos, ArrayList<Partido> partidos){
        System.out.println("Vereadores eleitos:");
        
        for(int i=0; i < candidatosEleitos.size(); i++){
            System.out.print(String.format("%d - ", i+1));
            int numero = candidatosEleitos.get(i).getNumeroPartido();
            System.out.println(candidatosEleitos.get(i).toString(retornaPartidoPeloNumero(partidos, numero).getSiglaPartido()));
        }
        
        System.out.println();
    }

    /*IMPRIME O RELATÓRIO 3
    INPUTs: Array de Candidatos Mais Votados, Array de Partidos e Inteiro com o Número do Partido
    OUTPUTs: -
    Pré-condição: Arrays devem existir e estarem preenchidos. Inteiro deve existir e corresponder a um partido existente
    Pós-condição: -
    */
    public void imprimeCandidatosMaisVotados (ArrayList<Candidato> candidatosMaisVotados, ArrayList<Partido> partidos){
        System.out.println("Candidatos mais votados (em ordem decrescente de votação e respeitando número de vagas):");
        int numero = 0;
        for(int i=0; i < candidatosMaisVotados.size();i++){
            System.out.print(String.format("%d - ", i+1));
            numero = candidatosMaisVotados.get(i).getNumeroPartido();
            System.out.println(candidatosMaisVotados.get(i).toString(retornaPartidoPeloNumero(partidos, numero).getSiglaPartido()));
        }
        System.out.println();
    }

    /*IMPRIME O RELATÓRIO 4
    INPUTs: Array de Candidatos "desfavorecidos pelo sistema" e Array de Partidos
    OUTPUTs: -
    Pré-condição: Arrays devem existir e estarem preenchidos
    Pós-condição: -
    */
    public void imprimeCandidatosEleitosMaj (ArrayList<Candidato> candidatosEleitosSeMajoritaria, ArrayList<Partido> partidos){
        System.out.println("Teriam sido eleitos se a votação fosse majoritária, e não foram eleitos:\n(com sua posição no ranking de mais votados)"); 
        
        for(int i=0; i < candidatosEleitosSeMajoritaria.size(); i++){
            int numero = candidatosEleitosSeMajoritaria.get(i).getNumeroPartido();
            System.out.print(String.format("%d - ", candidatosEleitosSeMajoritaria.get(i).getPos()));
            System.out.println(candidatosEleitosSeMajoritaria.get(i).toString(retornaPartidoPeloNumero(partidos, numero).getSiglaPartido()));
        }
        
        System.out.println();
    }

    /*IMPRIME O RELATÓRIO 5
    INPUTs: Array de Candidatos "beneficiados pelo sistema" e Array de Partidos
    OUTPUTs: -
    Pré-condição: Arrays devem existir e estarem preenchidos
    Pós-condição: -
    */
    public void imprimeCandidatosEleitosBeneficiadosProp (ArrayList<Candidato> candidatosEleitosBeneficiadosProp, ArrayList<Partido> partidos){
        System.out.println("Eleitos, que se beneficiaram do sistema proporcional:\n(com sua posição no ranking de mais votados)");
        
        for(int i=0; i < candidatosEleitosBeneficiadosProp.size(); i++){
            int numero = candidatosEleitosBeneficiadosProp.get(i).getNumeroPartido();
            System.out.print(String.format("%d - ", candidatosEleitosBeneficiadosProp.get(i).getPos()));
           System.out.println(candidatosEleitosBeneficiadosProp.get(i).toString(retornaPartidoPeloNumero(partidos, numero).getSiglaPartido()));
        }
        
        System.out.println();
    }

    /*IMPRIME O RELATÓRIO 6
    INPUTs: Array de Candidatos Eleitos e Array de Partidos
    OUTPUTs: -
    Pré-condição: Arrays devem existir e estarem preenchidos
    Pós-condição: -
    */
    public void imprimeVotacaoPartidos (ArrayList<Candidato> candidatosEleitos, ArrayList<Partido> partidos){
        System.out.println("Votação dos partidos e número de candidatos eleitos:");
        
        for (int i=0; i < partidos.size(); i++){
            System.out.print(String.format("%d - ", i+1));
            System.out.print(partidos.get(i).toString());
            if(retornaQtdCandidatosEleitosPartido(candidatosEleitos,partidos.get(i).getNumeroPartido()) >= 2 ){
                System.out.println(String.format("%d candidatos eleitos", retornaQtdCandidatosEleitosPartido(candidatosEleitos,partidos.get(i).getNumeroPartido() )));
            } else {
                System.out.println(String.format("%d candidato eleito", retornaQtdCandidatosEleitosPartido(candidatosEleitos,partidos.get(i).getNumeroPartido() )));
            }
        }

        System.out.println();
    }

    /*IMPRIME O RELATÓRIO 7
    INPUTs: Array com Candidatos mais votados de cada partido e Array de partidos
    OUTPUTs: -
    Pré-condição: Arrays devem existir e estarem preenchidos
    Pós-condição: -
    */
    public void imprimePrimeiroUltimoPartido (ArrayList<Candidato> candidatoMaisVotado, ArrayList<Partido> partidos,String dataEleicao){
        Candidato candidatoMenosVotado;
        Partido partidoAtual;
        
        System.out.println("Primeiro e último colocados de cada partido:");
        
        for(int i=0; i < partidos.size(); i++){
            candidatoMaisVotado.add(partidos.get(i).retornaCandidatoMaisVotadoPartido());
            candidatoMaisVotado.get(i).setFlagCompare(1);
        }
        Collections.sort(candidatoMaisVotado);

        for(int i = 0; i < candidatoMaisVotado.size(); i++){
            if(candidatoMaisVotado.get(i).getNome() == null)continue;
            partidoAtual = retornaPartidoPeloNumero(partidos, candidatoMaisVotado.get(i).getNumeroPartido());
            candidatoMenosVotado = partidoAtual.retornaCandidatoMenosVotadoPartido(dataEleicao);
            if(partidoAtual.getVotosTotais() != 0){

                if(candidatoMaisVotado.get(i).getVotosNominais() >= 2){
                    System.out.print(String.format("%d - %s - %d, %s (%d, %d votos) / ", (i+1), partidoAtual.getSiglaPartido(),partidoAtual.getNumeroPartido(), candidatoMaisVotado.get(i).getNomeUrna(),candidatoMaisVotado.get(i).getNumero(),candidatoMaisVotado.get(i).getVotosNominais()));
                }else{
                    System.out.print(String.format("%d - %s - %d, %s (%d, %d voto) / ", (i+1), partidoAtual.getSiglaPartido(),partidoAtual.getNumeroPartido(), candidatoMaisVotado.get(i).getNomeUrna(),candidatoMaisVotado.get(i).getNumero(),candidatoMaisVotado.get(i).getVotosNominais()));
                }
                
                if(candidatoMenosVotado.getVotosNominais() >= 2){
                    System.out.println(String.format("%s (%d, %d votos)", candidatoMenosVotado.getNomeUrna(), candidatoMenosVotado.getNumero(), candidatoMenosVotado.getVotosNominais()));
                }else{
                    System.out.println(String.format("%s (%d, %d voto)", candidatoMenosVotado.getNomeUrna(), candidatoMenosVotado.getNumero(), candidatoMenosVotado.getVotosNominais()));
                }
            }
        }

        System.out.println();
    }

    /*IMPRIME O RELATÓRIO 8
    INPUTs: Array com Candidatos Eleitos, Número de Vagas e Data da eleição.
    OUTPUTs: -
    Pré-condição: Array deve estar inicializado e preenchido. Número de Vagas deve existir e ser >=0. Data da eleição deve ser válida
    Pós-condição: -
    */
    public void imprimeEleitosFaixaEtaria (ArrayList<Candidato> candidatosEleitos, double numeroVagas, String data){
        System.out.println("Eleitos, por faixa etária (na data da eleição):");
        
        int idades[] = new int[(int)numeroVagas];
        int contMenor30 = 0, cont30Menor40 = 0, cont40Menor50 = 0, cont50Menor60 = 0, contMaior60 =0;

        for(int i=0; i< candidatosEleitos.size(); i++){
            idades[i] = candidatosEleitos.get(i).retornaIdadeCandidato(data);
        }

        for(int i=0; i < idades.length;i++){
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

        System.out.println(String.format("      Idade < 30: %d (%.2f%%)", contMenor30,porcentagem));
        porcentagem = (float)cont30Menor40/(float)numeroVagas*100;
        System.out.println(String.format("30 <= Idade < 40: %d (%.2f%%)", cont30Menor40,porcentagem));
        porcentagem = (float)cont40Menor50/(float)numeroVagas*100;
        System.out.println(String.format("40 <= Idade < 50: %d (%.2f%%)", cont40Menor50,porcentagem));
        porcentagem = (float)cont50Menor60/(float)numeroVagas*100;
        System.out.println(String.format("50 <= Idade < 60: %d (%.2f%%)", cont50Menor60,porcentagem));
        porcentagem = (float)contMaior60/(float)numeroVagas*100;
        System.out.println(String.format("60 <= Idade     : %d (%.2f%%)", contMaior60, porcentagem));
        System.out.println();
    }

    /*IMPRIME O RELATÓRIO 9
    INPUTs: Número de Vagas, Quantidade de Eleitos do sexo feminino e Porcentagens (F e M)
    OUTPUTs: -
    Pré-condição: Variáveis devem existir
    Pós-condição: -
    */
    public void imprimeEleitosPorSexo (double numeroVagas, double qtdF, double porcentagemF, double porcentagemM){
        System.out.println("Eleitos, por sexo:");

        System.out.print("Feminino:  " + String.format("%.0f", qtdF));
        System.out.println(String.format(" (%.2f", porcentagemF) + "%)");
        System.out.print("Masculino: " + String.format("%.0f", (numeroVagas - qtdF)));
        System.out.println(String.format(" (%.2f", porcentagemM) + "%)\n");
    }

    /*IMPRIME O RELATÓRIO 10
    INPUTs: Total de Votos Válidos, Nominais e de Legenda e Porcentagens (VN e VL)
    OUTPUTs: -
    Pré-condição: Variáveis devem existir
    Pós-condição: -
    */
    public void imprimeTotal (double totalVotosValidos, double totalVotosNominais, double totalVotosLegenda, double porcentagemVN, double porcentagemVL){
        System.out.println(String.format("Total de votos válidos:    %.0f", totalVotosValidos));
        System.out.println(String.format("Total de votos nominais:   %.0f (%.2f%%)", totalVotosNominais,porcentagemVN));
        System.out.println(String.format("Total de votos de Legenda: %.0f (%.2f%%)", totalVotosLegenda,porcentagemVL));
        System.out.println();
    }


    public int confereSeValido(Candidato candidato){
        if(candidato.getDestinoVoto().equals("Válido")){
            return 1;
        }else{
            return 0;
        }
    }
}