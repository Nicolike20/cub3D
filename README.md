# cub3D

## 📚 About the Project

**cub3D** is a graphical programming project from the 42 coding school curriculum. It is a simplified 3D game engine based on raycasting, inspired by early first-person shooters like *Wolfenstein 3D*. The goal is to render a 3D projection from a 2D map using a basic graphics library and implement real-time player movement.

This project introduces fundamental concepts of 3D rendering, vector math, collision detection, and real-time graphics in C.

---

## 🧩 Project Objective

- Parse a map file with `.cub` extension
- Render a 3D first-person view using raycasting
- Display walls with textures based on direction and distance
- Allow player movement (forward/backward/strafe) and rotation
- Handle basic minimap or HUD (optional)
- Respect memory and performance constraints

---

## 🛠️ How to Use

1. Clone the repository:
   ```bash
   git clone https://github.com/yourusername/cub3D.git
   cd cub3D
   ```

2. Compile the project:
   ```bash
   make
   ```

3. Run the game with a valid map:
   ```bash
   ./cub3D maps/map.cub
   ```

4. Controls:
   - `W / A / S / D` – move forward, left, backward, right
   - `← / →` – rotate view
   - `ESC` – exit the game

---

## 🗺️ Map Format

The `.cub` file must define:

- Map layout with walls (`1`) and empty space (`0`)
- Player starting position and orientation (`N`, `S`, `E`, `W`)
- Paths to texture files for each direction (north, south, east, west)
- RGB values for floor and ceiling colors

The map must be closed (surrounded by walls) and properly formatted.

---

## 🎨 Features

- Real-time 3D rendering with raycasting
- Basic texture mapping
- Dynamic player movement and collision detection
- Minimap *(optional/bonus)*
- Frame-rate independent rendering loop
- Error handling for malformed maps and resources

---

## 🧠 Skills Demonstrated

- Raycasting algorithm implementation  
- Vector math and geometric transformations  
- Low-level graphics with **MiniLibX**  
- Real-time input handling and rendering loop  
- Texture parsing and rendering  
- Efficient memory management and leak prevention  
- Modular project architecture in C

---

## 📁 Project Status

✅ Completed – fully functional and compliant with the mandatory requirements.  

---

## 📌 Notes

- Built with **MiniLibX** – a minimal graphics library provided by 42  
- All logic, rendering, and resource management written in C  
- Compatible with macOS or Linux depending on setup

---

## 📫 Contact

Feel free to reach out via [GitHub](https://github.com/Nicolike20) if you have any questions or want to connect.
