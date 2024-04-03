#include <iostream>
#include <ctime>

void drawBoard(char *spaces);
void playerMove(char *spaces, char player);
void computerMove(char *spaces, char computer);
bool checkWinner(char *spaces, char player, char computer);
bool checkTie(char *spaces);

int main() {
    char player = 'X';
    char computer = 'O';
    char spaces[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    bool winner, tie;
    drawBoard(spaces);

    while(true) {
        playerMove(spaces, player);
        drawBoard(spaces);

        winner = checkWinner(spaces, player, computer);
        if (winner) {
            break;
        }
        tie = checkTie(spaces);
        if (tie) {
            break;
        }
        computerMove(spaces, computer);
        drawBoard(spaces);

        winner = checkWinner(spaces, player, computer);
        if (winner) {
            break;
        }
        tie = checkTie(spaces);
        if (tie) {
            break;
        }
    }

    return 0;
}

void drawBoard(char *spaces){
    std::cout << '\n';
    std::cout << "     |     |     " << std::endl;
    std::cout << "  " << spaces[0] <<"  |  "<< spaces[1] <<"  |  " << spaces[2] << "  " << std::endl;
    std::cout << "_____|_____|_____" << std::endl;
    std::cout << "     |     |     " << std::endl;
    std::cout << "  " << spaces[3] <<"  |  "<< spaces[4] <<"  |  " << spaces[5] << "  " << std::endl;
    std::cout << "_____|_____|_____" << std::endl;
    std::cout << "     |     |     " << std::endl;
    std::cout << "  " << spaces[6] <<"  |  "<< spaces[7] <<"  |  " << spaces[8] << "  " << std::endl;
    std::cout << "     |     |     " << std::endl;
    std::cout << '\n';
}
void playerMove(char *spaces, char player){
    int pos;
    while(true){
        std::cout << "Escolha onde quer jogar [1-9]: ";
        std::cin >> pos;
        pos--;
        if ((pos >= 0 && pos <= 8) && spaces[pos] == ' ') {
            spaces[pos] = player;
            break;
        }
    }
}
void computerMove(char *spaces, char computer){
    srand(time(0));
    int pos;
    while (true) {
        pos = rand() % 9;
        if (spaces[pos] == ' '){
            spaces[pos] = computer;
            return;
        } 
    }
}
bool checkWinner(char *spaces, char player, char computer){
    if (spaces[0] != ' ' && spaces[0] == spaces[1] && spaces[1] == spaces[2]){
        // someone wins
        if (spaces[0] == player) {
            std::cout << "VOCE GANHOU" << std::endl;
        } else {
            std::cout << "VOCE PERDEU" << std::endl;
        }
        return true;
    }
    else if (spaces[3] != ' ' && spaces[3] == spaces[4] && spaces[4] == spaces[5]){
        // someone wins
        if (spaces[3] == player) {
            std::cout << "VOCE GANHOU" << std::endl;
        } else {
            std::cout << "VOCE PERDEU" << std::endl;
        }
        return true;
    }
    else if (spaces[6] != ' ' && spaces[6] == spaces[7] && spaces[7] == spaces[8]){
        // someone wins
        if (spaces[6] == player) {
            std::cout << "VOCE GANHOU" << std::endl;
        } else {
            std::cout << "VOCE PERDEU" << std::endl;
        }
        return true;
    }
    else if (spaces[0] != ' ' && spaces[0] == spaces[3] && spaces[3] == spaces[6]){
        // someone wins
        if (spaces[0] == player) {
            std::cout << "VOCE GANHOU" << std::endl;
        } else {
            std::cout << "VOCE PERDEU" << std::endl;
        }
        return true;
    }
    else if (spaces[1] != ' ' && spaces[1] == spaces[4] && spaces[4] == spaces[7]){
        // someone wins
        if (spaces[1] == player) {
            std::cout << "VOCE GANHOU" << std::endl;
        } else {
            std::cout << "VOCE PERDEU" << std::endl;
        }
        return true;
    }
    else if (spaces[2] != ' ' && spaces[2] == spaces[5] && spaces[5] == spaces[8]){
        // someone wins
        if (spaces[2] == player) {
            std::cout << "VOCE GANHOU" << std::endl;
        } else {
            std::cout << "VOCE PERDEU" << std::endl;
        }
        return true;
    }
    else if (spaces[0] != ' ' && spaces[0] == spaces[4] && spaces[4] == spaces[8]){
        // someone wins
        if (spaces[0] == player) {
            std::cout << "VOCE GANHOU" << std::endl;
        } else {
            std::cout << "VOCE PERDEU" << std::endl;
        }
        return true;
    }
    else if (spaces[2] != ' ' && spaces[2] == spaces[4] && spaces[4] == spaces[6]){
        // someone wins
        if (spaces[2] == player) {
            std::cout << "VOCE GANHOU" << std::endl;
        } else {
            std::cout << "VOCE PERDEU" << std::endl;
        }
        return true;
    }
    return false;
}
bool checkTie(char *spaces){
    for (int i=0; i < 9; i++) {
        if (spaces[i] == ' ') {
            return false;
        }
    }
    std::cout << "EMPATE!";
    return true;
}