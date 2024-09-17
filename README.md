# Quantum-Size-Effect
Code for quantum size effect calculation based on the article W. A. Atkinson, A.J. Salvin, A free-electron calculation for quantum size effects in the properties of metallic islands on surfaces, American Journal of Physics 76 (12) 2008.

## How to configure values 
Open the values.txt file, which is located under the path:

```
source/src/configuration/values.txt
```

First value: Element name
Second value: Sample length in the x direction
Third value: Sample length in the y direction
Fourth value: Sample length in the z direction -thickness of the sample

## How to use
```
cd Quantum-Size-Effect
mkdir build
cd build
cmake -G "Unix Makefiles" ..
make
./run.exe
```

## How to run tests:
```
ctest -V
```

## Hot to plot results 
Use the command line under the scripts path and type:
```
python plot.py
```
