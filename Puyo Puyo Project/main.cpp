/*
Marie Claire Salha
 
This is a personal project for my own practice. I've decided to recreate the game Puyo Puyo out
 of my own peronal interest. I will import my own art/fanart for the game.
 
Here's how the game works:
 -There are 5 different puyo colors, but the game will randomly pick 4 to give to you for the whole game
 -Each time, you will get a "pair" of puyos stuck together, and you can stack them in any cardinal direction you want
    -The color of the pair will be within the group of 4 colors picked for your game
 -Connect 4 or more of the same colored Puyos to pop them
 -build up chains in your game by stacking your Puyos in a certain way!
 
*/

#include <SFML/Graphics.hpp>
#include <iostream>

//I will be creating a render window in mian
    //this is what all of our objects are rendered to
int main()
{
    /*"window" is the name of the object we gave it
     -This takes in 2 parameters:
        -sf::VideoMode(), which also takes in 2 parameters:
            -width, and then the height
        -and then the title of the application, which will be put in double quotations (so, it takes in a
         string as its second argument)*/
    /*We can also add in other parameters, but those first two are necessary to put in. sf::Style::Titlebar allows us to keep
        the title of the window that we have.
        sf::Style::Close prevents the user from being able to resize the window.*/
    sf::RenderWindow window(sf::VideoMode(1200, 1200), "Puyo Puyo!", sf::Style::Titlebar | sf::Style::Close);
    window.setFramerateLimit(60);   //this will set the maximum framerate this game can run at to 60
    
    //loading the images from my image file into textures
    sf::Texture green, drk_green, pink_puyo;
    green.loadFromFile("image/Puyo_Background.png");
    drk_green.loadFromFile("image/border1.png");
    pink_puyo.loadFromFile("image/Pink_Puyo.png");
    
    /*putting the textures onto sprites
     Putting background(green) is a shorter way of doing background.setTexture(green)*/
    sf::Sprite background(green), border(drk_green), puyo1(pink_puyo);
    border.setOrigin(291.5, 500);    //This is needed because this sets the origin of the image to be wherever I want it to be, instead of in the corner                                    of the image, so this way, when I set the position of the sprite, it is centered at that position based on the                                       origin I gave it,not based on the corner of the image.
                                   //The coordinates work as followed: (width in pixels of image, height in pixels of image);
    border.setPosition(600, 600);  //This sets where the sprite will be within the window. setPosition(width in pixels of window, height);

    puyo1.setOrigin(37, 37);
    puyo1.setPosition(550, 189);    //This is where we start puyos on their boards
    
    
    
    //This is where most of your application stuff is done, like what happens in the window
    while (window.isOpen())
    {
        /*It's important that you handle all events, such as keyboard events, and mouse events,
          protective window re-sizing events, and others*/
        sf::Event event;    //name of the variable is "event"
        
        //handle all events
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                window.close();
            if(event.type == sf::Event::KeyPressed)
            {
                /*if(event.key.code == sf::Keyboard::Up)
                    puyo1.move(0, -10);*/
                if(event.key.code == sf::Keyboard::Left)
                {
                    //If the puyo is at the very left of the border, then we won't allow it to move outside of the border
                    if(puyo1.getPosition().x > 379.68)
                        puyo1.move(-85.16, 0);
                    continue;
                }
                else if(event.key.code == sf::Keyboard::Right)
                {
                    //If the puyo is at the very right of the border, then we won't allow it to move outside of the border
                    if(puyo1.getPosition().x < 805.48)
                        puyo1.move(85.16, 0);
                    continue;
                }
                else if(event.key.code == sf::Keyboard::Down)
                {
                    //If the puyo is at the very bottom of the border, then we won't allow it to move outside of the border
                    if(puyo1.getPosition().y < 969.8)
                        puyo1.move(0, 74.6);
                    continue;
                }
                else if(event.key.code == sf::Keyboard::D)
                    puyo1.rotate(90.f);
                else if(event.key.code == sf::Keyboard::A)
                    puyo1.rotate(-90.f);
                /*else if(event.key.code == sf::Keyboard::S)
                    puyo1.setRotation(0.f);*/
            }
        }
        
        //Update the game
        /*This just clears the contents of the window and updates what is on there. Without this, whenever we move the sprite "border" around,
            if we were to not have the background on there, for example, then instead of the sprite looking like it's moving, it will look like
            it is leaving a trail instead. (removing the background sprite helps see that)*/
        window.clear();
        
        //draw object here
        //we put window.draw() per sprite that we want to display onto the window
        //Yes, the order DOES matter
        window.draw(background);
        window.draw(puyo1);
        window.draw(border);
        
        //This just displays the window itself. Without this you wouldn't see anything.
        window.display();
    }
    
    return 0;
}
