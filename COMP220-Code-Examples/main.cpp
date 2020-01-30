#include <iostream>
#include <SDL.h>

int main(int argc, char ** argsv)
{
	//Initialises the SDL Library, passing in SDL_INIT_VIDEO to only initialise the video subsystems
	//https://wiki.libsdl.org/SDL_Init
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		//Display an error message box
		//https://wiki.libsdl.org/SDL_ShowSimpleMessageBox
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "SDL_Init failed", SDL_GetError(), NULL);
		return 1;
	}

	//Create a window, note we have to free the pointer returned using the DestroyWindow Function
	//https://wiki.libsdl.org/SDL_CreateWindow
	SDL_Window* window = SDL_CreateWindow("SDL2 Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1280, 720, SDL_WINDOW_SHOWN);

	SDL_Renderer* SDL_GetRenderer(SDL_Window * window);

	/* CreateRenderer is called to enable draw calls*/
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
	
	/* Set the color for drawing */
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);


	//Checks to see if the window has been created, the pointer will have a value of some kind
	if (window == nullptr)
	{
		//Show error
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "SDL_CreateWindow failed", SDL_GetError(), NULL);
		//Close the SDL Library
		//https://wiki.libsdl.org/SDL_Quit
		SDL_Quit();
		return 1;
	}

	
	int xCoords = 0;
	int yCoords = 0;

	SDL_Rect rectangle;


	//Event loop, we will loop until running is set to false, usually if escape has been pressed or window is closed
	bool running = true;
	//SDL Event structure, this will be checked in the while loop
	SDL_Event ev;
	while (running)
	{
		//Poll for the events which have happened in this frame
		//https://wiki.libsdl.org/SDL_PollEvent
		while (SDL_PollEvent(&ev))
		{
			//Switch case for every message we are intereted in
			switch (ev.type)
			{
				//QUIT Message, usually called when the window has been closed
			case SDL_QUIT:
				running = false;
				break;
				//KEYDOWN Message, called when a key has been pressed down
			case SDL_KEYDOWN:
				//Check the actual key code of the key that has been pressed
				switch (ev.key.keysym.sym)
				{
					//Escape key
				case SDLK_ESCAPE:
					running = false;
					break;
				
				case SDLK_d:
					SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
					SDL_RenderClear(renderer);

					SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

					xCoords += 10;

					
					rectangle.x = xCoords;
					rectangle.y = yCoords;
					rectangle.w = 50;
					rectangle.h = 50;
					break;

				case SDLK_s:
					SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
					SDL_RenderClear(renderer);

					SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

					yCoords += 10;

					rectangle.x = xCoords;
					rectangle.y = yCoords;
					rectangle.w = 50;
					rectangle.h = 50;
					break;

				case SDLK_w:
					SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
					SDL_RenderClear(renderer);

					SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

					yCoords -= 10;

					rectangle.x = xCoords;
					rectangle.y = yCoords;
					rectangle.w = 50;
					rectangle.h = 50;
					break;

				case SDLK_a:
					SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
					SDL_RenderClear(renderer);

					SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

					xCoords -= 10;

					rectangle.x = xCoords;
					rectangle.y = yCoords;
					rectangle.w = 50;
					rectangle.h = 50;
					break;

				case SDLK_r:
					
					printf("Did this work? \n");

					SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
					
					rectangle.x = 0;
					rectangle.y = 0;
					rectangle.w = 50;
					rectangle.h = 50;
					break;
				}
			}
		}

		SDL_RenderFillRect(renderer, &rectangle);
		/* Update the renderer*/
		SDL_RenderPresent(renderer);

		SDL_GL_SwapWindow(window);
	}

	//Destroy the window and quit SDL2, NB we should do this after all cleanup in this order!!!
	//https://wiki.libsdl.org/SDL_DestroyWindow
	SDL_DestroyWindow(window);
	//https://wiki.libsdl.org/SDL_Quit
	SDL_Quit();

	return 0;
}