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
	
	
	//vector2 paddle_pos;
	//int paddle_dir;
	//const int paddle_h = 100;
//	vector2 ball_pos;
	//vector2 ball_vel;



	Uint32 ticks_count;

	const int thickness = 15;

	bool is_running;

	int window_height;
	int window_width;

};
