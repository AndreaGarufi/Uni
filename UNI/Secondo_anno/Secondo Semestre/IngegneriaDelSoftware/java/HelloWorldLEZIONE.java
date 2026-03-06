import java.time.LocalDate;

public class HelloWorldLEZIONE {
    private static int valore = 0;
    private int contatore;
    private String saluto="Ciao";
    private static LocalDate data= LocalDate.now();

    public static void main(String[] args){
        System.out.println("Hello World.");

        HelloWorldLEZIONE h=new HelloWorldLEZIONE();
        h.stampe();
    }

    private void stampe(){
        valore++;
        System.out.println(data);
        //IO.println("ciao ciao");
        System.out.println("valore : " +valore);
        System.out.println(saluto + ", Ingegneria del software.");
        contatore++;
        System.out.println("contatore: " +contatore);
       /**  HelloWorld hello;
        *hello= new HelloWorld(); lo tolgo perchè l'ho creato nel main
        *hello.contatore++;
        *System.out.println("contatore: " +hello.contatore);
        *HelloWorld hello1;
        *hello1= new HelloWorld();
        *System.out.println(hello1.contatore);
        */
    }
}
