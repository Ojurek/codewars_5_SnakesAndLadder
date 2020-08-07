#include <iostream>
#include <string>
#include <cassert>

struct Player
{
    int number;
    int position;
};

class SnakesLadders
{
private:
    int board[101] = {0, 1, 38, 3, 4, 5, 6, 14, 31, 9, 10, 11, 12, 13, 14, 26, 6, 17, 18, 19, 20, 42, 22, 23, 24, 25, 26, 27, 84, 29, 30, 31, 32, 33, 34, 35, 44, 37, 38, 39, 40, 41, 42, 43, 44, 45, 25, 47, 48, 11, 50, 67, 52, 53, 54, 55, 56, 57, 58, 58, 60, 61, 19, 63, 60, 65, 66, 67, 68, 69, 70, 91, 72, 73, 53, 75, 76, 77, 98, 79, 80, 81, 82, 83, 84, 85, 86, 94, 88, 68, 90, 91, 88, 93, 94, 75, 96, 97, 98, 80, 100};
    Player player[2];
    int activePlayerIndex = 0;
    bool gameFinished = false;

public:
    SnakesLadders();
    std::string play(int die1, int die2);

    int getBoardValue(int index)
    {
        return board[index];
    }
};

SnakesLadders::SnakesLadders()
{
    player[0].number = 1;
    player[0].position = 0;
    player[1].number = 2;
    player[1].position = 0;
}

std::string SnakesLadders::play(int die1, int die2)
{

    if (gameFinished == true)
    {
        return "Game over!";
    }

    int newBordIndex = player[activePlayerIndex].position + die1 + die2;
    if (newBordIndex > 100)
    {
        newBordIndex = 200 - newBordIndex;
    }

    player[activePlayerIndex].position = board[newBordIndex];

    if (player[activePlayerIndex].position == 100)
    {
        gameFinished = true;
        return "Player " + std::to_string(player[activePlayerIndex].number) + " Wins!";
    }

    std::string result = "Player " + std::to_string(player[activePlayerIndex].number) + " is on square " + std::to_string(player[activePlayerIndex].position);

    if (die1 != die2)
    {
        activePlayerIndex = (activePlayerIndex + 1) % 2;
    }

    return result;
};

bool checkResult(std::string received, std::string expected)
{
    return received == expected;
}

int main()
{
    SnakesLadders game;

    assert(checkResult(game.play(1, 1), std::string("Player 1 is on square 38")));
    assert(checkResult(game.play(1, 5), std::string("Player 1 is on square 44")));
    assert(checkResult(game.play(6, 2), std::string("Player 2 is on square 31")));
    assert(checkResult(game.play(1, 1), std::string("Player 1 is on square 25")));
    std::cout << "Test passed";
}