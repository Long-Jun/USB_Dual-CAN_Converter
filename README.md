# USB to Dual CAN-Bus Board 🔌🚌🚌  
**雙通道 CAN-Bus USB 轉接板範例專案**

This project provides example code for the **UTL USB to Dual CAN-Bus EVM Board**, using a Seeeduino XIAO microcontroller to control two MCP2515 CAN transceivers via SPI.  
本專案提供 **UTL USB to Dual CAN-Bus 擴展板** 的範例程式，使用 Seeeduino XIAO 透過 SPI 控制兩顆 MCP2515 CAN 控制器。

---

## 📚 Overview | 簡介

This repository contains example code and utility libraries for USB-to-CAN applications.  
此儲存庫包含 USB 轉雙 CAN-Bus 應用的範例程式與輔助函式庫。

Use cases include:
- Vehicle CAN diagnostics  
- Industrial controller communication  
- Robotics CAN networks  

應用場景包含：
- 車用 CAN 診斷工具  
- 工業控制器 CAN 通訊  
- 機器人 CAN 網路整合  

---

## 🧰 Requirements | 使用環境

- ✅ Arduino IDE 1.8.x / 2.x  
- ✅ Seeeduino XIAO nRF52840 Sense  
- ✅ MCP2515 CAN Controller x2  
- ✅ External 8~16MHz Crystal (MCP2515 clock source)  
- ✅ 外接 8~16MHz 晶體振盪器（MCP2515 時脈來源）

---

## 📦 Included Code | 專案內容

### ✅ Libraries | 函式庫

- `UTL_MCP_CAN` — MCP2515 initialization and CAN I/O wrapper  
  MCP2515 初始化、CAN 傳送與接收封裝  
- `UTL_Timer` / `UTL_Event` — non-blocking task scheduler and event framework  
  非阻塞的計時任務排程與事件管理函式庫

### ✅ Example | 範例程式

- `USB_DUAL_CAN.ino` — Example demonstrating dual MCP2515 CAN transmission  
  展示雙 MCP2515 同時傳輸與接收的範例程式

---

## 🚀 Getting Started | 快速上手

1. **Install Board Package | 安裝開發板套件**  
   Install Seeeduino XIAO nRF52840 via Arduino Boards Manager  
   透過 Arduino Boards Manager 安裝 Seeeduino XIAO nRF52840 開發板

2. **Install Library | 安裝函式庫**  
   Clone or copy this repo into your `Arduino/libraries/` folder  
   將本專案複製至 `Arduino/libraries/` 目錄

3. **Wiring Guide | 接線說明**

| Seeeduino XIAO Pin | MCP2515 CAN1 | MCP2515 CAN2 |
|--------------------|--------------|--------------|
| D0 (INT1)          | INT          |              |
| D1 (INT2)          |              | INT          |
| D2 (CS1)           | CS           | -            |
| D3 (CS2)           | -            | CS           |
| SPI (SCK/MOSI/MISO)| Shared       | Shared       |

| 說明 |  
|------|  
| INT 腳用於 MCP2515 接收中斷觸發。兩顆 MCP2515 共用同一組 SPI 腳位。|

4. **Upload Example | 上傳程式**  
   Open `USB_DUAL_CAN.ino`, select board and COM port, then upload.  
   打開 `USB_DUAL_CAN.ino`，選擇對應開發板與序列埠，上傳即可。

---

## 🧪 Features | 功能特色

- Dual-channel CAN send and receive via independent MCP2515 chips  
  雙通道 CAN 傳送與接收（獨立濾波與掩碼）
- Support for standard/extended IDs and RTR frames  
  支援標準與擴展 ID、遠端訊框（RTR）
- INT pin for interrupt-based reception  
  透過 INT 腳中斷觸發接收，提高效率
- 8~16MHz external crystal clock supported for MCP2515  
  支援 MCP2515 使用 8～16MHz 外部晶體作為時脈

---

## 📁 File Structure | 檔案結構

```
.
├── examples/
│   └── USB_DUAL_CAN.ino           # Main example 主範例
├── UTL_MCP_CAN.h / .cpp / _DFS.h # MCP2515 CAN library 函式庫
├── UTL_Timer.h / .cpp            # Timer function 計時器
├── UTL_Event.h / .cpp            # Event helper 事件排程
└── README.md                     # Project documentation 說明文件
```

---

## 👤 Author & License | 作者與授權

- Author / 作者: [Long Jun, Chiou](https://github.com/Long-Jun) @ NTUT UTL & SPIE Lab  
- License / 授權: Apache-2.0

---

## 💬 Feedback | 問題回報與建議

Feel free to open an Issue or Pull Request if you have suggestions or bug reports.  
如有使用問題、Bug 回報或改進建議，歡迎開啟 Issue 或發送 Pull Request！
