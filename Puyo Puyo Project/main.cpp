/*
Marie Claire Salha
 
This is a personal project for my own practice. I've decided to recreate the game Puyo Puyo out
 of my own peronal interest. I will import my own art/fanart for the game.
 
Here's how the game works:
 -There are 5 different puyo colors, but the game will randomly pick 4 to give to you for the whole game
 -Each time, you will get a "pair" puyos stuck together, and you can stack them in any direction you want
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
    sf::RenderWindow window(sf::VideoMode(1080, 1080), "Puyo Puyo!");
    sf::Texture texture;
    sf::Sprite sprite;
    
    //checks to make sure the image exists
    if(!texture.loadFromFile("image/Gasp!copy.png"))
    {
        std::cout << "The texture could not be found." << std::endl;
    }
    sprite.setTexture(texture);
    sprite.setOrigin(232, 215.5);
    sprite.setPosition(540, 540);
    
    
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
                 std::cout << "control:" << event.key.control << std::endl;
                
                if(event.key.code == sf::Keyboard::Up)
                    sprite.move(0, -10);
                else if(event.key.code == sf::Keyboard::Left)
                    sprite.move(-10, 0);
                else if(event.key.code == sf::Keyboard::Down)
                    sprite.move(0, 10);
                else if(event.key.code == sf::Keyboard::Right)
                    sprite.move(10, 0);
                else if(event.key.code == sf::Keyboard::D)
                    sprite.rotate(10.f);
                else if(event.key.code == sf::Keyboard::A)
                    sprite.rotate(-10.f);
                else if(event.key.code == sf::Keyboard::S)
                    sprite.setRotation(0.f);
            }
        }
        
        //Update the game
        //This just clears the contents of the window
        window.clear();
            //draw object here
            window.draw(sprite);
        
        window.display();
    }
    
    return 0;
}
