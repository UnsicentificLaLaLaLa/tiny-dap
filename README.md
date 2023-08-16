# tiny-dap

[TOC]

## 介绍

基于 TinyUSB 和 CMSIS-5 实现的 CMSIS-DAP，支持 SWD 调试接口和串口通信。

选择 TinyUSB 作为协议栈的原因是 TinyUSB 开源免费，且适配多家 MCU，具有良好的通用性。

基于 CMSIS-5 实现 CMSIS-DAP 可以降低移植 DapLink 的难度，降低实现门槛。

## 文件结构

- hardware

    - v1.x

        tiny-dap 的硬件实现，使用 KiCad 7.0 设计，已生成生产文件和原理图。

        - production

            使用 KiCad 嘉立创提供的插件生成的生产文件。

- software

    tiny-dap 的软件实现，基于 MM32F0162D4Q。

## 适配芯片

目前计划采用 MM32F0162D4Q 作为 tiny-dap 的 MCU，后续也将计划在更多 QFN32 芯片上实现 tiny-dap，如果有精力的话。

