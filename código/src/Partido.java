package src;

import java.util.ArrayList;

public class Partido implements Comparable<Partido>{
    private int numeroPartido; //Número do partido;
    private int votosLegenda; //Total de votos de legenda do partido;
    private String nomePartido; //Nome do partido;
    private String siglaPartido; //Sigla do partido;
    private ArrayList<Candidato> candidatosPartido; //Lista de candidatos pertencentes ao partido

    Partido(){}

    Partido(int numeroPartido, int votosLegenda, String nomePartido,String siglaPartido){
        this.numeroPartido = numeroPartido;
        this.votosLegenda = votosLegenda;
        this.nomePartido = nomePartido;
        this.siglaPartido = siglaPartido;
        this.candidatosPartido = new ArrayList<Candidato>();
    }

    //GETs e SETs

    public int getNumeroPartido(){
        return this.numeroPartido;
    }

    public void setNumeroPartido(int numeroPartido){
        this.numeroPartido = numeroPartido;
    }

    public int getVotosLegendas(){
        return this.votosLegenda;
    }

    public void setVotosLegendas(int votosLegenda){
        this.votosLegenda = votosLegenda;
    }

    public String getNomePartido(){
        return this.nomePartido;
    }

    public void setNomePartido(String nomePartido){
        this.nomePartido = nomePartido;
    }

    public String getSiglaPartido(){
        return this.siglaPartido;
    }

    public void setSiglaPartido(String siglaPartido){
        this.siglaPartido = siglaPartido;
    }  

    public ArrayList<Candidato> getCandidatoPartido(){
        return candidatosPartido;
    }

    public void setNovoCandidatoPartido(Candidato candidato){
        this.candidatosPartido.add(candidato);
    }

    public Candidato retornaCandidatoMaisVotadoPartido(){
        int maior = 0;
        Candidato candidato = new Candidato();
        for(int i=0; i < this.candidatosPartido.size();i++){
            if(this.candidatosPartido.get(i).getVotosNominais() > maior && this.candidatosPartido.get(i).getDestinoVoto().equals("Válido")){
                maior = this.candidatosPartido.get(i).getVotosNominais();
                candidato = this.candidatosPartido.get(i);
            }else{
                continue;
            }
        }
        return candidato;
    }

    public Candidato retornaCandidatoMenosVotadoPartido(String dataEleicao){
        int menor = 0, aux=0;

        Candidato candidato = new Candidato();

        for(int i=0; i < this.candidatosPartido.size();i++){
                
                if(aux==0){ //define o primeiro valor para a variavel "menor"
                    if(this.candidatosPartido.get(i).getDestinoVoto().equals("Válido")){
                        menor = this.candidatosPartido.get(i).getVotosNominais();
                        candidato = this.candidatosPartido.get(i);
                        aux++;
                        continue;
                    }
                }
                if(this.candidatosPartido.get(i).getDestinoVoto().equals("Válido")){
                    if(this.candidatosPartido.get(i).getVotosNominais() < menor){
                        menor = this.candidatosPartido.get(i).getVotosNominais();
                        candidato = this.candidatosPartido.get(i);
                    }else if(this.candidatosPartido.get(i).getVotosNominais() == menor){
                        if(this.candidatosPartido.get(i).retornaIdadeCandidato(dataEleicao) < candidato.retornaIdadeCandidato(dataEleicao)){
                            candidato = this.candidatosPartido.get(i);
                        }else if(this.candidatosPartido.get(i).retornaIdadeCandidato(dataEleicao) == candidato.retornaIdadeCandidato(dataEleicao)){
                            if(this.Candidato1MaisVelho(this.candidatosPartido.get(i), candidato) == 1){
                                candidato = this.candidatosPartido.get(i);
                            }
                        }
                    }
            }
        }
        return candidato;
    }

    public int Candidato1MaisVelho(Candidato candidato1, Candidato candidato2){
        //31/05/2001
        if(Integer.parseInt(candidato1.getDataNasc().substring(6,9)) > Integer.parseInt(candidato2.getDataNasc().substring(6,9))){
            return 0;
        }else if(Integer.parseInt(candidato1.getDataNasc().substring(6,9)) == Integer.parseInt(candidato2.getDataNasc().substring(6,9))){
            if(Integer.parseInt(candidato1.getDataNasc().substring(3,4)) > Integer.parseInt(candidato2.getDataNasc().substring(3,4))){
                return 0;
            }else if(Integer.parseInt(candidato1.getDataNasc().substring(3,4)) == Integer.parseInt(candidato2.getDataNasc().substring(3,4))){
                if(Integer.parseInt(candidato1.getDataNasc().substring(0,1)) > Integer.parseInt(candidato2.getDataNasc().substring(0,1))){
                    return 0;
                }
            }
        }
        return 1;
    }
    public int getVotosTotais(){
        int votosNominaisPartido = 0, votosTotais = 0;
        for(int i=0; i < this.candidatosPartido.size(); i++){
            if(this.candidatosPartido.get(i).getDestinoVoto().equals("Válido")){
                votosNominaisPartido += this.candidatosPartido.get(i).getVotosNominais();
            }
        }
        votosTotais = votosNominaisPartido + this.getVotosLegendas();
        return votosTotais;
    }

    @Override
    public int compareTo(Partido partido){
        // Ordenando pelos votos totais
        int votosTotaiso1 = this.getVotosTotais();
        int votosTotaiso2 = partido.getVotosTotais();

        if(votosTotaiso1 < votosTotaiso2){
            return 1;
        }else{
            return -1;
        }
    }

    @Override
    public String toString(){
        if(this.getVotosTotais() >= 2){
            if(this.getVotosTotais() - this.getVotosLegendas() >= 2){
                return String.format("%s - %d, %d votos (%d nominais e %d de legenda), ", this.siglaPartido, this.numeroPartido, this.getVotosTotais(), (this.getVotosTotais() - this.getVotosLegendas()), this.getVotosLegendas());
            }else{
                return String.format("%s - %d, %d votos (%d nominal e %d de legenda), ", this.siglaPartido, this.numeroPartido, this.getVotosTotais(), (this.getVotosTotais() - this.getVotosLegendas()), this.getVotosLegendas());
            }
        }else{
            return String.format("%s - %d, %d voto (%d nominal e %d de legenda), ", this.siglaPartido, this.numeroPartido, this.getVotosTotais(), (this.getVotosTotais() - this.getVotosLegendas()), this.getVotosLegendas());
        }
    }
}