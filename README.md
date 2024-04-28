<div align="center">
  <strong>
  <img width="70%" src="https://github.com/LuisHenriqueDaSilv/tictactoeGameWithC/blob/main/github/print.png?raw=true" alt="print"/>
    <h1>TicTacToe</h1>
  <p>"Jogo da velha" simples , desenvolvido com o intuito de estudar os conceitos básicos da linguagem C. Como variaveis, matrizes, tipos, entrada e saida padrão de dados (Via terminal), funções, manipulação de dados, entre outros.</p>
  </strong>
  <br/>
  <br/>

</div>




### Como funciona
Para jogar é simples. Após executar o programa, sera mostrado um menu onde você pode escolher entre: <br/>
 
***Jogar:*** Sera mostrado o tabuleiro com o tamanho configurado o usuário deverá informar a posição onde cada jogador deseja jogar. Após o final da partida, o programa encontrará se há algum vencedor e informará quem é, caso não haja, o programa informa que foi um empate e retorna ao menu.

***Editar Tamanho do tabuleiro:*** Sera perguntado ao usuário tamanho desejado para o tabuleiro (É possivel jogar em qualquer tabuleiro entre 2x2 e 9x9, padrão: 3x3). 

***sair do jogo:***  Caso opte por sair do jogo, o programa sera finalizado. 

### Como usar:
Para utilizar o programa já compilado, clone o repositório do github em sua máquina e execute o arquivo **run** da seguinte maneira: 
```sh
git clone https://github.com/LuisHenriqueDaSilv/tictactoeGameWithC.git #Clona o repositório em sua maquina

cd  tictactoeGameWithC #Entra no diretório onde o repositório foi clonado

./run #executa o programa
```

### Como compilar: 
Para compilar o programa em sua máquina, clone o repositório do github em sua máquina e utilize o make ou compile utilizando o gcc utilizando os seguintes comandos: 

#### Utilizando o make:
```sh
git clone https://github.com/LuisHenriqueDaSilv/tictactoeGameWithC.git #Clona o repositório em sua maquina

cd  tictactoeGameWithC #Entra no diretório onde o repositório foi clonado

rm ./run # Apaga o programa já compilado existente no repositório

make ## Utiliza os scrips escritos no arquivo Makefile do projeto e gera do

./run #executa o programa
```

#### Utilizando o gcc:
```sh

git clone https://github.com/LuisHenriqueDaSilv/tictactoeGameWithC.git #Clona o repositório em sua maquina

cd  tictactoeGameWithC #Entra no diretório onde o repositório foi clonado

rm ./run # Apaga o programa já compilado existente no repositório

gcc ./src/main.c ./src/Logic/verifyWinner.c ./src/Tools/printBoard.c ./src/Logic/handleInput.c ./src/Tools/clearTerminal.c -o ./run

./run #executa o programa
```