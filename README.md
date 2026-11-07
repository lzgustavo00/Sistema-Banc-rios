Banco Digital - Controle de Contas Bancarias
Aplicacao desenvolvida em C++ para cadastrar clientes e administrar contas bancarias por meio de operacoes realizadas no terminal. O projeto corresponde a Etapa 2 da atividade de INF101 - Programacao de Computadores I.
Proposta do projeto
O sistema organiza diferentes contas em estruturas de arrays e registra as operacoes financeiras realizadas durante a execucao. A aplicacao foi planejada para atender as seguintes necessidades:
1. Abrir e cadastrar contas para clientes.
2. Consultar uma conta individualmente ou visualizar a relacao completa.
3. Creditar valores por meio de depositos.
4. Efetuar retiradas, impedindo saques acima do saldo disponivel.
5. Transferir dinheiro entre contas cadastradas.
6. Consultar o extrato e os totais de entradas e saidas de cada conta.
Recursos disponiveis
Cadastro e consulta
Cada novo cadastro recebe um numero sequencial, iniciado em 1001. Para cada conta, sao guardados o nome do titular, CPF, modalidade, saldo e situacao. O sistema oferece uma tela de consulta individual e outra para listar todos os cadastros.
Operacoes financeiras
As operacoes verificam se a conta informada foi cadastrada e esta ativa. Depositos e transferencias recebidas aumentam o saldo; saques e transferencias enviadas diminuem o saldo. Valores iguais ou inferiores a zero nao sao aceitos, e uma retirada somente e concluida quando existe saldo suficiente.
Registro de movimentacoes
Cada operacao e adicionada ao historico em memoria:
- D: deposito ou valor recebido;
- S: saque ou valor enviado.
Uma transferencia e representada por dois lancamentos: um de saida na conta de origem e outro de entrada na conta de destino. O extrato filtra os registros pelo numero da conta consultada.
Limites e armazenamento
O programa utiliza arrays paralelos para guardar os dados, respeitando os limites definidos na atividade:
- 100 contas bancarias;
- 500 lancamentos no historico.
As informacoes existem somente enquanto o programa esta aberto. Ao encerrar a execucao, os dados sao apagados. O armazenamento permanente nao faz parte desta etapa.
Tecnologias e conceitos
- Linguagem C++;
- Arrays paralelos;
- Funcoes;
- Estruturas condicionais (if, else e switch);
- Estruturas de repeticao (for e do while);
- Entrada e saida de dados pelo terminal.
Arquivos
- BancoDigital.cpp: implementacao do sistema;
- README.md: descricao do projeto e orientacoes de uso.
Como obter o projeto
Clone o repositorio substituindo o endereco abaixo pelo link publicado no GitHub da pessoa responsavel:
git clone https://github.com/USUARIO/REPOSITORIO.git
Depois, entre na pasta criada pelo Git:
cd REPOSITORIO
Compilacao e execucao
E necessario ter um compilador C++ instalado, como o G++.

No Windows, compile com:
g++ -std=c++17 -Wall -Wextra -pedantic BancoDigital.cpp -o BancoDigital.exe
E execute:
BancoDigital.exe
No Linux, compile com:
g++ -std=c++17 -Wall -Wextra -pedantic BancoDigital.cpp -o BancoDigital
E execute:
./BancoDigital
Exemplo de utilizacao
1. Selecione 1 para abrir duas contas.
2. Use a opcao 4 para depositar um valor na primeira conta.
3. Escolha 6 para transferir parte do saldo para a segunda conta.
4. Consulte a opcao 7 nas duas contas para conferir os lancamentos de saida e entrada.
Consideracoes finais
O Banco Digital foi organizado para demonstrar o uso de arrays, funcoes, decisoes e repeticoes na construcao de um sistema de contas bancarias. O historico permite acompanhar as operacoes feitas durante a sessao, mantendo o comportamento de armazenamento em memoria solicitado para a Etapa 2.
