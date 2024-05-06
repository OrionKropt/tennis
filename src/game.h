#include <SDL.h>
#include "paddle.h"
#include "ball.h"


class Game
{
public:
	Game();

	bool initialize();

	void run_loop();

	void shutdown();
private:
	void process_input();

	void update_game();

	void generate_output();

	SDL_Window* window;

	SDL_Renderer* renderer;

	Paddle paddle_1;
	Paddle paddle_2;
	
	Ball ball;

	Uint32 ticks_count;

	const int thickness = 15; // walls's thikness

	bool is_running;

	int window_height;
	int window_width;

};
