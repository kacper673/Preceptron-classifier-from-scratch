# Perceptron Iris Classifier - From Scratch 

This project demonstrates how a **perceptron** - one of the simplest neural models - can be built **entirely from scratch** in **C++**.  
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
  - No metrics libraries - only integer counters and division.
 
- **Visualisation of Learning**
  - Saving necessary data to csv
  - Python script to process and plot the data
  - Plotting in Matplotlib

## 📸 Example Screenshots

- **Charts plotted with Matplotlib showig impoving accuracy over each epoch**
  
  <img width="776" height="592" alt="Zrzut ekranu 2025-09-19 233309" src="https://github.com/user-attachments/assets/0bca76f7-eab0-4132-95da-668f9bea4efa" />
  
---

  <img width="774" height="580" alt="Zrzut ekranu 2025-09-19 233224" src="https://github.com/user-attachments/assets/fc0f8b97-0152-4dbf-934d-ab49d5d6968b" />

---

 
- **Accuracy after every epoch and final accuracy of the model**

<img width="881" height="560" alt="image" src="https://github.com/user-attachments/assets/61d27500-4b91-4651-9e3d-c180383c8e68" />

---

- **Learning process info (debug flag  = true)**

<img width="551" height="1070" alt="image" src="https://github.com/user-attachments/assets/0b58553b-8805-4dd8-80a3-57b7a9880f19" />

---

- **Adjusting learning paramters (eta, epochs) influences the model performacne, for example small eta makes model perform very poorly despite relativly many epochs**

<img width="984" height="609" alt="image" src="https://github.com/user-attachments/assets/caa9e035-86c7-4e03-9769-f289a56db56c" />

---
