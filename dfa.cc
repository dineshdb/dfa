#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Transition {
public:
    char currentState;
    char input;
    char nextState;
    Transition(char c, char i, char n) : currentState(c), input(i), nextState(n){}
};

class NoTransitionDefined{};

class DFA {
public:
    string input;
    vector<char> states;
    vector<char> finalStates;
    vector<Transition> transitions;
    char currentState;
    
    void addState(char state){
        this->states.push_back(state);
    }
    void addFinalState(char state){
        this->states.push_back(state);
        this->finalStates.push_back(state);
    }
    
    void addTransition(char currentState, char input, char nextState){
        Transition t = Transition(currentState, input, nextState);
        this->transitions.push_back(t);
    }

    void startExecution(){
        this->currentState = this->states[0];
    }
    void nextState(char input){
	for( auto tran: this->transitions){
		if( tran.currentState == this->currentState && input == tran.input){
			this-> currentState = tran.nextState;
			return;
		}
	}
	
	throw NoTransitionDefined();
    }
};

int main(){
    DFA a = DFA();
    a.addState('P');
    a.addState('Q');
    a.addFinalState('R');
    
    a.addTransition('P', 'a', 'Q');
    a.addTransition('P', 'b', 'R');
    a.addTransition('Q', 'a', 'R');
    a.addTransition('Q', 'b', 'Q');
    
    a.startExecution();
    cout << a.currentState << endl;
    a.nextState('a');
    cout << a.currentState << endl;
}
