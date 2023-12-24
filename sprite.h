#include "headers.h"
class Sprite
{
    public:
		//The dimensions of the sprite
		static const int Sprite_WIDTH = 63;
		static const int Sprite_HEIGHT = 85;
		int mPosX, mPosY;
		//Maximum axis velocity of the sprite
		static const int Sprite_VEL = 10;
		int jumped;
        int fireball_throwed;
		int Life;
		
		int hitten;
		//Initializes the variables
		Sprite();

		//Takes key presses and adjusts the sprite's velocity
		void handleEvent( SDL_Event& e );

		//Moves the sprite
		void move();
		void jump();
		void init();
		//Shows the sprite on the screen
		void render(SDL_Rect* currentClip);
		double initial ;
		double velocity;
		double gravity;
		SDL_Rect Sprite_Rect;
    private:
		//The X and Y offsets of the sprite
		

		//The velocity of the sprite
		int mVelX, mVelY;
};
void Sprite::init()
{
	mPosX = 40;
    mPosY = GROUND;//GROUND = 625;

    //Initialize the velocity

    mVelX = 0;
    mVelY = 0;
    jumped=0;
    hitten = 0;
    fireball_throwed=0;
    initial = -13;
    velocity=initial;
 	gravity=0.5;
 	Sprite_Rect.w=Sprite_WIDTH;
 	Sprite_Rect.h=Sprite_HEIGHT;
 	Life=100;
 	
}
Sprite::Sprite()
{
    //Initialize the offsets
    mPosX = 40;
    mPosY = GROUND;

    //Initialize the velocity
    hitten = 0;
    mVelX = 0;
    mVelY = 0;
    jumped=0;
    fireball_throwed=0;
    initial = -13;
    velocity=initial;
 	gravity=0.5;
 	Sprite_Rect.w=Sprite_WIDTH;
 	Sprite_Rect.h=Sprite_HEIGHT;
 	Life=100;
 	
}

void Sprite::jump()
{
	if(velocity >= abs(initial)+1)
	{
		velocity=initial;
		jumped=0;
	}
	else
	{
		mPosY+=velocity;
		velocity+=gravity;

	}
}

void Sprite::handleEvent( SDL_Event& e )
{
    // cout << mVelX << ' ';

    //If a key was pressed
	if( e.type == SDL_KEYDOWN && e.key.repeat == 0 )
    {
        //Adjust the velocity
        if(!PauseOn)
        switch( e.key.keysym.sym )
        {
        	case 'p': PauseOn=1;break;                  //if P is pressed, game is paused
            case SDLK_UP: mVelY -= Sprite_VEL; break;
            case SDLK_DOWN: mVelY += Sprite_VEL; break;
            case 'a': mVelX -= Sprite_VEL; break;        //if A is pressed,runner goes left
            case 'd': mVelX += Sprite_VEL; break;        //if D is pressed, runner goes right
            case 'w': jumped=1;break;                   //if W is pressed, runner jumps
            case 'q': fireball_throwed=1;break;         //if q is pressed, runner shoots fireballs
            
        }
        else
        {
        	if(e.key.keysym.sym=='p')
        	{
        		PauseOn=0;
        	}
        	mVelX=0;
        }
    }
    //If a key was released
    else if( e.type == SDL_KEYUP && e.key.repeat == 0 )
    {
        //Adjust the velocity
        if(!PauseOn)
        switch( e.key.keysym.sym )
        {
            case SDLK_UP: mVelY += Sprite_VEL; break;
            case SDLK_DOWN: mVelY -= Sprite_VEL; break;
            case 'a': mVelX += Sprite_VEL; break;
            case 'd': mVelX -= Sprite_VEL; break;
            case 'p': mVelX =0;break;
            //case 'q': fireball_throwed=0;break;

        }
        else
        	mVelX=0;
    }
   // cout << "Vel changed to " << mVelX <<endl;
   // cout << PauseOn << endl;
    if(PauseOn)
    {
    	mVelX=0;
    }
    // mVelX = min(0, mVelX);
    // cout << mVelX << endl;
}

void Sprite::move()
{   
    //Move the sprite left or right
    if(jumped)
	{
		jump();
	}

    mPosX += mVelX;
    mPosX=max(mPosX, 40 );
    mPosX=min(mPosX, SCREEN_WIDTH/2 );
    //If the sprite went too far to the left or right
    

    //Move the sprite up or down
    mPosY += mVelY;

    //If the sprite went too far up or down
    if( ( mPosY < 0 ) || ( mPosY + Sprite_HEIGHT > SCREEN_HEIGHT ) )
    {
        //Move back
        mPosY -= mVelY;
    }
    Sprite_Rect.x=mPosX;
    Sprite_Rect.y=mPosY;
}

void Sprite::render(SDL_Rect* currentClip)
{
    gSprite.render(mPosX, mPosY, currentClip);
}
