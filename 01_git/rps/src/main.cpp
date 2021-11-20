/*
 * COPYRIGHT (C) 2021 Oleksandr Aleksieiev
 * all rights reserved
*/

#include <iostream>

#include "datatypes/constants.h"
#include "driver/player_move.h"
#include "ui/user_interface.h"

using namespace rps;

int main() {
    char user_option = ' ';

    while (user_option != EXIT_OPTION) {
        UserInterface::printInviteMessage();
        std::cin >> user_option;
        if (user_option != EXIT_OPTION) {
            auto user = PlayerMove(user_option);
            if (user.isValid()) {
                auto pc = PlayerMove();
                pc.print("I choose ");
                user.print("Your option is ");
                UserInterface::printGameResult(pc == user);
            } else {
                UserInterface::printInvalidInputMessage();
            }
        }
    }
    UserInterface::printExitMessage();

    return 0;
}
