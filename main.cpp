/**
 * @file main.cpp
 * @brief Implementation of merge sort algorithm.
 *
 * @copyright Copyright (C) 2025
 * @license This software is provided "as-is," without warranty of any kind.
 *          Permission to use, copy, modify, and distribute this software for
 *          any purpose is hereby granted without fee.
 *
 * @date 2025-01-15
 */
#include <iostream>
#include <vector>
#include <algorithm>

// Función para fusionar dos subvectores en orden descendente
void merge(std::vector<double>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Subvectores temporales
    std::vector<double> L(n1);
    std::vector<double> R(n2);

    // Copiar datos a los subvectores
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int i = 0; i < n2; i++)
        R[i] = arr[mid + 1 + i];

    // Fusionar los subvectores en orden descendente
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] >= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copiar los elementos restantes de L si los hay
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copiar los elementos restantes de R, si los hay
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Función recursiva para dividir y ordenar el vector
void merge_sort(std::vector<double>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Dividir
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);

        // Conquistar
        merge(arr, left, mid, right);
    }
}

void solve(std::vector<double>& values, int& n) {
    merge_sort(values, 0, n - 1); // Ordenar usando merge_sort en orden descendente
    std::cout << "Resultado:\nValores ordenados de mayor a menor:" << std::endl;
    for (int i = 0; i < n; i++) std::cout << values[i] << " "; // Imprimir los valores ordenados
    std::cout << std::endl;
}


int main() {
  std::cout << "Numero de casos de prueba: ";
  int t;
  std::cin >> t;
  std::cout << std::endl; // Casos de prueba
  int c = 1; // Caso inicial
  while(t--){ // Ejecutar los casos de prueba
    std::cout << "Caso de prueba " << c++ << ":" << std::endl; // Imprime e incrementa el caso de prueba
    std::cout << "Ingrese el número de valores a ordenar: ";
    int n; 
    std::cin >> n;
    std::cout << std::endl; 
    std::cout << "Ingrese " << n << " valores (reales o enteros), uno por línea:" << std::endl;
    std::vector<double> values(n);
    for(int i = 0; i < n; i++) std::cin >> values[i]; // Leer los valores
    std::cout << std::endl;
    solve(values, n); // Ordenar e imprimir
    std::cout << std::endl;
    values.clear(); // Borrar datos del vector para el siguiente caso de prueba por si acaso
  }
  return 0;
}
