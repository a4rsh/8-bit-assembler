## Rudimentary Assembler for my [8 bit CPU](https://github.com/a4rsh/8-bit-cpu)


### Usage

`make assembler`<br>
`./assembler input.txt output.bin`<br>
bin file can be used as `program.bin` with the CPU<br>

### Syntax
```WLO [R (A or B)] [XXXX]
WUP [R (A or B)] [XXXX]
MOVE [R (Destination)] [R (Source)]
LOAD [R (Value)] [R (Address)]
SAVE [R (Value)] [R (Address)]
ADD [R (Op 1/Destination)] [R (Op 2/Destination)]
SUB [R (Op 1/Destination)] [R (Op 2/Destination)]
AND [R (Op 1/Destination)] [R (Op 2/Destination)]
XOR [R (Op 1/Destination)] [R (Op 2/Destination)]
JMP [R (Desitation)]
JEQ [R (Destination)] [R (Value)]
HALT
```