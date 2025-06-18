# Descrição

Este é um jogo de Batalha Naval simples implementado em C++, onde o jogador deve atacar as posições de um tabuleiro inimigo para tentar afundar todos os navios. 
O jogo consiste em adivinhar as posições dos navios inimigos no tabuleiro, utilizando coordenadas de linha e coluna. A cada ataque, o jogador é informado se acertou ou não um navio.

# Estrutura

~ indica água (posições vazias).

N indica a presença de um navio.

X indica que o navio foi atingido.

O indica que o ataque foi na água.

# Funções

inicializarTabuleiro(): Inicializa um tabuleiro com água (~) em todas as posições.

exibirTabuleiro(): Exibe o tabuleiro de forma formatada para o jogador.

colocarNavio(): Coloca navios de forma aleatória no tabuleiro inimigo, garantindo que eles não se sobreponham.

atacar(): Executa um ataque nas coordenadas fornecidas e marca o tabuleiro com a letra correspondente (X ou O).

# Divirta-se...
