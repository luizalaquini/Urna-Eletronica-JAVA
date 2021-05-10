package src;

import java.lang.String;

public class Candidato implements Comparable<Candidato>{
    private int numero; //Número do candidato na urna;
    private int votosNominais; //Total de votos nominais do candidato;
    private String situacao; //Situação do candidato: Eleito / Não Eleito / Suplente;
    private String nome; //Nome completo do candidato;
    private String nomeUrna; //Nome do candidato como mostrado na urna eletrônica;
    private String sexo; //Sexo do candidato: F / M;
    private String dataNasc; //Data de nascimento do candidato no formato dd/mm/aaaa;
    private String destinoVoto; //Válido / Anulado / Anulado sub judice; 
    private int numeroPartido; //Número do partido do candidato;
    private int pos = 0;
    private int flagCompare = 0;
    
    Candidato() {}

    Candidato(int numero, int votosnominais, String situacao,String nome, String nomeUrna, String sexo,String dataNasc, String destinoVoto, int numeroPartido){
        this.numero = numero;
        this.votosNominais = votosnominais;
        this.situacao = situacao;
        this.nome = nome;
        this.nomeUrna = nomeUrna;
        this.sexo = sexo;
        this.dataNasc = dataNasc;
        this.destinoVoto = destinoVoto;
        this.numeroPartido = numeroPartido;
    }

    //GETs e SETs
    
    public void setPos(int pos){
        this.pos = pos;
    }
    public int getPos(){
        return this.pos;
    }

    public void setFlagCompare(int flagCompare){
        this.flagCompare = flagCompare;
    }
    public int getFlagCompare(){
        return this.flagCompare++;
    }

    public void setNumero (int numero){
        this.numero = numero;
    }

    public void setVotosNominais (int votosNominais){
        this.votosNominais = votosNominais;
    }
    
    public void setSituacao (String situacao){
        this.situacao = situacao;
    }
    
    public void setNome (String nome){
        this.nome = nome;
    }

    public void setNomeUrna (String nomeUrna){
        this.nomeUrna = nomeUrna;
    }

    public void setSexo (String sexo){
        this.sexo = sexo;
    }

    public void setDataNasc (String dataNasc){
        this.dataNasc = dataNasc;
    }

    public void setDestinoVoto (String destinoVoto){
        this.destinoVoto = destinoVoto;
    }

    public void setNumeroPartido (int numeroPartido){
        this.numeroPartido = numeroPartido; 
    }

    public int getNumero(){
        return this.numero;
    }
    
    public int getVotosNominais(){
        return this.votosNominais;
    }
    
    public String getSituacao(){
        return this.situacao;
    }
    
    public String getNome(){
        return this.nome;
    }

    public String getNomeUrna(){
        return this.nomeUrna;
    }

    public String getSexo(){
        return this.sexo;
    }

    public String getDataNasc(){
        return this.dataNasc;
    }
    
    public String getDestinoVoto(){
        return this.destinoVoto;
    }

    public int getNumeroPartido(){
        return this.numeroPartido;
    }

    public int retornaIdadeCandidato(String dataEleicao){
        String[] dataEleicaoSeparada = dataEleicao.split("/");
        String[] dataNascSeparada = this.dataNasc.split("/");

        int idade = 0;
        int diaEleicao = 0, diaNasc = 0;
        int MesEleicao = 0, MesNasc = 0;
        int AnoEleicao = 0, AnoNasc = 0;
        try{
        diaEleicao = Integer.parseInt(dataEleicaoSeparada[0]);
        MesEleicao = Integer.parseInt(dataEleicaoSeparada[1]);
        AnoEleicao = Integer.parseInt(dataEleicaoSeparada[2]);
        diaNasc = Integer.parseInt(dataNascSeparada[0]);
        MesNasc = Integer.parseInt(dataNascSeparada[1]);
        AnoNasc = Integer.parseInt(dataNascSeparada[2]);
        }
        catch(NumberFormatException e)
        {
        //Caso nao seja inteiro executa o que estiver neste bloco
        }

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
    
    @Override
    public int compareTo(Candidato candidatos){
        
        if(this.votosNominais < candidatos.getVotosNominais()){
            return 1;
        }
        else if(this.votosNominais > candidatos.getVotosNominais()){
            return -1;
        }   
        if(candidatos.flagCompare == 1){
            if(this.numeroPartido < candidatos.numeroPartido){
                return -1;
            }else{
                return 1;
            }
        }else{
            /*
            if(this.retornaIdadeCandidato("15/11/2020") < candidatos.retornaIdadeCandidato("15/11/2020")){
                return 1;
            }else{
                return -1;
            }
        }
        */

        if(Integer.parseInt(this.getDataNasc().substring(6,9)) > Integer.parseInt(candidatos.getDataNasc().substring(6,9))){
            return 1;
        }else if(Integer.parseInt(this.getDataNasc().substring(6,9)) == Integer.parseInt(candidatos.getDataNasc().substring(6,9))){
            if(Integer.parseInt(this.getDataNasc().substring(3,4)) > Integer.parseInt(candidatos.getDataNasc().substring(3,4))){
                return 1;
            }else if(Integer.parseInt(this.getDataNasc().substring(3,4)) == Integer.parseInt(candidatos.getDataNasc().substring(3,4))){
                if((Integer.parseInt(this.getDataNasc().substring(0,1)) > Integer.parseInt(candidatos.getDataNasc().substring(0,1)))){
                    return 1;
                }else{
                    return -1;
                }
            }else{
                return -1;
            }
        }else{
            return -1;
        }
    }
}

    public String toString(String nomePartido){
        return String.format("%s / %s (%s, %d votos)", this.nome, this.nomeUrna,nomePartido, this.votosNominais);
    }

}
