package javaEsercizi;
import java.time.LocalDate;
import java.util.ArrayList;
import java.util.List;

public class File {
    
    private static final LocalDate giorno = LocalDate.now();
    private List<String> lista;

    public static void main(String[] args){
        System.out.println("File avviato in data: " + giorno);
        File oggetto = new File();

        oggetto.creaLista();

    }

    public void creaLista(){

        lista = new ArrayList<>();

        lista.add("Primo");
        lista.add("Secondo");
        lista.add("Terzo");
        lista.add("Quarto");
        lista.add("Quinto");

        for(int i = 0; i < lista.size(); i++){

            System.out.println(lista.get(i));
        }

    }
    
}
