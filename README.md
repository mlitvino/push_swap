# push_swap

This project aims to sort data on a stack, with a limited set of instructions, using the lowest possible number of actions.

Given a set of integers, sort it using a predefined set of instructions using
two stacks. The instruction set is defined below. This program outputs a program
in push_swap instructions that sorts the input integers.

## Instruction set

| Code  | Instruction                         | Action                                                 |
| ----- | ----------------------------------- | ------------------------------------------------------ |
| `sa`  | swap a                              | swaps the 2 top elements of stack a                    |
| `sb`  | swap b                              | swaps the 2 top elements of stack b                    |
| `ss`  | swap a + swap b                     | both `sa` and `sb`                                     |
| `pa`  | push a                              | moves the top element of stack b at the top of stack a |
| `pb`  | push b                              | moves the top element of stack a at the top of stack b |
| `ra`  | rotate a                            | shifts all elements of stack a from bottom to top      |
| `rb`  | rotate b                            | shifts all elements of stack b from bottom to top      |
| `rr`  | rotate a + rotate b                 | both `ra` and `rb`                                     |
| `rra` | reverse rotate a                    | shifts all elements of stack a from top to bottom      |
| `rrb` | reverse rotate b                    | shifts all elements of stack b from top to bottom      |
| `rrr` | reverse rotate a + reverse rotate b | both `rra` and `rrb`                                   |

## Algorithm

In this project I used Radix sort as the main algorithm. Radix sort is an efficient algorithm to sort non-negative integers with time complexity O (n).

## Installation

```bash
make
./push_swap <integer list>
```
## Verification
```bash
ARG="3 1 5 7"; ./push_swap $ARG | ./checker_linux $ARG
```
OK - push_swap sorted stack correctly and checker approved it

## Screenshots
1. Simple input
<img width="425" height="232" alt="image" src="https://github.com/user-attachments/assets/fd4c160d-ec59-48ae-8888-c09ee0cf050a" />

2. Input from shuf with checker verification
<img width="959" height="54" alt="image" src="https://github.com/user-attachments/assets/f387f3e8-56d7-498d-9064-b46b1cdd98a7" />



