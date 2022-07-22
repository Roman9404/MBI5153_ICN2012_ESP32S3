# MBI5153_ICN2012_ESP32S3
Тестовая прошивка для длинного дисплея
схема подключения:
MAIN -- DISPLAY

COLUMN OUT -> MBI5153GP
SDO  -- SDI
CLK  -- DCLK
LE   -- LE
GCLK -- GCLK

LINE OUT -> SN74HC595OR
OE   -- OE
RCLK -- RCLK
SRCLR-- SRCLR
CLK  -- SRCLK
SDO  -- SIN
