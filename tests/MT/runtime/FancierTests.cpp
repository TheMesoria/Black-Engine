//
// Created by Wojciech Ormaniec on 02.12.18.
// Copyright (c) 2018 Industry of Black. All rights reserved.
//

#include <gtest/gtest.h>
#include <engine/Fancier.hpp>
#include <model/hunt/HuntObject.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <memory>
#include "../../COMMON/TestBase.hpp"

struct TestableHuntObject
    : public HuntObject
{
    std::string Text;
    int         Val;

    sf::RectangleShape drawable;

    const sf::Drawable& getDrawable() override { return drawable; }
    const std::pair<float, float> getSize() override { return {}; }
    const std::pair<float, float> getPosition() override { return {}; }
};

class FancierShould
    : public TestBase, public ::testing::Test
{
public:
    FancierShould() = default;

    void SetUp() override
    {
        sut_ = std::make_shared<Fancier>();
    }

public:
    std::shared_ptr<Fancier> sut_;
};

TEST_F(FancierShould, Exist)
{
    ASSERT_FALSE(sut_ == nullptr);
}

TEST_F(FancierShould, AddObjectAndReturnIt)
{
    auto obj_1   = sut_->add<TestableHuntObject>();
    auto fetch_1 = sut_->getFirst<TestableHuntObject>();

    ASSERT_TRUE(obj_1 == fetch_1);
}

TEST_F(FancierShould, AddObjectAndStoreRefernce)
{
    auto obj_1   = sut_->add<TestableHuntObject>();
    auto fetch_1 = sut_->getFirst<TestableHuntObject>();

    obj_1->Text = "Testable String";
    obj_1->Val  = 10;

    if (!fetch_1)
        FAIL();

    ASSERT_TRUE(obj_1->Text == (*fetch_1)->Text);
    ASSERT_TRUE(obj_1->Val == (*fetch_1)->Val);
}

TEST_F(FancierShould, AddAndremoveElements)
{
    auto obj_1   = sut_->add<TestableHuntObject>();
    auto fetch_1 = sut_->getFirst<TestableHuntObject>();

    obj_1->Text = "Testable String";
    obj_1->Val  = 10;

    if (!fetch_1)
        FAIL();

    ASSERT_TRUE(obj_1->Text == (*fetch_1)->Text);
    ASSERT_TRUE(obj_1->Val == (*fetch_1)->Val);

    auto fetch_list_1 = sut_->get<TestableHuntObject>();

    ASSERT_EQ(fetch_list_1.size(), 1u);

    sut_->removeFirst<TestableHuntObject>();
    fetch_list_1 = sut_->get<TestableHuntObject>();

    ASSERT_EQ(fetch_list_1.size(), 0u);
}

TEST_F(FancierShould, AddMultipleElementsAndGetSelected)
{
    auto obj_1 = sut_->add<TestableHuntObject>();
    auto obj_2 = sut_->add<TestableHuntObject>();
    auto obj_3 = sut_->add<TestableHuntObject>();

    obj_1->Text = "Testable String 1";
    obj_1->Val  = 10;

    obj_2->Text = "Testable String 2";
    obj_2->Val  = 11;

    obj_3->Text = "Testable String 3";
    obj_3->Val  = 11;

    auto fetch_1 = sut_->getFirst<TestableHuntObject>([](TestableHuntObject t) -> bool
                                                      { return t.Val == 11; });

    auto fetch_list_1 = sut_->get<TestableHuntObject>();

    ASSERT_EQ(fetch_list_1.size(), 3u);
    ASSERT_TRUE(fetch_1 != nullptr);

    ASSERT_EQ((*fetch_1)->Text, obj_2->Text);
    ASSERT_EQ((*fetch_1)->Val, obj_2->Val);
}

TEST_F(FancierShould, AddElementsAnd)
{
    auto obj_1 = sut_->add<TestableHuntObject>();
    auto obj_2 = sut_->add<TestableHuntObject>();
    auto obj_3 = sut_->add<TestableHuntObject>();

    obj_1->Text = "Testable String 1";
    obj_1->Val  = 10;

    obj_2->Text = "Testable String 2";
    obj_2->Val  = 11;

    obj_3->Text = "Testable String 3";
    obj_3->Val  = 12;

    ASSERT_TRUE(sut_->remove<TestableHuntObject>([](TestableHuntObject t) -> bool
                                                 { return t.Val == 11; }));

    auto fetch_list_1 = sut_->get<TestableHuntObject>();

    auto fetch_1 = sut_->getFirst<TestableHuntObject>([](TestableHuntObject t) -> bool
                                                      { return t.Val == 11; });

    ASSERT_EQ(fetch_list_1.size(), 2u);
    ASSERT_TRUE(fetch_1 == nullptr);
}