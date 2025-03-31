#pragma once
#include <hand.h>

// Rock Paper Scissors
std::vector<Command> paper = {
	Command(FingerEnum::INDEX, 	JointEnum::TOP, CommandEnum::POSITION, (void*)&(int){0}),
	Command(FingerEnum::INDEX, 	JointEnum::BOT, CommandEnum::POSITION, (void*)&(int){0}),

	Command(FingerEnum::MIDDLE, JointEnum::TOP, CommandEnum::POSITION, (void*)&(int){0}),
	Command(FingerEnum::MIDDLE, JointEnum::BOT, CommandEnum::POSITION, (void*)&(int){0}),

	Command(FingerEnum::RING,  	JointEnum::TOP, CommandEnum::POSITION, (void*)&(int){0}),
	Command(FingerEnum::RING,  	JointEnum::BOT, CommandEnum::POSITION, (void*)&(int){0}),

	Command(FingerEnum::LITTLE,	JointEnum::TOP, CommandEnum::POSITION, (void*)&(int){0}),
	Command(FingerEnum::LITTLE,	JointEnum::BOT, CommandEnum::POSITION, (void*)&(int){0}),

    Command(FingerEnum::THUMB, 	JointEnum::TOP, CommandEnum::POSITION, (void*)&(int){0}),
	Command(FingerEnum::THUMB, 	JointEnum::BOT, CommandEnum::POSITION, (void*)&(int){0})
};

// Approximating first with 90 degrees
std::vector<Command> rock = {
	Command(FingerEnum::INDEX, 	JointEnum::TOP, CommandEnum::POSITION, (void*)&(int){90}),
	Command(FingerEnum::INDEX, 	JointEnum::BOT, CommandEnum::POSITION, (void*)&(int){90}),

	Command(FingerEnum::MIDDLE, JointEnum::TOP, CommandEnum::POSITION, (void*)&(int){90}),
	Command(FingerEnum::MIDDLE, JointEnum::BOT, CommandEnum::POSITION, (void*)&(int){90}),

	Command(FingerEnum::RING,  	JointEnum::TOP, CommandEnum::POSITION, (void*)&(int){90}),
	Command(FingerEnum::RING,  	JointEnum::BOT, CommandEnum::POSITION, (void*)&(int){90}),

	Command(FingerEnum::LITTLE,	JointEnum::TOP, CommandEnum::POSITION, (void*)&(int){90}),
	Command(FingerEnum::LITTLE,	JointEnum::BOT, CommandEnum::POSITION, (void*)&(int){90}),

    Command(FingerEnum::THUMB, 	JointEnum::TOP, CommandEnum::POSITION, (void*)&(int){90}),
	Command(FingerEnum::THUMB, 	JointEnum::BOT, CommandEnum::POSITION, (void*)&(int){90})
};

std::vector<Command> scissor = {
	Command(FingerEnum::INDEX, 	JointEnum::TOP, CommandEnum::POSITION, (void*)&(int){0}),
	Command(FingerEnum::INDEX, 	JointEnum::BOT, CommandEnum::POSITION, (void*)&(int){0}),

	Command(FingerEnum::MIDDLE, JointEnum::TOP, CommandEnum::POSITION, (void*)&(int){0}),
	Command(FingerEnum::MIDDLE, JointEnum::BOT, CommandEnum::POSITION, (void*)&(int){0}),

	Command(FingerEnum::RING,  	JointEnum::TOP, CommandEnum::POSITION, (void*)&(int){90}),
	Command(FingerEnum::RING,  	JointEnum::BOT, CommandEnum::POSITION, (void*)&(int){90}),

	Command(FingerEnum::LITTLE,	JointEnum::TOP, CommandEnum::POSITION, (void*)&(int){90}),
	Command(FingerEnum::LITTLE,	JointEnum::BOT, CommandEnum::POSITION, (void*)&(int){90}),

    Command(FingerEnum::THUMB, 	JointEnum::TOP, CommandEnum::POSITION, (void*)&(int){90}),
	Command(FingerEnum::THUMB, 	JointEnum::BOT, CommandEnum::POSITION, (void*)&(int){90})
};

// movement
std::vector<Command> come_closer = {
    // Set Up
    // Move thumb out of the way so the index isnt locked in
    Command(FingerEnum::THUMB, 	JointEnum::TOP, CommandEnum::POSITION, (void*)&(int){0}),
	Command(FingerEnum::THUMB, 	JointEnum::BOT, CommandEnum::POSITION, (void*)&(int){0})
    // Move index out of the way
    Command(FingerEnum::INDEX, 	JointEnum::TOP, CommandEnum::POSITION, (void*)&(int){0}),
	Command(FingerEnum::INDEX, 	JointEnum::BOT, CommandEnum::POSITION, (void*)&(int){0}),

    // Set the other positions
	Command(FingerEnum::MIDDLE, JointEnum::TOP, CommandEnum::POSITION, (void*)&(int){90}),
	Command(FingerEnum::MIDDLE, JointEnum::BOT, CommandEnum::POSITION, (void*)&(int){90}),

	Command(FingerEnum::RING,  	JointEnum::TOP, CommandEnum::POSITION, (void*)&(int){90}),
	Command(FingerEnum::RING,  	JointEnum::BOT, CommandEnum::POSITION, (void*)&(int){90}),

	Command(FingerEnum::LITTLE,	JointEnum::TOP, CommandEnum::POSITION, (void*)&(int){90}),
	Command(FingerEnum::LITTLE,	JointEnum::BOT, CommandEnum::POSITION, (void*)&(int){90}),

    Command(FingerEnum::THUMB, 	JointEnum::TOP, CommandEnum::POSITION, (void*)&(int){90}),
	Command(FingerEnum::THUMB, 	JointEnum::BOT, CommandEnum::POSITION, (void*)&(int){90}),

    // repeat rocking motion numerours times
    std::pair<int, int> forward(400, 1000); 
    std::pair<int, int> backward(400, 1000); 
    Command(FingerEnum::INDEX, 	JointEnum::TOP, CommandEnum::MOVEMENT, static_cast<void*>(&forward)),
    Command(FingerEnum::INDEX, 	JointEnum::TOP, CommandEnum::MOVEMENT, static_cast<void*>(&forward)),
    
    Command(FingerEnum::INDEX, 	JointEnum::TOP, CommandEnum::MOVEMENT, static_cast<void*>(&backward)),
	Command(FingerEnum::INDEX, 	JointEnum::BOT, CommandEnum::MOVEMENT, static_cast<void*>(&backward)),

    // 2nd time
    Command(FingerEnum::INDEX, 	JointEnum::TOP, CommandEnum::MOVEMENT, static_cast<void*>(&forward)),
    Command(FingerEnum::INDEX, 	JointEnum::TOP, CommandEnum::MOVEMENT, static_cast<void*>(&forward)),
    
    Command(FingerEnum::INDEX, 	JointEnum::TOP, CommandEnum::MOVEMENT, static_cast<void*>(&backward)),
	Command(FingerEnum::INDEX, 	JointEnum::BOT, CommandEnum::MOVEMENT, static_cast<void*>(&backward)),
}

