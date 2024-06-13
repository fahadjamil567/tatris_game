/* PROGRAMMING FUNDAMENTAL'S PROJECT FOR FALL 2022 BS(CS)
 * You need to define the required function in the part instructed here below.
 * Avoid making any unnecessary changes, particularly the ones you don't understand.
 * The different pieces should be defined using an array - uncomment the following code once you are done creating the array.
 * TIP: Understand thoroughly before getting started with coding.
 * */

//---Piece Starts to Fall When Game Starts---//

;void fallingPiece(float& timer, float& delay,int& colorNum,int& delta_x,int &n,int & lev,int & count,bool & bomb,int &x,bool & space)
{
	int a;
	if (timer>delay)			//when greater than delay
	{
    	for (int i=0;i<4;i++)
    	{
    		point_2[i][0]=point_1[i][0];
    		point_2[i][1]=point_1[i][1];
    		point_1[i][1]+=1;   			//How much units downward
    		point_3[i][1]=point_1[i][1];
    	}
    	for (int i=0;i<4;i++)
    	{
    		if((point_1[i][0]==0 and delta_x==-1) ||(gameGrid[point_1[i][1]][point_1[i][0]+delta_x]!=0)||bomb==true)			//check where point should not move in axis
    			delta_x=0;
    		if(point_1[i][0]==9 and delta_x==1)
        		delta_x=0;
			point_3[i][0]=point_1[i][0];
		}
		for (int i=0;i<4;i++)
    	{	
			point_1[i][0]+=delta_x;
			point_3[i][0]=point_1[i][0];							//point_1 value is coppied in point_3 which is used in shadow making
   		}
		delta_x=0;
    	if (bomb==true)								//if bomb is in grid conditions are checked
		{
			if((gameGrid[point_1[0][1]+1][point_1[0][0]]!=0) and y==gameGrid[point_1[0][1]+1][point_1[0][0]])			//if bomb and color matched clear the grid
			{
				for(int i=0; i<20;i++)
				{
					for(int j=0;j<10;j++)
					{
						gameGrid[i][j]=0;
					}	
				}
				count=0;
				point_1[0][0]=10;
				point_1[0][1]=20;
				gameGrid[point_1[0][1]-1][point_1[0][0]]=0;
				x=1+rand()%10;
			}
			else if((gameGrid[point_1[0][1]+1][point_1[0][0]]!=0) and y!=gameGrid[point_1[0][1]+1][point_1[0][0]])		//if bomb and color not matched 4 blocks are removed from the grid
			{
				gameGrid[point_1[0][1]+1][point_1[0][0]]=0;
				gameGrid[point_1[0][1]+1][point_1[0][0]-1]=0;
				gameGrid[point_1[0][1]+1][point_1[0][0]+1]=0;
				gameGrid[point_1[0][1]+1][point_1[0][0]+2]=0;
				gameGrid[point_1[0][1]-1][point_1[0][0]]=0;
				point_1[0][0]=10;
				point_1[0][1]=20;
				count=0;
				x=1+rand()%10;		
			}
		}
		if (!anamoly())				//anamoly funtion is called
		{
    		if(!bomb)				//if not bomb then store the block in grid
    		{			
        		for(int i=0; i<4;i++)
        		{
        			gameGrid[point_2[i][1]][point_2[i][0]]=y;	
      			}
      		}
      		if (lev==1)
      			n=rand()%4;			//if basic level only 4 blocks are called
      		else
      			n=rand()%7;
      		y=colorNum;
      		colorNum=1+rand()%7;	//color num is generated randomly
      		int f=rand()%10;
      		space=false; 
      		if(count==x)			//if counter and random number matches bomb is generated randomly 
        	{
				for (int i=0;i<4;i++)		//blocks are formed
				{
					colorNum=1+rand()%7;
					point_1[i][0] = BLOCKS[8][i] % 2;
					point_1[i][1] = BLOCKS[8][i] / 2;
					 
					bomb=true;
        		    point_1[i][0] +=f;
        		}
       		}
        	else
        	{
        		for(int k=0; k<4;k++)
        			{
        				for(int j=0; j<2;j++)
        				{
        					gameGrid1[k][j]=0;
        				}
        			}
        		for (int i=0;i<4;i++)
        		{
            		point_1[i][0] = point_4[i][0];			//point_4 values are stored in point_1
            		point_1[i][1] = point_4[i][1];
            		point_3[i][0] = point_4[i][0];
            		point_3[i][1] = point_4[i][1];
            		
            		point_4[i][0] = BLOCKS[n][i] % 2;		//blocks are stored in next which is point_4 
            		point_4[i][1] = BLOCKS[n][i] / 2;

            		bomb=false;      	
            	}
            	for (int i=0;i<4;i++)
            	{
            		point_3[i][0] +=4;
            		point_1[i][0] +=4;
            	}
                 
        	}   
        	count+=1;  
		}
	
	
		while(anamoly1())					//shadow formation to base 
		{
	  		for (int i=0;i<4;i++)
        	{
        		point_3[i][1] ++;
        	}
        }
        for (int i=0;i<4;i++)
        {
        	point_3[i][1] --;
        }
  
		bool present=0;				//checking lines for level
		for(int i=19; i>=0;i--)
		{
			present=0;
			for(int j=2; j<9;j++)
			{
				if (gameGrid[i][j]!=0)
				{
					present=1;	
				}
			}
			if(present==1)
				a=i;
		}
		if(a>15 and lev<2)			//level formation
			lev=1;
		else if(a>10 and lev<3)
			lev=2;
		else if(a>5 and lev<4)
			lev=3;
		else if(a>0)
			lev=4;
		if (!space)
	    	timer=0;
	    if (lev==4)
			delay=0.1;
	    else if (lev==3)
	       	delay=0.2;
	    else if (lev==2)
	        delay=0.3;
	    else if (lev==1)
	        delay=0.4;  
	}
}
/////////////////////////////////////////////
///*** START CODING YOUR FUNTIONS HERE ***///
void grid(int lev)					//grid shrinked according to level
{
	if (lev==2)
	{
		
		gameGrid[1][0]=9;
		gameGrid[2][0]=9;
		gameGrid[3][0]=9;
		gameGrid[4][0]=9;
		gameGrid[5][0]=9;
		gameGrid[6][0]=9;
		gameGrid[7][0]=9;
		gameGrid[8][0]=9;
		gameGrid[9][0]=9;
		gameGrid[10][0]=9;
		gameGrid[11][0]=9;
		gameGrid[12][0]=9;
		gameGrid[13][0]=9;
		gameGrid[14][0]=9;
		gameGrid[15][0]=9;
		gameGrid[16][0]=9;
		gameGrid[17][0]=9;
		gameGrid[18][0]=9;
		gameGrid[19][0]=9;

	}
	if (lev==3)
	{
		gameGrid[1][0]=9;
		gameGrid[2][0]=9;
		gameGrid[3][0]=9;
		gameGrid[4][0]=9;
		gameGrid[5][0]=9;
		gameGrid[6][0]=9;
		gameGrid[7][0]=9;
		gameGrid[8][0]=9;
		gameGrid[9][0]=9;
		gameGrid[10][0]=9;
		gameGrid[11][0]=9;
		gameGrid[12][0]=9;
		gameGrid[13][0]=9;
		gameGrid[14][0]=9;
		gameGrid[15][0]=9;
		gameGrid[16][0]=9;
		gameGrid[17][0]=9;
		gameGrid[18][0]=9;
		gameGrid[19][0]=9;

		gameGrid[1][9]=9;
		gameGrid[2][9]=9;
		gameGrid[3][9]=9;
		gameGrid[4][9]=9;
		gameGrid[5][9]=9;
		gameGrid[6][9]=9;
		gameGrid[7][9]=9;
		gameGrid[8][9]=9;
		gameGrid[9][9]=9;
		gameGrid[10][9]=9;
		gameGrid[11][9]=9;
		gameGrid[12][9]=9;
		gameGrid[13][9]=9;
		gameGrid[14][9]=9;
		gameGrid[15][9]=9;
		gameGrid[16][9]=9;
		gameGrid[17][9]=9;
		gameGrid[18][9]=9;
		gameGrid[19][9]=9;

	}
	if (lev==4)
	{
		gameGrid[1][0]=9;
		gameGrid[2][0]=9;
		gameGrid[3][0]=9;
		gameGrid[4][0]=9;
		gameGrid[5][0]=9;
		gameGrid[6][0]=9;
		gameGrid[7][0]=9;
		gameGrid[8][0]=9;
		gameGrid[9][0]=9;
		gameGrid[10][0]=9;
		gameGrid[11][0]=9;
		gameGrid[12][0]=9;
		gameGrid[13][0]=9;
		gameGrid[14][0]=9;
		gameGrid[15][0]=9;
		gameGrid[16][0]=9;
		gameGrid[17][0]=9;
		gameGrid[18][0]=9;
		gameGrid[19][0]=9;

		gameGrid[1][9]=9;
		gameGrid[2][9]=9;
		gameGrid[3][9]=9;
		gameGrid[4][9]=9;
		gameGrid[5][9]=9;
		gameGrid[6][9]=9;
		gameGrid[7][9]=9;
		gameGrid[8][9]=9;
		gameGrid[9][9]=9;
		gameGrid[10][9]=9;
		gameGrid[11][9]=9;
		gameGrid[12][9]=9;
		gameGrid[13][9]=9;
		gameGrid[14][9]=9;
		gameGrid[15][9]=9;
		gameGrid[16][9]=9;
		gameGrid[17][9]=9;
		gameGrid[18][9]=9;
		gameGrid[19][9]=9;
		
		gameGrid[1][1]=9;
		gameGrid[2][1]=9;
		gameGrid[3][1]=9;
		gameGrid[4][1]=9;
		gameGrid[5][1]=9;
		gameGrid[6][1]=9;
		gameGrid[7][1]=9;
		gameGrid[8][1]=9;
		gameGrid[9][1]=9;
		gameGrid[10][1]=9;
		gameGrid[11][1]=9;
		gameGrid[12][1]=9;
		gameGrid[13][1]=9;
		gameGrid[14][1]=9;
		gameGrid[15][1]=9;
		gameGrid[16][1]=9;
		gameGrid[17][1]=9;
		gameGrid[18][1]=9;
		gameGrid[19][1]=9;
	}
}

void rotation(bool&rotate, int n,int lev)			//rotation of the block with center point
{
	int a=center[n];
	if(rotate==1)
	{
		int x=0, y=0;
		bool less=0,greater=0;
   		for(int i=0;i<4;i++)
   		{
   			x=point_1[a][0]-point_1[i][0];
   			y=point_1[a][1]-point_1[i][1];
   			if(lev==1)
   			{
   				if(point_1[a][0]+(y)<0 || point_1[a][0]+(y)>9)
   				{
   					rotate=0;
   					a=point_1[a][0]+(y);
   				}
   			}
   			
   			else if(lev==2)
   			{
   				if(point_1[a][0]+(y)<1 || point_1[a][0]+(y)>9)
   				{
   					rotate=0;
   					a=point_1[a][0]+(y);
   				}
   			}
   			
   			if(lev==3)
   			{
   				if(point_1[a][0]+(y)<1 || point_1[a][0]+(y)>8)
   				{
   					rotate=0;
   					a=point_1[a][0]+(y);
   				}
   			}
   			
   			if(lev==4)
   			{
   				if(point_1[a][0]+(y)<2 || point_1[a][0]+(y)>8)
   				{
   					rotate=0;
   					a=point_1[a][0]+(y);
   				}
   			}
   			
   		}
   		
   		if(gameGrid[point_1[2][1]-x][point_1[2][0]+y]!=0)
   			rotate=0;	
   		
   		if (rotate==1)
   		{
   			for(int i=0;i<4;i++)
   			{
   				x=point_1[2][0]-point_1[i][0];
   				y=point_1[2][1]-point_1[i][1];
  				point_1[i][0]=point_1[2][0]+y;
   				point_1[i][1]=point_1[2][1]-x;	
   			}
   		}
   		less=0;
   		greater=0;
   	}	
   	rotate=0;         		
}
void clearline(int a,int lev)			//clearing line if line is completed according to level the shrinked grid
{
	if(lev==1)
	{	
		for(int i=a; i>0;i--)
		{
			for(int j=0;j<10;j++)
			{
				gameGrid[i][j]=gameGrid[i-1][j];
				gameGrid[i-1][j]=0;
			}				
		}
	}
	
	if(lev==2)
	{	
		for(int i=a; i>0;i--)
		{
			for(int j=1;j<10;j++)
			{
				gameGrid[i][j]=gameGrid[i-1][j];
				gameGrid[i-1][j]=0;
			}				
		}
	}
	
	if(lev==3)
	{	
		for(int i=a; i>0;i--)
		{
			for(int j=1;j<9;j++)
			{
				gameGrid[i][j]=gameGrid[i-1][j];
				gameGrid[i-1][j]=0;
			}				
		}
	}
	
	if(lev==4)
	{	
		for(int i=a; i>0;i--)
		{
			for(int j=2;j<9;j++)
			{
				gameGrid[i][j]=gameGrid[i-1][j];			//movin blocks down when line is cleared
				gameGrid[i-1][j]=0;
			}				
		}
	}
	
}

void line(int & counter,int lev)				//checking where line is full and must be cleared
{
	counter=0;
	bool full=0;
	if (lev==1)
	{
		for(int i=0; i<20;i++)
		{
			full=1;
			for(int j=0; j<10;j++)
			{
				if (gameGrid[i][j]==0)
				{
					full=0;	
				}
			}
			if(full==1)
			{
				clearline(i,lev);
				counter+=1;
			}
		}
	}	
	if (lev==2)
	{
		for(int i=0; i<20;i++)
		{
			full=1;
			for(int j=1; j<10;j++)
			{
				if (gameGrid[i][j]==0)
				{
					full=0;	
				}
			}
			if(full==1)
			{
				clearline(i,lev);
				counter+=1;
			}
		}
	}
		
	if (lev==3)
	{
		for(int i=0; i<20;i++)
		{
			full=1;
			for(int j=1; j<9;j++)
			{
				if (gameGrid[i][j]==0)
				{
					full=0;	
				}
			}
			if(full==1)
			{
				clearline(i,lev);
				counter+=1;
			}
		}
	}
	if (lev==4)
	{
		for(int i=0; i<20;i++)
		{
			full=1;
			for(int j=2; j<9;j++)
			{
				if (gameGrid[i][j]==0)
				{
					full=0;	
				}
			}
			if(full==1)
			{
				clearline(i,lev);
				counter+=1;
			}
		}
	}		
	
}
void endingmenu(bool & end)			//menu when game is end
{
	sf::Font font;
	if (!font.loadFromFile("arial.ttf"))
	{
    	// error...
	}
	sf::Texture obj4, obj5, obj6;
    	obj4.loadFromFile("img/tiles.png");
    	obj5.loadFromFile("img/background.png");
    	obj6.loadFromFile("img/frame.png");
	sf::Sprite sprite(obj4), background(obj5), frame(obj6);
	
	sf::RenderWindow window(sf::VideoMode(320, 480), title);
	window.clear(sf::Color::Black);
    	
    sf::Clock clock;
    while (window.isOpen())
    {
    	bool f=0; 
    	float time = clock.getElapsedTime().asSeconds();
        window.draw(background);
    	sf::Event e;
        while (window.pollEvent(e))			//Event is occurring - until the game is in running state
        {                       
            if (e.type == sf::Event::Closed ||f==1)
            { 
				window.close();
            }                               				  //Opened window disposes
            if (e.type == sf::Event::KeyPressed) 
            {
            	if (e.key.code == sf::Keyboard::B)
                {  
                	f=1;
                	end=true;        								//Check if the other key pressed is UP key  
                }
            }
		}	
     	sf::Text text;
		text.setFont(font); 
		text.setPosition(5,110);	
		text.setString("GAME OVER!!");
		text.setCharacterSize(15);
		text.setFillColor(sf::Color::White);
		text.setStyle(sf::Text::Bold | sf::Text::Underlined);
		
		sf::Text text1;
		text1.setFont(font); 
		text1.setPosition(5,140);	
		text1.setString("BETTER LUCK NEXT TIME!!");
		text1.setCharacterSize(15);
		text1.setFillColor(sf::Color::White);
		text1.setStyle(sf::Text::Bold | sf::Text::Underlined);
		
		sf::Text text5;
		text5.setFont(font); 
		text5.setPosition(5,190);	
		text5.setString("PRESS 'B' FOR EXIT");
		text5.setCharacterSize(15);
		text5.setFillColor(sf::Color::White);
		text5.setStyle(sf::Text::Bold | sf::Text::Underlined);
		
		window.draw(text5);
		window.draw(text1);
		window.draw(text);
		window.display();
	}
}
void ending(bool & end)				//when grid reches top game is end
{
	for(int i=0; i<10;i++)
	{
		if(gameGrid[0][i]!=0)
			endingmenu(end);
	}


}

void scoreGame(int & lev,int & counter,int & score)			//calculating score
{
	if (counter==1)
    {
    	score+=10*lev*counter;
    }
    else if (counter==2)
    {
    	score+=15*lev*counter;
    }
    else if (counter==3)
    {
    	score+=20*lev*counter;
    }
   	else if (counter==4)
    {
    	score+=25*lev*counter;
    }
}
void Heighest_score(int score2[],int size)					//display heighest score from stored file
{
	int max=0;
	for(int i=0;i<size;i++)
	{
		if(score2[i]>max)
			max=score2[i];
	}
	int a=0;
	a=max;
	
	sf::Font font;
	if (!font.loadFromFile("arial.ttf"))
	{
    // error...
	}
	sf::Texture obj4, obj5, obj6;
    	obj4.loadFromFile("img/tiles.png");
    	obj5.loadFromFile("img/background.png");
    	obj6.loadFromFile("img/frame.png");
	sf::Sprite sprite(obj4), background(obj5), frame(obj6);
	
	sf::RenderWindow window(sf::VideoMode(320, 480), title);
	window.clear(sf::Color::Black);
    	
    sf::Clock clock;
    while (window.isOpen())
    {
    	bool f=0; 
    	float time = clock.getElapsedTime().asSeconds();
        //clock.restart();
        window.draw(background);
        //timer+=time;
    	sf::Event e;
        while (window.pollEvent(e))			//Event is occurring - until the game is in running state
        {                       
            if (e.type == sf::Event::Closed ||f==1)
            { 
				window.close();
            }                               				  //Opened window disposes
            if (e.type == sf::Event::KeyPressed) 
            {
            	if (e.key.code == sf::Keyboard::B)
                {  
                	f=1;        								//Check if the other key pressed is UP key  
                }
            }
		}	
     	sf::Text text;
		text.setFont(font); 
		text.setPosition(90,140);	
		text.setString(std::to_string(a));
		text.setCharacterSize(20);
		text.setFillColor(sf::Color::Red);
		text.setStyle(sf::Text::Bold | sf::Text::Underlined);
		
		sf::Text text1;
		text1.setFont(font); 
		text1.setPosition(5,140);	
		text1.setString("FAHAD");
		text1.setCharacterSize(20);
		text1.setFillColor(sf::Color::White);
		text1.setStyle(sf::Text::Bold | sf::Text::Underlined);
		
		sf::Text text2;
		text2.setFont(font); 
		text2.setPosition(5,200);	
		text2.setString("PRESS B TO RETURN");
		text2.setCharacterSize(15);
		text2.setFillColor(sf::Color::White);
		text2.setStyle(sf::Text::Bold | sf::Text::Underlined);
		
		sf::Text text3;
		text3.setFont(font); 
		text3.setPosition(5,100);	
		text3.setString("HEIGHEST SCORE");
		text3.setCharacterSize(20);
		text3.setFillColor(sf::Color::Black);
		text3.setStyle(sf::Text::Bold | sf::Text::Underlined);
		
		window.draw(text3);
		window.draw(text2);
		window.draw(text1);
		window.draw(text);
		
        //---The Window that now Contains the Frame is Displayed---//
  		window.display();
	}

}
void Help()															//when help funtion to display help
{
	sf::Font font;
	if (!font.loadFromFile("arial.ttf"))
	{
    // error...
	}
	sf::Texture obj4, obj5, obj6;
    	obj4.loadFromFile("img/tiles.png");
    	obj5.loadFromFile("img/background.png");
    	obj6.loadFromFile("img/frame.png");
	sf::Sprite sprite(obj4), background(obj5), frame(obj6);
	
	sf::RenderWindow window(sf::VideoMode(320, 480), title);
	window.clear(sf::Color::Black);
    	
    sf::Clock clock;
    while (window.isOpen())
    {
    	bool f=0; 
    	float time = clock.getElapsedTime().asSeconds();
        //clock.restart();
        window.draw(background);
        //timer+=time;
    	sf::Event e;
        while (window.pollEvent(e))			//Event is occurring - until the game is in running state
        {                       
            if (e.type == sf::Event::Closed ||f==1)
            { 
				window.close();
            }                               				  //Opened window disposes
            if (e.type == sf::Event::KeyPressed) 
            {
            	if (e.key.code == sf::Keyboard::B)
                {  
                	f=1;        								//Check if the other key pressed is UP key  
                }
            }
		}	
     	sf::Text text;
		text.setFont(font); 
		text.setPosition(5,110);	
		text.setString("YOU CAN MOVE THE PICES IN SPECIFIC WAYS");
		text.setCharacterSize(10);
		text.setFillColor(sf::Color::White);
		text.setStyle(sf::Text::Bold | sf::Text::Underlined);
		
		sf::Text text1;
		text1.setFont(font); 
		text1.setPosition(5,140);	
		text1.setString("YOUR GAME IS OVER WHEN U REACH TOP OF SCEEN");
		text1.setCharacterSize(10);
		text1.setFillColor(sf::Color::White);
		text1.setStyle(sf::Text::Bold | sf::Text::Underlined);
		
		sf::Text text2;
		text2.setFont(font); 
		text2.setPosition(5,170);	
		text2.setString("WHEN ROW IS COMPLETED ROW IS CLEAR");
		text2.setCharacterSize(10);
		text2.setFillColor(sf::Color::White);
		text2.setStyle(sf::Text::Bold | sf::Text::Underlined);
		
		
		sf::Text text3;
		text3.setFont(font); 
		text3.setPosition(5,200);	
		text3.setString("PLAY AND ENJOY THE GAME AND SCORE HEIGHEST");
		text3.setCharacterSize(10);
		text3.setFillColor(sf::Color::White);
		text3.setStyle(sf::Text::Bold | sf::Text::Underlined);
		
		sf::Text text4;
		text4.setFont(font); 
		text4.setPosition(5,230);	
		text4.setString("BEST OF LUCK!!!!!");
		text4.setCharacterSize(10);
		text4.setFillColor(sf::Color::White);
		text4.setStyle(sf::Text::Bold | sf::Text::Underlined);
		
		sf::Text text5;
		text5.setFont(font); 
		text5.setPosition(5,290);	
		text5.setString("PRESS 'B' FOR BACK");
		text5.setCharacterSize(10);
		text5.setFillColor(sf::Color::White);
		text5.setStyle(sf::Text::Bold | sf::Text::Underlined);
		
		window.draw(text5);
		window.draw(text4);
		window.draw(text3);
		window.draw(text2);
		window.draw(text1);
		window.draw(text);
		
        //---The Window that now Contains the Frame is Displayed---//
  		window.display();
	}
      
}
 
void menu(bool & end,int score2[],int size)				//menu function is called
{
	sf::Font font;
	if (!font.loadFromFile("arial.ttf"))
	{
    	// error...
	}
	sf::Texture obj4, obj5, obj6;
    	obj4.loadFromFile("img/tiles.png");
    	obj5.loadFromFile("img/background.png");
    	obj6.loadFromFile("img/frame.png");
	sf::Sprite sprite(obj4), background(obj5), frame(obj6);
	
	
	sf::RenderWindow window(sf::VideoMode(320, 480), title);
	window.clear(sf::Color::Black);
    	
    sf::Clock clock;
    while (window.isOpen())
    {
    	bool f=0;
    	float time = clock.getElapsedTime().asSeconds();
    	//clock.restart();
    	window.draw(background);
    	//timer+=time;
   		sf::Event e;
    	while (window.pollEvent(e))
   		{                       //Event is occurring - until the game is in running state
    		if (e.type == sf::Event::Closed || f==1||end==1)
        	{ 
                window.close();
            }
                                           				  //Opened window disposes
        	if (e.type == sf::Event::KeyPressed) 
        	{	
        		if (e.key.code == sf::Keyboard::S)
            	{  
            	    f=1;        								//Check if the other key pressed is UP key  
            	}
            	else if (e.key.code == sf::Keyboard::H)
            	{  
            	    Heighest_score(score2,size);         								//Check if the other key pressed is UP key  
            	}
            	else if (e.key.code == sf::Keyboard::Q)
            	{  
            	    Help();         								//Check if the other key pressed is UP key  
            	}
            	else if (e.key.code == sf::Keyboard::R)
            	{  
            	    end=1;         								//Check if the other key pressed is UP key  
            	}                      								//If any other key (not cross) is pressed
            
			}
		}
     	sf::Text text;
		text.setFont(font); 
		text.setPosition(5,110);	
		text.setString("PRESS 'S' TO START NEW GAME");
		text.setCharacterSize(15);
		text.setFillColor(sf::Color::White);
		text.setStyle(sf::Text::Bold | sf::Text::Underlined);
		
		sf::Text text1;
		text1.setFont(font); 
		text1.setPosition(5,140);	
		text1.setString("PRESS 'H' TO SEE HEIGHEST SCORE");
		text1.setCharacterSize(15);
		text1.setFillColor(sf::Color::White);
		text1.setStyle(sf::Text::Bold | sf::Text::Underlined);
		
		sf::Text text2;
		text2.setFont(font); 
		text2.setPosition(5,170);	
		text2.setString("PRESS 'Q' TO HELP");
		text2.setCharacterSize(15);
		text2.setFillColor(sf::Color::White);
		text2.setStyle(sf::Text::Bold | sf::Text::Underlined);
		
		
		sf::Text text3;
		text3.setFont(font); 
		text3.setPosition(5,200);	
		text3.setString("PRESS 'R' TO EXIT");
		text3.setCharacterSize(15);
		text3.setFillColor(sf::Color::White);
		text3.setStyle(sf::Text::Bold | sf::Text::Underlined);
		
		window.draw(text3);
		window.draw(text2);
		window.draw(text1);
		window.draw(text);
		//window.draw(frame);
        //---The Window that now Contains the Frame is Displayed---//
  		 window.display();
	}
	
	      
}

void pause(bool & end,int score2[],int size)			//pause menu is called when P key was pessed and display pause option
{
	sf::Font font;
		if (!font.loadFromFile("arial.ttf"))
		{
    	// error...
		}
	sf::Texture obj4, obj5, obj6;
    	obj4.loadFromFile("img/tiles.png");
    	obj5.loadFromFile("img/background.png");
    	obj6.loadFromFile("img/frame.png");
	sf::Sprite sprite(obj4), background(obj5), frame(obj6);
	
	
	sf::RenderWindow window(sf::VideoMode(320, 480), title);
	window.clear(sf::Color::Black);
    	
    	sf::Clock clock;
    while (window.isOpen()){
    	bool a=0,b=0,c=0,d=0,f=0; 
    	  float time = clock.getElapsedTime().asSeconds();
        //clock.restart();
        window.draw(background);
        //timer+=time;
    	  sf::Event e;
        while (window.pollEvent(e)){                       //Event is occurring - until the game is in running state
            if (e.type == sf::Event::Closed || f==1|| end==1)
                { 
                	window.close();
                }
                                           				  //Opened window disposes
            if (e.type == sf::Event::KeyPressed) {
            	if (e.key.code == sf::Keyboard::C)
                {  
                	f=1;         								//Check if the other key pressed is UP key  
                }
                
                else if (e.key.code == sf::Keyboard::H)
                {  
                	Heighest_score(score2,size);        								//Check if the other key pressed is UP key  
                }
                else if (e.key.code == sf::Keyboard::Q)
                {  
                	Help();         								//Check if the other key pressed is UP key  
                }
                else if (e.key.code == sf::Keyboard::R)
                {  
                	end=1;
                      								//Check if the other key pressed is UP key  
                }                      								//If any other key (not cross) is pressed
            
            }
            }
		
		sf::Text text1;
		text1.setFont(font); 
		text1.setPosition(5,140);	
		text1.setString("PRESS 'H' TO SEE HEIGHEST SCORE");
		text1.setCharacterSize(15);
		text1.setFillColor(sf::Color::White);
		text1.setStyle(sf::Text::Bold | sf::Text::Underlined);
		
		sf::Text text2;
		text2.setFont(font); 
		text2.setPosition(5,170);	
		text2.setString("PRESS 'Q' TO HELP");
		text2.setCharacterSize(15);
		text2.setFillColor(sf::Color::White);
		text2.setStyle(sf::Text::Bold | sf::Text::Underlined);
		
		
		sf::Text text3;
		text3.setFont(font); 
		text3.setPosition(5,200);	
		text3.setString("PRESS 'R' TO EXIT");
		text3.setCharacterSize(15);
		text3.setFillColor(sf::Color::White);
		text3.setStyle(sf::Text::Bold | sf::Text::Underlined);
		
		sf::Text text4;
		text4.setFont(font); 
		text4.setPosition(5,230);	
		text4.setString("PRESS 'C' TO CONTINUE");
		text4.setCharacterSize(15);
		text4.setFillColor(sf::Color::White);
		text4.setStyle(sf::Text::Bold | sf::Text::Underlined);
		
		window.draw(text4);
		window.draw(text3);
		window.draw(text2);
		window.draw(text1);
		
		
        //---The Window that now Contains the Frame is Displayed---//
  	window.display();
	}
      
}

///*** YOUR FUNCTIONS END HERE ***///
/////////////////////////////////////
