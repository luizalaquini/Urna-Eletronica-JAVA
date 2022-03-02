package src;

import java.util.ArrayList;
import java.util.Scanner;
import java.io.FileReader;
import java.util.NoSuchElementException;
import java.io.FileNotFoundException;

public class Leitura {
    
    /*REALIZA A LEITURA DOS PARTIDOS
    INPUTs: Caminho do arquivo de partidos, Sistema Instanciado e Array de partidos inicializado
    OUTPUTs: Array de partidos
    Pré-condição: Caminho deve existir e estar correto. Array de partidos deve somente existir
    Pós-condição: -
    */
    public ArrayList<Partido> leituraPartidos(String path, Sistema sistema, ArrayList<Partido> partidos){
        String[] vetorLinha = new String[9];

        try{
            FileReader reader = new FileReader(path);
            Scanner scanP = new Scanner(reader); //Scanner para partidos
        try{
            scanP.nextLine(); //A primeira linha do arquivo dever consumida;
            while (scanP.hasNext()){ //Leitura total do arquivo
                vetorLinha = scanP.nextLine().split(",");
                Partido partido = new Partido(
                    Integer.parseInt(vetorLinha[0]),
                    Integer.parseInt(vetorLinha[1]),
                    vetorLinha[2],
                    vetorLinha[3]
                    );
                partidos.add(partido);
            }
            scanP.close();
        }catch(NoSuchElementException e){
            System.out.println("Exceção: " + e + "\nArquivo Vazio");
            //return null;    
        }
        }catch (FileNotFoundException e){
            System.out.println("Arquivo de partidos não foi encontrado");
            //return null;
        }

        return partidos;
    }

    /*REALIZA A LEITURA DOS CANDIDATOS
    INPUTs: Caminho do arquivo de candidatos, Sistema Instanciado, Array de partidos e de candidatos inicializados
    OUTPUTs: Array de candidatos
    Pré-condição: Caminho deve existir e estar correto. Arrays devem somente existir
    Pós-condição: -
    */
    public ArrayList<Candidato> leituraCandidatos(String path, Sistema sistema, ArrayList<Partido> partidos, ArrayList<Candidato> candidatos){
        String[] vetorLinha = new String[9];

        try{
            FileReader reader = new FileReader(path);
            Scanner scanC = new Scanner(reader); //Scanner para candidatos
            Partido partidoRtn = new Partido();
        try{
            scanC.nextLine(); //A primeira linha do arquivo dever consumida;
            while (scanC.hasNext()){ 
                vetorLinha = scanC.nextLine().split(",");
                Candidato candidato = new Candidato(
                    Integer.parseInt(vetorLinha[0]),
                    Integer.parseInt(vetorLinha[1]),
                    vetorLinha[2],
                    vetorLinha[3],
                    vetorLinha[4],
                    vetorLinha[5],
                    vetorLinha[6],
                    vetorLinha[7],
                    Integer.parseInt(vetorLinha[8])
                    );
                partidoRtn = sistema.retornaPartidoPeloNumero(partidos, Integer.parseInt(vetorLinha[8]));
                partidoRtn.setNovoCandidatoPartido(candidato);   
                candidatos.add(candidato);
        }
        scanC.close();
        }catch(NoSuchElementException e){
            System.out.println("Exceção: " + e + "\nArquivo Vazio!");
            return null;
        }
        }catch(FileNotFoundException e){
            System.out.println("Arquivo de candidatos não foi encontrado");
            return null;
        }
        
        return candidatos;
    }
}

