🏀 3D Ball Trajectory Simulator (C++ & OpenGL)

![GitHub repo size](https://img.shields.io/github/repo-size/your-username/3d-ball-trajectory)
![GitHub stars](https://img.shields.io/github/stars/your-username/3d-ball-trajectory?style=social)
![GitHub forks](https://img.shields.io/github/forks/your-username/3d-ball-trajectory?style=social)
![License](https://img.shields.io/github/license/your-username/3d-ball-trajectory)

---

📄 Project Summary

The goal of this project is to **simulate and visualize the trajectory of a ball** in 3D space.  
Given the **coordinates of the impact point**, the program calculates the **ball’s motion under gravity** and displays the **path from the launch point to the ground**.  

> ⚡ Combines **physics calculations** with **OpenGL graphics** for a realistic, interactive simulation.

---

🚀Overview

The **3D Ball Trajectory Simulator** is an **interactive, real-time physics simulation** built in **C++ using OpenGL** within **Code::Blocks IDE**.  

Users can:  
- Visualize the **3D trajectory of a ball**.  
- Adjust **initial speed, launch angle, gravity, and bounce**.  
- Observe realistic projectile motion in real time.  

This project combines **computer graphics** and **physics principles**, making it ideal for:  
- Students learning **OpenGL rendering**  
- Physics enthusiasts exploring **projectile motion**  
- Hobbyists interested in **simulation or game development**  

> 🎯 **Key Highlights:**  
> - Real-time 3D ball rendering  
> - Dynamic trajectory visualization  
> - Interactive parameter customization  
> - Educational and visually engaging

---

✨ Features

| Feature | Description |
|---------|-------------|
| 🎮 Real-time Physics | Ball motion calculated using projectile physics equations |
| 🏀 3D Ball Rendering | Ball visualized with OpenGL primitives |
| 📈 Trajectory Visualization | Ball path displayed as a line strip for clarity |
| ⚡ Custom Parameters | Launch speed, angle, gravity, and restitution adjustable |
| ⏯ Interactive Controls | Restart or modify simulation in real time |
| 💻 Code::Blocks Compatible | Seamless Windows IDE support |

---

## 🛠 Tech Stack

- **Language:** C++  
- **Graphics Library:** OpenGL (GLUT/GLU)  
- **IDE:** Code::Blocks (Windows)  
- **Math:** Manual vector calculations (no external library)  


📦 Installation & Setup (Windows / Code::Blocks)
1️⃣ Prerequisites
Code::Blocks IDE (with MinGW)

OpenGL libraries (GLUT/GLU)

2️⃣ Open Project
bash
Copy
Edit
git clone https://github.com/NabajitPaul/3d-ball-trajectory.git
Open 3d_ball_trajectory.cbp in Code::Blocks.

3️⃣ Configure Libraries
Link opengl32.lib and glut32.lib in Project → Build Options → Linker Settings
Ensure GLUT headers are included if required

4️⃣ Build & Run
Click Build → Build and Run
The 3D Ball Trajectory window will appear

⚠️ Tip: Adjust initial speed and angle in the code for different simulations.


🔬 Future Enhancements
🌈 Textured 3D ball for realism
🕹 GUI sliders to adjust parameters at runtime
📊 Multi-ball simulation with collisions

🎥 Camera controls (orbit, zoom, pan)

🌍 Obstacle and terrain interactions
