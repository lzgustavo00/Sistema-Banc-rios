# Banco Digital – Sistema de Gestão de Contas Bancárias

Projeto desenvolvido em C++ para implementar um sistema de cadastro e movimentação de contas bancárias, permitindo registrar clientes, consultar contas e acompanhar operações financeiras realizadas durante a execução do programa.

## Objetivo

O projeto foi desenvolvido para realizar três atividades principais:

1. Cadastrar e organizar diferentes contas bancárias.
2. Realizar operações de depósito, saque e transferência entre contas.
3. Registrar as movimentações e consultar o extrato de cada conta.

## Funcionalidades

### 1. Cadastrar contas bancárias

O programa permite abrir novas contas e armazenar informações dos clientes, como:

- Número da conta, gerado automaticamente a partir de `1001`;
- Nome do titular;
- CPF;
- Modalidade da conta (Corrente ou Poupança);
- Saldo inicial;
- Situação da conta.

O sistema permite cadastrar até 100 contas.

### 2. Listar e pesquisar contas

O programa permite visualizar todas as contas cadastradas ou pesquisar uma conta pelo número.

Na consulta são apresentadas informações como:

- Número da conta;
- Nome do titular;
- CPF;
- Modalidade da conta;
- Saldo disponível;
- Situação da conta.

### 3. Realizar depósitos e saques

O sistema permite adicionar ou retirar valores das contas cadastradas.

Para realizar essas operações, são verificadas as seguintes condições:

- A conta informada precisa existir e estar ativa;
- O valor da operação deve ser maior que zero;
- Para saques, é necessário possuir saldo suficiente;
- Deve existir espaço disponível no histórico de movimentações.

Os depósitos são registrados com o código `D`, enquanto os saques utilizam o código `S`.

### 4. Realizar transferências

O programa permite transferir valores entre duas contas diferentes.

Antes de concluir a operação, o sistema verifica:

- Se as duas contas foram encontradas;
- Se ambas estão ativas;
- Se a conta de origem é diferente da conta de destino;
- Se o valor informado é positivo;
- Se existe saldo suficiente na conta de origem;
- Se há espaço para registrar as duas movimentações.

Cada transferência gera dois registros no histórico:

- `S`: saída do valor na conta de origem;
- `D`: entrada do valor na conta de destino.

### 5. Consultar extrato

O sistema permite consultar as movimentações de uma conta específica, apresentando:

- Créditos e depósitos recebidos;
- Débitos e saques realizados;
- Total de créditos;
- Total de débitos;
- Saldo disponível.

O extrato percorre o histórico e apresenta somente os lançamentos pertencentes à conta consultada.

### 6. Histórico de movimentações

As movimentações são armazenadas em arrays paralelos, com capacidade para até 500 lançamentos.

Cada registro guarda o número da conta, o tipo da movimentação e o valor correspondente. Os dados ficam disponíveis apenas enquanto o programa estiver em execução. Ao encerrar o sistema, as informações são perdidas, conforme definido para a Etapa 2.

## Tecnologias utilizadas

- C++
- Arrays (vetores paralelos)
- Funções
- Estruturas condicionais (`if`, `else` e `switch`)
- Estruturas de repetição (`for` e `do while`)
- Manipulação de dados em memória

## Instalação

Primeiro, clone o repositório:

```bash
git clone https://github.com/USUARIO/REPOSITORIO.git
```

Entre na pasta do projeto:

```bash
cd REPOSITORIO
```

## Compilação e execução

Com o compilador G++ instalado, compile o programa:

### Windows

```bash
g++ -std=c++17 -Wall -Wextra -pedantic BancoDigital.cpp -o BancoDigital.exe
```

Execute o programa:

```bash
BancoDigital.exe
```

### Linux

```bash
g++ -std=c++17 -Wall -Wextra -pedantic BancoDigital.cpp -o BancoDigital
./BancoDigital
```

## Estrutura do projeto

- `BancoDigital.cpp` – código-fonte do sistema bancário;
- `README.md` – documentação do projeto e instruções de instalação e execução.

## Considerações finais

O projeto foi desenvolvido como parte da Etapa 2 do trabalho da disciplina INF101 – Programação de Computadores I. A implementação utiliza arrays para armazenar contas e movimentações em memória, permitindo praticar conceitos de programação na construção de um sistema de gestão bancária.
