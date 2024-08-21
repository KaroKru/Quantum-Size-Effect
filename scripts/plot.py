import matplotlib.pyplot as plt
import numpy as np 
import csv
import os

def plot(x, y, title, xLabel, yLabel):
    plt.figure(figsize=(10,6))
    plt.title(title)
    plt.plot(x, y)
    plt.xlabel(xLabel)
    plt.ylabel(yLabel)
    plt.grid(True)
    plt.show()

def spherePlot(data):
    x = [row[0] for row in data]
    columnsNum = len(data[0])

    for num in range(1, columnsNum):
        y = [row[num] for row in data]

        if num == 1:
            title = "Fermi wave vector.\n"
            xLabel = "Lz [nm]"
            yLabel = "kF [nm^-1]"

        elif num == 2:
            title = "Number of subbands inside the Fermi surface.\n"
            xLabel = "Lz [nm]"
            yLabel = "P"

        elif num == 3:
            title = "Electron density of states at the Fermi energy.\n"
            xLabel = "Lz [nm]"
            yLabel = "D(EF) [eV^-1 nm^-3]"

        elif num == 4:
            title = "Electron density of states at the Fermi energy.\n"
            xLabel = "Lz [nm]"
            yLabel = "E/n [eV]"

        plot(x, y, title, xLabel, yLabel)


def electronicDensity(data):
    E = [row[1] for row in data]
    DE = [row[0] for row in data]
    title = "Electronic density of states per unit volume as a function of the energy for specific values of sample thickness. \n"
    xLabel = "E [eV]"
    yLabel = "D(E) [eV^-1 nm^-3]"

    plot(E, DE, title, xLabel, yLabel)

def readData(filePath):
    data = []

    try:
        with open(filePath, 'r') as file:
            for line in file:
                try:
                    values = list(map(float, line.split(',')))
                    data.append(values)
                except ValueError as e:
                    print(f"Data conversion error at line: {line.strip()}. Details: {e}")
    except FileNotFoundError:
        print("File not found.")
    except IOError:
        print("Error during reading process.")

    return data

def sphereResults():
    filePath = os.path.join('..', 'build', 'savedData.txt')
    data = readData(filePath)

    if data:
        spherePlot(data)

def electronicResults():
    filePath = os.path.join('..', 'build', 'electronicData.txt')
    eData = readData(filePath)

    if eData:
        electronicDensity(eData)

if __name__ == "__main__":
    sphereResults()
    electronicResults()