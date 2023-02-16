  /*define waveform parameters. uint8_t is used to minimise size
    the calculated parameters were:
      a=200uS
      b=2100uS
      c=22
      d=3500uS
      mode=2
  */
  const int pulseWidth = 200;                                 //parameter A - width of inital pulse (μS) 
  const int pulseWidthIncrement = 50;                         //incremental increase of pulse width (μS)
  const int pulseSpacing = 2100;                              //parameter B - width of space between pulses (μS)
  const int pulsesPerBlock = 21;                              //parameter C - number of pulses in a block
  const int blockSpacing = 3500;                              //parameter D - width of space between blocks (μS)
  
  //define constants for pin numbers
  const int switch1Pin = 5;
  const int switch2Pin = 4;
  const int signalAPin = 3;
  const int signalBPin = 18;


void setup() {
  //set the pins for the buttons as inputs and for the signals as outputs
  pinMode(switch1Pin, INPUT);
  pinMode(switch2Pin, INPUT);
  pinMode(signalAPin, OUTPUT);
  pinMode(signalBPin, OUTPUT);
}

void loop() {
  if (digitalRead(switch1Pin) == HIGH) {                      //if switch 1 is pressed
    sigB;                                                     //run signal B

    if (digitalRead(switch2Pin) == HIGH){sigAMod;}            //if switch 2 is also pressed, run the modified version of signal A
    else {sigA;}                                              //if switch 2 is not pressed, run the regular version of signal A

    delayMicroseconds(blockSpacing);                          //wait for a time defined by parameter D, before looping to start a new block of pulses
    
  }
}

//method to generate signal A
void sigA(){
  for (uint8_t i=0; i<pulsesPerBlock; i++){                   //iterate from 0 up to Parameter C
    digitalWrite(signalAPin, HIGH);                           //set the signal high
    delayMicroseconds(pulseWidth+(pulseWidthIncrement*i));    //wait for a time defined by parameter A + parameter B multiplied by the iteration value, as iteration counts up, this will increase the pulse length each iteration
    digitalWrite(signalAPin, LOW);                            //set the signal low
    delayMicroseconds(pulseSpacing);                          //wait for a time defined by parameter B
  }
}

//method to generate the modified signal A
void sigAMod(){
  for (uint8_t i=pulsesPerBlock; i>0; i--){                   //iterate from Parameter C down to 0 
    digitalWrite(signalAPin, HIGH);                           //set the signal high
    delayMicroseconds(pulseWidth+(pulseWidthIncrement*i));    //wait for a time defined by parameter A + parameter B multiplied by the iteration value, as iteration counts down, this will decrease the pulse length each iteration
    digitalWrite(signalAPin, LOW);                            //set the signal low
    delayMicroseconds(pulseSpacing);                          //wait for a time defined by parameter B
  }
}

void sigB(){
  digitalWrite(signalBPin, HIGH);                             //set the signal high
  delayMicroseconds(50);                                      //wait 50 microseconds
  digitalWrite(signalBPin, LOW);                              //set the signal low
}
