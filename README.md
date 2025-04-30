# 1-DoF Helicopter: Dynamics and Backstepping Control

[![MATLAB](https://img.shields.io/badge/MATLAB-R2021a%2B-blue.svg)](https://www.mathworks.com/products/matlab.html)
[![Simulink](https://img.shields.io/badge/Simulink-R2021a%2B-orange.svg)](https://www.mathworks.com/products/simulink.html)

A MATLAB/Simulink implementation of a **single-axis (pitch) helicopter model** with nonlinear dynamics and backstepping control for educational and research purposes.  

---

## 📝 Authors  

- **Nabil Hassan** | [nabil.hassan@student.guc.edu.eg](mailto:nabil.hassan@student.guc.edu.eg)  
- **Ahmed Daw** | [ahmed.daw@student.guc.edu.eg](mailto:ahmed.daw@student.guc.edu.eg)  
- **Mohamed Al-Salhawy** | [mohamed.alsalhawy@student.guc.edu.eg](mailto:mohamed.alsalhawy@student.guc.edu.eg) 
- **Mohamed Ashraf** | [mohamed.ashraf@student.guc.edu.eg](mailto:mohamed.ashraf@student.guc.edu.eg)  
- **Salma Khedr** | [salma.mohamedkhedr@student.guc.edu.eg](mailto:salma.mohamedkhedr@student.guc.edu.eg)  

---

## 🚀 Overview  
This project focuses on modeling and controlling a **1-DoF helicopter** constrained to pitch-axis motion. Key contributions include:  
- Derivation of nonlinear dynamics for a BLDC motor-driven coaxial helicopter.  
- Design of a **backstepping controller** for global asymptotic stability and trajectory tracking.  
- Robustness validation against **±10% mass perturbations** with **1.2-second settling time**.  
- Full system identification using experimental data and MATLAB optimization tools.  

---

## 🔧 Features  
- **System Modeling**:  
  - Nonlinear dynamics with gravitational torque and BLDC motor thrust.  
  - Simulink blocks for open/closed-loop simulations.  
- **Control Design**:  
  - Backstepping control with Lyapunov stability guarantees.  
  - Pole placement for desired closed-loop performance.  
- **Validation**:  
  - Open/closed-loop response analysis.  
  - Trajectory tracking with **2 mm end-effector accuracy**.  

---

## ⚙️ Installation  
1. **Prerequisites**:  
   - MATLAB R2021a or later.  
   - Simulink and Control System Toolbox.  
2. **Clone the Repository**:  
   ```bash
   git clone https://github.com/nhhassan/1dof-copter-backstepping.git
