//
// Created by Wojciech Ormaniec on 07.11.18.
// Copyright (c) 2018 Industry of Black. All rights reserved.
//

#include <engine/Huntsman.hpp>
#include <list>
#include <iostream>
#include <SFML/Graphics.hpp>
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
    auto& huntsman = Huntsman::getInstance();
    class HuntObjectWithGravity;
    class Behavior{};
    class Gravity : public Behavior {
    public:
        explicit Gravity(HuntingGround, HuntObjectWithGravity* ho) {};
    };

    class HuntObjectWithGravity : public HuntObject{
    public:
        const sf::Drawable& getDrawable() override{ return sf::RectangleShape();}
        const std::pair<float, float>& getSize() override{return {0.f,0.f};}
        const std::pair<float, float>& getPosition() override{return {0.f,0.f};}
        void addBehavior(Behavior* behavior);
    };

    auto huntObject = huntsman.getFancier().add<HuntObjectWithGravity>();
    huntObject->addBehavior(new Gravity(huntsman.getHuntingGround(), &*huntObject));


    return EXIT_SUCCESS;
}