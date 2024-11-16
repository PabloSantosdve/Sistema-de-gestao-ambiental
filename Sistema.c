#include <stdio.h>      // Inclusão da biblioteca para funções de entrada e saída
#include <stdlib.h>     // Inclusão da biblioteca para funções gerais, como exit()
#include <string.h>     // Inclusão da biblioteca para manipulação de strings

#define MAX_LEN 256     // Definindo o tamanho máximo das strings como 256 caracteres

// Função simples de criptografia (XOR)
void criptografar(char *str) {
    char chave = 0xA5; // Definindo a chave fixa de criptografia (valor hexadecimal)
    for (int i = 0; str[i] != '\0'; i++) {  // Loop para percorrer cada caractere da string até o fim
        str[i] ^= chave; // Aplica a operação XOR entre cada caractere e a chave
    }
}

// Função de login
int login() {
    char usuario[MAX_LEN];            // Declaração de variável para armazenar o nome de usuário
    char senha[MAX_LEN];              // Declaração de variável para armazenar a senha
    char senha_criptografada[MAX_LEN]; // Declaração de variável para armazenar a senha criptografada
    
    // Dados do usuário e senha cadastrados
    char usuario_cadastrado[MAX_LEN] = "admin";  // Usuário fixo cadastrado
    char senha_cadastrada[MAX_LEN] = "12345";    // Senha fixa cadastrada (a ser criptografada)
    
    // Criptografa a senha cadastrada
    strcpy(senha_criptografada, senha_cadastrada);  // Copia a senha cadastrada para a variável de senha criptografada
    criptografar(senha_criptografada); // Criptografa a senha cadastrada

    printf("Digite o usuario: ");  // Solicita ao usuário que digite o nome de usuário
    fgets(usuario, MAX_LEN, stdin); // Lê o nome do usuário da entrada padrão (teclado)
    usuario[strcspn(usuario, "\n")] = '\0'; // Remove o caractere de nova linha, caso presente

    printf("Digite a senha: ");  // Solicita a senha do usuário
    fgets(senha, MAX_LEN, stdin);  // Lê a senha da entrada padrão
    senha[strcspn(senha, "\n")] = '\0';  // Remove o caractere de nova linha

    // Criptografa a senha digitada
    char senha_digitada[MAX_LEN];  // Declara variável para armazenar a senha digitada
    strcpy(senha_digitada, senha); // Copia a senha digitada para a variável
    criptografar(senha_digitada); // Criptografa a senha digitada

    // Verifica se o login foi bem-sucedido comparando usuário e senha criptografada
    if (strcmp(usuario, usuario_cadastrado) == 0 && strcmp(senha_digitada, senha_criptografada) == 0) {
        printf("Login bem-sucedido!\n");  // Se os dados corresponderem, exibe mensagem de sucesso
        return 1;  // Retorna 1, indicando sucesso
    } else {
        printf("Usuario ou senha incorretos.\n");  // Caso contrário, exibe erro
        return 0;  // Retorna 0, indicando falha
    }
}

// Função para cadastrar um funcionário
void cadastrar_funcionario() {
    FILE *fp = fopen("funcionarios.txt", "a");  // Abre o arquivo "funcionarios.txt" para adicionar novos dados
    if (!fp) {  // Verifica se o arquivo não pôde ser aberto
        printf("Erro ao abrir o arquivo de funcionarios!\n");  // Exibe mensagem de erro
        return;  // Retorna da função
    }

    // Solicitar dados do funcionário
    char nome[MAX_LEN], cpf[MAX_LEN], cargo[MAX_LEN], telefone[MAX_LEN], endereco[MAX_LEN], email[MAX_LEN];
    printf("Digite o nome do funcionario: ");  // Solicita o nome do funcionário
    fgets(nome, MAX_LEN, stdin);  // Lê o nome do funcionário
    nome[strcspn(nome, "\n")] = '\0';  // Remove o caractere de nova linha

    printf("Digite o CPF do funcionario: ");  // Solicita o CPF do funcionário
    fgets(cpf, MAX_LEN, stdin);  // Lê o CPF
    cpf[strcspn(cpf, "\n")] = '\0';  // Remove a quebra de linha

    printf("Digite o cargo do funcionario: ");  // Solicita o cargo do funcionário
    fgets(cargo, MAX_LEN, stdin);  // Lê o cargo
    cargo[strcspn(cargo, "\n")] = '\0';  // Remove a quebra de linha

    printf("Digite o telefone do funcionario: ");  // Solicita o telefone
    fgets(telefone, MAX_LEN, stdin);  // Lê o telefone
    telefone[strcspn(telefone, "\n")] = '\0';  // Remove a quebra de linha

    printf("Digite o endereco do funcionario: ");  // Solicita o endereço
    fgets(endereco, MAX_LEN, stdin);  // Lê o endereço
    endereco[strcspn(endereco, "\n")] = '\0';  // Remove a quebra de linha

    printf("Digite o email do funcionario: ");  // Solicita o e-mail
    fgets(email, MAX_LEN, stdin);  // Lê o e-mail
    email[strcspn(email, "\n")] = '\0';  // Remove a quebra de linha

    // Gravar dados do funcionário no arquivo
    fprintf(fp, "%s,%s,%s,%s,%s,%s\n", nome, cpf, cargo, telefone, endereco, email);  // Grava os dados do funcionário no arquivo

    fclose(fp);  // Fecha o arquivo
    printf("Funcionario cadastrado com sucesso!\n");  // Exibe confirmação
}

// Função para visualizar os funcionários cadastrados
void visualizar_funcionarios() {
    FILE *fp = fopen("funcionarios.txt", "r");  // Abre o arquivo para leitura
    if (!fp) {  // Verifica se o arquivo não pôde ser aberto
        printf("Erro ao abrir o arquivo de funcionarios!\n");  // Exibe mensagem de erro
        return;  // Retorna da função
    }

    char linha[MAX_LEN];  // Declara variável para armazenar cada linha lida
    printf("\nFuncionarios Cadastrados:\n");  // Exibe título
    printf("--------------------------------------------------------\n");  // Exibe linha divisória
    while (fgets(linha, MAX_LEN, fp)) {  // Lê cada linha do arquivo
        char *nome = strtok(linha, ",");  // Extrai o nome da linha
        char *cpf = strtok(NULL, ",");  // Extrai o CPF
        char *cargo = strtok(NULL, ",");  // Extrai o cargo
        char *telefone = strtok(NULL, ",");  // Extrai o telefone
        char *endereco = strtok(NULL, ",");  // Extrai o endereço
        char *email = strtok(NULL, "\n");  // Extrai o e-mail

        // Exibe os dados extraídos
        printf("Nome: %s\n", nome);
        printf("CPF: %s\n", cpf);
        printf("Cargo: %s\n", cargo);
        printf("Telefone: %s\n", telefone);
        printf("Endereco: %s\n", endereco);
        printf("Email: %s\n", email);
        printf("--------------------------------------------------------\n");  // Exibe linha divisória
    }

    fclose(fp);  // Fecha o arquivo
}

// Função para cadastrar uma empresa
void cadastrar_empresa() {
    FILE *fp = fopen("empresas.txt", "a");  // Abre o arquivo "empresas.txt" para adicionar dados
    if (!fp) {  // Verifica se o arquivo não pôde ser aberto
        printf("Erro ao abrir o arquivo de empresas!\n");  // Exibe mensagem de erro
        return;  // Retorna da função
    }

    // Solicitar dados da empresa
    char nome[MAX_LEN], cnpj[MAX_LEN], razao_social[MAX_LEN], nome_fantasia[MAX_LEN], endereco[MAX_LEN], telefone[MAX_LEN], email[MAX_LEN], data_abertura[MAX_LEN], dados_residuos[MAX_LEN];
    printf("Digite o nome da empresa: ");  // Solicita o nome da empresa
    fgets(nome, MAX_LEN, stdin);  // Lê o nome da empresa
    nome[strcspn(nome, "\n")] = '\0';  // Remove a quebra de linha

    printf("Digite o CNPJ da empresa: ");  // Solicita o CNPJ da empresa
    fgets(cnpj, MAX_LEN, stdin);  // Lê o CNPJ
    cnpj[strcspn(cnpj, "\n")] = '\0';  // Remove a quebra de linha

    printf("Digite a razao social da empresa: ");  // Solicita a razão social
    fgets(razao_social, MAX_LEN, stdin);  // Lê a razão social
    razao_social[strcspn(razao_social, "\n")] = '\0';  // Remove a quebra de linha

    printf("Digite o nome fantasia da empresa: ");  // Solicita o nome fantasia
    fgets(nome_fantasia, MAX_LEN, stdin);  // Lê o nome fantasia
    nome_fantasia[strcspn(nome_fantasia, "\n")] = '\0';  // Remove a quebra de linha

    printf("Digite o endereco da empresa: ");  // Solicita o endereço da empresa
    fgets(endereco, MAX_LEN, stdin);  // Lê o endereço
    endereco[strcspn(endereco, "\n")] = '\0';  // Remove a quebra de linha

    printf("Digite o telefone da empresa: ");  // Solicita o telefone da empresa
    fgets(telefone, MAX_LEN, stdin);  // Lê o telefone
    telefone[strcspn(telefone, "\n")] = '\0';  // Remove a quebra de linha

    printf("Digite o email da empresa: ");  // Solicita o e-mail da empresa
    fgets(email, MAX_LEN, stdin);  // Lê o e-mail
    email[strcspn(email, "\n")] = '\0';  // Remove a quebra de linha

    printf("Digite a data de abertura da empresa: ");  // Solicita a data de abertura da empresa
    fgets(data_abertura, MAX_LEN, stdin);  // Lê a data de abertura
    data_abertura[strcspn(data_abertura, "\n")] = '\0';  // Remove a quebra de linha

    printf("Digite os dados dos residuos tratados pela empresa: ");  // Solicita os dados dos resíduos
    fgets(dados_residuos, MAX_LEN, stdin);  // Lê os dados
    dados_residuos[strcspn(dados_residuos, "\n")] = '\0';  // Remove a quebra de linha

    // Grava os dados da empresa no arquivo
    fprintf(fp, "%s,%s,%s,%s,%s,%s,%s,%s,%s\n", nome, cnpj, razao_social, nome_fantasia, endereco, telefone, email, data_abertura, dados_residuos);

    fclose(fp);  // Fecha o arquivo
    printf("Empresa cadastrada com sucesso!\n");  // Exibe confirmação
}

// Função para atualizar dados dos resíduos
void atualizar_residuos() {
    FILE *fp = fopen("atualizacao_mensal.txt", "a");  // Abre o arquivo para adicionar dados
    if (!fp) {  // Verifica se o arquivo não pôde ser aberto
        printf("Erro ao abrir o arquivo de atualizacao de residuos!\n");  // Exibe mensagem de erro
        return;  // Retorna da função
    }

    char mes[MAX_LEN], residuos_tratados[MAX_LEN], custo_tratamento[MAX_LEN];
    printf("Digite o mes de atualizacao: ");  // Solicita o mês
    fgets(mes, MAX_LEN, stdin);  // Lê o mês
    mes[strcspn(mes, "\n")] = '\0';  // Remove a quebra de linha

    printf("Digite a quantidade de residuos tratados: ");  // Solicita a quantidade de resíduos
    fgets(residuos_tratados, MAX_LEN, stdin);  // Lê os resíduos
    residuos_tratados[strcspn(residuos_tratados, "\n")] = '\0';  // Remove a quebra de linha

    printf("Digite o custo do tratamento: ");  // Solicita o custo do tratamento
    fgets(custo_tratamento, MAX_LEN, stdin);  // Lê o custo
    custo_tratamento[strcspn(custo_tratamento, "\n")] = '\0';  // Remove a quebra de linha

    // Grava os dados de resíduos no arquivo
    fprintf(fp, "%s,%s,%s\n", mes, residuos_tratados, custo_tratamento);

    fclose(fp);  // Fecha o arquivo
    printf("Dados atualizados com sucesso!\n");  // Exibe confirmação
}

// Função para gerar relatórios
void gerar_relatorio() {
    FILE *fp = fopen("atualizacao_mensal.txt", "r");  // Abre o arquivo para leitura
    if (!fp) {  // Verifica se o arquivo não pôde ser aberto
        printf("Erro ao abrir o arquivo de atualizacao de residuos!\n");  // Exibe mensagem de erro
        return;  // Retorna da função
    }

    FILE *relatorio_txt = fopen("relatorio.txt", "w");  // Cria e abre o arquivo de relatório TXT
    FILE *relatorio_csv = fopen("relatorio.csv", "w");  // Cria e abre o arquivo de relatório CSV
    FILE *relatorio_xls = fopen("relatorio.xls", "w");  // Cria e abre o arquivo de relatório XLS

    if (!relatorio_txt || !relatorio_csv || !relatorio_xls) {  // Verifica se algum arquivo não pôde ser aberto
        printf("Erro ao criar os arquivos de relatorio!\n");  // Exibe mensagem de erro
        return;  // Retorna da função
    }

    char linha[MAX_LEN];  // Variável para armazenar cada linha do arquivo de dados

    // Loop para ler e escrever as linhas nos arquivos
    while (fgets(linha, MAX_LEN, fp)) {
        fprintf(relatorio_txt, "%s", linha);  // Escreve no arquivo TXT
        fprintf(relatorio_csv, "%s", linha);  // Escreve no arquivo CSV
        fprintf(relatorio_xls, "%s", linha);  // Escreve no arquivo XLS
    }

    fclose(fp);  // Fecha o arquivo de dados
    fclose(relatorio_txt);  // Fecha o arquivo de relatório TXT
    fclose(relatorio_csv);  // Fecha o arquivo de relatório CSV
    fclose(relatorio_xls);  // Fecha o arquivo de relatório XLS
    printf("Relatorios gerados com sucesso!\n");  // Exibe confirmação
}

// Função para mostrar o menu de opções
void menu() {
    int opcao;  // Variável para armazenar a opção escolhida pelo usuário

    do {
        // Exibe as opções do menu
        printf("\nMenu:\n");
        printf("1. Cadastrar Funcionario\n");
        printf("2. Visualizar Funcionarios\n");
        printf("3. Cadastrar Empresa\n");
        printf("4. Atualizar Residuos\n");
        printf("5. Gerar Relatorio\n");
        printf("6. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);  // Lê a opção escolhida pelo usuário

        getchar();  // Limpa o buffer do teclado

        // Switch para executar a opção escolhida
        switch (opcao) {
            case 1:
                cadastrar_funcionario();  // Chama a função para cadastrar um funcionário
                break;
            case 2:
                visualizar_funcionarios();  // Chama a função para visualizar os funcionários
                break;
            case 3:
                cadastrar_empresa();  // Chama a função para cadastrar uma empresa
                break;
            case 4:
                atualizar_residuos();  // Chama a função para atualizar os resíduos
                break;
            case 5:
                gerar_relatorio();  // Chama a função para gerar os relatórios
                break;
            case 6:
                printf("Saindo...\n");  // Exibe mensagem de saída
                break;
            default:
                printf("Opcao invalida!\n");  // Caso a opção seja inválida
        }
    } while (opcao != 6);  // Repete o menu até o usuário escolher sair
}

int main() {
    if (login()) {  // Verifica se o login foi bem-sucedido
        menu();  // Se o login for bem-sucedido, exibe o menu
    } else {
        printf("Falha no login! Tente novamente.\n");  // Exibe mensagem de erro em caso de falha no login
    }

    return 0;  // Finaliza o programa
}
