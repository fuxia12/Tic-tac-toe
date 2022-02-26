# Tic-tac-Toe 

**[Tic-tac-toe](https://tictactoebeast.com/post/what-is-tic-tac-toe-game/ "Tic-tac-toe")** (also called noughts and crosses) is a pencil-and-paper game for two players, **X** and **O**, who take turns marking the spaces in a **3×3** grid. The player who succeeds in placing three of their marks in a horizontal, vertical, or diagonal row wins the game.

This **Tic-tac-toe** model was developed with the user's entertainment in mind, so this project has some mechanisms that help with this, such as: report generator for each match, read the reports generated easily and among others. In addition, the project has two game modes, namely **Player x Player** and **Human x Computer**.

## Requirements

- **[GCC](https://gcc.gnu.org/)** - `11.2.0`

## Installation

```shell
$ git clone https://github.com/fuxia12/Tic-tac-toe
$ cd Tic-tac-toe
$ make
$ ./tic-tac-toe
```

## Usage

Using this **Tic-tac-toe** game is very simple, and below is some useful information on how to use it:

- In **Player x Player** mode it is necessary to enter the nickname of both players that will participate in the match.

- A report is generated at the end of each match and contains general information about that match. These reports are generated in the **reports** directory with certain identification codes for each report.

- The **clear-reports** script located inside the reports directory has the functionality to delete all previously generated reports and use it when necessary.

- There is another script that is interesting to use and makes reading reports easier - the read-report script is used to read reports generated from your ID code. Use `./read-report -h` to understand how to use it.

- The style of this **Tic-tac-toe** game is based on the chess format, for example: `C1, A2, B3` to make a move on those squares of the 3x3 board. If you want to learn more about how to play and other information, go to **"How to Play"** in the menu.


## Other information

> NOTE: This project was developed with GNU/Linux in mind, which means that it will not run on Windows-like environments. If you want to run this application in your Windows environment try using features like **[WSL](https://docs.microsoft.com/en-us/windows/wsl/install)** or Virtualization with **[VMware](https://customerconnect.vmware.com/downloads/#all_products)** or **[VirtualBox](https://www.virtualbox.org/wiki/Downloads)**.

> 

