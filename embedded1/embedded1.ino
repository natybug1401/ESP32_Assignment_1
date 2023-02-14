void setup() {
  // put your setup code here, to run once:
  
  /*define waveform parameters. uint8_t is used to minimise size
    the calculated parameters were:
      a=200uS
      b=2100uS
      c=21
      d=3500uS
      mode=2
  */
  const uint8_t pulseWidth = 200          //parameter A - width of inital pulse (μS) 
  const uint8_t pulseWidthIncrement = 50  //incremental increase of pulse width (μS)
  const uint8_t pulseSpacing = 2100       //parameter B - width of space between pulses (μS)
  const uint8_t pulsesPerBlock = 21       //parameter C - number of pulses in a block
  const uint8_t blockSpacing = 3500       //parameter D - width of space between blocks (μS)
  
  //define constants for pin numbers
  const uint8_t switch1Pin = 5;
  const uint8_t switch2Pin = 4;
  const uint8_t signalAPin = 3;
  const uint8_t signalBPin = 18;

  //set the pins for the buttons as inputs and for the signals as outputs
  pinMode(switch1Pin, INPUT);
  pinMode(switch1Pin, INPUT);
  pinMode(signalAPinPin, OUTPUT);
  pinMode(signalBPinPin, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

}
