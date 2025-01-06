#include <mcp_can.h>
#include <SPI.h>
#include <Timer.h>

/* 開發板備註 https://github.com/Long-Jun/USB_Dual-CAN_Converter
   MCP2515 採用 8Mhz XTAL，要注意code需設定為8Mhz
   MCU 採用 Seeeduino Xiao，同時可相容 Seeeduino Xiao BLE，I2C要注意電壓位準為3.3V
*/


//CAN BUS 需要使用的全域變數
long unsigned int rxId;
unsigned char len = 0;
unsigned char rxBuf[8];
char msgString[128];

//CAN 1; INT -> D0, CS -> D2
#define CAN1_INT 0
MCP_CAN CAN1(2);

//CAN 2; INT -> D1, CS -> D3
#define CAN2_INT 1
MCP_CAN CAN2(3);

//宣告程式化LED腳位變數名稱
#define P1 4
#define P2 5
#define P3 6
#define P4 7

//宣告timer函數
Timer LED;

void setup()
{
  Serial.begin(115200);

  //初始化 CAN-1  MCP2515
  if (CAN1.begin(MCP_ANY, CAN_500KBPS, MCP_8MHZ) == CAN_OK)
    Serial.println("CAN1 Initialized Successfully!");
  else
    Serial.println("Error Initializing CAN0...");

  //設定 CAN-1 模式
  CAN1.setMode(MCP_NORMAL);
  pinMode(CAN1_INT, INPUT);

  //初始化 CAN-2 MCP2515
  if (CAN2.begin(MCP_ANY, CAN_500KBPS, MCP_8MHZ) == CAN_OK)
    Serial.println("CAN2 Initialized Successfully!");
  else
    Serial.println("Error Initializing CAN1...");

  //設定 CAN-2 模式
  CAN2.setMode(MCP_NORMAL);
  pinMode(CAN2_INT, INPUT);

  Serial.println("CAN1, CAN2 Ready...");

  //設定I2C P1、P2，為Open-Drain輸入
  pinMode(P1, INPUT);
  pinMode(P2, INPUT);

  //設定可程式化 LED P3、P4，為 OUTPUT 輸出
  pinMode(P3, OUTPUT);
  pinMode(P4, OUTPUT);
  delay(10);

  //設定可程式化 LED 亮起
  digitalWrite(P3, LOW);
  digitalWrite(P4, LOW);
  delay(10);

  LED.oscillate(P3, 500, LOW);
  LED.oscillate(P4, 500, LOW);

}

void loop()
{
  CAN1_receive();
  CAN2_receive();

  LED.update();
}


void CAN1_receive() {

  //CAN1 接收程式碼(通過INT實現)

  // If CAN1_INT pin is low, read receive buffer
  if (!digitalRead(CAN1_INT))
  {
    // Read data: len = data length, buf = data byte(s)
    CAN1.readMsgBuf(&rxId, &len, rxBuf);

    // Determine if ID is standard (11 bits) or extended (29 bits)
    if ((rxId & 0x80000000) == 0x80000000)
      sprintf(msgString, "Extended ID: 0x%.8lX  DLC: %1d  Data:", (rxId & 0x1FFFFFFF), len);
    else
      sprintf(msgString, "Standard ID: 0x%.3lX       DLC: %1d  Data:", rxId, len);

    Serial.print("CAN1: ");
    Serial.print(msgString);

    if ((rxId & 0x40000000) == 0x40000000) {
      // Determine if message is a remote request frame.
      sprintf(msgString, " REMOTE REQUEST FRAME");
      Serial.print(msgString);
    }
    else {
      for (byte i = 0; i < len; i++) {
        sprintf(msgString, " 0x%.2X", rxBuf[i]);
        Serial.print(msgString);
      }
    }
    Serial.println();
  }
}


void CAN2_receive() {

  //CAN2 接收程式碼(通過INT實現)

  // If CAN2_INT pin is low, read receive buffer
  if (!digitalRead(CAN2_INT))
  {
    // Read data: len = data length, buf = data byte(s)
    CAN2.readMsgBuf(&rxId, &len, rxBuf);

    // Determine if ID is standard (11 bits) or extended (29 bits)
    if ((rxId & 0x80000000) == 0x80000000)
      sprintf(msgString, "Extended ID: 0x%.8lX  DLC: %1d  Data:", (rxId & 0x1FFFFFFF), len);
    else
      sprintf(msgString, "Standard ID: 0x%.3lX       DLC: %1d  Data:", rxId, len);

    Serial.print("CAN2: ");
    Serial.print(msgString);

    if ((rxId & 0x40000000) == 0x40000000) {
      // Determine if message is a remote request frame.
      sprintf(msgString, " REMOTE REQUEST FRAME");
      Serial.print(msgString);
    }
    else {
      for (byte i = 0; i < len; i++) {
        sprintf(msgString, " 0x%.2X", rxBuf[i]);
        Serial.print(msgString);
      }
    }
    Serial.println();
  }
}



/* 作廢程式碼保留區

  void CAN0_receive() {

  //CAN1 接收程式碼(通過INT觸發實現)
  if (!digitalRead(CAN0_INT))                        // If CAN0_INT pin is low, read receive buffer
  {
    CAN0.readMsgBuf(&rxId, &len, rxBuf);      // Read data: len = data length, buf = data byte(s)
    uint32_t ID = rxId & 0x1FFFFFFF;

    switch (ID) {
      case 0x2901:
        Serial.println("ID 1 find");
        break;
      case 0x2902:
        Serial.println("ID 2 find");
        break;
      case 0x2903:
        Serial.println("ID 3 find");
        break;
      case 0x2904:
        Serial.println("ID 4 find");
        break;

    }

    //Serial.println(ID, HEX);

    //print_can_value();

  }

*/
