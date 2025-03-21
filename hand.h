#include <sstream>
#include <unordered_map>
#include <vector>
//TODO  - Ask if i can moving servos is blocking or non blocking
//      - make the naming convention _ instead of camelcase or standardize the enums naming

/**
    Send Commands to the hand structured as the following:
    FingerID (to identify which finger this applies to)
    Command Type (Two that pop into mind are:
        movement:   Moves the finger a certain amount stopping if it reaches "limit"
        position:   Figures out how to get the finger to the specified position
        delay:      Just delays if there are multiple commands for each of the fingers and whatnot
    )
    Values
    TODO: 
    - Will i be passing in a c array of commands or vectors 
    - No General delay ie get to a posn and wait for other to also get there
*/
enum FingerEnum{
    THUMB, 
    INDEX, 
    MIDDLE, 
    RING, 
    LITTLE,
};
enum CommandEnum{
    MOVEMENT,
    POSITION, 
    DELAY
};
struct Command {
    FingerEnum fingerEnum;
    CommandEnum commandEnum;
    void *args; 


};


// To keep track of the servo position
//TODO: 
// - find out when it resets to reduce how much data is being stored.
// - will need to be adapted to fit 
// can set it up so overflowCounter just
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
}

// Finger
class Finger{
public:

    // TODO: Honestly might be an easier and mor elegant way of handling this
    // And decide whether or not to cast before sending to the appropriate functions
    void update(CommandEnum commandEnum, void *args){
        // Might need to add in this. in front of commands
        switch(commandEnum){
            case MOVEMENT:
                movement(args);
                break;
            case POSITION:
                position(args);
                break;
            case DELAY:
                delay(args);
                break;
            default:
                break;
        }
    }
    
    void movement(void *args){

    }

    void position(void *args){

    }

    void delay(void *args){

    }
    
private:
    // Some sort of state representation
    ServoPosn servoPosn;
    // Restrictions would go here? Maybe they influence how servoPosn works
};

// Hand
class Hand{
public:
    // Ik i can initialize  without this so ill fix this later.
    Hand(){
        this.fingers = new std::unordered_map<std::string, Finger>({
            {THUMB,  Finger()},
            {INDEX,  Finger()},
            {MIDDLE, Finger()},
            {RING,   Finger()},
            {LITTLE, Finger()}
        });
    }

    ~Hand(){ delete fingers; }

    // Working on the assumption that will be passed in vector of commands 
    void update(std::vector<Command> commands){
        std::for_each(commands.begin(), commands.end(), [this](const Command& cmd){
            auto it = fingers->find(cmd.fingerEnum)            
            if(it != fingers.end()){
                it->second.update(cmd.commandEnum, cmd.args);
            }
        });
    }

private:
    std::unordered_map<FingerEnum, Finger> *fingers;
};



