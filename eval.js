let input = require("./state-machine.js")

class DFA {
  constructor(obj){
      this.states = {}
      this._initialState =  obj.states[0]
      this._currentState = this._initialState

      for (let state of obj.states){
      	  let isFinal = obj.finalStates.includes(state)
          this.states[state] = { isFinal}
      }
      
      let a = obj.transitions.map(line => line.replace(" ", "").split("->")).forEach(([a, i, b]) =>{
	  if(this.states[a] === null){
	     console.error(`No such state '${a}' is defined. Exiting.`)
	     process.exit(1)
	  }
	  
	  this.states[a][i] = b
      })
  }
  
  get inFinalState(){
      return this.states[this._currentState].isFinal
  }
  
  step(input){
      this._currentState = this.states[this._currentState][input]
      if(this._currentState === null){
         console.error(`No such input '${input}' is defined. Exiting.`)
      }
  }
  
  evaluate(input){
    let trans = []
    trans.push(dfa.currentState)
    for(let letter of input.replace(" ", "")){
      dfa.step(letter)
      trans.push(dfa.currentState)
    }
    return trans
  }
  get initialState(){
  	return this._initialState
  }
  
  get currentState(){
  	return this._currentState
  }
}


let dfa = new DFA(input)
let transitions = dfa.evaluate("a")
console.log(transitions, dfa.inFinalState ? "Accepted": "Rejected")
