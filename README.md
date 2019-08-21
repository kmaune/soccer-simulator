# soccer-simulator

Project to simulate a soccer game in C++

### Compiling & Running

To compile, after downloading or cloning the repository, run:

	g++ -std=c++17 -Werror Field.cpp Game.cpp soccer.cpp Player.cpp Team.cpp Goalkeeper.cpp Defender.cpp Midfielder.cpp Forward.cpp -o soccer 

**Note:** The code can also be compiled using C++11 or C++14

Then, to run:

	./soccer


### Overview

This project simulates a soccer game between two teams. The game is played between two teams with the game ending when one team scores 3 goals or when time runs out. 

Each team is created with 1 goalkeeper, and a 4-3-3 formation. Team 1 starts with the ball. 

The field is broken down into components based on Pep Guardiolas positional/field grid tactics. ([Reference](https://coachdibernardo.com/2018/01/27/pep-guardiolas-positional-grid-a-cognitive-roadmap-for-players/))

A player in possession of the ball has the option to shoot, pass or dribble, whereas a player without possession of the ball has the option to move or stay where they are. 

One iteration of the game (This can also be thought of as 'one minute' for simplicity) occurs when each player on the pitch makes a move. 
The first player to make a move is the player on the ball. Then every remaining player makes their off ball move. This is repeated until the game is over due to the score limit being reached or the time limit running out. 

After a goal, the opposing team is given possession and the game is continued.


### Planned Future Improvements 

	- Usage of attributes/skills by position to determine success of passes/shots/dribbles.
	- Better incorporation of Goalkeeper for each team
	- Better movement functionality
	- Different formations
	- Verbose and non-verbose mode
	- Reset player positions after a goal
	- Improve initial player positioning setup