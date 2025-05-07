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
    nova_letras[letras.length] = letra;
    
    this.letras = nova_letras;
  }

  public void InsLetra(Letra letra, int indice) {
    if (indice >= letras.length) return;

    int inserido = 0;
    Letra[] nova_letras = new Letra[letras.length+1];

    for (int i = 0; i < letras.length + 1; i++) {
      if (indice == i) {
        nova_letras[i] = letra;
        inserido = 1;
      } else {
        nova_letras[i] = letras[i-inserido];
      }
    }

    this.letras = nova_letras;
  }

  public void RmLetra(Letra letra) {
    RmLetra(letra, letras.length);
  }

  public void RmLetra(Letra letra, int contagem) {
    if (letras.length == 0) return;

    int conta_letra = 0;

    for (int i = 0; i < letras.length; i++) {
      if (letras[i] != letra || contagem == 0) {
        letras[i-conta_letra] = letras[i];
      } else {
        conta_letra++;
        contagem--;
      } 
    }

    Letra[] nova_letras = new Letra[letras.length - conta_letra];
    System.arraycopy(letras, 0, nova_letras, 0, letras.length - conta_letra);
    this.letras = nova_letras;
  }

  public void RmLetra(int indice) {
    if (letras.length < indice - 1) return;

    Letra[] nova_letras = new Letra[letras.length-1];

    System.arraycopy(letras, 0, nova_letras, 0, indice);
    System.arraycopy(letras, indice+1, nova_letras, indice, letras.length -(indice+1));
    
    this.letras = nova_letras;
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

    Letra J = new Letra(4, 'J', new String[] {
      "0 0 0 1 1",
      "0 0 0 0 1",
      "1 0 0 0 1",
      "0 1 1 1 0" });

    Letra A = new Letra(4, 'A', new String[] {
      "0 0 0 1 0 0 0",
      "0 0 1 0 1 0 0",
      "0 1 1 1 1 1 0",
      "1 0 0 0 0 0 1" });

    Letra V = new Letra(4, 'V', new String[] {
      "1 0 0 0 0 0 1",
      "0 1 0 0 0 1 0",
      "0 0 1 0 1 0 0",
      "0 0 0 1 0 0 0" });

    Letra L = new Letra(4, 'L', new String[] {
      "1 0 0",
      "1 0 0",
      "1 0 0",
      "1 1 1" });

    Letra I = new Letra(4, 'I', new String[] {
      "1 1 1",
      "0 1 0",
      "0 1 0",
      "1 1 1"}
    );

    Letra N = new Letra(4, 'N', new String[] {
      "1 0 0 1",
      "1 1 0 1",
      "1 0 1 1",
      "1 0 0 1" }
    );

    Letra W = new Letra(4, 'W', new String[] {
      "1 0 0 0 0 0 1",
      "1 0 0 1 0 0 1",
      "0 1 0 1 0 1 0",
      "0 0 1 0 1 0 0" });

    Palavra java = new Palavra(4, J, A, V, A, L, L, I);

    java.Imprimir();
    java.RmLetra(L);
    java.Imprimir();

    java.RmLetra(4);
    java.RmLetra(V, 1);
    java.AddLetra(N);
    java.InsLetra(W, 2);

    java.Imprimir();
   }
}
