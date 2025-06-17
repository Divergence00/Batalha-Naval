#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int TAMANHO_TABULEIRO = 10;
char tabuleiroJogador[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
char tabuleiroInimigo[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

// Fun��o para inicializar o tabuleiro com �gua
void inicializarTabuleiro(char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = '~';  // Marca "�gua"
        }
    }
}

// Fun��o para exibir o tabuleiro
void exibirTabuleiro(char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    cout << "  ";
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        cout << i << " ";
    }
    cout << endl;

    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        cout << i << " ";
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            cout << tabuleiro[i][j] << " ";
        }
        cout << endl;
    }
}

// Fun��o para colocar um navio no tabuleiro
void colocarNavio(char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int tamanho) {
    bool navioColocado = false;
    int x, y, direcao;

    while (!navioColocado) {
        // Gerando uma posi��o aleat�ria para o navio
        x = rand() % TAMANHO_TABULEIRO;
        y = rand() % TAMANHO_TABULEIRO;
        direcao = rand() % 2; // 0 para horizontal, 1 para vertical

        // Verificando se o navio cabe na posi��o escolhida
        bool podeColocar = true;
        if (direcao == 0) { // Horizontal
            if (y + tamanho > TAMANHO_TABULEIRO) {
                podeColocar = false;
            } else {
                for (int i = 0; i < tamanho; i++) {
                    if (tabuleiro[x][y + i] != '~') {
                        podeColocar = false;
                        break;
                    }
                }
            }
        } else { // Vertical
            if (x + tamanho > TAMANHO_TABULEIRO) {
                podeColocar = false;
            } else {
                for (int i = 0; i < tamanho; i++) {
                    if (tabuleiro[x + i][y] != '~') {
                        podeColocar = false;
                        break;
                    }
                }
            }
        }

        // Se puder colocar o navio, coloca
        if (podeColocar) {
            for (int i = 0; i < tamanho; i++) {
                if (direcao == 0) {
                    tabuleiro[x][y + i] = 'N'; // Navio horizontal
                } else {
                    tabuleiro[x + i][y] = 'N'; // Navio vertical
                }
            }
            navioColocado = true;
        }
    }
}

// Fun��o para verificar se o jogador acertou
bool atacar(char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int x, int y) {
    if (tabuleiro[x][y] == 'N') {
        tabuleiro[x][y] = 'X';  // Marca o navio como atingido
        return true;
    } else if (tabuleiro[x][y] == '~') {
        tabuleiro[x][y] = 'O';  // Marca �gua
        return false;
    }
    return false;
}

// Fun��o principal
int main() {
    srand(time(0)); // Gerador de n�meros aleat�rios

    // Inicializa os tabuleiros
    inicializarTabuleiro(tabuleiroJogador);
    inicializarTabuleiro(tabuleiroInimigo);

    // Coloca os navios no tabuleiro inimigo
    for (int i = 1; i <= 4; i++) { // Coloca 4 navios de tamanhos 1 a 4
        colocarNavio(tabuleiroInimigo, i);
    }

    int acertos = 0;
    int tentativas = 0;
    int x, y;
    bool jogoAtivo = true;

    // Loop principal do jogo
    while (jogoAtivo) {
        system("cls");
        cout << "Tabuleiro do Jogador (Apenas Acertos/�gua):" << endl;
        exibirTabuleiro(tabuleiroJogador);

        cout << "\nTabuleiro Inimigo (Adivinha as posi��es dos navios):" << endl;
        exibirTabuleiro(tabuleiroInimigo);

        // Entrada do jogador
        cout << "\nDigite as coordenadas para atacar (linha coluna): ";
        cin >> x >> y;

        if (x < 0 || x >= TAMANHO_TABULEIRO || y < 0 || y >= TAMANHO_TABULEIRO) {
            cout << "Coordenadas inv�lidas. Tente novamente." << endl;
            continue;
        }

        // Atacar
        bool acerto = atacar(tabuleiroInimigo, x, y);
        if (acerto) {
            cout << "Acertou um navio!" << endl;
            acertos++;
        } else {
            cout << "�gua!" << endl;
        }
        tentativas++;

        // Verifica se o jogo terminou
        if (acertos == 10) {
            cout << "\nParab�ns, voc� afundou todos os navios inimigos!" << endl;
            jogoAtivo = false;
        }

        // Limite de tentativas
        if (tentativas >= 50) {
            cout << "\nVoc� atingiu o limite de tentativas. Jogo terminado!" << endl;
            jogoAtivo = false;
        }

        cout << "\nPressione qualquer tecla para continuar...";
        cin.ignore();
        cin.get();
    }

    return 0;
}

