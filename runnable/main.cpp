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
        HuntingGround& huntingGround_;
        sf::Clock clock;
        float     speed_;
    public:
        Gravity(std::shared_ptr<HuntObject> ho, HuntingGround& hg, float speed)
            : huntingGround_(hg)
        {
            targetObject_ = ho;
            speed_        = speed;
            clock.restart();
        };

        void behave() override
        {
            if (targetObject_.expired())
            {
                return;
            }

            auto obj = targetObject_.lock();

            huntingGround_.moveHuntObject(obj, {0, -speed_ * clock.restart().asSeconds()});
        };
    };

    class PlayOntouchBehavior : public huntsman::Behavior
    {
        sf::Music music;
        HuntingGround& hg_;
        std::shared_ptr<HuntObject> ho_;
    public:
        PlayOntouchBehavior(std::shared_ptr<HuntObject> ho, HuntingGround& hg, float speed)
        : hg_(hg), ho_(ho)
        {
            if(!music.openFromFile("/home/black/Music/EndOfTheRoad.wav"))
            {
                assert(false);
            }

        }
        void behave()
        {
            if(hg_.verifyCollision(&*ho_)!= nullptr)
            {
                music.play();
            }
        }
    };

    auto elem  = Huntsman::getInstance().getFancier().add<GreenSquare>();
    auto elem2 = Huntsman::getInstance().getFancier().add<GreenSquare>();
    // auto elem3 = Huntsman::getInstance().getFancier().add<GreenSquare>();
    elem2->setSize({1000, 50});
    elem2->setPosition({0, 700});
    // elem3->setPosition({150, 50});
    elem->addBehavior(std::shared_ptr<huntsman::Behavior>(new PlayOntouchBehavior(elem, Huntsman::getInstance()
        .getHuntingGround(), 50.f)));
    // elem3->addBehavior(std::shared_ptr<huntsman::Behavior>(new Gravity(elem3, Huntsman::getInstance()
    //     .getHuntingGround(), 25.f)));

    auto& falconer_ = Huntsman::getInstance().getFalconer();

    class SfmlLogo : public HuntObject
    {
        sf::Texture texture;
        sf::Sprite  sprite;
    public:
        SfmlLogo()
        {
            texture.loadFromFile("/home/black/Pictures/sfml.png");
            sprite.setTexture(texture, true);
            sprite.setPosition(300, 300);
            sprite.setScale(0.3, 0.3);
        }

        const sf::Drawable& getDrawable() override
        { return sprite; }

        const std::pair<float, float> getSize() override
        { return std::pair<float, float>(); }

        void setSize(std::pair<float, float> const& pair) override
        {}

        const std::pair<float, float> getPosition() override
        { return std::pair<float, float>(); }

        void setPosition(std::pair<float, float> const& pair) override
        {}
    };

    auto elem3 = Huntsman::getInstance().getFancier().add<SfmlLogo>();

    auto x = std::shared_ptr<HuntObject>(elem);

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

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            Huntsman::getInstance().getHuntingGround().moveHuntObject(x, {5, 0});
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            Huntsman::getInstance().getHuntingGround().moveHuntObject(x, {-5, 0});
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            Huntsman::getInstance().getHuntingGround().moveHuntObject(x, {0, 5});
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            Huntsman::getInstance().getHuntingGround().moveHuntObject(x, {0, -5});
        }
    }

    //
    // spdlog::get("main")->info("Example Logging Method");
    // spdlog::get("main")->info("Example Logging Method {} {}", "with", "args");

    return EXIT_SUCCESS;
}