import matplotlib.pyplot as plt
import numpy as np 
import csv
import os

def electronicDensity(data):
    E = [row[1] for row in data]
    DE = [row[0] for row in data]

    plt.figure(figsize=(10,6))
    plt.title("Electronic density of states per unit volume as a function of the energy for specific values of sample thickness. \n")
    plt.plot(E, DE)
    plt.xlabel('E')
    plt.ylabel('DE')
    plt.grid(True)
    plt.show()


def fermiWaveVector(data):
    Lz = [row[0] for row in data]
    kF = [row[1] for row in data]

    plt.figure(figsize=(10,6))
    plt.title("Fermi wave vector.\n")
    plt.plot(Lz, kF)
    plt.xlabel('Lz')
    plt.ylabel('kF')
    plt.grid(True)
    plt.show()

def subbandsNumber(data):
    Lz = [row[0] for row in data]
    P = [row[2] for row in data]

    plt.figure(figsize=(10,6))
    plt.title("Number of subbands inside the Fermi surface.\n")
    plt.plot(Lz, P)
    plt.xlabel('Lz')
    plt.ylabel('P')
    plt.grid(True)
    plt.show()

def fermiElectronDensity(data):
    Lz = [row[0] for row in data]
    dos = [row[3] for row in data]

    plt.figure(figsize=(10,6))
    plt.title("Electron density of states at the Fermi energy.\n")
    plt.plot(Lz, dos)
    plt.xlabel('Lz [nm]')
    plt.ylabel('DOS')
    plt.grid(True)
    plt.show()

def electronEnergy(data):
    Lz = [row[0] for row in data]
    Ef = [row[4] for row in data]

    plt.figure(figsize=(10,6))
    plt.title("Electron energy per electron.\n")
    plt.plot(Lz, Ef)
    plt.xlabel('Lz')
    plt.ylabel('Ef')
    plt.grid(True)
    plt.show()


def sphereResults():
    
    filePath = os.path.join('..', 'build', 'savedData.txt')
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
        
    fermiWaveVector(data)
    subbandsNumber(data)
    fermiElectronDensity(data)
    electronEnergy(data)

def electronicResults():
    eData = []

    filePath = os.path.join('..', 'build', 'electronicData.txt')

    try:
        with open(filePath, 'r') as file:
            for line in file:
                try:
                    values = list(map(float, line.split(',')))
                    eData.append(values)
                except ValueError as e:
                    print(f"Data conversion error at line: {line.strip()}. Details: {e}")
    except FileNotFoundError:
        print("File not found.")
    except IOError:
        print("Error during reading process.")

    electronicDensity(eData)

if __name__ == "__main__":
    sphereResults()
    electronicResults()