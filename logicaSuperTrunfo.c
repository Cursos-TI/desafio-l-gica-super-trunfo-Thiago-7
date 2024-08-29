#include <stdio.h>
#include <string.h>

// Definição da estrutura da carta
struct Carta {
    char estado[3]; 
    char codigo[4];
    char nome_cidade[50];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
};

// Função para verificar se o código da carta já existe
int verificarCodigoExistente(struct Carta cartas[], int num_cartas, char codigo[]) {
    for (int i = 0; i < num_cartas; i++) {
        if (strcmp(cartas[i].codigo, codigo) == 0) {
            return i; 
        }
    }
    return -1; 
}

// Verificar se a cidade já existe no mesmo estado
int verificarCidadeExistente(struct Carta cartas[], int num_cartas, char nome_cidade[], char estado[]) {
    for (int i = 0; i < num_cartas; i++) {
        if (strcmp(cartas[i].estado, estado) == 0 && strcmp(cartas[i].nome_cidade, nome_cidade) == 0) {
            return 1;
        }
    }
    return 0;
}

// Editar uma carta existente
void editarCarta(struct Carta *carta) {
    printf("Editando carta de código %s:\n", carta->codigo);
    printf("Digite o novo estado (ex: SC, SP): ");
    scanf("%2s", carta->estado);

    printf("Digite o novo nome da cidade: ");
    scanf(" %[^\n]%*c", carta->nome_cidade);

    printf("Digite a nova população: ");
    scanf("%d", &carta->populacao);

    printf("Digite a nova área em km²: ");
    scanf("%f", &carta->area);

    printf("Digite o novo PIB: ");
    scanf("%f", &carta->pib);

    printf("Digite o novo número de pontos turísticos: ");
    scanf("%d", &carta->pontos_turisticos);

    printf("\nCarta editada com sucesso!\n\n");
}

// Cadastrar uma nova carta
void cadastrarCarta(struct Carta cartas[], int *num_cartas) {
    char codigo[4];
    char nome_cidade[50];
    char estado[3];
    
    printf("Digite o código da carta (por exemplo, A01): ");
    scanf("%s", codigo);

    int index = verificarCodigoExistente(cartas, *num_cartas, codigo);

    if (index != -1) {
        printf("Código de carta já existente. Deseja editar a carta existente? (s/n): ");
        char opcao;
        scanf(" %c", &opcao);
        if (opcao == 's' || opcao == 'S') {
            editarCarta(&cartas[index]);
        } else {
            printf("Operação cancelada.\n\n");
        }
        return;
    }

    printf("Digite o estado (ex: SC, SP): ");
    scanf("%2s", estado);

    printf("Digite o nome da cidade: ");
    scanf(" %[^\n]%*c", nome_cidade);

    // Verifica se a cidade já existe no mesmo estado
    if (verificarCidadeExistente(cartas, *num_cartas, nome_cidade, estado)) {
        printf("Já existe uma cidade com esse nome no mesmo estado.\n");
        return;
    }

    // Cadastro da nova carta
    strcpy(cartas[*num_cartas].codigo, codigo);
    strcpy(cartas[*num_cartas].estado, estado);
    strcpy(cartas[*num_cartas].nome_cidade, nome_cidade);

    printf("Digite a população: ");
    scanf("%d", &cartas[*num_cartas].populacao);

    printf("Digite a área em km²: ");
    scanf("%f", &cartas[*num_cartas].area);

    printf("Digite o PIB: ");
    scanf("%f", &cartas[*num_cartas].pib);

    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &cartas[*num_cartas].pontos_turisticos);

    (*num_cartas)++;
    printf("\nCarta cadastrada com sucesso!\n\n");
}

// exibir os dados de uma carta
void exibirCarta(struct Carta carta) {
    printf("Informações da Carta:\n");
    printf("Estado: %s\n", carta.estado);
    printf("Código: %s\n", carta.codigo);
    printf("Nome da Cidade: %s\n", carta.nome_cidade);
    printf("População: %d\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: %.2f\n", carta.pib);
    printf("Pontos Turísticos: %d\n", carta.pontos_turisticos);
}


void compararCartas(struct Carta carta1, struct Carta carta2, int atributo) {
    switch (atributo) {
        case 1: // Comparar população
            if (carta1.populacao > carta2.populacao)
                printf("A carta %s venceu na comparação de população!\n", carta1.codigo);
            else if (carta1.populacao < carta2.populacao)
                printf("A carta %s venceu na comparação de população!\n", carta2.codigo);
            else
                printf("Empate na comparação de população!\n");
            break;

        case 2: // Comparar área
            if (carta1.area > carta2.area)
                printf("A carta %s venceu na comparação de área!\n", carta1.codigo);
            else if (carta1.area < carta2.area)
                printf("A carta %s venceu na comparação de área!\n", carta2.codigo);
            else
                printf("Empate na comparação de área!\n");
            break;

        case 3: // Comparar PIB
            if (carta1.pib > carta2.pib)
                printf("A carta %s venceu na comparação de PIB!\n", carta1.codigo);
            else if (carta1.pib < carta2.pib)
                printf("A carta %s venceu na comparação de PIB!\n", carta2.codigo);
            else
                printf("Empate na comparação de PIB!\n");
            break;

        case 4: // Comparar número de pontos turísticos
            if (carta1.pontos_turisticos > carta2.pontos_turisticos)
                printf("A carta %s venceu na comparação de pontos turísticos!\n", carta1.codigo);
            else if (carta1.pontos_turisticos < carta2.pontos_turisticos)
                printf("A carta %s venceu na comparação de pontos turísticos!\n", carta2.codigo);
            else
                printf("Empate na comparação de pontos turísticos!\n");
            break;

        default:
            printf("Atributo inválido!\n");
            break;
    }
}

int main() {
    struct Carta cartas[32];
    int i, num_cartas = 0;

    printf("Cadastro de cartas para o jogo Super Trunfo - Países\n");

    // Cadastro das cartas
    for (i = 0; i < 32; i++) {
        printf("Cadastro da carta %d de 32\n", num_cartas + 1);
        cadastrarCarta(cartas, &num_cartas);

        char opcao;
        printf("Deseja cadastrar outra carta? (s/n): ");
        scanf(" %c", &opcao);

        if (opcao == 'n' || opcao == 'N') {
            break;
        }
    }

    // Exibição das cartas cadastradas
    printf("\nExibindo todas as cartas cadastradas:\n");
    for (i = 0; i < num_cartas; i++) {
        exibirCarta(cartas[i]);
        printf("\n");
    }

    // Loop para comparações
    while (1) {
        int carta1, carta2, atributo;
        printf("Selecione duas cartas para comparação (índices de 0 a %d):\n", num_cartas - 1);
        printf("Carta 1: ");
        scanf("%d", &carta1);
        printf("Carta 2: ");
        scanf("%d", &carta2);

        if (carta1 < 0 || carta1 >= num_cartas || carta2 < 0 || carta2 >= num_cartas) {
            printf("Índices inválidos!\n");
            continue;
        }

        printf("Escolha o atributo para comparação:\n");
        printf("1. População\n");
        printf("2. Área\n");
        printf("3. PIB\n");
        printf("4. Pontos Turísticos\n");
        printf("Opção: ");
        scanf("%d", &atributo);

        // Comparação das cartas
        compararCartas(cartas[carta1], cartas[carta2], atributo);

        char continuar;
        printf("Deseja fazer outra comparação? (s/n): ");
        scanf(" %c", &continuar);

        if (continuar == 'n' || continuar == 'N') {
            break;
        }
    }

    printf("Obrigado por jogar!\n");
    return 0;
}
