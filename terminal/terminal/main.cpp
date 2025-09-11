#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <sstream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(600, 200), "SFML Pseudo Terminal - Input");

    // Za³aduj czcionkê (upewnij siê, ¿e plik arial.ttf jest w katalogu .exe!)
    sf::Font font;
    if (!font.loadFromFile("C:\\Users\\alber\\Desktop\\Projekty\\perceptron_iris\\assets\\arial.ttf")) {
        std::cerr << "Nie znaleziono czcionki arial.ttf!" << std::endl;
        return -1;
    }

    // Pole do wpisywania
    sf::RectangleShape inputBox(sf::Vector2f(500, 50));
    inputBox.setPosition(50, 50);
    inputBox.setFillColor(sf::Color(30, 30, 30));
    inputBox.setOutlineThickness(2);
    inputBox.setOutlineColor(sf::Color::White);

    // Wyœwietlany tekst
    std::string inputText;
    sf::Text inputDisplay;
    inputDisplay.setFont(font);
    inputDisplay.setCharacterSize(24);
    inputDisplay.setFillColor(sf::Color::White);
    inputDisplay.setPosition(60, 60);

    // Flaga aktywnego pola
    bool isInputActive = true;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Zamkniêcie okna
            if (event.type == sf::Event::Closed)
                window.close();

            // Obs³uga wpisywanego tekstu
            if (isInputActive && event.type == sf::Event::TextEntered)
            {
                if (event.text.unicode == 8) { // Backspace
                    if (!inputText.empty())
                        inputText.pop_back();
                }
                else if (event.text.unicode == 13) { // Enter
                    // Konwersja do liczby ca³kowitej
                    try {
                        int asInt = std::stoi(inputText);
                        std::cout << "INT: " << asInt << std::endl;
                    }
                    catch (...) {
                        std::cout << "Niepoprawna liczba ca³kowita." << std::endl;
                    }

                    // Konwersja do liczby zmiennoprzecinkowej
                    try {
                        double asDouble = std::stod(inputText);
                        std::cout << "DOUBLE: " << asDouble << std::endl;
                    }
                    catch (...) {
                        std::cout << "Niepoprawna liczba zmiennoprzecinkowa." << std::endl;
                    }

                    inputText.clear(); // czyœcimy pole
                }
                else if (event.text.unicode < 128) {
                    char znak = static_cast<char>(event.text.unicode);
                    if (isdigit(znak) || znak == '.' || znak == '-') {
                        inputText += znak;
                    }
                }
            }
        }

        inputDisplay.setString(inputText);

        window.clear(sf::Color::Black);
        window.draw(inputBox);
        window.draw(inputDisplay);
        window.display();
    }

    return 0;
}
