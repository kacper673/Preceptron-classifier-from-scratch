# Perceptron Iris Classifier — From Scratch 

This project demonstrates how a **perceptron** — one of the simplest neural models — can be built **entirely from scratch** in **C++**.  
No machine learning libraries, no high-level frameworks: just basic data structures, loops, and arithmetic.

The program classifies samples from the **Iris dataset** into two categories by directly implementing:
- manual dataset parsing,
- handcrafted train/test splitting,
- weight initialization with basic random numbers,
- perceptron learning rule with explicit updates,
- accuracy evaluation without external tools.

---

- **Raw Data Handling**  
  - CSV parsing implemented line by line using streams.  
  - Features stored in a simple `Input` struct with `std::vector<double>` for attributes and an integer label.  

- **Perceptron from First Principles**  
  - Weights are just a `std::vector<double>`.  
  - Predictions use a **dot product + bias**.  
  - Error drives updates according to the original Rosenblatt learning rule.  

- **Train/Test Split Without Libraries**  
  - Random shuffling and slicing of vectors.  
  - Implemented directly with STL algorithms (`std::shuffle`) instead of scikit-learn–style utilities.  

- **Accuracy Check**  
  - Counting correct predictions with explicit loops.  
  - No metrics libraries — only integer counters and division.

---


