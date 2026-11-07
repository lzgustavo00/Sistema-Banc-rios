
#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
#include <cmath>
#include <sstream>

using namespace std;

// Limites do sistema
const int LIMITE_CONTAS = 100;
const int LIMITE_LANCAMENTOS = 500;

// Dados das contas
int contas[LIMITE_CONTAS];
string titulares[LIMITE_CONTAS];
string documentos[LIMITE_CONTAS];
int modalidades[LIMITE_CONTAS];
double saldos[LIMITE_CONTAS];
bool ativas[LIMITE_CONTAS];

int totalContas = 0;
int proximaConta = 1001;

// Historico de movimentacoes
int contaDoLancamento[LIMITE_LANCAMENTOS];
char naturezaLancamento[LIMITE_LANCAMENTOS];
double quantiaLancamento[LIMITE_LANCAMENTOS];

int totalLancamentos = 0;

// Leitura de numeros inteiros
int lerOpcao(string mensagem) {
    int numero;

    while (true) {
        cout << mensagem;

        if (cin >> numero) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return numero;
        }

        cout << "Entrada invalida. Digite um numero inteiro.\n";

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

// Leitura de valores monetarios
double lerQuantia(string mensagem) {
    string entrada;

    while (true) {
        cout << mensagem;
        getline(cin, entrada);

        for (char &c : entrada) {
            if (c == ',') {
                c = '.';
            }
        }

        stringstream fluxo(entrada);
        double valor;
        char extra;

        if (fluxo >> valor && !(fluxo >> extra) && isfinite(valor)) {
            return valor;
        }

        cout << "Valor invalido. Exemplo: 150.50\n";
    }
}

// Leitura de textos
string lerCampo(string mensagem) {
    string texto;

    do {
        cout << mensagem;
        getline(cin, texto);

        if (texto.empty()) {
            cout << "O campo nao pode ficar vazio.\n";
        }

    } while (texto.empty());

    return texto;
}

// Localiza uma conta pelo numero
int buscarIndice(int numeroConta) {

    for (int i = 0; i < totalContas; i++) {

        if (contas[i] == numeroConta) {
            return i;
        }
    }

    return -1;
}

// Verifica espaco no historico
bool existeEspacoNoHistorico(int quantidade) {
    return totalLancamentos + quantidade <= LIMITE_LANCAMENTOS;
}

// Registra uma movimentacao
void incluirLancamento(int numeroConta, char tipo, double valor) {

    contaDoLancamento[totalLancamentos] = numeroConta;
    naturezaLancamento[totalLancamentos] = tipo;
    quantiaLancamento[totalLancamentos] = valor;

    totalLancamentos++;
}

// Mostra os dados de uma conta
void imprimirDadosConta(int indice) {

    cout << fixed << setprecision(2);

    cout << "\nNumero da conta: " << contas[indice] << endl;
    cout << "Titular: " << titulares[indice] << endl;
    cout << "CPF: " << documentos[indice] << endl;

    cout << "Tipo de conta: ";

    if (modalidades[indice] == 1) {
        cout << "Corrente\n";
    } else {
        cout << "Poupanca\n";
    }

    cout << "Saldo: R$ " << saldos[indice] << endl;

    cout << "Situacao: "
         << (ativas[indice] ? "Ativa" : "Inativa") << endl;
}

// Cadastro de contas
void abrirConta() {

    if (totalContas >= LIMITE_CONTAS) {
        cout << "Limite de contas atingido.\n";
        return;
    }

    cout << "\n===== NOVA CONTA =====\n";

    int posicao = totalContas;

    contas[posicao] = proximaConta++;

    titulares[posicao] = lerCampo("Nome do cliente: ");
    documentos[posicao] = lerCampo("CPF: ");

    do {
        modalidades[posicao] = lerOpcao(
            "Tipo (1 - Corrente | 2 - Poupanca): "
        );

        if (modalidades[posicao] != 1 &&
            modalidades[posicao] != 2) {

            cout << "Digite 1 ou 2.\n";
        }

    } while (modalidades[posicao] != 1 &&
             modalidades[posicao] != 2);

    saldos[posicao] = 0.0;
    ativas[posicao] = true;

    totalContas++;

    cout << "\nConta criada com sucesso!\n";
    cout << "Numero da conta: " << contas[posicao] << endl;
}

// Lista todas as contas
void apresentarContas() {

    cout << "\n===== LISTA DE CONTAS =====\n";

    if (totalContas == 0) {
        cout << "Nenhuma conta cadastrada.\n";
        return;
    }

    for (int i = 0; i < totalContas; i++) {

        cout << "\n-------------------------\n";

        imprimirDadosConta(i);
    }
}

// Consulta uma conta
void pesquisarConta() {

    cout << "\n===== CONSULTAR CONTA =====\n";

    int numero = lerOpcao("Informe o numero da conta: ");

    int indice = buscarIndice(numero);

    if (indice == -1) {
        cout << "Conta nao encontrada.\n";
        return;
    }

    imprimirDadosConta(indice);
}

// Realiza deposito
void fazerDeposito() {

    cout << "\n===== DEPOSITO =====\n";

    int numero = lerOpcao("Numero da conta: ");

    int indice = buscarIndice(numero);

    if (indice == -1 || !ativas[indice]) {
        cout << "Conta inexistente ou inativa.\n";
        return;
    }

    if (!existeEspacoNoHistorico(1)) {
        cout << "Historico de movimentacoes cheio.\n";
        return;
    }

    double valor = lerQuantia("Valor do deposito: R$ ");

    if (valor <= 0) {
        cout << "O valor deve ser maior que zero.\n";
        return;
    }

    saldos[indice] += valor;

    incluirLancamento(numero, 'D', valor);

    cout << fixed << setprecision(2);

    cout << "Deposito realizado!\n";
    cout << "Novo saldo: R$ " << saldos[indice] << endl;
}

// Realiza saque
void fazerSaque() {

    cout << "\n===== SAQUE =====\n";

    int numero = lerOpcao("Numero da conta: ");

    int indice = buscarIndice(numero);

    if (indice == -1 || !ativas[indice]) {
        cout << "Conta inexistente ou inativa.\n";
        return;
    }

    if (!existeEspacoNoHistorico(1)) {
        cout << "Historico de movimentacoes cheio.\n";
        return;
    }

    double valor = lerQuantia("Valor do saque: R$ ");

    if (valor <= 0) {
        cout << "O valor deve ser maior que zero.\n";
        return;
    }

    if (valor > saldos[indice]) {
        cout << "Saldo insuficiente.\n";
        return;
    }

    saldos[indice] -= valor;

    incluirLancamento(numero, 'S', valor);

    cout << fixed << setprecision(2);

    cout << "Saque realizado!\n";
    cout << "Novo saldo: R$ " << saldos[indice] << endl;
}

// Realiza transferencia entre contas
void enviarTransferencia() {

    cout << "\n===== TRANSFERENCIA =====\n";

    int origem = lerOpcao("Conta de origem: ");
    int destino = lerOpcao("Conta de destino: ");

    int posOrigem = buscarIndice(origem);
    int posDestino = buscarIndice(destino);

    if (posOrigem == -1 || posDestino == -1) {
        cout << "Uma das contas nao foi encontrada.\n";
        return;
    }

    if (!ativas[posOrigem] || !ativas[posDestino]) {
        cout << "As duas contas precisam estar ativas.\n";
        return;
    }

    if (origem == destino) {
        cout << "As contas devem ser diferentes.\n";
        return;
    }

    if (!existeEspacoNoHistorico(2)) {
        cout << "Espaco insuficiente no historico.\n";
        return;
    }

    double valor = lerQuantia("Valor da transferencia: R$ ");

    if (valor <= 0) {
        cout << "O valor deve ser maior que zero.\n";
        return;
    }

    if (valor > saldos[posOrigem]) {
        cout << "Saldo insuficiente na conta de origem.\n";
        return;
    }

    // Atualizacao dos saldos
    saldos[posOrigem] -= valor;
    saldos[posDestino] += valor;

    // Registro das duas movimentacoes
    incluirLancamento(origem, 'S', valor);
    incluirLancamento(destino, 'D', valor);

    cout << fixed << setprecision(2);

    cout << "\nTransferencia realizada com sucesso!\n";

    cout << "Saldo da origem: R$ "
         << saldos[posOrigem] << endl;

    cout << "Saldo do destino: R$ "
         << saldos[posDestino] << endl;
}

// Exibe extrato da conta
void consultarExtrato() {

    cout << "\n===== EXTRATO =====\n";

    int numero = lerOpcao("Numero da conta: ");

    int indice = buscarIndice(numero);

    if (indice == -1) {
        cout << "Conta nao encontrada.\n";
        return;
    }

    double entradas = 0.0;
    double saidas = 0.0;

    bool encontrou = false;

    cout << "\nTitular: " << titulares[indice] << endl;
    cout << "Conta: " << numero << endl;

    cout << "-----------------------------\n";

    cout << fixed << setprecision(2);

    for (int i = 0; i < totalLancamentos; i++) {

        if (contaDoLancamento[i] == numero) {

            encontrou = true;

            if (naturezaLancamento[i] == 'D') {

                cout << "Deposito/Entrada: + R$ "
                     << quantiaLancamento[i] << endl;

                entradas += quantiaLancamento[i];

            } else if (naturezaLancamento[i] == 'S') {

                cout << "Saque/Saida: - R$ "
                     << quantiaLancamento[i] << endl;

                saidas += quantiaLancamento[i];
            }
        }
    }

    if (!encontrou) {
        cout << "Nenhuma movimentacao encontrada.\n";
    }

    cout << "-----------------------------\n";

    cout << "Total de entradas: R$ " << entradas << endl;
    cout << "Total de saidas: R$ " << saidas << endl;
    cout << "Saldo atual: R$ " << saldos[indice] << endl;
}

// Menu principal
void mostrarMenu() {

    cout << "\n========== BANCO DIGITAL ==========\n";

    cout << "1 - Abrir conta\n";
    cout << "2 - Listar contas\n";
    cout << "3 - Consultar conta\n";
    cout << "4 - Realizar deposito\n";
    cout << "5 - Realizar saque\n";
    cout << "6 - Realizar transferencia\n";
    cout << "7 - Consultar extrato\n";
    cout << "0 - Sair\n";

    cout << "===================================\n";
}

// Programa principal
int main() {

    int opcao;

    do {

        mostrarMenu();

        opcao = lerOpcao("Escolha uma opcao: ");

        switch (opcao) {

            case 1:
                abrirConta();
                break;

            case 2:
                apresentarContas();
                break;

            case 3:
                pesquisarConta();
                break;

            case 4:
                fazerDeposito();
                break;

            case 5:
                fazerSaque();
                break;

            case 6:
                enviarTransferencia();
                break;

            case 7:
                consultarExtrato();
                break;

            case 0:
                cout << "Sistema encerrado. Ate mais!\n";
                break;

            default:
                cout << "Opcao invalida. Tente novamente.\n";
        }

    } while (opcao != 0);

    return 0;
}
