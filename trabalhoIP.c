#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define SELETOR_PAÍS 26
#define LIMITOR_JOGADOR 26

typedef struct {
    char nome[50]; //nome do jogador
    char posicao[6]; //"GOL", "ZAG", "MEI", "ATA" ou "pais"
    int habilidade;
    int energia;
    int estado; //0 para em campo, 1 no banco e 2 lesionado
} jogador;

void escolher_jogadores(int selecao, int formacao, jogador copa[4][27], char posicao[4]);

void inicializar_dados(jogador copa[4][27]) {
    // brasil = 0
    copa[0][0] = (jogador){"Alisson Becker", "GOL", 86, 100, 1};
    copa[0][1] = (jogador){"Weverton Pereira", "GOL", 78, 100, 1};
    copa[0][2] = (jogador){"Ederson Santana", "GOL", 72, 100, 1};
    copa[0][3] = (jogador){"Gabriel Magalhães", "ZAG", 85, 100, 1};
    copa[0][4] = (jogador){"Marquinhos", "ZAG", 88, 100, 1};
    copa[0][5] = (jogador){"Alex Sandro", "ZAG", 77, 100, 1};
    copa[0][6] = (jogador){"Danilo Luiz", "ZAG", 83, 100, 1};
    copa[0][7] = (jogador){"Gleison Bremer", "ZAG", 83, 100, 1};
    copa[0][8] = (jogador){"Léo Pereira", "ZAG", 78, 100, 1};
    copa[0][9] = (jogador){"Douglas Santos", "ZAG", 80, 100, 1};
    copa[0][10] = (jogador){"Ibañez", "ZAG", 79, 100, 1};
    copa[0][11] = (jogador){"Éderson", "MEI", 81, 100, 1};
    copa[0][12] = (jogador){"Casemiro", "MEI", 85, 100, 1};
    copa[0][13] = (jogador){"Bruno Guimarães", "MEI", 88, 100, 1};
    copa[0][14] = (jogador){"Fabinho", "MEI", 83, 100, 1};
    copa[0][15] = (jogador){"Danilo", "MEI", 79, 100, 1};
    copa[0][16] = (jogador){"Lucas Paquetá", "MEI", 86, 100, 1};
    copa[0][17] = (jogador){"Vinicius Júnior", "ATA", 90, 100, 1};
    copa[0][18] = (jogador){"Matheus Cunha", "ATA", 84, 100, 1};
    copa[0][19] = (jogador){"Neymar", "ATA", 90, 100, 1};
    copa[0][20] = (jogador){"Raphinha", "ATA", 86, 100, 1};
    copa[0][21] = (jogador){"Endrick", "ATA", 88, 100, 1};
    copa[0][22] = (jogador){"Luiz Henrique", "ATA", 75, 100, 1};
    copa[0][23] = (jogador){"Gabriel Martinelli", "ATA", 86, 100, 1};
    copa[0][24] = (jogador){"Igor Thiago", "ATA", 78, 100, 1};
    copa[0][25] = (jogador){"Rayan", "ATA", 75, 100, 1};
    copa[0][26] = (jogador){"Brasil", "pais", -1, -1, -1};

    //alemanha = 1

    copa[1][0] = (jogador){"Manuel Neuer", "GOL", 86, 100, 1};
    copa[1][1] = (jogador){"Oliver Baumann", "GOL", 79, 100, 1};
    copa[1][2] = (jogador){"Alexander Nübel", "GOL", 79, 100, 1};
    copa[1][3] = (jogador){"Antonio Rüdiger", "ZAG", 87, 100, 1};
    copa[1][4] = (jogador){"Joshua Kimmich", "ZAG", 88, 100, 1};
    copa[1][5] = (jogador){"Jonathan Tah", "ZAG", 84, 100, 1};
    copa[1][6] = (jogador){"Nico Schlotterbeck", "ZAG", 83, 100, 1};
    copa[1][7] = (jogador){"Waldemar Anton", "ZAG", 80, 100, 1};
    copa[1][8] = (jogador){"David Raum", "ZAG", 81, 100, 1};
    copa[1][9] = (jogador){"Malick Thiaw", "ZAG", 80, 100, 1};
    copa[1][10] = (jogador){"Nathaniel Brown", "ZAG", 74, 100, 1};
    copa[1][11] = (jogador){"Jamal Musiala", "MEI", 90, 100, 1};
    copa[1][12] = (jogador){"Florian Wirtz", "MEI", 90, 100, 1};
    copa[1][13] = (jogador){"Leon Goretzka", "MEI", 83, 100, 1};
    copa[1][14] = (jogador){"Aleksandar Pavlović", "MEI", 82, 100, 1};
    copa[1][15] = (jogador){"Angelo Stiller", "MEI", 81, 100, 1};
    copa[1][16] = (jogador){"Pascal Groß", "MEI", 80, 100, 1};
    copa[1][17] = (jogador){"Felix Nmecha", "MEI", 79, 100, 1};
    copa[1][18] = (jogador){"Nadiem Amiri", "MEI", 78, 100, 1};
    copa[1][19] = (jogador){"Jamie Leweling", "MEI", 76, 100, 1};
    copa[1][20] = (jogador){"Assan Ouédraogo", "MEI", 75, 100, 1};
    copa[1][21] = (jogador){"Leroy Sané", "MEI", 86, 100, 1};
    copa[1][22] = (jogador){"Kai Havertz", "ATA", 87, 100, 1};
    copa[1][23] = (jogador){"Deniz Undav", "ATA", 82, 100, 1};
    copa[1][24] = (jogador){"Maximilian Beier", "ATA", 78, 100, 1};
    copa[1][25] = (jogador){"Nick Woltemade", "ATA", 76, 100, 1};
    copa[1][26] = (jogador){"Alemanha", "pais", -1, -1, -1};

    //França = 2

    copa[2][0] = (jogador){"Mike Maignan", "GOL", 88, 100, 1};
    copa[2][1] = (jogador){"Brice Samba", "GOL", 80, 100, 1};
    copa[2][2] = (jogador){"Robin Risser", "GOL", 73, 100, 1};
    copa[2][3] = (jogador){"William Saliba", "ZAG", 89, 100, 1};
    copa[2][4] = (jogador){"Theo Hernández", "ZAG", 87, 100, 1};
    copa[2][5] = (jogador){"Jules Koundé", "ZAG", 85, 100, 1};
    copa[2][6] = (jogador){"Ibrahima Konaté", "ZAG", 84, 100, 1};
    copa[2][7] = (jogador){"Dayot Upamecano", "ZAG", 83, 100, 1};
    copa[2][8] = (jogador){"Lucas Hernández", "ZAG", 82, 100, 1};
    copa[2][9] = (jogador){"Lucas Digne", "ZAG", 80, 100, 1};
    copa[2][10] = (jogador){"Malo Gusto", "ZAG", 81, 100, 1};
    copa[2][11] = (jogador){"Maxence Lacroix", "ZAG", 79, 100, 1};
    copa[2][12] = (jogador){"Aurélien Tchouaméni", "MEI", 87, 100, 1};
    copa[2][13] = (jogador){"Adrien Rabiot", "MEI", 82, 100, 1};
    copa[2][14] = (jogador){"Warren Zaïre-Emery", "MEI", 85, 100, 1};
    copa[2][15] = (jogador){"N'Golo Kanté", "MEI", 83, 100, 1};
    copa[2][16] = (jogador){"Manu Koné", "MEI", 80, 100, 1};
    copa[2][17] = (jogador){"Rayan Cherki", "MEI", 79, 100, 1};
    copa[2][18] = (jogador){"Maghnes Akliouche", "MEI", 78, 100, 1};
    copa[2][19] = (jogador){"Kylian Mbappé", "ATA", 92, 100, 1}; 
    copa[2][20] = (jogador){"Ousmane Dembélé", "ATA", 86, 100, 1};
    copa[2][21] = (jogador){"Michael Olise", "ATA", 86, 100, 1};
    copa[2][22] = (jogador){"Bradley Barcola", "ATA", 84, 100, 1};
    copa[2][23] = (jogador){"Marcus Thuram", "ATA", 84, 100, 1};
    copa[2][24] = (jogador){"Jean-Philippe Mateta", "ATA", 81, 100, 1};
    copa[2][25] = (jogador){"Désiré Doué", "ATA", 76, 100, 1};
    copa[2][26] = (jogador){"França", "pais", -1, -1, -1};

    // Espanha = 3

    copa[3][0] = (jogador){"Unai Simón", "GOL", 86, 100, 1};
    copa[3][1] = (jogador){"David Raya", "GOL", 85, 100, 1};
    copa[3][2] = (jogador){"Joan García", "GOL", 75, 100, 1};
    copa[3][3] = (jogador){"Aymeric Laporte", "ZAG", 85, 100, 1};
    copa[3][4] = (jogador){"Pau Cubarsí", "ZAG", 83, 100, 1};
    copa[3][5] = (jogador){"Marc Cucurella", "ZAG", 84, 100, 1};
    copa[3][6] = (jogador){"Alejandro Grimaldo", "ZAG", 83, 100, 1};
    copa[3][7] = (jogador){"Pedro Porro", "ZAG", 81, 100, 1};
    copa[3][8] = (jogador){"Marcos Llorente", "ZAG", 82, 100, 1};
    copa[3][9] = (jogador){"Eric García", "ZAG", 79, 100, 1};
    copa[3][10] = (jogador){"Marc Pubill", "ZAG", 77, 100, 1};
    copa[3][11] = (jogador){"Rodri", "MEI", 90, 100, 1};
    copa[3][12] = (jogador){"Pedri", "MEI", 88, 100, 1};
    copa[3][13] = (jogador){"Gavi", "MEI", 86, 100, 1};
    copa[3][14] = (jogador){"Fabián Ruiz", "MEI", 84, 100, 1};
    copa[3][15] = (jogador){"Martín Zubimendi", "MEI", 84, 100, 1};
    copa[3][16] = (jogador){"Mikel Merino", "MEI", 82, 100, 1};
    copa[3][17] = (jogador){"Álex Baena", "MEI", 81, 100, 1};
    copa[3][18] = (jogador){"Lamine Yamal", "ATA", 90, 100, 1};
    copa[3][19] = (jogador){"Nico Williams", "ATA", 87, 100, 1};
    copa[3][20] = (jogador){"Dani Olmo", "ATA", 86, 100, 1};
    copa[3][21] = (jogador){"Mikel Oyarzabal", "ATA", 83, 100, 1};
    copa[3][22] = (jogador){"Ferran Torres", "ATA", 82, 100, 1};
    copa[3][23] = (jogador){"Yéremy Pino", "ATA", 80, 100, 1};
    copa[3][24] = (jogador){"Borja Iglesias", "ATA", 79, 100, 1}; 
    copa[3][25] = (jogador){"Víctor Muñoz", "ATA", 74, 100, 1};
    copa[3][26] = (jogador){"Espanha", "pais", -1, -1, -1};

}


int validar_entrada_numerica(int max, int min) {
    int entrada = -1;
    scanf("%d", &entrada);
    while(entrada < min || entrada > max) {
        printf("Ei, isso não é valido, repita!\n");
        while(getchar() != '\n');
        scanf("%d", &entrada);
    }
    while(getchar() != '\n');
    return entrada;
}

int escolher_seleçao() {
    int escolha;
    printf("Escolha entre as 4 selecoes disponiveis:\n");
    printf("[1] Brasil\n[2] Alemanha\n[3] França\n[4] Espanha\n");
    printf("digite o numero correspontente\n");
    escolha = validar_entrada_numerica(4, 1);
    switch (escolha) {
        case 1:
            return 0;
            break;
        case 2:
            return 1;
            break;
        case 3:
            return 2;
            break;
        case 4:
            return 3;
            break;
    }
}

void escolha_pre_jogo(int escolhap, int selecao, jogador copa[4][27]) {
    char nome_selecao[10];
    strcpy(nome_selecao, copa[selecao][SELETOR_PAÍS].nome);
    if(escolhap == 1) {
        printf("jogadores da selecao %s e seus atributos\n", nome_selecao);
        for(int i = 0; i < LIMITOR_JOGADOR; i++) {
            printf("Nome: %s\n", copa[selecao][i].nome);
            printf("Posição: %s\n", copa[selecao][i].posicao);
            printf("Habilidade: %d\n", copa[selecao][i].habilidade);
            printf("\n");
        }
    } else if(escolhap == 2) {
        printf("4-3-3\n");
        printf("Uma das formações mais populares do futebol moderno. Utiliza 4 zagueiros/laterais na linha defensiva, 3 meio-campistas para controlar o ritmo de jogo e 3 atacantes, garantindo amplitude com pontas bem abertos\n");
        printf("4-4-2\n");
        printf("O sistema clássico e equilibrado. Com 4 defensores, 4 meio-campistas dispostos em linha ou em losango e 2 atacantes, oferece excelente cobertura defensiva e facilidade para compactação das linhas\n");
        printf("3-5-2\n");
        printf("Formação que prioriza o domínio do meio-campo. Utiliza 3 zagueiros centrais, 5 meio-campistas (incluindo alas que cobrem todo o corredor lateral) e 2 atacantes para pressionar a defesa adversária\n");
        printf("3-4-3\n");
        printf("Uma alternativa ultra-ofensiva e dinâmica. É composta por 3 zagueiros na recomposição, 4 meio-campistas distribuídos no centro e nas alas, e 3 atacantes para pressionar alto a saída de bola do adversário\n");
        printf("5-3-2\n");
        printf("Opção ideal para um estilo de jogo mais reativo e seguro. Utiliza 5 defensores para fechar os espaços na área, 3 meio-campistas de contenção e 2 atacantes prontos para explorar os contra-ataques\n");
    }
}

void escolher_formacao(int formacao[3]) {
    int escolha;
    printf("Escolha a formação desejada\n");
    printf("[1] 4-3-3\n[2] 4-4-2\n[3] 3-5-2\n[4] 3-4-3\n[5] 5-3-2\n");
    escolha = validar_entrada_numerica(5, 1);
    switch(escolha){
        case 1:
            formacao[0] = 4; formacao[1] = 3; formacao[2] = 3;
            break;
        case 2:
            formacao[0] = 4; formacao[1] = 4; formacao[2] = 2;
            break;
        case 3:
            formacao[0] = 3; formacao[1] = 5; formacao[2] = 2;
            break;
        case 4:
            formacao[0] = 3; formacao[1] = 4; formacao[2] = 3;
            break;
        case 5:
            formacao[0] = 5; formacao[1] = 3; formacao[2] = 2;
            break;
    }
}

void montar_escalaçao(int selecao, int formacao[3], jogador copa[4][27]) {
    int escolha;
    printf("vamos montar a escalacao da seleção %s para lutar contra a Argentina\n", copa[selecao][SELETOR_PAÍS].nome);
    escolher_jogadores(selecao, formacao[0], copa, "ZAG");
    escolher_jogadores(selecao, formacao[1], copa, "MEI");
    escolher_jogadores(selecao, formacao[2], copa, "ATA");
    printf("Escolha seu goleiro\nVoce tem que escolher 1\n");
    for(int i = 0; i < 3; i++) {
        printf("%d. Nome: %s\n", i, copa[selecao][i].nome);
        printf("Habilidade: %d\n", copa[selecao][i].habilidade);
    }
    printf("Escolha seu goleiro entre as opcoes listadas\n");
    escolha = validar_entrada_numerica(2, 0);
    copa[selecao][escolha].estado = 0;

    printf("=== ESCALAÇÂO ===\n");
    for(int i = 0; i < LIMITOR_JOGADOR; i++) {
        if(copa[selecao][i].estado == 0) { 
            printf("%s\n", copa[selecao][i].nome);
        }
    }

}

void escolher_jogadores(int selecao, int formacao, jogador copa[4][27], char posicao[4]) {
    int primeira_jogador;
    int ultima;
    int escolha;
    printf("Escolha seus %s\nVoce tem que escolher %d\n", posicao, formacao);
    for(int i = 0; i < LIMITOR_JOGADOR; i++) {
        if(strcmp(copa[selecao][i].posicao, posicao) == 0) {
            printf("%d. Nome: %s\n", i, copa[selecao][i].nome);
            printf("Habilidade: %d\n", copa[selecao][i].habilidade);
            ultima = i;
        }
        if(i != 0 && strcmp(copa[selecao][i-1].posicao, posicao) != 0 && strcmp(copa[selecao][i].posicao, posicao) == 0) {
            primeira_jogador = i;
        }
    }
    for(int i = 0; i < formacao; i++) {
        printf("escolha o %s numero %d entre as opcoes listadas\n", posicao, i);
        do {
            escolha = validar_entrada_numerica(ultima, primeira_jogador);
            if(copa[selecao][escolha].estado == 0) {
                printf("Ei, não escolha um jogador duas vezes!\n");
            
            }
        } while(copa[selecao][escolha].estado == 0);

        copa[selecao][escolha].estado = 0;
    }
}

void iniciar_tempo_45m(jogador copa[4][27], int placar[2]) {
    int tempo = 45;
    for(int i = 0; i < tempo; i++) {
        
    }
}

void sortear_evento_aleatorio() {
    int evento = (rand() % (200 - 1 + 1)) + 1;

}



int main() {
    srand(time(NULL));
    jogador jogadores_copa26[4][27];
    inicializar_dados(jogadores_copa26);
    char nome_jogador[50];
    int selecao;
    int escolha;
    int formacao[3]; // 0 zagueiro, 1 meia e 2 atacante
    int placar[2] = {0, 0}; //placar[0] sua seleção e placar[1] oponente
    printf("=== Comandante da Selecao ===\n");
    printf("Bem vindo ao Comandante da Selecao! um jogo de futubol onde voce vira o tecnico de uma selecao de copa do mundo e precisa tomar decisoes estrategicas para ganhar o jogo\n");
    printf("Digite o nome do tecnico da seleçao(seu nome)\n");
    fgets(nome_jogador, 50, stdin);
    nome_jogador[strcspn(nome_jogador, "\n")] = '\0';
    printf("Para comecar, escolha sua Seleçao\n");
    selecao = escolher_seleçao();
    do {
        printf("O que deseja fazer agora?:\n");
        printf("[0] iniciar jogo\n[1] Olhar jogadores\n[2] Conferir formaçoes\n");
        escolha = validar_entrada_numerica(2, 0);
        escolha_pre_jogo(escolha, selecao, jogadores_copa26);
    } while (escolha != 0);
    escolher_formacao(formacao);
    montar_escalaçao(selecao, formacao, jogadores_copa26);
    printf("Vamos inciar o primeiro tempo eeeeeeee! juiz apita e inicia o primeiro tempo!\n");


}
