
String moxieCSV = "";

void homePage()
{
  String homePage =
      "<html>\
      <body>\
        <h1>Moxie Points!</h1>" +
      moxieCSV +
      "</body>\
    </html>";

  server.send(200, "text/html", homePage);
}

void updateWebsite()
{
  String points = "\n<p>test, " + getMoxiePoints("test") + "</p>";
  
  for (int i = 0; i < 24; i++)
  {
    points += "\n<p>" + String(i) + ", " + getMoxiePoints(String(i)) + "</p>";
  }

  moxieCSV = points;
}

void handleRequests()
{
  updateWebsite();
  server.handleClient();
}

void setupWebsite()
{
  connectToWifi();
  setupHttpServer();
}

void connectToWifi()
{
  const String WIFI_NAME = "PumpingStationOne";
  const String WIFI_PASSWORD = "ps1frocks";

  WiFi.begin(WIFI_NAME, WIFI_PASSWORD);

  while (WiFi.status() != WL_CONNECTED)
  {
    String message = "Connecting to " + WIFI_NAME;
    Serial.println(message);
    delay(2000);
  }
  Serial.println("Connected, assigned " + WiFi.localIP());
}

void setupHttpServer()
{
  server.on("/", homePage);
  server.begin();
  Serial.println("HTTP server started");
}