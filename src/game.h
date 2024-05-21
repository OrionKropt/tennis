#include <SDL.h>
#include <SDL_ttf.h>
#include "paddle.h"
#include "ball.h"
#include <random>

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

	void collisions(Ball& ball);
	

	SDL_Window* window;

	SDL_Renderer* renderer;

	Paddle paddle_1;
	Paddle paddle_2;
	
	Ball ball_1;
	Ball ball_2;

	Uint32 ticks_count;
	Uint32 ball_respawn_timer = 2;
	const Uint32 ball_respawn_delay = 3000; 


	const int thickness = 15; // walls's thikness

	bool is_running;

	int window_height;
	int window_width;


	

};
