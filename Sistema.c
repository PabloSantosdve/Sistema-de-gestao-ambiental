#include <stdio.h>  // Inclui a biblioteca padrão de entrada e saída para uso de funções como printf e scanf
#include <string.h> // Inclui a biblioteca de manipulação de strings, para funções como strlen e strcmp

#define SHIFT 3  // Define uma constante SHIFT para o valor do deslocamento usado na criptografia (cifra de César)

// Função para criptografar uma string usando a cifra de César
// Cada caractere da senha é deslocado para a direita por um valor fixo (SHIFT)
void criptografar(char senha[]) {
    for (int i = 0; i < strlen(senha); i++) {  // Loop que percorre cada caractere da string "senha"
        senha[i] += SHIFT;  // Adiciona o valor de SHIFT ao caractere atual, modificando-o
    }
}

// Função para autenticar o login do usuário
// Recebe como entrada o nome do usuário e a senha digitados
int autenticar(char usuario[], char senha[]) {
    char usuarioCorreto[] = "admin";  // Nome de usuário correto para autenticação
    char senhaCorreta[] = "12345";    // Senha correta para autenticação

    // Criptografa a senha correta antes de compará-la com a senha fornecida pelo usuário
    // Isso garante que ambas estejam no mesmo formato
    criptografar(senhaCorreta);

    // Criptografa a senha fornecida pelo usuário para comparação
    criptografar(senha);

    // Verifica se o nome de usuário e a senha criptografados coincidem com os valores corretos
    // Usa strcmp, que retorna 0 se as strings forem iguais
    if (strcmp(usuario, usuarioCorreto) == 0 && strcmp(senha, senhaCorreta) == 0) {
        return 1; // Retorna 1 indicando que a autenticação foi bem-sucedida
    } else {
        return 0; // Retorna 0 indicando falha na autenticação
    }
}

// Função principal do programa, onde o código começa a ser executado
int main() {
    char usuario[20];  // Declara um array para armazenar o nome de usuário fornecido pelo usuário
    char senha[20];    // Declara um array para armazenar a senha fornecida pelo usuário
    int tentativas = 3; // Define o número máximo de tentativas de login para 3

    printf("=== Sistema de Login ===\n");  // Exibe o título do sistema de login

    // Loop que permite ao usuário tentar o login até 3 vezes
    while (tentativas > 0) {
        // Solicita que o usuário insira seu nome e senha
        printf("\nUsuário: ");
        scanf("%s", usuario);  // Lê a entrada do nome de usuário
        printf("Senha: ");
        scanf("%s", senha);    // Lê a entrada da senha

        // Chama a função autenticar para verificar se o login está correto
        if (autenticar(usuario, senha)) {
            printf("\nLogin realizado com sucesso!\n"); // Exibe uma mensagem de sucesso
            break; // Sai do loop, pois o login foi bem-sucedido
        } else {
            tentativas--; // Decrementa o número de tentativas restantes
            printf("\nUsuário ou senha incorretos. Você tem %d tentativas restantes.\n", tentativas); // Exibe uma mensagem de erro
        }
    }

    // Se o usuário não conseguir fazer login após 3 tentativas, exibe uma mensagem de bloqueio
    if (tentativas == 0) {
        printf("\nVocê excedeu o número de tentativas. Acesso bloqueado.\n");
    }

    return 0; // Retorna 0 para indicar que o programa terminou sem erros