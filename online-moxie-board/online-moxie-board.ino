
#include <ESP8266WiFi.h>
#include <Firebase_ESP_Client.h>
#include <Adafruit_PCF8574.h>

#include "addons/TokenHelper.h"
#include "addons/RTDBHelper.h"

#define WIFI_SSID "__SSID_HERE__"
#define WIFI_PASSWORD "__WIFI__PASSWORD__HERE__"

#define API_KEY "__API_KEY_HERE__"
#define DATABASE_URL "https://prs-moxie-votes-default-rtdb.firebaseio.com/" 

FirebaseData fbdo;
FirebaseAuth auth;
FirebaseConfig config;
FirebaseJson json;
int databaseUpdateInterval = 15000;
String databaseName = "MKE_" + String(random(10000));
unsigned long lastDatabaseUpdateTime = 0;
bool firebaseLoggedIn = false;

uint16_t votes[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
uint16_t mapButtonsFromTheWayTheyAreWiredToTheWayTheyAppearOnTheMoxieBoard[] = {7,6,5,4,3,2,1,0,15,14,13,12,11,10,9,8,23,21,22,20,19,18,17,16};



Adafruit_PCF8574 board1;
Adafruit_PCF8574 board2;
Adafruit_PCF8574 board3;
uint8_t board1Address = 0x20;
uint8_t board2Address = 0x21;
uint8_t board3Address = 0x22;
// uint8_t board4Address = 0x23;
uint8_t board1InteruptPin = 14; //d5 GPIO14
uint8_t board2InteruptPin = 12; //d6 GPIO12
uint8_t board3InteruptPin = 15; //d8 GPIO15



uint8_t mostRecentlyPressedButton = 99;
bool newButtonPress = false;

void setup() {
  Serial.begin(115200);
  wifiSetup();
  firebaseSetup();
  ioBoardSetup();
}

void loop() {
  if(newButtonPress){
    printButtonInfo();
    sendVotesToTheInternet();
    delay(300); // debounce
    newButtonPress = false;
  }
}

void sendVotesToTheInternet() {
  int currentTime = millis();
  int timeSinceLastUpdate = currentTime - lastDatabaseUpdateTime;

  if (Firebase.ready() && firebaseLoggedIn && timeSinceLastUpdate > databaseUpdateInterval){
    lastDatabaseUpdateTime = currentTime;

    // create json object with teams and votes
    for(int teamNumber = 0; teamNumber<16; teamNumber++){
      json.set(String(teamNumber), String(votes[teamNumber]));
    }
    // send the json to firebase
    Firebase.RTDB.setJSON(&fbdo, databaseName, &json);
  }
}

void printButtonInfo() {
  Serial.println("Button " + String(mostRecentlyPressedButton) + ": " + String(votes[mostRecentlyPressedButton]));
}


void wifiSetup() {
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED){
    Serial.print(".");
    delay(300);
  }
  Serial.println();
  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());
  Serial.println();
}

void firebaseSetup() {
  config.api_key = API_KEY;

  config.database_url = DATABASE_URL;

  if (Firebase.signUp(&config, &auth, "", "")){
    Serial.println("ok");
    firebaseLoggedIn = true;
  }
  else{
    Serial.printf("%s\n", config.signer.signupError.message.c_str());
  }

  config.token_status_callback = tokenStatusCallback;
  
  Firebase.begin(&config, &auth);
  Firebase.reconnectWiFi(true);
}

void setupIOBoard(Adafruit_PCF8574 board) {
  for (uint8_t p=0; p<8; p++) {
    board.pinMode(p, INPUT_PULLUP);
  }
}

void ICACHE_RAM_ATTR board1InteruptHandler () {
    findTheButton(board1, 1);
}

void ICACHE_RAM_ATTR board2InteruptHandler () {
    findTheButton(board2, 2);
}

void ICACHE_RAM_ATTR board3InteruptHandler () {
    findTheButton(board3, 3);
}

uint8_t findTheButton(Adafruit_PCF8574 board, uint8_t boardNumber) {
  boardNumber = boardNumber - 1;
  for (uint8_t p=0; p<8; p++) {
    if (!board.digitalRead(p)) {
      newButtonPress = true;

      int add8IfTheButtonIsOnTheSecondIOExpanderBoard = p + boardNumber * 8;
      int button = mapButtonsFromTheWayTheyAreWiredToTheWayTheyAppearOnTheMoxieBoard[add8IfTheButtonIsOnTheSecondIOExpanderBoard];
      votes[button]++;
      mostRecentlyPressedButton = button;
    }
  }
  return 98;
}

void ioBoardSetup() {
  board1.begin(board1Address, &Wire);
  setupIOBoard(board1);
  board2.begin(board2Address, &Wire);
  setupIOBoard(board2);
  board3.begin(board3Address, &Wire);
  setupIOBoard(board3);

  pinMode(board1InteruptPin, INPUT_PULLUP);
  pinMode(board2InteruptPin, INPUT_PULLUP);
  pinMode(board3InteruptPin, INPUT_PULLUP);
  attachInterrupt(board1InteruptPin, board1InteruptHandler, FALLING);
  attachInterrupt(board2InteruptPin, board2InteruptHandler, FALLING);
  attachInterrupt(board3InteruptPin, board3InteruptHandler, FALLING);
}