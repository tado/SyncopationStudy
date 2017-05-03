#include "GUI.hpp"

GUI::GUI(){
    gui.setup();
    gui.add(drawSynco.setup("Draw Syncopation", false));
}

void GUI::update(){
    
}

void GUI::draw(){
    gui.draw();
}
