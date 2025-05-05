/*
 * Programa que escreve JAVA no terminal. Implementação exagerada e maluca para
 * fins de exercício.
 */


class Letra {
  private char letra;
  private int tamanho;
  private String[] mapa;

  public Letra() {};

  public Letra(int tamanho, char letra, String[] mapa) {
    this.letra = letra;
    this.tamanho = tamanho;
    this.mapa = mapa;
  }

  public char GetLetra() {
    return this.letra;
  }

  public String[] GetMapa() {
    return this.mapa;
  }
}


class Palavra {
  private int tamanho;
  private Letra[] letras;

  public Palavra(int tamanho, Letra... letras) {
    this.tamanho = tamanho;
    this.letras = letras;
  }

  public void AddLetra(Letra letra) {
    Letra[] nova_letras = new Letra[letras.length+1];

    System.arraycopy(letras, 0, nova_letras, 0, letras.length);
    nova_letras[letras.length+1] = letra;
    
    letras = nova_letras;
  }

  public void RmLetra(Letra letra) {
   Letra[] nova_letras = new Letra[letras.length-1];

    int i = 0;
    do {
      if (letra == letras[i]) {
        System.out.println("RAPAZ 1");

        letras[i] = null;
        System.arraycopy(letras, 0, nova_letras, 0, i);
        System.arraycopy(letras, i+1, nova_letras, i, letras.length -(i+1));
      }
      i++;
    }
    while (i < letras.length && letra != letras[i]);

    letras = nova_letras;
  }

  public void RmLetra(int index) {
    Letra[] nova_letras = new Letra[letras.length-1];
    letras[index] = null;

    System.out.println("RAPAZ 2");
    System.arraycopy(letras, 0, nova_letras, 0, index);
    System.arraycopy(letras, index+1, nova_letras, index, letras.length -(index+1));
    letras = nova_letras;
  }

  public void Imprimir() {
    for (int i_linha = 0; i_linha < tamanho; i_linha++) {
      for (int i_letra = 0; i_letra < letras.length; i_letra++) {
        String linha_out = letras[i_letra].GetMapa()[i_linha].replace(" ", "");
        
        for (int i_char = 0; i_char < linha_out.length(); i_char++) {
          char out = (linha_out.charAt(i_char) == '1') ? letras[i_letra].GetLetra() : ' ';
          System.out.print(out);
        }
        System.out.print("  ");
      }
      System.out.println();
    }
  }
}


public class Java {
  public static void main(String[] args) {

    Letra J = new Letra(4, 'J', new String[]
        { "0 0 0 1 1",
          "0 0 0 0 1",
          "1 0 0 0 1",
          "0 1 1 1 0" }
    );

    Letra A = new Letra(4, 'A', new String[]
        { "0 0 0 1 0 0 0",
          "0 0 1 0 1 0 0",
            "0 1 1 1 1 1 0",
          "1 0 0 0 0 0 1" }
    );

    Letra V = new Letra(4, 'V', new String[]
        { "1 0 0 0 0 0 1",
          "0 1 0 0 0 1 0",
          "0 0 1 0 1 0 0",
          "0 0 0 1 0 0 0" }
    );

    Letra L = new Letra();
    Letra I = new Letra();

    Palavra java = new Palavra(4, J, A, V, A, L, I);

    java.Imprimir();
    java.RmLetra('L');
    java.Imprimir();
    java.RmLetra(4);

    java.Imprimir();
   }
}
