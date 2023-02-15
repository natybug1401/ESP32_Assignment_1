  /*define waveform parameters. uint8_t is used to minimise size
    the calculated parameters were:
      a=200uS
      b=2100uS
      c=22
      d=3500uS
      mode=2
  */
  const int pulseWidth = 200;          //parameter A - width of inital pulse (μS) 
  const int pulseWidthIncrement = 50;  //incremental increase of pulse width (μS)
  const int pulseSpacing = 2100;       //parameter B - width of space between pulses (μS)
  const int pulsesPerBlock = 21;       //parameter C - number of pulses in a block
  const int blockSpacing = 3500;       //parameter D - width of space between blocks (μS)
  
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
  if (digitalRead(switch1Pin) == HIGH) {
    sigB;
    
    if (digitalRead(switch2Pin) == HIGH){sigAInverted;}
    else {sigA;}
    
    delayMicroseconds(blockSpacing);
  }
}

void sigA(){
  for (uint8_t i=0; i<pulsesPerBlock; i++){
    digitalWrite(signalAPin, HIGH);
    delayMicroseconds(pulseWidth+(pulseWidthIncrement*i));
    digitalWrite(signalAPin, LOW);
    delayMicroseconds(pulseSpacing);
  }
}

void sigAInverted(){
  for (uint8_t i=pulsesPerBlock; i>0; i--){
    digitalWrite(signalAPin, HIGH);
    delayMicroseconds(pulseWidth+(pulseWidthIncrement*i));
    digitalWrite(signalAPin, LOW);
    delayMicroseconds(pulseSpacing);
  }
}

void sigB(){
  digitalWrite(signalBPin, HIGH);
  delayMicroseconds(50);
  digitalWrite(signalBPin, LOW);
}
