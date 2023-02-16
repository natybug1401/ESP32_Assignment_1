  //define waveform parameters
  /*the calculated parameters were:
      a=200uS
      b=600uS
      c=13
      d=3500uS
      mode=2
  */
  const int pulseWidth = 200;                                                     //parameter A - width of inital pulse (μS) 
  const int pulseWidthIncrement = 50;                                             //incremental increase of pulse width (μS)
  const int pulseSpacing = 600;                                                   //parameter B - width of space between pulses (μS)
  const int pulsesPerBlock = 13;                                                  //parameter C - number of pulses in a block
  const int blockSpacing = 3500;                                                  //parameter D - width of space between blocks (μS)

  //define testing multiplier, set to 1 for oscilloscope, set to 1000 for LEDs
  const int testingMultiplier = 1000;                                             
  
  //define constants for I/O pin numbers
  const int switch1Pin = 5;
  const int switch2Pin = 4;
  const int signalAPin = 3;
  const int signalBPin = 18;

//method ran at start of program. Used to set the mode of I/O pins
void setup() {
  
  //set the pins for the buttons as inputs and for the signals as outputs
  pinMode(switch1Pin, INPUT);
  pinMode(switch2Pin, INPUT);
  pinMode(signalAPin, OUTPUT);
  pinMode(signalBPin, OUTPUT);
  
}

//method that continuously loops after setup() has ran. Used to run the signal generation methods when required
void loop() {

  if (digitalRead(switch1Pin) == HIGH)                                                                //if switch 1 is pressed
  { 
    sigB();                                                                                           //run signal B
    sigA(digitalRead(switch2Pin));                                                                    //run signal A, with the state of switch 2 passed as an argument  
  }
  
}

//method to generate signal A, the modifier argument controls whether the basic or modifed signal is generated
void sigA(int modifier){
  
  for (uint8_t i=0; i<pulsesPerBlock; i++)                                                            //iterate from 0 to Parameter C
  {
    
    digitalWrite(signalAPin, HIGH);                                                                   //set the signal high
    
    if (modifier == HIGH)                                                                             //if the switch is engaged, modified mode is selected
    {
      delayMicroseconds((pulseWidth+(pulseWidthIncrement*(pulsesPerBlock-1-i)))*testingMultiplier);   //wait for a time defined by parameter A + parameter B * no. of remaining pulses
    }
    
    else                                                                                              //if the switch is not engaged, regular mode is selected
    { 
      delayMicroseconds((pulseWidth+(pulseWidthIncrement*i))*testingMultiplier);                      //wait for a time defined by parameter A + parameter B * no. of prior pulses
    }
    
    digitalWrite(signalAPin, LOW);                                                                    //set the signal low
    delayMicroseconds((pulseSpacing)*testingMultiplier);                                              //at the end of each pulse, wait for a time defined by parameter B
    
  }
  
  delayMicroseconds((blockSpacing)*testingMultiplier);                                                //at the end of each block of pulses, wait for a time defined by parameter D
  
}

//method to generate signal B
void sigB(){
  
  digitalWrite(signalBPin, HIGH);                                                                     //set the signal high
  delayMicroseconds((50)*testingMultiplier);                                                          //wait 50 microseconds
  digitalWrite(signalBPin, LOW);                                                                      //set the signal low
  
}
