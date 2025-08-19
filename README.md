# USB to Dual CAN-Bus Board 🔌🚌🚌

本專案為 **UTL USB to Dual CAN-Bus EVM Board** 的範例程式碼，使用 Seeeduino XIAO 作為主控，透過 SPI 控制雙路 MCP2515 CAN 控制器，實現 USB to Dual CAN-Bus 功能。  
支援 Arduino IDE 開發與快速上手。

---

## 📚 Overview | 簡介

This repository contains example code and utility libraries for **UTL USB to Dual CAN-Bus Board**.  
It enables USB communication with two independent CAN-Bus channels via MCP2515.  
適合開發車用 CAN 裝置、機器人網路、工控設備通訊等應用。

---

## 🧰 Requirements | 使用環境

- ✅ Arduino IDE 1.8.x / 2.x
- ✅ Seeeduino XIAO nRF52840 Sense
- ✅ MCP2515 CAN Controller (x2)
- ✅ External 8MHz~16MHz Crystal (MCP2515 clock source)

---

## 📦 Included Code | 專案內容

本專案包含以下自製函式庫與範例程式：

### ✅ Libraries
- **UTL_MCP_CAN** — 封裝 MCP2515 初始化、傳送與接收函式。
- **UTL_Timer / UTL_Event** — 非阻塞的計時器與事件排程機制，適合多任務控制。

### ✅ Example
- `USB_DUAL_CAN.ino` — 主範例，展示如何使用兩個 MCP2515 控制器同時收發 CAN 訊息。

---

## 🚀 Getting Started | 快速開始

1. **安裝開發板套件**  
   在 Arduino IDE 中安裝 **Seeeduino XIAO nRF52840 board support**。

2. **安裝函式庫**  
   將本專案複製或下載，放入 Arduino `libraries/` 目錄。

3. **接線說明**  
   | Seeeduino XIAO Pin | MCP2515 #1 | MCP2515 #2 |
   |---------------------|------------|------------|
   | D2 (INT)            | INT        | INT        |
   | D3 (CS)             | CS         | -          |
   | D4 (CS)             | -          | CS         |
   | SPI (SCK/MOSI/MISO) | 共用       | 共用       |

4. **上傳範例程式**  
   打開 `USB_DUAL_CAN.ino`，選擇對應開發板與序列埠，按下「上傳」。

---

## 🧪 Features | 功能特色

- 雙通道 CAN 同時傳送與接收（獨立濾波與掩碼）
- 可選擇標準/擴展 ID 與遠端訊框（RTR）
- 使用中斷腳（INT）提高接收效率
- 支援 8MHz 或 16MHz MCP2515 外部時鐘

---

## 📁 File Structure | 檔案結構

```
.
├── examples/
│   └── USB_DUAL_CAN.ino           # 主範例
├── UTL_MCP_CAN.h / .cpp / _DFS.h # MCP2515 函式庫
├── UTL_Timer.h / .cpp            # 計時器函式庫
├── UTL_Event.h / .cpp            # 事件物件函式庫
└── README.md                     # 本說明文件
```

---

## 🧑‍💻 Author & License

- Author: [Long Jun, Chiou](https://github.com/Long-Jun) @ NTUT UTL & SPIE Lab  
- License: MIT

---

## 💬 Feedback

如果你在使用過程中有任何疑問、Bug 回報或改進建議，歡迎開啟 [Issue](https://github.com/你的repo/issues) 或發送 Pull Request！
