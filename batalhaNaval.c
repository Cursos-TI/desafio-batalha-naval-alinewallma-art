#include <stdio.h>

/* APENAS PARA REGISTRO QUE FOI REALIZADO
// Desafio Batalha Naval - MateCheck  - Nível Novato - Posicionamento dos Navios

int main() {
    int tabuleiro [5][5];               // Declarand uma matriz bidimensional para representar o tabuleiro.

    for (int i = 0; i < 5; i ++) {
        for (int j = 0 ; j < 5; j++) {
            tabuleiro[i][j] = 0;
        }
    }                                  // Inicializa todas as posições com 0

    int tamanhoNavio = 3;              // Tamanho fixo dos navios: 3 posições

    // Posicionamento dos navios 
    // Posicionando dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Navo 1 na horizontal
    int linhaHorizontal = 2;
    int colunaInicialHorizontal =1;

    // Navio 2 na vertical
    int colunaVertical = 4;
    int colunaHorizontal = 0;
   
    //Utilize `printf` para exibir as coordenadas de cada parte dos navios.
    printf("Coordenadas das partes dos navios:\n\n");

    // Posiciona o navio horizontal
    printf("Navio horizontal:\n");
    for (int i = 0; i < tamanhoNavio; i++) {
        int linha = linhaHorizontal;
        int coluna = colunaInicialHorizontal + i;
        tabuleiro[linha][coluna] = 3;  // marca navio
        printf("Parte %d -> Linha: %d, Coluna: %d\n", i + 1, linha, coluna);
    }

    // Posiciona o navio vertical
    printf("\nNavio vertical:\n");
    for (int i = 0; i < tamanhoNavio; i++) {
        int linha = linhaInicialVertical + i;
        int coluna = colunaVertical;
        tabuleiro[linha][coluna] = 3;  // marca navio
        printf("Parte %d -> Linha: %d, Coluna: %d\n", i + 1, linha, coluna);
    }

    return 0;
} */

/* APENAS PARA REGISTRO QUE FOI REALIZADO
// Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    
int main() {
    // Expanda o tabuleiro para uma matriz 10x10.
    int tabuleiro[10][10];

    // Inicializa o tabuleiro com 0 (zero)
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    int tamanhoNavio = 3;

    // Posicionamento dos 4 navios:
    // 2 navios tradicionais (horizontal e vertical)
    // 2 navios diagonais
    
    // Navio 1 — Horizontal
    int linhaH = 2, colunaH = 3;
    for (int i = 0; i < tamanhoNavio; i++) {
        tabuleiro[linhaH][colunaH + i] = 3;
    }

    // Navio 2 — Vertical
    int linhaV = 5, colunaV = 7;
    for (int i = 0; i < tamanhoNavio; i++) {
        tabuleiro[linhaV + i][colunaV] = 3;
    }

    // Navio 3 — Diagonal Principal (↘)
    int linhaD1 = 1, colunaD1 = 1;
    for (int i = 0; i < tamanhoNavio; i++) {
        tabuleiro[linhaD1 + i][colunaD1 + i] = 3;
    }

    // Navio 4 — Diagonal Secundária (↙)
    int linhaD2 = 0, colunaD2 = 9;
    for (int i = 0; i < tamanhoNavio; i++) {
        tabuleiro[linhaD2 + i][colunaD2 - i] = 3;
    }

    // Exibindo o tabuleiro completo no console.
    // Mostrando 0 para água e 3 para parte dos navios.

    printf("\n=== TABULEIRO COMPLETO ===\n\n");

    printf("   ");
    for (int c = 0; c < 10; c++) printf("%d ", c);
    printf("\n");

    for (int i = 0; i < 10; i++) {
        printf("%d  ", i);
        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
*/

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Criado matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Utilizando estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.

#define TAM 10                                        // tamanho do tabuleiro 10x10
#define NAV 3                                         // tamanho dos navios (3)
#define HSIZE 5                                       // tamanho das matrizes de habilidade (5x5)
#define WATER 0
#define SHIP 3
#define EFFECT 5
#define SHIP_EFFECT 8                                // usado quando efeito e navio se sobrepõem

// Função para imprimir o tabuleiro com legenda
void imprimirTabuleiro(int tab[TAM][TAM]) {
    printf("\n=== TABULEIRO (0=água, 3=navio, 5=efeito, 8=navio+efeito) ===\n\n");
    printf("   ");
    for (int c = 0; c < TAM; c++) printf("%d ", c);
    printf("\n");
    for (int r = 0; r < TAM; r++) {
        printf("%d  ", r);
        for (int c = 0; c < TAM; c++) {
            printf("%d ", tab[r][c]);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    int tabuleiro[TAM][TAM];

    // Inicializando tabuleiro com água 0 (zero)
    for (int r = 0; r < TAM; r++)
        for (int c = 0; c < TAM; c++)
            tabuleiro[r][c] = WATER;

    // Posicionando os navios (mantém exemplo do nível anterior)
    // Navio 1 — Horizontal (linha 2, col 3..5)
    int linhaH = 2, colunaH = 3;
    for (int i = 0; i < NAV; i++)
        tabuleiro[linhaH][colunaH + i] = SHIP;

    // Navio 2 — Vertical (linha 5..7, col 7)
    int linhaV = 5, colunaV = 7;
    for (int i = 0; i < NAV; i++)
        tabuleiro[linhaV + i][colunaV] = SHIP;

    // Navio 3 — Diagonal principal (↘) (ex: 1,1 -> 3 posições)
    int linhaD1 = 1, colunaD1 = 1;
    for (int i = 0; i < NAV; i++)
        tabuleiro[linhaD1 + i][colunaD1 + i] = SHIP;

    // Navio 4 — Diagonal secundária (↙) (ex: 0,9 -> 3 posições)
    int linhaD2 = 0, colunaD2 = 9;
    for (int i = 0; i < NAV; i++)
        tabuleiro[linhaD2 + i][colunaD2 - i] = SHIP;

    // Criando dinamicamente as matrizes de habilidade (HSIZE x HSIZE)
    int cone[HSIZE][HSIZE];
    int cruz[HSIZE][HSIZE];
    int octaedro[HSIZE][HSIZE];

    int center = HSIZE / 2; // por ex. para HSIZE=5, center = 2

    // Preencher CONE (ponta no topo, abre para baixo)
    // Para cada linha r (0..HSIZE-1), a "largura" do cone cresce com r:
    // colStart = center - r; colEnd = center + r;
    for (int r = 0; r < HSIZE; r++) {
        for (int c = 0; c < HSIZE; c++) {
            int colStart = center - r;
            int colEnd = center + r;
            // usa condicionais para definir 1 dentro do cone e 0 fora
            if (c >= colStart && c <= colEnd)
                cone[r][c] = 1;
            else
                cone[r][c] = 0;
        }
    }

    // Preencher CRUZ (linha e coluna central)
    // Marca 1 quando r == center (linha central) ou c == center (coluna central)
    for (int r = 0; r < HSIZE; r++) {
        for (int c = 0; c < HSIZE; c++) {
            if (r == center || c == center)
                cruz[r][c] = 1;
            else
                cruz[r][c] = 0;
        }
    }

    // Preencher OCTAEDRO (vista frontal -> losango / diamante)
    // Pontos com Manhattan distance <= center formam o diamante
    // i.e., abs(r-center) + abs(c-center) <= center
    for (int r = 0; r < HSIZE; r++) {
        for (int c = 0; c < HSIZE; c++) {
            int manhattan = (r > center ? r - center : center - r) + (c > center ? c - center : center - c);
            if (manhattan <= center)
                octaedro[r][c] = 1;
            else
                octaedro[r][c] = 0;
        }
    }

    // Definindo pontos de origem (centro) das habilidades no tabuleiro
    int origemConeR = 3, origemConeC = 2;    // exemplo: cone com origem em (3,2)
    int origemCruzR = 6, origemCruzC = 6;    // exemplo: cruz com origem em (6,6)
    int origemOctR  = 4, origemOctC  = 4;    // exemplo: octaedro com origem em (4,4)

    // Sobrepondo cada matriz no tabuleiro

    // Função inline: aplica uma matriz de habilidade ao tabuleiro
    for (int r = 0; r < HSIZE; r++) {
        for (int c = 0; c < HSIZE; c++) {
            if (cone[r][c] == 1) {
                int tr = origemConeR - center + r;
                int tc = origemConeC - center + c;
                if (tr >= 0 && tr < TAM && tc >= 0 && tc < TAM) {
                    if (tabuleiro[tr][tc] == SHIP)
                        tabuleiro[tr][tc] = SHIP_EFFECT;     // navio afetado
                    else if (tabuleiro[tr][tc] == WATER)
                        tabuleiro[tr][tc] = EFFECT;         // efeito sobre água
                }
            }
        }
    }

    for (int r = 0; r < HSIZE; r++) {
        for (int c = 0; c < HSIZE; c++) {
            if (cruz[r][c] == 1) {
                int tr = origemCruzR - center + r;
                int tc = origemCruzC - center + c;
                if (tr >= 0 && tr < TAM && tc >= 0 && tc < TAM) {
                    if (tabuleiro[tr][tc] == SHIP)
                        tabuleiro[tr][tc] = SHIP_EFFECT;
                    else if (tabuleiro[tr][tc] == WATER)
                        tabuleiro[tr][tc] = EFFECT;
                }
            }
        }
    }

    for (int r = 0; r < HSIZE; r++) {
        for (int c = 0; c < HSIZE; c++) {
            if (octaedro[r][c] == 1) {
                int tr = origemOctR - center + r;
                int tc = origemOctC - center + c;
                if (tr >= 0 && tr < TAM && tc >= 0 && tc < TAM) {
                    if (tabuleiro[tr][tc] == SHIP)
                        tabuleiro[tr][tc] = SHIP_EFFECT;
                    else if (tabuleiro[tr][tc] == WATER)
                        tabuleiro[tr][tc] = EFFECT;
                }
            }
        }
    }

    // Exibindo o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas
    imprimirTabuleiro(tabuleiro);

    return 0;
}

