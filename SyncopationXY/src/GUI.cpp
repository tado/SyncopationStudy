#include "GUI.hpp"

GUI::GUI(){
    gui.setup();
    gui.add(fps.setup("FPS", 120, 10, 300));
    gui.add(syncoMode.setup("Syncopation Model", 0, 0, 6));
    gui.add(expLength.setup("Experiment Length", 30, 1, 180));
    gui.add(drawSynco.setup("Draw Syncopation", true));
    gui.add(guideBeat.setup("Guide / Drum or Click", false));
    gui.add(timbre.setup("Timbre / BD or Clap", false));
    gui.loadFromFile("settings.xml");
}

void GUI::update(){
    
}

void GUI::draw(){
    gui.draw();
}
