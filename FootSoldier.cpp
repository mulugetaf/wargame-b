
#include <string>
#include <vector>
#include <stdexcept>
#include <iostream>
#include "FootSoldier.hpp"

void FootSoldier::Full_attack(Soldier &other, std::vector<std::vector<Soldier *>> board, std::pair<int, int> p)
{
    Basic_attack(other, board, p);
}
void FootSoldier::Basic_attack(Soldier &other, std::vector<std::vector<Soldier *>> board, std::pair<int, int> p)
{
    int i = (int)p.first;
    int j = (int)p.second;

    if (board[i][j] != nullptr)
    {
        if (board[i][j]->player_health <= 10)
        {
            board[i][j]->player_health = 0;
        }
        else
        {
            board[i][j]->player_health =
                board[i][j]->player_health - other.player_damge;
        }
    }
}
