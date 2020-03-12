#include <iostream>

enum game_result { WIN, LOSE, TIE, CANCEL };

int main()
{
	game_result result, omit = CANCEL;

	int count;

	for (count = WIN; count <= CANCEL; count++)
	{
		result = (game_result)count;

		if (result == omit)
			std::cout << "The game was cancelled" << std::endl;

		else
		{
			std::cout << "The game was played ";
			if (result == WIN)
				std::cout << "and we won!";
			if (result == LOSE)
				std::cout << "and you are lost!!!:).";
			std::cout << std::endl;
		}
	}

	return 0;
}
