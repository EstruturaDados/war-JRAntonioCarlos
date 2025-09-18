// ============================================================================
//         PROJETO WAR ESTRUTURADO - DESAFIO DE CÓDIGO
// ============================================================================
//        
// ============================================================================
//
// OBJETIVOS:
// - Modularizar completamente o código em funções especializadas.
// - Implementar um sistema de missões para um jogador.
// - Criar uma função para verificar se a missão foi cumprida.
// - Utilizar passagem por referência (ponteiros) para modificar dados e
//   passagem por valor/referência constante (const) para apenas ler.
// - Foco em: Design de software, modularização, const correctness, lógica de jogo.
//
// ============================================================================

// Inclusão das bibliotecas padrão necessárias para entrada/saída, alocação de memória, manipulação de strings e tempo.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// --- Constantes Globais ---
// Definem valores fixos para o número de territórios, missões e tamanho máximo de strings, facilitando a manutenção.
#define MAX_TERRITORIO 5
#define MAX_MISSOES 10
#define MAX_STRING 50

// --- Estrutura de Dados ---
// Define a estrutura para um território, contendo seu nome, a cor do exército que o domina e o número de tropas.
struct Territorio{
    char nomedoTerritorio[50];
    char cordoexercito[20];
    int numero_de_tropas;
};
// FUNÇÃO LIMPAR O BUFFER DE ENTRADA
void LimparBufferDeEntrada(){
    int c;
    while ((c = getchar()) != '\n'&& c != EOF);
 
    }
// --- Protótipos das Funções ---
// Declarações antecipadas de todas as funções que serão usadas no programa, organizadas por categoria.
// Funções de setup e gerenciamento de memória:
struct Territorio* alocarMapa(int quantidade);
void liberarMemoria(struct Territorio* mapa);
// Funções de interface com o usuário:
// Funções de lógica principal do jogo:
int sortearMissao(int maxMissoes);
// Função utilitária:

// --- Função Principal (main) ---
// Função principal que orquestra o fluxo do jogo, chamando as outras funções em ordem.
int main() {
    // 1. Configuração Inicial (Setup):
    // - Define o locale para português.
    // - Inicializa a semente para geração de números aleatórios com base no tempo atual.
    // - Aloca a memória para o mapa do mundo e verifica se a alocação foi bem-sucedida.
    // - Preenche os territórios com seus dados iniciais (tropas, donos, etc.).
    // - Define a cor do jogador e sorteia sua missão secreta.
struct Territorio* mapa = alocarMapa(MAX_TERRITORIO);
int missaoID = sortearMissao(MAX_MISSOES);
char corTropa[MAX_STRING] = "Vermelho";
    // 2. Cadastro dos territórios (executa uma vez)
    struct Territorio territorios[5];
    printf("\nVamos cadastrar os 5 territórios iniciais\n");
    for (int i = 0; i < 5; i++) {
        printf("Digite o nome do território %d: ", i+1);
        fgets(territorios[i].nomedoTerritorio, sizeof(territorios[i].nomedoTerritorio), stdin);
        territorios[i].nomedoTerritorio[strcspn(territorios[i].nomedoTerritorio, "\n")] = 0;
        printf("Digite a cor do exército do território %d: ", i+1);
        fgets(territorios[i].cordoexercito, sizeof(territorios[i].cordoexercito), stdin);
        territorios[i].cordoexercito[strcspn(territorios[i].cordoexercito, "\n")] = 0;
        printf("Digite o número de tropas do território %d: ", i+1);
        scanf("%d", &territorios[i].numero_de_tropas);
        LimparBufferDeEntrada();
    }
    // Exibe os territórios cadastrados
    for (int i = 0; i < 5; i++) {
        printf("territorio%d: %s, cor do exercito: %s, numero de tropas: %d\n",
            i+1, territorios[i].nomedoTerritorio, territorios[i].cordoexercito, territorios[i].numero_de_tropas);
    }
    //fase de ataque
    int origem, destino;
    printf("\nFase de Ataque\n");
    printf("Escolha o território atacante (1-5): ");
    scanf("%d", &origem);
    printf("Escolha o território defensor (1-5): ");
    scanf("%d", &destino);
   //resulto doda batalha
    int atacante = origem;
    int defensor = destino;
   printf("O território %s atacou o território %s\n", territorios[atacante-1].nomedoTerritorio, territorios[defensor-1].nomedoTerritorio);
   if(rand()%2==0){
    printf("O território %s venceu a batalha!\n", territorios[atacante-1].nomedoTerritorio);
    territorios[defensor-1].numero_de_tropas--;
   } else {
    printf("O território %s venceu a batalha!\n", territorios[defensor-1].nomedoTerritorio);
    territorios[atacante-1].numero_de_tropas--;
   }
   //atualiza as 5 tropas
   for (int i = 0; i < 5; i++) {
    if(territorios[i].numero_de_tropas<0) territorios[i].numero_de_tropas=0;
   }
   // Exibe os territórios atualizados
    for (int i = 0; i < 5; i++) {
        printf("territorio%d: %s, cor do exercito: %s, numero de tropas: %d\n",
            i+1, territorios[i].nomedoTerritorio, territorios[i].cordoexercito, territorios[i].numero_de_tropas);
    }
    //proximo passo
    printf("pressione ENTER para o próximo turno...");
    getchar();
            
    // 3. Limpeza:
    // - Ao final do jogo, libera a memória alocada para o mapa para evitar vazamentos de memória.
    liberarMemoria(mapa);
    return 0;
}
// --- Implementação das Funções ---
// Implementações básicas (stubs) para permitir compilação
struct Territorio* alocarMapa(int quantidade) {
    // Apenas aloca memória para o vetor de territórios
    return (struct Territorio*)calloc(quantidade, sizeof(struct Territorio));
}

void liberarMemoria(struct Territorio* mapa) {
    // Libera a memória alocada
    free(mapa);
}

int sortearMissao(int maxMissoes) {
    // Retorna sempre 0 como missão sorteada (stub)
    return 0;
}

// alocarMapa():
// Aloca dinamicamente a memória para o vetor de territórios usando calloc.
// Retorna um ponteiro para a memória alocada ou NULL em caso de falha.

// inicializarTerritorios():
// Preenche os dados iniciais de cada território no mapa (nome, cor do exército, número de tropas).
// Esta função modifica o mapa passado por referência (ponteiro).

// liberarMemoria():
// Libera a memória previamente alocada para o mapa usando free.

// exibirMenuPrincipal():
// Imprime na tela o menu de ações disponíveis para o jogador.

// exibirMapa():
// Mostra o estado atual de todos os territórios no mapa, formatado como uma tabela.
// Usa 'const' para garantir que a função apenas leia os dados do mapa, sem modificá-los.

// exibirMissao():
// Exibe a descrição da missão atual do jogador com base no ID da missão sorteada.

// faseDeAtaque():
// Gerencia a interface para a ação de ataque, solicitando ao jogador os territórios de origem e destino.
// Chama a função simularAtaque() para executar a lógica da batalha.

// simularAtaque():
// Executa a lógica de uma batalha entre dois territórios.
// Realiza validações, rola os dados, compara os resultados e atualiza o número de tropas.
// Se um território for conquistado, atualiza seu dono e move uma tropa.

// sortearMissao():
// Sorteia e retorna um ID de missão aleatório para o jogador.

// verificarVitoria():
// Verifica se o jogador cumpriu os requisitos de sua missão atual.
// Implementa a lógica para cada tipo de missão (destruir um exército ou conquistar um número de territórios).
// Retorna 1 (verdadeiro) se a missão foi cumprida, e 0 (falso) caso contrário.

// limparBufferEntrada():
// Função utilitária para limpar o buffer de entrada do teclado (stdin), evitando problemas com leituras consecutivas de scanf e getchar.
