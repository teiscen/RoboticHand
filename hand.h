#pragma once

#include <sstream>
#include <unordered_map>
#include <vector>
#include <utility>

#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

#define STOP 300   // Neutral position (stops the servo)
#define MAX_SPEED 500  // Maximum speed 
// 400 slower forward
#define MIN_SPEED 100  // Maximum speed backward
// 200 slower backwards


//TODO
// - Come up with a way to identify servo positions
//  - Come up with guards to stop damage, including thumb blocking the index
// - Consider addition speed to the transitions for position movements (currently opearates at max speed)
// - Enable repeat motions
// - Find a more elegant way to avoid having pwm set up twice
// - Figure out the best way to go about casting
// - Software documentations
//  - As if someone welse is going ot use it to build something

/**
    Send Commands to the hand structured as the following:
    FingerID 
    Joint num (to identify top or lower servo)
    Command Type (Two that pop into mind are:
        movement:   Moves the finger a certain amount stopping if it reaches "limit"
        position:   Figures out how to get the finger to the specified position
        delay:      Just delays if there are multiple commands for each of the fingers and whatnot
    )
    Values
    TODO: 
    Decide whether its better to have a virtual class with it or not
*/
enum FingerEnum{
    THUMB, 
    INDEX, 
    MIDDLE, 
    RING, 
    LITTLE,
};
enum JointEnum{
    TOP,
    BOT
};
enum CommandEnum{
    MOVEMENT,
    POSITION, 
    DELAY
};
struct Command {
    FingerEnum finger;
    JointEnum joint;
    CommandEnum command;
    void *args; 

    Command(FingerEnum fEnum, JointEnum jEnum, CommandEnum cEnum, void* args) :
        finger(fEnum), joint(jEnum), command(commandEnum), args(args) {}
};


/**
    This keeps track of the servos positions.
    It is responsible for ensuring the fingers dont exceeed their limits.
    
    TODO:  
        Actually come up with a way to track the joints positions. 
        Current Impl: 
*/
struct ServoPosn {
    uint score            = 0;
    short overflowCounter = 0;
    
    void update(int time, int speed){
        // if time is 0 it gives a default value of 1
        uint newScore += speed + (time == 0) ? 1 : time;
        
        // Check for an overflow
        uint checkScore = score + newScore;
        if(checkScore < score){ 
            overflowCounter++;
            score = newScore
        } else {
            score = checkScore;
        }
    }

    uint getPosn(){
        return score;
    }

    std::stringstream toString(){
        std::stringstream ss;
        return ss << "OverFlow: " << this.overflowCounter << " Score: " << this.score << "\n";
    }
};


class Joint{
public:
    void update(Command cmd){
        switch(cmd.CommandEnum){
            // Once its decided how to implement movement and position it needs to casted to the proper
            case CommandEnum::MOVEMENT: movement(cmd.args);     break;
            case CommandEnum::POSITION: position(cmd.args);     break;
            case CommandEnum::DELAY:    delay(*(int*)cmd.args); break;
            default: break;
        }
    }

    Joint(uint servoNum) : servoNum(servoNum) {
        pwm.begin();
        pwm.setPWMFreq(50); // Set frequency to 50Hz
    }

private:
    void movement(void *args){

        delay(100);
    }
    void position(void *args){
        
        delay(100);
    }


    ServoPosn servoPosn;
    uint servoNum;
    Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x40); // Default I2C address
};

// Finger
class Finger{
public:
    Finger(uint top, uint bot) : topJoint(top), botJoint(bot) {}
    void update(Command cmd){

        switch(cmd.joint){
            case JointEnum::TOP: topJoint.update(cmd); break;
            case JointEnum::TOP: botJoint.update(cmd); break;
            default: break;
        }
    }
    
private:
    // Some sort of state representation
    // Restrictions would go here? Maybe they influence how servoPosn works
    Joint topJoint;
    Joint botJoint;
};

// Hand
class Hand{
public:
    // Ik i can initialize  without this so ill fix this later.
    Hand(){
        this.fingers = new std::unordered_map<std::string, Finger>({
            {THUMB,  Finger(0, 1)},
            {INDEX,  Finger(2, 3)},
            {MIDDLE, Finger(4, 5)},
            {RING,   Finger(6, 7)},
            {LITTLE, Finger(7, 9)}
        });
    }

    ~Hand(){ delete fingers; }

    // Working on the assumption that will be passed in vector of commands 
    void update(std::vector<Command> commands){
        std::for_each(commands.begin(), commands.end(), [this](const Command& cmd){
            auto it = fingers->find(cmd.fingerEnum)            
            if(it != fingers.end()){
                it->second.update(cmd);
            }
        });
    }

    std::string toString(){

    }

private:
    std::unordered_map<FingerEnum, Finger> *fingers;
};



