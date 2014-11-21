long baud = 115200L; // baud rate for HM-11 BLE
const bool pretty = true; // false for raw data output, no local echo.
String str;

void setup()
{
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }


  Serial.println("Initalizing.");

  // set the data rate for the SoftwareSerial port
  Serial1.begin(baud);
  delay(500);
  Serial.println("Sending AT - ready if OK received.");
  Serial.println("");
  Serial1.print("AT");
  
}

void loop() // run over and over
{
  if (pretty) {
    if(Serial1.available() > 0) {
    Serial1.setTimeout(100);
    str = Serial1.readString();
    Serial.print("> ");Serial.println(str);
    }
    if(Serial.available() > 0) {
      Serial.setTimeout(100);
      str = Serial.readString();
      Serial.print(str);
      Serial1.print(str);
    }
  } else {
    if (Serial1.available())
      Serial.write(Serial1.read());
    if (Serial.available())
      Serial1.write(Serial.read());
  }
}

