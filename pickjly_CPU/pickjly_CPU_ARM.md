MCU structure
    - CPU
        - Register file
        - instruction latch / decode / branch
        - stack
        - clock / reset
    - memory
    - peripheral
 
1 CPU
    contains:
        - ALU：             Arithmetic logic unit     只负责运算和逻辑运算（必备）

![image](./img/ALU.jpg.png)

            -- Two Input data   输入操作数
            -- Instruction      操作指令
            -- result           保留操作结果
            -- status           保留操作结果状态
        - Input Data：      register file             寄存器组（必备， 操作数从这里取）
        - Input Operation： control unit              控制单元（必备）
        -- float point process unit 浮点处理处理单元
        -- Cache mangement
        -- memory management