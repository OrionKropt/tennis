#include "game.h"

Game::Game() 
{
    // Window size
    window_height = 768;
    window_width = 1024;

    paddle_1.height = 100;
    paddle_1.width = 15;
    paddle_2.height = 100;
    paddle_2.width = 15;
    paddle_1.transform.position = vector2
    (
        25,
        window_height / 2
    );
    paddle_2.transform.position = vector2
    (
        window_width - 25,
        window_height / 2
    );
   
    paddle_1.transform.velocity = paddle_2.transform.velocity = vector2(0, 300);

    paddle_1.transform.dir = paddle_2.transform.dir = 0;

    ball.transform.position = vector2(window_width / 2, window_height / 2);
    ball.transform.velocity = vector2(-300, 275);
    ball.height = ball.width = 15;
    ticks_count = 0;

    /*paddle_pos.x = ball_pos.x = 1024 / 2;
    paddle_pos.y = ball_pos.y = 768 / 2;*/

    /*ball_vel.x = -285.0f;
    ball_vel.y = 250.0f;*/

    //paddle_dir = 0;

   
}

bool Game::initialize()
{
    int sdl_res = SDL_Init(SDL_INIT_VIDEO);
    if (sdl_res)
    {
        SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
        return false;
    }
     
   

    window = SDL_CreateWindow("Chapter 1",
        100,   // Top left x of window

        100,   // Top left y of window

        window_width,  // Width of window

        window_height,   // Height of window

        0);    // Flags (0 for no flags set)
    
    if (window == nullptr)
    {
        SDL_Log("Unable to create window : %s", SDL_GetError());
        return false;
    }

    renderer = SDL_CreateRenderer(window,
        -1,
        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
    );

    if (renderer == nullptr)
    {
        SDL_Log("Unable to create renderer : %s", SDL_GetError());
        return false;
    }

  

    is_running = true;
    return true;
}

void Game::run_loop()
{
    while (is_running)
    {
        process_input();
        
        update_game();

        generate_output();
    }

}

void Game::shutdown()
{
    SDL_DestroyRenderer(renderer);

    SDL_DestroyWindow(window);

    SDL_Quit();

}

void Game::process_input()
{
    SDL_Event event;

    const Uint8* state = SDL_GetKeyboardState(NULL);

    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_QUIT:
            is_running = false;
            break;
        default:
            break;
        }
    }

    if (state[SDL_SCANCODE_ESCAPE])
        is_running = false;


    paddle_1.transform.dir = 0;
    paddle_2.transform.dir = 0;

    if (state[SDL_SCANCODE_W])
        paddle_1.transform.dir -= 1;

    if (state[SDL_SCANCODE_S])
        paddle_1.transform.dir += 1;

    if (state[SDL_SCANCODE_UP])
        paddle_2.transform.dir -= 1;

    if (state[SDL_SCANCODE_DOWN])
        paddle_2.transform.dir += 1;


}

void Game::update_game()
{
    while (!SDL_TICKS_PASSED(SDL_GetTicks(), ticks_count + 16));

    float delta_time = (SDL_GetTicks() - ticks_count) / 1000.0f;

    ticks_count = SDL_GetTicks();

    if (delta_time > 0.05f)
        delta_time = 0.05f;

    if (paddle_1.transform.dir != 0)
    {
      
        paddle_1.transform.position += (paddle_1.transform.velocity * paddle_1.transform.dir * delta_time);

        if (paddle_1.transform.position.y < (-paddle_1.height / 2.0f + paddle_1.width))
            paddle_1.transform.position.y = -paddle_1.height / 2.0f + paddle_1.width;

        
        else if (paddle_1.transform.position.y > (window_height - paddle_1.height / 2.0f - paddle_1.width))
            paddle_1.transform.position.y = window_height - paddle_1.height / 2.0f - paddle_1.width;
        //SDL_Log("%f", paddle_pos.y);
    }
    if (paddle_2.transform.dir != 0)
    {
        
        paddle_2.transform.position += paddle_2.transform.velocity * paddle_2.transform.dir * delta_time;

        if (paddle_2.transform.position.y < (-paddle_2.height / 2.0f + paddle_2.width))
            paddle_2.transform.position.y = -paddle_2.height / 2.0f + paddle_2.width;


        else if (paddle_2.transform.position.y > (window_height - paddle_2.height / 2.0f - paddle_2.width))
            paddle_2.transform.position.y = window_height - paddle_2.height / 2.0f - paddle_2.width;
    }

    ball.transform.position += ball.transform.velocity * delta_time;
   

    if (ball.transform.position.y <= thickness && ball.transform.velocity.y < 0)
        ball.transform.velocity.y *= -1;
    else if (ball.transform.position.y >= (window_height - thickness) && ball.transform.velocity.y > 0)
        ball.transform.velocity.y *= -1;

    float dif = fabs(ball.transform.position.y - paddle_1.transform.position.y);
    if 
        (
            dif <= (paddle_1.height / 2) &&
            ball.transform.position.x <= (paddle_1.transform.position.x + (paddle_1.width / 2)) &&
            ball.transform.position.x >= (paddle_1.transform.position.x + (paddle_1.width / 2) - 5) &&
            ball.transform.velocity.x < 0
        )
        ball.transform.velocity.x *= -1;

    dif = fabs(paddle_2.transform.position.y - ball.transform.position.y);
    if 
        (
            dif <= (paddle_2.height / 2) &&
            ball.transform.position.x >= (paddle_2.transform.position.x - (paddle_2.width / 2)) &&
            ball.transform.position.x <= (paddle_2.transform.position.x - (paddle_2.width / 2) + 5) &&
            ball.transform.velocity.x > 0
        )
        ball.transform.velocity.x *= -1;

 
    

}

void Game::generate_output()
{
    SDL_SetRenderDrawColor(
        renderer,
        255,
        0,
        255,
        255
    );

    SDL_RenderClear(renderer);



    SDL_SetRenderDrawColor(
        renderer,
        0,
        0,
        255,
        255
    );
   

    //                    walls
    SDL_Rect  wall_top
    {
       0,        // Top x
       0,        // Top y
       window_width,     // Width
       thickness // Height 
    };

    SDL_Rect wall_down
    {
        0,
        window_height - thickness,
        window_width,
        thickness
    };
    SDL_RenderFillRect(renderer, &wall_top);
    SDL_RenderFillRect(renderer, &wall_down);
    //                    walls

    SDL_SetRenderDrawColor(
        renderer,
        255,
        255,
        255,
        255
    );

    ball.rect.x = static_cast<int>(ball.transform.position.x - ball.width / 2);
    ball.rect.y = static_cast<int>(ball.transform.position.y - ball.width / 2);
    ball.rect.w = ball.rect.h = ball.height;
   

  /*  SDL_Rect ball
    {
        static_cast<int>(ball .x - thickness / 2),
        static_cast<int>(ball_pos.y - thickness / 2),
        thickness,
        thickness
    };*/

    paddle_1.rect.x = static_cast<int>(paddle_1.transform.position.x);
    paddle_1.rect.y = static_cast<int>(paddle_1.transform.position.y);
    paddle_1.rect.w = paddle_1.width;
    paddle_1.rect.h = paddle_1.height;

    paddle_2.rect.x = static_cast<int>(paddle_2.transform.position.x);
    paddle_2.rect.y = static_cast<int>(paddle_2.transform.position.y);
    paddle_2.rect.w = paddle_2.width;
    paddle_2.rect.h = paddle_2.height;
    /*SDL_Rect paddle
    {
        static_cast<int>(paddle_pos.x - 500),
        static_cast<int>(paddle_pos.y - thickness / 2),
        thickness,
        paddle_h
    };*/

    SDL_RenderFillRect(renderer, &ball.rect);
    SDL_RenderFillRect(renderer, &paddle_1.rect);
    SDL_RenderFillRect(renderer, &paddle_2.rect);
   
    SDL_RenderPresent(renderer);

    
}
