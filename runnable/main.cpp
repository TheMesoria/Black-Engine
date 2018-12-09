//
// Created by Wojciech Ormaniec on 07.11.18.
// Copyright (c) 2018 Industry of Black. All rights reserved.
//

#include <engine/Huntsman.hpp>
#include <list>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <engine/Fancier.hpp>

int main(int argc, char** args)
{
    std::wcerr << "argc : " << argc << std::endl;
    std::wcerr << "args : " << std::endl;
    for (auto i = 0; i < argc; i++)
    {
        std::wcerr << i + 1 << ")" << args[i] << std::endl;
    }
    std::wcerr << std::endl << std::endl;

    Huntsman::getInstance().start();

    class GreenSquare : public HuntObject
    {
        sf::RectangleShape rectangleShape_;
    public:
        GreenSquare() : rectangleShape_({30,30})
        {
            rectangleShape_.setPosition({50,50});
            rectangleShape_.setFillColor(sf::Color::Green);
        }
        const sf::Drawable& getDrawable() override { return rectangleShape_; }
        const std::pair<float, float>& getSize() override { return {}; }
        const std::pair<float, float>& getPosition() override { return {}; }
    };

    class Gravity : public huntsman::Behavior
    {
    public:
        Gravity(){};
        void behave() override {  };
    };

    Huntsman::getInstance().getFancier().add<GreenSquare>();

    auto& falconer_ = Huntsman::getInstance().getFalconer();

    while(Huntsman::getInstance().isRunning())
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
        sf::Event event;
        while (falconer_->pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed)
            {
                LOG_CRIT(spdlog::get("main"),"Closing app!");
                falconer_->close();
            }
        }
    }

    //
    // spdlog::get("main")->info("Example Logging Method");
    // spdlog::get("main")->info("Example Logging Method {} {}", "with", "args");

    return EXIT_SUCCESS;
}