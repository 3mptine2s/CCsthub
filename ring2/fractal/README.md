*This project has been created as part of the 42 curriculum by sthubthi*

# Fract-ol : Mandelbrot & Julia Set Renderer

A high-performance fractal renderer built in standard C using the MiniLibX graphical library. This project calculates and renders the Mandelbrot set and infinite variations of the Julia set by translating screen pixels into complex mathematical coordinates and applying the `Z = Z^2 + C` escape-time algorithm.

---

## Prerequisites

To compile and run this project, you need the **MiniLibX** library and its underlying X11 dependencies installed on your Linux machine.

```bash
sudo apt-get update
sudo apt-get install gcc make xorg libxext-dev libx11-dev
```

## Instructions
To compile this project simply run **make** with all the forementioned dependencies and libraries including ftprintf.

---

## Resources
A video by Oceano on youtube introducing the viewer to the minilibx library and a git showcasing simple functions.
https://www.youtube.com/watch?v=bYS93r6U0zg
https://github.com/suspectedoceano/mlx

Documentation on minilibx.
https://harm-smits.github.io/42docs/libs/minilibx

**AI Usage :** Debugging , checking memory leaks and demonstrating function usages of minilibx.

---

## Usages
**Zooming**         : Scroll up to zoom in and Scroll down to zoom out
**Closing Program** : ESC on keyboard or clicking Close Window Button
```
./fractol mandelbrot
./fractol julia -0.4 0.6
```
## Features
* **Dual Fractal Engine:** Renders both the Mandelbrot set and custom Julia sets.
* **Infinite Zoom:** Interactive viewport scaling using the mouse scroll wheel.
* **Custom Mathematics:** Built without standard math libraries for complex numbers
* **Algorithmic Coloring:** Smooth, iteration-based gradient shading for escaped coordinates.
