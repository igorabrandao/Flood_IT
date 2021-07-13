#ifndef INPUT_HPP
#define INPUT_HPP

// ***************************************************
// ** Implements the functions related to Input
// ***************************************************
#include <iostream>
#include "FloodIt.h"
#include "GUI.hpp"

using namespace std;

// ***************************************************
// ** Functions
// ***************************************************

namespace Input
{
     /**
      * Function to handle the user input
      */
     int handleInput(const char *prompt, int *i)
     {
          int Invalid = 0;
          int EndIndex;
          char buffer[100];

          do
          {
               if (Invalid)
                    fputs("Invalid option!\n\n", stdout);
               Invalid = 1;
               fputs(prompt, stdout);
               if (NULL == fgets(buffer, sizeof(buffer), stdin))
                    return 1;
               errno = 0;
          } while ((1 != sscanf(buffer, "%d %n", i, &EndIndex)) || buffer[EndIndex] || errno);

          return 0;
     }

     /**
      * Method to handle the main menu input
      */
     void inputMainMenu(FloodIt game_)
     {
          /* Declarações no escopo local */
          int option = 0;

          do
          {
               // Input data
               handleInput("Choose between 1 - 4: ", &option);

               // Validate the input
               switch ((int)option)
               {
               /* Opção inválida */
               case 0:
                    option = 99;
                    printf("Invalid option!\n\n");
                    break;
               // New game
               case 1:
                    GUI::clearConsole();
                    /*inicializarTabuleiro(tabuleiro_, config_->tam_tabuleiro);
                    imprimirTabuleiro(tabuleiro_, config_->tam_tabuleiro);
                    gerarMenuOpcoesJogo();
                    entrarJogada(tabuleiro_, config_, 0);*/
                    break;
               // Settings
               case 2:
                    GUI::clearConsole();
                    /*gerarMenuPrincipal();
                    configurarDificuldade(config_);*/
                    break;
               // Show credits
               case 3:
                    GUI::clearConsole();
                    /*imprimeCreditos();
                    gerarMenuPrincipal();
                    entrarMenu(tabuleiro_, config_);*/
                    break;
               // Exit game
               case 4:
                    printf("\nFinishing...\n\n");
                    exit(0);
                    break;
               // Invalid option
               default:
                    option = 99;
                    printf("Invalid option!\n\n");
                    break;
               }
          } while (option == 99);
     }

     /**
      * Match menu handler
      */
     int inputMatchMenu(FloodIt game_)
     {
          /* TODO */
          return 0;
     }

     /**
      * Difficult level menu handler
      */
     int inputDifficultLevel(FloodIt game_)
     {
          /* TODO */
          return 0;
     }
}

#endif