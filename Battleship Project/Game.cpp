#include "Game.h"


Game::Game(sf::ContextSettings settings):
	m_window(sf::VideoMode(1280, 720), "Battleship", sf::Style::Default, settings)
{
	
}


Game::~Game()
{
	
}

///<summary>
/// Run function which handles the game loop
///<summary>
void Game::run()
{
	AiPlayer aiPlayer;

	std::string name;
	std::cin >> name;
	Player player = inputName(name);


	giveTurn(player.m_myTurn);
	while (true)
	{
		while (player.m_myTurn)
		{
			sf::Vector2i guess = player.takeGuess();
			
			processShot(player, aiPlayer, guess);
			
		}

		while (aiPlayer.m_myTurn)
		{
			sf::Vector2i guess = aiPlayer.takeGuess();

			processShot(aiPlayer, player, guess);
		}
	}
	/*m_clock.restart();
	while(m_window.isOpen())
	{
		proccessEvents();
		m_elapsedTime += m_clock.restart();
		while (m_elapsedTime > FRAMES_PER_SECOND)
		{
			m_elapsedTime -= FRAMES_PER_SECOND;
			update(FRAMES_PER_SECOND);
		}
		render();
	}*/
}

///<summary>
/// Update for the Game class.
/// Handles all rendering that
/// happen on the screen at a given time
///<summary>
void Game::update(sf::Time const &)
{
	
	

}

///<summary>
/// Update for the Game class.
/// Handles all updates to the screen 
/// that happen in the game.
///<summary>
void Game::render()
{
	m_window.clear();
	
	m_window.display();
}

///<summary>
/// Event Handler for the game
///<summary>
void Game::proccessEvents()
{
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::KeyPressed: /*KeyPress event manager*/
			switch (event.key.code)
			{
			case sf::Keyboard::Escape:
				m_window.close();
				break;
			default:
				break;
			}
			break;
		case sf::Event::Closed: /* "X" icon event handler */
			m_window.close();
			break;
		default:
			break;
		}
	}
}

void Game::giveTurn(bool & turn)
{
	turn = true;
}

void Game::printRules()
{

}

void Game::displayShotResult(std::string result)
{
}


Player Game::inputName(std::string name)
{
	std::cout << "Enter Player Name" << std::endl;
	return Player(name);
}

void Game::processShot(Player &player, AiPlayer &aiPlayer, sf::Vector2i & guess)
{

	if (aiPlayer.m_board.m_board[guess.x][guess.y].m_containsShip && !aiPlayer.m_board.m_board[guess.x][guess.y].m_hit)
	{
		player.m_score++;
		std::cout << "HIT" << std::endl;
		aiPlayer.m_board.m_board[guess.x][guess.y].m_containsShip = false;
	}
	else
	{
		player.m_myTurn = false;
		std::cout << "MISS" << std::endl;
		giveTurn(aiPlayer.m_myTurn);
	}

}

void Game::processShot(AiPlayer & player, Player & aiPlayer, sf::Vector2i & guess)
{
	if (aiPlayer.m_board.m_board[guess.x][guess.y].m_containsShip && !aiPlayer.m_board.m_board[guess.x][guess.y].m_hit)
	{
		player.m_score++;
		std::cout << "HIT" << std::endl;
		aiPlayer.m_board.m_board[guess.x][guess.y].m_containsShip = false;
	}
	else
	{
		player.m_myTurn = false;
		std::cout << "MISS" << std::endl;
		giveTurn(aiPlayer.m_myTurn);
	}
}

void Game::checkWinner(AiPlayer & aiPlayer, Player & player)
{

}

void Game::displayWinner()
{
}

void Game::displayWinnerScore()
{
}
