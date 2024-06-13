/* PROGRAMMING FUNDAMENTAL'S PROJECT FOR FALL 2022 BS(CS)
 * You don't need to change anything in the driver code/main function except the part(s) where instructed.
 * You are expected to define your functionalities in the "functionality.h" header and call them here in the instructed part(s).
 * The game is started with a small box, you need to create other possible in "pieces.h" file in form of array.
    E.g., Syntax for 2 pieces, each having four coordinates -> int Pieces[2][4];
 * Load the images into the textures objects from img directory.
 * Don't make any changes to the "utils.h" header file except for changing the coordinate of screen or global variables of the game.
 * SUGGESTION: If you want to make changes in "utils.h", do it once you complete rest of the functionalities.
 * TIP: You can study SFML for drawing scenes, sprites and window.
 * */

#include <SFML/Graphics.hpp>
#include <time.h>
#include "utils.h"
#include "pieces.h"
#include "functionality.h"
#include <sstream>
#include<fstream>
#include <SFML/Audio.hpp>
#include<iostream>
using namespace std;
using namespace sf;

int main()
{
    int n=0,a=0,lev=0,count=0,delta_x=0, colorNum=1,score=0,counter=0,x,level,max=0 ;
    bool full=0,bomb=false,space=false,end=false;
    x=rand()%10; 
    float timer=0, delay=0.4;
    sf::Font font;
		if (!font.loadFromFile("arial.ttf"))
		{
    	// error...
		}
   
   	fstream file("score.txt", ios::app);
                	
     file<<score<<endl;
                	file.close();
                	
                	int size=0;
					ifstream infile1("score.txt");
					while(infile1>>score)
					{
						size++;
					}
					infile1.close();
 					//how to read in arrays
 
					int score1[size];
 
					ifstream infile("score.txt");
					int index=0;
					while(infile>>score1[index]){
					//infile>>score;
					index++;}
					infile.close();
   
    srand(time(0));
    menu(end,score1,size);
    srand(time(0));
    RenderWindow window(VideoMode(320, 480), title);

    Texture obj1, obj2, obj3;
    obj1.loadFromFile("img/tiles.png");
    obj2.loadFromFile("img/background.png");
    obj3.loadFromFile("img/frame.png");
    /*
        Load "frames.png","tiles.png" and "background.png" for Texture objects
    */
    Sprite sprite(obj1), background(obj2), frame(obj3);
   
   /*sf::SoundBuffer buffer;
    if (!buffer.loadFromFile("tetris.mp3"))
    {
       // return -1;

    }

   // return 0;
   // sf::SoundBuffer buffer;
	// load something into the sound buffer...

	sf::Sound sound;
	sound.setBuffer(buffer);
	sound.play();
	sf::Music music;
if (!music.openFromFile("tetris.mp3"))
    return -1; // error
music.play();*/

    
   	
    Clock clock;
    while (window.isOpen()){
    	bool rotate=0;
        float time = clock.getElapsedTime().asSeconds();
        clock.restart();
        
        timer+=time;
		
        //---Event Listening Part---//
        Event e;
        while (window.pollEvent(e)){                       //Event is occurring - until the game is in running state
            if (e.type == Event::Closed || end==true)
                {               			//If cross/close is clicked/pressed
                	//cout<<score;
                	
						
                	window.close();
                	
               
                }                            				  //Opened window disposes
            if (e.type == Event::KeyPressed) {
            	if (e.key.code == Keyboard::P)
                {  
                	pause(end,score1,size);          								//Check if the other key pressed is UP key
                   
                }             								//If any other key (not cross) is pressed
                else if (e.key.code == Keyboard::Up)
                {            								//Check if the other key pressed is UP key
                    rotate = true;	
                }
                else if (e.key.code == Keyboard::Space)
                {            								//Check if the other key pressed is UP key
                    space = true;
                	delay=0.00000001;
                }			     		   //Rotation gets on
                else if (e.key.code == Keyboard::Left)     //Check if the other key pressed is LEFT key
                {
                    //if (bomb==false)
                    delta_x = -1;               		   //Change in X-Axis - Negative
                }
                else if (e.key.code == Keyboard::Right)    //Check if the other key pressed is RIGHT key
                  //  if (bomb==false)
                    	delta_x = 1;                           //Change in X-Axis - Positive
            }
        }
        if (Keyboard::isKeyPressed(Keyboard::Down))   //Just another way to detect key presses without event listener
            delay=0.05;                                    //If DOWN key is pressed, delay in falling piece decreases from 0 to 0.05

	
        ///////////////////////////////////////////////
        ///*** START CALLING YOUR FUNCTIONS HERE ***///
        ending(end);
        rotation(rotate,n,lev);
        
    	fallingPiece(timer, delay, colorNum,delta_x,n,lev,count,bomb,x,space);

    	
    	line(counter,lev);
    	
    	scoreGame(lev,counter,score);
    	grid(lev);
    	
    	
    	//cout<<score<<" ";
  	//level(lev);
  	//fallbomb(bomb)
	
               //Example: fallingPiece() function is called here
        ///*** YOUR CALLING STATEMENTS END HERE ***///
        //////////////////////////////////////////////

	
       window.clear(Color::Black);
       window.draw(background);
        for (int i=0; i<M; i++){
            for (int j=0; j<N; j++){
                if (gameGrid[i][j]==0)
                    continue;
                sprite.setTextureRect(IntRect(gameGrid[i][j]*18,0,18,18));
                sprite.setPosition(j*18,i*18);
                
                sprite.move(28,31); //offset
                window.draw(sprite);
            }
        }
         sf::RectangleShape rectangle(sf::Vector2f(90.0f,270.0f));
            rectangle.setFillColor(sf::Color::White); rectangle.setPosition(225,110); 
    	    window.draw(rectangle);
        
        for (int i=0; i<4; i++)
        {
        	sprite.setTextureRect(IntRect(10*18,0,18,18));
            sprite.setPosition(point_3[i][0]*18,point_3[i][1]*18);
            sprite.move(28,31);
            window.draw(sprite);
            
            sprite.setTextureRect(IntRect(y*18,0,18,18));
            sprite.setPosition(point_1[i][0]*18,point_1[i][1]*18);
            sprite.move(28,31);
            window.draw(sprite);
            
            sprite.setTextureRect(IntRect(colorNum*18,0,18,18));
            sprite.setPosition(point_4[i][0]*18,point_4[i][1]*18);
            sprite.move(250,300);
            window.draw(sprite);
            
           
            
            sprite.setTextureRect(IntRect(colorNum*18,0,18,18));
            sprite.setPosition(180,288);
          }
        //---The Final on Which Everything is Drawn Over is Loaded---//
       
            // Render our shape.
         rectangle.setOrigin(64.0f,64.0f);
          
        int a=score;
        int b=lev;
         
        
        sf::Text text;
		text.setFont(font); 
		text.setPosition(225,110);	
		text.setString("SCORE");
		text.setCharacterSize(24);
		text.setFillColor(sf::Color::Black);
		text.setStyle(sf::Text::Bold | sf::Text::Underlined);
		
		sf::Text text1;
		text1.setFont(font); 
		text1.setPosition(255,140);	
		text1.setString(to_string(a));
		text1.setCharacterSize(24);
		text1.setFillColor(sf::Color::Red);
		
		
		sf::Text text3;
		text3.setFont(font); 
		text3.setPosition(225,170);	
		text3.setString("LEVEL");
		text3.setCharacterSize(24);
		text3.setFillColor(sf::Color::Black);
		text3.setStyle(sf::Text::Bold | sf::Text::Underlined);
		
		sf::Text text4;
		text4.setFont(font); 
		text4.setPosition(255,200);	
		text4.setString(to_string(b));
		text4.setCharacterSize(24);
		text4.setFillColor(sf::Color::Red);
		
		sf::Text text5;
		text5.setFont(font); 
		text5.setPosition(230,260);	
		text5.setString("NEXT");
		text5.setCharacterSize(24);
		text5.setFillColor(sf::Color::Red);
		
		
		window.draw(text4);
		window.draw(text5);
		window.draw(text3);
		window.draw(text1);
		window.draw(text);
        
        
        window.draw(frame);
       
        //---The Window that now Contains the Frame is Displayed---//
        window.display();
    }
    return 0;
}
