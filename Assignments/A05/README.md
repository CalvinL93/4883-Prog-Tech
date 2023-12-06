## 161
### Calvin Leavy
### Description:

Solution for Traffic Light Problem. Begins checking for all lights being green after first light turns red. So if all lights remain green for 30 seconds except one is only green for 10 seconds once that light cycles it will be green again at 20 seconds as well as all of the other lights will be green. So the time taken is 20 seconds. To change to waiting until all lights have turned red at least once uncomment line 70 and line 80. This will not allow checking for all lights being green until the longest light has turned red at least once. I cannot see what the problem is with this solution as it appears it should work. It seems to work with a smaller input but larger inputs there are several issues while most of the inputs work.

### Files

|   #   | File                       | Description                                                |
| :---: | -------------------------- | ---------------------------------------------------------- |
|   1   | [main.cpp](./main.cpp)     | Solution file.                                             |
|   2   | [Data](./Data)             | Test input file from problem statement                     |
|   3   | [Data2](./Data2)           | Larger test input from udebug                              |
|   4   | [Data3](./Data3)           | An Even Larger test input from udebug                      |
|   5   | [p161.pdf](./p161.pdf)     | Traffic Light problem instructions pdf                     |

### Instructions

- run ./main < (data file) > (output file)

