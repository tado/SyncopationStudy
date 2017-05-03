#include "GUI.hpp"

GUI::GUI(){
    gui.setup();
    gui.add(drawSynco.setup("Draw Syncopation", false));
    gui.add(syncoMode.setup("Syncopation Model", 0, 0, 6));
}

void GUI::update(){
    
}

void GUI::draw(){
    gui.draw();
}
