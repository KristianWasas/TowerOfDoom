#include "controlState.hpp"

ControlState::ControlState(sf::RenderWindow* win) : State(5, win){
    this->returnButton = new Button(this->window->getSize().x/2 - 100, this->window->getSize().y - 200, 200, 50, "Return", 20, sf::Color::Red, sf::Color::Green, sf::Color::Yellow);
    controls = new Text(0,0," ", "fonts/Montserrat-Regular.ttf", sf::Color::Black, sf::Color::White, 30, 1, true);
    title = new Text(win->getSize().x/2, 100, "Controls", "fonts/Montserrat-Regular.ttf", sf::Color::Black, sf::Color::White, 50, 1, true);
}

ControlState::~ControlState(){
    delete this->returnButton;
}

void ControlState::reset(){
    this->goNextState = false;
    this->returnButton->activated = false;
}

void ControlState::updateState(){
    
    this->updateMousePos();
    this->returnButton->updateButton(mousePos);

    if(this->returnButton->activated){
        this->goNextState = true;
        this->nextStateNum = 0;
    }
}

void ControlState::drawState(sf::RenderTarget* target){

    title->drawText(target);

    for(int i = 0; i < 7; ++i){
        controls->setText(controlTexts[i]);
        controls->setCords(window->getSize().x/2 - 300, 175 + i*70);
        controls->drawText(target);
    }
    this->returnButton->drawButton(target);

}