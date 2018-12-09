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
#include <model/hunt/behavior/Behavior.hpp>

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
        GreenSquare()
            : rectangleShape_({30, 30})
        {
            rectangleShape_.setPosition({50, 50});
            rectangleShape_.setFillColor(sf::Color::Green);
        }

        const sf::Drawable& getDrawable() override
        { return rectangleShape_; }

        const std::pair<float, float> getSize() override
        { return {rectangleShape_.getSize().x, rectangleShape_.getSize().y}; }

        const std::pair<float, float> getPosition() override
        { return {rectangleShape_.getPosition().x, rectangleShape_.getPosition().y}; }

        void setPosition(std::pair<float, float> const& arg) override
        { rectangleShape_.setPosition({arg.first, arg.second}); }

        void setSize(std::pair<float, float> const& arg) override
        { rectangleShape_.setSize({arg.first, arg.second}); }
    };

    class Gravity : public huntsman::Behavior
    {
        std::weak_ptr<HuntObject> targetObject_;
        float                     speed_;
    public:
        Gravity(std::shared_ptr<HuntObject> ho, float speed)
        {
            targetObject_ = ho;
            speed_        = speed;
        };

        void behave() override
        {
            if (targetObject_.expired())
            {
                return;
            }

            auto obj = targetObject_.lock();
            obj->setSize({obj->getSize().first, obj->getSize().second - speed_});
        };
    };

    auto elem = Huntsman::getInstance().getFancier().add<GreenSquare>();
    elem->addBehavior(std::shared_ptr<huntsman::Behavior>(new Gravity(elem,5.f)));

    auto& falconer_ = Huntsman::getInstance().getFalconer();

    while (Huntsman::getInstance().isRunning())
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
        sf::Event event;
        while (falconer_->pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed)
            {
                LOG_CRIT(spdlog::get("main"), "Closing app!");
                falconer_->close();
            }
        }
    }

    //
    // spdlog::get("main")->info("Example Logging Method");
    // spdlog::get("main")->info("Example Logging Method {} {}", "with", "args");

    return EXIT_SUCCESS;
}