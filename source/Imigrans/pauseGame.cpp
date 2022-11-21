#include "main.h"

void pauseGame()
{
    sf::RectangleShape background(sf::Vector2f(WIDTH, HEIGHT));
    background.setFillColor(sf::Color::White);
    sf::RectangleShape holdingHand(sf::Vector2f(WIDTH / 3.f, HEIGHT));
    sf::RectangleShape nokiPhone(sf::Vector2f(WIDTH / 4.f, HEIGHT / 1.2f));
    sf::RectangleShape playButton(sf::Vector2f(WIDTH / 4.5f, HEIGHT / 9.31f));
    sf::RectangleShape exitButton(sf::Vector2f(WIDTH / 4.5f, HEIGHT / 9.31f));
    sf::RectangleShape pointerHand(sf::Vector2f(WIDTH / 3.f, HEIGHT));
    sf::RectangleShape guideButton(sf::Vector2f(WIDTH / 4.5f, HEIGHT / 9.31f));

 
    sf::Texture BackgroundTex;
    BackgroundTex.loadFromFile("assets/background/phoneBackground.png");
    background.setTexture(&BackgroundTex);


    win.setMouseCursorVisible(false); // Hide cursor
    sf::View fixed = win.getView(); // Create a fixed view
    fixed.setCenter(WIDTH / 2, HEIGHT / 2);


    sf::Texture cursorTex;
    cursorTex.loadFromFile("assets/hand/cursor.png");
    pointerHand.setTexture(&cursorTex);
    pointerHand.setOrigin(sf::Vector2f(WIDTH / 10, HEIGHT / 10));


    sf::Texture holderTex;
    holderTex.loadFromFile("assets/hand/phoneHolder.png");
    holdingHand.setTexture(&holderTex);
    holdingHand.setPosition(WIDTH / 2.f - WIDTH / 4.f, HEIGHT / 5.f);


    sf::Texture nokiPhoneTex;
    nokiPhoneTex.loadFromFile("assets/nokiTech/empty.png");
    nokiPhone.setTexture(&nokiPhoneTex);
    nokiPhone.setPosition(WIDTH / 2.6f, HEIGHT / 4.f - HEIGHT / 6.f);


    sf::Texture playButtonTex;
    playButtonTex.loadFromFile("assets/buttons/continue.png");
    playButton.setTexture(&playButtonTex);
    playButton.setPosition(sf::Vector2f(WIDTH / 2.51f, HEIGHT / 2.6f));


    sf::Texture exitButtonTex;
    exitButtonTex.loadFromFile("assets/buttons/exit.png");
    exitButton.setTexture(&exitButtonTex);
    exitButton.setPosition(sf::Vector2f(WIDTH / 2.51f, HEIGHT / 1.9));


    while (win.isOpen())
    {
        sf::Vector2f mpos = win.mapPixelToCoords(sf::Mouse::getPosition(win));
        sf::Event e;
        while (win.pollEvent(e))
        {
            if (e.type == sf::Event::MouseButtonPressed && e.mouseButton.button == sf::Mouse::Left && exitButton.getGlobalBounds().contains(mpos))
                exit(0);

            else if (e.type == sf::Event::MouseButtonPressed && e.mouseButton.button == sf::Mouse::Left && playButton.getGlobalBounds().contains(mpos))
                return;

            if (e.type == sf::Event::KeyPressed && e.key.code == sf::Keyboard::Escape)
                return;
        }

        win.setView(fixed);
        pointerHand.setPosition(mpos); // Set position
        win.clear();
        win.draw(background);
        win.draw(holdingHand);
        win.draw(nokiPhone);
        win.draw(playButton);
        win.draw(exitButton);

        win.draw(pointerHand);
        win.display();
    }
}