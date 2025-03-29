#include <iostream>
#include <cstdlib>   
#include <ctime>     
#include <limits>    

void playGame() {
  
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    int secretNumber = std::rand() % 100 + 1;

    int attempts = 0; 
    int guess = 0;    

    std::cout << "Добро пожаловать в игру \"Угадай число\"!" << std::endl;
    std::cout << "Программа загадала число от 1 до 100. Попробуйте угадать его!" << std::endl;

    while (true) {
        std::cout << "\nВведите ваше предположение: ";
        std::cin >> guess;

        if (std::cin.fail()) {
            std::cin.clear(); 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
            std::cout << "Пожалуйста, введите корректное число!" << std::endl;
            continue;
        }

        attempts++;

        if (guess < secretNumber) {
            std::cout << "Загаданное число больше." << std::endl;
        } else if (guess > secretNumber) {
            std::cout << "Загаданное число меньше." << std::endl;
        } else {
            std::cout << "Поздравляем! Вы угадали число " << secretNumber << " за " << attempts << " попыток!" << std::endl;
            break;
        }
    }
}

int main() {
    char playAgain = 'y';

    do {
        playGame();

        std::cout << "\nХотите сыграть ещё раз? (y/n): ";
        std::cin >> playAgain;

        while (playAgain != 'y' && playAgain != 'n') {
            std::cout << "Введите 'y' для продолжения или 'n' для выхода: ";
            std::cin >> playAgain;
        }

    } while (playAgain == 'y');

    std::cout << "Спасибо за игру! До свидания." << std::endl;

    return 0;
}