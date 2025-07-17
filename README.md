# Derivatives Pricing in C++ – Joshi's Book Implementation

This repository contains a complete C++ implementation of the key design patterns and numerical techniques for derivative pricing from *"C++ Design Patterns and Derivatives Pricing"* by Mark Joshi.

## 📘 About

The project is structured around the book’s development of a reusable C++ library for quantitative finance, with an emphasis on:

- Object-oriented design
- Use of inheritance, polymorphism, and templates
- Monte Carlo simulation techniques
- Vanilla and exotic option pricing
- Reusable parameter classes and payoff structures

## 📂 Folder Structure

- source/: C++ implementation files (classes for options, payoffs, parameters, etc.)
- include/: Header files
- projects/: Main programs and examples
- utils/: Helper functions and utility classes
- Makefile: Build instructions

## 🚀 How to Compile

To build the project, use `make` from the root directory:

    make
    ./Ex4.3Main

Ensure your system supports C++20 and you have clang++ or g++ installed.

## ✨ Features Implemented

- PayOff classes with virtual and bridge pattern usage
- Parameters class hierarchy for deterministic/stochastic interest rates or volatilities
- VanillaOption and SimpleMonteCarlo methods
- Running statistics using the strategy pattern
- Piecewise constant parameters
- clone() idiom for copying polymorphic objects

## 📈 Examples

You’ll find programs such as Ex4.3Main.cpp that run pricing experiments using:

- Power options
- Piecewise-constant volatilities
- Custom payoff functions

## 🛠 Tools and Standards

- C++20
- clang++ / g++
- Make
- Clean and minimal code with consistent naming and comments

## 📚 Reference

This repository follows:

> Mark Joshi, *"C++ Design Patterns and Derivatives Pricing"*, 2nd Edition, Cambridge University Press.

## 🧠 Who Is This For?

- Quantitative finance students and professionals
- Developers implementing pricing libraries
- Anyone studying C++ patterns in a mathematical context

## 🗓️ Last Updated

July 17, 2025

---

Feel free to fork, star ⭐, and contribute!

## 📬 License

For educational use only. The original book and intellectual content belong to Mark Joshi and Cambridge University Press.# C++ Monte Carlo Option Pricing

This project implements Monte Carlo methods for pricing European options using object-oriented C++.

## Structure

- `Ch1_Intro`: Basics of C++ and option payoff functions.
- `Ch2_Random`: Random number generators.
- `Ch3_Inheritance`: Parameters and payoffs using inheritance.
- `Ch4_Stats`: Statistics gatherers.
- ...

## How to Build

Run `make` inside each chapter folder:


