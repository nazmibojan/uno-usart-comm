String request = "get_status\r\n";
String rx_string = "";
char relay_status;
bool stringComplete = false;

void setup() {
  Serial.begin(9600);
}

void loop() {
  // Receive character until get '\n'
  if (stringComplete) {
    Serial.println(rx_string);
    // Check if UNO receive 'get_status' phrase
    if (rx_string == request) {
      Serial.println("relay_off");
    }

    rx_string = "";
    stringComplete = false;
  }
}

void serialEvent() {
  while (Serial.available()) {
    char inChar = (char)Serial.read();
    rx_string += inChar;
    if (inChar == '\n') {
      stringComplete = true;
    }
  }
}
