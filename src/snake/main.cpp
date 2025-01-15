#include <SFML/Graphics.hpp>
#include "GameManager.h"
#include <random>
#include <iostream>

int main()
{
	//GameManager
	{
		GameManager* gameManager = new GameManager();
		gameManager->Run();
		delete gameManager;
		/*
		//GameManager();
		{
			std::mt19937 gen;
			gen.seed(time(nullptr));

			sf::RenderWindow window(sf::VideoMode(800, 600), "Snake");

			//snake
			{
				//Snake();
				{
					sf::RectangleShape shape(sf::Vector2f(32, 32));

					std::vector<sf::Vector2f> snakeBody;
					snakeBody.push_back(sf::Vector2f(0, 0));
					sf::Vector2f snakeDirection(0, 0);
				}
			}

			//Food
			{
				//Food();
				{
					sf::RectangleShape shape(sf::Vector2f(32, 32));
					sf::Vector2f foodPosition;
					//SeachPlace();
					{
						bool found;
						do
						{

							found = false;
							sf::Vector2f tmpPosition((int)(gen() % 23) - 12, (int)(gen() % 17) - 8);
							if (std::find(snakeBody.begin(), snakeBody.end(), tmpPosition) != snakeBody.end()) 
							{
								found = true;
							}
							foodPosition = tmpPosition;
						} while (found);
					}
				}
			}



			sf::View v = window.getDefaultView();
			v.setCenter(0, 0);

			window.setView(v);


			float time_between_move = 0.5f;
			float current_timer_between_move = 0.f;

			bool gameover = false;

			sf::Clock c;
		}

		//Run();
		{
			// run the program as long as the window is open
			while (window.isOpen())
			{
				float deltaTime = c.restart().asSeconds();
				//Input
				{
					//Update();
					{
						// check all the window's events that were triggered since the last iteration of the loop
						sf::Event event;
						while (window.pollEvent(event))
						{
							// "close requested" event: we close the window
							if (event.type == sf::Event::Closed)
							{
								window.close();
							}

							if (event.type == sf::Event::KeyPressed) 
							{
								if (event.key.scancode == sf::Keyboard::Scancode::Left) 
								{
									snakeDirection = sf::Vector2f(-1, 0);
								}
								if (event.key.scancode == sf::Keyboard::Scancode::Right) 
								{
									snakeDirection = sf::Vector2f(1, 0);
								}
								if (event.key.scancode == sf::Keyboard::Scancode::Up) 
								{
									snakeDirection = sf::Vector2f(0, -1);
								}
								if (event.key.scancode == sf::Keyboard::Scancode::Down) 
								{
									snakeDirection = sf::Vector2f(0, 1);
								}
							}
						}
					}
				}

				window.clear(sf::Color::Black);
				if (!gameover) 
				{
					//Snake
					{
						//Update();
						{
							if (current_timer_between_move <= 0)
							{
								//Move();
								{
									if (snakeDirection.x != 0 || snakeDirection.y != 0)
									{
										sf::Vector2f nextPosition = snakeBody[0] + snakeDirection;
										if (std::find(snakeBody.begin(), snakeBody.end(), nextPosition) == snakeBody.end())
										{
											//CollideFood();
											{
												if (nextPosition == foodPosition)
												{
													//SizePlusPlus();
													{
														//SeachPlace();
														{
															do
															{
																found = false;
																sf::Vector2f tmpPosition((int)(gen() % 23) - 12, (int)(gen() % 17) - 8);
																if (std::find(snakeBody.begin(), snakeBody.end(), tmpPosition) != snakeBody.end() && nextPosition != tmpPosition)
																{
																	found = true;
																}
																foodPosition = tmpPosition;
															} while (found);
														}
														snakeBody.push_back(snakeBody[snakeBody.size() - 1]);
													}
												}
											}
											for (int i = snakeBody.size() - 1; i > 0; --i) {
												snakeBody[i] = snakeBody[i - 1];
											}
											snakeBody[0] = nextPosition;
										}
										else
										{
											gameover = true;
										}

									}
								}
								current_timer_between_move += (time_between_move - 0.01f * snakeBody.size() < 0.06f) ? 0.06f : (time_between_move - 0.01f * snakeBody.size());
							}
							else
							{
								current_timer_between_move -= deltaTime;
							}
						}
					}

					//Snake();
					{
						//Show();
						{
							for (sf::Vector2f p : snakeBody)
							{
								shape.setPosition(p * shape.getSize().x);
								shape.setFillColor(sf::Color::Green);
								window.draw(shape);
							}
						}
					}

					//Food();
					{
						//Show();
						{
							shape.setPosition(foodPosition * shape.getSize().x);
							shape.setFillColor(sf::Color::Red);
							window.draw(shape);
						}
					}
					
				}

				window.display();
			}

		}*/
	}

	return 0;
}
