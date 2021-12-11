#pragma once

#include "state.hpp"

class ControlState : public State {

public: 

    ControlState(sf::RenderWindow*);
    ~ControlState();

    void reset();

    void drawState(sf::RenderTarget*);
    void updateState();

private:

    Text* controls;
    Text* title;

    std::array<std::string, 7> controlTexts =  {"wasd                                                      move", 
                                                "e                                               pick up items",
                                                "t                                                 talk to NPC's", 
                                                "space                                                    attack",
                                                "left mouse button                         use item",
                                                "right mouse button                    drop item"};

    Button* returnButton;
};