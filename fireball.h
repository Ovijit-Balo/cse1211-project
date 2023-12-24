#include "headers.h"

class Fireball
{
	public:
		static const int Fireball_WIDTH = 20;
		static const int Fireball_HEIGHT = 20;
		int mPosX, mPosY;
		int mVelX;
		int flag_of_fireball;
		
		static const int Fireball_VEL = 12;

		//Initializes the variables
		Fireball();

		
		
		void move();
		//void close();
	
		void render();
		SDL_Rect Fireball_rect;

    private:

		int f;
};

Fireball::Fireball()
{
	
	mVelX=Fireball_VEL;
	flag_of_fireball=0;
	Fireball_rect.w=Fireball_WIDTH;
	Fireball_rect.h=Fireball_HEIGHT;
}	

void Fireball::move()
{
	mPosX+=mVelX;
	Fireball_rect.x=mPosX;
	Fireball_rect.y=mPosY;
}





